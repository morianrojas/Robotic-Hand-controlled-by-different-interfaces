# Robotic hand controlled by different interfaces
Proyecto de 10 cuatrimestre en ingenieria en mecatronica de la Universidad Tecnologica de Tijuana.
El nombre asignado al proyecto es "Prototipo de mano robótica controlada por diferentes interfaces".
Se diseñó una mano robótica con impresión 3D, con 12 grados de libertad; y controlada por medio de un exoesqueleto,
un HMI, y control por gesturas a traves de una camara web.   
# Estudiantes: Moriancumer Rojas Higuera, Raul Dionicio de la Cruz
# Presentacion
Control por medio de gesturas a traves de una camara web:
Usando Mediapipe con Python se elaboró el control por medio de una camara web

![gestures hand master](https://user-images.githubusercontent.com/82742790/115182570-09327000-a08f-11eb-8371-044b759c23e6.gif)

![gesture hand slave](https://user-images.githubusercontent.com/82742790/115182590-14859b80-a08f-11eb-86ae-44aebf3ac0c3.gif)

![gesture hand balon](https://user-images.githubusercontent.com/82742790/115182617-2109f400-a08f-11eb-962e-164def2e56a7.gif)

![gestures hand naranja](https://user-images.githubusercontent.com/82742790/115182632-26673e80-a08f-11eb-9a16-1443bdccc53b.gif)

![gestures hand huevo](https://user-images.githubusercontent.com/82742790/115182644-2b2bf280-a08f-11eb-8871-a444a09ac431.gif)

Control por medio de exoesqueleto:

Se diseño un exoesqueleto en Solid Works, y se armó con un total de 95 piezas, 104 tornillos y 12 potenciometros.

![movimiento exoesqueleto](https://user-images.githubusercontent.com/82742790/115182776-6a5a4380-a08f-11eb-9772-e4c7208a5a15.gif)

![exo mano movimientos](https://user-images.githubusercontent.com/82742790/115182670-367f1e00-a08f-11eb-87f2-3276b94910a5.gif)

![exo balon](https://user-images.githubusercontent.com/82742790/115182795-70e8bb00-a08f-11eb-9748-347191d4e2b5.gif)

![exo huevo](https://user-images.githubusercontent.com/82742790/115182809-77773280-a08f-11eb-877f-402088445121.gif)

Control y monitoreo por medio de HMI:
Se elaboro un HMI en LabVIEW, con un total de 6 pestañas
Iniciando con la primer pestaña de usuario y contraseña
![HMI usuario](https://user-images.githubusercontent.com/82742790/115182844-8d84f300-a08f-11eb-8da4-e3381df5c716.gif)
En la pestaña principal, se observan animaciones de la mano robótica, indicadores del estado del sistema, indicadores de alarmas, 
indicadores de los valores que llegan por el puerto serial.
![HMI encendido](https://user-images.githubusercontent.com/82742790/115182855-937ad400-a08f-11eb-8377-4205a007d89b.gif)
Una vez encendido, se inicia por defecto en modo lectura, si se da click en el boton de control, los indicadores de estado cambian a color amarillo
y los sliders se habilitan. Entonces el usuario tiene control de la mano robotica desde el HMI. 
![HMI control](https://user-images.githubusercontent.com/82742790/115182870-98d81e80-a08f-11eb-8e77-fee339e77634.gif)
En la siguiente pestaña, se observa una grafica con las señales de los valores de voltaje y grados de los motores. 
![HMI grafica comb](https://user-images.githubusercontent.com/82742790/115182892-a42b4a00-a08f-11eb-9517-4715e59f56b0.gif)
En la siguiente pestaña, se observa una grafica exclusiva para las señales de los movimientos verticales de la mano robotica.
![HMI grafica vert](https://user-images.githubusercontent.com/82742790/115182911-aa212b00-a08f-11eb-9049-3a928799deeb.gif)
En la siguiente pestaña, se observa una grafica con las mismas operaciones de la pestaña anterior. Se 
![HMI grafica hor](https://user-images.githubusercontent.com/82742790/115182924-adb4b200-a08f-11eb-8ddf-2337062b6147.gif)

![HMI alarmas](https://user-images.githubusercontent.com/82742790/115182941-b6a58380-a08f-11eb-87bf-97b22d65b543.gif)

![HMI fechas](https://user-images.githubusercontent.com/82742790/115182952-bc9b6480-a08f-11eb-8d28-1ca9529a7a6c.gif)

![HMI movements](https://user-images.githubusercontent.com/82742790/115182973-c624cc80-a08f-11eb-9ec5-99ccf357fa92.gif)
