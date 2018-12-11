/*
Libreria que se encarga de guardar los tamalgochis y de checar que esten creados
*/

#include <stdlib.h>
#include <fstream>
#include <ctype.h>
#include <string.h>

using namespace std;

//Variables

//Prototipos
void crear();
int iniciar();

//Funciones

void crear(){
    system("cls");
    string notificacion = "No uses espacios, estos se ignoraran";
    string lecturaAD,nombreString;
    char nombre[20],verificacion;
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

        strcpy(nombre,nombreString.c_str());

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

        string(nombre);

        do{
            cout << "\n¿Es correcto? s/n" << endl
                 << "=> ";
            cin >> verificacion;
            verificacion = toupper(verificacion);
            fflush(stdin);
        }while(verificacion != 'S' && verificacion != 'N');

        archivo.open("Archivos/tamalgochis.txt",ios::app);
        buscador.open("Archivos/tamalgochis.txt");
        buscador >> lecturaAD;

        if (archivo.fail()){
            notificacion = "No se puede abrir la base de datos";
        }

        while(!buscador.eof()){
            if(lecturaAD == nombre){
                notificacion = "El usuario ya esta en uso";
                libre = false;
            }else{
                libre = true;

            }
            buscador >> lecturaAD;
        }
        if (libre == true){
            archivo << nombre << endl;
        }
        buscador.close();
        archivo.close();

        system("cls");
    }while(libre != true);



}
