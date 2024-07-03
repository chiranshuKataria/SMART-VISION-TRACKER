
int PWM_LOWER = 5; //Lower motor
// int PWM_UPPER = 6 //Upper motor
int INA_LOWER = 8;
int INB_LOWER = 7;
int PWM_UPPER = 6; //Upper motor
int INA_UPPER = 12;
int INB_UPPER = 13;
// int INA_UPPER =
// int INB_UPPER =
int x;
int y;
int prevX;
int prevY;
int speedX;
int speedY;
void setup()
{
  Serial.begin(9600);
  // servoVer.attach(9); //Attach Vertical Servo to Pin 5
  // servoHor.attach(10); //Attach Horizontal Servo to Pin 6
  // servoVer.write(90);
  // servoHor.write(90);
  pinMode(PWM_LOWER,OUTPUT);
  pinMode(INA_LOWER,OUTPUT);
  pinMode(INB_LOWER,OUTPUT);

}
void Pos()
{
  if(prevX != x || prevY != y)
  {
    speedX = x-90;
    speedY = y-90;
  }
  else{
    speedX = 0;
    speedY= 0;
  }
  if(speedX<10 || speedX>-10){
    speedX=0;
  }
  if(speedY<5 || speedY>-5){
    speedY=0;
  }
  
  prevX=x;
  prevY=y;
  // Serial.Print(speedX);
  // Serial.Printnl;

}
void loop()
{
  if(Serial.available() > 0)
  {
    if(Serial.read() == 'X')
    {
      x = Serial.parseInt();
      if(Serial.read() == 'Y')
      {
        y = Serial.parseInt();
        Serial.print(x);
        Serial.print(" ");
        Serial.print(y);
        Serial.println();
       //Pos();
            if(x-880>0){
        analogWrite(PWM_LOWER,70);
        digitalWrite(INA_LOWER,HIGH);
        digitalWrite(INB_LOWER,LOW); 
        }
        else{
        analogWrite(PWM_LOWER,70);
        digitalWrite(INA_LOWER,LOW);
        digitalWrite(INB_LOWER,HIGH); 
        }
        if(y-420>0){
        analogWrite(PWM_UPPER,90);
        digitalWrite(INA_UPPER,HIGH);
        digitalWrite(INB_UPPER,LOW); 
        }
        else{
        analogWrite(PWM_UPPER,90);
        digitalWrite(INA_UPPER,LOW);
        digitalWrite(INB_UPPER,HIGH); 
        }
        //delay(100);
      }
    }
    // while(Serial.available() > 0)
    // {
    //   Serial.read();
    // }
  }
}
