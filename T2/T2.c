#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int descobre_linhas()
{

    int i,nlinhas=0;
    FILE *f = fopen ("alunos.txt","r");
    do{
            i=fgetc(f);
            if(i == '\n') nlinhas++;
    }while(i!= EOF);
    return nlinhas;
    fclose(f);
}


void le_alunos(int* matriculas1,char** nomes,int numlinha)
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
            matriculas1[linha]=mat;
            nomes[linha]=(char*)malloc((strlen(nome)+1)*sizeof(char));
            strcpy(nomes[linha],nome);

            if(linha!=numlinha) linha++;
    }
    fclose(f);
}


void le_notas(int* matriculas2, float* medianotas, int numlinha)
{
    int mat,linha=0;
    float nota1,nota2,media;
    FILE *f = fopen("notas.txt","r");
    while(linha<numlinha){
            fscanf(f,"%d %f %f",&mat,&nota1,&nota2);
            media=(nota1+nota2)/2;
            matriculas2[linha]=mat;
            medianotas[linha]=media;
            linha++;
    }
    fclose(f);
}

void busca_imprime(int *matriculas1, int *matriculas2, float *medianotas,int numlinha,char **nomes){
    int i,j;
    char nomedigitado[50];
    scanf("%s",&nomedigitado);
    for(i=0;i<numlinha;i++){
       if(strstr(nomes[i],nomedigitado)!=NULL){
            for(j=0;j<numlinha;j++){
                if(matriculas1[i]==matriculas2[j]){
                    printf("%s %.2f\n",nomes[i],medianotas[j]);
                }
            }

       }

    }
}

int main()
{

    int numlinha;
    char **nomes;
    int *matriculas1,*matriculas2;
    float *medianotas;
    int aux;

    numlinha=descobre_linhas();

    /* Aloca */
    nomes=(char**)malloc(numlinha*sizeof(char*));
    matriculas1=(int*)malloc(numlinha*sizeof(int));
    matriculas2=(int*)malloc(numlinha*sizeof(int));
    medianotas=(float*)malloc(numlinha*sizeof(float));


    /* Chama funções */
    le_alunos(matriculas1,nomes,numlinha);
    le_notas(matriculas2,medianotas,numlinha);
    busca_imprime(matriculas1,matriculas2,medianotas,numlinha,nomes);


    /* Desaloca */
    for(aux=0;aux<numlinha;aux++){
    free(nomes[aux]);
    }
    free(nomes);
    free(matriculas1);
    free(matriculas2);
    free(medianotas);


    return 0;
}
