#include <string>
#include <iostream>
#include <fstream>
#include "Personaje.hpp"
#include "Banda.hpp"

using namespace std;
using namespace bblProgIIB;

/*  g++ -c personaje.cpp -Wall -Werror -Wextra
g++ -c main_banda.cpp -Wall -Werror -Wextra
g++ -c banda.cpp -Wall -Werror -Wextra
g++ -o zmainband main_banda.o banda.o personaje.o -Wall -Werror -Wextra  */

char menu()
{
    system("cls");
    cout << "------------ Menu Banda ------------" << endl;
    cout << "0.- Fin" << endl;
    cout << "1.- Unir personaje a una banda" << endl;
    cout << "2.- Eliminar personaje de una banda" << endl;
    cout << "3.- Consultar personajes de una banda" << endl;
    cout << "4.- Mostrar el numero de componentes de una banda" << endl;
    cout << "5.- Mostrar los componentes de la banda por pantalla" << endl;
    cout << "6.- Leer banda desde fichero" << endl;
    cout << "7.- Escribir banda a fichero" << endl;
    cout << "8.- Copiar banda (constructor de copia)" << endl;
    char op;
    do
    {
        cout << " Opcion ? ";
        cin >> op;
    } while (op < '0' || op > '8');
    cout << endl;
    return op;
}

void mostrarPers(Personaje &pers)
{
    cout << pers.mostrarNombre() << endl;
    cout << pers.mostrarRaza() << endl;
    cout << pers.mostrarCaracter() << endl;
    cout << pers.mostrarSexo() << endl;
    cout << pers.mostrarPvida() << endl;
    cout << pers.mostrarPfuerza() << endl;
    cout << pers.mostrarPdestreza() << endl;
    cout << pers.mostrarPmagia() << endl;
    cout << pers.mostrarOro() << endl;
    pers.mostrarBolsa();
}

int main()
{
    Banda band, band2;
    char op;

    while ((op = menu()) != '0')
    {
        switch (op)
        {
        case '1':
        {
            system("cls");
            Personaje pers;
            cout << "--- Unir un personaje a la banda ---" << endl;
            // Nombre
            cout << "Nombre del personaje: ";
            string nombre;
            cin >> nombre;
            pers.asignarNombre(nombre);
            cout << endl;
            // Raza
            cout << "Raza del personaje (Elfo, Enano, Hobbit, Humano u Orco): ";
            string raza;
            cin >> raza;
            pers.asignarRaza(raza);
            cout << endl;
            // Caracter / Rol
            cout << "Caracter | Rol: ";
            string caracter;
            cin >> caracter;
            pers.asignarCaracter(caracter);
            cout << endl;
            // Genero
            cout << "Sexo (Hombre - H | Mujer - M): ";
            char gen;
            cin >> gen;
            pers.asignarSexo(gen);
            cout << endl;
            // Pts de vida, fuerza, destreza y magia
            cout << "Puntos de vida: ";
            unsigned pts;
            cin >> pts;
            pers.asignarPvida(pts);
            cout << endl;
            cout << "Puntos de fuerza: ";
            cin >> pts;
            pers.asignarPfuerza(pts);
            cout << endl;
            cout << "Puntos de destreza:  ";
            cin >> pts;
            pers.asignarPdestreza(pts);
            cout << endl;
            cout << "Puntos de magia: ";
            cin >> pts;
            pers.asignarPmagia(pts);
            cout << endl;
            // Oro
            double oro;
            cout << "Oro: ";
            cin >> oro;
            pers.asignarOro(oro);
            // Bolsa
            system("cls");
            pers.crearBolsa();
            char yn;
            cout << "Quieres guardar objetos en la bolsa? [y/n]: ";
            cin >> yn;
            while (yn == 'y')
            {
                Objeto elemento;
                cout << "Nombre del objeto: ";
                cin >> elemento.nombre; // No puedo leer con getline(cin,elemento.nombre) por alguna razon que desconozco.
                cout << endl;
                cout << "Tipo del objeto: ";
                cin >> elemento.tipo;
                cout << endl;
                cout << "Valor del objeto: ";
                cin >> elemento.valor;
                cout << endl;
                cout << "Cantidad: ";
                cin >> elemento.cantidad;
                cout << endl;
                pers.insertar_objeto(elemento);

                cout << "Quieres aladir otro objeto? [y/n]: ";
                cin >> yn;
                cout << endl;
            }

            // Inserto al personaje en la banda
            band.insertar_personaje(pers);
            cout << "El personaje num. " << band.integrantes_Banda() << " ha sido aceptado en la banda." << endl;
            cout << endl;
            system("pause");
            break;
        }

        case '2':
        {
            system("cls");
            cout << "--- Eliminar un personaje de la banda ---" << endl;
            if (band.integrantes_Banda() == 0)
            {
                cout << "No hay ningun integrante en la banda." << endl;
                cout << endl;
                system("pause");
            }
            else
            {
                Personaje pers;
                bool esta;
                string nombre;
                cout << "A quien quieres eliminar: ";
                cin >> nombre;
                band.consultar_personaje(nombre, pers, esta); // Compruebo que este el personaje
                if (esta)
                {
                    band.eliminar_personaje(nombre);
                    system("pause");
                }
                else
                {
                    cout << endl;
                    cout << "No existe ningun integrante con el nombre " << nombre << " en la banda." << endl;
                    cout << endl;
                    system("pause");
                }
            }
            break;
        }

        case '3':
        {
            system("cls");
            Personaje pers;
            bool esta;
            string nombre;
            cout << "--- Consultar personajes de la banda ---" << endl;
            cout << "Para consultar si un personaje está en la banda, introduzca su nombre: ";
            cin >> nombre;
            band.consultar_personaje(nombre, pers, esta);
            if (esta)
            {
                cout << nombre << " esta en la banda." << endl;
                mostrarPers(pers);
                cout << endl;
                system("pause");
            }
            else
            {
                cout << nombre << " no esta en la banda." << endl;
            }
            cout << endl;
            system("pause");
            break;
        }

        case '4':
        {
            system("cls");
            cout << "--- Numero de integrantes de la banda ---" << endl;
            cout << "El numero de integrantes de la banda es: " << band.integrantes_Banda() << endl;
            cout << endl;
            system("pause");
            break;
        }

        case '5':
        {
            system("cls");
            cout << "--- Integrantes de la banda ---" << endl;
            cout << endl;
            band.mostrar_Banda();
            system("pause");
            break;
        }

        case '6':
        {
            string archivo;
            bool leido;
            system("cls");
            cout << "--- Lectura de banda de un archivo ---" << endl;
            cout << endl;
            cout << "Que archivo quieres leer?: ";
            cin >> archivo;
            band.leer_de_fichero(archivo, leido);
            system("cls");
            if (leido)
            {
                cout << "Se ha leido el archivo correctamente." << endl;
            }
            else
            {
                cout << "No se ha leido el archivo." << endl;
            }
            cout << endl;
            system("pause");
            break;
        }

        case '7':
        {
            string archivo;
            bool escrito;
            system("cls");
            cout << "--- Escritura de banda a un archivo ---" << endl;
            cout << endl;
            cout << "Con que nombre quieres guardar el archivo?: ";
            cin >> archivo;
            band.escribir_a_fichero(archivo, escrito);
            system("cls");
            if (escrito)
            {
                cout << "Se ha escrito el archivo correctamente." << endl;
            }
            else
            {
                cout << "No se ha escrito el archivo." << endl;
            }
            cout << endl;
            system("pause");
            break;
        }

        case '8':
        {
            Banda bandcopia(band);
            band2 = bandcopia;
            break;
        }
        }
    }
}
