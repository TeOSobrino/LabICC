#include<stdio.h>
#include<stdlib.h>
#include<string.h>


typedef struct{
    int id, idade;
    char *nome, *curso;
}pessoas;

char *readline();
void preencher_struct(int num_alunos, pessoas *alunos);
pessoas *aumenta_num_alunos(int num_alunos, pessoas *alunos);
void buscar_aluno(int id_consulta, int num_alunos, pessoas *alunos);
void buscar_curso(char *curso_consulta, int num_alunos, pessoas *alunos);
void imprime_aluno(int i, pessoas *alunos);

int main(int argc, char *argv[]){

    int num_alunos = 0;
    int  controle; //avalia a entrada do usuário, se é -1 sai do laço.
    pessoas *alunos = NULL; //vetor da struct pessoas.
    scanf("%d", & controle);

    while( controle != -1){
        
        //função para aumentar o número de alunos; Aumenta o número de elementos no vetor.
        alunos = aumenta_num_alunos(num_alunos+1, alunos);
        
        alunos[num_alunos].id =  controle; //caso o número inserido não seja -1 ele é o Nusp 
        //do aluno.
        preencher_struct(num_alunos, alunos); //preenche os dados da struct atual
        //com o que pe fornecido pelo usuário.
        num_alunos++;

        scanf("%d", & controle);
    }

    scanf("%d", & controle);
    while( controle != -1){
        
        int id_consulta; //numero para consulta inserido pelo usário
        char *curso_consulta;
        switch(controle){
            case 1:

                scanf("%d", &id_consulta);
                buscar_aluno(id_consulta, num_alunos, alunos); //função que busca um id fornecido.

                break;
            case 2:

                curso_consulta = readline();
                buscar_curso(curso_consulta, num_alunos, alunos); //função que busca um curso fornceido.
                free(curso_consulta);

                break;
            case 3:
                for(int i = 0; i < num_alunos; i++){
                    imprime_aluno(i, alunos); //função para imprimir cada struct na ordem determinada.
                }

                break;
        }
        scanf("%d", & controle);
    }

    //o nome e o curso de cada aluno são guardados de forma dinâmica, assim após o término do programa devemos 
    //desalocar essa memória.
    for(int i = 0; i < num_alunos; i++){
        free(alunos[i].nome);
        free(alunos[i].curso);
    }
    //o vetor de structs também deve ser desalocado.
    free(alunos);
    
    return 0;
}

pessoas *aumenta_num_alunos(int num_alunos, pessoas *alunos){

    alunos = realloc(alunos, num_alunos*sizeof(pessoas));
    return alunos;
}

void preencher_struct(int num_alunos, pessoas *alunos){

    alunos[num_alunos].nome = readline();
    alunos[num_alunos].curso = readline();
    scanf("%d", &alunos[num_alunos].idade);
    
}

void buscar_aluno(int id_consulta, int num_alunos, pessoas *alunos){

    for(int i = 0; i < num_alunos; i++){

        if(id_consulta == alunos[i].id){
            imprime_aluno(i, alunos);
        }
    }
}


void buscar_curso(char *curso_consulta, int num_alunos, pessoas *alunos){

    for(int i = 0; i < num_alunos; i++){
        if(strcmp(curso_consulta, alunos[i].curso) == 0) imprime_aluno(i, alunos);
    }
}

void imprime_aluno(int i, pessoas *alunos){

    printf("Nome: %s\n", alunos[i].nome);
    printf( "Curso: %s\n", alunos[i].curso);
    printf( "N USP: %d\n", alunos[i].id);
    printf( "IDADE: %d\n", alunos[i].idade);
    printf( "%c", '\n');
    
}

char *readline(){
    char caractere_atual = '\0';
    int tam_frase = 0;
    char *frase = NULL;
    
    caractere_atual = getchar(); //tirar um possível \n depois da entrada de inteiros (id aluno).
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