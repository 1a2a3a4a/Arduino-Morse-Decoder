#include <LiquidCrystal.h>

LiquidCrystal lcd();

int counter = 0; //number of signals in a letter
int space = 6; // space or not
int newLetter = 5; //newletter or not
int c0 = 2; //LSB
int c1 = 3; // 2nd
int c2 = 4; //MSB

int columns = 0; //number of columns on the display
int rows = 0; //number of rows on the display

void setup() {
  Serial.begin(9600);
  pinMode(space, INPUT);  //space 
  pinMode(newLetter, INPUT);  //newLetter
  pinMode(c0, INPUT);  //c0
  pinMode(c1, INPUT);  //c1
  pinMode(c2, INPUT);  //c2
  pinMode(A0, INPUT); //x0
  pinMode(A1, INPUT); //x1
  pinMode(A2, INPUT); //x2
  pinMode(A3, INPUT); //x3
  pinMode(A4, INPUT); //x4
  pinMode(A5, INPUT); //x5
  
  lcd.begin(columns, rows);

}

void setCounter(){ // c0 = LSB, c2 = MSB  // use the arduino pins as arguments
  int c0 = digitalRead(c0);
  int c1 = digitalRead(c1);
  int c2 = digitalRead(c2);
  if(c2 == HIGH && c1 == LOW && c0 == LOW){ //4 signals
    counter = 4;  
  }
  if(c2 == LOW && c1 == HIGH && c0 == HIGH){ //3 signals  
    counter = 3;
  }
  if(c2 == LOW && c1 == HIGH && c0 == LOW){ //2 signals
    counter = 2; 
  }
  if(c2 == LOW && c1==LOW && c0 == HIGH){ //1 signal
    counter = 1; 
  }
  if(c2 == LOW && c1 == LOW && c0 == LOW){ //0 signals not used
    counter = 0;
  }
}



void loop() {
  setcounter(); //  from pins 2,3,4 on the arduino board, 2 is the LSB and 4 is MSB

  int A1 = analogRead(A0);
  int A1 = analogRead(A1);
  int A2 = analogRead(A2);
  int A3 = analogRead(A3);
  int A4 = analogRead(A4);
  int A5 = analogRead(A5);
  
  if (digitalRead(space)== HIGH || digitalRead(newLetter)== HIGH){ //checks if finished with letter or word
    
    switch(counter){ //counter was determined above, the number of signals in the letter
      case 0:
        if( A0 == LOW){
          //print E to the display then move pointer one step to next on the display
          Serial.print("E");
        }
        else{
          //print T
          Serial.print("T");
        }
      case 1:
        if(A1 == HIGH && A0 == LOW){
          //print A
          Serial.print("A");
        }
        if{A1 == LOW && A0 == LOW){ 
          //print  I    
          Serial.print("I");    
        }
        if(A1 == HIGH && A0 == HIGH){
          //print M 
          Serial.print("M");
        }
        if{A1 == HIGH && A0 == LOW){
          //print N     
         Serial.print("N");   
        } 
      case 2:
        if( A2 == HIGH && A1 ==  LOW && A0 == LOW){
          //print D  
          Serial.print("D");
        }
        if( A2 == HIGH && A1 == HIGH && A0 == LOW){
          //print G   
          Serial.print("G");
        }
        if( A2 == HIGH  && A1 == LOW  && A0 == HIGH){
          //print K
          Serial.print("K");
        }
        if( A2 == HIGH && A1 == HIGH && A0 == HIGH){
          //print O  
          Serial.print("O");
        }
        if( A2 == LOW && A1 == HIGH && A0 == LOW){
          //print R
          Serial.print("R");
        }
        if( A2 == LOW && A1 == LOW && A0 == LOW){
          //print S
          Serial.print("S");
        }
        if( A2 == LOW && A1 == LOW && A0 == HIGH){
          //print U 
          Serial.print("U");
        }
        if( A2 ==LOW && A1 ==HIGH && A0 ==HIGH ){
          //print W
        Serial.print("W");  
          
        }

      case 3:
        if(A3 == HIGH && A2 == LOW && A1 == LOW  && A0 == LOW ){
          //print B
          Serial.print("B");
        }
        if(A3 == HIGH && A2 == LOW && A1 == HIGH  && A0 == LOW ){
          //print C
          Serial.print("C");
        }
        if(A3 == LOW && A2 == LOW && A1 == HIGH  && A0 == LOW ){
          //print F
          Serial.print("F");
        }
        if(A3 == LOW && A2 == LOW && A1 == LOW  && A0 == LOW ){
          //print H
          Serial.print("H");
        }
        if(A3 == LOW && A2 == HIGH && A1 == HIGH && A0 == HIGH ){
          //print J
          Serial.print("J");
        }
        if(A3 == LOW && A2 == HIGH && A1 == LOW  && A0 == LOW ){
          //print L
          Serial.print("L");
        }
        if(A3 == LOW && A2 == HIGH && A1 == HIGH && A0 == LOW ){
          //print P
          Serial.print("P");
        }
        if(A3 == HIGH && A2 == HIGH && A1 == LOW  && A0 == HIGH ){
          //print Q
          Serial.print("Q");
        }
        if(A3 == LOW && A2 == LOW && A1 == LOW  && A0 == HIGH ){
          //print V
          Serial.print("V");
        }
        if(A3 == HIGH && A2 == LOW && A1 == LOW  && A0 == HIGH ){
          //print X
          Serial.print("X");
        }
        if(A3 == HIGH && A2 == LOW && A1 ==HIGH  && A0 == HIGH ){
          //print Y
          Serial.print("Y");
        }
        if(A3 == HIGH && A2 == HIGH && A1 == LOW  && A0 == LOW ){
          //print Z
          Serial.print("Z");
        }
        
      case 4:
        if(A4 == HIGH && A3 == HIGH && A2 == HIGH && A1 == HIGH && A0 == HIGH ){
          //print 0
          Serial.print(0);
        }
        if(A4 == LOW && A3 == HIGH && A2 == HIGH && A1 == HIGH  && A0 == HIGH ){
          //print 1
          Serial.print(1);
        }
        if(A4 == LOW && A3 == LOW && A2 == HIGH && A1 == HIGH  && A0 == HIGH ){
          //print 2
          Serial.print(2);
        }
        if(A4 == LOW && A3 == LOW && A2 == LOW && A1 == HIGH  && A0 == HIGH ){
          //print 3
          Serial.print(3);
        }
        if(A4 == LOW && A3 == LOW && A2 == LOW && A1 == LOW  && A0 == HIGH ){
          //print 4
          Serial.print(4);
        }
        if(A4 == LOW && A3 == LOW && A2 == LOW && A1 == LOW  && A0 == LOW ){
          //print 5
          Serial.print(5);
        }
        if(A4 == HIGH && A3 == LOW && A2 == LOW && A1 == LOW  && A0 == LOW ){
          //print 6
          Serial.print(6);
        }
        if(A4 == HIGH && A3 == HIGH && A2 == LOW && A1 == LOW  && A0 == LOW ){
          //print 7
          Serial.print(7);
        }
        if(A4 == HIGH && A3 == HIGH && A2 == HIGH && A1 == LOW  && A0 == LOW ){
          //print 8
          Serial.print(8);
        }
        if(A4 == HIGH && A3 == HIGH && A2 == HIGH && A1 == HIGH  && A0 == LOW ){
          //print 9
          Serial.print(9);
        }
    }
  }

}
