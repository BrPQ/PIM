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

// Função para carregar os produtos do arquivo produtos.txt
vector<Produto> carregarProdutos() {
    vector<Produto> produtos;
    ifstream arquivo("produtos.txt");
    if (arquivo.is_open()) {
        string linha;
        while (getline(arquivo, linha)) {
            if (linha == "Nome do produto") {
                Produto p;
                getline(arquivo, p.nome);
                getline(arquivo, linha); // Ignora "Código do produto"
                arquivo >> p.codigo;
                arquivo.ignore(); // Ignora o caractere de nova linha
                getline(arquivo, linha); // Ignora "Preço do produto"
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

// Função para realizar a pesagem de um produto
void realizarPesagem(const vector<Produto>& produtos) {
    if (produtos.empty()) {
        cout << "Nenhum produto disponível para pesagem." << endl;
        return;
    }

    while (true) {
        // Solicita o código do produto
        int codigo;
        cout << "Precione 0 para desligar a balança... \n";
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
        cout << "Digite o código do produto\n";
        cin >> codigo;

        // Verifica se o código é 0 para encerrar
        if (codigo == 0) {
            cout << "Encerrando a balança..." << endl;
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
            cout << "Produto não encontrado!" << endl;
            continue; // Volta para o início do loop e pede outro código
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
        system("cls");  // Limpa a tela após a impressão da etiqueta
    }
}

int main() {
    setlocale(LC_ALL, "");



    // Carrega os produtos do arquivo
    vector<Produto> produtos = carregarProdutos();

    // Realiza a pesagem de produtos até que o código 0 seja digitado
    realizarPesagem(produtos);

    return 0;
}
