/******************************************************************************
 * Banda.hpp
 *
 * Módulo que contiene la clase Banda
 *
 * Programador:
 * Fecha:
 *****************************************************************************/

#ifndef __BANDA_HPP__
#define __BANDA_HPP__

#include <string>
#include <iostream>
#include "Personaje.hpp"

namespace bblProgIIB
{

	class Banda
	{
	private:
		struct Miembro
		{
			Personaje personaje;
			Miembro *sig;
		};
		typedef Miembro *Lista;

		Lista banda;

	public:
		Banda();
		// Constructor por defecto
		Banda(const Banda &Otra_banda);
		// Constructor de copia
		~Banda();
		// Destructor

		void crear_Banda();
		// Crea la banda de personajes vacia;
		// -------------------------------------
		void insertar_personaje(const Personaje &personaje);
		// Inserta un personaje en la banda en la posición correcta.
		void eliminar_personaje(const std::string &nombre);
		// Elimina un personaje de la banda
		// -------------------------------------
		void consultar_personaje(const std::string &nombre, Personaje &personaje, bool &esta) const;
		// Consulta si un personaje está en la banda, por el nombre del mismo, si está se
		// devuelve el personaje en personaje y esta se pone a true, si no está, esta se
		// pone a false y no se devuelve nada.
		// -------------------------------------
		unsigned integrantes_Banda() const;
		// Muestra el número total de integrantes de la banda
		// -------------------------------------
		void mostrar_Banda() const;
		// Muestra por pantalla todos los miembros de la banda y sus atributos, incluida la bolsa
		// -------------------------------------
		void leer_de_fichero(const std::string &nom_fic, bool &leido);
		// Inicializa la banda de personajes a partir de los datos leídos desde fichero.
		// Los personajes se insertan en orden alfabético por nombre de personaje, es decir, a partir de llamadas
		// al método insertar(...) de la propia clase. La banda actual debe
		// eliminarse antes de la lectura (es decir, debe borrarse completamente toda la lista
		// enlazada). El método recibe el nombre de fichero. Si el fichero puede abrirse
		// correctamente, leido se pone a true y se leen los datos desde fichero. Si no,
		// leido se pone a false y la banda quedará vacía.
		// El formato de fichero coincide con el de salida por pantalla (véase más arriba).
		// -------------------------------------
		void escribir_a_fichero(const std::string &nom_fic, bool &escrito) const;
		// Escribe en fichero la banda de personajes actual. El método recibe el identificador de fichero.
		// Si el fichero puede abrirse correctamente, escrito se pone a true y se escriben los datos a
		// fichero. Si no, escrito se pone a false. El formato de fichero coincide con el de salida
		// por pantalla (véase más arriba).

		// Operadores
		Banda &operator=(const Banda &otra);
		bool operator==(const Banda &otra) const;

		// Métodos privados

		void buscar_personaje(const std::string &nombre, Lista &pos, Lista &ant) const;
		// Busca un personaje en la banda.
		// ---------------------------------------------------------------------------
		void insertar_ordenado(const Personaje &personaje);
		// Inserta en la banda el personaje que se pasa como parámetro.
		// La lista debe quedar ordenada en orden creciente de nombres.
		// ---------------------------------------------------------------------------
		void eliminar_ordenado(const std::string &nombre);
		// Elimina de la lista el personaje cuyo nombre se pasa como parámetro.
		// ---------------------------------------------------------------------------
		void copiar_lista(Lista &destino, Lista origen) const;
		// Hace una copia de la lista que cuelga del puntero origen en el puntero destino.
		// ---------------------------------------------------------------------------
		void borrar_lista(Lista &lista) const;
		// Elimina todos los nodos de la lista que se pasa como parámetro, poniendo
		// lista finalmente a NULL (o nullptr).

	}; // Fin Class
} // Fin bblProgIIB
#endif