# C♭

Actualmente el archivo sound.c es un demo de cómo armar música. Tiene un bug donde las notas más altas tienen un tempo más rápido, pero bueno. Podríamos limitar que uses solo 3 octavas (3-5) en vez de las 5 disponibles (2-6).

## Instrucciones de Instalacion en Pampero

### En la Computadora Local

1) Instalar OpenAL desde la terminal localmente (donde estan el dispositivo de sonido, no pampero) con el siguiente comando:

En Mac:
> brew install openal-soft

En Linux:
> sudo apt-get install libopenal-dev

2) En la computadora local (la que tiene el dispositivo de)

2) Correr el siguiente comando para crear el compilador de C♭ y el servidor de C♭
> make all

3) Una vez listo, correr el compilador de C♭ junto con algún archivo de ejemplo escrito en nuestro lenguaje
> ./cflat Examples/example

4) Antes de ejecutar cualquier archivo de cflat debe estar corriendo el servidor del mismo. Si no esta corriendo, ejecutar el comando (este servidor se cuelga del puerto 58415, verificar que dicho puerto no este siendo usado por otro programa):
> ./cflat.server

TO DO:
- Hacer que se puedan sumar **variabes** de tipo *note* y numeros, no solo valores de tipo *note*
- Eliminar el flag al compilar que crea el archivo C traducido

Fun facts:
- El **and** toma precedencia sobre el **or**

Recursos para el informe. Lenguaje de inspiración y de donde sacamos el getchar para el teclado:
- https://github.com/atharos1/Cpanish
- https://stackoverflow.com/questions/7469139/what-is-the-equivalent-to-getch-getche-in-linux