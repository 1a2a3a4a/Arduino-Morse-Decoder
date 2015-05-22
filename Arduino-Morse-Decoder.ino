#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 10, 9, 8, 7); //arduino pin 12 displayen RS 4, arduino pin 11 enable signal displayen 6, arduino {10, 9, 8, 7} databuslines displayen
                                        //displayen ska även ha potentiometer i lcd pin 3 för contrast  och ground i 5 och 1, vcc(5volt) i displayen 2.

int counter = 0; //number of signals in a letter
int space = 6; // space or not
int newLetter = 5; //newletter or not
int counter0 = 2; //LSB
int counter1 = 3; // 2nd
int counter2 = 4; //MSB
int clock = A5;
bool clockHigh = false;
bool clockTicked = false;



int columns = 8; //number of columns on the display
int rows = 2; //number of rows on the display

int cursorRow = 0;
int cursorColumn = 0;
bool moveCursor = false; 

void setup() {
  Serial.begin(9600);
  pinMode(space, INPUT);  //space 
  pinMode(newLetter, INPUT);  //newLetter/send
  pinMode(counter0, INPUT);  //c0
  pinMode(counter1, INPUT);  //c1
  pinMode(counter2, INPUT);  //c2
  pinMode(clock, INPUT); //clock
  pinMode(A0, INPUT); //x0
  pinMode(A1, INPUT); //x1
  pinMode(A2, INPUT); //x2
  pinMode(A3, INPUT); //x3
  pinMode(A4, INPUT); //x4
  
  lcd.begin(columns, rows);


  
}

void setCounter(){ // c0 = LSB, c2 = MSB  // use the arduino pins as arguments
  int c0 = digitalRead(counter0);
  int c1 = digitalRead(counter1);
  int c2 = digitalRead(counter2);
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

void printCharacter() {
  int analog0 = digitalRead(A0);
  int analog1 = digitalRead(A1);
  int analog2 = digitalRead(A2);
  int analog3 = digitalRead(A3);
  int analog4 = digitalRead(A4);
  switch(counter){ //counter was determined above, the number of signals in the letter
  case 0:
    if( analog0 == LOW){
      //print E to the display then move pointer one step to next on the display
      Serial.print("E");
      lcd.print("E");
      break;
    }
    else{
      //print T
      Serial.print("T");
      lcd.print("T");
      break;
    }
  case 1:
    if(analog1 == LOW && analog0 == HIGH){
      //print A
      Serial.print("A");
      lcd.print("A");
      break;
    }
    if(analog1 == LOW && analog0 == LOW){ 
      //print I    
      Serial.print("I");
      lcd.print("I");
      break;
    }
    if(analog1 == HIGH && analog0 == HIGH){
      //print M 
      Serial.print("M");
      lcd.print("M");
      break;
    }
    if(analog1 == HIGH && analog0 == LOW){
      //print N     
      Serial.print("N"); 
      lcd.print("N");  
      break;
    } 
  case 2:
    if( analog2 == HIGH && analog1 ==  LOW && analog0 == LOW){
      //print D  
      Serial.print("D");
      lcd.print("D");
      break;
    }
    if( analog2 == HIGH && analog1 == HIGH && analog0 == LOW){
      //print G   
      Serial.print("G");
      lcd.print("G");
      break;
    }
    if( analog2 == HIGH  && analog1 == LOW  && analog0 == HIGH){
      //print K
      Serial.print("K");
      lcd.print("K");
      break;
    }
    if( analog2 == HIGH && analog1 == HIGH && analog0 == HIGH){
      //print O  
      Serial.print("O");
      lcd.print("O");
      break;
    }
    if( analog2 == LOW && analog1 == HIGH && analog0 == LOW){
      //print R
      Serial.print("R");
      lcd.print("R");
      break;
    }
    if( analog2 == LOW && analog1 == LOW && analog0 == LOW){
      //print S
      Serial.print("S");
      lcd.print("S");
      break;
    }
    if( analog2 == LOW && analog1 == LOW && analog0 == HIGH){
      //print U 
      Serial.print("U");
      lcd.print("U");
      break;
    }
    if( analog2 ==LOW && analog1 ==HIGH && analog0 ==HIGH ){
      //print W
      Serial.print("W");
      lcd.print("W");  
      break;
    }

  case 3:
    if(analog3 == HIGH && analog2 == LOW && analog1 == LOW  && analog0 == LOW ){
      //print B
      Serial.print("B");
      lcd.print("B");
      break;
    }
    if(analog3 == HIGH && analog2 == LOW && analog1 == HIGH  && analog0 == LOW ){
      //print C
      Serial.print("C");
      lcd.print("C");
      break;
    }
    if(analog3 == LOW && analog2 == LOW && analog1 == HIGH  && analog0 == LOW ){
      //print F
      Serial.print("F");
      lcd.print("F");
      break;
    }
    if(analog3 == LOW && analog2 == LOW && analog1 == LOW  && analog0 == LOW ){
      //print H
      Serial.print("H");
      lcd.print("H");
      break;
    }
    if(analog3 == LOW && analog2 == HIGH && analog1 == HIGH && analog0 == HIGH ){
      //print J
      Serial.print("J");
      lcd.print("J");
      break;
    }
    if(analog3 == LOW && analog2 == HIGH && analog1 == LOW  && analog0 == LOW ){
      //print L
      Serial.print("L");
      lcd.print("L");
      break;
    }
    if(analog3 == LOW && analog2 == HIGH && analog1 == HIGH && analog0 == LOW ){
      //print P
      Serial.print("P");
      lcd.print("P");
      break;
    }
    if(analog3 == HIGH && analog2 == HIGH && analog1 == LOW  && analog0 == HIGH ){
      //print Q
      Serial.print("Q");
      lcd.print("Q");
      break;
    }
    if(analog3 == LOW && analog2 == LOW && analog1 == LOW  && analog0 == HIGH ){
      //print V
      Serial.print("V");
      lcd.print("V");
      break;
    }
    if(analog3 == HIGH && analog2 == LOW && analog1 == LOW  && analog0 == HIGH ){
      //print X
      Serial.print("X");
      lcd.print("X");
      break;
    }
    if(analog3 == HIGH && analog2 == LOW && analog1 ==HIGH  && analog0 == HIGH ){
      //print Y
      Serial.print("Y");
      lcd.print("Y");
      break;
    }
    if(analog3 == HIGH && analog2 == HIGH && analog1 == LOW  && analog0 == LOW ){
      //print Z
      Serial.print("Z");
      lcd.print("Z");
      break;
    }
        
  case 4:
    if(analog4 == HIGH && analog3 == HIGH && analog2 == HIGH && analog1 == HIGH && analog0 == HIGH ){
      //print 0
      Serial.print(0);
      lcd.print("0");
      break;
    }
    if(analog4 == LOW && analog3 == HIGH && analog2 == HIGH && analog1 == HIGH  && analog0 == HIGH ){
      //print 1
      Serial.print(1);
      lcd.print("1");
      break;
    }
    if(analog4 == LOW && analog3 == LOW && analog2 == HIGH && analog1 == HIGH  && analog0 == HIGH ){
      //print 2
      Serial.print(2);
      lcd.print("2");
      break;
    }
    if(analog4 == LOW && analog3 == LOW && analog2 == LOW && analog1 == HIGH  && analog0 == HIGH ){
      //print 3
      Serial.print(3);
      lcd.print("3");
      break;
    }
    if(analog4 == LOW && analog3 == LOW && analog2 == LOW && analog1 == LOW  && analog0 == HIGH ){
      //print 4
      Serial.print(4);
      lcd.print("4");
      break;
    }
    if(analog4 == LOW && analog3 == LOW && analog2 == LOW && analog1 == LOW  && analog0 == LOW ){
      //print 5
      Serial.print(5);
      lcd.print("5");
      break;
    }
    if(analog4 == HIGH && analog3 == LOW && analog2 == LOW && analog1 == LOW  && analog0 == LOW ){
      //print 6
      Serial.print(6);
      lcd.print("6");
      break;
    }
    if(analog4 == HIGH && analog3 == HIGH && analog2 == LOW && analog1 == LOW  && analog0 == LOW ){
      //print 7
      Serial.print(7);
      lcd.print("7");
      break;
    }
    if(analog4 == HIGH && analog3 == HIGH && analog2 == HIGH && analog1 == LOW  && analog0 == LOW ){
      //print 8
      Serial.print(8);
      lcd.print("8");
      break;
    }
    if(analog4 == HIGH && analog3 == HIGH && analog2 == HIGH && analog1 == HIGH  && analog0 == LOW ){
      //print 9
      Serial.print(9);
      lcd.print("9");
      break;
    }
  }
}

void handleCursor() {
  if (moveCursor) {
    cursorColumn = cursorColumn + 1; //flytta pekaren ett steg framåt för att skriva nästa tecken
  }
    
  if(cursorColumn >= columns + 1){ // byt rad
    if (cursorRow == 0) { //rad 0
      cursorRow = 1;
      cursorColumn = 0;                                     
    }
    else { //rad 1
      cursorRow = 0;
      cursorColumn = 0;
      lcd.setCursor(cursorColumn, cursorRow);
      lcd.print("        ");
      cursorRow = 0;
      cursorColumn = 0;
      lcd.setCursor(cursorColumn, cursorRow);
    }
  }
}

void loop() {
  int clockValue = digitalRead(clock);

  if (clockValue) {

    if (clockTicked == false) {
      clockTicked = true;
  
	if (digitalRead(newLetter) == HIGH) { //checks if we should read from A0-A5

	  lcd.setCursor(cursorColumn, cursorRow);
          Serial.print("cursorColumn:");
          Serial.print(cursorColumn);
          Serial.print("\t");
          Serial.print("cursorRow:");
          Serial.print(cursorRow);          
          Serial.print("\t");
          
	  moveCursor = true;

	  setCounter(); //  from pins 2,3,4 on the arduino board, 2 is the LSB and 4 is MSB
     
          printCharacter();
          if (digitalRead(space)== HIGH){ //checks if space is sent 
            lcd.print(" ");
            cursorColumn = cursorColumn + 1;
          }
          handleCursor();
	}
        else { //if space is HIGH and newLetter is LOW, print ? and don't move the cursor. 
          if (digitalRead(space) == HIGH) {
	    //print ?
	    lcd.setCursor(cursorColumn, cursorRow);
	    Serial.print("?");
            
	    lcd.print("?"); 

          }

      }

    }
  }
  else {
    clockTicked = false; 
  }
}

