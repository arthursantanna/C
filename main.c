// Arthur Silva Santana 10420550
// Daniel Monteiro Malacarne 10420454
// Murillo Henrique Sakamoto 10426242

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 10000   // Número máximo de palavras
#define MAX_LEN 100       // Comprimento máximo de cada palavra

// Função de ordenação Insertion Sort
int insertion_sort(char palavras[][MAX_LEN], int tamanho) {
    int cont = 0;
    char key[MAX_LEN];
    int i, j;

    for (i = 1; i < tamanho; i++) {
        strcpy(key, palavras[i]);
        j = i - 1;

        // Desloca os elementos que são maiores que a 'key' uma posição à frente
        while (j >= 0 && strcasecmp(palavras[j], key) > 0) {
            strcpy(palavras[j + 1], palavras[j]);
            j--;
            cont++;  // Contagem de comparações
        }
        strcpy(palavras[j + 1], key);
        cont++;  // Contagem de comparações
    }
    return cont;
}

// Função de mesclagem usada no Merge Sort com contador de passos
void merge(char palavras[][MAX_LEN], int left, int mid, int right, int *contador) {
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Arrays temporários para armazenar as duas metades
    char L[n1][MAX_LEN], R[n2][MAX_LEN];

    // Copia os dados para os arrays temporários
    for (i = 0; i < n1; i++)
        strcpy(L[i], palavras[left + i]);
    for (j = 0; j < n2; j++)
        strcpy(R[j], palavras[mid + 1 + j]);

    i = 0;  // Índice inicial do primeiro subarray
    j = 0;  // Índice inicial do segundo subarray
    k = left;  // Índice inicial do array mesclado

    // Mescla os arrays temporários de volta no array original
    while (i < n1 && j < n2) {
        (*contador)++;  // Incrementa o contador para cada comparação
        if (strcasecmp(L[i], R[j]) <= 0) {
            strcpy(palavras[k], L[i]);
            i++;
        } else {
            strcpy(palavras[k], R[j]);
            j++;
        }
        k++;
    }

    // Copia os elementos restantes de L[], se houver
    while (i < n1) {
        strcpy(palavras[k], L[i]);
        i++;
        k++;
    }

    // Copia os elementos restantes de R[], se houver
    while (j < n2) {
        strcpy(palavras[k], R[j]);
        j++;
        k++;
    }
}

// Função principal do Merge Sort com contador de passos
void merge_sort(char palavras[][MAX_LEN], int left, int right, int *contador) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        // Ordena a primeira e segunda metades
        merge_sort(palavras, left, mid, contador);
        merge_sort(palavras, mid + 1, right, contador);

        // Mescla as metades ordenadas
        merge(palavras, left, mid, right, contador);
    }
}

int main(void) {
    FILE *file_in, *file_out, *file_out2;
    char filename_in[] = "in.txt";
    char filename_out[] = "out1.txt";
    char filename_out2[] = "out2.txt";
    char palavras[MAX_WORDS][MAX_LEN]; // Array para armazenar até 10.000 palavras
    int tamanho = 0;

    // Abre o arquivo de entrada
    file_in = fopen(filename_in, "r");
    if (file_in == NULL) {
        printf("Erro ao abrir o arquivo de entrada.\n");
        return 1;
    }

    // Lê as palavras do arquivo de entrada
    while (fscanf(file_in, "%s", palavras[tamanho]) != EOF && tamanho < MAX_WORDS) {
        tamanho++;
    }
    fclose(file_in);  // Fecha o arquivo de entrada

    // Ordena as palavras usando Insertion Sort
    int passos_insertion = insertion_sort(palavras, tamanho);

    // Abre o arquivo de saída
    file_out = fopen(filename_out, "w");
    if (file_out == NULL) {
        printf("Erro ao abrir o arquivo de saída.\n");
        return 1;
    }

    // Escreve as palavras ordenadas no arquivo de saída
    for (int i = 0; i < tamanho; i++) {
        fprintf(file_out, "%s\n", palavras[i]);
    }
    fclose(file_out);  // Fecha o arquivo de saída
    
    // Contador para o Merge Sort
    int passos_merge = 0;

    // Ordena as palavras usando Merge Sort
    merge_sort(palavras, 0, tamanho - 1, &passos_merge);

    // Abre o arquivo de saída 2
    file_out2 = fopen(filename_out2, "w");
    if (file_out2 == NULL) {
        printf("Erro ao abrir o arquivo de saída.\n");
        return 1;
    }

    // Escreve as palavras ordenadas no arquivo de saída 2
    for (int i = 0; i < tamanho; i++) {
        fprintf(file_out2, "%s\n", palavras[i]);
    }
    fclose(file_out2);  // Fecha o arquivo de saída 2

    // Exibe a contagem de passos
    printf("Número de passos do Insertion Sort: %d\n", passos_insertion);
    printf("Número de passos do Merge Sort: %d\n", passos_merge);

    return 0;
}
