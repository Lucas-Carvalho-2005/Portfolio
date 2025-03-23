// Marcelo Heitor de Almeida Lira
// Lucas Carvalho dos Santos

#include <iostream>
#include <string>
#include <cstring>
#include <cctype>

using namespace std;

// Definindo struct de suporte para a pilha dinamica
template<typename T>
struct No {
    T chave;
    No *prox;
};

// Implementacao da pilha dinamica
template<typename T>
class Pilha {
public:
    No<T> *topo, *fundo, *aux;

    // Metodo para criar pilha
    void cria() 
    {
        fundo = (No<T>*) malloc(sizeof(No<T>));
        if (!fundo)
            cout << "Erro de alocacao de memoria! \n";
        fundo -> prox = nullptr;
        topo = fundo;
    }

    // Metodo para adicionar elemento na pilha
    void empilha(T n) 
    {
        aux = (No<T>*) malloc(sizeof(No<T>));
        if (!aux)
            cout << "Erro de alocacao de memoria! \n";
        topo -> chave = n;
        aux -> prox = topo;
        topo = aux;
    }

    // Metodo para remover elemento da pilha
    T desempilha(T n, T i) {
        if (topo == fundo) {
            cout << "Pilha vazia! \n";
            return i;
        } else {
            aux = topo;
            topo = topo -> prox;
            n = topo -> chave;
            free(aux);
            // Retorna a chave do topo da pilha apos a remocao
            return n;
        }
    }
};

// Classe NeeStr = Linha do programa Nee
template<typename K, typename V>
class NeeString {
public:
    K chave; // Numero da linha na lista
    V desc; // Conteudo da linha

    // Construtor sem parametros
    NeeString() {
        chave = 0;
        desc = "";
    }

    // Construtor com parametros
    NeeString(K _chave, V _desc) {
        chave = _chave;
        desc = _desc;
    }

    // Metodo de impressao
    void print() {
        cout << chave << " - ";
        cout << desc << "\n";
    }
};

// Implementacao da lista estatica
template <typename K, typename V>
class Lista {
public:
    NeeString<K, V> *linha;
    int tamLista;
    int n;
    K fimFuncaoZ; // Atributo especifico para armazenar a chave da linha que termina a funcao "Z"

    // Construtor com parametros
    Lista(int _tamLista) {
        tamLista = _tamLista;
        linha = new NeeString<K, V>[tamLista];
        n = 0;
        fimFuncaoZ = -1;
    }

    // Metodo de insercao de elemento na lista
    void insere(NeeString<K, V> l) 
    {
        if (n < tamLista) {
            linha[n] = l;
            n++;
        } else
            cout << "Lista cheia! \n";
    }

    // Metodo de impressao
    void print() 
    {
        cout << "Lista:\n";
        for (int i = 0; i <= n; ++i) {
            cout << "Tamanho da linha: " << linha[i].desc.length() << " ---> "; // Imprime tamanho da linha
            NeeString<K, V> t = linha[i]; // Armazena linha em variavel NeeStr
            t.print(); // Chama a funcao print de NeeStr
        }
        cout << endl << "Tamanho total: " << tamLista;
    }

    // Metodo de busca de elemento
    NeeString<K, V> Busca(V l) {
        int i = n - 1;
        // O metodo vai comparar a primeira letra (funcao Nee) com a quinta (chamada de funcao Nee)
        while (i >= 0 && l[4] != linha[i].desc[0])
          i--;

        if (i >= 0)
            return linha[i];
        else {
            cout << "Chave nao encontrada! \n";
            linha[i].desc = "nenhum";
            return linha[i];
        }
    }

    // Metodo para achar a funcao "Z" No programa
    K getZ(V l) 
    {
        int i = 0;
        while (l[0] != linha[i].desc[0])
            i++;
        return linha[i].chave; // Retorna a chave da linha com a funcao "Z"
    }
};

int main() 
{
    string program;
    int tamVetor = 0, j = 0, x = 0;
    NeeString<int, string> chamaFuncao;

    // Instanciando e criando a pilha
    Pilha<int> pilha;
    pilha.cria();

    // Instanciando lista com tamanho 300
    Lista<int, string> l(300);

    // Lendo linhas do programa
    while (getline(cin, program)) {
        if (ispunct(program[0])) // Checa se o primeiro elemento da string "program" e um caractere de pontuacao. Caso positivo, encerra a leitura (caso em que aparece o til para finalizar o programa)
            break;
        else {
            // Armazenando uma linha em um objeto NeeStr
            NeeString<int, string> linha(j, program);
            // Inserindo objeto NeeStr na lista
            l.insere(linha);
            // Atualizando variavel "tamVetor" para definir tamanho do vetor
            tamVetor = tamVetor + program.length();
            // Atualizando "j" para atuar como Chave em NeeStr
            j++;
        }
    }
    l.tamLista = tamVetor;

    // "get_z" recebe a chave da linha que contem a funcao "Z"
    int get_z = l.getZ("Z");
    if (get_z == -1){
      cout << "Funcao Z nao encontrada!" << endl;
      return 1;
    }

    // Loop para definir a chave da linha final de "Z"
    for (int i = get_z + 1; i < l.tamLista; i++) {
        if (l.linha[i].desc.empty()) {
            l.fimFuncaoZ = l.linha[i].chave;
            break;
        }
    }

    // Linha final de "Z"
    int linhaFinalZ = l.fimFuncaoZ;

    // "i" comeca em "get_z", pois o programa comeca com a funcao "Z"
    for (int i = get_z + 1; i < l.tamLista; i++) {

        // Se a linha tiver tamanho 11 ou 12, ela sera um comando Nee PRINT
        if (l.linha[i].desc.length() == 11 || l.linha[i].desc.length() == 12) {
            for (int k = 10; k < int(l.linha[i].desc.length()); k++) {
                // Imprimindo numero
                cout << l.linha[i].desc[k];
            }
            cout << " ";
        }

        // Se a linha tiver tamanho 5, ela sera uma chamada de funcao Nee
        else if (l.linha[i].desc.length() == 5) {
            // Empilhando pseudoendereco
            pilha.empilha(i);
            // Buscando funcao chamada
            chamaFuncao = l.Busca(l.linha[i].desc);
            // Colocando chave da funcao chamada em "i"
            i = chamaFuncao.chave - 1;
        }

        // Se a chave for a linha final de "Z", o programa encerra
        else if (l.linha[i].chave == linhaFinalZ) {
            cout << endl;
            break;
        }

        // Se a linha nao tiver nada, sera o final de uma funcao Nee
        else if (l.linha[i].desc.length() == 0) {
            // Desempilhando endereco e voltando para chamada de funcao
            i = pilha.desempilha(x, i);
        }
    }
}
