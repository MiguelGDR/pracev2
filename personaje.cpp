#include <string>
#include <iostream>
#include "Personaje.hpp"

using namespace std;
using namespace bblProgIIB;

// Constructores y destructor
Personaje::Personaje()
{
    nombre = "";
    raza = "";
    caracter = "";
    pvida = 0;
    pfuerza = 0;
    pdestreza = 0;
    pmagia = 0;
    oro = 0;
    bolsa = new Objeto;
}

Personaje::Personaje(std::string nnombre, std::string nraza, std::string ncaracter, char nsexo, unsigned npvida, unsigned npfuerza, unsigned npdestreza, unsigned npmagia, double noro, Bolsa &nbolsa)
{
    nombre = nnombre;
    raza = nraza;
    caracter = ncaracter;
    sexo = nsexo;
    pvida = npvida;
    pfuerza = npfuerza;
    pdestreza = npdestreza;
    pmagia = npmagia;
    oro = noro;
    bolsa = nbolsa;
}

Personaje::Personaje(const Personaje &Otro_personaje)
{
    nombre = Otro_personaje.nombre;
    raza = Otro_personaje.raza;
    caracter = Otro_personaje.caracter;
    sexo = Otro_personaje.sexo;
    pvida = Otro_personaje.pvida;
    pfuerza = Otro_personaje.pfuerza;
    pdestreza = Otro_personaje.pdestreza;
    pmagia = Otro_personaje.pmagia;
    oro = Otro_personaje.oro;
    bolsa = Otro_personaje.bolsa;
}

Personaje::~Personaje()
{
    delete bolsa;
}

// Métodos públicos
// ASIGNAR
void Personaje::asignarNombre(const std::string nomb)
{
    nombre = nomb;
}

void Personaje::asignarRaza(const std::string raz)
{
    raza = raz;
}

void Personaje::asignarCaracter(const std::string caract)
{
    caracter = caract;
}

void Personaje::asignarSexo(const char sex)
{
    sexo = sex;
}

void Personaje::asignarPvida(const unsigned pv)
{
    pvida = pv;
}

void Personaje::asignarPfuerza(const unsigned pf)
{
    pfuerza = pf;
}

void Personaje::asignarPdestreza(const unsigned pd)
{
    pdestreza = pd;
}

void Personaje::asignarPmagia(const unsigned pm)
{
    pmagia = pm;
}

void Personaje::asignarOro(const double mor)
{
    oro = mor;
}

void Personaje::asignarBolsa(const Bolsa &bols)
{
    bolsa = bols;
}

// MOSTRAR
std::string Personaje::mostrarNombre() const
{
    return nombre;
}

std::string Personaje::mostrarRaza() const
{
    return raza;
}

std::string Personaje::mostrarCaracter() const
{
    return caracter;
}

char Personaje::mostrarSexo() const
{
    return sexo;
}

unsigned Personaje::mostrarPvida() const
{
    return pvida;
}

unsigned Personaje::mostrarPfuerza() const
{
    return pfuerza;
}

unsigned Personaje::mostrarPdestreza() const
{
    return pdestreza;
}

unsigned Personaje::mostrarPmagia() const
{
    return pmagia;
}

double Personaje::mostrarOro() const
{
    return oro;
}

void Personaje::mostrarBolsa() const
{
    return;
}

// Metodos para uso de la bolsa (lista)
void Personaje::crearBolsa()
{
    bolsa = nullptr;
}

void Personaje::entregarBolsa(Bolsa &bolsac)
{
    bolsac = bolsa;
    borrar_bolsa(bolsa);
}

// Métodos privados
/*
void Personaje::buscar_objeto(const std::string nombre, Bolsa &pos, Bolsa &ant) const
{

}
*/

void Personaje::insertar_ordenado(Objeto &objeto)
{
    Bolsa ptr, nuevo_obj = new Objeto;
    nuevo_obj->nombre = objeto.nombre;
    nuevo_obj->tipo = objeto.tipo;
    nuevo_obj->valor = objeto.valor;
    nuevo_obj->cantidad = objeto.cantidad;
    nuevo_obj->sig = objeto.sig;

    if (bolsa == nullptr || bolsa->nombre > nuevo_obj->nombre)
    {
        nuevo_obj->sig = bolsa;
        bolsa = nuevo_obj;
    }
    else
    {
        bool done = false;
        ptr = bolsa;
        while (ptr != nullptr)
        {
            if (ptr->nombre > nuevo_obj->nombre)
            {
                nuevo_obj->sig = ptr;
                ptr = nuevo_obj;
                done = true;
            }
            ptr = ptr->sig;
        }
        if (false)  // ptr == nullptr
        {
            nuevo_obj->sig = nullptr;
            ptr = nuevo_obj;
        }
    }
}

void Personaje::eliminar_ordenado(const std::string &objeto)
{
    Bolsa ptr, ant = nullptr;
    if (bolsa != nullptr)
    {
        ptr = bolsa;
        while (ptr != nullptr && ptr->nombre < objeto)
        {
            ant = ptr;
            ptr = ptr->sig;
        }
        if (ptr != nullptr && ptr->nombre == objeto)
        {
            if (ant == nullptr)
            {
                bolsa = bolsa->sig;
            }
            else
            {
                ant->sig = ptr->sig;
            }
            delete ptr;
        }
    }
}

void Personaje::copiar_bolsa(Bolsa &destino, Bolsa origen) const
{
    destino = origen;
}

void Personaje::borrar_bolsa(Bolsa &bolsap) const
{
    Bolsa ptr; // Puntero auxiliar

    if (bolsap != nullptr)
    {
        ptr = bolsap;         // Igualo el nodo
        bolsap = bolsap->sig; // Paso al siguiente nodo
        delete ptr;           // Borr o el nodo
    }
}
