#include<stdio.h>

int main(void){

    long long int x1, y1, l1, h1, x2, y2, l2, h2;

    scanf("%lld %lld %lld %lld", &x1, &y1, &l1, &h1);
    scanf("%lld %lld %lld %lld", &x2, &y2, &l2, &h2);

    char hitx = 0, hity = 0;

    if(x2+l2 >= x1 && x1+l1 >= x2) hitx = 1;

    if(y2+h2 >= y1 && y1+h1 >= y2) hity = 1;

    if(hitx && hity){
        
        printf("HIT: ");

        long long int big_x, big_y;

        if(x1>x2) big_x = x1;
        else big_x = x2;

        if(y1>y2) big_y = y1;
        else big_y = y2;

        long long int intercept_x, intercept_y;

        // dividimos o problema em duas dimensoes, para o eixo x e y
        // o tamanho do lado do hitbox sera igual ao retangulo de menor lado,
        // subtraido da maior coordenada x, o analogo ocorre com y.
        if(x1+l1 >= x2+l2) intercept_x = (x2+l2 - big_x);
        else intercept_x = (x1+l1 - big_x);

        if(y1+h1 >= y2+h2) intercept_y = (y2+h2 - big_y);
        else intercept_y = (y1+h1 - big_y);

        printf("%lld %lld %lld %lld",big_x, big_y, intercept_x, intercept_y);
    }

    else printf("MISS\n");

    return 0;

}