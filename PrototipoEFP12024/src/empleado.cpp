#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<cstdlib>
#include<iomanip>
#include <sstream>
#include <cstring>
#include "empleado.h"
#include"Bitacora.h"

using namespace std;


struct Empleado {
    char codigo_empleado[5];
    char nombre_empleado[60];
    char codigo_puesto[5];
    char codigo_departamento[5];
    char sueldo_empleado[10];
    char status_empleado[1];
};



void empleado::menu()
{

    string codigoPrograma = "1100";
    Bitacora Auditoria;

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
    char x;


    do
    {
        system("cls");


        cout<<"\t\t\t-----------------------------------------"<<endl;
        cout<<"\t\t\t| SISTEMA DE GESTION EMPLEADOS -  1100  |"<<endl;
        cout<<"\t\t\t-----------------------------------------"<<endl;
        cout<<"\t\t\t 1. Ingreso empleados"<<endl;
        cout<<"\t\t\t 2. Despliegue empleados"<<endl;
        cout<<"\t\t\t 3. Modifica empleados"<<endl;
        cout<<"\t\t\t 4. Borra empleados"<<endl;
        cout<<"\t\t\t 5. Retornar menu anterior"<<endl;
        cout<<"\t\t\t-----------------------------------------"<<endl;
        cout<<"\t\t\tOpcion a escoger:[1/2/3/4/5]"<<endl;
        cout<<"\t\t\t-----------------------------------------"<<endl;
        cout<<"\t\t\tIngresa tu Opcion: ";
        cin>>choice;

        switch(choice)
        {
        case 1:

            do
            {
                insertar();

                Auditoria.ingresoBitacora(user,codigoPrograma,"INS");
                cout<<"\n\t\t\t Agrega otra Sede(Y,N): ";
                cin>>x;
            } while(x=='y'||x=='Y');
            break;
        case 2:
            desplegar();

            Auditoria.ingresoBitacora(user,codigoPrograma,"CON");
            break;
        case 3:
            modificar();

            Auditoria.ingresoBitacora(user,codigoPrograma,"MOD");
            break;
        case 4:
            borrar();

            Auditoria.ingresoBitacora(user,codigoPrograma,"DEL");
            break;
        case 5:
            break;
        default:
            cout<<"\n\t\t\t Opcion invalida...Por favor prueba otra vez..";
            cin.get();
        }
    } while(choice!= 5);
}


void empleado::insertar() {
    system("cls");
    Empleado empleado;
    ofstream file("empleados.dat", ios::binary | ios::app);


    if (!file) {
        cerr << "No se pudo abrir el archivo." << endl;
        return;
    }


    cout << "\n--------------------------------------------------------------------------------------------------------------------";
    cout << "\n-------------------------------------------------Agregar Empleado---------------------------------------------------" << endl;
    cout << "\t\t\tIngrese codigo del empleado   : ";
    cin.ignore();
    cin.getline(empleado.codigo_empleado, sizeof(empleado.codigo_empleado));
    cout << "\t\t\tIngrese nombre del empleado   : ";
    cin.getline(empleado.nombre_empleado, sizeof(empleado.nombre_empleado));
    cout << "\t\t\tIngrese codigo de puesto      : ";
    cin.getline(empleado.codigo_puesto, sizeof(empleado.codigo_puesto));
    cout << "\t\t\tIngrese codigo de departamento: ";
    cin.getline(empleado.codigo_departamento, sizeof(empleado.codigo_departamento));
    cout << "\t\t\tIngrese el sueldo del empleado: ";
    cin.getline(empleado.sueldo_empleado, sizeof(empleado.sueldo_empleado));
    cout << "\t\t\tIngrese status del empleado (solvente=1 | pendiente=0): ";
    cin.getline(empleado.status_empleado, sizeof(empleado.status_empleado));
    file.write(reinterpret_cast<const char*>(&empleado), sizeof(Empleado));
    file.close();
}


void empleado::desplegar(){
    system("cls");
    ifstream file("empleados.dat", ios::binary);

    if (!file) {
        cerr << "No se pudo abrir el archivo." << endl;
        return;
    }

    int total = 0;


    cout << "\n-----------------------------------------Tabla Detalles de empleados ----------------------------------------------" << endl;
    Empleado empleado;
    while (file.read(reinterpret_cast<char*>(&empleado), sizeof(Empleado))) {
        cout << "\t\t\t Codigo de empleado     : " << empleado.codigo_empleado<< endl;
        cout << "\t\t\t Nombre de empleado     : " << empleado.nombre_empleado << endl;
        cout << "\t\t\t Codigo de puesto       : " << empleado.codigo_puesto << endl;
        cout << "\t\t\t Codigo de departamento : " << empleado.codigo_departamento << endl;
        cout << "\t\t\t Sueldo del empleado    : Q" << empleado.sueldo_empleado << endl;
        cout << "\t\t\t Status del empleado    : " << empleado.status_empleado << endl;
        cout << "-----------------------------------------------------------------------------------------------------------------" << endl;
        total++;
    }

    if (total == 0) {
        cout << "\n\t\t\tNo hay informacion..." << endl;
    }

    file.close();
    cin.ignore();
    system("pause");
}


void empleado::modificar() {
    system("cls");
    fstream file("empleados.dat", ios::in | ios::out | ios::binary);


    if (!file) {
        cout << "\n\t\t\tNo hay información...";
        return;
    }

    string id_modificar;
    int found = 0;

    cout << "\n-------------------------------------Modificar Detalles de empleado----------------------------------------------" << endl;
    cout << "\t\t\tIngrese codigo del empleado que desea modificar: ";
    cin >> id_modificar;

    Empleado empleado;
    ofstream file1("temporal.dat", ios::binary);


    if (!file1) {
        cout << "\n\t\t\tError al abrir el archivo temporal...";
        return;
    }


    while (file.read(reinterpret_cast<char*>(&empleado), sizeof(Empleado))) {
        if (strcmp(empleado.codigo_empleado, id_modificar.c_str()) == 0) {
            cout << "\t\t\tIngrese nuevo codigo del empleado: ";
            cin >> empleado.codigo_empleado;
            cout << "\t\t\tIngrese nuevo nombre del empleado: ";
            cin.ignore();
            cin.getline(empleado.nombre_empleado, sizeof(empleado.nombre_empleado));
            cout << "\t\t\tIngrese nuevo codigo de puesto: ";
            cin.getline(empleado.codigo_puesto, sizeof(empleado.codigo_puesto));
            cout << "\t\t\tIngrese nuevo codigo de departamento: ";
            cin.getline(empleado.codigo_departamento, sizeof(empleado.codigo_departamento));
            cout << "\t\t\tIngrese el nuevo sueldo del empleado: ";
            cin.getline(empleado.sueldo_empleado, sizeof(empleado.sueldo_empleado));
            cout << "\t\t\tIngrese el nuevo status del empleado (solvente=1 | pendiente=0): ";
            cin.getline(empleado.status_empleado, sizeof(empleado.status_empleado));

            file1.write(reinterpret_cast<const char*>(&empleado), sizeof(Empleado));

            cout << "\n\t\t\tEmpleado modificado correctamente!!!" << endl;
            found++;
        } else {
            file1.write(reinterpret_cast<const char*>(&empleado), sizeof(Empleado));
        }
    }

    if (!found) {
        cout << "\n\t\t\tNo se encontro el empleado con el codigo proporcionado." << endl;
    }

    file.close();
    file1.close();
    remove("empleados.dat");
    rename("temporal.dat", "empleados.dat");
    cin.ignore();
    system("pause");
}


void empleado::borrar() {
    system("cls");
    string id_borrar;
    int found = 0;

    cout << "\n------------------------------------------Detalles del empleado a Borrar-----------------------------------------------" << endl;

    ifstream file("empleados.dat", ios::binary);


    if (!file) {
        cout << "\n\t\t\tNo hay informacion...";
        return;
    }

    ofstream file1("temporal.dat", ios::binary);


    if (!file1) {
        cout << "\n\t\t\tError al abrir el archivo temporal...";
        return;
    }

    cout << "\n-----------------------------------------Sistema Busqueda de empleados---------------------------------------------" << endl;
    cout << "\n\t\t Ingrese el codigo del empleado que quiere Borrar: ";
    cin >> id_borrar;

    Empleado empleado;
    while (file.read(reinterpret_cast<char*>(&empleado), sizeof(Empleado))) {
        if (strcmp(empleado.codigo_empleado, id_borrar.c_str()) == 0) {
            cout << "\n\t\t\tBorrado de informacion exitoso!!!!" << "\n" << endl;
            found++;
        } else {
            file1.write(reinterpret_cast<const char*>(&empleado), sizeof(Empleado));
        }
    }

    if (found == 0) {
        cout << "\n\t\t\t Codigo del empleado no encontrado...." << "\n" << endl;
    }

    file1.close();
    file.close();

    remove("empleados.dat");
    rename("temporal.dat", "empleados.dat");

    cin.ignore();
    system("pause");
}
