//-----------------------------------------------------------------------------
// SpotMini pins Mega2560
// 2020-04-11 dan@marginalllyclever.com
// 12 servos * 300ma/servo <= 4A.  Make sure you have at least 12v4a or the servos won't turn together.
// See also https://forum.arduino.cc/index.php?topic=13779.msg102414#msg102414
//-----------------------------------------------------------------------------

#define NUM_LEGS 4
#define JOINTS_PER_LEG 3
#define NUM_SERVOS (NUM_LEGS*JOINTS_PER_LEG)

//code > mega > ASPv4 (ELEC-0132) > servo connections
//leg joint/leg address/PCB Schematic/PCB stencil/Arduino Mega analog pin/Arduino mega digital pin
#define LEG_2_2 (58)  //front left knee     /22/input5/p2 /A4/d58  
#define LEG_2_1 (57)  //front left shoulder /21/input4/p3 /A3/d57  
#define LEG_2_0 (56)  //front left torso    /20/input3/p4 /A2/d56  
#define LEG_3_2 (55)  //front right knee    /32/input2/p5 /A1/d55  
#define LEG_3_1 (54)  //front right shoulder/31/input1/p6 /A0/d54  
#define LEG_3_0 (60)  //front right torso   /30/input7/p23/A6/d60

#define LEG_1_0 ( 2)  //back left torso    /10/output1/p7 /~/d2
#define LEG_1_1 ( 4)  //back left shoulder /11/output2/p8 /~/d4
#define LEG_1_2 ( 5)  //back left knee     /12/output3/p9 /~/d5
#define LEG_0_0 ( 8)  //back right torso   /00/output4/p10/~/d8
#define LEG_0_1 ( 9)  //back right shoulder/01/output5/p11/~/d9
#define LEG_0_2 (10)  //back right knee    /02/output6/p12/~/d10


#include <Servo.h>


Servo muscle[NUM_SERVOS];

void setup() {
  Serial.begin(57600);
  Serial.println(F("Waking"));

#define Sn(JJ,KK)  { muscle[i++].attach( LEG_##JJ##_##KK ); }
#define Sn2(JJ)    {  Sn(JJ,0);  Sn(JJ,1);  Sn(JJ,2);  }
  int i = 0;
  Sn2(0);
  Sn2(1);
  Sn2(2);
  Sn2(3);

  // put all servos to middle position.
  for (int i = 0; i < NUM_SERVOS; ++i) {
    muscle[i].write(90);
  }

  Serial.println(F("Ready"));
}


void loop() {
}
