Alumno: Miguel González del Río
Grado: Ing. de Sonido e Imagen

Detalles a destacar:

- No he implementado que se pueda meter por teclado nombres (ya sea del personaje, o del objeto... en definitiva cualquier string) 
  que contengan un espacio. P.ej, no puede introducirse "Frodo Bolson" o "Espada elfica Narsil" --> Dará error en ese caso.

- Respecto al anterior detalle, sí he implementado que se puedan leer archivos con nombres (que contengan espacios), pero, en caso
  de querer eliminar un personaje cuyo nombre contenga espacios, no sera posible debido al detalle anterior.

- El archivo "Banda.txt" se puede leer pero no se pueden eliminar aquellos personajes que tengan nombres con espacios.

- El programa leerá erróneamente archivos de texto (.txt) que contengan una línea adicional vacía al final. --> Lo que hará será 
  añadir un nuevo personaje sin nombre, o duplicará al último.

- En consecuencia al detalle anterior, la opción de escribir_archivo que he implementado no añade una línea adicional vacía al final.
  De este modo, el programa será capaz de leer correctamente cualquier archivo generado con el mismo.

Conclusión: Todo archivo generado con el programa será perfectamente leido y se podrá manipular enteramente con el mismo. No habrá 
	    problemas con la lectura pues al escribir el archivo no añade la linea final vacía. Lo mismo ocurre con los nombres;
	    pues como solo se pueden escribir nombres sin espacios, todo archivo generado - leido tendrá ese mismo tipo de nombres 
	    y se podrán eliminar de la banda (si se desea). 
            
