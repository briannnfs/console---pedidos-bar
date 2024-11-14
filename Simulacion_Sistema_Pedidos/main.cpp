#include <iostream>
#include "modoPedidos.h"

using namespace std;

int main()
{
    int opcion_principal;
    do{
        system("cls");
        cout << "--------------- MENU PRINCIPAL ---------------" << endl;
        cout << "\nSELECCIONE EL METODO DE INGRESO" << endl;
        cout << "1.- MODO ADMINISTRADOR" << endl;
        cout << "2.- MODO PEDIDOS" << endl;
        cout << "0.- SALIR DEL SISTEMA" << endl;
        cout << endl;
        cin >> opcion_principal;

        switch(opcion_principal){
            case 1:
                system("cls");
                if(ModoAdministrador() == 3){
                    cout << "SE HA ALCANZADO EL LIMITE DE INTENTOS PARA LA CONTRASEÑA" << endl;
                }
                return 0;
                break;

            /*case 2:
                ModoPedidos();
                break;*/

            case 0:
                return 0;
                break;

            default:
                cout << "INGRESE UNA OPCION CORRECTA" << endl;
                system("pause");
                break;
        }

    }while(true);
    return 0;
}
