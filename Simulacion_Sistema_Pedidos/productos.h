#ifndef PRODUCTOS_H_INCLUDED
#define PRODUCTOS_H_INCLUDED

#include <iostream>
#include <cstring>

using namespace std;

void cargarProductos(char *palabra, int tamano){

    int i=0;

    fflush(stdin);

    for (i=0; i<tamano; i++){

        palabra[i]=cin.get();

        if (palabra[i]=='\n'){

            break;

        }

    }

    palabra[i]='\0';

    fflush(stdin);

}

class Productos{
private:
    int precio, codigo;
    char nombre[40];
    bool estado = true;

public:

    void Cargar(int cod);
    void Mostrar();
    void Modificar();

    void setPrecio(int x){precio = x;}
    void setCodigo(int x){codigo = x;}
    void setNombre(const char *n){strcpy(nombre, n);}
    void setEstado(bool e){estado = e;}

    int getPrecio(){return precio;}
    int getCodigo(){return codigo;}
    const char *getNombre(){return nombre;}
    bool getEstado(){return estado;}
};
void Productos::Cargar(int cod){
    int x;
    char n[40];
    setCodigo(cod);
    cout << "NOMBRE: ";
    cargarProductos(n, 39);
    setNombre(n);
    do{
        cout << "PRECIO: ";
        cin >> x;
    }while(x <= 0);
    setPrecio(x);
}
void Productos::Mostrar(){
    if(getEstado()){
        cout << getNombre() << endl;
        cout << "PRECIO: " << getPrecio() << endl;
    }
}
void Productos::Modificar(){
    int x;
    char n[40];
    cout << "NOMBRE: ";
    cargarProductos(n, 39);
    setNombre(n);
    cout << "PRECIO: ";
    cin >> x;
    setPrecio(x);
}
#endif // PRODUCTOS_H_INCLUDED
