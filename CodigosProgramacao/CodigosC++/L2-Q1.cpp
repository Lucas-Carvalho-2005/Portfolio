#include <iostream>
using namespace std;

struct Disciplina {
    string nome, codigo;
    int cargaHoraria;
};

void imprimirDisciplina(string nome, string codigo, int carga_horaria) {
    cout << nome << ", " << codigo << ", " << carga_horaria << "h";
}

int main() {
    Disciplina disc1;

    getline(cin, disc1.nome);
    cin >> disc1.codigo;
    cin >> disc1.cargaHoraria;
    
    cout << "\n";
 

    imprimirDisciplina(disc1.nome, disc1.codigo, disc1.cargaHoraria);
}



