#include<stdio.h>

int main(void){

    int n, m, p;
    scanf("%d %d %d", &n, &m, &p);
    p--;

    int repeticoes = 1, posicao = 0;
    int num_ciclos = 0, frase_atual = 0;

    int fim_seq = 3, conta_repeticoes = 0; //definimos a sequencia como as 3 frases ditas
    //e o ciclo como sendo uma rodada completa.

    while(posicao < n){

        int vez_pingu = (p + (num_ciclos * m));
        

        if(posicao == vez_pingu){

            switch(frase_atual){
            case 0:
                if(posicao == 0) printf("1 pinguim\n");
                else if(conta_repeticoes==0) printf("%d pinguins\n", repeticoes+1);
                else printf("%d pinguins\n", repeticoes);
                break;
            case 1: 
                printf("no gelo\n");
                break;
            case 2:
                printf("uhuu!\n");
                break;
            }
        }

        posicao++;
        
        //passou uma rodada
        if(posicao % m == 0){
            num_ciclos++;
        }

        //caso a sequencia tenha terminado
        if(posicao > fim_seq){

            repeticoes++;

            fim_seq+=(repeticoes*3);
        }   

        if(posicao <= fim_seq){
            
            conta_repeticoes++;

            if(repeticoes <= conta_repeticoes){ 

                frase_atual++;
                frase_atual %= 3;
                conta_repeticoes=0;
            }
        }
        
    }

    return 0;
}