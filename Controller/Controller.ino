//#include <Arduino.h>
//#include "controller\watering_controller_AVR.c"
#include "watering_controller_AVR.c"
void rt_oneStep(void);
void comm(void);

unsigned char cmd;
unsigned char reg;
unsigned char value1;
unsigned char value2;
enum
{
  Moisture,
  UpperThreshold,
  LowerThreshold,
  ManualAuto,
  OnOff,
  Valve
};
unsigned int REG[6] = {0,100,20,1,0,0};

void setup() {
  Serial1.begin(9600);
  Serial.begin(9600);
  pinMode(13,OUTPUT);
  watering_controller_AVR_initialize();
}

void loop() {
  comm();
  rt_oneStep();
  //Serial.println(analogRead(0));
}

void comm() {
  if(Serial1.available()>0)
  {
    static int Bytes=0;
    Bytes++;
    if(Bytes==1)
    {
      cmd = Serial1.read();
    }
    if(Bytes==2)
    {
      reg = Serial1.read();
    }
    if(Bytes==3)
    {
      value1 = Serial1.read();
    }
    if(Bytes==4)
    {
      value2 = Serial1.read();
    }
    
    if(Bytes==4)
    {
      if(cmd =='A')
      {
        unsigned int value = analogRead(0);
        unsigned int value_L = value&255;
        unsigned int value_H = value>>8;
        Serial1.write(value_H);
        Serial1.write(value_L);
      }
      else if(cmd == 'W')
      {
        REG[reg] = value2 + (value1<<8);
      }
      else if(cmd == 'R')
      {
        unsigned int value = REG[reg];
        unsigned int value_L = value&255;
        unsigned int value_H = value>>8;
        Serial1.write(value_H);
        Serial1.write(value_L);

      }
      Bytes=0;
    }  
  }
}

void key()
{

}

void rt_oneStep(void)
{
  static boolean_T OverrunFlag = false;

  if (OverrunFlag) {
    rtmSetErrorStatus(watering_controller_AVR_M, "Overrun");
    return;
  }

  OverrunFlag = true;
  REG[Moisture] = analogRead(0);
  watering_controller_AVR_U.Dampness = REG[Moisture];
  watering_controller_AVR_U.Manual_Automatic = REG[ManualAuto];
  watering_controller_AVR_U.Manual_On_Off = REG[OnOff];
  watering_controller_AVR_U.Upper_threshold = REG[UpperThreshold];
  watering_controller_AVR_U.Lower_threshold = REG[LowerThreshold];

  watering_controller_AVR_output();
  watering_controller_AVR_update();
  REG[Valve] = watering_controller_AVR_Y.ValveRelay;
  //Serial.println(REG[Valve]);
  Serial.println(REG[UpperThreshold]);
  Serial.println(REG[LowerThreshold]);
  digitalWrite(13,REG[Valve]);
  /* Indicate task complete */
  OverrunFlag = false;

}

