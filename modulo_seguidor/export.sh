kicad-cli pcb export pdf modulo_seguidor.kicad_pcb \
--layers "B.Cu" \
--black-and-white \
--drill-shape-opt 2

kicad-cli pcb export svg modulo_seguidor.kicad_pcb\
 --layers "F.Cu,B.Cu,Edge.Cuts,F.Silkscreen,B.Silkscreen,F.Paste,B.Paste,B.Adhesive,B.Mask,User.Drawings"\
 --exclude-drawing-sheet
