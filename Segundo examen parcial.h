#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
void segundoexamen();

using namespace std;

void segundoexamen()
{
	int monedas = 10;
	int precio = 25;
	int decision;
	int decision2;
	int espacios;
	vector <string> inventory(0);
	inventory.push_back("Barco");
	inventory.push_back("Ballesta");
	inventory.push_back("Remo");

	cout << "Bienvenido a Whale territory." << endl << endl;;
	cout << "La cantidad de monedas que tienes son: " << monedas << endl;
	cout << "Tienes " << inventory.size() << " items en tu inventario." << endl;
	inventory.reserve(5);
	cout << "La capacidad total de tu inventario es de: " << inventory.capacity() << endl;

	cout << "Tus objetos son: " << endl;
	for (unsigned int i = 0; i < inventory.size(); i++)
	{
		cout << inventory[i] << endl;
	}

	cout << "Desea recojer los objetos tirados?" << endl << "1- Si" << endl << "2- No" << endl;
	cin >> decision;
	cout << endl;
	if (decision == 1)
	{
		inventory.push_back("Lancha");
		inventory.push_back("Red");

		if (inventory.size() > 3)
		{
			cout << "No hay suficiente espacio en tu inventario, Que desea hacer?" << endl;
			cout << "1- Reemplazar objeto." << endl << "2- Continuar sin el objeto recogido." << endl << "3- Añadir un espacio por costo de monedas." << endl;
			cin >> decision2;
			cout << endl;
			if (decision2 == 1)
			{
				int cambio;
				cout << "Cual item desea cambiar?" << endl << "1- Barco" << endl << "2- Ballesta" << endl << "3- Remo" << endl;
				cin >> cambio;
				cout << endl;
				switch (cambio)
				{
				case 1:
					cout << "Cambiaste tu " << inventory[0] << " por un Cañon.";
					inventory[0] = "Cañon";
					cout << endl;
					inventory.pop_back();
					inventory.pop_back();
					for (unsigned int i = 0; i < inventory.size(); i++)
					{
						cout << inventory[i] << endl;
					}
					cout << "La cantidad de monedas que tienes son: " << monedas << endl;
					break;
				case 2:
					cout << "Cambiaste tu " << inventory[1] << " por un Cañon.";
					inventory[1] = "Cañon";
					cout << endl;
					inventory.pop_back();
					inventory.pop_back();
					for (unsigned int i = 0; i < inventory.size(); i++)
					{
						cout << inventory[i] << endl;
					}
					cout << "La cantidad de monedas que tienes son: " << monedas << endl;
					break;
				case 3:
					cout << "Cambiaste tu " << inventory[2] << " por un Cañon.";
					inventory[2] = "Cañon";
					cout << endl;
					inventory.pop_back();
					inventory.pop_back();
					for (unsigned int i = 0; i < inventory.size(); i++)
					{
						cout << inventory[i] << endl;
					}
					cout << "La cantidad de monedas que tienes son: " << monedas << endl;
					break;
				default:
					cout << "Escoja algun item para cambiar" << endl;
					break;
				}
			}
			else if (decision2 == 2)
			{
				cout << "Usted eligio continuar sin recoger objetos" << endl;
				exit(EXIT_SUCCESS);
			}
			else if (decision2 == 3)
			{
				cout << "Cuantos espacios desea adquirir?" << endl << "1- Uno" << endl << "2- Dos" << endl;
				cin >> espacios;
				cout << endl;
				if (espacios == 1)
				{
					int saldo;
					saldo = monedas - precio;
					inventory.pop_back();
					for (unsigned int i = 0; i < inventory.size(); i++)
					{
						cout << inventory[i] << endl;
					}
					cout << "La cantidad de monedas que tienes son: " << saldo << endl;
				}
				else if (espacios == 2)
				{
					int saldo;
					saldo = monedas - (2 * (precio));
					for (unsigned int i = 0; i < inventory.size(); i++)
					{
						cout << inventory[i] << endl;
					}
					cout << "La cantidad de monedas que tienes son: " << saldo << endl;
				}
				else
				{
					cout << "Solo existen disponibles cinco espacios" << endl;
				}
			}
			else
			{
				cout << "Elija una opcion de las mostradas." << endl;
			}
		}
	}
	else if (decision == 2)
	{
		cout << "Usted eligio que no quiere recoger los objetos" << endl;
		exit(EXIT_SUCCESS);
	}
	else
	{
		cout << "Elija una opcion de las mostradas." << endl;
	}
}