#include<stdio.h>
#include<stdlib.h>

int main(int argc, char *argv[]){

    FILE *arq_in;
    FILE *arq_out;

    arq_in = stdin; //a entrada padrão é o teclado.
    if((arq_out = fopen("temp.c", "w+")) == NULL){
        printf("Erro ao criar arquivo.\n");
        exit(1);
    } 

    //temos que printar o cabeçalho padrão, e a função main no arquivo temporário.
    fprintf(arq_out, "#include<stdio.h>\n");
    fprintf(arq_out, "#include<stdlib.h>\n");

    fprintf(arq_out, "int main(int agrc, char *argv[]){\n");
    //criamos o vetor mem com calloc, para inicializá-lo em 0;
    fprintf(arq_out, "\tchar *mem;");
    fprintf(arq_out, "\n\tmem = calloc(30000, sizeof(char));");
    fprintf(arq_out, "\n\tint i = 0; \n");

    char bf_command;
    //iremos ler da entrada padrão até EOF e traduzir cada char para um comando em C.
    while(fscanf(arq_in, "%c", &bf_command) != EOF){

        switch (bf_command){

        case '+':
            fprintf(arq_out, "\tmem[i]++;\n");
            break;
        case '-':
            fprintf(arq_out, "\tmem[i]--;\n");
            break;
        case '>':
            fprintf(arq_out, "i++;\n");
            break;
        case '<':
            fprintf(arq_out, "i--;\n");
            break;
        case '.' :
            fprintf(arq_out, "putchar(mem[i]);\n");
            break;
        case '[':
            fprintf(arq_out, "while(mem[i]){\n");
            break;
        case ']':
            fprintf(arq_out, "}\n");
            break;
        }
    }

    //código para imprimir todas as células não vazias:
    fprintf(arq_out, "\tprintf(\"\\n\");\n\tfor (int j = 0; j < 30000; j++) {\n\t\tif (mem[j] != 0) {");
    fprintf(arq_out, "\n\t\tprintf(\"%%d \", mem[j]);\n\t\t}\n\t}\n\tprintf(\"\\n\");");
   
    //como o vetor mem foi alocado, devemos liberá-lo;
    fprintf(arq_out, "\n\tfree(mem);");
    fprintf(arq_out, "\n%c", '}');

    fclose(arq_out);

    system("gcc temp.c -o exec.bin");
    system("./exec.bin");
    system("rm temp.c");//excluímos o arquivo temporário .c;

    return 0;
}