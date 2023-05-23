#include <iostream>
void primerexamen();
void menu();
void jugar();
void jugarnuev();
void salir();

using namespace std;

void primerexamen()
{
    menu();
}

void menu()
{
    int eleccmen;
    do
    {
        cout << "Bienvenido al menu." << endl;
        cout << "Tiene dos opciones para elegir." << endl;
        cout << "1- Jugar." << endl;
        cout << "2- Salir." << endl;
        cin >> eleccmen;
        switch (eleccmen)
        {
        case 1:
            jugar();
            jugarnuev();
            break;
        case 2:
            salir();
            break;
        default:
            cout << "Elija alguna de las dos opciones" << endl;
            break;
        }
    } while (eleccmen > 0 || eleccmen < 1);
}
void jugar()
{
    int nummin, nummay;
    cout << "Ingrese el rango minimo del numero" << endl;
    cin >> nummin;
    cout << "Ingrese el rango maximo del numero" << endl;
    cin >> nummay;
    srand(static_cast <unsigned int> (time(0)));
    int numalea = rand();
    int num = numalea % (nummay - nummin + 1) + (nummin);
    //
    int elecc;
    int mov{};
    cout << num << endl;
    cout << "Bienvenido a Guess my number" << endl << endl << "Se va a generar un numero aleatorio, el cual debe adivinar para ganar" << endl;
    do
    {
        cin >> elecc;
        mov++;
        if (elecc == num)
            cout << "Felicidades, ganaste! Tu numero de intentos fue: " << mov << endl;
        else if (elecc > num)
        {
            if (elecc > num && elecc <= num + 3)
                cout << "Es un numero menor, pero estas cerca" << endl;
            else if (elecc > num && elecc > num + 3)
                cout << "Es un numero menor, aunque estas lejos" << endl;
        }
        else
        {
            if (elecc < num && elecc >= num - 3)
                cout << "Es un numero mayor, pero estas cerca" << endl;
            else if (elecc < num && elecc < num - 3)
                cout << "Es un numero mayor, aunque estas lejos" << endl;
        }
    } while (elecc != num);
}
void jugarnuev()
{
    int jugar2;
    cout << "Quiere jugar de nuevo?" << endl << "1- Si" << endl;
    cout << "2- No" << endl;
    cin >> jugar2;
    if (jugar2 == 1)
    {
        system("cls");
        jugar();
    }
    else if (jugar2 == 2)
    {
        system("cls");
        menu();
    }
    else
    {
        cout << "Elija alguna de las dos opciones" << endl;
    }
}
void salir()
{
    int sal;
    cout << "Realmente quieres salir?" << endl;
    cout << "1- Si" << endl << "2- No" << endl;
    cin >> sal;
    if (sal == 1)
    {
        exit(EXIT_SUCCESS);
    }
    else if (sal == 2)
    {
        menu();
    }
    else
    {
        cout << "Elija alguna de las dos opciones" << endl;
    }
}