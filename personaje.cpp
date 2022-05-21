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