#include <iostream>
#include "Arbol/ArbolBinarioAVL.h"
using namespace std;


void menu(){
    cout << "1. Insertar un codigo de producto" << endl;
    cout << "2. Eliminar un codigo de producto" << endl;
    cout << "3. Buscar un codigo de producto" << endl;
    cout << "4. Imprimir el arbol" << endl;
    cout << "5. Salir" << endl;
    cout << "Ingrese una opcion: ";

}



int main() {

    ArbolBinarioAVL<int> productos;
    int opc, codigo;

    do
    {
        menu();
        cin >> opc;
        switch (opc)
        {
        case 1:
            cout << "Ingrese el codigo del producto: ";
            cin >> codigo;
            productos.put(codigo);
            try
            {
                productos.put(codigo);
                cout<<"Producto con codigo "<<codigo<<" insertado correctamente"<<endl;
            }
            catch(int e)
            {
                if(e==404){
                    cout<<"Error: el codigo es invalido"<<endl;
                }
            }
            break;
        case 2:
            cout << "Ingrese el codigo del producto a eliminar: ";
            cin >> codigo;
            try
            {
                productos.remove(codigo);
                cout<<"Producto con codigo "<<codigo<<" eliminado correctamente"<<endl;
            }
            catch(int e)
            {
                cout<<"Error: el codigo no existe o es invalido"<<endl;
            }
            break;
        case 3:
            cout << "Ingrese el codigo del producto a buscar: ";
            cin >> codigo;
            try
            {
                int encontrado=productos.search(codigo);
                cout<<"Producto con codigo "<<codigo<<" encontrado"<<endl;
            }
            catch(int e)
            {
                cout<<"Error: el codigo no existe o es invalido"<<endl;
            }
            break;
        case 4:
            cout<<"Arbol de productos: "<<endl;
            productos.print();
            break;
        case 5:
            cout << "Saliendo..." << endl;
            break;
        default:
            cout << "Opcion invalida" << endl;
            break;
        }

    } while (opc != 5);
    
}
