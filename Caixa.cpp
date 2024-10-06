#include <iostream>
#include <locale.h>
#include <thread>
#include <vector>
#include <fstream>
#include <iomanip>

using namespace std;

#define SENHA 123456

// Estrutura para armazenar informações do produto
struct Produto {
    string nome;
    double peso;
    double preco;
};

// Função para remover um produto da lista
void removerProduto(vector<Produto>& produtosVendidos, double& total) {
    if (produtosVendidos.empty()) {
        cout << "Nenhum produto para remover.\n";
        return;
    }

    // Exibir os produtos vendidos
    cout << "Produtos vendidos até agora:\n";
    for (int i = 0; i < produtosVendidos.size(); i++) {
        cout << i + 1 << ". " << produtosVendidos[i].nome << " - " << produtosVendidos[i].peso << " kg - R$ " << produtosVendidos[i].preco << endl;
    }

    int indiceRemover;
    cout << "\nDigite o número do produto que deseja remover: ";
    cin >> indiceRemover;

    if (indiceRemover > 0 && indiceRemover <= produtosVendidos.size()) {
        // Subtrai o valor do produto removido do total
        total -= produtosVendidos[indiceRemover - 1].preco;
        produtosVendidos.erase(produtosVendidos.begin() + (indiceRemover - 1));
        cout << "Produto removido com sucesso!\n";
    } else {
        cout << "Número inválido, tente novamente.\n";
    }
}

int main()
{
    setlocale(LC_ALL, "");
    int opc;

    cout << "*****************************************************\n";
    cout << "|                                                   |\n";
    cout << "|             HORTIFRUTI ESTAÇÃO VERDE              |\n";
    cout << "|                                                   |\n";
    cout << "*****************************************************\n";
    this_thread::sleep_for(chrono::milliseconds(500));

    cout << "O que deseja fazer?\n\n";
    cout << "1. Acessar sistema.\n\n";
    cout << "2. Sair do sistema.\n\n";
    cin >> opc;
    cout << endl;

    fflush(stdin);
    if (opc == 1) {
        cout << "Voce escolheu entrar no sistema!\n\n";
        cout << "Digite 'ENTER' para continuar...\n";
    } else if (opc == 2) {
        cout << "Voce escolheu sair do sistema!";
    }
    getchar();
    system("cls");

    switch (opc) {
        case 1: {
            int senhaDigitada;
            do {
                cout << "Digite a senha para continuar: ";
                cin >> senhaDigitada;
                if (senhaDigitada == SENHA) {
                    cout << "Senha correta! Acesso concedido!\n\n";
                    fflush(stdin);
                    cout << "Digite 'ENTER' para continuar...\n";
                    getchar();
                    system("cls");
                } else {
                    cout << "Senha incorreta, tente novamente!\n\n";
                    fflush(stdin);
                    cout << "Digite 'ENTER' para continuar...\n";
                    getchar();
                    system("cls");
                }
            } while (senhaDigitada != SENHA);

            int N200, N100, N50, N20, N10, N5, N2, M1, M50, M25, M10, M5;
            double dinheiroCaixa = 0, totalCredito = 0, totalDebito = 0, totalDinheiro = 0;
            cout << "Bem vindo(a)!\n";
            cout << "Digite a quantia que vai entrar no caixa!\n";
            cout << "Quantas notas de R$ 200?\n";
            cin >> N200;
            dinheiroCaixa = dinheiroCaixa + (N200 * 200);
            cout << "Quantas notas de R$ 100?\n";
            cin >> N100;
            dinheiroCaixa = dinheiroCaixa + (N100 * 100);
            cout << "Quantas notas de R$ 50?\n";
            cin >> N50;
            dinheiroCaixa = dinheiroCaixa + (N50 * 50);
            cout << "Quantas notas de R$ 20?\n";
            cin >> N20;
            dinheiroCaixa = dinheiroCaixa + (N20 * 20);
            cout << "Quantas notas de R$ 10?\n";
            cin >> N10;
            dinheiroCaixa = dinheiroCaixa + (N10 * 10);
            cout << "Quantas notas de R$ 5?\n";
            cin >> N5;
            dinheiroCaixa = dinheiroCaixa + (N5 * 5);
            cout << "Quantas notas de R$ 2?\n";
            cin >> N2;
            dinheiroCaixa = dinheiroCaixa + (N2 * 2);
            cout << "Quantas moedas de R$ 1?\n";
            cin >> M1;
            dinheiroCaixa = dinheiroCaixa + (M1 * 1);
            cout << "Quantas moedas de R$ 0,50?\n";
            cin >> M50;
            dinheiroCaixa = dinheiroCaixa + (M50 * 0.5);
            cout << "Quantas moedas de R$ 0,25?\n";
            cin >> M25;
            dinheiroCaixa = dinheiroCaixa + (M25 * 0.25);
            cout << "Quantas moedas de R$ 0,10?\n";
            cin >> M10;
            dinheiroCaixa = dinheiroCaixa + (M10 * 0.1);
            cout << "Quantas moedas de R$ 0,05?\n";
            cin >> M5;
            dinheiroCaixa = dinheiroCaixa + (M5 * 0.05);
            cout << fixed << setprecision(2);
            cout << "O caixa será incializado com: R$" << dinheiroCaixa << endl;
            this_thread::sleep_for(chrono::milliseconds(500));
            fflush(stdin);
            cout << "Precione 'ENTER' para continuar...\n";
            getchar();
            system("cls");
            cout << "Inicializando sistema, aguarde...\n";
            this_thread::sleep_for(chrono::milliseconds(5000));
            system("cls");

            int codigos[] = {1, 2, 3, 4, 5};
            string nomes[] = {"Maçã", "Banana", "Laranja", "Batata", "Tomate"};
            float precos[] = {5.99, 3.49, 4.29, 2.89, 6.50};

            int codigo;
            double peso, total = 0;
            char tecla;

            vector<Produto> produtosVendidos;
            bool finalizarDia = false;

            while (!finalizarDia) {
                produtosVendidos.clear();
                total = 0;
                system("cls");
                cout << "*****************************************************\n";
                cout << "|                                                   |\n";
                cout << "|                  CAIXA LIVRE                      |\n";
                cout << "|                                                   |\n";
                cout << "*****************************************************\n\n";
                cout << "Digite 1 para registrar compra.\n";
                cout << "Digite 2 para finalizar o caixa.\n";
                int escolha;
                cin >> escolha;
                if (escolha == 1) {
                    do {
                        cout << "\nDigite o código do produto: ";
                        cin >> codigo;

                        if (codigo >= 1 && codigo <= 5) {
                            int indice = codigo - 1;

                            cout << "Produto: " << nomes[indice] << endl;
                            cout << "Digite o peso (em kg): ";
                            cin >> peso;

                            double preco = precos[indice] * peso;
                            total += preco;
                            produtosVendidos.push_back({nomes[indice], peso, preco});

                            cout << "Adicionado: " << nomes[indice] << " - " << peso << " kg - R$ " << preco << endl;
                            this_thread::sleep_for(chrono::milliseconds(1000));
                        } else {
                            cout << "Código inválido, tente novamente.\n";
                            this_thread::sleep_for(chrono::milliseconds(1000));
                            system("cls");
                            continue;
                        }

                        system("cls");
                        for (const auto& produto : produtosVendidos) {
                            cout << produto.nome << " - " << produto.peso << " kg - R$ " << produto.preco << endl;
                        }

                        cout << "\nDeseja finalizar a compra? (S/N): ";
                        cin >> tecla;
                        while (tecla != 'S' && tecla != 's') {
                            cout << "\nO que deseja fazer?\n";
                            cout << "1. Remover um produto\n";
                            cout << "2. Adicionar outro produto\n";
                            cout << "3. Finalizar compra\n";
                            int opcao;
                            cin >> opcao;

                            switch (opcao) {
                                case 1:
                                    removerProduto(produtosVendidos, total);
                                    break;
                                case 2:
                                    cout << "\nDigite o código do produto: ";
                                    cin >> codigo;
                                    if (codigo >= 1 && codigo <= 5) {
                                        int indice = codigo - 1;
                                        cout << "Produto: " << nomes[indice] << endl;
                                        cout << "Digite o peso (em kg): ";
                                        cin >> peso;

                                        double preco = precos[indice] * peso;
                                        total += preco;
                                        produtosVendidos.push_back({nomes[indice], peso, preco});
                                        cout << "Adicionado: " << nomes[indice] << " - " << peso << " kg - R$ " << preco << endl;
                                        this_thread::sleep_for(chrono::milliseconds(2000));
                                    } else {
                                        cout << "Código inválido, tente novamente.\n";
                                        this_thread::sleep_for(chrono::milliseconds(1000));
                                        system("cls");
                                        continue;
                                    }
                                    break;
                                case 3:
                                    tecla = 'S';
                                    break;
                                default:
                                    cout << "Opção inválida, tente novamente.\n";
                                    break;
                            }

                            system("cls");
                            for (const auto& produto : produtosVendidos) {
                                cout << produto.nome << " - " << produto.peso << " kg - R$ " << produto.preco << endl;
                            }
                            cout << fixed << setprecision(2);
                            cout << "\nTotal a pagar: R$ " << total << endl;
                        }

                    } while (tecla != 'S' && tecla != 's');

                    // Pagamento
                    int formaPagamento;
                    bool pagamentoConcluido = false;

                    while (!pagamentoConcluido) {
                        for (const auto& produto : produtosVendidos) {
                                cout << produto.nome << " - " << produto.peso << " kg - R$ " << produto.preco << endl;
                            }
                            cout << fixed << setprecision(2);
                            cout << "\nTotal a pagar: R$ " << total << endl;
                        cout << "Forma de pagamento:\n";
                        cout << "1. Dinheiro\n";
                        cout << "2. Cartão de crédito\n";
                        cout << "3. Cartão de débito\n";
                        cin >> formaPagamento;

                        switch (formaPagamento) {
                            case 1: {
                                double valorPago, troco;
                                cout << "Digite o valor pago: ";
                                cin >> valorPago;
                                if (valorPago >= total) {
                                    troco = valorPago - total;
                                    cout << fixed << setprecision(2);
                                    cout << "Troco: R$ " << troco << endl;
                                    dinheiroCaixa += total;
                                    dinheiroCaixa -= troco;
                                    totalDinheiro += total;
                                    pagamentoConcluido = true;
                                    cout << "\nPagamento realizado com sucesso!\n";
                                    fflush(stdin);
                                    cout << "\n\nPrecione 'ENTER' para continuar...\n";
                                    getchar();
                                    system("cls");
                                } else {
                                    cout << "Valor insuficiente, operação cancelada.\n";
                                    this_thread::sleep_for(chrono::milliseconds(2000));
                                    system("cls");
                                }
                                break;
                            }
                            case 2: {
                                cout << "Pagamento com cartão de crédito.\n";
                                totalCredito += total;
                                pagamentoConcluido = true;
                                this_thread::sleep_for(chrono::milliseconds(1000));
                                cout << "\nPagamento realizado com sucesso!\n";
                                fflush(stdin);
                                cout << "\n\nPrecione 'ENTER' para continuar...\n";
                                getchar();
                                system("cls");
                                break;
                            }
                            case 3: {
                                cout << "Pagamento com cartão de débito.\n";
                                totalDebito += total;
                                pagamentoConcluido = true;
                                this_thread::sleep_for(chrono::milliseconds(1000));
                                cout << "\nPagamento realizado com sucesso!\n";
                                fflush(stdin);
                                cout << "\n\nPrecione 'ENTER' para continuar...\n";
                                getchar();
                                system("cls");
                                break;
                            }
                            default: {
                                cout << "Opção inválida, tente novamente.\n";
                                break;
                            }
                        }
                    }

                } else if (escolha == 2) {
                    cout << "Finalizando o caixa...\n";
                    finalizarDia = true;
                }
            }

            // Exibe os totais e finaliza o programa
            cout << fixed << setprecision(2);
            cout << "Total em caixa: R$ " << dinheiroCaixa << endl;
            this_thread::sleep_for(chrono::milliseconds(500));
            cout << fixed << setprecision(2);
            cout << "\nTotal de vendas em dinheiro: R$ " << totalDinheiro << endl;
            this_thread::sleep_for(chrono::milliseconds(500));
            cout << fixed << setprecision(2);
            cout << "\nTotal de vendas no cartão de crédito: R$ " << totalCredito << endl;
            this_thread::sleep_for(chrono::milliseconds(500));
            cout << fixed << setprecision(2);
            cout << "\nTotal de vendas no cartão de débito: R$ " << totalDebito << endl;
            this_thread::sleep_for(chrono::milliseconds(500));
            cout << "\nTotal geral: R$ " << totalCredito + totalDebito + totalDinheiro << endl;


	    // Gravar os dados no arquivo
            ofstream arquivo("relatorio_caixa.txt");
            if (arquivo.is_open()) {
                arquivo << "Relatório do Caixa\n";
                arquivo << "------------------\n\n";
                arquivo << "Produtos vendidos:\n";
                for (const auto& produto : produtosVendidos) {
                    arquivo << produto.nome << " - " << produto.peso << " kg - R$ " << produto.preco << endl;
                }
                arquivo << "\nTotal em caixa: R$ " << dinheiroCaixa << endl;
                arquivo << "Total de vendas no dinheiro: R$ " << totalDinheiro << endl;
                arquivo << "Total de vendas no cartão de crédito: R$ " << totalCredito << endl;
                arquivo << "Total de vendas no cartão de débito: R$ " << totalDebito << endl;
                arquivo.close();
                cout << "\n\nRelatório salvo com sucesso!\n";
            } else {
                cout << "Erro ao salvar o relatório.\n";
            }

            break;
        }
        case 2:
            break;
    }

    fflush(stdin);
    cout << "\n\nPrecione 'ENTER' para continuar...\n";
    getchar();
    system("cls");

    return 0;
}
