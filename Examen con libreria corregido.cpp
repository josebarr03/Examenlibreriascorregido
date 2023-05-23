#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "D:\Trabajos\Examen con libreria corregido\Primer examen parcial.h"
#include "D:\Trabajos\Examen con libreria corregido\Segundo examen parcial.h"
#include "D:\Trabajos\Examen con libreria corregido\Tercer examen parcial.h"
#include "D:\Trabajos\Examen con libreria corregido\Cuarto examen parcial.h"

using namespace std;

void ciclo();//Ciclo eleccion de examen

int main()
{
    ciclo();
}

void ciclo()
{
    int eleccmen;
    do // ciclo para repetir el menu hasta elegir la opcion salir
    {
        cout << endl << "Bienvenido al menu de examenes." << endl;
        cout << "Tiene cuatro opciones para elegir." << endl;
        cout << "1- Primer parcial." << endl;
        cout << "2- Segundo parcial." << endl;
        cout << "3- Tercer parcial." << endl;
        cout << "4- Cuarto parcial." << endl;
        cout << "5- Salir." << endl;
        cin >> eleccmen;
        cout << endl;
        switch (eleccmen) // switch para casos dependiendo de la opcion elegida
        {
        case 1:
            primerexamen();
            break;
        case 2:
            segundoexamen();
            break;
        case 3:
            tercerexamen();
            break;
        case 4:
            cuartoexamen();
            break;
        case 5:
            exit(EXIT_SUCCESS);
        default:
            cout << "Opcion elegida no valida, seleccione otra opcion" << endl;
            break;
        }
    } while (eleccmen > 0 || eleccmen < 4);
}