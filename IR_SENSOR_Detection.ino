//LED library
#include <Adafruit_NeoPixel.h>

const int Red_Corner = 0;
const int Blue_Corner = 1;
const int Yellow_Corner = 2;
const int Green_Corner = 3;
int currentColor;
int score = 0;
int prevRand;

//test value
int wait = 500;

// Which pin on the Arduino is connected to the NeoPixels?
#define LED_PIN     30

// How many NeoPixels are attached to the Arduino?
#define LED_COUNT  40

// NeoPixel brightness, 0 (min) to 255 (max)
#define BRIGHTNESS 50

//LED setup
Adafruit_NeoPixel strip(LED_COUNT, LED_PIN); 

int red = (255, 0, 0, 0); //red light combination
int green = (0, 255, 0, 0);// green light combination
int blue = (0, 0, 255, 0);//blue light combination
int yellow = (255,255,0,0);//yellow light combination

int Sensor_Rec_1 = A14;//red corner sensor
int Sensor_Rec_2 = A15;// blue corner sensor
int Sensor_Rec_3 = A16;// yellow corner sensor
int Sensor_Rec_4 = A17;// green corner sensor
int Sensor_Rec_5 = A18;// left hand sensor
int Sensor_Rec_6 = A19;// right hand sensor

void colorWipe(uint32_t color, int wait) {
  for(int i=0; i<strip.numPixels(); i++) { // For each pixel in strip...
    strip.setPixelColor(i, color);         //  Set pixel's color (in RAM)
    strip.show();                          //  Update strip to match
    delay(wait);                           //  Pause for a moment
  }
}

void setup() {
  strip.begin();           // INITIALIZE NeoPixel strip object (REQUIRED)
  strip.show();            // Turn OFF all pixels ASAP
  strip.setBrightness(50); // Set BRIGHTNESS to about 1/5 (max = 255)
  colorWipe(strip.Color(  0,   0,   0, 255), 50); // True white (not RGB white)

  currentColor = random(0,4);
  Serial.print("first hole is ");
  Serial.println(currentColor);

    for(int i=1; i<=10; i++) { // For 1/4 of the strip
    strip.setPixelColor(i+currentColor*10, currentColor);         //  Set pixel's color (in RAM)
    strip.show();                          //  Update strip to match
    delay(wait);                           //  Pause for a moment
  }

  pinMode(Sensor_Rec_1, INPUT);
  pinMode(Sensor_Rec_2, INPUT);
  pinMode(Sensor_Rec_3, INPUT);
  pinMode(Sensor_Rec_4, INPUT);
  pinMode(Sensor_Rec_5, INPUT);
  pinMode(Sensor_Rec_6, INPUT);

}

void loop() {
  // put your main code here, to run repeatedly:

  int photocellReading = analogRead(A14+currentColor); 
  Serial.print("Analog reading = ");
  Serial.print(photocellReading);
  if(photocellReading < 20){
    score++;
    prevRand = currentColor;
    colorWipe(strip.Color(  0,   0,   0, 255), 50); // True white (not RGB white)
    //change light to another light ensuring it wasn't the previous light
    
    while (currentColor != prevRand){//prevRand
      currentColor = random(0,4);
      Serial.println(currentColor);
      delay(10);
    
    }
    
  }
    


}
