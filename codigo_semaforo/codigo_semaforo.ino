#define GREEN_LED_PIN   27
#define YELLOW_LED_PIN  33
#define RED_LED_PIN     16
#define BUZZER_PIN      17 // Define o pino do buzzer

class Led {
  private:
    byte pin;
  public:
    Led(byte pin){
      this->pin = pin;
      init();
    }

    void init() {
      pinMode(pin, OUTPUT);
      off();
    }

    void on() {
      digitalWrite(pin, HIGH);
    }

    void off() {
      digitalWrite(pin, LOW);
    }
};

Led GREEN_LED(GREEN_LED_PIN);
Led YELLOW_LED(YELLOW_LED_PIN);
Led RED_LED(RED_LED_PIN);

void setup() {
  pinMode(BUZZER_PIN, OUTPUT); // Configura o pino do buzzer como saída
}

void loop() {
  // - 6 segundos no vermelho
  GREEN_LED.off();
  YELLOW_LED.off();
  RED_LED.on();
  delay(6000);

  // - 2 segundos no amarelo
  YELLOW_LED.on();
  RED_LED.off();
  delay(2000);

  // - 2 segundos no verde
  GREEN_LED.on();
  YELLOW_LED.off();
  RED_LED.off();
  delay(2000);

  // - +2 segundos no verde com buzzer piscando (para pedestres terminarem a travessia)
  for (int i = 0; i < 2; i++) {
    GREEN_LED.off();
    digitalWrite(BUZZER_PIN, HIGH); // Liga o buzzer
    delay(500);
    
    GREEN_LED.on();
    digitalWrite(BUZZER_PIN, LOW); // Desliga o buzzer
    delay(500);
  }

  // - 2 segundos no amarelo
  YELLOW_LED.on();
  RED_LED.off();
  GREEN_LED.off();
  delay(2000);
}
