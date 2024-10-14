#include <iostream>
#include <locale.h>
#include <fstream>

using namespace std;

int main()
{
    setlocale(LC_ALL,"");
    int opc;

    cout << "Escolha uma opção: \n";
    cout << "1. Cadastrar senha de funcionários\n";
    cin >> opc;
    system("cls");
    switch(opc){
        case 1:
        //Criação de senha para funcionários
                cout << "1. Caixa\n";
                cout << "2. Gerente\n";
                cin >> opc;
                system("cls");
            switch(opc){
                case 1:{
                    int senha;
                    cout << "Crie uma senha para o funcionário CAIXA: ";
                    cin >> senha;

                    ofstream arquivo("senha_caixa.txt");
                    if (arquivo.is_open()) {
                        arquivo << "Senha Caixa\n";
                        arquivo <<  senha << endl;
                        arquivo.close();
                            cout << "\n\nSenha criada com sucesso!\n";
                    } else {
                        cout << "Erro ao salvar o relatório.\n";
                    }
                break;
                }
                case 2:{
                    int senha2;
                    cout << "Crie uma senha para o funcionário GERENTE: ";
                    cin >> senha2;

                    ofstream arquivo2("senha_gerente.txt");
                    if (arquivo2.is_open()) {
                        arquivo2 << "Senha Gerente\n";
                        arquivo2 <<  senha2 << endl;
                        arquivo2.close();
                            cout << "\n\nSenha criada com sucesso!\n";
                    } else {
                        cout << "Erro ao salvar o relatório.\n";
                    }
                break;
                }
            }
    }



    return 0;
}
