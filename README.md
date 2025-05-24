# Robot Seguidor de Línea

Test de seguidor de línea para competiciones.
Nombre pendiente.

## Estructura del proyecto
Boceto de la estructura del proyecto

```bash
.
├── placa_sensor
│   ├── kicad_sch
│   └── kicad_pcb
├── placa_seguidor
│   ├── kicad_sch
│   └── kicad_pcb
├── modelo
│   └── seguidor.FCStd
├── include
│   ├── file1.h
│   └── file2.h
├── src
│   ├── file1.ino
│   └── file2.ino
├── res
│   ├── datasheets.pdf
│   ├── images.png
│   └── referencias o links
└── README.md
```

## Requisitos
 - 20cm largo x 14cm de ancho x 10cm de alto
 - Area mínima de 23mm x 14mm. Visible. No pueden ser secciones de la batería.
 - No control remoto, o que solo de la orden de salida
 - Indicador luminoso (fijo o intermitente) que muestra cuando el robot inicia a correr.
 - Ruedas sin adherentes

## TODOs
 - ~~Rediseñar la placa de sensores (corregir errores) y mandar al lci~~
 - ~~Puente H~~
 - ~~Arduino Nano o ATmega328~~ y programarlo
 - ~~Comprar Placa Experimental~~
 - ~~Elegir batería ~~
 - Hacer un diagrama tal vez de como seguir el proyecto
 - ~~Hacér una bitácora~~ (subirla al repo?)
 - Agregar pagina de documentación (KiBot)
 - ~~Agregar una lista de compras que puedan editar todos~~
 - ~~Terminar de Soldar/limpiar modulo de sensores chequeando continuidad (Ciin lo hace el jueves)~~
 - ~~Probar modulo se sensores con arduino (Armar código de prueba) ~~
 - Comprar Resistencias, capacitores (1206), diodos schottsky, hembra y macho (90 grados)
 - Soldar puente h anterior para probar
 - Medir las ruedas/bandas de caucho que se usará en la compe
 - Ajustar el modelo 3D del interior de la rueda
 - Soldar placa

## Artículos pendientes
 - 4 Capacitores 100nf (Puente H)
 - 8 x Diodos Schottsky 1N4007  (Puente H)
 - 1R de 1K y 1 de 330 SMD (1206)
 - 1 (+1) 74HC14 Schmitt Trigger THT
 - 2 DIP14
