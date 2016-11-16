#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
	int cont;
	char *line = malloc(sizeof(char*));
	FILE *file = fopen(argv[1],"r");
	while(fgets(line, 100, file) != NULL)
		cont++;
	printf("%d linhas", cont);
}
