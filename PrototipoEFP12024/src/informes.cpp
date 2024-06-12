
#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<cstdlib>
#include<iomanip>
#include <sstream>
#include <cstring>
#include "informes.h"
#include "empleado.h"
#include"Bitacora.h"

using namespace std;

struct Informes{
    string imp_codigo;
    string imp_nombre;
    string imp_puesto;
    string imp_departamento;
    string imp_sueldo;
    string imp_status;
};


void informes::imprimirArchivo() {

    string codigoPrograma = "1200";
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

    system("cls");
    Informes informes;
    ofstream file("impresion.txt", ios::out);

    if (!file) {
        cerr << "No se pudo abrir el archivo 'impresion.txt'." << endl;
        return;
    } else {
        Empleado empleado;

        ifstream fileEmp("empleados.dat", ios::binary);
        if (!fileEmp.is_open()) {
            cerr << "Error: No se pudo abrir el archivo 'empleados.dat'." << endl;
            return;
        }
        else
        {
            cout << "\n\t\t\tLa informacion del empleado se ha impreso exitosamente." << endl;
            system("pause");
            Auditoria.ingresoBitacora(user,codigoPrograma,"IMP");

            file <<"-----------------------------------------Tabla Detalles de empleados ----------------------------------------------" << endl;
            while (fileEmp.read(reinterpret_cast<char*>(&empleado), sizeof(Empleado))){
                file << "\t\t\t Codigo de empleado     : " << empleado.codigo_empleado << endl;
                file << "\t\t\t Nombre de empleado     : " << empleado.nombre_empleado << endl;
                file << "\t\t\t Codigo de puesto       : " << empleado.codigo_puesto << endl;
                file << "\t\t\t Codigo de departamento : " << empleado.codigo_departamento << endl;
                file << "\t\t\t Sueldo del empleado    : Q" << empleado.sueldo_empleado << endl;
                file << "\t\t\t Status del empleado    : " << empleado.status_empleado << endl;
                file << "-----------------------------------------------------------------------------------------------------------------" << endl;
                }
        fileEmp.close();
        file.close();
        }
    }
}
