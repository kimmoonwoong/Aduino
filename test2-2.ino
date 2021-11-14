int button = 3;
int LED = 8;
boolean onoff = LOW;
int ThermistorPin = 0;
int V0;
int maxTer = 0;
int count = 0;
void setup() {
  pinMode(button, INPUT);
  pinMode(LED, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  V0 = analogRead(ThermistorPin);
  Serial.println(V0);
  if(digitalRead(button) == LOW){
    delay(10);
    if(digitalRead(button) == HIGH){
        count++;
        delay(10);
        while(digitalRead(button) == HIGH){
          delay(1);
        }
    }
  }
  if(count ==1){
    maxTer = 19;
  }
  else if(count == 2){
    maxTer = 50;
  }
  else if(count>=3){
    maxTer = 60;
  }
  if (V0>maxTer){
    digitalWrite(LED, HIGH);
  }
  else{
    digitalWrite(LED, LOW);
  }
}
