#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

unsigned long long cont = 0; // contador geral

// contadores
#define C_CMP() (cont++)
#define C_MOV() (cont++)

// para imprimir depois no relatório
void gerarCSV(char nome[], int tam, char tipo[], unsigned long long passos, double tempo) {
    printf("%s,%d,%s,%llu,%.4f\n", nome, tam, tipo, passos, tempo);
}

// mostra o vetor se for pequeno
void mostrarVetor(int v[], int n) {
    if (n > 20) {
        printf("[muito grande]\n");
    } else {
        for (int i = 0; i < n; i++) {
            printf("%d ", v[i]);
        }
        printf("\n");
    }
}


void selection(int v[], int n) {
    int i, j, pos, aux;

    for (i = 0; i < n - 1; i++) {
        pos = i;

        for (j = i + 1; j < n; j++) {
            C_CMP();
            if (v[j] < v[pos]) {
                pos = j;
            }
        }

        if (pos != i) {
            aux = v[i];
            v[i] = v[pos];
            v[pos] = aux;
            C_MOV();
        }
    }
}


void merge(int v[], int inicio, int meio, int fim) {
    int tam1 = meio - inicio + 1;
    int tam2 = fim - meio;

    int *A = malloc(tam1 * sizeof(int));
    int *B = malloc(tam2 * sizeof(int));

    int i, j, k;

    for (i = 0; i < tam1; i++) {
        A[i] = v[inicio + i];
        C_MOV();
    }
    for (j = 0; j < tam2; j++) {
        B[j] = v[meio + 1 + j];
        C_MOV();
    }

    i = 0;
    j = 0;
    k = inicio;

    while (i < tam1 && j < tam2) {
        C_CMP();
        if (A[i] <= B[j]) {
            v[k] = A[i];
            i++;
            C_MOV();
        } else {
            v[k] = B[j];
            j++;
            C_MOV();
        }
        k++;
    }

    while (i < tam1) {
        v[k] = A[i];
        i++;
        k++;
        C_MOV();
    }

    while (j < tam2) {
        v[k] = B[j];
        j++;
        k++;
        C_MOV();
    }

    free(A);
    free(B);
}

void mergeRec(int v[], int inicio, int fim) {
    if (inicio < fim) {
        C_CMP();
        int meio = (inicio + fim) / 2;
        mergeRec(v, inicio, meio);
        mergeRec(v, meio + 1, fim);
        merge(v, inicio, meio, fim);
    }
}

void mergeSort(int v[], int n) {
    mergeRec(v, 0, n - 1);
}


int partir(int v[], int ini, int fim) {
    int pivo = v[fim];
    C_MOV();

    int i = ini - 1;
    int aux;

    for (int j = ini; j < fim; j++) {
        C_CMP();
        if (v[j] <= pivo) {
            i++;
            aux = v[i];
            v[i] = v[j];
            v[j] = aux;
            C_MOV();
        }
    }

    aux = v[i+1];
    v[i+1] = v[fim];
    v[fim] = aux;
    C_MOV();

    return i + 1;
}

void quickRec(int v[], int ini, int fim) {
    if (ini < fim) {
        C_CMP();
        int pi = partir(v, ini, fim);
        quickRec(v, ini, pi - 1);
        quickRec(v, pi + 1, fim);
    }
}

void quickSort(int v[], int n) {
    quickRec(v, 0, n - 1);
}


void rodarTeste(char nome[], void (*func)(int[], int)) {

    int *vet = NULL;
    int tamanho;
    char tipo[20];

    printf("\nRodar teste para %s\n", nome);
    printf("1 - RGM\n2 - Aleatório\n");
    printf("Escolha: ");
    int resp;
    scanf("%d", &resp);

    if (resp == 1) {
        char rgm[30];
        printf("Digite o RGM: ");
        scanf("%s", rgm);

        tamanho = strlen(rgm);
        vet = malloc(tamanho * sizeof(int));
        strcpy(tipo, "rgm");

        for (int i = 0; i < tamanho; i++) {
            vet[i] = rgm[i] - '0';
        }

    } else if (resp == 2) {
        printf("Digite tamanho N: ");
        scanf("%d", &tamanho);

        vet = malloc(tamanho * sizeof(int));
        strcpy(tipo, "aleatorio");

        for (int i = 0; i < tamanho; i++) {
            vet[i] = rand() % 10000;
        }

    } else {
        printf("Opcao invalida!\n");
        return;
    }

    if (tamanho <= 20) {
        printf("Entrada: ");
        mostrarVetor(vet, tamanho);
    }

    cont = 0;
    clock_t ini = clock();

    func(vet, tamanho);

    clock_t fim = clock();
    double tempo = (double)(fim - ini) * 1000.0 / CLOCKS_PER_SEC;

    if (tamanho <= 20) {
        printf("Saida: ");
        mostrarVetor(vet, tamanho);
    }

    printf("\nLinha CSV:\n");
    printf("metodo,N,caso,passos,tempo_ms\n");
    gerarCSV(nome, tamanho, tipo, cont, tempo);

    free(vet);
}



void menu() {
    int op = -1;
    srand(time(NULL));

    while (op != 0) {
        printf("\n=======================\n");
        printf("   MENU ORDENACAO\n");
        printf("=======================\n");
        printf("1 - Selection Sort\n");
        printf("2 - Merge Sort\n");
        printf("3 - Quick Sort\n");
        printf("0 - sair\n");
        printf("Opcao: ");
        scanf("%d", &op);

        if (op == 1) rodarTeste("selection", selection);
        else if (op == 2) rodarTeste("merge", mergeSort);
        else if (op == 3) rodarTeste("quick", quickSort);
        else if (op == 0) printf("Encerrando...\n");
        else printf("Opcao invalida!\n");
    }
}

int main() {
    menu();
    return 0;
}
