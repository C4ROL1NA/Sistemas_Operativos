
// Declaración de los pines para los LEDs

//semaforo uno
int s1_rojo = 2;
int s1_amarillo = 3;
int s1_verde = 4;

//semaforo dos
int s2_rojo = 5;
int s2_amarillo = 6;
int s2_verde = 7;

//semaforo tres
int s3_rojo = 8;
int s3_amarillo = 9;
int s3_verde = 10;

//semaforo cuatro
int s4_rojo = 11;
int s4_amarillo = 12;
int s4_verde = 13;

void setup() {
    // Configuración de los pines como salida
    pinMode(s1_rojo, OUTPUT);
    pinMode(s1_amarillo, OUTPUT);
    pinMode(s1_verde, OUTPUT);
  
    pinMode(s2_rojo, OUTPUT);
    pinMode(s2_amarillo, OUTPUT);
    pinMode(s2_verde, OUTPUT);
  
    pinMode(s3_rojo, OUTPUT);
    pinMode(s3_amarillo, OUTPUT);
    pinMode(s3_verde, OUTPUT);
  
    pinMode(s4_rojo, OUTPUT);
    pinMode(s4_amarillo, OUTPUT);
    pinMode(s4_verde, OUTPUT);
    
                             
}

void loop() {
  
    // Fase 1: Semáforo 1 en verde los demas en rojo(5 segundos)
    digitalWrite(s1_verde, HIGH); // Semáforo 1 verde 
    digitalWrite(s2_rojo, HIGH); // Semáforo 2 rojo 
    digitalWrite(s3_rojo, HIGH); //semaforo 3 rojo
    digitalWrite(s4_rojo, HIGH); //semaforo 4 rojo
    delay(5000); // Espera 5 segundos

    // Apagar rojo y verde
    digitalWrite(s1_verde, LOW); // Semáforo 1 rojo apagado
    digitalWrite(s2_rojo, LOW); // Semáforo 2 verde apagado

    // Fase 2: Ambos semáforos en amarillo (2 segundos)
    digitalWrite(s1_amarillo, HIGH); // Semáforo 1 amarillo encendido
    digitalWrite(s2_amarillo, HIGH); // Semáforo 2 amarillo encendido
    delay(2000); // Espera 2 segundos

    // Apagar amarillo
    digitalWrite(s1_amarillo, LOW); // Semáforo 1 amarillo apagado
    digitalWrite(s2_amarillo, LOW); // Semáforo 2 amarillo apagado

    // Fase 3: Semáforo 1 en verde, semáforo 2 en rojo (5 segundos)
    digitalWrite(s1_rojo, HIGH); // Semáforo 1 verde encendido
    digitalWrite(s2_verde, HIGH); // Semáforo 2 rojo encendido
    delay(5000); // Espera 5 segundos
  
  
  	// Apagar rojo y verde
    digitalWrite(s2_verde, LOW); // Semáforo 2 rojo apagado
    digitalWrite(s3_rojo, LOW); // Semáforo 3 verde apagado
  
  	//Fase 4: semaforo dos cambia con semaforo 3
  	digitalWrite(s2_amarillo, HIGH); // Semáforo 2 amarillo encendido
    digitalWrite(s3_amarillo, HIGH); // Semáforo 3 amarillo encendido
    delay(2000); // Espera 2 segundos
  	
  	// Apagar amarillo
    digitalWrite(s2_amarillo, LOW); // Semáforo 2 amarillo apagado
    digitalWrite(s3_amarillo, LOW); // Semáforo 3 amarillo apagado
  
  	// Fase 5: Semáforo 3 en verde, semáforo 2 en rojo (5 segundos)
    digitalWrite(s2_rojo, HIGH); // Semáforo 1 verde encendido
    digitalWrite(s3_verde, HIGH); // Semáforo 2 rojo encendido
    delay(5000); // Espera 5 segundos
  
  	//Fase 6: cambio de semaforo 3 y 4
  	digitalWrite(s3_verde, LOW);
  	digitalWrite(s4_rojo, LOW);
  
  	digitalWrite(s3_amarillo, HIGH);
  	digitalWrite(s4_amarillo, HIGH);
  	delay(2000);
  
  	digitalWrite(s3_amarillo, LOW);
  	digitalWrite(s4_amarillo, LOW);
  
  	digitalWrite(s3_rojo, HIGH);
  	digitalWrite(s4_verde, HIGH);
  	delay(5000);
  
  	digitalWrite(s4_verde, LOW);
    digitalWrite(s1_rojo, LOW);
  	digitalWrite(s1_amarillo, HIGH);
  	digitalWrite(s4_amarillo, HIGH);
  	delay(2000);
  
  	digitalWrite(s1_amarillo, LOW);
  	digitalWrite(s4_amarillo, LOW);

    
}

