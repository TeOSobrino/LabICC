#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void){
    
    char proibido[13][10] = {{"gratuito"}, {"atencao "} ,{"urgente "}, {"imediato"}, {"zoombie "}, 
    {"oferta  "}, {"dinheiro"}, {"renda   "}, {"fundo  "}, {"limitado"}, {"ajuda   "}, {"SOS     "}, {"zoombies"}};

    char atual;
    char cont_proibido = 0;
    int tam_atual = 0;
    int tam_lin = 0;
    char palavra_atual[10] = {"        "};

    while((atual = getchar()) != EOF){

        if(atual != '\r' || atual != '\n'){
            tam_lin++;
            if(tam_lin >= 77 && cont_proibido < 3){
                cont_proibido = 3;
                printf("Spam");
                break;
            }
        }
        else{ 

            tam_lin = 0;
        }
        
        while(isalpha(atual) && tam_atual < 10){
            palavra_atual[tam_atual] = atual;
            atual = getchar();
            tam_lin++;
            tam_atual++;
        }


        if(tam_atual == 10){

            while(!(atual == ' ' || atual == '\n' || atual == '\r'|| ispunct(atual))){
                
                atual = getchar();
                tam_lin++;
                if(tam_lin >77 && cont_proibido < 3){
                    printf("Spam");
                    cont_proibido = 3;
                    break;
                }
            }
            if(atual == ' '){
                tam_lin +=0;
            }

            else{
                tam_lin = 0;
            }

            for(int i = 0; i < 10; i++){
                palavra_atual[i] = ' ';
            }
            tam_atual = 0;
        }

        

        if((atual == ' ' || atual == '\n' || atual == '\r'|| ispunct(atual)) && tam_atual > 0){
            if(atual == ' '){
                tam_lin +=0;
            }

            else{
                tam_lin = 0;
            }
            int avalia = 1;
            for(int i = 0; i < 13; i++){

                for(int i = 0; i < 13; i++){
                    for(int j = 0; j < 8; j++){

                        if(proibido[i][j] == palavra_atual[j]){
                            avalia = 0;
                        }
                        else{
                            avalia = 1;
                            break;
                        } 
                    }
                    if(!avalia) break;
                }
                
                if(avalia == 0){

                    cont_proibido++;
                    if(cont_proibido == 2){
                        printf("Spam");
                        break;
                    }
                    for(int i = 0; i < tam_atual; i++){
                        palavra_atual[i] = ' ';
                    }
                    tam_atual = 0;
                    break;
                }
            }

            if(avalia != 0){
                for(int i = 0; i < tam_atual; i++){
                    palavra_atual[i] = ' ';
                }
                tam_atual = 0;
            }
            else if(cont_proibido>=2) break;

        }
    }
    if(cont_proibido < 2){
        printf("Inbox");
    }
    
}