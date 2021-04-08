# C♭

Guía de instalación del compilador C♭ en Pampero. Si tiene problemas instalando OpenAL en su computadora, puede utilizar el archivo **cflat_basic** en lugar de **cflat** para correr código sin audio.

## Instrucciones de instalación

1) Clonar el repositorio
> git clone https://github.com/sterenziani/chunchunmaru

2) Acceder al branch *local*
> git checkout local

3) Entrar a la carpeta del repositorio
> cd chunchunmaru

4) Instalar OpenAL desde la terminal con el siguiente comando:

En Mac:
> brew install openal-soft

En Linux:
> sudo apt-get install libopenal-dev

5) Correr el siguiente comando para crear el compilador de C♭
> make compiler

6) Una vez conectado, correr el compilador de C♭ junto con algún archivo de ejemplo escrito en nuestro lenguaje:
> ./cflat Examples/keyboard

7) Luego simplemente correr el archivo a.out:
> ./a.out
