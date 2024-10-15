#include <iostream>
#include <locale.h>
#include <fstream>
#include <thread>
#include <vector>
#include <string>

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
    }
    return produtos;
}

// Fun��o para salvar todos os produtos no arquivo
void salvarProdutos(const vector<Produto>& produtos) {
    ofstream arquivo("produtos.txt");
    if (arquivo.is_open()) {
        for (const Produto& p : produtos) {
            arquivo << "Nome do produto\n";
            arquivo << p.nome << endl;
            arquivo << "C�digo do produto\n";
            arquivo << p.codigo << endl;
            arquivo << "Pre�o do produto\n";
            arquivo << p.preco << endl;
        }
        arquivo.close();
    }
}

// Fun��o para verificar se o c�digo j� existe
bool codigoJaExiste(const vector<Produto>& produtos, int codigo) {
    for (const Produto& p : produtos) {
        if (p.codigo == codigo) {
            return true;
        }
    }
    return false;
}

// Fun��o para ler o relat�rio de caixa
void lerRelatorioCaixa() {
    ifstream arquivo("relatorio_caixa.txt");
    if (arquivo.is_open()) {
        string linha;
        while (getline(arquivo, linha)) {
            cout << linha << endl;
        }
        arquivo.close();
    } else {
        cout << "Erro ao abrir o arquivo de relat�rio de caixa." << endl;
    }
}

int main() {
    setlocale(LC_ALL,"");
    int opc;
    do {
        cout << "Digite 0 para encerrar.\n";
        this_thread::sleep_for(chrono::milliseconds(2000));
        system("cls");
        cout << "Escolha uma op��o: \n";
        cout << "1. Cadastrar senha de funcion�rios\n";
        cout << "2. Cadastrar um produto\n";
        cout << "3. Remover um produto\n";
        cout << "4. Relat�rio do caixa\n";
        cin >> opc;
        system("cls");
        switch(opc) {
            case 1: {
                //Cria��o de senha para funcion�rios
                cout << "1. Caixa\n";
                cout << "2. Gerente\n";
                cout << "3. Voltar\n";
                cin >> opc;
                system("cls");
                switch(opc) {
                    case 1: {
                        int senha;
                        cout << "Crie uma senha para o funcion�rio CAIXA: ";
                        cin >> senha;

                        ofstream arquivo("senha_caixa.txt");
                        if (arquivo.is_open()) {
                            arquivo << "Senha Caixa\n";
                            arquivo <<  senha << endl;
                            arquivo.close();
                            cout << "\n\nSenha criada com sucesso!\n";
                        } else {
                            cout << "Erro ao salvar a senha.\n";
                        }
                    break;
                    }
                    case 2: {
                        int senha2;
                        cout << "Crie uma senha para o funcion�rio GERENTE: ";
                        cin >> senha2;

                        ofstream arquivo2("senha_gerente.txt");
                        if (arquivo2.is_open()) {
                            arquivo2 << "Senha Gerente\n";
                            arquivo2 <<  senha2 << endl;
                            arquivo2.close();
                            cout << "\n\nSenha criada com sucesso!\n";
                        } else {
                            cout << "Erro ao salvar a senha.\n";
                        }
                    break;
                    }
                    default: {
                    break;
                    }
                }
            break;
            }
            case 2: {
                string nome;
                int codigo;
                double preco;

                // Carregar os produtos existentes no arquivo
                vector<Produto> produtos = carregarProdutos();

                cout << "Digite o nome do produto a ser registrado: ";
                cin.ignore();
                getline(cin, nome);

                // Solicitar c�digo e verificar se j� foi usado
                do {
                    cout << "Digite o c�digo desse produto: ";
                    cin >> codigo;
                    if (codigoJaExiste(produtos, codigo)) {
                        cout << "Esse c�digo j� foi utilizado. Por favor, insira outro c�digo.\n";
                    }
                } while (codigoJaExiste(produtos, codigo));

                cout << "Digite o pre�o por KG: ";
                cin >> preco;

                // Adicionar o novo produto
                produtos.push_back({nome, codigo, preco});

                // Salvar todos os produtos
                salvarProdutos(produtos);

                cout << "\nProduto cadastrado com sucesso!\n";
                this_thread::sleep_for(chrono::milliseconds(1000));
                system("cls");
            break;
            }
            case 3: {
                // Remover produto
                vector<Produto> produtos = carregarProdutos();

                if (produtos.empty()) {
                    cout << "N�o h� produtos cadastrados para remover.\n";
                    break;
                }

                cout << "Lista de produtos:\n";
                for (const Produto& p : produtos) {
                    cout << "C�digo: " << p.codigo << ", Nome: " << p.nome << endl;
                }

                int codigo;
                cout << "\nDigite o c�digo do produto que deseja remover: ";
                cin >> codigo;

                bool encontrado = false;

                // Procurar e remover o produto pelo c�digo
                for (auto it = produtos.begin(); it != produtos.end(); ++it) {
                    if (it->codigo == codigo) {
                        produtos.erase(it);
                        encontrado = true;
                        break;
                    }
                }

                if (encontrado) {
                    salvarProdutos(produtos);
                    cout << "Produto removido com sucesso!\n";
                } else {
                    cout << "C�digo do produto n�o encontrado.\n";
                }

                this_thread::sleep_for(chrono::milliseconds(2000));
                system("cls");
            break;
            }
            case 4:{
                // Chamar a fun��o para ler o relat�rio de caixa
                lerRelatorioCaixa();
                fflush(stdin);
                cout << "\n\nPressione 'ENTER' para continuar...\n";
                getchar();
                system("cls");
            break;
            }
        }
    } while (opc != 0);

    fflush(stdin);
    cout << "Encerrando...\n";
    this_thread::sleep_for(chrono::milliseconds(2000));
    cout << "\n\nPressione 'ENTER' para continuar...\n";
    getchar();
    system("cls");

    return 0;
}
