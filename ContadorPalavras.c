#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000

int busca_binaria_recursiva(char *palavras[], int menor, int maior, char *word) {
    if (menor > maior) {
        return -1;
    }

    int meio = (menor + maior) / 2;
    int cmp = strcmp(palavras[meio], word);

    if (cmp == 0) {
        return meio;
    } else if (cmp < 0) {
        return busca_binaria_recursiva(palavras, meio + 1, maior, word);
    } else {
        return busca_binaria_recursiva(palavras, menor, meio - 1, word);
    }
}

int compara(const void *a, const void *b) {
    return strcmp(*(const char **)a, *(const char **)b);
}

int main() {
    FILE *file;
    char filename[] = "arquivo.txt"; 
    char word[100];
    char *palavras[MAX_WORDS]; 
    int counts[MAX_WORDS] = {0};
    int numWords = 0;

    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    while (fscanf(file, "%s", word) != EOF) {
        for (int i = 0; word[i]; i++) {
            word[i] = tolower(word[i]);
        }

        int index = busca_binaria_recursiva(palavras, 0, numWords - 1, word);

        if (index != -1) {
            counts[index]++;
        } else {
            palavras[numWords] = strdup(word);
            counts[numWords] = 1;
            numWords++;

            for (int i = numWords - 1; i > 0 && strcmp(palavras[i], palavras[i - 1]) < 0; i--) {
                char *tempWord = palavras[i];
                palavras[i] = palavras[i - 1];
                palavras[i - 1] = tempWord;

                int tempCount = counts[i];
                counts[i] = counts[i - 1];
                counts[i - 1] = tempCount;
            }
        }
    }

    for (int i = 0; i < numWords; i++) {
        printf("%s, %d\n", palavras[i], counts[i]);
    }
    printf("Total de palavras diferentes no dicionário: %d\n", numWords);

    for (int i = 0; i < numWords; i++) {
        free(palavras[i]);
    }

    fclose(file);
    return 0;
}
