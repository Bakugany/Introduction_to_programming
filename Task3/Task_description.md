# Wprowadzenie

Rozważamy realizację języka programowania **Pętlik**. Składnię języka opisuje następująca gramatyka z symbolem początkowym **Program**:

```
Program → CiągInstrukcji
CiągInstrukcji → ε | CiągInstrukcji Instrukcja
Instrukcja → Zwiększ | Powtarzaj
Zwiększ → Zmienna
Powtarzaj → '(' Zmienna CiągInstrukcji ')'
Zmienna → 'a' | ... | 'z'
```

Program składa się jedynie ze znaków ujętych w apostrofy. Żadne inne znaki, nawet spacje czy znaki nowej linii, nie mogą wystąpić w kodzie źródłowym.

Program ma dostęp do 26 zmiennych, których wartości są nieujemnymi liczbami całkowitymi. Instrukcje wyprowadzone z symbolu **CiągInstrukcji** są wykonywane sekwencyjnie, od pierwszej do ostatniej.

- **Instrukcja Zwiększ**, reprezentowana przez pojedynczą zmienną, jest równoważna instrukcji w języku C:
  ```
  ++zmienna;
  ```
- **Instrukcja Powtarzaj**, w postaci `(zmienna ... )`, jest równoważna następującej konstrukcji w języku C:
  ```
  while (zmienna > 0) {
      --zmienna;
      ...
  }
  ```

Realizacja języka **Pętlik** składa się z dwóch głównych części:
1. **Kompilator optymalizujący**, który generuje kod przeznaczony dla maszyny wirtualnej.
2. **Interpreter**, który wykonuje kod tej maszyny.

## Instrukcje Maszyny

Maszyna wirtualna wykonuje następujące polecenia:

- **INC Zmienna**  
  Zwiększa wartość zmiennej o 1.

- **ADD Zmienna0 Zmienna1**  
  Dodaje do zmiennej **Zmienna0** wartość zmiennej **Zmienna1**.

- **CLR Zmienna**  
  Ustawia wartość zmiennej **Zmienna** na 0.

- **JMP Adres**  
  Skacze do instrukcji znajdującej się pod adresem **Adres**.

- **DJZ Zmienna Adres**  
  Jeśli wartość zmiennej **Zmienna** wynosi 0, wykonuje skok do instrukcji o adresie **Adres**; w przeciwnym przypadku dekrementuje wartość **Zmienna** o 1.

- **HLT**  
  Zakończa wykonywanie programu.

Wykonanie programu maszynowego zaczyna się od pierwszej instrukcji. Jeśli instrukcja nie wskazuje inaczej, po jej wykonaniu następuje przejście do kolejnej instrukcji. Kod wygenerowany dla programu kończy się instrukcją **HLT**.

### Optymalizacja Instrukcji Powtarzaj

Jeżeli instrukcja **Powtarzaj** nie zawiera zagnieżdżonej instrukcji **Powtarzaj**, czyli wewnątrz nawiasów znajduje się ciąg zmiennych `Zmienna0, ..., ZmiennaN` (dla N ≥ 0) i żadna z zmiennych `Zmienna1, ..., ZmiennaN` nie jest równa **Zmienna0**, to kompilator może wygenerować zoptymalizowany kod o następującej postaci:
```
ADD Zmienna1 Zmienna0
...
ADD ZmiennaN Zmienna0
CLR Zmienna0
```
W przeciwnym razie generowany jest kod zwykły.

Kod zwykły dla:
- **Instrukcji Zwiększ** (`Zmienna`):
  ```
  INC Zmienna
  ```
- **Instrukcji Powtarzaj** (`(Zmienna ... )`):
  ```
  DJZ Zmienna Koniec
  ...
  JMP Początek
  ```
  gdzie **Początek** oznacza adres pierwszej instrukcji ciągu, a **Koniec** adres instrukcji następującej bezpośrednio po ciągu.

## Polecenie

Napisz program będący realizacją języka **Pętlik**.

Program powinien obsługiwać dwa rodzaje poleceń:

1. **Wypisanie wartości zmiennej:**  
   Polecenie rozpoczynające się od znaku `=` i zawierające nazwę zmiennej. Program wypisuje wartość tej zmiennej w postaci dziesiętnej, bez zer wiodących (wartość 0 reprezentowana jako `0`, natomiast liczby dodatnie zaczynają się od cyfry różnej od zera).

2. **Wykonanie programu w języku Pętlik:**  
   Wiersz zawiera kod źródłowy programu w języku **Pętlik**. Przed wykonaniem pierwszego polecenia wszystkie zmienne mają wartość 0. Po wykonaniu programu zmienne zachowują swoje zmienione wartości; nie są one resetowane przed kolejnym wykonaniem.

## Postać Danych

Dane wejściowe programu stanowią ciąg wierszy, z których każdy zawiera jedno polecenie:
- Wiersz zaczynający się od znaku `=` służy do wypisania wartości zmiennej.
- Wiersz zawierający kod źródłowy w języku **Pętlik** służy do wykonania tego programu.

## Postać Wyniku

Wynik programu to ciąg wierszy wypisanych w wyniku polecenia wypisania wartości zmiennych. Każda wartość wypisywana jest w osob ▋
