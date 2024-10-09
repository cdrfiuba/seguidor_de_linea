## Script para exportar la placa a distintos formatos
## .grb .drl .svg

EXPORT_DIRECTORY=exports
FABRICATION_DIRECTORY=fabrication

export_svg() {
  # Exporto a SVG y cambio dentro de los archivos la opacidad de las zonas rellenas
  kicad-cli pcb export svg\
    --page-size-mode 2\
    --layers User.Drawings,F.Silkscreen,Edge.Cuts,F.Courtyard,F.Fab,F.Cu\
    modulo_sensor.kicad_pcb

  sed "s/C83434; fill-opacity:1.0000/C83434; fill-opacity:0.5000/g"\
    < modulo_sensor.svg > aux.svg

  sed "s/stroke:#000000; stroke-width:0.1500; stroke-opacity:1;/stroke:#000000; stroke-width:0.1500; stroke-opacity:0;/g"\
    < aux.svg > $EXPORT_DIRECTORY/front_preview.svg

  kicad-cli pcb export svg\
    --page-size-mode 2\
    --layers User.Drawings,B.Silkscreen,Edge.Cuts,B.Courtyard,B.Fab,B.Cu\
    modulo_sensor.kicad_pcb

  sed "s/4D7FC4; fill-opacity:1.0000/4D7FC4; fill-opacity:0.3500/g"\
    < modulo_sensor.svg > $EXPORT_DIRECTORY/bottom_preview.svg

  rm modulo_sensor.svg aux.svg
}

export_drl() {
  # Genero archivos .drl
  kicad-cli pcb export drill --output $FABRICATION_DIRECTORY\
    --drill-origin absolute\
    --excellon-oval-format route\
    --excellon-units in\
    --excellon-separate-th\
    modulo_sensor.kicad_pcb
}

export_grb(){
  #Genero archivos .grb (Hardcodeo las layers)
  kicad-cli pcb export gerbers --output $FABRICATION_DIRECTORY\
    --layers F.Cu,B.Cu,F.Paste,B.Paste,F.Silkscreen,B.Silkscreen,F.Mask,B.Mask,Edge.Cuts\
    --no-protel-ext\
    modulo_sensor.kicad_pcb
}

echo "Exportando SVG..."
export_svg

if [ $# -ne 0 ] && [  $1 == "-f" ]; then
	echo "Exportando .drl y .grb ..."
	export_drl
	export_grb
fi
