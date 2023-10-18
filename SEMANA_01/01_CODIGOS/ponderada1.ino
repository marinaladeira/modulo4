const int LED_PIN1 = 1;  // Define o LED pin como 1

void setup() {
    pinMode(LED_PIN1, OUTPUT);  
}

void loop() {
    digitalWrite(LED_PIN1, HIGH);  // Liga o led 
    delay(500);                    //Espera 500 milisegundos
    digitalWrite(LED_PIN1, LOW);   // Desliga o LED 
    delay(500);                    // Espera mais 500 milisegundos
}
