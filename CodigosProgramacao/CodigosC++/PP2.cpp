#include <iostream>
#include <list>
#include <limits>

using namespace std;

class Fila {

private:
    list<pair<int, int>> fila;

public:
    void enfileira(pair<int, int> coordenada) {
        fila.push_back(coordenada);
    }

    pair<int, int> desenfileira() {
        pair<int, int> coordenada = fila.front();
        fila.pop_front();
        return coordenada;
    }

    bool vazia() const {
        return fila.empty();
    }
};

class Tabuleiro {
private:
    static const int movimentos[8][2];
public:
    static const int TAMANHO_TABULEIRO = 8;

    bool eValido(int x, int y) const {
        return x >= 1 && x <= TAMANHO_TABULEIRO && y >= 1 && y <= TAMANHO_TABULEIRO;
    }

    const int (*getMovimentos() const)[2] {
        return movimentos;
    }
};

const int Tabuleiro::movimentos[8][2] = {
    {2, 1}, {1, 2}, {-2, 1}, {-1, 2}, 
    {2, -1}, {1, -2}, {-2, -1}, {-1, -2}
};

class Cavalo {
private:
    int x, y;
public:
    Cavalo(int x_, int y_) : x(x_), y(y_) {}

    list<pair<int, int>> getMovimentos(const Tabuleiro &tabuleiro) const {
        list<pair<int, int>> movimentosPossiveis;
        const int (*movimentos)[2] = tabuleiro.getMovimentos();
        for (int i = 0; i < 8; ++i) {
            int novoX = x + movimentos[i][0];
            int novoY = y + movimentos[i][1];
            if (tabuleiro.eValido(novoX, novoY)) {
                movimentosPossiveis.push_back(make_pair(novoX, novoY));
            }
        }
        return movimentosPossiveis;
    }

    int getX() const { return x; }
    int getY() const { return y; }
};

class BFS {
public:
    int encontrarMinMovimentos(const Cavalo &cavalo, int reiX, int reiY, 
                                const Tabuleiro &tabuleiro) {
        Fila fila;
        bool visitado[Tabuleiro::TAMANHO_TABULEIRO][Tabuleiro::TAMANHO_TABULEIRO] = {false};

        fila.enfileira(make_pair(cavalo.getX(), cavalo.getY()));
        visitado[cavalo.getX() - 1][cavalo.getY() - 1] = true;

        int distancia[Tabuleiro::TAMANHO_TABULEIRO][Tabuleiro::TAMANHO_TABULEIRO] = {0};

        while (!fila.vazia()) {
            pair<int, int> atual = fila.desenfileira();

            if (atual.first == reiX && atual.second == reiY) {
                return distancia[atual.first - 1][atual.second - 1];
            }

            Cavalo cavaloTemp(atual.first, atual.second);
            list<pair<int, int>> movimentos = cavaloTemp.getMovimentos(tabuleiro);
            for (auto movimento : movimentos) {
                int novoX = movimento.first;
                int novoY = movimento.second;
                if (!visitado[novoX - 1][novoY - 1]) {
                    fila.enfileira(make_pair(novoX, novoY));
                    visitado[novoX - 1][novoY - 1] = true;
                    distancia[novoX - 1][novoY - 1] = distancia[atual.first - 1][atual.second - 1] + 1;
                }
            }
        }

        return numeric_limits<int>::max();
    }
};

int converterCoordenada(char letra) {
    return letra - 'a' + 1;
}

void executarTestes() {
    int numTestes;
    cin >> numTestes;

    Tabuleiro tabuleiro;
    BFS bfs;

    while (numTestes--) {
        list<Cavalo> cavalos;
        int reiX, reiY;

        for (int i = 0; i < 5; ++i) {
            char letra;
            int numero;
            cin >> letra >> numero;
            int y = converterCoordenada(letra);

            if (i == 4) {
                reiX = numero;
                reiY = y;
            } else {
                cavalos.push_back(Cavalo(numero, y));
            }
        }

        int minMovimentos = numeric_limits<int>::max();
        list<int> resultados;

        for (auto cavalo : cavalos) {
            int movimentos = bfs.encontrarMinMovimentos(cavalo, reiX, reiY, tabuleiro) - 1;
            if (movimentos < minMovimentos) {
                minMovimentos = movimentos;
                resultados.clear();
                resultados.push_back(movimentos);
            } else if (movimentos == minMovimentos) {
                resultados.push_back(movimentos);
            }
        }

        for (int resultado : resultados) {
            cout << resultado;
        }
    }
}

int main() {
    executarTestes();
    return 0;
}