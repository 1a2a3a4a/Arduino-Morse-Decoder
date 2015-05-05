int ledPin = 13;
int A0 = 0;

void setup() {
pinmode(ledPin, OUTPUT);
Serial.begin(9600);
}

void loop() {
digitalWrite(ledPin, HIGH); // LOOP restarts

//A0 = amount of signals
if(001) //A0 = 1;
if(010) //A0 = 2;
if(011) //A0 = 3;
if(100) //A0 = 4;

if(A0 == && A1 == && A2 == && A3 == && A4 == && A5 == && A6 == ){ //A
  //prints A to display 
}
 //... all letters
 
 
 /*
switch(A0){ //Hur kan A0 vara 1,2,3,4
  case 1:
      if(A1 == kort){ //print bokstav med en kort
        //print E
    }
    else //print T
  case 2:
  case 3:
  case 4:
  }
*/


digitalWrite(ledPin, LOW); //LOOP ends 
}
