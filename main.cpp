#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <time.h>
#include <cmath>

using namespace std;
const int N = 10;
int A[N];
int M = 0, C = 0;
int K = 0;

    //1st lab
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
void InsertSort(int array[], int size) {
    M = 0, C = 0;
    int temp, j;
    for (int i = 1; i < size; i++) {
        temp = array[i]; 
        M++;
        j = i - 1;
        C++;
        while ((j >= 0) && (temp < array[j])) {
            array[j + 1] = array[j];
            if (j == i - 1) {
                C--;
            }
            M++; 
            C++;
            j = j - 1;
        }
        array[j + 1] = temp; 
        M++;
    }
}
void ShellSort(int array[], int size) {
    M = 0, C = 0;
    int max = 0, temp = size;
    while (temp >= 2) {
        temp /= 2;
        max++;
    }
    max-=1;
    int* Steps;
    Steps = new int[max];
    Steps[0] = 1;
    for (int k = 1; k < max; k++) {
        Steps[k] = 2 * Steps[k - 1] + 1;
    }
    for (int i = max - 1, t; i >= 0; i--) {
        int k = Steps[i];
        for (int j = k ; j < size; j++) {                
            temp = array[j];
            M++;
            t = j - k;
            C++;
            while ((t >= 0) && (temp < array[t])) {
                array[t + k] = array[t];
                M++;
                t -= k;
            }
            array[t + k] = temp;
            M++;
        }
    
    }
    Steps = NULL;
    K = max;
}

int main() {
    //2nd lab
    cout << "SelectSort\n\n";
    cout << "INCREASING MASSIVE\n";
    FillInc(A, N);
    PrintMas();
    cout << CheckSum() << endl << RunNumber() << endl;
    SelectSort(A, N);
    PrintMas();
    cout << CheckSum() << endl << RunNumber() << endl;
    cout << "Fakticheskie M = " << M << " C = " << C << endl; 
    cout << "Theoretical: M = " << 3 * (N - 1) << " C = " << (N * N - N) / 2;
    
    cout << "\n\nDECREASING MASSIVE\n";
    FillDec(A, N);
    PrintMas();
    cout << CheckSum() << endl << RunNumber() << endl;
    SelectSort(A, N);
    PrintMas();
    cout << CheckSum() << endl << RunNumber() << endl;
    cout << "Fakticheskie M = " << M << " C = " << C << endl;
    cout << "Theoretical: M = " << 3 * (N - 1) << " C = " << (N * N - N) / 2;
    
    cout << "\n\nRANDOM MASSIVE\n";
    FillRand(A, N);
    PrintMas();
    cout << CheckSum() << endl << RunNumber() << endl;
    SelectSort(A, N);
    PrintMas();
    cout << CheckSum() << endl << RunNumber() << endl;
    cout << "Fakticheskie M = " << M << " C = " << C << endl;
    cout << "Theoretical: M = " << 3 * (N - 1) << " C = " << (N * N - N) / 2;


    //3d lab
    cout << "\n\nBubbleSort\n";
    cout << "\nINCREASING MASSIVE\n";
    FillInc(A, N);
    PrintMas();
    cout << CheckSum() << endl << RunNumber() << endl;
    BubbleSort(A, N);
    PrintMas();
    cout << CheckSum() << endl << RunNumber() << endl;
    cout << "Theoretical: M = " << 0 << " C = " << (N*N - N)/2;
    cout << "\nFakticheskie M = " << M << " C = " << C << endl; 
    
    cout << "\n\nDECREASING MASSIVE\n";
    FillDec(A, N);
    PrintMas();
    cout << CheckSum() << endl << RunNumber() << endl;
    BubbleSort(A, N);
    PrintMas();
    cout << CheckSum() << endl << RunNumber() << endl;
    cout << "Fakticheskie M = " << M << " C = " << C << endl; 
    cout << "Theoretical: M = " << 3*((N*N - N)/2) << " C = " << (N*N - N)/2;
    
    cout << "\n\nRANDOM MASSIVE\n";
    FillRand(A, N);
    PrintMas();
    cout << CheckSum() << endl << RunNumber() << endl;
    BubbleSort(A, N);
    PrintMas();
    cout << CheckSum() << endl << RunNumber() << endl;
    cout << "Fakticheskie M = " << M << " C = " << C << endl; 
    cout << "Theoretical: M = " << (3*((N*N - N)/2))/2 << " C = " << (N*N - N)/2; 
   
   
int I[100]; 
    cout << "\nN        Dec        Rand       Inc\n";
    FillDec(I, 100);
    BubbleSort(I, 100);
    cout << "100      " << M + C;
    FillRand(I, 100);
    BubbleSort(I, 100);
    cout << "      " << M + C;
    FillInc(I, 100);
    BubbleSort(I, 100);
    cout << "      " << M + C << endl;
int G[200];
    FillDec(G, 200);
    BubbleSort(G, 200);
    cout << "200      " << M + C;
    FillRand(G, 200);
    BubbleSort(G, 200);
    cout << "      " << M + C;
    FillInc(G, 200);
    BubbleSort(G, 200);
    cout << "      " << M + C << endl;
int J[300];
    FillDec(J, 300);
    BubbleSort(J, 300);
    cout << "300      " << M + C;
    FillRand(J, 300);
    BubbleSort(J, 300);
    cout << "      " << M + C;
    FillInc(J, 300);
    BubbleSort(J, 300);
    cout << "      " << M + C << endl;
int L[400];
    FillDec(L, 400);
    BubbleSort(L, 400);
    cout << "400      " << M + C;
    FillRand(L, 400);
    BubbleSort(L, 400);
    cout << "      " << M + C;
    FillInc(L, 400);
    BubbleSort(L, 400);
    cout << "      " << M + C << endl;    
int O[500];
    FillDec(O, 500);
    BubbleSort(O, 500);
    cout << "500      " << M + C;
    FillRand(O, 500);
    BubbleSort(O, 500);
    cout << "      " << M + C;
    FillInc(O, 500);
    BubbleSort(O, 500);
    cout << "      " << M + C << endl; 
    
   
    //4th lab
    cout << "\n\nShakerSort\n";
    cout << "\nINCREASING MASSIVE\n";
    FillInc(A, N);
    PrintMas();
    cout << CheckSum() << endl << RunNumber() << endl;
    ShakerSort(A, N);
    PrintMas();
    cout << CheckSum() << endl << RunNumber() << endl;
    cout << "Fakticheskie M = " << M << " C = " << C << endl;
    cout << "Theoretical: M = " << 0 << " C = " << (N * N - N) / 2;
    
    cout << "\n\nDECREASING MASSIVE\n";
    FillDec(A, N);
    PrintMas();
    cout << CheckSum() << endl << RunNumber() << endl;
    ShakerSort(A, N);
    PrintMas();
    cout << CheckSum() << endl << RunNumber() << endl;
    cout << "Fakticheskie M = " << M << " C = " << C << endl;
    cout << "Theoretical: M = " << 3 * ((N * N - N) / 2) << " C = " << (N * N - N) / 2;
    
    cout << "\n\nRANDOM MASSIVE\n";
    FillRand(A, N);
    PrintMas();
    cout << CheckSum() << endl << RunNumber() << endl; 
    ShakerSort(A, N);
    PrintMas();
    cout << CheckSum() << endl << RunNumber() << endl;
    cout << "Fakticheskie M = " << M << " C = " << C << endl;
    cout << "Theoretical: M = " << (3 * ((N * N - N) / 2)) / 2 << " C = " << (N * N - N) / 2;

int B[100]; 
    cout << "\nN        Dec        Rand       Inc        Dec        Rand       Inc\n";
    FillDec(B, 100);
    BubbleSort(B, 100);
    cout << "100      " << M + C;
    FillRand(B, 100);
    BubbleSort(B, 100);
    cout << "      " << M + C;
    FillInc(B, 100);
    BubbleSort(B, 100);
    cout << "      " << M + C;
    FillDec(B, 100);
    ShakerSort(B, 100);
    cout << "      " << M + C;
    FillRand(B, 100);
    ShakerSort(B, 100);
    cout << "      " << M + C;
    FillInc(B, 100);
    ShakerSort(B, 100);
    cout << "      " << M + C;
    cout << endl;
int U[200];
    FillDec(U, 200);
    BubbleSort(U, 200);
    cout << "200      " << M + C;
    FillRand(U, 200);
    BubbleSort(U, 200);
    cout << "      " << M + C;
    FillInc(U, 200);
    BubbleSort(U, 200);
    cout << "      " << M + C;
    FillDec(U, 200);
    ShakerSort(U, 200);
    cout << "      " << M + C;
    FillRand(U, 200);
    ShakerSort(U, 200);
    cout << "      " << M + C;
    FillInc(U, 200);
    ShakerSort(U, 200);
    cout << "      " << M + C;
    cout << endl;
int D[300];
    FillDec(D, 300);
    BubbleSort(D, 300);
    cout << "300      " << M + C;
    FillRand(D, 300);
    BubbleSort(D, 300);
    cout << "      " << M + C;
    FillInc(D, 300);
    BubbleSort(D, 300);
    cout << "      " << M + C;
    FillDec(D, 300);
    ShakerSort(D, 300);
    cout << "      " << M + C;
    FillRand(D, 300);
    ShakerSort(D, 300);
    cout << "      " << M + C;
    FillInc(D, 300);
    ShakerSort(D, 300);
    cout << "      " << M + C;
    cout << endl;
int E[400];
    FillDec(E, 400);
    BubbleSort(E, 400);
    cout << "400      " << M + C;
    FillRand(E, 400);
    BubbleSort(E, 400);
    cout << "      " << M + C;
    FillInc(E, 400);
    BubbleSort(E, 400);
    cout << "      " << M + C;
    FillDec(E, 400);
    ShakerSort(E, 400);
    cout << "      " << M + C;
    FillRand(E, 400);
    ShakerSort(E, 400);
    cout << "      " << M + C;
    FillInc(E, 400);
    ShakerSort(E, 400);
    cout << "      " << M + C;
    cout << endl;
int F[500];
    FillDec(F, 500);
    BubbleSort(F, 500);
    cout << "500      " << M + C;
    FillRand(F, 500);
    BubbleSort(F, 500);
    cout << "      " << M + C;
    FillInc(F, 500);
    BubbleSort(F, 500);
    cout << "      " << M + C;
    FillDec(F, 500);
    ShakerSort(F, 500);
    cout << "      " << M + C;
    FillRand(F, 500);
    ShakerSort(F, 500);
    cout << "      " << M + C;
    FillInc(F, 500);
    ShakerSort(F, 500);
    cout << "      " << M + C;

    //5th lab
    cout << "\n\nInsertSort\n";
    cout << "\n\nINCREASING MASSIVE\n";
    FillInc(A, N);
    PrintMas();
    cout << CheckSum() << endl << RunNumber() << endl;
    InsertSort(A, N);
    PrintMas();
    cout << CheckSum() << endl << RunNumber() << endl;
    cout << "Fakticheskie M = " << M << " C = " << C << endl;
    cout << "Theoretical: M = " << 2 * (N - 1) << " C = " << N - 1;
    
    cout << "\n\nDECREASING MASSIVE\n";
    FillDec(A, N);
    PrintMas();
    cout << CheckSum() << endl << RunNumber() << endl;
    InsertSort(A, N);
    PrintMas();
    cout << CheckSum() << endl << RunNumber() << endl;
    cout << "Fakticheskie M = " << M << " C = " << C << endl;
    cout << "Theoretical: M = " << (N * N - N) / 2 + 2 * N - 2 << " C = " << (N * N - N) / 2;
    
    cout << "\n\nRANDOM MASSIVE\n";
    FillRand(A, N);
    PrintMas();
    cout << CheckSum() << endl << RunNumber() << endl;
    InsertSort(A, N);
    PrintMas();
    cout << CheckSum() << endl << RunNumber() << endl;
    cout << "Fakticheskie M = " << M << " C = " << C << endl;
    cout << "Theoretical: M = " << (N * N - N)/2 + 2 * N - 2 << " C = " << (N * N - N) / 2;


    int Tab[25];
    for (int i = 0; i < 25; i += 5) {
        Tab[i] = 100 + (20 * i);
    }
    cout << endl;
    int t = 0;
    for (int i = 100; i <= 500; i += 100) {
        int* P;
        P = new int[i];
        if (P == NULL) {
            return 1;
        }
        t++;
        FillRand(P, i);
        SelectSort(P, i);
        Tab[t] = M + C; t++;
        FillRand(P, i);
        BubbleSort(P, i);
        Tab[t] = M + C; t++;
        FillRand(P, i);
        ShakerSort(P, i);
        Tab[t] = M + C; t++;
        FillRand(P, i);
        InsertSort(P, i);
        Tab[t] = M + C; t++;
        P = NULL;
    }
    cout << "\n n      Select      Bubble      Shaker      Insert\n";
    for (int i = 0; i < 25; i++) {
        if ((i % 5 == 0) && (i != 0)) {
            cout << endl;
        }
        cout << Tab[i] << "      ";
    }


    //6th lab
    cout << "\n\nShellSort" << endl;
    cout << "\nINCREASING MASSIVE\n";
    FillInc(A, N);
    PrintMas();
    cout << CheckSum() << endl << RunNumber() << endl;
    ShellSort(A, N);
    PrintMas();
    cout << CheckSum() << endl << RunNumber() << endl;
    cout << "Fakticheskie M = " << M << " C = " << C << endl;
    cout << "Theoretical: M = " << pow(N, 1.5) << " C = " << pow(N, 1.5);
    
    cout << "\n\nDECREASING MASSIVE\n";
    FillDec(A, N);
    PrintMas();
    cout << CheckSum() << endl << RunNumber() << endl;
    ShellSort(A, N);
    PrintMas();
    cout << CheckSum() << endl << RunNumber() << endl;
    cout << "Fakticheskie M = " << M << " C = " << C << endl;
    cout << "Theoretical: M = " << pow(N, 1.5) << " C = " << pow(N, 1.5);

    cout << "\n\nRANDOM MASSIVE\n";
    FillRand(A, N);
    PrintMas();
    cout << CheckSum() << endl << RunNumber() << endl;
    ShellSort(A, N);
    PrintMas();
    cout << CheckSum() << endl << RunNumber() << endl;
    cout << "Fakticheskie M = " << M << " C = " << C << endl;
    cout << "Theoretical: M = " << pow(N, 1.5) << " C = " << pow(N, 1.5);
    
    int Tabb[20];
    for (int i = 0; i < 20; i += 4) {
        Tab[i] = 100 + (100 * (i/4));
    }
    cout << endl;
    int tt = 0;
    for (int i = 100; i <= 500; i += 100) {
        int* P;
        P = new int[i];
        if (P == NULL) {
            return 1;
        }
        t++;
        FillRand(P, i);
        ShellSort(P, i);
        Tab[t] = K; t++;
        Tab[t] = M + C; t++;
        FillRand(P, i);
        InsertSort(P, i);
        Tab[t] = M + C; t++;
        P = NULL;
    }
    cout << "\n n      K-sorts      Shell      Insert\n";
    for (int i = 0; i < 20; i++) {
        if ((i % 4 == 0) && (i != 0)) {
            cout << endl;
        }
        cout << Tab[i] << "      ";
    }
    cout << endl;
}
