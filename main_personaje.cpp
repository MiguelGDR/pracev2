#include <string>
#include <iostream>
#include "Personaje.hpp"

using namespace std;
using namespace bblProgIIB;

char menu()
{
    system("cls"),
        cout << "CREACION DE PERSONAJE" << endl;
    cout << "0.- Fin" << endl;
    cout << "1.- Crear personaje" << endl;
    cout << "2.- Eliminar personaje" << endl;
    cout << "3.- Consultar atributos de personaje" << endl;
    cout << "4.- Crear bolsa de personaje." << endl;
    cout << "5.- Insertar elemento en bolsa de personaje" << endl;
    cout << "6.- Eliminar elemento de bolsa de personaje" << endl;
    cout << "7.- Consultar bolsa de personaje." << endl;
    cout << "8.- Consultar el numero de elementos de la lista" << endl;
    cout << "9.- Copiar bolsa de personaje (constructor de copia)" << endl;

    char op;
    do
    {
        cout << " Opcion ? ";
        cin >> op;
    } while (op < '0' || op > '9');

    cout << endl;
    return op;
}

int main()
{
    char op;
    Personaje pers;

    while ((op = menu()) != '0')
    {
        switch (op)
        {
        case '1':
        {
            system("cls");
            // Nombre
            cout << "Nombre del personaje: ";
            string nombre;
            cin >> nombre;
            pers.asignarNombre(nombre);
            system("cls");
            // Raza
            cout << "Raza del personaje (Elfo, Enano, Hobbit, Humano u Orco): ";
            string raza;
            cin >> raza;
            pers.asignarRaza(raza);
            system("cls");
            // Caracter / Rol
            cout << "Caracter | Rol (Caballero, Arquero, Mago, Asesino): ";
            string caracter;
            cin >> caracter;
            pers.asignarCaracter(caracter);
            system("cls");
            // Genero
            cout << "Genero (Masculino - M | Femenino - F): ";
            char gen;
            cin >> gen;
            pers.asignarSexo(gen);
            system("cls");

            // Pts de vida, fuerza, destreza y magia
            if (caracter == "Caballero" || caracter == "caballero")
            {
                pers.asignarPvida(200);
                pers.asignarPfuerza(100);
                pers.asignarPdestreza(50);
                pers.asignarPmagia(0);
            }
            else if (caracter == "Arquero" || caracter == "arquero")
            {
                pers.asignarPvida(100);
                pers.asignarPfuerza(50);
                pers.asignarPdestreza(100);
                pers.asignarPmagia(0);
            }
            else if (caracter == "Mago" || caracter == "mago")
            {
                pers.asignarPvida(80);
                pers.asignarPfuerza(50);
                pers.asignarPdestreza(0);
                pers.asignarPmagia(150);
            }
            else if (caracter == "Asesino" || caracter == "asesino")
            {
                pers.asignarPvida(125);
                pers.asignarPfuerza(75);
                pers.asignarPdestreza(150);
                pers.asignarPmagia(0);
            }
            system("cls");

            pers.asignarOro(1000);
            pers.crearBolsa();
            break;
        }

        case '2':
        {
            system("cls");
            cout << "Estas seguro de querer eliminar al personaje? [y/n]: ";
            char y;
            cin >> y;
            if (y == 'y')
            {
                pers.~Personaje();
                system("pause");
            }
            break;
        }

        case '3':
        {
            system("cls");
            cout << "Nombre: " << pers.mostrarNombre() << endl;
            cout << "Raza: " << pers.mostrarRaza() << endl;
            cout << "Caracter | Rol: " << pers.mostrarCaracter() << endl;
            cout << "Genero: " << pers.mostrarSexo() << endl;
            cout << endl;
            cout << "Puntos: " << endl;
            cout << "Vida: " << pers.mostrarPvida() << endl;
            cout << "Fuerza: " << pers.mostrarPfuerza() << endl;
            cout << "Destreza: " << pers.mostrarPdestreza() << endl;
            cout << "Magia: " << pers.mostrarPmagia() << endl;
            cout << endl;
            cout << "Oro: " << pers.mostrarOro() << endl;
            cout << endl;
            system("pause");
            break;
        }

        case '4':
        {
            system("cls");
            pers.crearBolsa();
            cout << "Bolsa creada." << endl;
            cout << endl;
            system("pause");
            break;
        }

        case '5':
        {
            system("cls");
            Objeto elemento;
            cout << "Nombre del objeto: ";
            cin >> elemento.nombre;
            cout << endl;
            cout << "Tipo del objeto: ";
            cin >> elemento.tipo;
            cout << endl;
            cout << "Valor del objeto: ";
            cin >> elemento.valor;
            cout << endl;
            cout << "Cantidad: ";
            cin >> elemento.cantidad;

            pers.insertar_objeto(elemento);
            break;
        }

        case '6':
        {
            system("cls");
            Objeto objeto;
            cout << "Que objeto quieres eliminar (nombre): ";
            cin >> objeto.nombre;
            pers.eliminar_objeto(objeto);
            break;
        }

        case '7':
        {
            system("cls");
            pers.mostrarBolsa();
            system("pause");
            break;
        }

        case '8':
        {
            system("cls");
            cout << "Hay " << pers.numobjBolsa() << " objeto(s) en la bolsa." << endl;
            cout << endl;
            system("pause");
            break;
        }
        }
    }
}