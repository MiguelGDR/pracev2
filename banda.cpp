#include <string>
#include <iostream>
#include <fstream>
#include "Personaje.hpp"
#include "Banda.hpp"

using namespace std;
using namespace bblProgIIB;

// Contructores y destructor ------------------------------------
Banda::Banda()
{
    banda = nullptr;
}

Banda::Banda(const Banda &Otra_banda)
{
    this->banda->personaje.asignarNombre(Otra_banda.banda->personaje.mostrarNombre());
    this->banda->personaje.asignarRaza(Otra_banda.banda->personaje.mostrarRaza());
    this->banda->personaje.asignarCaracter(Otra_banda.banda->personaje.mostrarCaracter());
    this->banda->personaje.asignarSexo(Otra_banda.banda->personaje.mostrarSexo());
    this->banda->personaje.asignarPvida(Otra_banda.banda->personaje.mostrarPvida());
    this->banda->personaje.asignarPfuerza(Otra_banda.banda->personaje.mostrarPfuerza());
    this->banda->personaje.asignarPdestreza(Otra_banda.banda->personaje.mostrarPdestreza());
    this->banda->personaje.asignarPmagia(Otra_banda.banda->personaje.mostrarPmagia());
    this->banda->personaje.asignarOro(Otra_banda.banda->personaje.mostrarOro());
    this->banda->personaje.asignarBolsa(Otra_banda.banda->personaje.obtenerBolsa());
}

Banda::~Banda()
{
    delete banda;
}

// Métodos públicos ---------------------------------------------
void Banda::crear_Banda()
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

        if (ptr != nullptr && ptr->personaje.mostrarNombre() == nombre)
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

void Banda::mostrar_Banda() const
{
    Lista ptr = banda;
    unsigned i = 1;
    while (ptr != nullptr)
    {
        cout << "Integrante num. " << i << ": " << endl;
        i += 1;
        cout << "Nombre: " << ptr->personaje.mostrarNombre() << endl;
        cout << "Raza: " << ptr->personaje.mostrarRaza() << endl;
        cout << "Caracter | Rol: " << ptr->personaje.mostrarCaracter() << endl;
        cout << "Sexo (Hombre - H | Mujer - M): " << ptr->personaje.mostrarSexo() << endl;
        cout << "Oro: " << ptr->personaje.mostrarOro() << endl;
        cout << endl;

        cout << "--- Puntos ---" << endl;
        cout << "Vida:     " << ptr->personaje.mostrarPvida() << endl;
        cout << "Fuerza:   " << ptr->personaje.mostrarPfuerza() << endl;
        cout << "Destreza: " << ptr->personaje.mostrarPdestreza() << endl;
        cout << "Magia:    " << ptr->personaje.mostrarPmagia() << endl;
        cout << "--------------" << endl;
        cout << endl;

        cout << " _____-----BOLSA-----_____" << endl;
        cout << endl;
        ptr->personaje.mostrarBolsa();
        cout << "--------------------------" << endl;

        ptr = ptr->sig;
        cout << endl;
    }
}

void Banda::leer_de_fichero(const std::string &nom_fic, bool &leido)
{
    borrar_lista(banda); // Borro la lista
    ifstream f_ent;
    Personaje pers;
    string entrada;
    char sexo;
    unsigned pts;
    double oro;
    f_ent.open(nom_fic);
    if ((leido = !f_ent.fail()))
    {
        while (!f_ent.eof())
        {
            // Nombre
            getline(f_ent, entrada);
            pers.asignarNombre(entrada);
            // Raza
            getline(f_ent, entrada);
            pers.asignarRaza(entrada);
            // Rol
            getline(f_ent, entrada);
            pers.asignarCaracter(entrada);
            // Sexo
            f_ent >> sexo;
            pers.asignarSexo(sexo);
            // Puntos (vida, fuerza, destreza, magia)
            f_ent >> pts;
            pers.asignarPvida(pts);
            f_ent >> pts;
            pers.asignarPfuerza(pts);
            f_ent >> pts;
            pers.asignarPdestreza(pts);
            f_ent >> pts;
            pers.asignarPmagia(pts);
            // Oro
            f_ent >> oro;
            pers.asignarOro(oro);
            // Numero de objetos (uso la variable pts para ahorrar espacio)
            f_ent >> pts;
            // Objetos de la bolsa
            pers.crearBolsa();
            for (unsigned i = 0; i < pts; i++) // Bucle para en num de objetos indicados
            {
                getline(f_ent, entrada); // Lo utilizo porque se queda un salto se linea pillado
                Objeto obj;
                double valor;
                unsigned cantidad;

                // Nombre
                getline(f_ent, entrada);
                obj.nombre = entrada;
                // Tipo
                getline(f_ent, entrada);
                obj.tipo = entrada;
                // Valor
                f_ent >> valor;
                obj.valor = valor;
                // Cantidad
                f_ent >> cantidad;
                obj.cantidad = cantidad;
                // Inserto el objeto
                pers.insertar_objeto(obj);
            }

            getline(f_ent, entrada); // Lo utilizo porque se queda un salto se linea pillado
            insertar_personaje(pers);
        }

        f_ent.close();
    }
}

void Banda::escribir_a_fichero(const std::string &nom_fic, bool &escrito) const
{
    ofstream f_sal;
    Lista ptr = banda;
    Personaje pers;
    Bolsa obj;
    unsigned num, inte;
    f_sal.open(nom_fic);
    inte = integrantes_Banda();
    if ((escrito = 1))
    {
        for (unsigned i = 0; i < inte; i++)
        {
            f_sal << ptr->personaje.mostrarNombre() << endl;
            f_sal << ptr->personaje.mostrarRaza() << endl;
            f_sal << ptr->personaje.mostrarCaracter() << endl;
            f_sal << ptr->personaje.mostrarSexo() << endl;
            f_sal << ptr->personaje.mostrarPvida() << endl;
            f_sal << ptr->personaje.mostrarPfuerza() << endl;
            f_sal << ptr->personaje.mostrarPdestreza() << endl;
            f_sal << ptr->personaje.mostrarPmagia() << endl;
            f_sal << ptr->personaje.mostrarOro() << endl;
            f_sal << (num = ptr->personaje.numobjBolsa()) << endl;
            obj = ptr->personaje.obtenerBolsa();

            if (i + 1 == inte) // Si es el ultimo personaje, el utlimo objeto se guarda sin endl (en el apartado de cantidad) para no escribir una linea de más innecesaria
            {
                for (unsigned a = 0; a < num; a++)
                {
                    if (a + 1 == num) // Ultimo objeto
                    {
                        f_sal << obj->nombre << endl;
                        f_sal << obj->tipo << endl;
                        f_sal << obj->valor << endl;
                        f_sal << obj->cantidad; // Sin endl
                    }
                    else
                    {
                        f_sal << obj->nombre << endl;
                        f_sal << obj->tipo << endl;
                        f_sal << obj->valor << endl;
                        f_sal << obj->cantidad << endl;
                        obj = obj->sig;
                    }
                }
            }
            else
            {
                for (unsigned a = 0; a < num; a++)
                {
                    f_sal << obj->nombre << endl;
                    f_sal << obj->tipo << endl;
                    f_sal << obj->valor << endl;
                    f_sal << obj->cantidad << endl;
                    obj = obj->sig;
                }
                ptr = ptr->sig;
            }
        }
    }

    f_sal.close();
}

// Operadores ---------------------------------------------------
Banda &Banda::operator=(const Banda &otra)
{
    this->banda = otra.banda;
    return *this;
}

bool Banda::operator==(const Banda &otra) const
{
    return (this->banda == otra.banda);
}

// Métodos privados ---------------------------------------------
void Banda::insertar_ordenado(const Personaje &personaje)
{
    Lista ptr, nuevopers = new Miembro;
    nuevopers->personaje.asignarNombre(personaje.mostrarNombre());
    nuevopers->personaje.asignarRaza(personaje.mostrarRaza());
    nuevopers->personaje.asignarCaracter(personaje.mostrarCaracter());
    nuevopers->personaje.asignarSexo(personaje.mostrarSexo());
    nuevopers->personaje.asignarPvida(personaje.mostrarPvida());
    nuevopers->personaje.asignarPfuerza(personaje.mostrarPfuerza());
    nuevopers->personaje.asignarPdestreza(personaje.mostrarPdestreza());
    nuevopers->personaje.asignarPmagia(personaje.mostrarPmagia());
    nuevopers->personaje.asignarOro(personaje.mostrarOro());
    nuevopers->personaje.asignarBolsa(personaje.obtenerBolsa());
    nuevopers->sig = nullptr;

    if (banda == nullptr || banda->personaje.mostrarNombre() > nuevopers->personaje.mostrarNombre())
    {
        nuevopers->sig = banda;
        banda = nuevopers;
    }
    else
    {
        ptr = banda;

        while ((ptr->sig != nullptr) && (ptr->personaje.mostrarNombre() < nuevopers->personaje.mostrarNombre()))
        {
            ptr = ptr->sig;
        }
        if (ptr->sig == nullptr)
        {
            nuevopers->sig = ptr->sig;
            ptr->sig = nuevopers;

            cout << endl;
        }
        else
        {
            nuevopers->sig = ptr->sig;
            ptr->sig = nuevopers;

            cout << endl;
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
        delete ptr;         // Borro el nodo
    }
    lista = nullptr;
}