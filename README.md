# C♭

Guía de instalación del compilador C♭ en Pampero. Si tiene problemas instalando OpenAL en su computadora, puede utilizar el archivo **cflat_basic** en lugar de **cflat** para correr código sin audio.

## Instrucciones de Instalacion en Pampero

Se requieren dos copias del repositorio, una en la Computadora Local y otra en Pampero.

### En la Computadora Local (la que tiene el dispositivo de reproduccion de audio)

1) Clonar el repositorio
> git clone https://github.com/sterenziani/chunchunmaru

2) Entrar a la carpeta del repositorio
> cd chunchunmaru

3) Instalar OpenAL desde la terminal con el siguiente comando:

En Mac:
> brew install openal-soft

En Linux:
> sudo apt-get install libopenal-dev

4) Correr el siguiente comando para crear el servidor de C♭
> make server

5) Una vez listo, correr el servirdor de C♭ (para ello no debe haber corriendo ningun proceso en el puerto 58415, puede ser checkeado de manera sencilla mediante `netstat -nlpt | grep 58415`):
> ./cflat.server

6) Realizar una connexion SSH con Pampero pero forwardeando el puerto en el que esta corriendo el servidor de C♭:
> ssh -R58415:localhost:58415 *user*@pampero.it.itba.edu.ar

### Dentro de Pampero

7) Clonar el repositorio dentro de Pampero
> git clone https://github.com/sterenziani/chunchunmaru

8) Entrar a la carpeta del repositorio
> cd chunchunmaru

9) Correr el siguiente comando para crear el compilador de C♭
> make compiler

10) Una vez conectado, correr el compilador de C♭ junto con algún archivo de ejemplo escrito en nuestro lenguaje:
> ./cflat Examples/keyboard

11) Luego simplemente correr el archivo a.out:
> ./a.out
