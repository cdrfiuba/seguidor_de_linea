## Fuentes
El archivo `src.ino` (nombrado para coincidir con las [especificaciones de sketch de Arduino](https://docs.arduino.cc/arduino-cli/sketch-specification/)) es el archivo principal y contiene un selector de versiones.
Para elegir cual incluir basta con definir la macro correspondiente a dicha version.

Los archivos `pins.h` y `config.h` contienen las macros correspondientes a los pines para no tener que definirlos en cada caso.

Las versiones se guardaron como archivos `.h` ya que al parecer no se pueden incluir `.ino`.
