int counter = 0; //number of signals in a letter

void setup() {
Serial.begin(9600);
pinMode(2, INPUT);  //c0
pinMode(3, INPUT);  //c1
pinMode(4, INPUT);  //c2
pinMode(A0, INPUT); //x0
pinMode(A1, INPUT); //x1
pinMode(A2, INPUT); //x2
pinMode(A3, INPUT); //x3
pinMode(A4, INPUT); //x4
pinMode(A5, INPUT); //x5
}

void setCounter(int c0, int c1, int c2){ // c0 = LSB, c2 = MSB  // use the arduino pins as arguments
  int c0 = digitalRead(c0);
  int c1 = digitalRead(c1);
  int c2 = digitalRead(c2);
  if(c2 == HIGH && c1 == LOW && c0 == LOW){
  counter = 4;  
  }
  
   if(c2 == LOW && c1 == HIGH && c0 == HIGH){  
    counter = 3;
    }
   if(c2 == LOW && c1 == HIGH && c0 == LOW){
    counter = 2;
    }
   if(c2 == LOW && c1==LOW && c0 == HIGH){
    counter = 1;
    }
    if(c2 == LOW && c1 == LOW && c0 == LOW){
    counter = 0;
    }
     
void loop() {
setcounter(2, 3, 4); //  from pins 2,3,4 on the arduino board, 2 is the LSB and 4 is MSB
 
switch(counter){ //counter was determined above, the number of signals in the letter
  case 0:
      if( A0 == LOW){
        //print E to the display then move pointer one step to next on the display
        }
       else{
         //print T
         }
  case 1:
        if(A1 == HIGH && A0 == LOW){
          //print A
          }
        if{A1 == LOW && A0 == LOW){ 
         //print  I        
          }
        if(A1 == HIGH && A0 == HIGH){
          //print M 
          }
        if{A1 == HIGH && A0 == LOW){
          //print N        
          } 
  case 2:
        if( A2 == HIGH && A1 ==  LOW && A0 == LOW){
         //print D  
        }
        if( A2 == HIGH && A1 == HIGH && A0 == LOW){
         //print G   
        }
        if( A2 == HIGH  && A1 == LOW  && A0 == HIGH){
         //print K
        }
        if( A2 == HIGH && A1 == HIGH && A0 == HIGH){
         //print O  
        }
        if( A2 == LOW && A1 == HIGH && A0 == LOW){
         //print R
        }
        if( A2 == LOW && A1 == LOW && A0 == LOW){
         //print S
        }
        if( A2 == LOW && A1 == LOW && A0 == HIGH){
         //print U 
        }
        if( A2 ==LOW && A1 ==HIGH && A0 ==HIGH ){
         //print   
        }
          
  case 3:
        if(A3 == HIGH && A2 == LOW && A1 == LOW  && A0 == LOW ){
          //print B
          }
        if(A3 == HIGH && A2 == LOW && A1 == HIGH  && A0 == LOW ){
          //print C
          }
        if(A3 == LOW && A2 == LOW && A1 == HIGH  && A0 == LOW ){
          //print F
          }
        if(A3 == LOW && A2 == LOW && A1 == LOW  && A0 == LOW ){
          //print H
          }
        if(A3 == LOW && A2 == HIGH && A1 == HIGH && A0 == HIGH ){
          //print J
          }
        if(A3 == LOW && A2 == HIGH && A1 == LOW  && A0 == LOW ){
          //print L
          }
          if(A3 == LOW && A2 == HIGH && A1 == HIGH && A0 == LOW ){
          //print P
          }
          if(A3 == HIGH && A2 == HIGH && A1 == LOW  && A0 == HIGH ){
          //print Q
          }
          if(A3 == LOW && A2 == LOW && A1 == LOW  && A0 == HIGH ){
          //print V
          }
          if(A3 == HIGH && A2 == LOW && A1 == LOW  && A0 == HIGH ){
          //print X
          }
          if(A3 == HIGH && A2 == LOW && A1 ==HIGH  && A0 == HIGH ){
          //print y
          }
          if(A3 == HIGH && A2 == HIGH && A1 == LOW  && A0 == LOW ){
          //print Z
          }
          
          
          
  
  case 4:
  if(A4= HIGH && A3 == HIGH && A2 == HIGH && A1 == HIGH && A0 == HIGH ){
  //print 0
  }
  if(A4= LOW && A3 == HIGH && A2 == HIGH && A1 == HIGH  && A0 == HIGH ){
  //print 1
  }
  if(A4= LOW && A3 == LOW && A2 == HIGH && A1 == HIGH  && A0 == HIGH ){
  //print 2
  }
  if(A4= LOW && A3 == LOW && A2 == LOW && A1 == HIGH  && A0 == HIGH ){
  //print 3
  }
  if(A4= LOW && A3 == LOW && A2 == LOW && A1 == LOW  && A0 == HIGH ){
  //print 4
  }
  if(A4= LOW && A3 == LOW && A2 == LOW && A1 == LOW  && A0 == LOW ){
  //print 5
  }
  if(A4= HIGH && A3 == LOW && A2 == LOW && A1 == LOW  && A0 == LOW ){
  //print 6
  }
  if(A4= HIGH && A3 == HIGH && A2 == LOW && A1 == LOW  && A0 == LOW ){
  //print 7
  }
  if(A4= HIGH && A3 == HIGH && A2 == HIGH && A1 == LOW  && A0 == LOW ){
  //print 8
  }
  if(A4= HIGH && A3 == HIGH && A2 == HIGH && A1 == HIGH  && A0 == LOW ){
  //print 9
  }
  }


}
