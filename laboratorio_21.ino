#define LED1_RED 5
#define LED1_GREEN 6
#define LED1_BLUE 7

#define LED2_RED 8 
#define LED2_GREEN 9  
#define LED2_BLUE 10

#define LED3_RED 11 
#define LED3_GREEN 12
#define LED3_BLUE 13

#define CONTROL_PIN 2  // Pin para el interruptor de encendido/apagado

void setup() {
  // Configurar los pines de LEDs como salida
  pinMode(LED1_RED, OUTPUT);
  pinMode(LED1_GREEN, OUTPUT);
  pinMode(LED1_BLUE, OUTPUT);
  
  pinMode(LED2_RED, OUTPUT);
  pinMode(LED2_GREEN, OUTPUT);
  pinMode(LED2_BLUE, OUTPUT);
  
  pinMode(LED3_RED, OUTPUT);
  pinMode(LED3_GREEN, OUTPUT);
  pinMode(LED3_BLUE, OUTPUT);

  pinMode(CONTROL_PIN, INPUT);  // Configurar el interruptor
  
  Serial.begin(9600);  // Iniciar el monitor serial
}

void setLedColors(int ledRedPin, int ledGreenPin, int ledBluePin, int r, int g, int b) {
  analogWrite(ledRedPin, r);
  analogWrite(ledGreenPin, g);
  analogWrite(ledBluePin, b);
}

void cicloSemaforos() {
  // Semáforo 1 en verde, los demás en rojo
  Serial.println("Semáforo 1: Verde, Semáforo 2: Rojo, Semáforo 3: Rojo");
  setLedColors(LED1_RED, LED1_GREEN, LED1_BLUE, 0, 255, 0);  // Verde en semáforo 1
  setLedColors(LED2_RED, LED2_GREEN, LED2_BLUE, 255, 0, 0);  // Rojo en semáforo 2
  setLedColors(LED3_RED, LED3_GREEN, LED3_BLUE, 255, 0, 0);  // Rojo en semáforo 3
  delay(2000);

  // Semáforo 2 en verde, los demás en rojo
  Serial.println("Semáforo 1: Rojo, Semáforo 2: Verde, Semáforo 3: Rojo");
  setLedColors(LED1_RED, LED1_GREEN, LED1_BLUE, 255, 0, 0);  // Rojo en semáforo 1
  setLedColors(LED2_RED, LED2_GREEN, LED2_BLUE, 0, 255, 0);  // Verde en semáforo 2
  setLedColors(LED3_RED, LED3_GREEN, LED3_BLUE, 255, 0, 0);  // Rojo en semáforo 3
  delay(2000);

  // Semáforo 3 en verde, los demás en rojo
  Serial.println("Semáforo 1: Rojo, Semáforo 2: Rojo, Semáforo 3: Verde");
  setLedColors(LED1_RED, LED1_GREEN, LED1_BLUE, 255, 0, 0);  // Rojo en semáforo 1
  setLedColors(LED2_RED, LED2_GREEN, LED2_BLUE, 255, 0, 0);  // Rojo en semáforo 2
  setLedColors(LED3_RED, LED3_GREEN, LED3_BLUE, 0, 255, 0);  // Verde en semáforo 3
  delay(2000);
}

void intermitenteAmarillo() {
  // Todos los semáforos en amarillo intermitente
  Serial.println("Semáforos intermitentes en amarillo");
  setLedColors(LED1_RED, LED1_GREEN, LED1_BLUE, 255, 255, 0);  // Amarillo en semáforo 1
  setLedColors(LED2_RED, LED2_GREEN, LED2_BLUE, 255, 255, 0);  // Amarillo en semáforo 2
  setLedColors(LED3_RED, LED3_GREEN, LED3_BLUE, 255, 255, 0);  // Amarillo en semáforo 3
  delay(1000);

  // Apagar LEDs
  setLedColors(LED1_RED, LED1_GREEN, LED1_BLUE, 0, 0, 0);
  setLedColors(LED2_RED, LED2_GREEN, LED2_BLUE, 0, 0, 0);
  setLedColors(LED3_RED, LED3_GREEN, LED3_BLUE, 0, 0, 0);
  delay(1000);
}

void loop() {
  int controlState = digitalRead(CONTROL_PIN);  // Leer el estado del interruptor
  
  if (controlState == HIGH) {
    // Si el interruptor está encendido, iniciar ciclo de semáforos
    cicloSemaforos();
  } else {
    // Si el interruptor está apagado, mostrar intermitente amarillo
    intermitenteAmarillo();
  }
}
