const int stepPin1 = 2; 
const int dirPin1 = 5; 
const int stepPin2 =3; 
const int dirPin2 = 6; 
const int stepPin3 = 4; 
const int dirPin3 = 7;
int ch1;
int ch2;
int ch5;

int R=A3;
int L=A5;

int verticle;
int horizontal;
void setup(){
Serial.begin(9600);
pinMode(stepPin1,OUTPUT); 
pinMode(dirPin1,OUTPUT);
pinMode(stepPin2,OUTPUT); 
pinMode(dirPin2,OUTPUT);
pinMode(stepPin3,OUTPUT); 
pinMode(dirPin3,OUTPUT);
pinMode(A0,INPUT);
pinMode(A1,INPUT);
pinMode(A2,INPUT);
pinMode(R,OUTPUT);
pinMode(L,OUTPUT);
}
void loop()
{
rf();
while(verticle>80){
fwd();
rf();
}
while(verticle<20){
bck();
rf();
}
while(horizontal>80){
lft();
rf();
}
while(horizontal<20){
rgt();
rf();
}
if(ch5>80){
clk();
}
else if(ch5<20){
nomove();
}
else{
aclk();
}

}
void fwd()
{ 
//one revolution
for(int x = 0; x < 3300; x++)
{
digitalWrite(dirPin1,LOW);
digitalWrite(stepPin1,HIGH); 
delayMicroseconds(300); 
digitalWrite(stepPin1,LOW); 
delayMicroseconds(300); 

digitalWrite(dirPin2,LOW);
digitalWrite(stepPin2,HIGH); 
delayMicroseconds(300); 
digitalWrite(stepPin2,LOW); 
delayMicroseconds(300); 
}
}
void bck()
{ 
for(int x = 0; x < 3300; x++)
{
digitalWrite(dirPin1,HIGH);
digitalWrite(stepPin1,HIGH); 
delayMicroseconds(300); 
digitalWrite(stepPin1,LOW); 
delayMicroseconds(300); 

digitalWrite(dirPin2,HIGH);
digitalWrite(stepPin2,HIGH); 
delayMicroseconds(300); 
digitalWrite(stepPin2,LOW); 
delayMicroseconds(300); 
}
}
void lft()
{
for(int x = 0; x < 3300; x++)
{
digitalWrite(dirPin1,LOW);
digitalWrite(stepPin1,HIGH); 
delayMicroseconds(300); 
digitalWrite(stepPin1,LOW); 
delayMicroseconds(300); 

digitalWrite(dirPin2,HIGH);
digitalWrite(stepPin2,HIGH); 
delayMicroseconds(300); 
digitalWrite(stepPin2,LOW); 
delayMicroseconds(300); 
}
}


void rgt()
{
for(int x = 0; x < 3300; x++)
{
digitalWrite(dirPin1,HIGH);
digitalWrite(stepPin1,HIGH); 
delayMicroseconds(300); 
digitalWrite(stepPin1,LOW); 
delayMicroseconds(300); 

digitalWrite(dirPin2,LOW);
digitalWrite(stepPin2,HIGH); 
delayMicroseconds(300); 
digitalWrite(stepPin2,LOW); 
delayMicroseconds(300); 
}
}
//throwawayfunction
void nomove()
{
digitalWrite(R,HIGH);
digitalWrite(L,HIGH);
}

void clk()
{ 
digitalWrite(R,HIGH);
digitalWrite(L,LOW);
}

void aclk()
{ 
digitalWrite(R,LOW);
digitalWrite(L,HIGH);
}

//radiofunction
void rf(){
ch1 = pulseIn(A0,HIGH);
ch2 = pulseIn(A1,HIGH); 
ch5=pulseIn(A2,HIGH);

ch5=map(ch5,1000,2000,0,100);

verticle=map(ch1,1000,2000,0,100);
horizontal=map(ch2,1000,2000,0,100);

}
