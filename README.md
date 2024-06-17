Popis projektu
Tento projekt používá Arduino k ovládání jasu tří LED diod (červené, zelené a modré) pomocí dálkového IR ovládání. Pomocí IR dálkového ovládání lze zadat čísla od 0 do 255, která reprezentují intenzitu jasu pro jednotlivé LED diody. Po zadání čísla a stisknutí tlačítka ENTER se nastaví jas červené LED diody na zadanou hodnotu. Poté se stejným způsobem nastaví jas zelené a modré LED diody v cyklu.

Potřebné součásti
Arduino (např. Arduino Uno)
IR přijímač
IR dálkové ovládání
Tři LED diody (červená, zelená, modrá)
Rezistory (doporučené hodnoty: 220 ohmů pro každou LED)
Propojovací kabely
Breadboard (nepovinné, ale doporučené)
Zapojení
IR přijímač:

Připojte výstupní pin IR přijímače na digitální pin 12 na Arduinu.
Připojte napájecí piny IR přijímače na 5V a GND na Arduinu.
LED diody:

Připojte červenou LED diodu (s rezistorem) na digitální pin 5 na Arduinu.
Připojte zelenou LED diodu (s rezistorem) na digitální pin 6 na Arduinu.
Připojte modrou LED diodu (s rezistorem) na digitální pin 9 na Arduinu.
Knihovny
Pro tento projekt je nutné nainstalovat knihovnu IRremote. Lze ji nainstalovat prostřednictvím Správce knihoven v Arduino IDE.