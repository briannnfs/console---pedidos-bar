#ifndef MODOADMINISTRADOR_H_INCLUDED
#define MODOADMINISTRADOR_H_INCLUDED

#include <iostream>
#include "manejoArchivos.h"

using namespace std;

int ModoAdministrador(){
    int cont = 0, pass;
    manejoArchivos arch1;

    do{
       cout << "INGRESE LA CONTRASEÑA: ";
       cin >> pass;
       cont++;
    }while(pass != 1234 && cont < 3);
    if(cont == 3){return cont;}

    int opcion_administrador;

    cout << "CONTRASEÑA CORRECTA" << endl;

    do{
        system("pause");
        system("cls");
        cout << "\n---------------- MENU ADMINISTRADOR ----------------" << endl;
        cout << "\n1.- CARGAR PRODUCTOS" << endl;
        cout << "2.- MOSTRAR PRODUCTOS" << endl;
        cout << "3.- EDITAR PRODUCTOS" << endl;
        cout << "4.- BORRAR PRODUCTOS" << endl;
        cout << "\n0.- SALIR" << endl;
        cin >> opcion_administrador;

        switch(opcion_administrador){

            case 1:
                system("cls");
                arch1.altaRegistro();
                break;

            case 2:
                system("cls");
                arch1.mostrarRegistros();
                break;

            case 3:
                system("cls");
                arch1.modificarRegistro();
                break;

            case 4:
                system("cls");
                arch1.bajaLogica();
                break;

            case 0:
                return 0;
                break;
        }

    }while(true);
}


#endif // MODOADMINISTRADOR_H_INCLUDED
