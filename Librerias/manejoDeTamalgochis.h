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
    ofstream archivo;
    ifstream buscador;
    string notificacion = "No uses espacios, estos se ignoraran";
     string nombreString,Direccion,DireccionNumeroInventario,DireccionInventario;
    char nombre[50],nombreLista[50],nombreInventario[50],numeroInventario[50],verificacion;
    int j,a=0,largo;
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


        DireccionNumeroInventario = Direccion + nombreString + "numeroInventario.txt";
        DireccionInventario = Direccion + nombreString + "inventario.txt";
        Direccion = Direccion + nombreString + ".txt";

        //Direccion del archivo
        strcpy(nombre,Direccion.c_str());
        //Direccion del numero de inventario
        strcpy(numeroInventario,DireccionNumeroInventario.c_str());
        //Direccion del inventario
        strcpy(nombreInventario,DireccionInventario.c_str());

        //Quita los espacios de la direccion
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

        //Comprueba si es correcto el nombre

        do{
            cout << "\n¿Es correcto? s/n" << endl
                 << "=> ";
            cin >> verificacion;
            cin.ignore();
            verificacion = toupper(verificacion);
        }while(verificacion != 'S' && verificacion != 'N');

        //En caso de serlo

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

                //Crea los archivos de un tamagochi
                archivo.open(nombre,ios::app);
                archivo << nombreLista << " " << vida << " " << ataque << " " << defensa << endl;
                archivo.close();

                //Guarda el numero de inventario que tendra

                archivo.open(numeroInventario,ios::app);
                archivo << inventario;
                archivo.close();

                //Crear el inventario

                archivo.open(nombreInventario,ios::app);
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
        system("cls");

    }while(libre != true);

}

string Fmensaje(){
    return RTnotificacion;

}
