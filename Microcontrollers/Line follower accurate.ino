#include <QTRSensors.h>
#define NUM_SENSORS             8  // numar senzori
#define NUM_SAMPLES_PER_SENSOR  4  // numarul de citiri analogice per citire senzor
#define EMITTER_PIN             2  // pin emitter

//senzori
QTRSensorsAnalog qtra((unsigned char[]) {0, 1, 2, 3, 4, 5, 6, 7}, NUM_SENSORS, NUM_SAMPLES_PER_SENSOR, EMITTER_PIN);
unsigned int sensorValues[NUM_SENSORS];

//Motor A
int PWMA = 9; //Pin viteza
int AIN1 = 7; //Dir
int AIN2 = 8; //Dir

//Motor B
int PWMB = 3; //Pin viteza
int BIN1 = 5; //Dir
int BIN2 = 4; //Dir
int STBY = 6; //stand=by

//PID constants
const float Kp = .025;
const float Kd = 0.03;
const float Ki = 0.001;
const float MaxSpeed = 170;

int Eroare, PrevEroare=0, EroareAcumulata=0;
int Viteza, VitezaA, VitezaB;

unsigned int Pozitie;

void setup()
{
  pinMode(STBY, OUTPUT);

  pinMode(PWMA, OUTPUT);
  pinMode(AIN1, OUTPUT);
  pinMode(AIN2, OUTPUT);

  pinMode(PWMB, OUTPUT);
  pinMode(BIN1, OUTPUT);
  pinMode(BIN2, OUTPUT);

  for (int i = 0; i < 100; i++)  // make the calibration take about 10 seconds
  {
    qtra.calibrate();       // reads all sensors 10 times at 2.5 ms per six sensors (i.e. ~25 ms per call)
  }

  Serial.begin(9600);
  /*for (int i = 0; i < NUM_SENSORS; i++)
  {
    Serial.print(qtra.calibratedMinimumOn[i]);
    Serial.print(' ');
  }
  Serial.println();

  for (int i = 0; i < NUM_SENSORS; i++)
  {
    Serial.print(qtra.calibratedMaximumOn[i]);
    Serial.print(' ');
  }
  Serial.println();
  Serial.println();*/
  delay(1000);
}

void loop()
{
  UrmaresteLinie();
}

void UrmaresteLinie()
{
  CitireSenz();
  PID();
  MiscaPID();

}

void CitireSenz()
{
  Pozitie = qtra.readLine(sensorValues);
}

void PID()
{
    PrevEroare = Eroare; //Derivata
    Eroare = Pozitie - 3500;
    EroareAcumulata += Eroare; //Integrala

    Viteza = (Kp * Eroare) + (Kd * (Eroare - PrevEroare)) + ( Ki * EroareAcumulata);

    if (Viteza > MaxSpeed) Viteza = MaxSpeed;
    if (Viteza < -MaxSpeed) Viteza = -MaxSpeed;

    if (Viteza < 0) // Intoarce stanga
    {
      VitezaA = MaxSpeed - abs( int(Viteza) );
      VitezaB = MaxSpeed;
    }

    else // Intoarce dreapta
    {
      VitezaA = MaxSpeed;
      VitezaB = MaxSpeed - int(Viteza);
    }
    for (unsigned char i = 0; i < NUM_SENSORS; i++)
    {
      Serial.print(sensorValues[i]);
      Serial.print('\t');
    }
    Serial.print(Pozitie);
    Serial.print('\t');
    Serial.print(Eroare);
    Serial.print('\t');
    Serial.print(Kp*Eroare);
    Serial.print('\t');
    Serial.print((Kd * (Eroare - PrevEroare)));
    Serial.print('\t');

    Serial.print(Viteza);
    Serial.print('\t');
    Serial.print(VitezaA);
    Serial.print('\t');
    Serial.println(VitezaB);
}

void MiscaPID()
{
    move(1, VitezaA, 0);
    move(0, VitezaB, 1);
}

void move(int motor, int speed, int direction)
{
    //motor: 0 - B
          // 1 - A
    //0 clockwise, 1 counter-clockwise

    digitalWrite(STBY, HIGH); //iesire din standby

    boolean inPin1 = LOW;
    boolean inPin2 = HIGH;

    if(direction == 1)
    {
      inPin1 = HIGH;
      inPin2 = LOW;
    }

    if(motor == 1)
    {
      digitalWrite(AIN1, inPin1);
      digitalWrite(AIN2, inPin2);
      analogWrite(PWMA, speed);
    }
    else
    {
      digitalWrite(BIN1, inPin1);
      digitalWrite(BIN2, inPin2);
      analogWrite(PWMB, speed);
    }
}

void stop()
{
    //intrare in Standby
    digitalWrite(STBY, LOW);
}
