# chunchunmaru

Actualmente el archivo sound.c es un demo de cómo armar música. Tiene un bug donde las notas más altas tienen un tempo más rápido, pero bueno. Podríamos limitar que uses solo 3 octavas (3-5) en vez de las 5 disponibles (2-6)

Uso en mac

1) Instalar openAL desde la terminal con el siguiente comando:
> brew install openal-soft

2) Una vez descargada e instalada la librería, compilar con:
> gcc -framework OpenAL sound.c -o sound

3) Ejecutar
> ./sound