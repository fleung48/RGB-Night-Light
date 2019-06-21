// Forrest - BlueStamp Starter Project

int photoresistor;          //variable for storing the photoresistor value
int potentiometer;          //this variable will hold a value based on the position of the knob
int threshold = 690;            //if the photoresistor reading is lower than this value the light will turn on

//LEDs are connected to these pins
int RedPin = 9;
int GreenPin = 10;
int BluePin = 11;

void setup() {
  Serial.begin(9600);           //start the serial link

  //set the LED pins to output
  pinMode(RedPin,OUTPUT);
  pinMode(GreenPin,OUTPUT);
  pinMode(BluePin,OUTPUT);
}

void loop() {
  photoresistor = analogRead(A0);         //check photoresistor value
  potentiometer = analogRead(A1);

  Serial.print("Photoresistor value:");
  Serial.print(photoresistor);          //print the photoresistor value
  Serial.print("Potentiometer value:");
  Serial.println(potentiometer);          //print the potentiometer value

  if(photoresistor < threshold){          //turn the LED on when photoresistor value under threshold
    //call different functions based on the current potentiometer value.
    if(potentiometer >= 0 && potentiometer <= 150)
      red();
    if(potentiometer > 150 && potentiometer <= 300)
      orange();
    if(potentiometer > 300 && potentiometer <= 450)
      yellow(); 
    if(potentiometer > 450 && potentiometer <= 600)
      green();
    if(potentiometer > 600 && potentiometer <= 750)
      cyan();
    if(potentiometer > 750 && potentiometer <= 900)
      blue(); 
    if(potentiometer > 900)
      magenta();  
  } 
  else {                                //if it isn't dark turn the LED off

    turnOff();                       //call the turn off function
  }  

  delay(100);                       //short delay so that the printout is easier to read
}

void red (){
    analogWrite(RedPin, 0);
    analogWrite(GreenPin, 255);
    analogWrite(BluePin, 255);
}
void orange (){
    analogWrite(RedPin, 100);
    analogWrite(GreenPin, 225);
    analogWrite(BluePin, 255);
}
void yellow (){
    analogWrite(RedPin, 0);
    analogWrite(GreenPin, 50);
    analogWrite(BluePin, 255);
}
void green (){
    analogWrite(RedPin, 255);
    analogWrite(GreenPin, 0);
    analogWrite(BluePin, 255);
}
void cyan (){
    analogWrite(RedPin, 200);
    analogWrite(GreenPin, 0);
    analogWrite(BluePin, 55);
}
void blue (){
    analogWrite(RedPin, 255);
    analogWrite(GreenPin, 255);
    analogWrite(BluePin, 0);
}
void magenta (){
    analogWrite(RedPin,205);
    analogWrite(GreenPin, 255);
    analogWrite(BluePin, 175);
}
void turnOff (){
    //turn all three LED pins off
    analogWrite(RedPin, 0);
    analogWrite(GreenPin, 0);
    analogWrite(BluePin, 0);
}
