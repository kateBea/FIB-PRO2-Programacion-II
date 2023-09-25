# FIB-PRO2 [Programación II]
Repositorio del curso de Programación II en el grado de Ingeniería Informática en la FIB UPC

- Setup de p2++ en casa:

    El comando p2++ es solo un typedef del compilador que usamos con normalidad (g++). 
    Simplemente deberemos definir el alias p2++ como se indica en la documentación de 
    laboratorio de PRO II.

    ``alias p2++ = "g++ -D_GLIBCXX_DEBUG -O2 -Wall -Wextra -Werror -Wno-sign-compare -std=c++11"``

Para más detalles sobre los comandos que se están pasando al invocar g++:

    > g++               -> Compilador C/C++ GNU (el binario ejecutable)
    > -D_GLIBCXX_DEBUG  -> Usar libreria libstdc++ en modo de Debug
    > -O2               -> Habilitar niveles de optimización
    > -Wall             -> Habilita todos los warnings
    > -Wextra           -> Warnings extra que no se habilitan con -Wall
    > -Wno-sign-compare -> Ignorar comparación entre expresiones con/sin signo
    > -std=c++11        -> Utilizar estandard 11 de C++

Recordatorio: Copiar alias al final de fichero .bashsrc en la carpeta $HOME (variable de entorno) para evitar tener que redefinir el alias cada vez que se abre una nueva terminal
