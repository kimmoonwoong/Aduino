#include <IRremote.h>

const int RECV_PIN = 7;

IRrecv irrecv(RECV_PIN);

decode_results results;

int x = 0;
char a = ' ';
int y = 0;
int c = 0;
int count = 0;
String string = " ";
void setup() {
  Serial.begin(9600);
  irrecv.enableIRIn();
  Serial.print(string);
}

void loop() {
  if (irrecv.decode(&results)) {
      if(results.value == 16738455 && count == 0){
      x = 0;
    }
    else if(results.value == 16724175 && count == 0){
      x = 1;
      Serial.print(x);
      Serial.print(' ');
      count++;
    }
    else if(results.value == 16718055 && count == 0){
      x = 2;
      Serial.print(x);
      Serial.print(' ');
      count++; 
    }
    else if(results.value == 16743045 && count == 0){
      x = 3;
      Serial.print(x);
      Serial.print(' ');
      count++;
    }
    else if(results.value == 16716015 && count ==0){
      x= 4;
      Serial.print(x);
      Serial.print(' ');
      count++;
    }
    else if(results.value == 16726215 && count == 0){
      x = 5;
      Serial.print(x);
      Serial.print(' ');
      count++;
    }
    else if(results.value == 16734885 && count == 0){
      x = 6;
      Serial.print(x);
      Serial.print(' ');
      count++;
    }
    else if(results.value == 16728765 && count ==0){
      x = 7;
      Serial.print(x);
      Serial.print(' ');
      count++;
    }
    else if(results.value == 16730805 && count ==0){
      x = 8;
      Serial.print(x);
      Serial.print(' ');
      count++;
    }
    else if(results.value == 16732845 && count == 0){
      x = 9;
      Serial.print(x);
      Serial.print(' ');
      count++;
    }
    
    else if(results.value == 16724175 && count == 2){
      y = 1;
      Serial.print(y);
      Serial.print(' ');
      count++;
    }
    else if(results.value == 16718055 && count == 2){
      y = 2;
      Serial.print(y);
      Serial.print(' ');
      count++;
    }
    else if(results.value == 16743045 && count == 2){
      y = 3;
      Serial.print(y);
      Serial.print(' ');
      count++;
    }
    else if(results.value == 16716015 && count == 2){
      y = 4;
      Serial.print(y);
      Serial.print(' ');
      count++;
    }
    else if(results.value == 16726215 && count == 2){
      y = 5;
      Serial.print(y);
      Serial.print(' ');
      count++;
    }
    else if(results.value == 16734885 && count == 2){
      y = 6;
      Serial.print(y);
      Serial.print(' ');
      count++;
    }
    else if(results.value == 16728765 && count == 2){
      y = 7;
      Serial.print(y);
      Serial.print(' ');
      count++;
    }
    else if(results.value == 16730805 && count == 2){
      y = 8;
      Serial.print(y);
      Serial.print(' ');
    }
    else if(results.value == 16732845 && count == 2){
      y = 9;
      Serial.print(y);
      Serial.print(' ');
      count++;
    }
    else if(results.value == 16769565 && count == 1){
      a = '+';
      Serial.print(a);
      Serial.print(' ');
      count++;
    }
    else if(results.value == 16753245 && count == 1){
      a = '-';
      Serial.print(a);
      Serial.print(' ');
      count++;
    }
    else if(results.value == 16736925 && count == 1){
      a = '*';
      Serial.print(a);
      Serial.print(' ');
      count++;
    }
    else if(results.value == 16761405 && count == 1){
      a = '/';
      Serial.print(a);
      Serial.print(' ');
      count++;
    }
    else{
       if(a == '+'){
        c = x+y;
        Serial.print('=');
        Serial.print(' ');
        Serial.println(c);
        count = 0;
    }
      else if(a == '-'){
        c = x-y;
        Serial.print('=');
        Serial.print(' ');
        Serial.println(c);
        count = 0;
    }
      else if(a == '*'){
        c = x*y;
        Serial.print('=');
        Serial.print(' ');
        Serial.println(c);
        count = 0;
    }
      else if(a = '/'){
        c = x/y;
        Serial.print('=');
        Serial.print(' ');
        Serial.println(c);
        count = 0;
    }
    }

    irrecv.resume();
}
}
