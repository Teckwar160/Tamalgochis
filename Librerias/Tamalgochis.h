/*
Esta libreria es donde estaran todas las funciones de los Tamalgochis
*/

#include <stdlib.h>
#include <fstream>
#include <ctype.h>
#include <string.h>

//Variables
string Tamalgochi;

//Prototipos

void Tamalgochis();

//Funciones



void Tamalgochis(){

    //Variables
    char decision;
    string notificacion;

    //Funcion

    //Nombre de tu tamalgochi

    Tamalgochi = Fnombre();

    //Menu

    do{
        cout << "\n\n\tTamalgochis\n\n";
        cout << "=>Tamalgochi: " << Tamalgochi << endl << endl;
        cout << "Notificacion: " << notificacion << endl;

        cout << "a) Inventario" << endl
             << "b) Tienda" << endl
             << "c) Sala de  entrenamiento" << endl
             << "d) Sala de combate" << endl
             << "e) Regresar al menu principal" << endl
             << "f) Salir" << endl
             << "=> ";
        cin >> decision;
        decision = toupper(decision);
        fflush(stdin);

        switch (decision){
            case 'A':
                notificacion ="";
                break;
            case 'B':
                notificacion ="";
                break;
            case 'C':
                notificacion ="";
                break;
            case 'D':
                notificacion ="";
                break;
            case 'E':
                notificacion ="";
                break;
            case 'F':
                system("cls");
                cout << "\n\nGracias por jugar\n\n";
                exit(0);
                break;
            default:
                notificacion = "Opción invalida";
                break;


        }
        system("cls");
    }while(decision != 'E');

}








