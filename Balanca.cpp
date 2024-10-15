#include <iostream>
#include <locale.h>
#include <vector>
#include <fstream>
#include <string>
#include <thread>

using namespace std;

// Estrutura para representar um produto
struct Produto {
    string nome;
    int codigo;
    double preco;
};

// Fun��o para carregar os produtos do arquivo produtos.txt
vector<Produto> carregarProdutos() {
    vector<Produto> produtos;
    ifstream arquivo("produtos.txt");
    if (arquivo.is_open()) {
        string linha;
        while (getline(arquivo, linha)) {
            if (linha == "Nome do produto") {
                Produto p;
                getline(arquivo, p.nome);
                getline(arquivo, linha); // Ignora "C�digo do produto"
                arquivo >> p.codigo;
                arquivo.ignore(); // Ignora o caractere de nova linha
                getline(arquivo, linha); // Ignora "Pre�o do produto"
                arquivo >> p.preco;
                arquivo.ignore();
                produtos.push_back(p);
            }
        }
        arquivo.close();
    } else {
        cout << "Erro ao abrir o arquivo de produtos." << endl;
    }
    return produtos;
}

// Fun��o para realizar a pesagem de um produto
void realizarPesagem(const vector<Produto>& produtos) {
    if (produtos.empty()) {
        cout << "Nenhum produto dispon�vel para pesagem." << endl;
        return;
    }

    while (true) {
        // Solicita o c�digo do produto
        int codigo;
        cout << "Precione 0 para desligar a balan�a... \n";
        this_thread::sleep_for(chrono::milliseconds(2000));
        system("cls");
        cout << "--------------------------------------------------\n";
        cout << "|                                                |\n";
        cout << "|"         <<"             SEJA ";
        cout << " BEM ";
        cout <<" VINDO(A)!"                    "               |\n";
        cout << "|                                                |\n";
        cout << "|";
        cout << "-------------------------------------------------\n";
        this_thread::sleep_for(chrono::milliseconds(1000));
        system("cls");
        cout << "Digite o c�digo do produto\n";
        cin >> codigo;

        // Verifica se o c�digo � 0 para encerrar
        if (codigo == 0) {
            cout << "Encerrando a balan�a..." << endl;
            break;
        }

        // Busca o produto selecionado
        bool produtoEncontrado = false;
        Produto produtoSelecionado;
        for (const Produto& p : produtos) {
            if (p.codigo == codigo) {
                produtoSelecionado = p;
                produtoEncontrado = true;
                break;
            }
        }

        if (!produtoEncontrado) {
            cout << "Produto n�o encontrado!" << endl;
            continue; // Volta para o in�cio do loop e pede outro c�digo
        }

        // Recebe o peso e calcula o valor total
        double peso;
        cout << "Digite o peso em KG: ";
        cin >> peso;

        double valorTotal = peso * produtoSelecionado.preco;
        cout << "Produto: " << produtoSelecionado.nome << endl;
        cout << "Peso: " << peso << " KG" << endl;
        cout << "Valor total: R$ " << valorTotal << endl;
        cout << "\nImprimindo etiqueta...";
        this_thread::sleep_for(chrono::milliseconds(2000));
        system("cls");  // Limpa a tela ap�s a impress�o da etiqueta
    }
}

int main() {
    setlocale(LC_ALL, "");



    // Carrega os produtos do arquivo
    vector<Produto> produtos = carregarProdutos();

    // Realiza a pesagem de produtos at� que o c�digo 0 seja digitado
    realizarPesagem(produtos);

    return 0;
}
