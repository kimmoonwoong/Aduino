int red = 8;
int yellow = 9;
int green = 10;
unsigned char value = 0;
unsigned char value2 = 0;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(red,OUTPUT);
  pinMode(yellow,OUTPUT);
  pinMode(green, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

  if(value / 128 >= 1){
    value-=128;
    Serial.print(1);
  }
  else{
    Serial.print(0);
  }
  if(value / 64 >= 1){
    value -= 64;
    Serial.print(1);
  }
  else{
    Serial.print(0);
  }
  if(value /32 >= 1){
    value -=32;
    Serial.print(1);
  }
  else{
    Serial.print(0);
  }
  if(value / 16 >=1){
    value -= 16;
    Serial.print(1);
  }
  else{
    Serial.print(0);
  }
  if(value /8 >= 1){
    value -=8;
    Serial.print(1);
  }
  else{
    Serial.print(0);
  }
  if(value / 4 >= 1){
    value -= 4;
    digitalWrite(green,HIGH);
  }
  else{
    digitalWrite(green,LOW);
  }
  if(value / 2 >= 1){
    value -= 2;
    digitalWrite(yellow,HIGH);
  }
  else{
    digitalWrite(yellow,LOW);
  }
  if(value -1 ==0){
     digitalWrite(red,HIGH);
  }

  else{
    digitalWrite(red,LOW);
  }
  if(value == 255){
    exit(0);
  }

  delay(1000);
  Serial.println();
  value2++;
  value = value2;
}
