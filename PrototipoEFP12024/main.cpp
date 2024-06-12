#include <iostream>
#include <cstdlib>
#include <conio.h>
#include "Login.h"
#include "Bitacora.h"
#include "empleado.h"
#include "informes.h"

using namespace std;

void menuGeneral();
void catalogos();
void Informes();
void seguridad();
string codigoPrograma="1";
Bitacora Auditoria;
string usuario, contrasena;

int main()
{

    Login ingreso(usuario, contrasena);


    bool UsuarioCorrecto = ingreso.VerificarUsuario();


    if (UsuarioCorrecto)
    {
        menuGeneral();
    }

    return 0;
}

void menuGeneral()
{

    ifstream fileU;
    fileU.open("usuarios.txt",ios::in);



    if (!fileU)
    {
        cout<<"\n\t\t\t No es posible abrir el archivo."<<endl;
        fileU.close();
    }

    string user,pass;
    while (fileU>>user>>pass)
    {

    }
     fileU.close();
    int choice;


    do
    {
        system("cls");
        cout << "\t\t\t-------------------------------" << endl;
        cout << "\t\t\t| SISTEMA DE GESTION EMPLEADOS |" << endl;
        cout << "\t\t\t-------------------------------" << endl;
        cout << "\t\t\t 1. Catalogos" << endl;
        cout << "\t\t\t 2. Informes" << endl;
        cout << "\t\t\t 3. Seguridad" << endl;
        cout << "\t\t\t 4. Salir del Sistema" << endl;
        cout << "\t\t\t-------------------------------" << endl;
        cout << "\t\t\t|Opcion a escoger:[1/2/3/4]  |" << endl;
        cout << "\t\t\t-------------------------------" << endl;
        cout << "\t\t\tIngresa tu Opcion: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            catalogos();
            break;
        case 2:
            Informes();
            break;
        case 3:
            seguridad();
            break;
        case 4:
                    Auditoria.ingresoBitacora(user,codigoPrograma,"LGO"); //llamada para registrar la bitacora de seguridad
            exit(0);
        default:
            cout << "\n\t\t\t Opcion invalida...Por favor prueba otra vez..";
            cin.ignore();
            cin.get();
        }
    } while (choice != 4);
}

void catalogos()
{
    int choice;

    do
    {
        system("cls");
        cout << "\t\t\t--------------------------------------------" << endl;
        cout << "\t\t\t| SISTEMA DE GESTION EMPLEADOS - CATALOGOS |" << endl;
        cout << "\t\t\t--------------------------------------------" << endl;
        cout << "\t\t\t 1. Empleados" << endl;
        cout << "\t\t\t 2. Retornar menu anterior" << endl;
        cout << "\t\t\t --------------------------------------------" << endl;
        cout << "\t\t\t | Opcion a escoger:[1/2]|" << endl;
        cout << "\t\t\t --------------------------------------------" << endl;
        cout << "\t\t\tIngresa tu Opcion: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {

            empleado empleados;
            empleados.menu();
        }
            break;
        case 2:
            menuGeneral();
            break;
        default:
            cout << "\n\t\t\t Opcion invalida...Por favor prueba otra vez..";
            cin.ignore();
            cin.get();
        }
    } while (choice != 2);
}

void Informes()
{

    int choice;

    do
    {
        system("cls");
        cout << "\t\t\t--------------------------------------------" << endl;
        cout << "\t\t\t| SISTEMA DE IMPRESION DE EMPLEADOS - 1200 |" << endl;
        cout << "\t\t\t--------------------------------------------" << endl;
        cout << "\t\t\t 1. Implesion de archivo txt" << endl;
        cout << "\t\t\t 2. Retornar menu anterior" << endl;
        cout << "\t\t\t --------------------------------------------" << endl;
        cout << "\t\t\t | Opcion a escoger:[1/2]|" << endl;
        cout << "\t\t\t --------------------------------------------" << endl;
        cout << "\t\t\tIngresa tu Opcion: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {

            informes informe;
            informe.imprimirArchivo();
        }
            break;
        case 2:
            menuGeneral();
            break;
        default:
            cout << "\n\t\t\t Opcion invalida...Por favor prueba otra vez..";
            cin.ignore();
            cin.get();
        }
    } while (choice != 2);
}

void seguridad()
{
    int choice;

    do
    {
        system("cls");
        cout << "\t\t\t--------------------------------------------" << endl;
        cout << "\t\t\t|   SISTEMA DE GESTION UMG - PROCESOS      |" << endl;
        cout << "\t\t\t--------------------------------------------" << endl;
        cout << "\t\t\t 1. Consultar bitacora" << endl;
        cout << "\t\t\t 2. Retornar menu anterior" << endl;
        cout << "\t\t\t --------------------------------------------" << endl;
        cout << "\t\t\t | Opcion a escoger:[1/2]|" << endl;
        cout << "\t\t\t --------------------------------------------" << endl;
        cout << "\t\t\tIngresa tu Opcion: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            Bitacora Auditoria;
            Auditoria.visualizarBitacora();
        }
            break;
        case 2:
            menuGeneral();
            break;
        default:
            cout << "\n\t\t\t Opcion invalida...Por favor prueba otra vez..";
            cin.ignore();
            cin.get();
        }
    } while (choice != 2);
}
