Contagem de Palavras com Busca Binária Recursiva

Descrição
Este programa em C realiza a contagem de palavras em um arquivo de texto, ignorando diferenças entre letras maiúsculas e minúsculas. Ele utiliza uma busca binária recursiva para verificar se uma palavra já foi encontrada anteriormente. Se a palavra já existir na lista, seu contador é incrementado. Caso contrário, a palavra é adicionada à lista e a lista é reordenada para manter a ordem alfabética.

Funcionalidades
Leitura de arquivo: O programa lê palavras de um arquivo de texto.
Conversão para minúsculas: Todas as palavras são convertidas para minúsculas para garantir que a contagem seja insensível a maiúsculas.
Busca binária recursiva: Utiliza busca binária recursiva para localizar palavras já existentes na lista.
Inserção ordenada: Insere novas palavras na lista mantendo a ordem alfabética.
Contagem de palavras: Conta quantas vezes cada palavra aparece no arquivo.
Exibição do resultado: Exibe a lista de palavras e suas respectivas contagens, assim como o número total de palavras diferentes encontradas.
Estrutura do Código
busca_binaria_recursiva: Função recursiva que realiza a busca binária em um array de strings.
compara: Função auxiliar usada para comparar strings ao ordenar o array.
main: Função principal que realiza a leitura do arquivo, a contagem das palavras e exibe os resultados.
