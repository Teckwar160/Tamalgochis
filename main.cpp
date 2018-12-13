#include <iostream>
#include <stdlib.h>
#include <ctype.h>
#include <string>
#include <locale>
#include "Librerias\manejoDeTamalgochis.h"
#include "Librerias\Tamalgochis.h"

using namespace std;

//Variables
string notificacion = "Escoge una opción";
char decision;
bool BanderaDeInicio;


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
        fflush(stdin);

        switch (decision){
            case 'A':
                crear();
                notificacion = Fmensaje();
                break;
            case 'B':
                iniciar();
                notificacion = Fmensaje();
                BanderaDeInicio = ControlDEInicio();

                if(BanderaDeInicio == true)
                    Tamalgochis();
                break;
            case 'C':
                break;
            default:
            notificacion = "Opción invalida";
            break;
        }
        system("cls");
    }while(decision != 'C');

    return 0;


}
