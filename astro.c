#include<stdio.h>

int main(void){

    unsigned int N, L, P, i=0, j=0, l=0, count =1, c=1;
    char sign_i, sign_j;
    
    scanf("%u", &N);

    L = N*N;

    scanf("%u", &P);

    if(P>L)
    printf("O astronauta ja saiu em missao ha %d chamadas.\n", P-L);
    
    else if(P==N)
    printf("O astronauta esta na posicao: %d %d\nPreste atencao, astronauta, chegou a sua vez!\n", (N/2), (N/2));
    
    else{
        sign_i = 1;
        sign_j = 0;

        for(int k=1; k<(P-1); k++){
            
           
                
            if(k==((c*N)-l)){
                count +=1;
                c+=1;

                if(sign_i==0 && count%2==0){
                    printf("entrei no sign_i = 1");
                    sign_i = 1;
                }

                else if(sign_i==0 && count%2 ==1){
                    printf("entrei no sign_i = -1");
                    sign_i= -1;
                }

                else {
                    printf("entrei no sign_i = 0");
                    sign_i = 0;
                }
            }

            printf("k = %d\n\nsign_i=%d\ni=%d\ncount=%d\n", k, sign_i, i, count);
            if(count == 2){
                count = 0;
                l+=1;
            }
            

            i+=sign_i;
            j+=sign_j;


        }
    printf("O astronauta esta na posicao: %d %d\nAinda faltam %d chamadas para a sua vez!\n", i, j, L-P);


    }

    

    return 0;
}