// 8,9,10,11 are the digital pins on nano 
int wire1 = 8;
int wire2 = 9;
int wire3 = 10;
int wire4 = 11;

// Declaring analog pins for controlling breaths per minute
int breath1 = A1;
int breath2 = A2;
int breath3 = A3;

// Clockwise and Anti-Clockwise rotation of stepper motors

int roundClockWise = 1;
int roundAntiClockWise = 2;

// Delay between energising of each coil

int delayTime = 5;

// Initialising pins and setting states

void setup() {
  pinMode(wire1,OUTPUT);
  pinMode(wire2,OUTPUT);
  pinMode(wire3,OUTPUT);
  pinMode(wire4,OUTPUT);
  
  pinMode(breath1,INPUT);
  pinMode(breath2,INPUT);
  pinMode(breath3,INPUT);
  
  digitalWrite(wire1,LOW);
  digitalWrite(wire2,LOW);
  digitalWrite(wire3,LOW);
  digitalWrite(wire4,LOW);
}

// Anticlockwise function : Energises each coil of motor by controlling HIGH and LOW on digital pins decalared above

int anticlockWise(int de){
  digitalWrite(wire2,HIGH);
  delay(de);
  digitalWrite(wire2,LOW);
  digitalWrite(wire3,HIGH);
  delay(de);
  digitalWrite(wire3,LOW);
  digitalWrite(wire1,HIGH);
  delay(de);
  digitalWrite(wire1,LOW);
  digitalWrite(wire4,HIGH);
  delay(de);
  digitalWrite(wire4,LOW); 
  }

// Clockwise function : Energises each coil of motor by controlling HIGH and LOW on digital pins decalared above

  int clockWise(int de){
  digitalWrite(wire1,HIGH);
  delay(de);
  digitalWrite(wire1,LOW);
  digitalWrite(wire3,HIGH);
  delay(de);
  digitalWrite(wire3,LOW);
  digitalWrite(wire2,HIGH);
  delay(de);
  digitalWrite(wire2,LOW);
  digitalWrite(wire4,HIGH);
  delay(de);
  digitalWrite(wire4,LOW); 
  }

// Continous Loop

void loop() {

  int b1 = analogRead(breath1);
  int b2 = analogRead(breath2);
  int b3 = analogRead(breath3);

  // A1,A2,A3 button state checks and priority is as follows : A3>A2>A1 i.e., if A3 and A2 are on at the same time : code will work according 
  // to parameters set by A3 
  
  // Default are A1 configurations

  if(b3>500){
  roundClockWise = 1.5;
  roundAntiClockWise = 1.5;
    }else if(b2>500){
  roundClockWise = 2.5;
  roundAntiClockWise = 2.5;
      }else if(b1>500){
  roundClockWise = 5;
  roundAntiClockWise = 5;
        }else{
  roundClockWise = 5;
  roundAntiClockWise = 5;
          }
    
  
delayTime = 5;

  // two for loops for up & down motion
  
  for(int i=0;i<50*roundAntiClockWise;i++){
      anticlockWise(delayTime);
    }
    delay(500);
  for(int j=0;j<50*roundClockWise;j++){
      clockWise(delayTime);  
    }
    delay(500);
  
}
