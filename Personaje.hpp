/******************************************************************************
 * Banda.hpp
 *
 * Módulo que contiene la clase Personaje
 *
 * Programador:
 * Fecha:
 *****************************************************************************/

#ifndef __PERSONAJE_HPP__
#define __PERSONAJE_HPP__

#include <string>
#include <iostream>

namespace bblProgIIB
{
    struct Objeto{
        std::string nombre;
        std::string tipo;
        double valor;
        unsigned cantidad;
        Objeto *sig;
     };
    typedef Objeto *Bolsa;

    class Personaje 
    {
        public:
        
            Personaje();
            // Constructor específico
            Personaje(std::string nnombre, std::string nraza, std::string ncaracter, char nsexo, unsigned npvida, unsigned npfuerza, unsigned npdestreza, unsigned npmagia, double noro, Bolsa &nbolsa);
            // Constructor de copia
            Personaje(const Personaje &Otro_personaje);
            // Destructor
            ~Personaje();
            
            // Establece el nombre del personaje.
            void asignarNombre(const std::string nomb);

            // Establece la raza del personaje.
            void asignarRaza(const std::string raz);

           // Establece el carácter del personaje.
            void asignarCaracter(const std::string caract);
            
            // Establece el sexo del personaje.
            void asignarSexo(const char sex);

            // Establece los puntos de vida del personaje
            void asignarPvida(const unsigned pv);
            
            // Establece los puntos de fuerza del personaje
            void asignarPfuerza(const unsigned pf);

            // Establece los puntos de destreza del personaje
            void asignarPdestreza(const unsigned pd);
            
            // Establece los puntos de magia del personaje
            void asignarPmagia(const unsigned pm);

            // Establece las monedas de oro que tiene el personaje
            void asignarOro(const double mor);

            // Establece los objetos que posee el personaje
            void asignarBolsa(const Bolsa &bols);

            // Muestra el nombre del personaje.
            std::string mostrarNombre() const;

            // Muestra la raza del personaje.
            std::string mostrarRaza() const;

            // Muestra el caracter del personaje.
            std::string mostrarCaracter() const;

            // Muestra el sexo del personaje.
            char mostrarSexo() const;

            // Muestra los puntos de vida del personaje
            unsigned mostrarPvida() const;
            
            // Muestra los puntos de fuerza del personaje
            unsigned mostrarPfuerza() const;

            // Muestra los puntos de destreza del personaje
            unsigned mostrarPdestreza() const;
            
            // Muestra los puntos de magia del personaje
            unsigned mostrarPmagia() const;

            // Muestra las monedas de oro que tiene el personaje
            double mostrarOro() const;

            // Muestra los objetos que posee el personaje
            void mostrarBolsa() const;

            // Crea la bolsa del personaje;
            void crearBolsa();

            //Copia la bolsa del personaje y la devuelve en bolsac, dejando vacia la bolsa del personaje
            void entregarBolsa(Bolsa &bolsac);

            // Inserta un objeto en la bolsa, si existe, actualiza el objeto existente, número y valor
            void insertar_objeto(Objeto &objeto);

            // Modifica un objeto de la bolsa
            void modifica_objeto(Objeto &objeto);

            // Elimina un objeto de la bolsa
            void eliminar_objeto(Objeto &objeto);
            
        // Operadores
        Personaje &operator=(const Personaje &otro);
        bool operator==(const Personaje &otro) const; 

        private:
            // Atributos del personaje
            std::string nombre;
            std::string raza;
            std::string caracter;
            char sexo;
            unsigned pvida;
            unsigned pfuerza;
            unsigned pdestreza;
            unsigned pmagia;
            double oro;
            Bolsa bolsa;

            // Métodos privados
            void buscar_objeto(const std::string nombre, Bolsa &pos, Bolsa &ant) const;
            // Busca un objeto en la bolsa y devuelve la posición en la que debería estar
            // si no lo encuentra o la posición en la que está.
        	void insertar_ordenado(Objeto &objeto);
	        // Inserta en la bolsa el objeto que se pasa como parámetro, 
	        // La bolsa debe quedar ordenada en orden creciente de nombres de objetos.
	        // ---------------------------------------------------------------------------
	        void eliminar_ordenado(const std::string &objeto);
	        // Elimina de la bolsa el nodo cuyo nombre de objeto se pasa como parámetro.
	        // ---------------------------------------------------------------------------
	        void copiar_bolsa(Bolsa &destino, Bolsa origen) const;
	        // Hace una copia de la bolsa que cuelga del puntero origen en el puntero destino.
	        // ---------------------------------------------------------------------------
	        void borrar_bolsa(Bolsa &bolsap) const;
	        // Elimina todos los nodos de la bolsa que se pasa como parámetro, poniendo
	        // bolsa finalmente a NULL (o nullptr). 
         

    }; // Fin Classa
}// Fin bblProgIIB
#endif