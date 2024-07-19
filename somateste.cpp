#include<stdio.h>

struct No {

    int valor;
    No* prox;

    No() {
        prox = NULL;
    }

    No(int _valor) {
        valor = _valor;
        prox = NULL;
    }

};

struct Lista {

    No* inicio;
    No* fim;

    Lista() {
        inicio = NULL;
        fim = NULL;
    }

    void inserirInicio(int n) {
        No* novo = new No(n);
        if (inicio == NULL) {
            inicio = novo;
            fim = novo;
        } else {
            novo->prox = inicio;
            inicio = novo;
        }
    }

    void inserirFinal(int n) {
        No* novo = new No(n);
        if (inicio == NULL) {
            inicio = novo;
            fim = novo;
        } else {
            fim->prox = novo;
            fim = novo;
        }
    }

    void imprimir() {
        No* aux = inicio;
        //printf("%d %d\n", aux, aux->valor);
        while (aux != NULL) {
            printf("%d\n", aux->valor);
            //printf("%d %d\n", aux->prox, aux->valor);
            aux = aux->prox;
        }
    }

};


int main() {

    int n, x;
    scanf("%d", &n);

    Lista a, b, r;

    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        a.inserirFinal(x);
    }

    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        b.inserirFinal(x);
    }

    No *aux1 = a.inicio;
    No *aux2 = b.inicio;

    int resto = 0;

    while (aux1 != NULL && aux2 != NULL) {
        int soma = aux1->valor + aux2->valor + resto;
        resto = 0;
        if (soma >= 10) {
            resto = resto + 1;
            soma = soma - 10;
        }
        r.inserirFinal(soma);
        aux1 = aux1->prox;
        aux2 = aux2->prox;
    }

    r.imprimir();

    return 0;
}

