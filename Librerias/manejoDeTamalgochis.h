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
bool RTValidacionDeInicio;

//Prototipos
void crear();
void iniciar();
void Tamalgochis();
string Fmensaje();
bool ControlDEInicio();

//Funciones

void crear(){
    //Variables de Crear
    ofstream archivo;
    ifstream buscador;
    string notificacion = "Si introduces espacios estos se eliminaran";
    string nombreString,Direccion,DireccionNumeroInventario,DireccionInventario;
    char nombre[50],nombreLista[50],nombreInventario[50],numeroInventario[50],verificacion;
    int j,a=0,largo;
    bool libre;

    //Inicio de la funcion

    system("cls");

    do{
        //Variables que se tienen que resetear
        Direccion = "Archivos/";
        largo =0;
        a=0;
        j=0;

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
                archivo << "=> "<< nombreLista << endl;
                archivo.close();

                RTnotificacion = "Tamalgochi creado con exito";

            }
        }else{
            system("cls");
        }
        system("cls");

    }while(libre != true);

}

void iniciar(){

    //Variables
    string notificacion = "Si introduces espacios estos se eliminaran",texto;
    ifstream buscador,mostrador;
    string nombreString,Direccion,DireccionNumeroInventario,DireccionInventario;
    char nombre[50],nombreLista[50],nombreInventario[50],numeroInventario[50];
    int j,a=0,largo;
    bool ValidacionInicio;

    //Inicio de la funcion

    system("cls");

    do{
        //Variables que se tienen que resetear
        Direccion = "Archivos/";
        //Muestra los Tamalgochis registrados
        mostrador.open("Archivos/Tamalgochis.txt",ios::in);

        if(mostrador.fail()){
            RTnotificacion = "No hay ningun tamalgochi registrado";
            ValidacionInicio = true;
        }else{

            cout << "\n\n\tTamalgochis Disponibles\n\n";

            while(!mostrador.eof()){
                getline(mostrador,texto);
                cout << texto << endl;
            }
            mostrador.close();

            cout << "Notificacion: " << notificacion << endl << endl
                 << "Nombre: ";
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
            buscador.open(nombre,ios::in);
            if(!buscador.fail()){
                ValidacionInicio = true;
                RTValidacionDeInicio = true;
            }else{
                notificacion = "Tamalgochi no encontrado";
                ValidacionInicio = false;
            }
            buscador.close();




        }
        system("cls");
    }while(ValidacionInicio != true);









}

void Tamalgochis(){
    system("cls");
    cout << "Entraste a Tamalgochis" << endl << endl;
    system("pause");

}

string Fmensaje(){
    return RTnotificacion;

}

bool ControlDEInicio(){
    return RTValidacionDeInicio;

}
