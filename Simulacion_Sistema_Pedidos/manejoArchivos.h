#ifndef MANEJOARCHIVOS_H_INCLUDED
#define MANEJOARCHIVOS_H_INCLUDED

#include <iostream>
#include <cstring>
#include "productos.h"

class manejoArchivos{
private:
    char nombre[14] = "productos.dat";

public:
    int buscarRegistro(int cod);
    Productos devolverRegistro(int pos);
    int reemplazarRegistro(int pos, Productos reg);
    int modificarRegistro();
    int bajaLogica();
    int altaRegistro();
    void mostrarRegistros();
    int validacionCodigo(int cod);

};
int manejoArchivos::altaRegistro(){
    FILE *p;
    Productos reg;
    int codigo, opcion_productos;
    do{
        p=fopen("productos.dat", "ab");
        if(p==nullptr){
        cout << "ERROR DE ARCHIVO" << endl;
        return -1;
        }
        system("cls");
        cout << "CODIGO: ";
        cin >> codigo;
        validacionCodigo(codigo);
        if(validacionCodigo(codigo) == -1){
            exit(0);
        }
        else if(validacionCodigo(codigo) == 1){
            cout << "EL CODIGO INGRESADO YA EXISTE" << endl;
            return 3;
        }
        reg.Cargar(codigo);
        int escribio = fwrite(&reg, sizeof reg, 1, p);

        if(escribio == 1){cout << "REGISTRO INGRESADO CORRECTAMENTE" << endl;}
        system("pause");
        system("cls");
        do{
            cout << "¿DESEA AGREGAR OTRO REGISTRO?" << endl;
            cout << "1.- SI" << endl;
            cout << "2.- NO" << endl;
            cin >> opcion_productos;
        }while(opcion_productos < 1 || opcion_productos > 2);
        fclose(p);
    }while(opcion_productos != 2);
    fclose(p);
    return 0;
}
void manejoArchivos::mostrarRegistros(){
    FILE *p;
    Productos reg;
    p=fopen("productos.dat", "rb");
    while(fread(&reg, sizeof reg, 1, p) == 1){
        reg.Mostrar();
    }
}
int manejoArchivos::buscarRegistro(int cod){
    FILE *p;
    Productos reg;
    int pos = 0;
    p=fopen("productos.dat", "rb");
    if(p==NULL){
        cout << "ERROR DE ARCHIVO" << endl;
        return -1;
    }
    while(fread(&reg, sizeof reg, 1, p) == 1){
        if(reg.getCodigo() == cod){
            fclose(p);
            return pos;
        }
        pos++;
    }
    fclose(p);
    return -2;
}
int manejoArchivos::reemplazarRegistro(int pos, Productos reg){
    FILE *p;
    p=fopen("productos.dat", "rb+");
    if(p==NULL){
        return -1;
    }
    fseek(p, sizeof reg*pos, 0);
    bool escribio=fwrite(&reg, sizeof reg, 1, p);
    if(escribio){
        fclose(p);
        return 0;
    }
    fclose(p);
    return -2;
}
Productos manejoArchivos::devolverRegistro(int pos){
    FILE *p;
    Productos reg;
    p=fopen("productos.dat", "rb");
    if(p==NULL){
        reg.setPrecio(-1);
        return reg;
    }
    fseek(p, sizeof reg*pos, 0);
    bool leyo = fread(&reg, sizeof reg, 1, p);
    if(leyo){
        fclose(p);
        return reg;
    }
    reg.setPrecio(-2);
    fclose(p);
    return reg;
}
int manejoArchivos::modificarRegistro(){
    Productos reg;
    int posicion, opcion, resultado, codigo;
    cout << "INGRESE EL CODIGO DEL REGISTRO A MODIFICAR: ";
    cin >> codigo;
    posicion = buscarRegistro(codigo);
    if(posicion == -1){
        cout << "ERROR DE ARCHIVO" << endl;
        return -1;
    }
    else if(posicion == -2){
        cout << "NO EXISTE REGISTRO CON EL CODIGO INGRESADO" << endl;
        return -2;
    }
    reg = devolverRegistro(posicion);
    if(reg.getPrecio() == -1){
        cout << "ERROR DE ARCHIVO" << endl;
        return -1;
    }
    else if(reg.getPrecio() == -2){
        cout << "NO SE PUDO GRABAR EL REGISTRO" << endl;
        return -2;
    }
    system("cls");
    reg.Mostrar();
    do{
        cout << "\n¿DESEA MODIFICAR ESTE REGISTRO?" << endl;
        cout << "1.- SI" << endl;
        cout << "2.- NO" << endl;
        cin >> opcion;
    }while(opcion < 1 || opcion > 2);
    if(opcion == 2){
        return -3;
    }
    system("cls");
    do{
        cout << "¿DESEA MODIFICAR TAMBIEN EL CODIGO DEL REGISTRO?" << endl;
        cout << "1.- SI" <<endl;
        cout << "2.- NO" << endl;
        cin >> opcion;
    }while(opcion < 1 || opcion > 2);
    if(opcion == 1){
        system("cls");
        cout << "CODIGO: ";
        cin >> codigo;
        resultado = validacionCodigo(codigo);
        if(resultado == -1){
            cout << "\nERROR DE ARCHIVO" << endl;
            return -1;
        }
        else if(resultado == 1){
            cout << "\nYA EXISTE UN REGISTRO CON ESE CODIGO" << endl;
            return 1;
        }
        else{
            reg.Cargar(codigo);
            resultado = reemplazarRegistro(posicion, reg);
            system("cls");
            if(resultado == -1){
                cout << "ERROR DE ARCHIVO" << endl;
                return -1;
            }
            else if(resultado == -2){
                cout << "NO SE PUDO MODIFICAR EL REGISTRO" << endl;
                return -2;
            }
            else{
                cout << "REGISTRO MODIFICADO CON EXITO" << endl;
                return 0;
            }
        }
    }
    reg.Modificar();
    resultado = reemplazarRegistro(posicion, reg);
    if(resultado == -1){
        cout << "ERROR DE ARCHIVO" << endl;
        return -1;
    }
    else if(resultado == -2){
        cout << "NO SE PUDO MODIFICAR EL REGISTRO" << endl;
        return -2;
    }
    else{
        cout << "REGISTRO MODIFICADO CON EXITO" << endl;
        return 0;
    }
}
int manejoArchivos::bajaLogica(){
    int cod, pos, opcion, resultado;
    Productos reg;
    cout << "INGRESE EL CODIGO DEL REGISTRO A BORRAR: ";
    cin >> cod;
    pos = buscarRegistro(cod);
    if(pos == -1){
        cout << "ERROR DE ARCHIVO" << endl;
        return -1;
    }
    else if(pos == -2){
        cout << "NO EXISTE REGISTRO CON EL CODIGO INGRESADO" << endl;
        return -2;
    }
    reg = devolverRegistro(pos);
    if(reg.getPrecio() == -1){
        cout << "ERROR DE ARCHIVO" << endl;
        return -3;
    }
    else if(reg.getPrecio() == -2){
        cout << "NO SE PUDO RECUPERAR EL REGISTRO" << endl;
    }
    system("cls");
    reg.Mostrar();
    do{
        cout << "\n¿DESEA ELIMINAR ESTE REGISTRO?" << endl;
        cout << "1.- SI" << endl;
        cout << "2.- NO" << endl;
        cin >> opcion;
    }while(opcion < 1 || opcion > 2);
    if(opcion == 2){
        return 1;
    }
    reg.setEstado(false);
    resultado = reemplazarRegistro(pos, reg);
    if(resultado == -1){
        cout << "ERROR DE ARCHIVO" << endl;
        return -4;
    }
    else if(resultado == -2){
        cout << "NO SE PUDO MODIFICAR EL REGISTRO" << endl;
        return -5;
    }
    cout << "SE HA ELIMINADO EL REGISTRO CON EXITO" << endl;
    return 0;
}
int manejoArchivos::validacionCodigo(int cod){
    FILE *p;
    Productos reg;
    p=fopen("productos.dat", "rb");
    if(p==NULL){
        cout << "ERROR DE ARCHIVO" << endl;
        return -1;
    }
    while(fread(&reg, sizeof reg, 1, p) == 1){
        if(reg.getCodigo() == cod && reg.getEstado() == true){
            fclose(p);
            return 1;
        }
    }
    fclose(p);
    return 0;
}
#endif // MANEJOARCHIVOS_H_INCLUDED
