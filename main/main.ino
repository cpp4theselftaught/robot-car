#include <IRremote.h>
#include "robotstatemachine.h"

/* Infra-red remote codes */
#define BUTTON_UP       16736925
#define BUTTON_DOWN     16754775
#define BUTTON_LEFT     16720605
#define BUTTON_RIGHT    16761405
#define BUTTON_OK       16712445
#define BUTTON_1        16738455
#define BUTTON_2        16750695
#define BUTTON_3        16756815
#define BUTTON_4        16724175
#define BUTTON_5        16718055
#define BUTTON_6        16743045
#define BUTTON_7        16716015
#define BUTTON_8        16726215
#define BUTTON_9        16734885
#define BUTTON_0        16730805
#define BUTTON_STAR     16728765
#define BUTTON_HASH     16732845

/* Pinout */
int const IR_REMOTE_RECV_PIN = 12;
int const ENABLE_A_PIN = 5;
int const ENABLE_B_PIN = 6;
int const DIRECTION_1_PIN = 7;
int const DIRECTION_2_PIN = 8;
int const DIRECTION_3_PIN = 9;
int const DIRECTION_4_PIN = 11;

uint32_t hello = 0;

/* Infra-red receiver and decoder */
IRrecv irrecv(IR_REMOTE_RECV_PIN);
decode_results results;

/* Functions to move the robot */
void goForward(RobotStateMachine_struct *, void*){
  Serial.println("Forward");
  digitalWrite(ENABLE_A_PIN, HIGH);
  digitalWrite(ENABLE_B_PIN, HIGH);
  digitalWrite(DIRECTION_1_PIN, HIGH);
  digitalWrite(DIRECTION_2_PIN, LOW);
  digitalWrite(DIRECTION_3_PIN, LOW);
  digitalWrite(DIRECTION_4_PIN, HIGH);
}

void goBackward(RobotStateMachine_struct *, void*){
  Serial.println("Backward");
  digitalWrite(ENABLE_A_PIN, HIGH);
  digitalWrite(ENABLE_B_PIN, HIGH);
  digitalWrite(DIRECTION_1_PIN, LOW);
  digitalWrite(DIRECTION_2_PIN, HIGH);
  digitalWrite(DIRECTION_3_PIN, HIGH);
  digitalWrite(DIRECTION_4_PIN, LOW);
}

void turnLeft(RobotStateMachine_struct *, void*){
  Serial.println("Left");
  digitalWrite(ENABLE_A_PIN, HIGH);
  digitalWrite(ENABLE_B_PIN, HIGH);
  digitalWrite(DIRECTION_1_PIN, LOW);
  digitalWrite(DIRECTION_2_PIN, HIGH);
  digitalWrite(DIRECTION_3_PIN, LOW);
  digitalWrite(DIRECTION_4_PIN, HIGH); 
}

void turnRight(RobotStateMachine_struct *, void*){
  Serial.println("Right");
  digitalWrite(ENABLE_A_PIN, HIGH);
  digitalWrite(ENABLE_B_PIN, HIGH);
  digitalWrite(DIRECTION_1_PIN, HIGH);
  digitalWrite(DIRECTION_2_PIN, LOW);
  digitalWrite(DIRECTION_3_PIN, HIGH);
  digitalWrite(DIRECTION_4_PIN, LOW);
}

void stop(RobotStateMachine_struct *, void*){
  Serial.println("Stop");
  digitalWrite(ENABLE_A_PIN, LOW);
  digitalWrite(ENABLE_B_PIN, LOW);
  digitalWrite(DIRECTION_1_PIN, LOW);
  digitalWrite(DIRECTION_2_PIN, LOW);
  digitalWrite(DIRECTION_3_PIN, LOW);
  digitalWrite(DIRECTION_4_PIN, LOW);
}

RobotStateMachine_struct state_machine__;

//before execute loop() function, 
//setup() function will execute first and only execute once
void setup() {
  Serial.begin(9600);//open serial and set the baudrate

  irrecv.enableIRIn(); // Start the receiver

  pinMode(DIRECTION_1_PIN, OUTPUT);//before useing io pin, pin mode must be set first 
  pinMode(DIRECTION_2_PIN, OUTPUT);
  pinMode(DIRECTION_3_PIN, OUTPUT);
  pinMode(DIRECTION_4_PIN, OUTPUT);
  pinMode(ENABLE_A_PIN, OUTPUT);
  pinMode(ENABLE_B_PIN, OUTPUT);

  RobotStateMachine_init(
      &state_machine__
    , NULL
    , goBackward
    , goForward
    , turnLeft
    , turnRight
    , stop
    , 1000
    );
}

void loop()
{
  if (irrecv.decode(&results)) {
    irrecv.resume(); // Receive the next value
    switch (results.value)
    {
    case BUTTON_UP :
      Serial.println("button-up");
      RobotStateMachine_onButtonUp(&state_machine__, millis());
      break;
    case BUTTON_DOWN :
      Serial.println("button-down");
      RobotStateMachine_onButtonDown(&state_machine__, millis());
      break;
    case BUTTON_LEFT  :
      Serial.println("button-left");
      RobotStateMachine_onButtonLeft(&state_machine__, millis());
      break;
    case BUTTON_RIGHT   :
      Serial.println("button-right");
      RobotStateMachine_onButtonRight(&state_machine__, millis());
      break;
    case BUTTON_OK      :
      Serial.println("button-OK");
      RobotStateMachine_onButtonOK(&state_machine__, millis());
      break;
    case BUTTON_1       :
      Serial.println("button-1");
      break;
    case BUTTON_2       :
      Serial.println("button-2");
      break;
    case BUTTON_3       :
      Serial.println("button-3");
      RobotStateMachine_onButton3(&state_machine__, millis());
      break;
    case BUTTON_4       :
      Serial.println("button-4");
      break;
    case BUTTON_5       :
      Serial.println("button-5");
      break;
    case BUTTON_6       :
      Serial.println("button-6");
      break;
    case BUTTON_7       :
      Serial.println("button-7");
      break;
    case BUTTON_8       :
      Serial.println("button-8");
      break;
    case BUTTON_9       :
      Serial.println("button-9");
      break;
    case BUTTON_0       :
      Serial.println("button-0");
      break;
    case BUTTON_STAR  :
      Serial.println("button-star");
      break;
    case BUTTON_HASH   :
      Serial.println("button-hash");
      break;
    }
  }
  clock_t update_result(RobotStateMachine_update(&state_machine__, millis()));
  char buffer[30];
  if (update_result != (clock_t)-1)
  {
    sprintf(buffer, "update_result: %lu", update_result);
//    Serial.println(buffer);
  }
}
