#include <iostream>
#include "AgenteArchivo.h"
#include "MultaArchivo.h"
#include "Parcial.h"
using namespace std;

int main()
{

    Parcial m;
    int selec;
    do
    {
        cout<<"Ingrese 1 para punto 1 parcial"<<endl;
        cout<<"Ingrese 2 para punto 2 parcial"<<endl;
        cout<<"Ingrese 3 para punto 3 parcial"<<endl;
        cout<<"Ingrese 4 para punto 4 parcial"<<endl;
        cout<<"Ingrese 0 para para salir"<<endl;
        cin>>selec;

        switch(selec)
        {
        case 1:
                m.Punto1();

            break;
        case 2:

             m.Punto2();
            break;
        case 3:
             m.Punto3();
            break;
             case 4:

            break;
        default:
             cout<<"Parametro incorrecto"<<endl;
            break;
        }










    }
    while(selec=!0);





    return 0;
}
