 const int clock = 7; //SCK
const int latch = 5; //RCK 
const int data = 6;  //DIO
int lect;
byte value[] ={ B11000000, // 0
                B11111001, // 1
                B10100100, // 2
                B10110000, // 3
                B10011001, // 4
                B10010010, // 5
                B10000010, // 6
                B11111000, // 7
                B10000000, // 8
                B10010000, // 9
                B11111111};// display nothing

byte digit[] ={ B00000001, // left segment
                B00000010,
                B00000100,
                B00001000,
                B00010000,
                B00100000,
                B01000000,
                B10000000}; // right segment
void setup() {
  Serial.begin(9600);
  pinMode(clock, OUTPUT);
  pinMode(latch, OUTPUT);
  pinMode(data, OUTPUT);
}

void loop() {;
  lect=analogRead(A0);
  for(int x=0;x<50;x++){
      digitos(lect);
      delay(10);
    }
}
void digitos(int i){
  int u=i%10;
  int d=i%100-u ;
  int c=i%1000-d-u;
  int m=i&10000-c-d-u;
  if (i<100){
    c=0;
    m=0;
  }
  if (i<10){
    c=0;
    m=0;
    d=0;
  }
  if (i<1000){
    m=0;
  }
  digitalWrite(latch,LOW);
  shiftOut(data,clock,MSBFIRST,B11111111); // select all segments
  shiftOut(data,clock,MSBFIRST,B11111111); // display nothing
  digitalWrite(latch,HIGH); 
  delayMicroseconds(20);
  digitalWrite(latch,LOW);
  
  shiftOut(data,clock,MSBFIRST,digit[4]);  
  
  shiftOut(data,clock,MSBFIRST,value[m/1000]);  
  digitalWrite(latch,HIGH);
  delayMicroseconds(20);

  digitalWrite(latch,LOW);
  shiftOut(data,clock,MSBFIRST,digit[5]);  
  shiftOut(data,clock,MSBFIRST,value[c/100]);  
  digitalWrite(latch,HIGH);
  delayMicroseconds(20);
  digitalWrite(latch,LOW);

  shiftOut(data,clock,MSBFIRST,digit[6]);  
  shiftOut(data,clock,MSBFIRST,value[d/10]);  
  digitalWrite(latch,HIGH);
  delayMicroseconds(20);
  digitalWrite(latch,LOW);

  shiftOut(data,clock,MSBFIRST,digit[7]);  
  shiftOut(data,clock,MSBFIRST,value[u]);  
  digitalWrite(latch,HIGH); 
  delayMicroseconds(20);
  digitalWrite(latch,LOW);

  shiftOut(data,clock,MSBFIRST,digit[0]);  
  shiftOut(data,clock,MSBFIRST,B11001000);  
  digitalWrite(latch,HIGH); 
  delayMicroseconds(20);
  digitalWrite(latch,LOW);

  shiftOut(data,clock,MSBFIRST,digit[1]);  
  shiftOut(data,clock,MSBFIRST,B10001001);  
  digitalWrite(latch,HIGH); 
  delayMicroseconds(20);
  digitalWrite(latch,LOW);
  
  shiftOut(data,clock,MSBFIRST,digit[2]);  
  shiftOut(data,clock,MSBFIRST,value[3]);  
  digitalWrite(latch,HIGH); 
  delayMicroseconds(20);
  digitalWrite(latch,LOW);
  
  shiftOut(data,clock,MSBFIRST,digit[3]);  
  shiftOut(data,clock,MSBFIRST,B01111111);  
  digitalWrite(latch,HIGH); 

 
}
