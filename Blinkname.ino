void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(9600);
}


void blinkMorse(char letter) {
  const char* morse;

  switch (letter) {
    case 'G': morse = "--."; break;
    case 'A': morse = ".-"; break;
    case 'U': morse = "..-"; break;
    case 'R': morse = ".-."; break;
    case 'V': morse = "...-"; break;
    case 'I': morse = ".."; break;
    default: morse = ""; break;
  }

  for (int i = 0; morse[i] != '\0'; i++) {
    if (morse[i] == '.') {
      digitalWrite(LED_BUILTIN, HIGH);
      delay(250); 
    } else if (morse[i] == '-') {
      digitalWrite(LED_BUILTIN, HIGH);
      delay(750); 
    }
    digitalWrite(LED_BUILTIN, LOW);
    delay(250); 
  }

  delay(1000); 
}

void loop() {
  char name[] = "GAURAVI";

  for (int i = 0; i < sizeof(name) - 1; i++) {
    blinkMorse(name[i]);
  }

  delay(3000); 
}
