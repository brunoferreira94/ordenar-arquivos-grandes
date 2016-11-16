#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void intercala (int v[],int aux[],int ini1, int ini2,int fim2)
{
    int in1=ini1, in2=ini2, fim1=in2-1, au=0, i;

    while(in1<=fim1 && in2<=fim2)
    {
        if (v[in1]<v[in2])
        {
            aux[au++] = v[in1++];
        }
        else
        {
            aux[au++] = v[in2++];
        }
    }
    while(in1<=fim1)
    {
        aux[au++] = v[in1++];
    }
    while(in2<=fim2)
    {
        aux[au++] = v[in2++];
    }

    for(i=0; i<au; i++)
    {
        v[i+ini1]=aux[i];
    }
}

void mergeSort (int v[], int aux[],int inicio, int fim)
{
    int meio;
    if(inicio<fim)
    {
        meio=(inicio+fim)/2;
        mergeSort(v,aux,inicio,meio);
        mergeSort(v,aux,meio+1,fim);
        intercala(v,aux,inicio,meio+1,fim);
    }
}
/*
int main()
{
    int tamanho = 10000;
    int v[tamanho];
    int aux[tamanho];
    int i;

    srand(time(NULL));

    for(i=0; i<tamanho; i++)
        v[i] = (int) rand() %100;

    mergeSort(v,aux,0,tamanho-1);

    for(i=0; i<tamanho; i++)
        printf("%d ",v[i]);

    return 0;
}
*/
