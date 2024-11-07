// #include <SPI.h>
// #include "mcp2515_can.h"
// #include <MsTimer2.h> 
 
/*SAMD core*/
// #ifdef ARDUINO_SAMD_VARIANT_COMPLIANCE
//     #define SERIAL SerialUSB
// #else
//     #define SERIAL Serial
// #endif
 
// const int SPI_CS_PIN = 9;
// mcp2515_can CAN(SPI_CS_PIN); // Set CS pin

// int i=0;
 
// void setup() {
//    Serial.begin(9600); 
//    pinMode(4, OUTPUT);
//    digitalWrite(4,LOW);
//    pinMode(5, OUTPUT);
//    digitalWrite(5,LOW);
//    pinMode(6, OUTPUT);
//    digitalWrite(6,LOW);
//    pinMode(7, OUTPUT);
//    digitalWrite(7,LOW);
//    SERIAL.begin(115200);
//    while(!Serial){};
//    while (CAN_OK != CAN.begin(CAN_1000KBPS)) 
//    {             // init can bus : baudrate = 1000k
//         SERIAL.println("CAN BUS Shield init fail");
//         SERIAL.println(" Init CAN BUS Shield again");
//         delay(100);
//     }
    

//     Zero_Set();
//     Enter_Mode();
//     SERIAL.println("CAN BUS Shield init ok!");
    
// }
 
unsigned char stmp[8] = {0, 0, 0, 0, 0, 0, 0, 0};
unsigned char len;
unsigned char buf[8];
unsigned char temp=0;

// void loop() 
// {
    
//     if(digitalRead(4))//进入电机模式
//     {
//      Enter_Mode();
//      SERIAL.println("run");
//     }
//     if(digitalRead(5))//退出电机模式
//     {
//       Exit_Mode();
//       SERIAL.println("exit");
//     }  
//     if(digitalRead(6))//转速模式 旋转
//     {
//       i = 1;
//     } 
//     if(digitalRead(7))//待机模式
//     {
//       i = 0;
//     } 
//     if(i =1)
//     {
//         Cw();
//         delay(10000); //延时10S
//         Ccw();
//         delay(10000); //延时10S
//     }
//     else if(i=0)
//     {
//       Cmd_init();
//     }
    
    
   
// }


void Enter_Mode()
{
      stmp[0] = 0xFF;
      stmp[1] = 0xFF;
      stmp[2] = 0xFF;
      stmp[3] = 0xFF;
      stmp[4] = 0xFF;
      stmp[5] = 0xFF;
      stmp[6] = 0xFF;
      stmp[7] = 0xFC;
      // CAN.sendMsgBuf(0x01, 0, 8, stmp);

      //delay(1000); //延时1S  
}

void Zero_Set()
{
      stmp[0] = 0xFF;
      stmp[1] = 0xFF;
      stmp[2] = 0xFF;
      stmp[3] = 0xFF;
      stmp[4] = 0xFF;
      stmp[5] = 0xFF;
      stmp[6] = 0xFF;
      stmp[7] = 0xFE;
      // CAN.sendMsgBuf(0x01, 0, 8, stmp);

      //delay(1000); //延时1S  
}

void Cw()
{
      stmp[0] = 0x7f;
      stmp[1] = 0xff;
      stmp[2] = 0xA6;
      stmp[3] = 0x50;
      stmp[4] = 0x00;
      stmp[5] = 0x33;
      stmp[6] = 0x37;
      stmp[7] = 0xFF;
      // CAN.sendMsgBuf(0x01, 0, 8, stmp);

      //delay(2000); //延时1S  
}

void Zero()
{
      stmp[0] = 0x7F;
      stmp[1] = 0xFF;
      stmp[2] = 0x7F;
      stmp[3] = 0xF0;
      stmp[4] = 0x51;
      stmp[5] = 0x11;
      stmp[6] = 0xE7;
      stmp[7] = 0xFF;
      // CAN.sendMsgBuf(0x01, 0, 8, stmp);

      //delay(2000); //延时1S  
}

void Ccw()
{
      stmp[0] = 0x7f;
      stmp[1] = 0xff;
      stmp[2] = 0x59;
      stmp[3] = 0x90;
      stmp[4] = 0x00;
      stmp[5] = 0x33;
      stmp[6] = 0x37;
      stmp[7] = 0xFF;
      // CAN.sendMsgBuf(0x01, 0, 8, stmp);

      //delay(2000); //延时1S  
}

void Exit_Mode()
{
      stmp[0] = 0xFF;
      stmp[1] = 0xFF;
      stmp[2] = 0xFF;
      stmp[3] = 0xFF;
      stmp[4] = 0xFF;
      stmp[5] = 0xFF;
      stmp[6] = 0xFF;
      stmp[7] = 0xFD;
      // CAN.sendMsgBuf(0x01, 0, 8, stmp);

      //delay(1000); //延时1S  
}

void Cmd_init()
{
      stmp[0] = 0x7F;
      stmp[1] = 0xFF;
      stmp[2] = 0x7F;
      stmp[3] = 0xF0;
      stmp[4] = 0x00;
      stmp[5] = 0x00;
      stmp[6] = 0x07;
      stmp[7] = 0xFF;
      // CAN.sendMsgBuf(0x01, 0, 8, stmp);

      //delay(1000); //延时1S  
}


// inline byte sendMsgBuf(unsigned long id, byte ext, byte len, const byte *buf) {
//         return sendMsgBuf(id, ext, 0, len, buf, true);
//     }