#include <iostream>
#include <locale.h>
#include <fstream>

using namespace std;

int main()
{
    setlocale(LC_ALL,"");



    //Cria��o de senha para funcion�rios
    int senha;
    cout << "Crie uma senha para o funcion�rio: ";
    cin >> senha;

    ofstream arquivo("senha_funcionario.txt");
    if (arquivo.is_open()) {
        arquivo << "Senha Funcion�rio\n";
        arquivo <<  senha << endl;
        arquivo.close();
            cout << "\n\nSenha criada com sucesso!\n";
    } else {
        cout << "Erro ao salvar o relat�rio.\n";
    }





    return 0;
}
