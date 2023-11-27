void setup() {
  // put your setup code here, to run once:
pinMode(8,INPUT); //RIGHT IR SENSOR
pinMode(9,INPUT); //LEFT IR SENSOR
pinMode(10,OUTPUT);  //IN1
pinMode(11,OUTPUT);  //IN2
pinMode(12,OUTPUT);   //IN3
pinMode(13,OUTPUT);   //IN4
}

void loop() {
  // put your main code here, to run repeatedly:
int a= digitalRead(8);
int b= digitalRead(9);

if(a==0 && b==0)
{
  digitalWrite(10,HIGH);
  digitalWrite(11,LOW);
  digitalWrite(12,HIGH);
  digitalWrite(13,LOW);
}
if(a==1 && b==1)
{
  digitalWrite(10,LOW);
  digitalWrite(11,LOW);
  digitalWrite(12,LOW);
  digitalWrite(13,LOW);
}
if(a==1 && b==0)
{
  digitalWrite(10,HIGH);
  digitalWrite(11,LOW);
  digitalWrite(12,LOW);
  digitalWrite(13,LOW);
}
if(a==0 && b==1)
{
  digitalWrite(10,LOW);
  digitalWrite(11,LOW);
  digitalWrite(12,HIGH);
  digitalWrite(13,LOW);
}
}
