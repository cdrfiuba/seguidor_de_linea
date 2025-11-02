## Fuentes
El archivo `src.ino` (nombrado para coincidir con las [especificaciones de sketch de Arduino](https://docs.arduino.cc/arduino-cli/sketch-specification/)) es el archivo principal y contiene un selector de versiones.
Para elegir cual incluir basta con definir la macro correspondiente a dicha version.

Los archivos `pins.h` y `config.h` contienen las macros correspondientes a los pines para no tener que definirlos en cada caso.

Las versiones se guardaron como archivos `.h` ya que al parecer no se pueden incluir `.ino`.

## TODO
- Se podria englobar cada version en su propio directorio y hacer desde dentro un `#include "../pins.h"` y seria mas liviano para el ide ya que solo se abriria un archivo a la vez
- Encapsular el conportamiento del seguidor en una funcion seguidor que se encargue de ejecutar el loop y gestionar como pasar de estado
- Script breve para compilar y subir el sketch 
