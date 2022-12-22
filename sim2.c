#include<stdio.h>
const int C = 66;

void atualizacao(char mat_orig[34][66], int i, int j, char mat_cop[34][66]);
int main(void){
    char mat_orig[34][C];
    char mat_cop[34][C];
    for(int i = 0; i < 34; i++){
        for(int j = 0; j < 66; j++){
            if(i == 0 || i == 33) mat_orig[i][j] = '@';
            else if(j == 0 || j == 65) mat_orig[i][j] = '@';
            else mat_orig[i][j] = ' ';
            mat_cop[i][j] = mat_orig[i][j];
        }
    }


    int n_frames, frame_atual, x, y;
    char nova_particula;

    scanf("%d", &n_frames);

    int contador = 0;
    while (contador < n_frames) {

        // `scanf` retorna EOF quando chega ao fim da entrada.
        int n_lido = scanf(" %d: %d %d %c", &frame_atual, &x, &y, &nova_particula);

        // Se não há mais partículas a serem criadas, continue até o final
        // da simulação.
        if (n_lido == EOF) {
            frame_atual = n_frames;
        }

        // Calcula todos os frames até o próximo frame onde queremos criar
        // uma partícula.
        while (contador < frame_atual) {
            printf("frame: %d\n", contador + 1);
            for(int i = 1; i < 33; i++){
                for(int j = 1; j < 65; j++){
                    printf("%c", mat_cop[i][j]);
                }
                printf("\n");
            }

            for(int i = 0; i < 34; i++){
                for(int j = 0; j < 66; j++){
                    mat_orig[i][j] = mat_cop[i][j];
                }
            }
     
            for(int j = 1; j < 65; j++){
                for(int i = 1; i < 33; i++){
                    switch(mat_orig[i][j]){
                    case '@':
                        break;
                    case' ':
                        break;
                    case'#':
                        atualizacao(mat_orig, i, j, mat_cop);
                        break;
                    case'~':
                        atualizacao(mat_orig, i, j, mat_cop);
                        break;
                    }
                }
            }
            contador++;
        }

        // Se há uma particula a ser criada, crie ela.
        if (n_lido != EOF) {
            mat_orig[y+1][x+1] = nova_particula;
        }
    }   
}

void atualizacao(char mat_orig[34][66], int i, int j, char mat_cop[34][66]){
    if(mat_orig[i][j] == '#'){
        if(mat_orig[i+1][j] == ' ' || mat_orig[i+1][j] == '~'){
            char tmp = mat_cop[i][j];
            mat_cop[i][j] = mat_cop[i+1][j];
            mat_cop[i+1][j] = tmp;
        }
        else if(mat_orig[i+1][j-1] == ' ' || mat_orig[i+1][j-1] == '~'){
            char tmp = mat_cop[i][j];
            mat_cop[i][j] = mat_cop[i+1][j-1];
            mat_cop[i+1][j-1] = tmp;
        }
        else if(mat_orig[i+1][j+1] == ' ' || mat_orig[i+1][j+1] == '~'){
            char tmp = mat_cop[i][j];
            mat_cop[i][j] = mat_cop[i + 1][j+1];
            mat_cop[i + 1][j+1] = tmp;
        }
    }
    else{

        if(mat_orig[i+1][j] == ' '){
            char tmp = mat_cop[i][j];
            mat_cop[i][j] = mat_cop[i + 1][j];
            mat_cop[i + 1][j] = tmp;
        }
        else if(mat_orig[i+1][j-1] == ' '){
            char tmp = mat_cop[i][j];
            mat_cop[i][j] = mat_cop[i + 1][j-1];
            mat_cop[i + 1][j-1] = tmp;
        }
        else if(mat_orig[i+1][j+1] == ' '){
            char tmp = mat_cop[i][j];
            mat_cop[i][j] = mat_cop[i + 1][j+1];
            mat_cop[i + 1][j+1] = tmp;
        }
    
        else if(mat_orig[i][j-1] == ' '){
            char tmp = mat_cop[i][j];
            mat_cop[i][j] = mat_cop[i][j-1];
            mat_cop[i][j-1] = tmp;
        }
        else if(mat_orig[i][j+1] == ' '){
            char tmp = mat_cop[i][j];
            mat_cop[i][j] = mat_cop[i][j+1];
            mat_cop[i][j+1] = tmp;
        }
    }
    
}
