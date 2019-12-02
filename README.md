# C♭

Actualmente el archivo sound.c es un demo de cómo armar música. Tiene un bug donde las notas más altas tienen un tempo más rápido, pero bueno. Podríamos limitar que uses solo 3 octavas (3-5) en vez de las 5 disponibles (2-6).

## Instrucciones de Instalacion en Pampero

Se requieren dos copias del repositorio, una en la Computadora Local y otra en Pampero.

### En la Computadora Local (la que tiene el dispositivo de reproduccion de audio)

1) Instalar OpenAL desde la terminal con el siguiente comando:

En Mac:
> brew install openal-soft

En Linux:
> sudo apt-get install libopenal-dev

2) Correr el siguiente comando para crear el servidor de C♭
> make server

3) Una vez listo, correr el servirdor de C♭ (para ello no debe haber corriendo ningun proceso en el puerto 58415, puede ser checkeado de manera sencilla mediante `netstat -nlpt | grep 58415`):
> ./cflat.server

### En Pampero

4) Realizar una connexion SSH con pampero pero forwardeando el puerto en el que esta corriendo el servidor de C♭:
> ssh -R58415:localhost:58415 *user*@pampero.it.itba.edu.ar

5) Correr el siguiente comando para crear el compilador de C♭
> make compiler

6) Una vez conectado, correr el compilador de C♭ junto con algún archivo de ejemplo escrito en nuestro lenguaje:
> ./cflat Examples/music

7) Luego simplemente correr el archivo a.out:
> ./a.out

TO DO:
- Hacer que se puedan sumar **variabes** de tipo *note* y numeros, no solo valores de tipo *note*
- Eliminar el flag al compilar que crea el archivo C traducido

Fun facts:
- El **and** toma precedencia sobre el **or**

Recursos para el informe. Lenguaje de inspiración y de donde sacamos el getchar para el teclado:
- https://github.com/atharos1/Cpanish
- https://stackoverflow.com/questions/7469139/what-is-the-equivalent-to-getch-getche-in-linux
