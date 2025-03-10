#include <stdio.h>

#define ROWS  8
#define COLUMNS  8
#define BLACKPON  1
#define WHITEPON  2

void check(int arr[COLUMNS][ROWS], int player) { // Funkcja do sprawdzania czy na polu można wykonać legalny ruch.
    if (player == 0) { // Rozważamy ruch czarnego gracza
        printf("C");;// Wypisujemy, że to ruch gracza czarnego.
        for (int i = 0; i < COLUMNS; ++i) {
            for (int j = 0; j < ROWS; ++j) { //Sprawdzamy dla każdego pola planszy, czy jest dostępne.
                if (arr[i][j] == 0) {// Sprawdzamy na których polach nie ma pionka.
                    int available = 0; // Początkową wartość dostępności ustawiamy na 0;
                    int white = 0;
                    int black = 0;
                    for (int k = j - 1; k >= 0; --k) { //Sprawdzamy kierunek południowy.
                        if (black == 0 && arr[i][k] == WHITEPON)
                            white = 1;
                        if (white == 0)
                            break;
                        if (white == 1 && arr[i][k] == 0)
                            break;
                        if (white == 1 && arr[i][k] == BLACKPON)
                            available = 1;
                    }
                    white = 0;
                    black = 0;
                    for (int k = j + 1; k < ROWS; ++k) { // Sprawdzamy kierunek północny.
                        if (black == 0 && arr[i][k] == WHITEPON)
                            white = 1;
                        if (white == 0)
                            break;
                        if (white == 1 && arr[i][k] == 0)
                            break;
                        if (white == 1 && arr[i][k] == BLACKPON)
                            available = 1;
                    }
                    white = 0;
                    black = 0;
                    for (int k = i - 1; k >= 0; --k) { // Sprawdzamy kierunek zachodni.
                        if (black == 0 && arr[k][j] == WHITEPON)
                            white = 1;
                        if (white == 0)
                            break;
                        if (white == 1 && arr[k][j] == 0)
                            break;
                        if (white == 1 && arr[k][j] == BLACKPON)
                            available = 1;
                    }
                    white = 0;
                    black = 0;
                    for (int k = i + 1; k < COLUMNS; ++k) { // Sprawdzamy kierunek wschodni.
                        if (black == 0 && arr[k][j] == WHITEPON)
                            white = 1;
                        if (white == 0)
                            break;
                        if (white == 1 && arr[k][j] == 0)
                            break;
                        if (white == 1 && arr[k][j] == BLACKPON)
                            available = 1;
                    }
                    white = 0;
                    black = 0;
                    int k = i - 1;
                    int l = j - 1;
                    while (k >= 0 && l >= 0) { // Sprawdzamy kierunek południowo-zachodni.
                        if (black == 0 && arr[k][l] == WHITEPON)
                            white = 1;
                        if (white == 0)
                            break;
                        if (white == 1 && arr[k][l] == 0)
                            break;
                        if (white == 1 && arr[k][l] == BLACKPON)
                            available = 1;
                        k--;
                        l--;
                    }
                    white = 0;
                    black = 0;
                    k = i + 1;
                    l = j - 1;
                    while (k < COLUMNS && l >= 0) { // Sprawdzamy kierunek południowo-wschodni.
                        if (black == 0 && arr[k][l] == WHITEPON)
                            white = 1;
                        if (white == 0)
                            break;
                        if (white == 1 && arr[k][l] == 0)
                            break;
                        if (white == 1 && arr[k][l] == BLACKPON)
                            available = 1;
                        k++;
                        l--;
                    }
                    white = 0;
                    black = 0;
                    k = i + 1;
                    l = j + 1;
                    while (k < COLUMNS && l < ROWS) { // Sprawdzamy kierunek północno-wschodni
                        if (black == 0 && arr[k][l] == WHITEPON)
                            white = 1;
                        if (white == 0)
                            break;
                        if (white == 1 && arr[k][l] == 0)
                            break;
                        if (white == 1 && arr[k][l] == BLACKPON)
                            available = 1;
                        k++;
                        l++;
                    }
                    white = 0;
                    black = 0;
                    k = i - 1;
                    l = j + 1;
                    while (k >= 0 && l < 8) { // Sprawdzamy kierunek północno-zachodni
                        if (black == 0 && arr[k][l] == WHITEPON)
                            white = 1;
                        if (white == 0)
                            break;
                        if (white == 1 && arr[k][l] == 0)
                            break;
                        if (white == 1 && arr[k][l] == BLACKPON)
                            available = 1;
                        k--;
                        l++;
                    }
                    if (available == 1) {
                        printf(" ");
                        printf("%c", (i+97));
                        printf("%d", j+1);

                    }

                }
            }
        }
    }
    if (player == 1) { // Rozważamy ruch białego gracza
        printf("B"); // Wypisujemy, że to ruch gracza białego.
        for (int i = 0; i < COLUMNS; ++i) {
            for (int j = 0; j < ROWS; ++j) { // Sprawdzamy dla każdego pola planszy, czy jest dostępne.
                if (arr[i][j] == 0) { //Sprawdzamy na których polach nie ma pionka
                    int available = 0; // Początkową wartość dostępności ustawiamy na 0;
                    int white = 0;
                    int black = 0;
                    for (int k = j - 1; k >= 0; --k) { //Sprawdzamy kierunek południowy.
                        if (white == 0 && arr[i][k] == BLACKPON)
                            black = 1;
                        if (black == 0)
                            break;
                        if (black == 1 && arr[i][k] == 0)
                            break;
                        if (black == 1 && arr[i][k] == WHITEPON)
                            available = 1;
                    }
                    white = 0;
                    black = 0;
                    for (int k = j + 1; k < ROWS; ++k) { // Sprawdzamy kierunek północny.
                        if (white == 0 && arr[i][k] == BLACKPON)
                            black = 1;
                        if (black == 0)
                            break;
                        if (black == 1 && arr[i][k] == 0)
                            break;
                        if (black == 1 && arr[i][k] == WHITEPON)
                            available = 1;
                    }
                    white = 0;
                    black = 0;
                    for (int k = i - 1; k >= 0; --k) { // Sprawdzamy kierunek zachodni.
                        if (white == 0 && arr[k][j] == BLACKPON)
                            black = 1;
                        if (black == 0)
                            break;
                        if (black == 1 && arr[k][j] == 0)
                            break;
                        if (black == 1 && arr[k][j] == WHITEPON)
                            available = 1;
                    }
                    white = 0;
                    black = 0;
                    for (int k = i + 1; k < COLUMNS; ++k) { // Sprawdzamy kierunek wschodni.
                        if (white == 0 && arr[k][j] == BLACKPON)
                            black = 1;
                        if (black == 0)
                            break;
                        if (black == 1 && arr[k][j] == 0)
                            break;
                        if (black == 1 && arr[k][j] == WHITEPON)
                            available = 1;
                    }
                    white = 0;
                    black = 0;
                    int k = i - 1;
                    int l = j - 1;
                    while (k >= 0 && l >= 0) { // Sprawdzamy kierunek południowo-zachodni.
                        if (white == 0 && arr[k][l] == BLACKPON)
                            black = 1;
                        if (black == 0)
                            break;
                        if (black == 1 && arr[k][l] == 0)
                            break;
                        if (black == 1 && arr[k][l] == WHITEPON)
                            available = 1;
                        k--;
                        l--;
                    }
                    white = 0;
                    black = 0;
                    k = i + 1;
                    l = j - 1;
                    while (k < COLUMNS && l >= 0) { // Sprawdzamy kierunek południowo-wschodni.
                        if (white == 0 && arr[k][l] == BLACKPON)
                            black = 1;
                        if (black == 0)
                            break;
                        if (black == 1 && arr[k][l] == 0)
                            break;
                        if (black == 1 && arr[k][l] == WHITEPON)
                            available = 1;
                        k++;
                        l--;
                    }
                    white = 0;
                    black = 0;
                    k = i + 1;
                    l = j + 1;
                    while (k < COLUMNS && l < ROWS) { // Sprawdzamy kierunek północno-wschodni
                        if (white == 0 && arr[k][l] == BLACKPON)
                            black = 1;
                        if (black == 0)
                            break;
                        if (black == 1 && arr[k][l] == 0)
                            break;
                        if (black == 1 && arr[k][l] == WHITEPON)
                            available = 1;
                        k++;
                        l++;
                    }
                    white = 0;
                    black = 0;
                    k = i - 1;
                    l = j + 1;
                    while (k >= 0 && l < ROWS) { // Sprawdzamy kierunek północno-zachodni
                        if (white == 0 && arr[k][l] == BLACKPON)
                            black = 1;
                        if (black == 0)
                            break;
                        if (black == 1 && arr[k][l] == 0)
                            break;
                        if (black == 1 && arr[k][l] == WHITEPON)
                            available = 1;
                        k--;
                        l++;
                    }
                    if (available == 1) {
                        printf(" ");
                        printf("%c", (i+97));
                        printf("%d", j + 1);

                    }
                }

            }
        }
    }
    printf("\n");
}

void move(int arr[COLUMNS][ROWS], int m, int n, int player){
    if(player == 0){
        int white = 0;
        int black = 0;
        for (int k = n - 1; k >= 0; --k) { //Sprawdzamy kierunek południowy.
            if (black == 0 && arr[m][k] == WHITEPON)
                white = 1;
            if (white == 0)
                break;
            if (white == 1 && arr[m][k] == 0)
                break;
            if (white == 1 && arr[m][k] == BLACKPON) {
                for (int a = k + 1; a <= n; ++a)
                    arr[m][a] = BLACKPON;
                break;
            }
        }
        white = 0;
        black = 0;
        for (int k = n + 1; k < ROWS; ++k) { // Sprawdzamy kierunek północny.
            if (black == 0 && arr[m][k] == WHITEPON)
                white = 1;
            if (white == 0)
                break;
            if (white == 1 && arr[m][k] == 0)
                break;
            if (white == 1 && arr[m][k] == BLACKPON){
                for (int a = k - 1; a >= n; --a)
                    arr[m][a] = BLACKPON;
                break;
            }
        }
        white = 0;
        black = 0;
        for (int k = m - 1; k >= 0; --k) { // Sprawdzamy kierunek zachodni.
            if (black == 0 && arr[k][n] == WHITEPON)
                white = 1;
            if (white == 0)
                break;
            if (white == 1 && arr[k][n] == 0)
                break;
            if (white == 1 && arr[k][n] == BLACKPON){
                for (int a = k + 1; a <= m; ++a)
                    arr[a][n] = BLACKPON;
                break;
            }
        }
        white = 0;
        black = 0;
        for (int k = m + 1; k < COLUMNS; ++k) { // Sprawdzamy kierunek wschodni.
            if (black == 0 && arr[k][n] == WHITEPON)
                white = 1;
            if (white == 0)
                break;
            if (white == 1 && arr[k][n] == 0)
                break;
            if (white == 1 && arr[k][n] == BLACKPON){
                for (int a = k - 1; a >= m; --a)
                    arr[a][n] = BLACKPON;
                break;
            }
        }
        white = 0;
        black = 0;
        int k = m - 1;
        int l = n - 1;
        while (k >= 0 && l >= 0) { // Sprawdzamy kierunek południowo-zachodni.
            if (black == 0 && arr[k][l] == WHITEPON)
                white = 1;
            if (white == 0)
                break;
            if (white == 1 && arr[k][l] == 0)
                break;
            if (white == 1 && arr[k][l] == BLACKPON) {
                int a = k + 1;
                int b = l + 1;
                while(a <= m && b <= n) {
                    arr[a][b] = BLACKPON;
                    a++;
                    b++;
                }
                break;
            }
            k--;
            l--;
        }
        white = 0;
        black = 0;
        k = m + 1;
        l = n - 1;
        while (k < COLUMNS && l >= 0) { // Sprawdzamy kierunek południowo-wschodni.
            if (black == 0 && arr[k][l] == WHITEPON)
                white = 1;
            if (white == 0)
                break;
            if (white == 1 && arr[k][l] == 0)
                break;
            if (white == 1 && arr[k][l] == BLACKPON){
                int a = k - 1;
                int b = l + 1;
                while(a >= m && b <= n) {
                    arr[a][b] = BLACKPON;
                    a--;
                    b++;
                }
                break;
            }
            k++;
            l--;
        }
        white = 0; //
        black = 0; //
        k = m + 1;
        l = n + 1;
        while (k < COLUMNS && l < ROWS) { // Sprawdzamy kierunek północno-wschodni
            if (black == 0 && arr[k][l] == WHITEPON)
                white = 1;
            if (white == 0)
                break;
            if (white == 1 && arr[k][l] == 0)
                break;
            if (white == 1 && arr[k][l] == BLACKPON){
                int a = k - 1;
                int b = l - 1;
                while(a >= m && b >= n) {
                    arr[a][b] = BLACKPON;
                    a--;
                    b--;
                }
                break;
            }
            k++;
            l++;
        }
        white = 0; //
        black = 0; //
        k = m - 1;
        l = n + 1;
        while (k >= 0 && l < ROWS) { // Sprawdzamy kierunek północno-zachodni
            if (black == 0 && arr[k][l] == WHITEPON)
                white = 1;
            if (white == 0)
                break;
            if (white == 1 && arr[k][l] == 0)
                break;
            if (white == 1 && arr[k][l] == BLACKPON){
                int a = k + 1;
                int b = l - 1;
                while(a <= m && b >= n) {
                    arr[a][b] = BLACKPON;
                    a++;
                    b--;
                }
                break;
            }
            k--;
            l++;
        }
    }
    if(player == 1){
        int white = 0; //
        int black = 0; //
        for (int k = n - 1; k >= 0; --k) { //Sprawdzamy kierunek południowy.
            if (white == 0 && arr[m][k] == BLACKPON)
                black = 1;
            if (black == 0)
                break;
            if (black == 1 && arr[m][k] == 0)
                break;
            if (black == 1 && arr[m][k] == WHITEPON) {
                for (int a = k + 1; a <= n; ++a)
                    arr[m][a] = WHITEPON;
                break;
            }
        }
        white = 0; //
        black = 0; //
        for (int k = n + 1; k < ROWS; ++k) { // Sprawdzamy kierunek północny.
            if (white == 0 && arr[m][k] == BLACKPON)
                black = 1;
            if (black == 0)
                break;
            if (black == 1 && arr[m][k] == 0)
                break;
            if (black == 1 && arr[m][k] == WHITEPON){
                for (int a = k - 1; a >= n; --a)
                    arr[m][a] = WHITEPON;
                break;
            }
        }
        white = 0; //
        black = 0; //
        for (int k = m - 1; k >= 0; --k) { // Sprawdzamy kierunek zachodni.
            if (white == 0 && arr[k][n] == BLACKPON)
                black = 1;
            if (black == 0)
                break;
            if (black == 1 && arr[k][n] == 0)
                break;
            if (black == 1 && arr[k][n] == WHITEPON){
                for (int a = k + 1; a <= m; ++a)
                    arr[a][n] = WHITEPON;
                break;
            }
        }
        white = 0; //
        black = 0; //
        for (int k = m + 1; k < COLUMNS; ++k) { // Sprawdzamy kierunek wschodni.
            if (white == 0 && arr[k][n] == BLACKPON)
                black = 1;
            if (black == 0)
                break;
            if (black == 1 && arr[k][n] == 0)
                break;
            if (black == 1 && arr[k][n] == WHITEPON){
                for (int a = k - 1; a >= m; --a)
                    arr[a][n] = WHITEPON;
                break;
            }
        }
        white = 0; //
        black = 0; //
        int k = m - 1;
        int l = n - 1;
        while (k >= 0 && l >= 0) { // Sprawdzamy kierunek południowo-zachodni.
            if (white == 0 && arr[k][l] == BLACKPON)
                black = 1;
            if (black == 0)
                break;
            if (black == 1 && arr[k][l] == 0)
                break;
            if (black == 1 && arr[k][l] == WHITEPON) {
                int a = k + 1;
                int b = l + 1;
                while(a <= m && b <= n) {
                    arr[a][b] = WHITEPON;
                    a++;
                    b++;
                }
                break;
            }
            k--;
            l--;
        }
        white = 0; //
        black = 0; //
        k = m + 1;
        l = n - 1;
        while (k < COLUMNS && l >= 0) { // Sprawdzamy kierunek południowo-wschodni.
            if (white == 0 && arr[k][l] == BLACKPON)
                black = 1;
            if (black == 0)
                break;
            if (black == 1 && arr[k][l] == 0)
                break;
            if (black == 1 && arr[k][l] == WHITEPON){
                int a = k - 1;
                int b = l + 1;
                while(a >= m && b <= n) {
                    arr[a][b] = WHITEPON;
                    a--;
                    b++;
                }
                break;
            }
            k++;
            l--;
        }
        white = 0; //
        black = 0; //
        k = m + 1;
        l = n + 1;
        while (k < COLUMNS && l < ROWS) { // Sprawdzamy kierunek północno-wschodni
            if (white == 0 && arr[k][l] == BLACKPON)
                black = 1;
            if (black == 0)
                break;
            if (black == 1 && arr[k][l] == 0)
                break;
            if (black == 1 && arr[k][l] == WHITEPON){
                int a = k - 1;
                int b = l - 1;
                while(a >= m && b >= n) {
                    arr[a][b] = WHITEPON;
                    a--;
                    b--;
                }
                break;
            }
            k++;
            l++;
        }
        white = 0; //
        black = 0; //
        k = m - 1;
        l = n + 1;
        while (k >= 0 && l < ROWS) { // Sprawdzamy kierunek północno-zachodni
            if (white == 0 && arr[k][l] == BLACKPON)
                black = 1;
            if (black == 0)
                break;
            if (black == 1 && arr[k][l] == 0)
                break;
            if (black == 1 && arr[k][l] == WHITEPON){
                int a = k + 1;
                int b = l - 1;
                while(a <= m && b >= n) {
                    arr[a][b] = WHITEPON;
                    a++;
                    b--;
                }
                break;
            }
            k--;
            l++;
        }

    }

}
int main() {
    int arr[COLUMNS][ROWS]; // Tworzymy planszę gry wypełnioną zerami.
    for (int i = 0; i < COLUMNS; ++i)
        for(int j = 0; j < ROWS; ++j)
            arr[i][j] = 0; // Planszę początkowo wypełniamy zerami.
    arr[COLUMNS / 2][ROWS / 2] =  WHITEPON;
    arr[(COLUMNS - 1) / 2][(ROWS - 1) / 2] = WHITEPON; // Białym kamieniom nadejmy wartość 2.
    arr[(COLUMNS - 1) / 2][ROWS / 2] = BLACKPON;
    arr[COLUMNS / 2][ (ROWS - 1) / 2] = BLACKPON; // Czarnym kamieniom nadajemy wartość 1.
    int player = 0; // Tworzymy zmienną pamiętającą czyj jest ruch.
    int stop = 0; // Zmienna trzymająca, czy gra się zakończyła.
    while (stop == 0){ // Sprawdzamy, czy gra się zatrzymała
        player = player % 2;
        check (arr, player); // Pokazujemy dozwolone ruchy aktualnego gracza.
        int m = getchar() -'a'; // Pobieramy ruch gracza.
        if (m == '=' -'a') stop = 1;
        else if (m == '-' -'a') {
            player++; // Gracz spasował, więc go zmieniamy.
            getchar();
        }
        else {
            int n = getchar () - '1'; // Pobieramy drugą współrzędną na której znajdzie się pionek.
            getchar();
            move( arr,  m,  n,  player);
            player++; // Gracz wykonał swój ruch, więc go zmieniamy.
        }

    }

}
