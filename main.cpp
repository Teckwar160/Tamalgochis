#include <iostream>
#include <stdlib.h>
#include <ctype.h>
#include <string>
#include <locale>

using namespace std;

//Variables
string notificacion = "Escoge una opci�n";
char decision;

//Prototipos

//Main

int main(){
    setlocale(LC_CTYPE,"Spanish");

    do{
        system("cls");
        cout << "\n\n\tTamalgochis\n\n";

        cout << "Notificacion: " << notificacion << endl
             << "a) Crear un Tamalgochi" << endl
             << "b) Entrar al juego" << endl
             << "c) Salir" << endl
             << "=> ";
        cin >> decision;

        decision = toupper(decision);

        switch (decision){
            case 'A':
                notificacion = "";
                break;
            case 'B':
                notificacion = "";
                break;
            case 'C':
                break;
            default:
            notificacion = "Opci�n invalida";
            break;
        }
        system("cls");
    }while(decision != 'C');


}

//Funcioens
