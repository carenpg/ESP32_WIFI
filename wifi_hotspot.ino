#include <WiFi.h>
#include <WiFiManager.h>  

#define RESET_PIN 0  // Botón físico para borrar credenciales (GPIO0)

WiFiManager wm;

void setup() {
  Serial.begin(115200);
  pinMode(RESET_PIN, INPUT_PULLUP);

  // Si se mantiene presionado al arrancar -> borrar credenciales
  if (digitalRead(RESET_PIN) == LOW) {
    Serial.println("Botón presionado -> borrando credenciales...");
    wm.resetSettings();  // Borra credenciales guardadas
    delay(1000);
  }

  WiFi.mode(WIFI_STA);  // siempre en modo estación

  // Intentar conectarse a la red conocida
  if (!wm.autoConnect("ESP32-Setup", "12345678")) {
    Serial.println("No se pudo conectar, abriendo AP para configurar...");
    // Esto queda esperando a que configures una red desde tu celular
  }

  Serial.println("Conexión exitosa!");
  Serial.print("SSID: ");
  Serial.println(WiFi.SSID());
  Serial.print("IP: ");
  Serial.println(WiFi.localIP());
}

void loop() {
  // Ejemplo: si pierde conexión, abre de nuevo el AP automáticamente
  if (WiFi.status() != WL_CONNECTED) {
    Serial.println("WiFi perdida, iniciando portal de configuración...");
    wm.startConfigPortal("ESP32-Setup", "12345678");
    Serial.println("Reconectado!");
  }

  if (Serial.available()) {
  char c = Serial.read();
  if (c == 'c') { // si envías "c" por Serial
    Serial.println("Forzando cambio de red...");
    wm.startConfigPortal("ESP32-Setup", "12345678");
  }


  // Tu código de aplicación aquí
  delay(5000);  // evitar saturar el serial
}