#define GREEN_LED_PIN   2
#define YELLOW_LED_PIN  3
#define RED_LED_PIN     4

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

  // - +2 segundos no verde (simulando um tempo adicional para pedestres terminarem a travessia)
  for (int i = 0; i <= 2; i++) {
    GREEN_LED.on();
    delay(500);
    GREEN_LED.off();
    delay(500);
    i++;
  }

  // - 2 segundos no amarelo
  YELLOW_LED.on();
  RED_LED.off();
  GREEN_LED.off();
  delay(2000);

}
