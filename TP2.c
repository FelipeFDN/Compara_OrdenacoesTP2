/**
 * @file TP2.c
 * @author Felipe_Daniel_Nerling
 * @version 1.0
 * @date 2023-11-17
 *
 * @copyright Copyright (c) 2023
 *
 *
  * Atenção: Antes de entregar, conferir se dos dados acima da documentação estão
 * preenchidos corretamente.
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void copia(long *A, long *v, int size);
void bubbleSort(long *A, int size);
void selectionSort(long *A, int size);
void insertionSort(long *A, int size);
void quickSort(long *A, long start, long end, long *swapcont);

void heapSort(long *A, int size);
void radixSort(long *A, int size, long *swapcont);

long partition_random(long *vet, long start, long end, long *swapcont);

void swap (long *a, long *b);
long partition(long arr[], long low, long high, long *swapcont);

void heapify(long *A, int size, int i, long *swapcont);


int main(){

	int i;
	int tamanhoVetor = 100000;
    long vetor[tamanhoVetor];

    srand(time(NULL));

    for (i = 0 ; i < tamanhoVetor ; i++)
        vetor[i] = (rand() % tamanhoVetor);

	printf("\nVetor original: ");
	for (i = 0 ; i < tamanhoVetor ; i++)
    	printf("%ld ", vetor[i]);

	printf("\nVetor tamanho = %d\n\n", tamanhoVetor);

	// bubble sort
	long *bubbleVec = (long *)malloc(tamanhoVetor * sizeof(long));;
	copia(vetor, bubbleVec, tamanhoVetor);
    clock_t begin = clock();
    printf("\nBubble sort: \n");
	bubbleSort(bubbleVec, tamanhoVetor);
    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	printf("\nTempo: %f\n\n", time_spent);
	/*for (i = 0 ; i < tamanhoVetor ; i++)
    	printf("%ld ", bubbleVec[i]);*/
	printf("\n");
    free(bubbleVec);

	// selection sort
    long *SelectVec = (long *)malloc(tamanhoVetor * sizeof(long));;
	copia(vetor, SelectVec, tamanhoVetor);
    begin = clock();
    printf("\nSelection sort: \n");
	selectionSort(SelectVec, tamanhoVetor);
    end = clock();
    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	printf("\nTempo: %f\n\n", time_spent);
	/*for (i = 0 ; i < tamanhoVetor ; i++)
    	printf("%ld ", SelectVec[i]);*/
	printf("\n");
    free(SelectVec);

	// insertion sort
    long *InsertVec = (long *)malloc(tamanhoVetor * sizeof(long));;
	copia(vetor, InsertVec, tamanhoVetor);
    printf("\nInsertion sort: \n");
    begin = clock();
	insertionSort(InsertVec, tamanhoVetor);
    end = clock();
    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	printf("\nTempo: %f\n\n", time_spent);
	/*for (i = 0 ; i < tamanhoVetor ; i++)
    	printf("%ld ", InsertVec[i]);*/
	printf("\n");
    free(InsertVec);

	// quick sort
    long *QuickVec = (long *)malloc(tamanhoVetor * sizeof(long));
	copia(vetor, QuickVec, tamanhoVetor);
    printf("\nQuick sort: ");
    begin = clock();
    long swapcont = 0;
	quickSort(QuickVec, 0, tamanhoVetor-1, &swapcont);
    end = clock();
    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	printf("\nTrocas: %ld\nTempo: %f\n\n", swapcont, time_spent);
	/*for (i = 0 ; i < tamanhoVetor ; i++)
    	printf("%ld ", QuickVec[i]);*/
	printf("\n");
    free(QuickVec);

    // heap sort
    long *HeapVec = (long *)malloc(tamanhoVetor * sizeof(long));
    copia(vetor, HeapVec, tamanhoVetor);
    printf("\nHeap sort: ");
    begin = clock();
    heapSort(HeapVec, tamanhoVetor);
    end = clock();
    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("\nTempo: %f\n\n", time_spent);
    /*for (i = 0; i < tamanhoVetor; i++)
        printf("%ld ", HeapVec[i]);*/
    printf("\n");
    free(HeapVec);

    //Radix sort
    long *RadixVec = (long *)malloc(tamanhoVetor * sizeof(long));
    copia(vetor, RadixVec, tamanhoVetor);
    printf("\nRadix sort: ");
    begin = clock();
    long swapcontradx = 0;
    radixSort(RadixVec, tamanhoVetor, &swapcontradx);
    end = clock();
    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("\nTrocas: %ld\nTempo: %f\n\n", swapcontradx, time_spent);
    /*for (i = 0; i < tamanhoVetor; i++)
        printf("%ld ", RadixVec[i]);*/
    printf("\n");
    free(RadixVec);

	return 0;
}

void copia(long *A, long *V, int size){
	int i;
	for (i = 0 ; i < size ; i++)
    	     V[i] = A[i];
}

void bubbleSort(long *A, int size){
   // implementação do Bubble
   int i, j, t;
   long cont = 0;   
    for (i = 0; i < size; i++) {   
        for (j = i + 1; j < size; j++) {   
            if (*(A + j) < *(A + i)) {   
                swap((A + j), (A + i)); 
                cont++;
            } 
        } 
    }printf("Trocas: %ld", cont);   
}

void printArray(int n, long* ptr) {
  for (int i = 0; i < n; ++i) {
    printf("%ld  ", ptr[i]);
  }
  printf("\n");
}

void swap (long *a, long *b){
   long temp=(*b);
   *b=*a;
   *a=temp;
};

void insertionSort(long *A, int size){
    // Implementação do Insertion
    int i,j, min, t;
    long cont=0;
    for (i = 1; i < size; i++) {   
        min=A[i];
        for (j=i; j>=1 && min< A[j-1];j--){
            A[j]=A[j-1]; 
            cont++;  
        }   
        A[j]=min;
    }printf("Trocas: %ld", cont); 
}

void selectionSort(long *A, int size){
    // Implementação do Selection
    long cont = 0;
    for (int i = 0; i < size - 1; i++) {
        int min_index = i;
        //find min index
        for (int j = i + 1; j < size; j++) {
            if (A[j] < A[min_index]) {
                min_index = j;

            }
        }
        //swap
        if (min_index != i) {
            long temp = A[i];
            A[i] = A[min_index];
            A[min_index] = temp;
            cont++;
        }
    }printf("Trocas: %ld", cont); 
}

void quickSort(long A[], long start, long end, long *swapcont){
    // Implementação do Quick
    if (start < end) {
        // Encontra o índice de partição, arr[p] está agora no lugar correto
        long pi = partition_random(A, start, end, swapcont);
        // Recursivamente ordena os elementos antes e depois da partição
        quickSort(A, start, pi - 1, swapcont);
        quickSort(A, pi + 1, end, swapcont);
    }
}

long partition(long arr[], long low, long high, long *swapcont) {
    long pivot = arr[high]; // Escolhe o último elemento como pivô
    long i = (low-1);    // O índice do menor elemento
    for (long j = low; j <= high - 1; j++) {
        // Se o elemento atual for menor ou igual ao pivô
        if (arr[j] <= pivot) {
            i++; // Incrementa o índice do menor elemento
            
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i+1], &arr[high]);
    (*swapcont)++;
    return (i + 1);
}

long partition_random(long *vet, long start, long end, long *swapcont)
{
	// seleciona um número entre fim (inclusive) e inicio (inclusive)
	long pivo_indice = (rand() % (end - start + 1)) + start;
	
	// faz a troca para colocar o pivô no fim
	swap(&vet[pivo_indice], &vet[end]);
	// chama a particiona
	return partition(vet, start, end, swapcont);
}

void heapify(long *A, int size, int i, long *swapcont) {
    int largest = i; // Inicializa o maior como raiz
    int left = 2 * i + 1; // índice do filho à esquerda
    int right = 2 * i + 2; // índice do filho à direita

    // Se o filho à esquerda é maior que a raiz
    if (left < size && A[left] > A[largest])
        largest = left;

    // Se o filho à direita é maior que o maior até agora
    if (right < size && A[right] > A[largest])
        largest = right;

    // Se o maior não é a raiz
    if (largest != i) {
        swap(&A[i], &A[largest]);
        (*swapcont)++;
        // Recursivamente heapify a subárvore afetada
        heapify(A, size, largest, swapcont);
    }
}

void heapSort(long *A, int size){
    long swapcont = 0;

    // Constrói o heap (rearranja o array)
    for (int i = size / 2 - 1; i >= 0; i--)
        heapify(A, size, i, &swapcont);

    // Extrai elementos um por um do heap
    for (int i = size - 1; i > 0; i--) {
        // Move a raiz atual para o final
        swap(&A[0], &A[i]);
        swapcont++;
        // chama max heapify no heap reduzido
        heapify(A, i, 0, &swapcont);
    }
    printf("\nTrocas: %ld", swapcont);
}

// Função para realizar a ordenação por contagem no Radix Sort
void countingSort(long *A, int size, long exp, long *swapcont) {
    long output[size]; // Array de saída
    int count[10] = {0};

    // Contagem do número de ocorrências em count[]
    for (int i = 0; i < size; i++)
        count[(A[i] / exp) % 10]++;

    // Altera count[i] para que contenha a posição real desse dígito em output[]
    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];

    // Constrói o array de saída
    for (int i = size - 1; i >= 0; i--) {
        output[count[(A[i] / exp) % 10] - 1] = A[i];
        count[(A[i] / exp) % 10]--;
        (*swapcont)++;
    }

    // Copia o array de saída de volta para A[] para atualizar
    for (int i = 0; i < size; i++)
        A[i] = output[i];
}

// Função principal do Radix Sort
void radixSort(long *A, int size, long *swapcont) {
    // Encontrar o número máximo para saber o número de dígitos
    long max = A[0];
    for (int i = 1; i < size; i++)
        if (A[i] > max)
            max = A[i];

    // Realiza a ordenação para cada dígito
    for (long exp = 1; max / exp > 0; exp *= 10)
        countingSort(A, size, exp, swapcont);
}