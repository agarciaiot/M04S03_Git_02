# MKL02Z32VFM4_UART_GPIO_ACCEL (Aplicación Modulo 04 Semana 03)

## Descripción:

_Control de Estado del LED RGB (GPIOB) de la FREESCALE FRDM-KL02Z mediante caracteres ingresados a través del puerto Serial (UART0), lectura de datos de posición del Acelerómetro (ACCEL) de tres Ejes MMA8451Q presente en la plataforma mediante caracteres referentes a ejes (x, y, z) más impresión en Terminal Serial del carácter ingresado. Esta es una implementación de prueba para el Módulo 4 del Diplomado de IoT, la optimización y lógica se basan en la propia experiencia del estudiante creador y la orientación del docente a cargo del módulo_

### Dinámica:

_El ingreso por teclado de los caracteres resultará en:_

* ‘R’, impresión por puerto serial del mensaje “Dato: R”, activación del Led RGB en Red (Rojo)

* ‘r’, impresión por puerto serial del mensaje “Dato: r”, desactivación del Led RGB en Red (Rojo)

* ‘G’, impresión por puerto serial del mensaje “Dato: G”, activación del Led RGB en Green (Verde)

* ‘g’, impresión por puerto serial del mensaje “Dato: g”, desactivación del Led RGB en Green (Verde)

* ‘B’, impresión por puerto serial del mensaje “Dato: B”, activación del Led RGB en Blue (Azul)

* ‘b', impresión por puerto serial del mensaje “Dato: b”, desactivación del Led RGB en Blue (Azul)

* ‘M' o ‘m’, impresión por puerto serial del mensaje “Dato: M” o “Dato: m”, impresión por puerto serial del mensaje “MMA8451Q Habilitado” si está habilitada el Acelerómetro o impresión del mensaje “MMA8451Q Error” en el caso contrario

* ‘X' o 'x', 'Y' o 'y', 'Z' o 'z', impresión por puerto serial del mensaje “Dato: ‘X’ o ‘Y’ o ‘Z’” o “Dato: ‘x’ o ‘y’ o ‘z’ ”, más impresión por puerto Serial del mensaje: “Valor equivalente en (g) para el eje ‘X’ o ‘Y’ o ‘Z’: '_dato calculado del acelerómetro_' ”

* 'Otros caracteres', impresión por puerto serial del mensaje “Dato: ‘Otros caracteres’”, Led RGB y lectura del acelerómetro sin cambios

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
