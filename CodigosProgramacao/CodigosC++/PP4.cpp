#include <iostream>
#include <list>
#include <vector>

typedef unsigned int uint;

class Simbolo {
private:
    std::string codigo;
    char letra;

public:
    Simbolo(std::string codigo, char letra) : codigo(codigo), letra(letra) {}

    std::string getCodigo() const { return codigo; }
    char getLetra() const { return letra; }
};

class Artefato {
private:
    static const int TAMANHO_TABELA_HASH = 11;
    std::list<Simbolo> tabelaHash[TAMANHO_TABELA_HASH];

public:
    Artefato() {
        tabelaHash[hashFunction(":::")].emplace_back(":::", 'A');
        tabelaHash[hashFunction(".::")].emplace_back(".::", 'B');
        tabelaHash[hashFunction(":.:")].emplace_back(":.:", 'C');
        tabelaHash[hashFunction("::.")].emplace_back("::.", 'D');
        tabelaHash[hashFunction(":..")].emplace_back(":..", 'E');
        tabelaHash[hashFunction(".:.")].emplace_back(".:.", 'F');
        tabelaHash[hashFunction("..:")].emplace_back("..:", 'G');
        tabelaHash[hashFunction("...")].emplace_back("...", 'H');
        tabelaHash[hashFunction("|::")].emplace_back("|::", 'I');
        tabelaHash[hashFunction(":|:")].emplace_back(":|:", 'J');
        tabelaHash[hashFunction("::|")].emplace_back("::|", 'K');
        tabelaHash[hashFunction("|.:")].emplace_back("|.:", 'L');
        tabelaHash[hashFunction(".|:")].emplace_back(".|:", 'M');
        tabelaHash[hashFunction(".:|")].emplace_back(".:|", 'N');
        tabelaHash[hashFunction("|:.")].emplace_back("|:.", 'O');
        tabelaHash[hashFunction(":|.")].emplace_back(":|.", 'P');
        tabelaHash[hashFunction(":.|")].emplace_back(":.|", 'Q');
        tabelaHash[hashFunction("|..")].emplace_back("|..", 'R');
        tabelaHash[hashFunction(".|.")].emplace_back(".|.", 'S');
        tabelaHash[hashFunction("..|")].emplace_back("..|", 'T');
        tabelaHash[hashFunction(".||")].emplace_back(".||", 'U');
        tabelaHash[hashFunction("|.|")].emplace_back("|.|", 'V');
        tabelaHash[hashFunction("||.")].emplace_back("||.", 'W');
        tabelaHash[hashFunction("-.-")].emplace_back("-.-", 'X');
        tabelaHash[hashFunction(".--")].emplace_back(".--", 'Y');
        tabelaHash[hashFunction("--.")].emplace_back("--.", 'Z');
        tabelaHash[hashFunction("---")].emplace_back("---", ' ');
        tabelaHash[hashFunction("~~~")].emplace_back("~~~", '.');
    }

    std::string traduzir(const std::string& simbolosStr) const {
        std::string traduzido;
        for (size_t i = 0; i < simbolosStr.size(); i += 3) {
            std::string grupo = simbolosStr.substr(i, 3);
            int indice = hashFunction(grupo);
            for (const auto& simbolo : tabelaHash[indice]) {
                if (simbolo.getCodigo() == grupo) {
                    traduzido += simbolo.getLetra();
                    break;
                }
            }
        }
        return traduzido;
    }

private:
    int hashFunction(const std::string& codigo) const {
        int valor = 0;
        for (uint i = 0; i < codigo.size(); ++i) {
            valor = (valor * 128 + codigo[i]) % TAMANHO_TABELA_HASH;
        }
        return valor;
    }
};

class CifraCesar {
public:
    std::string decifrar(const std::string& texto, int k) const {
        std::string resultado;
        for (char c : texto) {
            if (isalpha(c)) {
                char base = isupper(c) ? 'A' : 'a';
                resultado += (c - base - k + 26) % 26 + base;
            } else {
                resultado += c;
            }
        }
        return resultado;
    }
};

class TabelaBadChar {
public:
    std::vector<int> construir(const std::string& padrao) const {
        std::vector<int> tabela(256, -1);
        for (size_t i = 0; i < padrao.size(); ++i) {
            tabela[padrao[i]] = i;
        }
        return tabela;
    }
};

class BoyerMoore {
public:
    std::vector<std::pair<int, int>> buscar(const std::string& texto, const std::string& padrao) const {
        std::vector<std::pair<int, int>> resultados;
        int m = padrao.size();
        int n = texto.size();

        if (m > n) return resultados;

        TabelaBadChar badChar;
        auto tabelaBadChar = badChar.construir(padrao);
        int deslocamento = 0;

        while (deslocamento <= n - m) {
            int j = m - 1;

            while (j >= 0 && padrao[j] == texto[deslocamento + j]) {
                --j;
            }

            if (j < 0) {
                resultados.emplace_back(deslocamento, 0);
                int proximoSalto = (deslocamento + m < n) ? m - tabelaBadChar[texto[deslocamento + m]] : 1;
                deslocamento += proximoSalto;
                resultados.emplace_back(deslocamento, proximoSalto);
            } else {
                int salto = std::max(1, j - tabelaBadChar[texto[deslocamento + j]]);
                resultados.emplace_back(deslocamento, salto);
                deslocamento += salto;
            }
        }
        return resultados;
    }
};

int main() {
    std::string entradaSimbolos, linha;
    std::vector<std::string> padroes;

    std::getline(std::cin, entradaSimbolos);

    while (std::getline(std::cin, linha)) {
        std::string linhaUpper;
        for (char c : linha) {
            linhaUpper += toupper(c);
        }

        if (linhaUpper == "FIM") break;

        for (char& c : linha) {
            c = toupper(c);
        }
        padroes.push_back(linha);
    }

    Artefato artefato;
    std::string traduzido = artefato.traduzir(entradaSimbolos);

    CifraCesar cifra;
    std::string decifrado;
    for (int k = 0; k < 26; ++k) {
        decifrado = cifra.decifrar(traduzido, k);
        bool encontrado = false;
        for (const auto& padrao : padroes) {
            if (decifrado.find(padrao) != std::string::npos) {
                encontrado = true;
                break;
            }
        }
        if (encontrado) {
            break;
        }
    }

    BoyerMoore bm;
    for (const auto& padrao : padroes) {
        auto resultados = bm.buscar(decifrado, padrao);

        std::cout << padrao << ": ";
        for (uint i = 0; i < resultados.size(); ++i) {
            int posicao = resultados[i].first;
            int salto = resultados[i].second;

            if (salto == 0) {
                std::cout << salto << " (" << posicao << ") ";
                ++i;
                salto = resultados[i].second;
                if (salto-1 != 0)
                    std::cout << salto-1 << " ";
            } else {
                std::cout << salto << " ";
            }
        }
        std::cout << "\n";
    }

    return 0;
}