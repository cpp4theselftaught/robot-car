#include <timer-api.h>
#include <timer_setup.h>
#include <IRremote.h>

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

/* Infra-red receiver and decoder */
IRrecv irrecv(IR_REMOTE_RECV_PIN);
decode_results results;

/* 1 KHz timer */
unsigned long long tick_count = 0;
unsigned int restant = 0;
void timer_handle_interrupts(int timer)
{
  if (restant) --restant;
  tick_count++;
}

/* Functions to move the robot */
void goForward(){ 
  digitalWrite(ENABLE_A_PIN, HIGH);
  digitalWrite(ENABLE_B_PIN, HIGH);
  digitalWrite(DIRECTION_1_PIN, HIGH);
  digitalWrite(DIRECTION_2_PIN, LOW);
  digitalWrite(DIRECTION_3_PIN, LOW);
  digitalWrite(DIRECTION_4_PIN, HIGH);
}

void goBackward(){
  digitalWrite(ENABLE_A_PIN, HIGH);
  digitalWrite(ENABLE_B_PIN, HIGH);
  digitalWrite(DIRECTION_1_PIN, LOW);
  digitalWrite(DIRECTION_2_PIN, HIGH);
  digitalWrite(DIRECTION_3_PIN, HIGH);
  digitalWrite(DIRECTION_4_PIN, LOW);
}

void turnLeft(){
  digitalWrite(ENABLE_A_PIN, HIGH);
  digitalWrite(ENABLE_B_PIN, HIGH);
  digitalWrite(DIRECTION_1_PIN, LOW);
  digitalWrite(DIRECTION_2_PIN, HIGH);
  digitalWrite(DIRECTION_3_PIN, LOW);
  digitalWrite(DIRECTION_4_PIN, HIGH); 
}

void turnRight(){
  digitalWrite(ENABLE_A_PIN, HIGH);
  digitalWrite(ENABLE_B_PIN, HIGH);
  digitalWrite(DIRECTION_1_PIN, HIGH);
  digitalWrite(DIRECTION_2_PIN, LOW);
  digitalWrite(DIRECTION_3_PIN, HIGH);
  digitalWrite(DIRECTION_4_PIN, LOW);
}

void stop(){
  digitalWrite(ENABLE_A_PIN, LOW);
  digitalWrite(ENABLE_B_PIN, LOW);
  digitalWrite(DIRECTION_1_PIN, LOW);
  digitalWrite(DIRECTION_2_PIN, LOW);
  digitalWrite(DIRECTION_3_PIN, LOW);
  digitalWrite(DIRECTION_4_PIN, LOW);
}

#define GAUCHE 0
#define DROIT 1

void pirouette(int la_direction, unsigned int duree, bool arret_apres)
{
  if (la_direction == GAUCHE)
    turnLeft();
  else
    turnRight();
  delay(duree);
  if (arret_apres)
    stop();
}

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

  timer_init_ISR_1KHz(TIMER_DEFAULT);
}

void dancer() {
  int compte = 0;
debut:
  goForward();
  delay(1000);
  goBackward();
  delay(1000);
  turnLeft();
  delay(1000);
  turnRight();
  delay(1000);

  compte = compte + 1;
  if (compte < 5)
    goto debut;

  stop();
  delay(500);

  pirouette(DROIT, 5000, true);

  for (int i = 0; i < 2; ++i)
  {
    goForward();
    delay(500);
    goBackward();
    delay(500);
  }
  pirouette(DROIT, 5000, true);

  pirouette(GAUCHE, 5000, true);

  stop();
}

void loop()
{
  if (irrecv.decode(&results)) {
    irrecv.resume(); // Receive the next value
    switch (results.value)
    {
    case BUTTON_UP :
      goForward();
      break;
    case BUTTON_DOWN :
      goBackward();
      break;
    case BUTTON_LEFT  :
      turnLeft();
      break;
    case BUTTON_RIGHT   :
      turnRight();
      break;
    case BUTTON_OK      :
      stop();
      break;
    case BUTTON_1       :
      break;
    case BUTTON_2       :
      break;
    case BUTTON_3       :
      dancer();
      break;
    case BUTTON_4       :
      break;
    case BUTTON_5       :
      break;
    case BUTTON_6       :
      break;
    case BUTTON_7       :
      break;
    case BUTTON_8       :
      break;
    case BUTTON_9       :
      break;
    case BUTTON_0       :
      break;
    case BUTTON_STAR  :
      break;
    case BUTTON_HASH   :
      break;
    }
  }
}
