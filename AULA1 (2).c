#include <stdio.h>

main()
{
    int matricula;
    char nome[100];
    FILE *arq;

    printf("Matricula: ");
    scanf("%d", &matricula);
    printf("Nome: ");
    scanf("%s", nome);

    arq = fopen("saida.txt", "w");
    fprintf(arq,"%d %s \n", matricula, nome);
    //fprintf(stdout, "ola \n");

    fscanf(arq,"%d %s", &matricula, nome);
    printf("%d %s\n", matricula, nome);

    fclose(arq);
}
