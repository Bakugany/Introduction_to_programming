#include <stdio.h>
#include <limits.h>

#define MAX_ROW 100 // Line has at most 100 characters.

static int Axiom(int axiom[])
{
    int length_of_axiom = 0;
    int end_of_axiom = 0;
    while (end_of_axiom == 0)
    {
        int k = getchar();
        if (k == '\n')
        {
            end_of_axiom = 1;
        }
        else
        {
            axiom[length_of_axiom] = k;
            length_of_axiom++;
        }
    }
    return(length_of_axiom);
}

static void Rules(int swap[][MAX_ROW], int length[])
{
    int begin_of_prologue = 0;
    while (begin_of_prologue == 0)
    {
        int change_of_character = 0;
        int k = getchar();
        if (k == '\n')
        {
            begin_of_prologue = 1;
        }
        else
        {
            int length_of_character = 0;
            while (change_of_character == 0)
            {
                int l = getchar();
                if (l  == '\n')
                {
                    change_of_character = 1;
                    length[k] = length_of_character;
                }
                else
                {
                    swap[k][length_of_character]=l;
                    length_of_character++;
                }
            }
        }
    }
}

static void Prologue(void)
{
    int end_of_prologue = 0;
    while (end_of_prologue == 0)
    {
        int change_of_line = 0;
        char k = (char) getchar();
        if (k == '\n')
        {
            end_of_prologue = 1;
        }
        else
        {
            printf("%c", k);
            while (change_of_line == 0)
            {
                char l = (char) getchar();
                printf("%c", l);
                if (l  == '\n')
                {
                    change_of_line = 1;
                }
            }
        }
    }
}

static void Production(int prod, int axiom[], int length_of_axiom, int swap1[][MAX_ROW], int length1[],
                       int swap2[][MAX_ROW], int length2[])
{
    if (prod == 0 )
    {
        for (int i = 0; i < length_of_axiom; i++)
        {
            for (int j = 0; j < length2[axiom[i]]; j++)
            {
                printf("%c", swap2[axiom[i]][j]);
            }
            if (length2[axiom[i]] != -1)
            {
                printf("\n");
            }
        }
    }
    else
    {
        for (int i = 0; i < length_of_axiom; i++)
        {
            Production(prod - 1, swap1[axiom[i]], length1[axiom[i]], swap1, length1, swap2, length2);
        }
    }
}

static void Epilogue(void)
{
    int end_of_epilogue = 0;
    while (end_of_epilogue == 0)
    {
        char k = (char) getchar();
        if (k == EOF)
        {
            end_of_epilogue = 1;
        }
        else
        {
            printf("%c", k);
        }
    }
}

int main()
{
   int prod;
   scanf("%d \n", &prod);
   int axiom[MAX_ROW];
   int length_of_axiom;
   length_of_axiom = Axiom(axiom);
   int swap1[CHAR_MAX][MAX_ROW];
   for (int i = 0; i < CHAR_MAX; i++)
   {
        swap1[i][0] = i;
   }
   int length1[CHAR_MAX];
   for (int i = 0; i < CHAR_MAX;i++)
   {
       length1[i] = 1;
   }
   Rules(swap1, length1);
   Prologue();
   int swap2[CHAR_MAX][MAX_ROW];
   int length2[CHAR_MAX];
   for (int i = 0; i < CHAR_MAX; i++)
   {
       length2[i] = -1;
   }
   Rules(swap2, length2);
   Production(prod, axiom, length_of_axiom,swap1, length1, swap2, length2);
   Epilogue();
}
