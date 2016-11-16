#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mergesort.c"

#define MAXSIZELINE 100
#define MAXLINES 50000001

void DivideBlocos(char txt[])
{
    int cont = 0;
    int numTemp = 0;
    char tempChar[20] = "temp0.txt";
    char *line = malloc(sizeof(char*));
    FILE *file = fopen(txt,"r");
    FILE *temp = fopen(tempChar,"wa");
    printf("Criando %s\n", tempChar);

    //ATÉ AS LINHAS DO ARQUIVO DE TEXTO ACABAR É ARMAZENADO SUAS LINHAS EM ARQUIVOS TEMP
    while(fgets(line, MAXSIZELINE, file) != NULL)
    {
        fprintf(temp, line);
        cont++;

        //SE O ARQUIVO ATINGIR O LIMITE DE LINHAS...
        if(cont == MAXLINES)
        {
            //FECHA O ARQUIVO TEMP ANTERIOR E CRIA UM NOVO
            fclose(temp);
            numTemp++;
            sprintf(tempChar,"temp%d.txt", numTemp);
            temp = fopen(tempChar,"wa");
            printf("Criando %s\n", tempChar);
            cont = 0;
            //VERIFICA SE TEMP FOI CRIADO
            if(!temp){
                printf("%s não foi criado corretamente.", tempChar);
                exit(0);
            }
        }
    }
    //FECHA OS ARQUIVOS RESTANTES ABERTOS
	fclose(temp);
	fclose(file);
	free(line);
    printf("DivideBlocos terminado\nIniciando OrdenaPedaços\n");
}

void OrdenaPedacos(){
    int numTemp = 1;
    int cont;
    int cont2;
    static int temp[MAXLINES];
    static int aux[MAXLINES];
    char *line = malloc(sizeof(char*));
    char tempChar[20] = "temp0.txt";
    FILE *file = fopen(tempChar,"r");

    do{
        cont = 0;
        //ARMAZENA UM ARRAY DO ARQUIVO INTEIRO
        printf("Armazenando %s no array temp\n", tempChar);
        while(fgets(line, MAXSIZELINE, file) != NULL)
            temp[cont++] = atoi(line);

        //ORDENA O ARRAY DO ARQUIVO
        printf("Ordenando o array temp\n");
        mergeSort(temp,aux,0,cont-1);

        //ABRE O ARQUIVO NOVAMENTE COM PERMISSOES DE ESCRITA E APPEND
        file = fopen(tempChar,"wa");

        //SOBREPÕE O ARQUIVO TEMP COM O ARRAY ORDENADO
        printf("Armazenando o array ordenado no arquivo %s\n", tempChar);
        for(cont2 = 0; cont2<cont-1;cont2++)
            fprintf(file, "%d\n", aux[cont2]);

        fclose(file);
        sprintf(tempChar,"temp%d.txt", numTemp++);
        file = fopen(tempChar,"r");
    }
    while(file);
    close(file);
    free(line);
}

int main()
{
    DivideBlocos("txt");
    OrdenaPedacos();

    return 0;
}
