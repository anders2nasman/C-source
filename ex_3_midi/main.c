#include <stdio.h>

#define MIDI_NOTE_OFF   0x80
#define MIDI_NOTE_ON    0x90
#define MIDI_AFTERTOUCH 0xA0
#define MIDI_CONTINUOUS 0xB0
#define MIDI_PATCH_CHANGE 0xC0
#define MIDI_CHANNEL_PRESSURE 0xD0
#define MIDI_PITCH_BEND 0xE0
#define MIDI_SYSTEM 0xF0



int main(void)
{
   int m1,m2,m3,num;
   char midi_command_str[0xff][0x20];
    strcpy(midi_command_str[MIDI_NOTE_OFF],"MIDI_NOTE_OFF");
    strcpy(midi_command_str[MIDI_NOTE_ON],"MIDI_NOTE_ON");
    strcpy(midi_command_str[MIDI_AFTERTOUCH],"MIDI_AFTERTOUCH");
    strcpy(midi_command_str[MIDI_CONTINUOUS],"MIDI_CONTINUOUS");
    strcpy(midi_command_str[MIDI_PATCH_CHANGE],"MIDI_PATCH_CHANGE");
    strcpy(midi_command_str[MIDI_CHANNEL_PRESSURE],"MIDI_CHANNEL_PRESSURE");
    strcpy(midi_command_str[MIDI_PITCH_BEND],"MIDI_PATCH_CHANGE");
    strcpy(midi_command_str[MIDI_SYSTEM],"MIDI_PATCH_CHANGE");

   printf("enter midi message (1-3 hex byte): ");
   scanf("%x%x%x",&m1,&m2,&m3);

   command=m1&0xf0; channel=m1&0x0f;
   switch (command)
   {
   case MIDI_NOTE_OFF:
      printf("%s\n",midi_command_str[m1]);
      break;
   case 2:
      printf("%s\n",midi_command_str[m1]);
      break;
   case 3:
      printf("%s\n",midi_command_str[m1]);
      break;
   case 6:
      printf("%s\n",midi_command_str[m1]);
   case 5:
      printf("%s\n",midi_command_str[m1]);
   case 4:
      printf("%s\n",midi_command_str[m1]);
      break;
   default:
      printf("Input error!\n");
      break;
   }

   return 0;
}

int midi_receive(char c){}

int midi_send(int m) {}


/***



Command

Meaning

# parameters param 1 param 2

0x80  Note-off  2  key  velocity
0x90  Note-on  2  key  veolcity
0xA0  Aftertouch  2  key  touch
0xB0  Continuous controller  2  controller #  controller value
0xC0  Patch change  2  instrument #
0xD0  Channel Pressure  1  pressure
0xE0  Pitch bend  2  lsb (7 bits)  msb (7 bits)
0xF0  (non-musical commands)

#define MIDI_NOTE_OFF   0x80
#define MIDI_NOTE_ON    0x90
#define MIDI_AFTERTOUCH 0xA0
#define MIDI_CONTINUOUS 0xB0
#define MIDI_PATCH_CHANGE 0xC0
#define MIDI_CHANNEL_PRESSURE 0xD0
#define MIDI_PITCH_BEND 0xE0
#define MIDI_SYSTEM 0xF0



command meaning # param

0xF0  start of system exclusive message  variable
0xF1  MIDI Time Code Quarter Frame (Sys Common)
0xF2  Song Position Pointer (Sys Common)
0xF3  Song Select (Sys Common)
0xF4  ???
0xF5  ???
0xF6  Tune Request (Sys Common)
0xF7  end of system exclusive message  0
0xF8  Timing Clock (Sys Realtime)
0xFA  Start (Sys Realtime)
0xFB  Continue (Sys Realtime)
0xFC  Stop (Sys Realtime)
0xFD  ???
0xFE  Active Sensing (Sys Realtime)
0xFF  System Reset (Sys Realtime)
