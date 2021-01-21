# MKL02Z32VFM4_UART_GPIO_ACCEL (Aplicación Modulo 04 Semana 03)

## Descripción:

_Control de Estado del LED RGB (GPIOB) de la FREESCALE FRDM-KL02Z mediante caracteres ingresados a través del puerto Serial (UART0), lectura de datos de posición del Acelerómetro (ACCEL) de tres Ejes MMA8451Q presente en la plataforma mediante caracteres referentes a ejes (x, y, z) más impresión en Terminal Serial del carácter ingresado. Esta es una implementación de prueba para el Módulo 4 del Diplomado de IoT, la optimización y lógica se basan en la propia experiencia del estudiante creador y la orientación del docente a cargo del módulo_

### Dinámica:

_El ingreso por teclado de los caracteres resultará en:_

* Ingreso de ‘R’, impresión por puerto serial del mensaje “Dato ingresado: R”, activación del Led RGB en Red (Rojo)

* Ingreso de ‘r’, impresión por puerto serial del mensaje “Dato ingresado: r”, desactivación del Led RGB en Red (Rojo)

* Ingreso de ‘G’, impresión por puerto serial del mensaje “Dato ingresado: G”, activación del Led RGB en Green (Verde)

* Ingreso de ‘g’, impresión por puerto serial del mensaje “Dato ingresado: g”, desactivación del Led RGB en Green (Verde)

* Ingreso de ‘B’, impresión por puerto serial del mensaje “Dato ingresado: B”, activación del Led RGB en Blue (Azul)

* Ingreso de ‘b', impresión por puerto serial del mensaje “Dato ingresado: b”, desactivación del Led RGB en Blue (Azul)

* Ingreso de ‘M' o ‘m’, impresión por puerto serial del mensaje “Dato: M” o “Dato: m”, impresión por puerto serial del mensaje “MMA8451Q Encontrado!” si está habilitada el Acelerómetro o impresión del mensaje “MMA8451Q Error!” en el caso contrario

* Ingreso de ‘X' o 'x', 'Y' o 'y', 'Z' o 'z', impresión por puerto serial del mensaje “Dato: (‘X’ o ‘Y’ o ‘Z’)” o “Dato ingresado: (‘x’ o ‘y’ o ‘z’)”, más impresión por puerto Serial del mensaje: "ACCEL: (EJE)_MSB: (valor en eje MSB en Hex)  (EJE))_LSB: (valor en eje LSB en Hex), Calculo en (EJE)) = (Valor entero en mg) mg”

* Ingreso de ‘Otros caracteres', impresión por puerto serial del mensaje “Dato: ‘Otros caracteres’”, Led RGB y lectura del acelerómetro sin cambios

* Si no existe conexión serial o no se lee el dato se imprimirá el mensaje "Data Error"

## Construcción:

### Plataforma:

_Para la programación y ejecución pruebas con esta aplicación, se usó la plataforma:_

* [FRDM-KL02Z: Freedom Development Platform for the Kinetis® KL02 Family](https://www.nxp.com/design/development-boards/freedom-development-boards/mcu-boards/freedom-development-platform-for-the-kinetis-kl02-family:FRDM-KL02Z) - MCU Board (KL02Z) | Utra-Low-Power

** [MMA8451Q, Accelerometer, I2C, 1.91-3.6V, XYZ, 2/4/8g](https://www.nxp.com/products/sensors/motion-sensors/3-axis/2g-4g-8g-low-g-14-bit-digital-accelerometer:MMA8451Q) – Acelerómetro Incluido en el **MCU Board | FRDM-KL02Z**

### Software:

_Las herramientas software utilizadas en la construcción se basan en:_

* [MCUXpresso IDE v11.2.1 [Build 4149] [2020-10-07]](https://www.nxp.com/design/software/development-software/mcuxpresso-software-and-tools-/mcuxpresso-integrated-development-environment-ide:MCUXpresso-IDE) - IDE usado para la construcción, programación, depuración y pruebas
* [SourceTree 3.4.1 [2020-12-31]](https://www.sourcetreeapp.com/) - Git GUI usado para el control de versiones

_Otras herramientas tipo Serial Terminal GUI para pruebas externas al IDE_
* [Docklight v2.3.26](https://docklight.de/downloads/)
* [QCOM v1.6 (15.01.16.10.100) [Rev. 1.1] [2015-03-30]](https://www.quectel.com/product/ec25.htm)

### Documentación y Notas:

* [FRDM-KL02Z - User Manua (REV 0)l](https://www.nxp.com/docs/en/user-guide/FRDMKL02ZUM.pdf) - Manual de Usuario para la FRDM-LK02Z

* [FRDM-KL02Z Schematics (REV C)](https://www.nxp.com/downloads/en/schematics/FRDM-KL02Z_SCH_REV_C.pdf) - Esquemático de la FRDM-LK02Z

* [Kinetis KL02: 48MHz Cortex-M0+ 8-32KB Flash (16-32 pin) (REV 3.1)](https://www.nxp.com/docs/en/reference-manual/KL02P32M48SF0RM.pdf) - Manual de Referencias para la Sub-Familia KL02 **(MKL02Z32VFM4(R))**

* [MMA8451Q, 3-Axis, 14-bit/8-bit Digital Accelerometer - Data Sheet (REV 10.3)](https://www.nxp.com/docs/en/data-sheet/MMA8451Q.pdf) - Datasheet del MMA8451Q

* [AN4069, Offset Calibration of the MMA8451, 2, 3Q - Application Notes (REV 1)](https://www.nxp.com/docs/en/application-note/AN4069.pdf) - Nota de Aplicación sobre Calibración para el MMA8451Q

* [AN4076, Data Manipulation and Basic Settings of the MMA8451, 2, 3Q - Application Notes (REV 1)](https://www.nxp.com/docs/en/application-note/AN4076.pdf) - Nota de Aplicación sobre la Conversión de datos y Configuración del MMA8451Q

## Librerías utilizadas/requeridas:

_Las que están incluidas en el repositorio y las librerías internas de la placa de desarrollo_

## Pre-requisitos:

* Instalación previa del programa **MCUXpresso IDE de NXP** en la versión referenciada

* Consultar de la documentación de desarrollo y gestión sobre el programa ([MCUXpresso Integrated Development Environment (IDE)](https://www.nxp.com/design/software/development-software/mcuxpresso-software-and-tools-/mcuxpresso-integrated-development-environment-ide:MCUXpresso-IDE?&tab=Documentation_Tab&linkline=Users-Guide))

* Instalación en el programa del SDK necesario para le ejecución del proyecto con configuración activa ([MCUXpresso Software Development Kit (SDK)](https://www.nxp.com/design/software/development-software/mcuxpresso-software-and-tools-/mcuxpresso-software-development-kit-sdk:MCUXpresso-SDK))

## Instalación:

_Para descargar del respositorio en archivo *.rar se recomienda seguir los pasos siguientes para prevenir errores:_

* Descomprimir el archivo *.rar en una ubicación conocida y copiar la ruta de acceso al espacio de trabajo (por simplicidad se recomienda la ruta del sistema: C:'\'"nombre carpeta repositorio en disco"'\')

* Iniciar el Programa **MCUXpresso IDE** y en el lanzador de espacio de trabajo _(Workspace)_ asignar la ruta anterior, si ya posee una ruta de espacio de trabajo por defecto iniciar el programa en esa ruta y en la barra de menús ir a _File > Switch Workspace > Other_ digitar la ruta asignada lanzar en _Launch_, el programa se reiniciará y se lanzará en la ruta asignada como Workspace

* Para importar el proyecto en la barra de menús ir a _File > Import_ en la ventana _Import_ seleccionar el desplegable _General > Existing Projects into Workspace_ en _Browse..._ seleccionar la carpeta del proyecto (MKL02Z32VFM4_UART_GPIO_ACCEL), aparecerá en la lista en el cuadro Projects: seleccionarlo y luego aplicar en _Finish_, se iniciará la carga de los archivos y sdk necesarios para la ejecución

* Una vez cargado el proyecto presione _Ctrl+B_ para iniciar la primera depuración y comprobar que no existan errores.

## Ejecución de Pruebas:

_Se ejecutaron pruebas de envío/recepción de datos sobre los terminales Seriales:_

* MCUXpresso IDE v11.2.1 [Evidencia](https://youtu.be/dLQwkH8vXfA)

## Autores y Colaboradores:

* **Álvaro García** - *Trabajo Inicial* - [agarciaiot](https://github.com/agarciaiot)
* **Ernesto Rincón** - *Documentación y Asesoría* - [ErnestoARC](https://github.com/ErnestoARC)

## Licencia:

Este proyecto está bajo la Licencia gratuita (MIT License) - mira el archivo [LICENSE.md](https://github.com/agarciaiot/M04S03_Git_02/blob/main/LICENSE) para detalles

Desarrollado por [agarciaiot](https://github.com/agarciaiot) para el Diplomado de IoT (Internet of Things, en Español: _**Internet de las Cosas**_) del Programa de [Ingeniería Electrónica en la Universidad del Magdalena](https://www.unimagdalena.edu.co/presentacionPrograma/Programa/1005).
