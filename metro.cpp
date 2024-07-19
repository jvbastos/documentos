#include <stdio.h>
#include <string.h>

struct No {
    char valor[50];
    No* prox;

    No(const char* _valor) {
        strcpy(valor, _valor);
        prox = NULL;
    }
};

struct Lista {
    No* inicio;
    No* fim;

    Lista() : inicio(NULL), fim(NULL) {}

    void inserirFinal(const char* s) {
        No* novo = new No(s);
        if (inicio == NULL) {
            inicio = novo;
            fim = novo;
        } else {
            fim->prox = novo;
            fim = novo;
        }
    }

    int buscarEstacao(const char* estacao) {
        No* aux = inicio;
        int pos = 0;
        while (aux != NULL) {
            if (strcmp(aux->valor, estacao) == 0) return pos;
            aux = aux->prox;
            pos++;
        }
        return -1;
    }
};

int main() {
    Lista l;

    l.inserirFinal("PALMEIRAS BARRA FUNDA");
    l.inserirFinal("MARECHAL DEODORO");
    l.inserirFinal("SANTA CECILIA");
    l.inserirFinal("REPUBLICA");
    l.inserirFinal("ANHANGABAU");
    l.inserirFinal("SE");
    l.inserirFinal("PEDRO II");
    l.inserirFinal("BRAS");
    l.inserirFinal("BRESSER MOOCA");
    l.inserirFinal("BELEM");
    l.inserirFinal("TATUAPE");
    l.inserirFinal("CARRAO");
    l.inserirFinal("PENHA");
    l.inserirFinal("VILA MATILDE");
    l.inserirFinal("GUILHERMINA ESPERANCA");
    l.inserirFinal("PATRIARCA");
    l.inserirFinal("ARTUR ALVIM");
    l.inserirFinal("CORINTHIANS ITAQUERA");

    char origem[50], destino[50];

    fgets(origem, sizeof(origem), stdin);
    fgets(destino, sizeof(destino), stdin);

    origem[strcspn(origem, "\n")] = 0;
    destino[strcspn(destino, "\n")] = 0;

    int posOrigem = l.buscarEstacao(origem);
    int posDestino = l.buscarEstacao(destino);

    if (posOrigem == -1 || posDestino == -1) {
        printf("Uma das estações não foi encontrada.\n");
        return 1;
    }

    if (posDestino > posOrigem) {
        printf("direita %d\n", posDestino - posOrigem);
    } else {
        printf("esquerda %d\n", posOrigem - posDestino);
    }

    return 0;
}
