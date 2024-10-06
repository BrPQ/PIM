#include <iostream>
#include <locale.h>
#include <fstream>

using namespace std;

int main()
{
    setlocale(LC_ALL,"");



    //Criação de senha para funcionários
    int senha;
    cout << "Crie uma senha para o funcionário: ";
    cin >> senha;

    ofstream arquivo("senha_funcionario.txt");
    if (arquivo.is_open()) {
        arquivo << "Senha Funcionário\n";
        arquivo <<  senha << endl;
        arquivo.close();
            cout << "\n\nSenha criada com sucesso!\n";
    } else {
        cout << "Erro ao salvar o relatório.\n";
    }





    return 0;
}
