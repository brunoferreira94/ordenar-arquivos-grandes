#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXSIZELINE 100
#define MAXLINES 10

void DivideBlocos(char txt[])
{
    int cont = 0;
    int numTemp = 0;
    char tempChar[20] = "temp0.txt";
    char *line = malloc(sizeof(char*));
    FILE *file = fopen(txt,"r");
    FILE *temp = fopen(tempChar,"wa");
    printf("Criado %s\n", tempChar);

    while(fgets(line, MAXSIZELINE, file) != NULL){
        fprintf(temp, line);
        cont++;

        if(cont == MAXLINES){
            fclose(temp);
            numTemp++;
            sprintf(tempChar,"temp%d.txt", numTemp);
            temp = fopen(tempChar,"wa");
            printf("Criado %s\n", tempChar);
            cont = 0;
            }
            if(!temp){
                printf("temp não existe");
                exit(0);
            }
        }
	fclose(temp);
	fclose(file);
	}

int main()
{
    DivideBlocos("texto.txt");
    return 0;
}
