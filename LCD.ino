#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

int button = 7;
boolean result = false;
int count = 0;
String names = "2020136015 Kim Moon Woong ";
String changename = " Kim Moon Woong 2020136015";
int starts = 0;
int s_end = 16;
int i = 0;
String temp = "";
String temp2 = "";

void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2);
  pinMode(button, INPUT_PULLUP);
}

void loop() {
  if(digitalRead(button)==LOW){ //버튼이 눌러졌을 때 count 1증가
    if(result == false){
      count++;
      result = true;
      Serial.println(count);
    }
  }
  else{
    result = false;
  }


  if (count-1 == 1) { // 버튼을 한번 눌렀을 때
    lcd.print(names[i]); // 학번 이름 순의 문자열을 출력
    i++;
    if (i % 26 == 0) { // 
      i = 0;
    }
    if (i == 16) { // i가 16이 넘어가면 밑줄로 이동
      lcd.setCursor(0, 1);
    }
    if (i == 31) {
      lcd.setCursor(0, 0);
    }
  }
  else if (count-1 == 2) { // 버튼을 두번 눌렀을 떼
    for (int i = starts; i < s_end; i++) { //for문을 통해 temp에 학번 영문순의 문자열 저장, temp2에 영문 숫자 순의 문자열 저장 
      temp += names[i % 26];
      temp2 += changename[i % 26];
  }
  lcd.print(temp); //첫줄에 temp출력
  lcd.setCursor(0, 1); //줄바꿈
  lcd.print(temp2); //temp2출력
  delay(500);
  starts++; // 한 줄 짜르기 2020K -> 020k
  s_end++;
    
  temp = ""; //문자열 초기화
  temp2 = "";
  
  lcd.clear();
  }
  else if (count-1 == 3) { //버튼을 세번 눌렀을 때
    for (int i = starts; i < s_end; i++) { //위에서와 마찬가지로 temp와 temp2저장
      temp += names[i % 26];
      temp2 += changename[i % 26];
    }
    lcd.setCursor(0, 0); //첫줄 temp출력
    lcd.print(temp);
    lcd.setCursor(0, 1); //두번째 줄 temp2출력
    lcd.print(temp2);
    delay(50);

    temp = "";
    temp2 = "";
    
    lcd.clear();
  }
  else if (count-1 == 4) { // 버튼을  네번 눌르면 2번 누른거와 같음
    for (int i = starts; i < s_end; i++) {
      temp += names[i % 26];
      temp2 += changename[i % 26];
  }
    lcd.print(temp);
    lcd.setCursor(0, 1);
    lcd.print(temp2);
    delay(500);
    starts++;
    s_end++;
    
    temp = "";
    temp2 = "";
  
    lcd.clear(); 
  }
}
