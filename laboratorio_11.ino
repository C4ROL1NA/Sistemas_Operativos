#define LED_VERDE 11
#define LED_ROJO 12
#define LED_AMARILLO 13

void setup() {

  pinMode(LED_VERDE, OUTPUT);
  pinMode(LED_ROJO, OUTPUT);
  pinMode(LED_AMARILLO, OUTPUT);

  Serial.begin(9600);
  
  
  Serial.println("MENU PRINCIPAL");
  Serial.println("[1]. Encender luz verde");
  Serial.println("[2]. Apagar luz verde");
  Serial.println("[3]. Encender luz roja");
  Serial.println("[4]. Apagar luz roja");
  Serial.println("[5]. Encender luz amarilla");
  Serial.println("[6]. Apagar luz amarilla");
  Serial.println("[7]. Encender todas las luces");
  Serial.println("[8]. Apagar todas las luces");
  Serial.println("[9]. Modo intermitente");
}

void loop() {
  if (Serial.available() > 0) { 
  char opt = Serial.read();

    switch (opt) {
      case '1': // Encender luz verde
        digitalWrite(LED_VERDE, HIGH);
        digitalWrite (LED_ROJO, LOW);
        digitalWrite (LED_AMARILLO, LOW);

      Serial.println("Luz verde encendida");
        break;
      case '2': // Apagar luz verde
        digitalWrite(LED_VERDE, LOW);
        Serial.println("Luz verde apagada");
        break;
      case '3': // Encender luz roja
        digitalWrite(LED_ROJO, HIGH);
        digitalWrite (LED_VERDE, LOW);
        digitalWrite (LED_AMARILLO, LOW);
      
        Serial.println("Luz roja encendida");
        break;
      case '4': // Apagar luz roja
        digitalWrite(LED_ROJO, LOW);
        Serial.println("Luz roja apagada");
        break;
      case '5': // Encender luz amarilla
        digitalWrite(LED_AMARILLO, HIGH);
      digitalWrite(LED_ROJO, LOW);
        digitalWrite (LED_VERDE, LOW);
        Serial.println("Luz amarilla encendida");
        break;
      case '6': // Apagar luz amarilla
        digitalWrite(LED_AMARILLO, LOW);
        Serial.println("Luz amarilla apagada");
        break;
      case '7': // Encender todas las luces
        encenderTodas();
        Serial.println("Todas las luces encendidas");
        break;
      case '8': // Apagar todas las luces
        apagarTodas();
        Serial.println("Todas las luces apagadas");
        break;
      case '9': // Modo intermitente
        modoIntermitente();
        Serial.println("Modo intermitente activado");
        break;
      default:
        Serial.println("Comando no reconocido");
        break;
    }
  }
}

// Función para encender todas las luces
void encenderTodas() {
  digitalWrite(LED_VERDE, HIGH);
  digitalWrite(LED_ROJO, HIGH);
  digitalWrite(LED_AMARILLO, HIGH);
}

// Función para apagar todas las luces
void apagarTodas() {
  digitalWrite(LED_VERDE, LOW);
  digitalWrite(LED_ROJO, LOW);
  digitalWrite(LED_AMARILLO, LOW);
}

// Función para activar el modo intermitente
void modoIntermitente() {
  for (int i = 0; i < 5; i++) {  // Parpadea 5 veces
    encenderTodas();
    delay(500); // Espera 0.5 segundos
    apagarTodas();
    delay(500); // Espera 0.5 segundos
  }
}