#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<cstdlib>
#include<conio.h>
#include<iomanip>
#include "Login.h"
#include "Bitacora.h"

using namespace std;

Login::Login(string usuario, string contrasena)
{
    this -> usuarios=usuarios;
    this -> contrasena=contrasena;
}

string Login::setUser(string usuarios)
{
    this -> usuarios=usuarios;
}

string Login::getUser()
{
    return this->usuarios;
}

string Login::setContrasena(string contrasena)
{
    this -> contrasena=contrasena;
}

string Login::getContrasena()
{
    return this->contrasena;
}


bool Login::VerificarUsuario()
{
    string usuario,contrasena;
    int contador= 0;
    bool encontrado =false;

    while(contador<3 && !encontrado)
    {
         system("cls");
    cout <<"\t\t\t+-----------------------------------+"<<endl;
    cout <<"\t\t\t|       LOGIN                       |"<<endl;
    cout <<"\t\t\t+-----------------------------------+"<<endl;
    cout <<"\t\t\t|Solo tienes permitido 3 intentos   |"<<endl;
    cout <<"\t\t\t+-----------------------------------+"<<endl;
    cout <<"\t\t\tIngrese el nombre de usuario: ";
    cin >> usuario;
    cout <<"\t\t\tIngrese la contrasena: ";
    char caracter;
    caracter = getch();


    contrasena="";
        while (caracter!=13)
        {
        if(caracter !=8)
            {
                contrasena.push_back(caracter);
                cout<<"*";
            }
        else
            {
                if(contrasena.length()>0)
                {
                    cout<<"\b \b";
                    contrasena=contrasena.substr(0,contrasena.length()-1);
                }
            }
            caracter=getch();
        }


    ifstream fileU;
    fileU.open("usuarios.txt",ios::in);



    if (!fileU)
    {
        cout<<"\n\t\t\t No es posible abrir el archivo."<<endl;
        fileU.close();
        return false;
    }
    string codigoPrograma="1000";
    Bitacora Auditoria;


    string user,pass;
    while (fileU>>user>>pass)
    {
        if (user==usuario && pass==contrasena)
        {
            Auditoria.ingresoBitacora(user,codigoPrograma,"LGI");
            encontrado=true;
            break;
        }
    }
     fileU.close();


    if(!encontrado)
    {
        cout << "\n\n\t\t\tUSUARIO Y/O CONTRASEÑA INCORRECTOS" << endl;
        cout << "\n\n\t\t\tPerdio un intento, Intente de nuevo\n" << endl;
        contador++;
        system("pause");
    }
}


   if (encontrado)
    {
    	         system("cls");

    cout << "\n\t----- Bienvenido " << usuario << " -----" << endl;
     system("pause");
    return true;
    }
   else
    {
	system("cls");
    cout << "\n\n\t\t\tPERDIO LOS 3 INTENTOS" << endl;
     system("pause");
     exit(0);

    return false;
    }
}
