/*
Libreria que se encarga de guardar los tamalgochis y de checar que esten creados
*/

#include <stdlib.h>
#include <fstream>
#include <ctype.h>
#include <string.h>

//Defines
#define vida 100
#define ataque 50

using namespace std;

//Variables
string RTnotificacion;

//Prototipos
void crear();
int iniciar();
string Fmensaje();

//Funciones

void crear(){
    system("cls");
    string notificacion = "No uses espacios, estos se ignoraran";
    char nombre[20],verificacion;
    string nombreString,Direccion= "Archivos/";
    int j,a=0,largo;
    ofstream archivo;
    ifstream buscador;
    bool libre;

    do{
        cout << "\n\n\tCreador\n\n";

        cout << "Notificacion: " << notificacion << endl << endl
             << "¿Como se llamara tu Tamalgochi?" << endl
             << "=> ";
        getline(cin,nombreString);

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
            verificacion = toupper(verificacion);
            fflush(stdin);
        }while(verificacion != 'S' && verificacion != 'N');

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
            archivo << nombreString << " " << vida << " " << ataque << endl;
            archivo.close();
            RTnotificacion = "Tamalgochi creado con exito";

        }

    }while(libre != true);



}

string Fmensaje(){
    return RTnotificacion;

}
