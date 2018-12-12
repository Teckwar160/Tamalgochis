/*
Libreria que se encarga de guardar los tamalgochis y de checar que esten creados
*/

#include <stdlib.h>
#include <fstream>
#include <ctype.h>
#include <string.h>

//Defines
#define vida 10
#define ataque 5
#define defensa 5
#define inventario 5

using namespace std;

//Variables
string RTnotificacion;

//Prototipos
void crear();
int iniciar();
string Fmensaje();

//Funciones

void crear(){
    //Variables de Crear
    string notificacion = "No uses espacios, estos se ignoraran";
    char nombre[20],nombreLista[20],verificacion;
    string nombreString,Direccion;
    int j,a=0,largo;
    ofstream archivo;
    ifstream buscador;
    bool libre;

    //Inicio de la funcion

    system("cls");

    do{
        //Variables que se tienen que resetear
        Direccion = "Archivos/";

        //Contenido
        cout << "\n\n\tCreador\n\n";

        cout << "Notificacion: " << notificacion << endl << endl
             << "¿Como se llamara tu Tamalgochi?" << endl
             << "=> ";
        getline(cin,nombreString);


        //Quita los espacios del nombre para la lista

        strcpy(nombreLista,nombreString.c_str());

        largo = strlen(nombreLista);
        while(nombreLista[a]!='\0'){
            if (nombreLista[a]==' '){
                for(j=a;j<largo;j++){
                    nombreLista[j]=nombreLista[j+1];
                }
                largo--;
            }
            a++;
        }

        //Variables que se resetean
        largo =0;
        a=0;
        j=0;


        //Quita los espacios del nombre para evitar problemas

        Direccion = Direccion + nombreString + ".txt";


        strcpy(nombre,Direccion.c_str());

        largo = strlen(nombre);
        while(nombre[a]!='\0'){
            if (nombre[a]==' '){
                for(j=a;j<largo;j++){
                    nombre[j]=nombre[j+1];
                }
                largo--;
            }
            a++;
        }

        do{
            cout << "\n¿Es correcto? s/n" << endl
                 << "=> ";
            cin >> verificacion;
            cin.ignore();
            verificacion = toupper(verificacion);
        }while(verificacion != 'S' && verificacion != 'N');

        if (verificacion == 'S'){

        buscador.open(nombre,ios::in);
        if(!buscador.fail()){
            notificacion = "El nombre ya esta en uso";
            libre = false;
        }else{
            libre = true;
        }
        buscador.close();


        if(libre == true){
            archivo.open(nombre,ios::app);
            archivo << nombreLista << " " << vida << " " << ataque << " " << defensa << " " << inventario << endl;
            archivo.close();

            //Lista de todos los Tamalgochis

            archivo.open("Archivos/Tamalgochis.txt",ios::app);
            archivo << nombreLista << endl;
            archivo.close();

            RTnotificacion = "Tamalgochi creado con exito";

        }
        }else{
            system("cls");
        }

    }while(libre != true);

    fflush(stdin);



}

string Fmensaje(){
    return RTnotificacion;

}
