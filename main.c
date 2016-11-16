#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mergesort.c"

#define MAXSIZELINE 100 //NÚMERO MÁXIMO DO TAMANHO DA LINHA
#define MAXLINES 100000001 //NÚMERO DE LINHAS DO ARQUIVO + 1

void OrdenaArquivo(char arquivo[]){
    int cont;
    int cont2;
    static int temp[MAXLINES];
    static int aux[MAXLINES];
    char *line = malloc(sizeof(char*));
    FILE *file = fopen(arquivo,"r");
    FILE *ordenado = fopen("ordenado.txt","wa");
        cont = 0;
        //ARMAZENA UM ARRAY DO ARQUIVO INTEIRO
        printf("Armazenando %s no array temp\n", arquivo);
        while(fgets(line, MAXSIZELINE, file) != NULL)
            temp[cont++] = atoi(line);

        //ORDENA O ARRAY TEMP NO ARRAY AUX
        printf("Ordenando o array temp no array aux\n");
        mergeSort(temp,aux,0,cont-1);

        //ESCREVENDO O ARRAY ORDENADO NO ARQUIVO ordenado.txt
        printf("Armazenando o array ordenado no arquivo ordenado.txt\n");
        for(cont2 = 0; cont2<cont;cont2++)
            fprintf(ordenado, "%d\n", aux[cont2]);
    close(file);
    close(ordenado);
    free(line);
}

int main()
{   //INSIRA AQUI O NOME DO ARQUIVO GERADO
    OrdenaArquivo("txt");
    return 0;
}
