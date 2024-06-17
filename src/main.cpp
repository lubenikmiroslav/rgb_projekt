#include <Arduino.h>
#include <IRremote.hpp>

#define IR_USE_AVR_TIMER 1
#define PIN 12
#define ENTER 4127850240
#define CERVENA 5
#define ZELENA 6
#define MODRA 9

unsigned long kody[] = {
  3910598400, // 0
  4077715200, // 1
  3877175040, // 2
  2707357440, // 3
  4144561920, // 4
  3810328320, // 5
  2774204160, // 6
  3175284480, // 7
  2907897600, // 8
  3041591040, // 9
};

String aktualniVstup = ""; // retezec pro ukladani zadanych cisel
int aktualniLed = 0;

const int velikostKodu = sizeof(kody) / sizeof(kody[0]); // velikost pole "kody"

String getReceivedNumber(unsigned long data) { // funkce na prevod IR kodu na cisla
  for (int i = 0; i < velikostKodu; i++) {
    if (data == kody[i]) {
      return String(i);
    }
  }
  return ""; 
}

void nastaveniLed(int hodnota) { // funkce pro nastaveni jasu ledky
  switch (aktualniLed) {
    case 0:
      Serial.print("hodnota červené: ");
      analogWrite(CERVENA, hodnota);
      aktualniLed = 1; // prepne na zelenou led
      break;
    case 1:
      Serial.print("hodnota zelené: ");
      analogWrite(ZELENA, hodnota);
      aktualniLed = 2; // prepne na modrou led
      break;
    case 2:
      Serial.print("hodnota modré: ");
      analogWrite(MODRA, hodnota);
      aktualniLed = 0; // prepne na cervenou led
      break;
  }
  Serial.println(hodnota);
}

void setup() {
  IrReceiver.begin(PIN, ENABLE_LED_FEEDBACK); // inicializuje prijimac na zadanem pinu
  Serial.begin(9600);

  pinMode(CERVENA, OUTPUT);
  pinMode(ZELENA, OUTPUT);
  pinMode(MODRA, OUTPUT);

  Serial.println("\nzadejte číslo v rozsahu 0 - 255, stisknete ENTER a rozsvítí se červená led s vybranou intenzitou, následuje zelená, modrá a poté stále dokola");
}

void loop() {
  if (IrReceiver.decode()) {
    unsigned long data = IrReceiver.decodedIRData.decodedRawData; // ziska prijaty kod
    if (data > 0) {
      if (data == ENTER) {
        int vstupniHodnota = aktualniVstup.toInt(); // prevede na cele cislo
        if (vstupniHodnota >= 0 && vstupniHodnota <= 255) {
          nastaveniLed(vstupniHodnota); // nastavi jas ledky na zadanou hodnotu
          
        } else {
          Serial.println("mimo rozsah"); // pokud je hodnota mimo rozsah
        }
        aktualniVstup = ""; // vyprazdni promennou
      } else {
        aktualniVstup += getReceivedNumber(data); // prida cislo kodu do "aktualniVstup"
        String led;
        switch (aktualniLed) {
          case 0: led = "intenzita červené: "; break;
          case 1: led = "intenzita zelené: "; break;
          case 2: led = "intenzita modré: "; break;
          default: led = "neznámá"; break;
        }
        Serial.print(led);
        Serial.println(aktualniVstup);
        
      }
    }

    IrReceiver.resume(); // obnovi prijimani IR signalu
  }
}

