#ifndef BASE_H
#define BASE_H

#include <iostream>
#include <cstdlib>
#include <chrono>
#include <fstream>

using namespace std;

// Merge Sort
void Merge(int vet[], int esq, int mid, int dir) {
    int n1 = mid - esq + 1;
    int n2 = dir - mid;

    int *L = new int[n1];
    int *R = new int[n2];

    for (int i = 0; i < n1; i++) L[i] = vet[esq + i];
    for (int j = 0; j < n2; j++) R[j] = vet[mid + 1 + j];

    int i = 0, j = 0, k = esq;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) vet[k++] = L[i++];
        else vet[k++] = R[j++];
    }
    while (i < n1) vet[k++] = L[i++];
    while (j < n2) vet[k++] = R[j++];

    delete[] L;
    delete[] R;
}

void MergeSort(int vet[], int esq, int dir) {
    if (esq >= dir) return;
    int mid = esq + (dir - esq) / 2;
    MergeSort(vet, esq, mid);
    MergeSort(vet, mid + 1, dir);
    Merge(vet, esq, mid, dir);
}

int particao1(int array[], int menor, int maior) {
    int pivo = array[menor];
    int i = menor + 1;

    for (int j = menor + 1; j <= maior; j++) {
        if (array[j] < pivo) {
            int temp = array[i];
            array[i] = array[j];
            array[j] = temp;
            i++;
        }
    }
    int temp = array[menor];
    array[menor] = array[i - 1];
    array[i - 1] = temp;
    return i - 1;
}

double QuickSort_v1(int array[], int menor, int maior) {
    clock_t inicio = clock();

    int *pilha = (int *)malloc((maior - menor + 1) * sizeof(int));
    int topo = -1;

    pilha[++topo] = menor;
    pilha[++topo] = maior;

    while (topo >= 0) {
        maior = pilha[topo--];
        menor = pilha[topo--];

        if (menor < maior) {
            int pivoIndex = particao1(array, menor, maior);
            if (pivoIndex - 1 - menor > maior - (pivoIndex + 1)) {
                pilha[++topo] = menor;
                pilha[++topo] = pivoIndex - 1;
                pilha[++topo] = pivoIndex + 1;
                pilha[++topo] = maior;
            } else {
                pilha[++topo] = pivoIndex + 1;
                pilha[++topo] = maior;
                pilha[++topo] = menor;
                pilha[++topo] = pivoIndex - 1;
            }
        }
    }

    free(pilha);
    clock_t fim = clock();
    return ((double)(fim - inicio)) / CLOCKS_PER_SEC;
}

// calcula a média de três elementos como pivô
int calculaPivoMedia(int vet[], int menor, int maior) {
    int inicio = vet[menor];
    int meio = vet[menor + (maior - menor) / 2];
    int fim = vet[maior];

    // Retorna a mediana dos três
    return (inicio + meio + fim) / 3;
}

void QuickSort_v2(int vet[], int menor, int maior) {
    if (menor >= maior) return; // Caso base

    int i = menor, j = maior;

    // Calcula o pivô usando a média
    int pivo = calculaPivoMedia(vet, menor, maior);

    // Particionamento
    do {
        while (vet[i] < pivo) i++;
        while (vet[j] > pivo) j--;
        if (i <= j) {
            // Troca manual dos elementos
            int aux = vet[i];
            vet[i] = vet[j];
            vet[j] = aux;
            i++;
            j--;
        }
    } while (i <= j);

    // Recursão para as duas partições
    if (menor < j) QuickSort_v2(vet, menor, j); // Lado esquerdo
    if (i < maior) QuickSort_v2(vet, i, maior); // Lado direito
}


// QuickSort_v3: Pivô aleatório
void QuickSort_v3(int vet[], int n) {
    if (n <= 1) return;

    int i = 0, j = n - 1;
    int pivo = vet[rand() % n];

    do {
        while (vet[i] < pivo) i++;
        while (vet[j] > pivo) j--;
        if (i <= j) {
            int aux = vet[i];
            vet[i] = vet[j];
            vet[j] = aux;
            i++;
            j--;
        }
    } while (i <= j);

    if (j > 0) QuickSort_v3(vet, j + 1);
    if (i < n) QuickSort_v3(&vet[i], n - i);
}

#endif // !BASE_H
