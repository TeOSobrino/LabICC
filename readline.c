#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char *readline();

int main(int argc, char **argv){

    char *line;
    char *last_name;
    int cont = 0;
    int last_name_size = 0;
    char exit = 0;
    do{
        //o programa armazena a linha atual, se a linha é par, o last_name é
        //armazenado, partindo do último indicie do nome e indo até um espaço em branco, ou
        //o indicie 0, o começo do nome.

        line = readline();
        int i = 0;
        int name_size = strlen(line);
        if(line[name_size-1] == '$'){
            line[name_size-1] = '\0';
            exit = 1;
        }
        if(cont %2 == 0){
            //aqui o last name é armazenado.

            last_name = NULL;
            i = name_size;

            while(line[i-1] != ' ' && i > 0){
                if(line[i] != ' '){
                    last_name = realloc(last_name, (++last_name_size)*sizeof(char));
                    last_name[last_name_size-1] = line[i-1];
                }
                else{ 
                    last_name[last_name_size] = line[i-1];
                }
                i--;
            }
        }
        printf("%s", line);
        if(cont %2 == 1){
            //aqui last name é impresso, após a impressão do nome.
            printf(" ");
            for(int j = 0; j < last_name_size; j++){
                printf("%c", last_name[last_name_size - j - 1]);
            }
            printf("\n");

            free(last_name);
            last_name_size = 0;
        }
        else printf("\n");
        
        cont++;
    }while(exit == 0);
    free(line);

    return 0;
}

char *readline(){

    char c = '\0';
    int i = 0;
    char *line = NULL;

    do{
        c = getchar();
        line = realloc(line, (++i)*sizeof(char));
        line[i-1] = c;
    }while(c != '\n' && c != '$');

    if(c == '\n') line[i - 1] = '\0';
    else line[i - 1] = '$';
    return line;
}