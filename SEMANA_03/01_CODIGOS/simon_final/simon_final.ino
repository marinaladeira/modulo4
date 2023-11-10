#include <Arduino.h>

// Definição dos pinos
const int ledPins[] = {2, 3, 4, 5};
const int buttonPins[] = {10, 8, 11, 9};
const int resetPin = 13;

// Configurações do jogo
const int maxLevels = 5;
int gameSequence[maxLevels];
int playerSequence[maxLevels];
int currentLevel = 0;
int blinkSpeed = 1000;
bool resetFlag = false;

// Configuração inicial
void setup() {
  for (int i = 0; i < sizeof(ledPins) / sizeof(ledPins[0]); i++) {
    pinMode(ledPins[i], OUTPUT);
    pinMode(buttonPins[i], INPUT_PULLUP);
  }
  pinMode(resetPin, INPUT_PULLUP);
}

// Loop principal
void loop() {
  if (resetFlag) {
    initializeGame();
    resetFlag = false;
  }

  if (currentLevel == 0) {
    if (!digitalRead(resetPin)) {
      resetFlag = true;
    }
  } else {
    if (currentLevel <= maxLevels) {
      displaySequence();
      getPlayerSequence();
    } else {
      initializeGame();
    }
  }
}

// Inicializa o jogo
void initializeGame() {
  currentLevel = 1;
  randomSeed(analogRead(0));
  for (int i = 0; i < maxLevels; i++) {
    gameSequence[i] = random(0, 4);
  }
  delay(900);
}

// Mostra a sequência de LEDs
void displaySequence() {
  for (int i = 0; i < currentLevel; i++) {
    int ledToLight = gameSequence[i];
    digitalWrite(ledPins[ledToLight], HIGH);
    delay(blinkSpeed);
    digitalWrite(ledPins[ledToLight], LOW);
    delay(200);

    if (!digitalRead(resetPin)) {
      resetFlag = true;
      return;
    }
  }
  delay(300);
}

// Obtém a sequência do jogador
void getPlayerSequence() {
  int playerIndex = 0;
  while (playerIndex < currentLevel) {
    for (int i = 0; i < sizeof(buttonPins) / sizeof(buttonPins[0]); i++) {
      if (!digitalRead(buttonPins[i])) {
        playerSequence[playerIndex] = i;
        indicateButtonPress(i);
        playerIndex++;
        break; // Sair do for para evitar múltiplas leituras
      }
    }
  }
  validatePlayerSequence();
}

// Acende e apaga o LED correspondente ao botão pressionado
void indicateButtonPress(int buttonIndex) {
  digitalWrite(ledPins[buttonIndex], HIGH);
  delay(200);
  digitalWrite(ledPins[buttonIndex], LOW);
  delay(200);
}

// Valida a sequência inserida pelo jogador
void validatePlayerSequence() {
  for (int i = 0; i < currentLevel; i++) {
    if (playerSequence[i] != gameSequence[i]) {
      awaitResetPress();
      return;
    }
  }
  currentLevel++;
  delay(500);
}

// Aguarda o pressionamento do botão de reset
void awaitResetPress() {
  while (digitalRead(resetPin)) {
    // Espera ativa
  }
  initializeGame();
}
