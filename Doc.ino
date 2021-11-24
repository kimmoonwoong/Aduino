#include <FrequencyTimer2.h>

int pins[17] = { -1, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, A0, A1};

int GreenCols[8] = {pins[1], pins[2], pins[3], pins[4], pins[5], pins[6], pins[7], pins[8]};
int RedCols[8] = {pins[9], pins[10], pins[11], pins[12], pins[13], pins[14], pins[15], pins[16]};
const int DS = A2;
const int ST_CP = A3;
const int SH_CP = A4;
int button = A5;
int count = 0;

byte num_string[26][8] = {
  0x18,0x24,0x24,0x20,0x10,0x08,0x04,0x3C, //2
  0x18,0x24,0x42,0x42,0x42,0x42,0x24,0x18, //0
  0x18,0x24,0x24,0x20,0x10,0x08,0x04,0x3C, //2
  0x18,0x24,0x42,0x42,0x42,0x42,0x24,0x18, //0
  0x0C,0x08,0x08,0x08,0x08,0x08,0x08,0x3E, //1
  0x7E,0x40,0x40,0x40,0x7E,0x40,0x40,0x7E, //3
  0x02,0x02,0x02,0x02,0x1E,0x22,0x22,0x1C, //6
  0x18,0x24,0x42,0x42,0x42,0x42,0x24,0x18, //0
  0x0C,0x08,0x08,0x08,0x08,0x08,0x08,0x3E, //1
  0x3E,0x02,0x02,0x1E,0x20,0x20,0x1E,0x00, //5
  0x00,0x00,0x66,0x00,0x00,0x24,0x18,0x00, //이모티콘 1
  0x00,0x00,0x66,0x00,0x00,0x00,0x3C,0x00, //이모티콘 2
  0x00,0x66,0x66,0x00,0x00,0xC3,0x24,0x18, //이모티콘 3
  
  
};
unsigned int NumCnt = 0;
#define Row_Sig_AllOff 8
void shiftRegister(unsigned char data)  
{
  int i = 0;
  digitalWrite(ST_CP, LOW); 
  for (i = 0; i < 8; i++)
  {
    digitalWrite(SH_CP, LOW);  
    if (data & (0x80 >> i))
    {
      digitalWrite(DS, HIGH); 
    }
    else
    {
      digitalWrite(DS, LOW);  
    }
    digitalWrite(SH_CP, HIGH);  
  }
  digitalWrite(ST_CP, HIGH); 
}
void RowPulseControl(unsigned char data)  
{
  switch (data)
  {
    case 0:
      shiftRegister(0x80); break;  
    case 1:
      shiftRegister(0x40); break;  
    case 2:
      shiftRegister(0x20); break;  
    case 3:
      shiftRegister(0x10); break;  
    case 4:
      shiftRegister(0x08); break;  
    case 5:
      shiftRegister(0x04); break;  
    case 6:
      shiftRegister(0x02); break; 
    case 7:
      shiftRegister(0x01); break;  
    case Row_Sig_AllOff:
      shiftRegister(0x00); break;  
  }
}
void DotmatrixDisplay() 
{
      for (int i = 0; i < 8; i++)
  {
    for (int j = 0; j < 8; j++)  
    {
      if ((num_string[NumCnt][i] & 1 << j)) 
      {
        digitalWrite(RedCols[j], LOW);
      }
      else  digitalWrite(RedCols[j], HIGH);  
    }

    RowPulseControl(i);
    delay(1);  // LED 휘도 보장을 위함
    RowPulseControl(Row_Sig_AllOff); 
  }
    }
    

void clearLeds()  // 
{
  for (int i = 0; i < 8; i++)
  {
    for (int j = 0; j < 8; j++) 
    {
      digitalWrite(GreenCols[j], HIGH);
      RowPulseControl(i);
    }
  }
  for (int i = 0; i < 8; i++)
  {
    for (int j = 0; j < 8; j++) 
    {
      digitalWrite(RedCols[j], HIGH);
      RowPulseControl(i);
    }
  }
}
void Timer()  
{
  static unsigned int cnt = 0;  
  cnt++;    // 1ms 증가
  if (cnt == 1000)  //1초가 되면
  {
    if(count==1){
      NumCnt++;  
    }
    cnt = 0;
    if (NumCnt == 13)
    {
      NumCnt = 0;  
    }
  }
}
void setup()  // 초기화
{
  pinMode(0, OUTPUT);  
  pinMode(1, OUTPUT);  
  pinMode(2, OUTPUT);  
  pinMode(3, OUTPUT); 
  pinMode(4, OUTPUT); 
  pinMode(5, OUTPUT);  
  pinMode(6, OUTPUT); 
  pinMode(7, OUTPUT);  
  pinMode(8, OUTPUT); 
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);  
  pinMode(11, OUTPUT);  
  pinMode(12, OUTPUT);  
  pinMode(13, OUTPUT);  
  pinMode(A0, OUTPUT);  
  pinMode(A1, OUTPUT);  
  pinMode(SH_CP, OUTPUT);  
  pinMode(ST_CP, OUTPUT);  
  pinMode(DS, OUTPUT);  
  pinMode(button, INPUT_PULLUP);
  FrequencyTimer2::setPeriod(1000);
  FrequencyTimer2::setOnOverflow(Timer);
  clearLeds();
}
void loop()  // 무한 루프
{
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
      DotmatrixDisplay();
  }
}
