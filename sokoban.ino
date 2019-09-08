// Sokoban 
// By AlexSolex

const int btnUp    = 2;    // the number of the pushbutton pin
const int btnDown  = 4;    // the number of the pushbutton pin
const int btnLeft  = 5;    // the number of the pushbutton pin
const int btnRight = 6;    // the number of the pushbutton pin

const int IN1 = 8; // Y axis motor in1 pin number
const int IN2 = 9; // X axis motor in2 pin number
const int ENA = 3;
const int IN3 = 12; // Y axis motor in3 pin number
const int IN4 = 13; // X axis motor in4 pin number
const int ENB = 10;

const int SPEED = 200;

int axeX = 0;
int axeY = 0;
void setup() {
  Serial.begin(9600);
  // put your setup code here, to run once:
  pinMode(IN1, OUTPUT); // Définition de IN1 en tant que sortie moteur X
  pinMode(IN2, OUTPUT); // Définition de IN2 en tant que sortie moteur Y
  pinMode(IN3, OUTPUT); // Définition de IN2 en tant que sortie moteur Y
  pinMode(IN4, OUTPUT); // Définition de IN2 en tant que sortie moteur Y
  pinMode(btnUp,   INPUT); // Définition du bouton haut
  pinMode(btnDown, INPUT); // Définition du bouton bas
  pinMode(btnLeft, INPUT); // Définition du bouton gauche
  pinMode(btnRight, INPUT); // Définition du bouton droite
}

void loop() {
  analogWrite(ENA,250);
  analogWrite(ENB,250);
  // Y axis
  if (digitalRead(btnUp)== HIGH) {
    runMotor(IN1,IN2,HIGH);
    axeY = 1;
  } else {
    if (digitalRead(btnDown) == HIGH) {
      runMotor(IN1,IN2,LOW);
      axeY = -1;
    }
    else {
      stopMotor(IN1,IN2);
      axeY = 0;
    }
  }
  // X axis
  if (digitalRead(btnLeft)== HIGH) {
    runMotor(IN3,IN4,LOW);
    axeX = -1;
  } else {
    if (digitalRead(btnRight) == HIGH) {
      runMotor(IN3,IN4,HIGH);
      axeX = 1;
    }
    else {
      stopMotor(IN3,IN4);
      axeX = 0;
    }
  }

  Serial.println("X="+ String(axeX) + "/Y="+ String(axeY));

  delay(50);
}

void stopMotor(int in1Motor, int in2Motor) {
  digitalWrite(in1Motor,LOW);
  digitalWrite(in2Motor,LOW);
  
}

void runMotor(int inMotor1, int inMotor2, int way) {
  Serial.println("moteur way:"+ String(way));
  if (way == HIGH){
    digitalWrite(inMotor1,HIGH); // Sens de rotation du moteur 1
    digitalWrite(inMotor2,LOW); // Sens de rotation du moteur 1
  }
  else {
    digitalWrite(inMotor1,LOW); // Sens de rotation du moteur 1
    digitalWrite(inMotor2,HIGH); // Sens de rotation du moteur 1
  }
}
