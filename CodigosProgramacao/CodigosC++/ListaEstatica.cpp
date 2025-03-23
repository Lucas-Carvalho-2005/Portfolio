#include<iostream>
using namespace std; 

typedef string Chave;
typedef string Hora;

class Tarefa {
public:
	Chave desc;
	Hora hora;
	bool feito;

	// Construtor padrão
	Tarefa() {
		desc = "nenhuma";
		hora = "00:00";
		feito = false;
	}

	// Construtor com parâmetros: inicializa o objeto
	Tarefa(Chave _desc, Hora _hora): desc(_desc),
	 								 hora(_hora),
	 								 feito(false) {}

	void print() {
		cout << desc << " - ";
		cout << hora << " - ";
		cout << (feito?"sim":"não") << "\n";
	}

	void check() {
		feito = true;
	}
}; // Tarefa

class Lista {
public:
	Tarefa *tarefas; // vetor com alocação dinâmica
	int TAM; 		 // tamanho do vetor
	int n; 			 // tamanho atual da lista

	// Construtor padrão
	Lista() {
		TAM = 10;
		tarefas = new Tarefa[TAM];
		n = 0; // lista está vazia
	}

	// Construtor com parâmetros
	Lista(int _TAM): TAM(_TAM) {
		tarefas = new Tarefa[TAM];
		n = 0; // lista está vazia
	}

	void insere(Tarefa t) {
		if (n < TAM) {
			n++;
			tarefas[n] = t;
		}
		else {
			cout << "Lista cheia!\n";
		}
	}

	void print() {
		cout << "Lista:\n";
		for (int i = 1; i <= n; ++i) {
			Tarefa t  = tarefas[i];
			t.print();
		}
		cout << endl;
	}

	Tarefa busca(Chave k) {
		tarefas[0].desc = k; // sentinela
		int i = n;
		while (k != tarefas[i].desc) {
			i--;
		}
		if (i > 0) {
			return tarefas[i];
		}
		else {
			tarefas[i].desc = "nenhuma"; // sentinela
			return tarefas[i];
		}
	}

	bool vazia() {
		return n == 0;
	}

	bool posicao_valida(int pos) {
		return 1 <= pos && pos <= n;
	}

	void remove(int pos) {
		if (!vazia() && posicao_valida(pos)) {
			for (int i = pos; i <= n - 1; ++i) {
				tarefas[i] = tarefas[i + 1];
			}
			n--;
		}
		else {
			cout << "Lista vazia ou posição inválida!\n";
		}
	}

}; // Lista



int main() {         
	Tarefa t1("Tomar café com tucumã", "06:00");
	Tarefa t2("Dar uma surra no Batman", "07:00");
	Tarefa t3("Academia", "19:30");
	Tarefa t4("Rodizio de pizza", "20:30");

	// Criando a lista
	Lista l(10);

	// Povoando a lista
	l.insere(t1);
	t2.check();
	l.insere(t2);
	l.insere(t3);
	l.insere(t4);

	// Imprimindo a lista
	l.print();

	// Buscando item na lista
	// cout << "Buscando... ";
	// Chave k = "Tomar banho no vulcão";
	// cout << k << endl;
	// Tarefa t = l.busca(k);
	// if (t.desc == "nenhuma") {
	// 	cout << "Tarefa não encontrada.\n";
	// }
	// else {
	// 	t.print();
	// }

	// Removendo item na lista
	cout << "\nRemovendo da posição... ";
	int pos = 1;
	l.remove(pos);
	l.print();
	l.remove(pos);
	l.print();
	l.remove(pos);
	l.print();
	l.remove(pos);
	l.print();
	l.remove(pos);

	cout << endl;
	return 0;
}