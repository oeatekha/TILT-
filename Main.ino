int randnumb;
int prevRand;
unsigned long timer;

const int led_pin_Red = 4;
const int led_pin_Blue = 5;
const int led_pin_Yellow = 6;
const int led_pin_Green = 7;

int photocellPin = A3;
int Sensor_Rec_1 = A4;
int Sensor_Rec_2 = A5;
int Sensor_Rec_3 = A6;
int Sensor_Rec_4 = A7;

int value;
int timemax = 90;
int score;
int highscore;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600); 
  pinMode(4, OUTPUT);
  pinMode(led_pin_Blue, OUTPUT);
  pinMode(led_pin_Green, OUTPUT);
  pinMode(led_pin_Yellow, OUTPUT);
  pinMode(Sensor_Rec_1, INPUT);
  //pinMode(SCREEN 1 SCORE, SCREEN 2 (HIGHSCORE), SCREEN 3 (TIMER, OUTPUT);
  randnumb = random(0, 4);
  Serial.print("first hole is ");
  Serial.println(randnumb);


}

void loop() {
  // put your main code here, to run repeatedly:
  //while time != 0 { run  program
  Serial.println("Rand num: ");
  Serial.println(randnumb);
  digitalWrite(randnumb+4, HIGH);
  Serial.println("");

  int photocellReading = analogRead(A4); 
  //int photocellReading = analogRead(A4+randnumb); 
  Serial.print("Analog reading = ");
  Serial.print(photocellReading);

  
  

  //Serial.println("time ");
  //timer = millis();
  //Serial.println(timemax - timer);

   
  //Random function when ball hits

  if(photocellReading < 20){
    //score++;
    prevRand = randnumb;
    digitalWrite(randnumb+4, LOW);
    //change ligh to another light ensuring it wasn't the previous light
    do {
      randnumb = random(0,4);
      Serial.println(randnumb);
      delay(10);
    }
    while (randnumb != prevRand); //prevRand
    
  }
  Serial.println("");



  //if sensor value is > 25 then it is covered and on top of that we +1 to the score (perform random function to replace new light
  //else program repeats
  //within while loop
  
  /*if (score > highscore){
      highscore == score;
      Serial.println(highscore);
    }
   */
       
  delay(1000); //displays time for every second
}
