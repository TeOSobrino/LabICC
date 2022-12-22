
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *readline();//faz a leitura de uma linha
char *aumenta_frase_tabu(char *frase_sem_tabu, int aumento);//aloca o tamanho da frase sem tabu.

int main(int argc, char *argv[]){
    char palavra_tabu[20];
    scanf("%s", palavra_tabu);
    int tam_tabu = strlen(palavra_tabu);
    
    char *frase;
    frase = readline();
    int tam_frase = (strlen(frase));
    char *frase_sem_tabu = NULL;

    int ultimo_indicie_permitido = 0; //posição do último índicie da frase
    //depois do término de uma palavra tabu.
    int indicie_tabu = 0;
    int tam_frase_sem_tabu = 0;
    int cont_tabu = 0;

    for(int i = 0; i < tam_frase; i++){
       //para cada letra na frase, comparamos ela com a letra da palavra tabu;

        if(palavra_tabu[indicie_tabu] == frase[i]){
            //se as letras forem iguais aumentamos o indicie da palavra tabu e repetimos;

            indicie_tabu++;
            if(indicie_tabu == tam_tabu){
                //caso todas as letras da palavra tabu estejam na frase, guardamos na string frase_sem_tabu 
                //a frase desde o ultimo indicie permitido, até um char antes do início da palavra tabu
                //e atualizamos este indicie para uma posição depois do término da palavra tabu;

                cont_tabu ++;
                for(int k = ultimo_indicie_permitido; k <= (i - tam_tabu); k++){
                    frase_sem_tabu = aumenta_frase_tabu(frase_sem_tabu, ++tam_frase_sem_tabu);
                    frase_sem_tabu[tam_frase_sem_tabu-1] = frase[k];
                }
                ultimo_indicie_permitido = i+1;
                indicie_tabu = 0;
            }
        }
        else{
            //se a letra não corresponder, voltamos a comparar com o início da palavra tabu;

            indicie_tabu = 0;
        }

        if(i == tam_frase - 1){
            //ao atingirmos o final da frase, devemos guardar desde o último indicie permitido
            //até o fim na frase sem tabu;

            for(int k = ultimo_indicie_permitido; k <= i; k++){
                frase_sem_tabu = aumenta_frase_tabu(frase_sem_tabu, ++tam_frase_sem_tabu);
                frase_sem_tabu[tam_frase_sem_tabu-1] = frase[k];
            }

            free(frase);
        }
    }
    printf("A palavra tabu foi encontrada %d vezes \nFrase: ", cont_tabu);
    
    for(int i = 1; i < tam_frase_sem_tabu; i++){
        //como a entrada é do tipo: Palavra tabu \n frase, frase[0] = frase_sem_tabu[0] = '\n'
        //assim devemos iniciar do índicie 1;

        printf("%c", frase_sem_tabu[i]);
    }
    printf("\n");

    free(frase_sem_tabu);

    return 0;
}

char *readline(){
    char caractere_atual = '\0';
    int tam_frase = 0;
    char *frase = NULL;
    
    do{
        caractere_atual = getchar();
        frase = realloc(frase, (++tam_frase)*sizeof(char));
        frase[tam_frase-1] = caractere_atual;
        if(caractere_atual == '$'){
            frase[tam_frase-1] = '\0';
            break;
        }
        
    }while(caractere_atual != '$');
    
    return frase;
}
char *aumenta_frase_tabu(char *frase_sem_tabu, int aumento){

    frase_sem_tabu = realloc(frase_sem_tabu, aumento*sizeof(char));

    return frase_sem_tabu;

}