#include <stdio.h>

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
        while (aux != NULL) {
            printf("%d ", aux->valor);
            aux = aux->prox;
        }
        printf("\n");
    }
};

Lista mesclarListas(Lista& l1, Lista& l2) {
    Lista resultado;
    No* p1 = l1.inicio;
    No* p2 = l2.inicio;

    while (p1 != NULL && p2 != NULL) {
        if (p1->valor <= p2->valor) {
            resultado.inserirFinal(p1->valor);
            p1 = p1->prox;
        } else {
            resultado.inserirFinal(p2->valor);
            p2 = p2->prox;
        }
    }

    while (p1 != NULL) {
        resultado.inserirFinal(p1->valor);
        p1 = p1->prox;
    }

    while (p2 != NULL) {
        resultado.inserirFinal(p2->valor);
        p2 = p2->prox;
    }

    return resultado;
}

int main() {
    int N, M;
    scanf("%d %d", &N, &M);

    Lista lista1, lista2;

    for (int i = 0; i < N; ++i) {
        int valor;
        scanf("%d", &valor);
        lista1.inserirFinal(valor);
    }

    for (int i = 0; i < M; ++i) {
        int valor;
        scanf("%d", &valor);
        lista2.inserirFinal(valor);
    }

    Lista listaMesclada = mesclarListas(lista1, lista2);
    listaMesclada.imprimir();

    return 0;
}

