#include <stdio.h>

struct No {
    float valor;
    No *prox;
};

struct Lista {
    No *cabeca, *cauda;
    int n;

    Lista() {
        cabeca = cauda = NULL;
        n = 0;
    }

    bool vazia() {
        return (cabeca == NULL);
    }

    void inserirInicio(int v) {
        No *novo = new No();
        novo->valor = v;
        if (vazia()) {
            novo->prox = NULL;
            cabeca = novo;
            cauda = novo;
        } else {
            novo->prox = cabeca;
            cabeca = novo;
        }
        n++;
    }

    void inserirFinal(float v) {
        No *novo = new No();
        novo->valor = v;
        if (vazia()) {
            novo->prox = NULL;
            cabeca = novo;
            cauda = novo;
        } else {
            novo->prox = NULL;
            cauda->prox = novo;
            cauda = novo;
        }
        n++;
    }

    void imprimir() {
        No *aux = cabeca;
        while (aux != NULL) {
            printf("imprimir:%f\n", aux->valor);
            aux = aux->prox;
        }
    }

    int tamanho() {
        return n;
    }

    void removerInicio() {
        if (!vazia()) {
            if (tamanho() == 1) {
                No *aux = cabeca;
                cabeca = NULL;
                cauda = NULL;
                delete(aux);
            } else {
                No *aux = cabeca;
                cabeca = cabeca->prox;
                delete(aux);
            }
            n--;
        }
    }

    void removerFinal() {
        if (!vazia()) {
            if (tamanho() == 1) {
                No *aux = cabeca;
                cabeca = NULL;
                cauda = NULL;
                delete(aux);
            } else {
                No *penultimo = cabeca;
                while (penultimo->prox != cauda) {
                    penultimo = penultimo->prox;
                }
                delete(cauda);
                cauda = penultimo;
                cauda->prox = NULL;
            }
            n--;
        }
    }

    void resultado() {
        No *aux = cabeca;
        float soma = 0;

        while (aux != NULL) {
            soma = aux->valor + soma;

            if (soma < 0) {
                printf("invalido");
                return;
            }

            aux = aux->prox;
        }

        printf("%.2f", soma);
    }
};

int main() {
    Lista l;
    int x;
    float valor;

    scanf("%d", &x);

    for (int i = 0; i < x; i++) {
        scanf("%f", &valor);
        l.inserirFinal(valor);
    }

    l.resultado();

    return 0;
}

