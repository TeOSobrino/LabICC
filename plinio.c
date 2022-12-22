#include<stdio.h>
#define L 32
#define C 65


int main(void){

    char esteira[L][C];

    for(int i = 0; i < L; i++){
        for(int j = 0; j < C; j++){
            if(j == 64){
                esteira[i][j] = '\n';
            }
            else esteira[i][j] = ' ';
        }
    }

    char c;
    int i = 0, j = 0;
    int cont = 0;

    while((c = getchar())!= EOF && cont < 2080){
        
        switch(c){
        
        case '\r':
            i++;
            j = 0;
            break;
        case '\n':
            i++;
            j = 0;
            break;
        default:
        esteira[i][j] = c;
            j++;
        }
        cont++;
    }

    char comecou = 0;
    char atual;
    char soma_lin, soma_col;
    int k = 0;
    int l = 0;

    while(atual != ']'){

        atual = esteira[l][k];

        if(atual == '['){
            
            comecou = 1;
            k+=2;
            atual = esteira[l][k];
        }

        if(comecou == 1){
            switch(atual){

            case '>':
                esteira[l][k] = '.';
                soma_col = 2;
                soma_lin = 0;
                k+=soma_col;
                break;
            case '<':
                esteira[l][k] = '.';
                soma_col = -2;
                soma_lin = 0;
                k+=soma_col;
                break;
            case 'v':
                esteira[l][k] = '.';
                soma_col = 0;
                soma_lin = 1;
                l += soma_lin;
                break;
            case '^':
                esteira[l][k] = '.';
                soma_col = 0;
                soma_lin = -1;
                l += soma_lin;
                break;
            case '#':
                l += soma_lin;
                k += soma_col;
                break;
            case ' ':
                printf("Falha na esteira.\n");
                atual = ']';
                break;
            case ']':
                printf("Ok.\n");
                break;
            case '.':
                printf("Loop infinito.\n");
                atual = ']';
                break;
            }
        }
        
        else{ 
            k++;
            if(j == 32){
                l++;
                k = 0;
            }
        }
    }

    for(int k = 0; k < L; k++){
        for( int m = 0; m < C; m++){
            printf("%c", esteira[k][m]);
        }
    }

    return 0;
}