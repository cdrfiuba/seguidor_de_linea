kicad-cli pcb export svg --page-size-mode 2 --layers User.Drawings,F.Silkscreen,Edge.Cuts,F.Courtyard,F.Fab,F.Cu modulo_sensor.kicad_pcb
sed "s/C83434; fill-opacity:1.0000/C83434; fill-opacity:0.5000/g" < modulo_sensor.svg > aux.svg
sed "s/stroke:#000000; stroke-width:0.1500; stroke-opacity:1;/stroke:#000000; stroke-width:0.1500; stroke-opacity:0;/g" < aux.svg > front_preview.svg
kicad-cli pcb export svg --page-size-mode 2 --layers User.Drawings,B.Silkscreen,Edge.Cuts,B.Courtyard,B.Fab,B.Cu modulo_sensor.kicad_pcb
sed "s/4D7FC4; fill-opacity:1.0000/4D7FC4; fill-opacity:0.3500/g" < modulo_sensor.svg > bottom_preview.svg
rm modulo_sensor.svg aux.svg
