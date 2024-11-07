#include <ESP32-TWAI-CAN.hpp>
#include <LiquidCrystal_I2C.h>
#include "Motor.h"

// Default for ESP32
#define CAN_TX		5
#define CAN_RX		4

#define INCREASE_MOTOR_POS 3000U
#define DECREASE_MOTOR_POS 1000U

Motor motor1(0x02);
CanFrame rxFrame;

/******************************************************/
void sendCANMessage(CanFrame* msg){
    ESP32Can.writeFrame(msg);
}

/******************************************************/
void receivedCANMessage(CanFrame* msg){
    ESP32Can.readFrame(msg);
}

void setup() {
    Serial.begin(115200);
    while (!Serial) {};

/*-----------------------CAN SETUP---------------------------*/
    //Set pins
    pinMode(CAN_TX, OUTPUT);
    pinMode(CAN_RX, OUTPUT);
	ESP32Can.setPins(CAN_TX, CAN_RX);
	
    // set Rx/Tx queue
    ESP32Can.setRxQueueSize(5);
	ESP32Can.setTxQueueSize(5);

    ESP32Can.setSpeed(ESP32Can.convertSpeed(1000));//CAN Speed: 1 MHZ

    if(ESP32Can.begin()) {
        Serial.println("CAN bus started!");
    } else {
        Serial.println("CAN bus failed!");
    }
/*-----------------------MOTOR SETUP-----------------------*/
    // CanFrame setup;
    // motor1.zeroSet(&setup);
    // sendCANMessage(&setup);
    // motor1.enterMode(&setup);
    // sendCANMessage(&setup);
}

void loop() {
    CanFrame loop;
    char rc;  
    rc = Serial.read();
    delay(500);
    if(rc == 'e'){
        motor1.exitMode(&loop);
        sendCANMessage(&loop);
        Serial.println("Exit mode");
    }
    else if(rc == 's'){
        motor1.enterMode(&loop);
        sendCANMessage(&loop);
        Serial.println("Enter mode");
    }
    else if(rc == 'l'){
        motor1.zeroSet(&loop);
        sendCANMessage(&loop);
        Serial.println("Zero set");
    }
    else if(rc == 'a'){
        motor1.pack_cmd(&loop,0.0, 1.0, 0.0F, 0.0F, 0.0F );
        sendCANMessage(&loop);
        Serial.println("Command send: a");
    }
    else if(rc == 'b'){
        motor1.pack_cmd(&loop,0, 0.0, 0.0F, 0.0F, 0.0F );
        sendCANMessage(&loop);
        Serial.println("Command send: got to 3");
    }
    
}


