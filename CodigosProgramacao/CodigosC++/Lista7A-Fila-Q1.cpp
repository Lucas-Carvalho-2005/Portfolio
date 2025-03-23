#include <iostream>
using namespace std;

class Fila{
    private:
        int frente;
        int tras;
        int item[8];
        int TAM;

    public:

        void cria_fila() {
           frente = 0;
           tras = frente;
        }


        bool cheia() {
            return (tras + 1) % TAM == frente;
        }

        bool vazia() {
            return tras == frente;
        }


        void enfileira() {
            if (cheia()) {
                cout << "Fila cheia!";
            }

            else {
                item[tras] = item;
                tras = (tras + 1) % TAM;
            }
            
        }


        void desinfileira() {
            if (vazia()){
                cout << "Fila vazia!";
            }

            else {
                item = item[frente];
                frente = (frente + 1) % TAM;
            }
        }



};