#include <iostream>
using namespace std;

const int N = 10;
int A[N];
int M = 0, C = 0;

void FillInc(int A[], int N) {
    for (int i = 0; i < N; i++)
        A[i] = i + 1;
}

void FillDec(int A[], int N) {
    int x = N;
    for (int i = 0; i < N; i++) {
        A[i] = x--;
    }
}

void FillRand(int A[], int N) {
    srand(time(NULL));
    for (int i = 0; i < N; i++)
        A[i] = rand() % 10 + 1;
}

int CheckSum() {
    int y = 0;
    for (int i = 0; i < N; i++)
        y += A[i];
    return y;
}

int RunNumber() {
    int count = 0;
    for (int i = 0; i < N-1; i++) {
        if (A[i] > A[i + 1]) {
            count += 1;
        }
    }
    count += 1;
    return count;
}

void PrintMas() {
    for (int i = 0; i < N; i++)
        cout << A[i] << " ";
    cout << endl;
}

void SelectSort(int array[], int size) { 
    M = 0, C = 0;
    for (int i = 0; i < size - 1; i++) {
        int min = i;        
            for (int j = i + 1; j < size; j++) {
                C++;
                if (array[j] < array[min]) {
                    min = j;
                }
            }
                swap(array[i], array[min]);
                M += 3;
    }
}

void BubbleSort(int array[], int size) { 
    M = 0, C = 0;
    for (int i = 0; i < size - 1; i++) {
        for (int j = size - 1; j > i ; j--) {
            C++;
            if (array[j] < array[j - 1]) {
                swap(array[j], array[j - 1]);
                M += 3;
            }
        }
    }
}

void ShakerSort(int array[], int size) {
    M = 0, C = 0;
    int Left = 0, Right = size - 1, k = size - 1;
    do {
        for (int j = Right; j > Left; j--) {
            C++;
            if (array[j] < array[j - 1]) {
                swap(array[j], array[j - 1]);
                M += 3;
                k = j;
            }
        }
        Left = k;
        for (int j = Left; j < Right; j++) {
            C++;
            if (array[j] > array[j + 1]) {
                swap(array[j], array[j + 1]);
                M += 3;
                k = j;
            }
        }
        Right = k;
    } while (Left < Right);
}

int main() {
    cout << "INCREASING MASSIVE\n";
    FillInc(A, N);
    PrintMas();
    cout << CheckSum() << endl << RunNumber() << endl;

    cout << "\nDECREASING MASSIVE\n";
    FillDec(A, N);
    PrintMas();
    cout << CheckSum() << endl << RunNumber() << endl;

    cout << "\nRANDOM MASSIVE\n";
    FillRand(A, N);
    PrintMas();
    cout << CheckSum() << endl << RunNumber() << endl; }