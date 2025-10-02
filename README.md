# ESP32_WIFI
Se implementó en el ESP32 la librería WiFiManager, la cual permite gestionar de manera dinámica la conexión WiFi del dispositivo. En caso de no encontrar una red previamente configurada o cuando se desee cambiar de red, el ESP32 levanta un Access Point (AP) con un portal cautivo, desde el cual el usuario puede seleccionar y guardar nuevas credenciales de forma sencilla, sin necesidad de reprogramar el dispositivo.

Endpoints con Postamn:
Se realizo los endpoints con postman donde se averiguo los que se realizaban:

En esta primer imagen con un endpoint get se trae el inicio para obtener el  menu :
![Texto alternativo](./assets/imagen.png)

En el segundo se realiza un metodo Post para enviar las credenciales WIFI para que se guarden y configurar el esp32 por lo que se decide por el body enviar estas mismas:
![Texto alternativo](./assets/imagen.png)

En la tercera imagen aparece metodo get para llevar a cabo el reinicio de las credenciales.
![Texto alternativo](./assets/imagen.png)


Mecanismo Restablecer:
Se establecio una funcion de  cuando ya se este conectado a una red wifi y se quiera activar el hospot para restablecer la conexion y poderse conectar a otra conexion, se puede llevar a cabo desde el puerto seria digitando  la letra C de este modo se activa el hospot para que el usuario pueda oprimir el boton rojo como se ve en la imagen a continuacion y realizar de nuevo las conexiones wifi disponibles:
![Texto alternativo](./assets/imagen.png)

anexo conversacion IA: 
https://chatgpt.com/share/68de7b1f-827c-8000-ac83-6d0001ce67e9
