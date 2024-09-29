kicad-cli pcb export svg --page-size-mode 2 --layers User.1,F.Silkscreen,Edge.Cuts,F.Courtyard,F.Fab,F.Cu modulo_sensor.kicad_pcb
sed "s/C83434; fill-opacity:1.0000/C83434; fill-opacity:0.5000/g" < modulo_sensor.svg > aux.svg
sed "s/stroke:#000000; stroke-width:0.1500; stroke-opacity:1;/stroke:#000000; stroke-width:0.1500; stroke-opacity:0;/g" < aux.svg > preview.svg
rm modulo_sensor.svg aux.svg
