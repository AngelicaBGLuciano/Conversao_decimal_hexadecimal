#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct numero{
    int numero;
    struct numero* prox;
}Numero;

typedef struct pilha{
    Numero* topo;
}Pilha;

void inicializaPilha(Pilha *p){
    p->topo = NULL;
}

void converteParaHexadecimal(Pilha *p, int n){

    while (n > 0) {
        Numero *num=(Numero*)malloc(sizeof(Numero));
        int resto = n % 16;
        num->numero = resto;
        num->prox = p->topo;
        p->topo = num;
        n = n / 16;
    }
}
void imprimePilha(Pilha *p){

    Numero *num = p->topo;
    while (num != NULL) {
        int valor = num->numero;
        if (valor < 10) {
            printf("%d", valor);      //parte dos numeros
        }
        else {
            printf("%c", valor + 55);//para as letras a-f
        }
        num = num->prox;
    }
}
void destroiPilha(Pilha *p){
    Numero* aux = NULL;
    while (p->topo != NULL) {
        aux = p->topo;
        p->topo = aux->prox;
        free(aux);
    }
}
int main(){
    Pilha p;
    int n;

    printf("\n\nDigite um numero decimal:");
    scanf("%d", &n);

    inicializaPilha(&p);
    converteParaHexadecimal(&p, n);

    printf("\n\nO numero hexadecimal eh: ");
    imprimePilha(&p);
    printf("\n\n");

    destroiPilha(&p);


    return 0;
}
