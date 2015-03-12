#include <stdio.h>

void le_alunos(int* matriculas,char* nomes, int* n){
    int mat,i,linha;
    char c;
    char nome[50]
    FILE *f=fopen("alunos.txt","r");
    linha=0;
    while(feof(f) !=0){
            if(fscanf(f,"%d",&mat)==0){
                break;
            }
            i=0;
            c=fgetc(f);
            while(c==' '){
                c=fgetc(f);
            }
            while(c!='\n'){
              nome[i]=c;
              c=fgetc(f);
              i++  ;
            }
            nome[i]='\0';
            matriculas[linha]=mat;
            strcpy(nomes[linha],nome);
            linha++;
    }
    n=linha;
    fclose(f);
    }

}

}

/*int main (int argc, char **argv){
    char *nome
    if(argc>1){
        nome=argv[1];
    }
    printf("%s\n", nome);
}*/

/*fopen/fclose
fgetc/feof
fscanf/strcmp*/

