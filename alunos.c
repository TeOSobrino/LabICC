#include<stdio.h>
#include<stdlib.h>
#include<string.h>


struct pessoas{
    
    int id, idade;
    char *nome, *curso;
};

char *readline();
void preencher_struct(int num_alunos, struct pessoas *alunos);
struct pessoas *aumenta_num_alunos(int num_alunos, struct pessoas *alunos);
void buscar_aluno(int registro, int num_alunos, struct pessoas *alunos);
void buscar_curso(char *curso_consulta, int num_alunos, struct pessoas *alunos);
void imprime_aluno(int i, struct pessoas *alunos);

int main(int argc, char *argv[]){

    int num_alunos = 0;
    int  controle;
    struct pessoas *alunos = NULL;
    scanf("%d", & controle);

    do{
        alunos = aumenta_num_alunos(num_alunos+1, alunos);
        
        alunos[num_alunos].id =  controle;
        preencher_struct(num_alunos, alunos);
        num_alunos++;

        scanf("%d", & controle);
    }while( controle != -1);

    scanf("%d", & controle);

    do{
        int registro;
        char *curso_consulta;
        switch(controle){
            case 1:

                scanf("%d", &registro);
                buscar_aluno(registro, num_alunos, alunos);

                break;
            case 2:

                curso_consulta = readline();
                buscar_curso(curso_consulta, num_alunos, alunos);

                break;
            case 3:
                for(int i = 0; i < num_alunos; i++){
                    imprime_aluno(i, alunos);
                }

                break;
        }
        
        scanf("%d", & controle);
    }while( controle != -1);
    free(alunos);
    
    return 0;
}

struct pessoas *aumenta_num_alunos(int num_alunos, struct pessoas *alunos){

    alunos = realloc(alunos, num_alunos*sizeof(struct pessoas));
    return alunos;
}

void preencher_struct(int num_alunos, struct pessoas *alunos){

    alunos[num_alunos].nome = readline();
    alunos[num_alunos].curso = readline();
    scanf("%d", &alunos[num_alunos].idade);
}

void buscar_aluno(int registro, int num_alunos, struct pessoas *alunos){

    for(int i = 0; i < num_alunos; i++){

        if(registro == alunos[i].id){
            imprime_aluno(i, alunos);
        }
    }
}


void buscar_curso(char *curso_consulta, int num_alunos, struct pessoas *alunos){

    for(int i = 0; i < num_alunos; i++){
        if(strcmp(curso_consulta, alunos[i].curso) == 0) imprime_aluno(i, alunos);
    }
}

void imprime_aluno(int i, struct pessoas *alunos){
    printf("Nome: %s\n", alunos[i].nome);
    printf("Curso: %s\n", alunos[i].curso);
    printf("N USP: %d\n", alunos[i].id);
    printf("IDADE: %d\n", alunos[i].idade);
    printf("\n");
}

char *readline(){
    char caractere_atual = '\0';
    int tam_frase = 0;
    char *frase = NULL;
    
    caractere_atual = getchar(); //tirar o \n depois da entrada.
    if(caractere_atual != '\n'){
        frase = realloc(frase, (++tam_frase)*sizeof(char));
        frase[tam_frase-1] = caractere_atual;
    }
    do{
        caractere_atual = getchar();
        frase = realloc(frase, (++tam_frase)*sizeof(char));
        frase[tam_frase-1] = caractere_atual;

    }while(caractere_atual != '\n' && caractere_atual != EOF);
    frase[tam_frase-1] = '\0';
    
    return frase;
}