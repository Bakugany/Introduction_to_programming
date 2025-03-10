#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#include <inttypes.h>

#define BASE 1000000000000000000

struct node
{
    uint64_t val;
    struct node *next;
    struct node *previous;
};
typedef struct node my_list;

void zero(my_list *result , int character)
{
    my_list *clear = &(result[character]);
    if (clear->next != NULL)
    {
        clear = clear->next;
        while (clear->next != NULL)
        {
            clear = clear->next;
            free(clear->previous);
        }
        free(clear);
        result[character].next = NULL;
    }
    result[character].val = 0;
}

void increment(my_list *result, int character)
{
    bool available = 0;
    bool end_of_list = 0;
    my_list *add =&(result[character]);
    while (end_of_list == 0)
    {
        if (add->val + 1 < BASE)
        {
            add->val++;
            available = 1;
            break;
        }
        else
        {
            add->val = 0;
        }
        if (add->next != NULL)
        {
            add = add->next;
        }
        else
        {
            end_of_list = 1;
        }
    }
    if (available == 0)
    {
        add->next = (my_list*) malloc ( sizeof (my_list));
        add->next->val = 1;
        add->next->next = NULL;
        add->next->previous = add;
    }
}

void addition(int character_1, int character_2, my_list *result)
{
    my_list *add_1 = &(result[character_1]);
    my_list *add_2 = &(result[character_2]);
    unsigned long long transfer = 0;
    while (add_1->next != NULL)
    {
        if (add_2->next == NULL)
        {
            add_2->next = (my_list*) malloc ( sizeof (my_list));
            add_2->next->val = 0;
            add_2->next->next = NULL;
            add_2->next->previous = add_2;
        }
        if (add_2->val + add_1->val + transfer >= BASE)
        {
            add_2->val = add_2->val + add_1->val + transfer - BASE;
            transfer = 1;
        }
        else
        {
            add_2->val = add_2->val + add_1->val + transfer;
            transfer = 0;
        }
        add_2 = add_2->next;
        add_1 = add_1->next;
    }
    if (add_2->val + add_1->val + transfer >= BASE)
    {
        add_2->val = add_2->val + add_1->val + transfer - BASE;
        transfer = 1;
    }
    else
    {
        add_2->val = add_2->val + add_1->val + transfer;
        transfer = 0;
    }
    while (transfer == 1)
    {
        if (add_2->next == NULL)
        {
            add_2->next = (my_list*) malloc (sizeof (my_list));
            add_2->next->val = 1;
            add_2->next->next = NULL;
            add_2->next->previous = add_2;
            transfer = 0;
        }
        else
        {
            add_2 = add_2->next;
            if (add_2->val + transfer >= BASE)
            {
                add_2->val = 0;
            }
            else
            {
                add_2->val++;
                transfer = 0;
            }
        }
    }
}

void decrement(my_list *result, int character)
{
    my_list *add = &(result[character]);
    bool success = 0;
    if (add->val != 0 || add->next != NULL)
    {
        while (! success)
        {
            if (add->val != 0)
            {
                if (add->val == 1 && add->next == NULL && add->previous != NULL)
                {
                    add->previous->next = NULL;
                    free(add);
                }
                else
                {
                    add->val--;
                }
                success = 1;
            }
            else
            {
                add->val = BASE - 1;
            }
            add = add->next;
        }
    }
}

bool still_in_loop(my_list *result, int character)
{
    my_list *pointer = &(result[character]);
    if (pointer-> next == NULL && pointer->val == 0)
    {
        return false;
    }
    return true;
}

void production(int beginning, int end, char *line, my_list *result )
{
    int open_parenthesis = 0;
    int closed_parenthesis = 0;
    while (open_parenthesis == 0 && beginning != end)
    {
        if (line[beginning] == '(')
        {
            open_parenthesis++;
        }
        else
        {
            increment(result, (int) (line[beginning]-(int)'a'));
            beginning++;
        }
    }
    if (beginning == end)
    {
        return;
    }
    int new_ending = beginning;
    while (closed_parenthesis != open_parenthesis )
    {
        new_ending++;
        if (line[new_ending] == '(')
        {
            open_parenthesis++;
        }
        if (line[new_ending] == ')')
        {
            closed_parenthesis++;
        }
    }
    if (open_parenthesis == 1)
    {
        for (int i = beginning + 2; i < new_ending ; i++)
        {
            addition((int)(line[beginning + 1]-(int)'a'),(int)(line[i]-(int)'a'),result );
        }
        zero(result, (int)(line[beginning+ 1]-(int)'a') );
    }
    else
    {
        while (still_in_loop(result, (int) line[beginning + 1] - (int) 'a'))
        {
            decrement(result, (int) line[beginning + 1] - (int) 'a');
            production(beginning + 2, new_ending, line, result);
        }
    }
    if (new_ending + 1 < end)
    {
        production(new_ending + 1, end, line, result);
    }
}

void output(int character, my_list *result)
{
    my_list *pointer = &(result[character]);

    while (pointer->next != NULL)
    {
        pointer = pointer->next;
    }
    printf("%lu", pointer->val);
    if (pointer->previous != NULL)
    {
        while (pointer->previous != NULL)
        {
            pointer = pointer->previous;
            printf("%018" PRIu64, pointer->val);
        }
        putchar('\n');
    }
    else
    {
        putchar('\n');
    }
}

int main()
{
    char input;
    my_list *result =(my_list*) malloc(26 * sizeof(my_list));
    for(int i = 0; i < 26; i++)
    {
        result[i].previous = NULL;
        result[i].next = NULL;
        result[i].val = 0;
    }
    while ((input = (char) getchar()) != EOF )
    {
        char *line;
        if (input == '=')
        {
            output((int)getchar() - (int)'a', result);
        }
        else if (input != '\n')
        {
            line = (char*) malloc(1);
            line[0] = input;
            int new_realloc = 1;
            int size_of_line = 1;
            while( (input = (char) getchar()) != '\n')
            {
                if (new_realloc <= size_of_line )
                {
                    new_realloc *= 2;
                    line =(char*) realloc(line, (unsigned) new_realloc);
                }
                line[size_of_line] = input;
                size_of_line ++;
            }
            production(0, size_of_line, line, result);
            free(line);
        }

    }
    for (int i = 0; i < 26; i++)
    {
        zero(result, i);
    }
    free(result);
}

