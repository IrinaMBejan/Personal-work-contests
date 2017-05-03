#include <QTRSensors.h>

#define MlF 7
#define MlB 8
#define MrF 4
#define MrB 5
#define STBY 6
QTRSensorsAnalog qtra((unsigned char[]) {1,0,2,3,4,5,6,7}, 8,1);

int BS=170;
int MaxS=255;
int MinS=-255;
double Kp=0.013;
double Kd=0.03;
double Ki=0;

unsigned int sen[8];
int pos,ok1,ok2,Mls,Mrs,e,P,D,I,Out,Le,i;
char last;

void move(int motor, int speed, int direction)
{
  //motor: 0 - B
        // 1 - A
  //0 clockwise, 1 counter-clockwise

  //iesire din standby

  boolean inPin1 = LOW;
  boolean inPin2 = HIGH;

  if(direction == 1)
  {
    inPin1 = HIGH;
    inPin2 = LOW;
  }

  if(motor == 1)
  {
    digitalWrite(MrF, inPin1);
    digitalWrite(MrB, inPin2);
    analogWrite(9, speed);
  }
  else
  {
    digitalWrite(MlF, inPin1);
    digitalWrite(MlB, inPin2);
    analogWrite(3, speed);
  }
}


void motor(int vl,int vr)
{
    if (vl<-255) vl=-255;
    if (vl>255) vl=255;
    if (vr<-255) vr=-255;
    if (vr>255) vr=255;
    if (vl>=0) move(0,vl,0);
    else move(0,-vl,1);
    if (vr>=0) move(1,vr,0);
    else move(1,-vr,1);
}



void setup()
{
    int i;
    pinMode(13,OUTPUT);
    pinMode(MlF,OUTPUT);
    pinMode(MlB,OUTPUT);
    pinMode(MrF,OUTPUT);
    pinMode(MrB,OUTPUT);
    pinMode(3,OUTPUT);
    pinMode(9,OUTPUT);
    pinMode(STBY,OUTPUT);

    Serial.begin(9600);
    digitalWrite(STBY, HIGH);
    delay(500);

    //Calibrare
    for (i=0;i<=100;i++)
    {
      qtra.calibrate();
      delay(20);
    }

    for (i=1;i<=10;i++)
    {
        digitalWrite(13,HIGH);
        delay(100);
        digitalWrite(13,LOW);
        delay(100);
    }
    delay(1000);
}

void citire()
{
    int i;
    pos=qtra.readLine(sen);
    for (i=0;i<8;i++)
    {
        if (sen[i]<100)
            sen[i]=0;
        Serial.print(sen[i]);
        Serial.print('\t');
    }
    Serial.println();
}

void PID()
{
   e=pos-3500;
   P=e;
   D=e-Le;
   I+=e;
   Out=P*Kp+I*Ki+D*Kd;
   Le=e;
}

void loop()
{
    citire();

    ok1=1;ok2=0;
    for (i=0;i<=7;i++)
    {
        if (sen[i]==0)
            ok1=0;
        if (sen[i]>500)
            ok2=1;
    }

    if (!ok2)
    {
        if (last=='r')
            motor(30,MaxS);
        else if (last=='l')
            motor(MaxS,30);
        else
            motor(BS,BS);
    }
    else if (!ok1)
    {
        if (sen[0]>100)
            last='l';
        else if (sen[7]>100)
            last='r';
        else if (sen[3]>100 || sen[4]>100)
            last='n';

        PID();

        Mls=BS-Out;
        Mrs=BS+Out;

        if (Mrs>255)
        {
            Mls-=Mrs-255;
            Mrs=255;
        }

        if (Mls>255)
        {
            Mrs-=Mls-255;
            Mls=255;
        }

        if (Mrs<-255)
        {
            Mls+=Mrs+255;
            Mrs=-255;
        }

        if (Mls<-255)
        {
            Mrs+=Mls+255;
            Mls=-255;
        }

        motor(Mls,Mrs);
    }
}
