#include <iostream>
#include "Arbol/ArbolBinarioAVL.h"
using namespace std;

void menu(){
    cout<<"1. Agregar producto: inserta un nuevo codigo de producto en el sistema. "<<endl;
    cout<<"2. Eliminar producto: elimina un codigo de producto del sistema. "<<endl;
    cout<<"3. Buscar producto: verifica si un codigo de producto existe en el inventario. "<<endl;
    cout<<"4. Mostrar inventario: imprime el arbol AVL de productos para mostrar su estrcutra balanceada. "<<endl;
    cout<<"5. Mostrar el numero de balance del arbol. "<<endl;
    cout<<"6. Salir. "<<endl;
}

int main() {

    ArbolBinarioAVL<int> productos;
    int opc, codigo;

    do
    {
        menu();
        cin>>opc;
        switch (opc)
        {
        case 1:
            cout<<"Ingrese el codigo del producto: ";
            cin>>codigo;
            try
            {
                productos.put(codigo);
                cout<<"Producto con codigo "<<codigo<<" insertado correctamente"<<endl;
            }
            catch(int e)
            {
                if(e==200){
                    cout<<"Error: el codigo del producto ya existe en el inventario."<<endl;
                }
            }
            break;
        case 2:
            cout<<"Ingrese el codigo del producto: ";
            cin>>codigo;
            try
            {
                productos.remove(codigo);
                cout<<"Producto con codigo "<<codigo<<" eliminado correctamente"<<endl;
            }
            catch(int e)
            {
                if(e==404){
                    cout<<"Error: el codigo del producto no existe en el inventario."<<endl;
                }
            }
            break;
        case 3:
            cout<<"Ingrese el codigo del producto a buscar: ";
            cin>>codigo;
            try
            {
                int encontrado=productos.search(codigo);
                cout<<"Producto con codigo "<<codigo<<" encontrado en el inventario"<<endl;
            }
            catch(int e)
            {
                if(e==404){
                    cout<<"Error: el codigo del producto no existe en el inventario."<<endl;
                }
            }
            break;
        case 4:
            cout<<"Inventario: "<<endl;
            productos.print();
            break;
        case 5:
            cout<<"Numero de balance del arbol: "<<productos.getBalance()<<endl;
            break;
        case 6:
            cout<<"Fin del programa"<<endl;
            break;
            
        default:
            cout<<"Opcion invalida. Intente nuevamente."<<endl;
            break;
        }
    } while (opc!=6);
    
}
