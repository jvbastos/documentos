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

    No *inicio, *fim, *mediana;
    int n;

    Lista() {
        inicio = NULL;
        fim = NULL;
        mediana = NULL;
        n = 0;
    }

    bool vazia() {
        return inicio == NULL;
    }

    void inserirFinal(int valor) {

        n++;
        No *novo = new No(valor);

        if (vazia()) {
            inicio = novo;
            fim = novo;
            mediana = novo;
            return;
        }

        fim->prox = novo;
        fim = novo;

        if (tamanho() % 2 == 1) {
            mediana = mediana->prox;
        }

    }

    void imprimir() {

        No *aux = inicio;

        while (aux != NULL) {
            printf("%d ", aux->valor);
            aux = aux->prox;
        }

        printf("%.2lf\n", calculoMediana());

    }

    int tamanho() {
        return n;
    }

    double calculoMediana() {
        if (tamanho() % 2 == 0) {
            No *proximo = mediana->prox;
            return (mediana->valor + proximo->valor) / 2.0;
        } else {
            return mediana->valor;
        }
    }

};

int main() {

    Lista l;

    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        l.inserirFinal(x);
        l.imprimir();
    }

    return 0;
}
