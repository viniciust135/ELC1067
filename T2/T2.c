#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int descobre_linhas(){

    int i,nlinhas=0;
    FILE *f = fopen ("alunos.txt","r");
    do{
            i=fgetc(f);
            if(i == '\n') nlinhas++;
    }while(i!= EOF);
    return nlinhas;
}

void le_alunos(int matriculas[],char nomes[][],int nlinhas)
{
    int mat,i,linha=0;
    char c;
    char nome[50];
    FILE *f = fopen("alunos.txt","r");
    while(feof(f) ==0){
            if(fscanf(f,"%d",&mat)==0){
                break;
            }
            i=0;
            c=fgetc(f);
            while(c==' '){
                c=fgetc(f);
            }
            while(c!='\n' && c!=EOF){
              nome[i]=c;
              c=fgetc(f);
              i++  ;
            }
            nome[i]='\0';
            matriculas[linha]=mat;
            strcpy(nomes[linha],nome);
            linha++;
    }
    fclose(f);
}

void le_notas(float medianotas[], int numlinha)
{

    int mat,linhamedia=0;
    float nota1,nota2,media;
    FILE *f = fopen("notas.txt","r");
    while(linhamedia<numlinha){
            fscanf(f,"%d %f %f",&mat,&nota1,&nota2);
            media=(nota1+nota2)/2;
            medianotas[linhamedia]=media;
            linhamedia++;
    }
    fclose(f);
}

void busca_imprime(float medianotas[],int numlinha,char nomes[][50]){
    int i;
    char name[50];
    scanf("%s", &name);
    i=0;
    while(i<numlinha){
       if(strstr(nomes[i],name)!=NULL){
           printf("%s %.2f\n",nomes[i],medianotas[i]);
       }
    i++;
    }
}



main()
{
    char nomes[50][50];
    int matriculas[50],numlinha;
    float medianotas[50];


    numlinha=le_alunos(matriculas,nomes);
    le_notas(medianotas,numlinha);
    busca_imprime(medianotas,numlinha,nomes);
}
