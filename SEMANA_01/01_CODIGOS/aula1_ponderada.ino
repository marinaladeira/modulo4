// Define o LED pin para fechar o circuito
int ledPin = 1;
int dotDuration = 250;
int dashDuration = 3 * dotDuration;
int flashGap = dotDuration;

void setup() {
  pinMode(ledPin, OUTPUT);
}

void loop() {
  // "S" em código morse são 3 flashs curtos
  flashDot(); flashDot(); flashDot();
  delay(dashDuration); // Gap between characters

  // "O" em código morse são 3 flashs longos
  flashDash(); flashDash(); flashDash();
  delay(dashDuration); // Gap between characters

  // Segundo "S"
  flashDot(); flashDot(); flashDot();
  delay(3 * dashDuration); // Gap between words
}

// Função para um flash curto
void flashDot() {
  digitalWrite(ledPin, HIGH);
  delay(dotDuration);
  digitalWrite(ledPin, LOW);
  delay(flashGap);
}

// Função para flash longo
void flashDash() {
  digitalWrite(ledPin, HIGH);
  delay(dashDuration);
  digitalWrite(ledPin, LOW);
  delay(flashGap);
}
