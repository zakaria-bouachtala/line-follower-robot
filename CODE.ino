const int IN1=10;
const int IN2=11;
const int IN3=2;
const int IN4=3;
int v1=5;
int v2=9;
int out1=6;
int out2=7;
int out3=8;
int capt1;
int capt2;
int capt3;
void setup() {
  // put your setup code here, to run once:
pinMode( IN1 ,OUTPUT);
pinMode( IN2 ,OUTPUT);
pinMode( IN3 ,OUTPUT);
pinMode( IN4 ,OUTPUT);
pinMode( out1,INPUT);
pinMode( out2,INPUT);
pinMode( out3,INPUT);
pinMode(v1,OUTPUT);
pinMode(v2,OUTPUT);
Serial.begin(9600);
}
void turn_right(){
  analogWrite(v1,100);
  analogWrite(v2,100);
  digitalWrite(IN1,LOW);
  digitalWrite(IN2,HIGH);
  digitalWrite(IN3,HIGH);
  digitalWrite(IN4,LOW);
}
void turn_left(){
  analogWrite(v1,100);
  analogWrite(v2,100);
  digitalWrite(IN1,HIGH);
  digitalWrite(IN2,LOW);
  digitalWrite(IN3,LOW);
  digitalWrite(IN4,HIGH);
}
void forword(){
  analogWrite(v1,100);
  analogWrite(v2,100);
  digitalWrite(IN1,HIGH);
  digitalWrite(IN2,LOW);
  digitalWrite(IN3,HIGH);
  digitalWrite(IN4,LOW);
}
void loop() {
  capt1=digitalRead(out1);
  capt2=digitalRead(out2);
  capt3=digitalRead(out3);
  
  if(capt1==0 && capt2==0 && capt3==1){
      forword();
}
  if(capt1==0 && capt2==0 && capt3==0){
      forword();
}
  if(capt1==1 && capt2==1 && capt3==1){
      forword();
}
if(capt1==1 && capt2==1 && capt3==0){
      forword();
}
if(capt1==0 && capt2==1 && capt3==1){
      while(digitalRead(out3)==1){          // optional condition
        turn_right();
     }
}
if(capt1==1 && capt2==0 && capt3==1){
      while(digitalRead(out3)==1){          // optional condition
        turn_left();
      }
}
 if(capt1==0 && capt2==1 && capt3==0){
        turn_left();
     
  }
  if(capt1==1 && capt2==0 && capt3==0){
    
        turn_right();
     
}
}
#warning# : the function while(*conditions*) is used in the case of sever deviation from the followed line , in order to
            give more precision of the detection so as the robot re-follow the line correctly .  
