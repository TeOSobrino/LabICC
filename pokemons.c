#include<stdio.h>
#include<stdlib.h>

typedef struct attributes{
    int HP, atk, def, esp_atk, esp_def, speed;
}Attributes_t;

typedef struct attacks{
    char atk_name[20];
    int atk_power;
    float atk_accuracy;
    char atk_class;
}Attacks_t;

typedef struct pokemon{
    char name[50], p_type[20], s_type[20];
    Attacks_t pokemon_attacks[4];
    Attributes_t pokemon_atributes;
}Pokemon_t;

Pokemon_t *aumentar_num_pokemons(int num_poks, Pokemon_t *pokedex);
int main(int argc, char *argv[]){

    int opcao;
    int num_poks = 0;
    Pokemon_t *pokedex = NULL;
    int poke_atual;
    int atk_index;

    do{
        switch(opcao){

        case(1):
            num_poks++;
            pokedex = aumentar_num_pokemons(num_poks, pokedex);

            //lê a entrada do usuário e preenche os atributos básicos do pokemon.
            scanf("%s", pokedex[num_poks-1].name);
            scanf("%s", pokedex[num_poks-1].p_type);
            scanf("%s", pokedex[num_poks-1].s_type);
            scanf("%d", &pokedex[num_poks-1].pokemon_atributes.HP);
            scanf("%d", &pokedex[num_poks-1].pokemon_atributes.atk);
            scanf("%d", &pokedex[num_poks-1].pokemon_atributes.def);
            scanf("%d", &pokedex[num_poks-1].pokemon_atributes.esp_atk);
            scanf("%d", &pokedex[num_poks-1].pokemon_atributes.esp_def);
            scanf("%d", &pokedex[num_poks-1].pokemon_atributes.speed);

            break;
        case(2):

            //lê a entrada do usuário para preencher um ataque específico do pokemon.
            scanf("%d", &poke_atual);
            scanf("%d", &atk_index);

            scanf("%s", pokedex[poke_atual].pokemon_attacks[atk_index].atk_name);
            scanf("%d", &pokedex[poke_atual].pokemon_attacks[atk_index].atk_power);
            scanf("%f", &pokedex[poke_atual].pokemon_attacks[atk_index].atk_accuracy);
            scanf(" %c", &pokedex[poke_atual].pokemon_attacks[atk_index].atk_class);

            break;
        case(3):

            scanf("%d", &poke_atual);
            
            //imprime os tipos básicos do pokemon.
            printf("Nome do Pokemon: %s\n", pokedex[poke_atual].name);
            printf("Tipo primario: %s\n", pokedex[poke_atual].p_type);
            printf("Tipo secundario: %s\n", pokedex[poke_atual].s_type);
            printf("Status:\n");
            printf("\tHP: %d\n", pokedex[poke_atual].pokemon_atributes.HP);
            printf("\tAtaque: %d\n", pokedex[poke_atual].pokemon_atributes.atk);
            printf("\tDefesa: %d\n", pokedex[poke_atual].pokemon_atributes.def);
            printf("\tAtaque Especial: %d\n", pokedex[poke_atual].pokemon_atributes.esp_atk);
            printf("\tDefesa Especial: %d\n", pokedex[poke_atual].pokemon_atributes.esp_def);
            printf("\tVelocidade: %d\n\n", pokedex[poke_atual].pokemon_atributes.speed);

            break;
        case(4):

            scanf("%d", &poke_atual);
            scanf("%d", &atk_index);

            //imprime um ataque específico do pokemon. 
            printf("Nome do Ataque: %s\n", pokedex[poke_atual].pokemon_attacks[atk_index].atk_name);
            printf("Poder base: %d\n", pokedex[poke_atual].pokemon_attacks[atk_index].atk_power);
            printf("Acuracia: %f\n", pokedex[poke_atual].pokemon_attacks[atk_index].atk_accuracy);
            printf("Classe: %c\n\n", pokedex[poke_atual].pokemon_attacks[atk_index].atk_class);

            break;
        }
        scanf("%d", &opcao);
    }while(opcao != 0);

    free(pokedex);

    return 0;
}

/**
 * @brief essa função aumenta o numero de pokemons
 * 
 * @param num_poks numero atual de pokemons
 * @param pokedex vetor de pokemons
 * @return pokemon* retorna o vetor aumentado em 1
 */
Pokemon_t *aumentar_num_pokemons(int num_poks, Pokemon_t *pokedex){

    pokedex = realloc(pokedex, num_poks*sizeof(Pokemon_t));
    return pokedex;
}