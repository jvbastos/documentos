#include <stdio.h>

struct No {
    float valor;
    No* prox;

    No() {
        prox = NULL;
    }

    No(float _valor) {
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

    void inserirFinal(float n) {
        No* novo = new No(n);
        if (inicio == NULL) {
            inicio = novo;
            fim = novo;
        } else {
            fim->prox = novo;
            fim = novo;
        }
    }

    float calcularSaldo() {
        No* aux = inicio;
        float saldo = 0.0;
        while (aux != NULL) {
            saldo += aux->valor;
            if (saldo < 0) {
                return -1;
            }
            aux = aux->prox;
        }
        return saldo;
    }
};

int main() {
    int N;
    float valor;
    Lista l;

    scanf("%d", &N);

    for (int i = 0; i < N; ++i) {
        scanf("%f", &valor);
        l.inserirFinal(valor);
    }

    float saldo = l.calcularSaldo();
    if (saldo < 0) {
        printf("invalido\n");
    } else {
        printf("%.2f\n", saldo);
    }

    return 0;
}

