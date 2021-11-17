#include <IRremote.h>

const int RECV_PIN = 7;

IRrecv irrecv(RECV_PIN);

decode_results results;

int count = 0;
int x = 0;
int y = 0;
char a = ' ';
char b = ' ';
int c = 0;
String x1 = "";
String y1 = "";
void setup() {
  Serial.begin(9600);
  irrecv.enableIRIn();
}

void loop() {
  if (irrecv.decode(&results)) {
    
    if(results.value == 16738455 && count ==0){
      x1 = x1 + "0";
      Serial.print('0');
    }
    else if(results.value == 16724175 && count ==0){
      x1 = x1 + "1";
      Serial.print('1');
    }
    else if(results.value == 16718055 && count ==0){
      x1 = x1 + "2";
      Serial.print('2');
    }
    else if(results.value == 16743045 && count ==0){
      x1 = x1 + "3";
      Serial.print('3');
    }
    else if(results.value == 16716015 && count ==0){
      x1 = x1 + "4";
      Serial.print('4');
    }
    else if(results.value == 16726215 && count ==0){
      x1 = x1 + "5";
      Serial.print('5');
    }
    else if(results.value == 16734885 && count ==0){
      x1 = x1 + "6";
      Serial.print('6');
    }
    else if(results.value == 16728765 && count ==0){
      x1 = x1 + "7";
      Serial.print('7');
    }
    else if(results.value == 16730805 && count ==0){
      x1 = x1 + "8";
      Serial.print('8');
    }
    else if(results.value == 16732845 && count ==0){
      x1 = x1 + "9";
      Serial.print('9');
    }
    else if(results.value == 16769565 ){
      a = '+';
      x = x1.toInt();
      Serial.print(' ');
      Serial.print(a);
      Serial.print(' ');
      count++;
    }
    else if(results.value == 16753245 ){
      a = '-';
      x = x1.toInt();
      Serial.print(' ');
      Serial.print(a);
      Serial.print(' ');
      count++;
    }
    else if(results.value == 16736925){
      a = '*';
      x = x1.toInt();
      Serial.print(' ');
      Serial.print(a);
      Serial.print(' ');
      count++;
    }
    else if(results.value == 16761405){
      a = '/';
      x = x1.toInt();
      Serial.print(' ');
      Serial.print(a);
      Serial.print(' ');
      count++;
    }

    if(results.value == 16738455 && count == 1){
      y1 = y1 + "0";
      Serial.print('0');
    }
      else if(results.value == 16724175 && count == 1){
      y1 = y1 + "1";
      Serial.print('1');
    }
    else if(results.value == 16718055 && count == 1){
      y1 = y1 + "2";
      Serial.print('2');
    }
    else if(results.value == 16743045 && count == 1){
      y1 = y1 + "3";
      Serial.print('3');
    }
    else if(results.value == 16716015 && count == 1){
      y1 = y1 + "4";
      Serial.print('4');
    }
    else if(results.value == 16726215 && count == 1){
      y1 = y1 + "5";
      Serial.print('5');
    }
    else if(results.value == 16734885 && count == 1){
      y1 = y1 + "6";
      Serial.print('6');
    }
    else if(results.value == 16728765 && count == 1){
      y1 = y1 + "7";
      Serial.print('7');
    }
    else if(results.value == 16730805 && count == 1){
      y1 = y1 + "8";
      Serial.print('8');
    }
    else if(results.value == 16732845 && count == 1){
      y1 = y1 + "9";
      Serial.print('9');
    }
    else if(results.value == 16748655){
      b = '=';
      y = y1.toInt();
      Serial.print(' ');
      Serial.print(' ');
      if(a == '+'){
        c = x+y;
        Serial.print('=');
        Serial.print(' ');
        Serial.println(c);
    }
      else if(a == '-'){
        c = x-y;
        Serial.print('=');
        Serial.print(' ');
        Serial.println(c);
    }
      else if(a == '*'){
        c = x*y;
        Serial.print('=');
        Serial.print(' ');
        Serial.println(c);
    }
      else if(a == '/'){
        c = x/y;
        Serial.print('=');
        Serial.print(' ');
        Serial.println(c);
    }
    }
       

    irrecv.resume();
}
}
