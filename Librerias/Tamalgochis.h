/*
Esta libreria es donde estaran todas las funciones de los Tamalgochis
*/

#include <stdlib.h>
#include <fstream>
#include <ctype.h>
#include <string.h>

//Variables
string Tamalgochi;
string RTnotificacionTamalgochi;
string DireccionTama;
string DireccionNumInventario;
string DireccionInventa;

//Prototipos

void Tamalgochis();
void MenuInventario();
string FnotificacionTamalgochi();

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
                MenuInventario();
                notificacion = RTnotificacionTamalgochi;
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

void MenuInventario(){

    //Retornos
    DireccionTama = DT();
    DireccionNumInventario = DN();
    DireccionInventa = DI();

    //Variables
    ifstream archivoNumero,lecturaDelInventario;
    ofstream archivoTamalgochi;
    ofstream archivoInventa;
    char DirecTama[50],DirecNum[50],DirecInventa[50];
    int CantidadDeInventario;
    string elemento;



    //Transformacion a char

    //Direccion del archivo
    strcpy(DirecTama,DireccionTama.c_str());
    //Direccion del numero de inventario
    strcpy(DirecNum,DireccionNumInventario.c_str());
    //Direccion del inventario
    strcpy(DirecInventa,DireccionInventa.c_str());


    //Funcion

    //do{
        //Lee el numero de elementos del inventario
        archivoNumero.open(DirecNum,ios::in);
        archivoNumero >> CantidadDeInventario;
        archivoNumero.close();

        //
        string ElementosDeInventrio[CantidadDeInventario];




    //}while();


}

string FnotificacionTamalgochi(){
    return RTnotificacionTamalgochi;
}








