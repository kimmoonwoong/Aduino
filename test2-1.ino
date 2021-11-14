int trig = 3;
int echo = 2;
int LED1 = 8;
int LED2 = 9;
int LED3 = 10;
int LED4 = 11;
int LED5 = 12;
float duration;
float distance;

void setup() {
  Serial.begin(9600);
  pinMode(echo,INPUT);
  pinMode(trig,OUTPUT);
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);
  pinMode(LED5, OUTPUT);

}

void loop() {
    digitalWrite(trig,HIGH);
    delay(10);
    digitalWrite(trig,LOW);
    duration = pulseIn(echo,HIGH);
    distance = ((34000*duration)/1000000)/2;
    delay(100);
    Serial.print(distance);
    Serial.println("cm");
    if (distance<40){
      digitalWrite(LED1, LOW);
      digitalWrite(LED2, LOW);
      digitalWrite(LED3, LOW);
      digitalWrite(LED4, LOW);
      digitalWrite(LED5, LOW);
    }
    else if(distance > 40 && distance <= 45){
      digitalWrite(LED1, HIGH);
      digitalWrite(LED2, LOW);
      digitalWrite(LED3, LOW);
      digitalWrite(LED4, LOW);
      digitalWrite(LED5, LOW);
    }
    else if(distance > 45 && distance <= 50){
      digitalWrite(LED1, HIGH);
      digitalWrite(LED2, HIGH);
      digitalWrite(LED3, LOW);
      digitalWrite(LED4, LOW);
      digitalWrite(LED5, LOW);
    }
    else if(distance > 50 && distance <=55){
      digitalWrite(LED1, HIGH);
      digitalWrite(LED2, HIGH);
      digitalWrite(LED3, HIGH);
      digitalWrite(LED4, LOW);
      digitalWrite(LED5, LOW);
    }
    else if(distance > 55 && distance <=60){
      digitalWrite(LED1, HIGH);
      digitalWrite(LED2, HIGH);
      digitalWrite(LED3, HIGH);
      digitalWrite(LED4, HIGH);
      digitalWrite(LED5, LOW);
    }
    else{
      digitalWrite(LED1, HIGH);
      digitalWrite(LED2, HIGH);
      digitalWrite(LED3, HIGH);
      digitalWrite(LED4, HIGH);
      digitalWrite(LED5, HIGH);
    }
}
