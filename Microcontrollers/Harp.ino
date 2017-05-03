#include <SoftwareSerial.h>

//Music Shield Stuff
SoftwareSerial mySerial(2, 3); // RX, TX
byte resetMIDI = 4; //Tied to VS1053 Reset line
byte ledPin = 13; //MIDI traffic inidicator
int max[8]; //The aprox. maximum value that can be reached while on laser beam
int note[25]={0x30, 0x32, 0x34, 0x36, 0x38, 0x39, 0x37, 0x35, 0x33, 0x31,0x30, 0x32, 0x34, 0x36, 0x38, 0x39, 0x37, 0x35, 0x33, 0x31};

//int instrument[6]={1, 6, 104, 89, 36, 78};
int instrument[6]={1, 23, 41, 53, 86, 65};
//int instrument[6]={76, 118, 97,100};
//int instrument[6]={6,7,95,101,107,113}

int s[6];
unsigned int Delta;

void setup()
{
      //Music Shield
       mySerial.begin(31250); //Setup soft serial for MIDI control
       pinMode(resetMIDI, OUTPUT); //Reset the VS1053
       digitalWrite(resetMIDI, LOW);
       delay(100);
       digitalWrite(resetMIDI, HIGH);
       delay(100);
       talkMIDI(0xB0, 0x07, 120); //0xB0 is channel message, set channel volume to near max (127)
     //  talkMIDI(0xB0, 0, 0x00); //Default bank GM1

        //Photoresistor
         Serial.begin(9600);
        if(analogRead(A0)>max[0]) max[0]=analogRead(A0);
        if(analogRead(A1)>max[1]) max[1]=analogRead(A1);
        if(analogRead(A2)>max[2]) max[2]=analogRead(A2);
        if(analogRead(A3)>max[3]) max[3]=analogRead(A3);
        if(analogRead(A4)>max[4]) max[4]=analogRead(A4);
        if(analogRead(A5)>max[5]) max[5]=analogRead(A5);

        for(int i=0;i<6; ++i)
          max[i]+=100;
}

int DeltaNew[10];

void loop()
{
  talkMIDI(0xB0, 0, 0x00); //Default bank GM1

  Serial.print(analogRead(A0));
  Serial.print('\t');
  Serial.print(analogRead(A1));
  Serial.print('\t');
  Serial.print(analogRead(A2));
  Serial.print('\t');
  Serial.print(analogRead(A3));
  Serial.print('\t');
  Serial.print(analogRead(A4));
  Serial.print('\t');
  Serial.print(analogRead(A5));
  Serial.print('\n');

  s[0]=analogRead(A0);
  s[1]=analogRead(A1);
  s[2]=analogRead(A2);
  s[3]=analogRead(A3);
  s[4]=analogRead(A4);
  s[5]=analogRead(A5);

  for(int i=0;i<6;i++)
      Modul(i);

  for(int i=0;i<6;i++)
  if(DeltaNew[i]!=-999)
  {
     talkMIDI(0xC0, instrument[i], 0);
     noteOn(0, note[DeltaNew[i]], 90);

  }
  delay(150);

  for(int i=0;i<6;i++)
    if(DeltaNew[i]!=-999)
  {
     talkMIDI(0xC0, instrument[i], 0);
     noteOff(0, note[DeltaNew[i]], 90);
  }
  delay(50);
}

void Modul(int k)
{
  DeltaNew[k]=-999;
  if (s[k] > max[k])
   {
     Delta=s[k]-max[k];
     Delta/=50;
     DeltaNew[k]=Delta;
   }
}

void noteOn(byte channel, byte note, byte attack_velocity)
{
  talkMIDI( (0x90 | channel), note, attack_velocity);
}

//Send a MIDI note-off message.  Like releasing a piano key
void noteOff(byte channel, byte note, byte release_velocity)
{
  talkMIDI( (0x80 | channel), note, release_velocity);
}

//Plays a MIDI note.
void talkMIDI(byte cmd, byte data1, byte data2)
{
  digitalWrite(ledPin, HIGH);
  mySerial.write(cmd);
  mySerial.write(data1);

  if( (cmd & 0xF0) <= 0xB0)
    mySerial.write(data2);

  digitalWrite(ledPin, LOW);
}
