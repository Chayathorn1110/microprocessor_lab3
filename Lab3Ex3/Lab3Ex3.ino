int clk_pin = 13; //SHCP
int latch_pin = 10; //STCP
int data_pin = 11; //DS
int map7seg[10] ={
    0b00111111, //0
    0b00000110, //1
    0b01011011, //2
    0b01001111, //3
    0b01100110, //4
    0b01101101, //5
    0b01111101, //6
    0b00000111, //7
    0b01111111, //8
    0b01101111, //9
  };
int i=0;
const int buttonPinA0 = A0;
const int buttonPinA1 = A1;
int buttonStateL = 0;
int buttonStateR = 0;

void setLed(uint8_t _state)
{
digitalWrite(latch_pin,LOW);
for(int i = 0 ; i < 8 ; i++)
    {
  digitalWrite(data_pin,(_state >> (7-i)) & 0x01);
  digitalWrite(clk_pin,HIGH);
  digitalWrite(clk_pin,LOW);
  }
digitalWrite(latch_pin,HIGH);
}

void setup()
{
pinMode(clk_pin,OUTPUT);
pinMode(latch_pin,OUTPUT);
pinMode(data_pin,OUTPUT);
pinMode(buttonPinA0,INPUT_PULLUP);
pinMode(buttonPinA1,INPUT_PULLUP);
setLed(0x3F);

}
void loop()
{

buttonStateL = digitalRead(buttonPinA0);
buttonStateR = digitalRead(buttonPinA1);
  if(buttonStateL == 0)
  {
    if(i==0)
    {
    i=9;
    } else{
      i--;
    }
    setLed(map7seg[i]);
  delay(200);
  }
    if(buttonStateR == 0)
  {
    if(i==9)
    {
    i=0;
    } else{
      i++;
    }
    setLed(map7seg[i]);
  delay(200);
  }
}
