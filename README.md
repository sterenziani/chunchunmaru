# chunchunmaru

Actualmente el archivo sound.c es un demo de cómo armar música. Tiene un bug donde las notas más altas tienen un tempo más rápido, pero bueno. Podríamos limitar que uses solo 3 octavas (3-5) en vez de las 5 disponibles (2-6)

1) Instalar openAL desde la terminal con el siguiente comando:
> brew install openal-soft

2) Una vez descargada e instalada la librería, ejecutar desde la raíz del proyecto:
> make openal

3) Correr el siguiente comando para crear el compilador de C♭
> make all

4) Una vez listo, correr el compilador de C♭ junto con algún archivo de ejemplo escrito en nuestro lenguaje
> ./cflat Examples/example

TO DO:
- Hacer que se puedan sumar **variabes** de tipo *note* y numeros, no solo valores de tipo *note*
- Eliminar el flag al compilar que crea el archivo C traducido

Fun facts:
- El **and** toma precedencia sobre el **or**

Recursos para el informe. Lenguaje de inspiración y de donde sacamos el getchar para el teclado:
https://github.com/atharos1/Cpanish
https://stackoverflow.com/questions/7469139/what-is-the-equivalent-to-getch-getche-in-linux
