#include <iostream>
#include <locale.h>
#include <fstream>

using namespace std;

int main()
{
    setlocale(LC_ALL,"");
    int opc;

    cout << "Escolha uma op��o: \n";
    cout << "1. Cadastrar senha de funcion�rio\n";
    cin >> opc;
    switch(opc){
        case 1:


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




    }
    return 0;
}
