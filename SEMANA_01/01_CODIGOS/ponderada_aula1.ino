// Define the LED pin
int ledPin = 1;

// Define the duration of a dot (in milliseconds)
int dotDuration = 250;

// Define the duration of a dash (3 times the dot duration)
int dashDuration = 3 * dotDuration;

// Define the duration between individual flashes
int flashGap = dotDuration;

void setup() {
  // Initialize the LED pin as an output
  pinMode(ledPin, OUTPUT);
}

void loop() {
  // "S" in Morse code (3 short flashes)
  flashDot(); flashDot(); flashDot();
  delay(dashDuration); // Gap between characters

  // "O" in Morse code (3 long flashes)
  flashDash(); flashDash(); flashDash();
  delay(dashDuration); // Gap between characters

  // Second "S" in Morse code (3 short flashes)
  flashDot(); flashDot(); flashDot();
  delay(3 * dashDuration); // Gap between words
}

// Function to flash a dot (short blink)
void flashDot() {
  digitalWrite(ledPin, HIGH);
  delay(dotDuration);
  digitalWrite(ledPin, LOW);
  delay(flashGap);
}

// Function to flash a dash (long blink)
void flashDash() {
  digitalWrite(ledPin, HIGH);
  delay(dashDuration);
  digitalWrite(ledPin, LOW);
  delay(flashGap);
}
