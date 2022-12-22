#include<stdio.h>
#define R 26


int main(void){

    int rt1[R], rt2[R], rt3[R];

    //ignora - Rotores: \n
    scanf("%*[^\r\n]s");

    for(int i = 0; i < R; i++) scanf("%d", &rt1[i]);

    for(int i = 0; i < R; i++) scanf("%d", &rt2[i]);

    for(int i = 0; i < R; i++) scanf("%d", &rt3[i]);
    
    // ignora o \n
    scanf("%*[\r\n]s");

    char char_encript;
    unsigned char char_decript;
    int gira1 = 0, gira2 = 0;

    //ignora - Mensagem: \n
    scanf("%*[^\r\n]s");
    scanf("%*[\r\n]s");
    
    char_encript = 'a';
    
    while(char_encript != EOF){

        char_encript = getchar();
        if(char_encript == EOF) break;

        int confere = char_encript; //um inteiro recebe o char, para que seu código ascii seja comparado
        //com os limites do alfabeto e determinar se será ou não decriptado
        
        //Pela tabela ascii: 'A' = 65, 'Z' = 90, 'a' = 97, 'z' = 122;
        if((confere >= 65 && confere<= 90) || (confere >= 97 && confere <= 122)){

            int soma;
            //para decriptar o char, devemos somar o valor contido no rotor 3 em:
            //rt3[rt2[rt1['%c']]], onde '%c' é o caractere de entrada, ou seja, o
            //confere, porém seu valor deve ser padronizado com 'A' = 'a' = 0, 'Z' = 'z' = 25.
            if(char_encript <= 90){
                confere -= 65;
                soma = rt3[rt2[rt1[confere]]];
                char_decript = 65 + soma;
            }
            else {
                confere -= 97;
                soma = rt3[rt2[rt1[confere]]];
                char_decript = 97 + soma;
            }

            //caso o caracetere tenha passado de 'Z' ou 'z' ele deve voltar 26 posições ('z' + 1 = 'a').
            if(char_decript > 122) char_decript -= 26;
            if(char_encript <= 90 && char_decript > 90) char_decript -= 26;

            int aux;
            //aqui ocorre o giro dos rotores, a posição 0 é salva, a posição 1 ocupa a posição 0,
            //em seguida a 2 ocupa a 1, e assim por diante, até a posição 25 ocupar a 24,
            // então a posição 0 ocupa a 25.
            aux = rt1[0];
            for(int i = R-1; i > 0; i--){
                rt1[R-i-1] = rt1[R-i];
            }
            rt1[25] = aux;

            gira1++;
            if(gira1 == 26){

                gira1 = 0;
                aux = rt2[0];
                for(int i = R-1; i > 0; i--){

                    rt2[R-i-1] = rt2[R-i];
                }
                rt2[25] = aux;

                gira2++;

                if(gira2 == 26){

                    gira2 = 0;
                    aux = rt3[0];
                    for(int i = R-1; i > 0; i--){

                        rt3[R-i-1] = rt3[R-i];
                    }
                    rt3[25] = aux;
                }
            }

            printf("%c", char_decript);

        }
        else printf("%c", char_encript);
    }

    return 0;
}
