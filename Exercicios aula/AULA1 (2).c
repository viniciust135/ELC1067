#include <stdio.h>

void main(){
    int matricula;
    char nome[50];
    FILE *arq;

    printf("Matricula: ");
    scanf("%d", &matricula);
    printf("Primeiro nome: ");
    scanf("%s", nome);

    arq = fopen("saida.txt", "w");
    fprintf(arq,"%d %s \n", matricula, nome);

    fscanf(arq,"%d %s", &matricula, nome);
    printf("%d %s\n", matricula, nome);

    fclose(arq);

}
