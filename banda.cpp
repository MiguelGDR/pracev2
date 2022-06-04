#include <string>
#include <iostream>
#include "Personaje.hpp"
#include "Banda.hpp"

using namespace std;
using namespace bblProgIIB;

// Contructores y destructor ------------------------------------
Banda::Banda()
{
    banda = nullptr;
}

Banda::Banda(const Lista &Otra_banda)
{
    banda = Otra_banda;
}

Banda::~Banda()
{
    delete banda;
}

// Métodos públicos ---------------------------------------------
void Banda::crear_Banda(Lista &banda)
{
    banda = nullptr;
}

void Banda::insertar_personaje(const Personaje &personaje)
{
    insertar_ordenado(personaje);
}

void Banda::eliminar_personaje(const std::string &nombre)
{
    eliminar_ordenado(nombre);
}

void Banda::consultar_personaje(const std::string &nombre, Personaje &personaje, bool &esta) const
{
    Lista ptr = banda;
    esta = false;
    if (banda != nullptr)
    {
        if (ptr != nullptr && ptr->personaje.mostrarNombre() != nombre)
        {
            ptr = ptr->sig;
        }

        if (ptr->personaje.mostrarNombre() == nombre)
        {
            esta = true;
            personaje = ptr->personaje;
        }
    }
}

unsigned Banda::integrantes_Banda() const
{
    unsigned i = 0;
    Lista ptr = banda;
    while (ptr != nullptr)
    {
        ptr = ptr->sig;
        i += 1;
    }
    return i;
}

void Banda::mostrar_Banda(const Lista &bandal) const
{
    Lista ptr = bandal;
    unsigned i = 1;
    while (ptr != nullptr)
    {
        cout << "Integrante nº " << i << ": " << endl;
        i += 1;
        cout << "Nombre: " << ptr->personaje.mostrarNombre() << endl;
        cout << "Raza: " << ptr->personaje.mostrarRaza() << endl;
        cout << "Caracter | Rol: " << ptr->personaje.mostrarCaracter() << endl;
        cout << "Sexo (Masculino - M | Femenino - F): " << ptr->personaje.mostrarSexo() << endl;
        cout << "Oro: " << ptr->personaje.mostrarOro() << endl;
        cout << endl;

        cout << "-- Puntos ---" << endl;
        cout << "Vida:     " << ptr->personaje.mostrarPvida() << endl;
        cout << "Fuerza:   " << ptr->personaje.mostrarPfuerza() << endl;
        cout << "Destreza: " << ptr->personaje.mostrarPdestreza() << endl;
        cout << "Magia:    " << ptr->personaje.mostrarPmagia() << endl;

        cout << " _____-----BOLSA-----_____" << endl;
        ptr->personaje.mostrarBolsa();
        cout << "--------------------------" << endl;
        cout << endl;
    }

}

// Métodos privados ---------------------------------------------
void Banda::insertar_ordenado(const Personaje &personaje)
{
    Lista ptr, nuevopers = new Miembro;
    nuevopers->personaje.asignarNombre(personaje.mostrarNombre());

    if (banda == nullptr || banda->personaje.mostrarNombre() > nuevopers->personaje.mostrarNombre())
    {
        nuevopers->sig = banda;
        banda = nuevopers;

        system("pause");
    }
    else
    {
        bool done = false;
        ptr = banda;

        while ((ptr->sig != nullptr) && (ptr->personaje.mostrarNombre() < nuevopers->personaje.mostrarNombre()))
        {
            ptr = ptr->sig;
        }
        if (ptr->sig == nullptr)
        {
            nuevopers->sig = ptr->sig;
            ptr->sig = nuevopers;

            done = true;

            cout << endl;
            system("pause");
        }
        if (!done)
        {
            nuevopers->sig = ptr->sig;
            ptr->sig = nuevopers;

            cout << endl;
            system("pause");
        }
    }
}

void Banda::eliminar_ordenado(const std::string &nombre)
{
    Lista ptr, ant = nullptr;
    if (banda != nullptr)
    {
        ptr = banda;
        while (ptr != nullptr && ptr->personaje.mostrarNombre() < nombre)
        {
            ant = ptr;
            ptr = ptr->sig;
        }
        if (ptr != nullptr && ptr->personaje.mostrarNombre() == nombre)
        {
            if (ant == nullptr)
            {
                banda = banda->sig;
            }
            else
            {
                ant->sig = ptr->sig;
            }
            delete ptr;
        }
    }
}

void Banda::copiar_lista(Lista &destino, Lista origen) const
{
    destino = origen;
}

void Banda::borrar_lista(Lista &lista) const
{
    Lista ptr; // Puntero auxiliar

    if (lista != nullptr)
    {
        ptr = lista;        // Igualo el nodo
        lista = lista->sig; // Paso al siguiente nodo
        delete ptr;         // Borr o el nodo
    }
}