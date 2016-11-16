#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main(int argc, char** argv){

 

  if (argc == 2){

    int i, j;

    int n = atoi(argv[1]);

 

    for (i=0 ; i<n ; i++){

      j = rand()%999999999;

      printf("%d \n", j);

    }

  }

  else{

    printf("Usage: nomeArquivoExecutavel <NumeroLinhas>\n");

  }

}
