const uint8_t SW1=3;
const uint8_t SW2=4;
const uint8_t SW3=5;
const uint8_t M1=8;
const uint8_t M2=9;
int liczbaWlacz = 0;
bool PowerOn = false;
bool States[6] = {0,0,0,0,0,0};

void ButtonRead()
{
	States[0] = States[1];
	States[2] = States[3];
	States[4] = States[5];
	States[1] = digitalRead(SW1);
	States[3] = digitalRead(SW2);
	States[5] = digitalRead(SW3);
}
bool StateChange(bool State1, bool State2)
{
	return State1 == LOW && State2 == HIGH;
}

void setup()
{
   Serial.begin(9600);
   pinMode(SW1, INPUT);
   pinMode(SW2, INPUT);
   pinMode(SW3, INPUT);
   pinMode(M1, OUTPUT);
   pinMode(M2, OUTPUT);
   digitalWrite(M1,LOW);
   digitalWrite(M2,LOW);
}


void loop()
{
	
ButtonRead();
  
 if(StateChange(States[0], States[1]))
  {
      PowerOn = !PowerOn;
      liczbaWlacz++;
   	  digitalWrite(M1,LOW);
      digitalWrite(M2,LOW);
  }

  if(StateChange(States[2], States[3]) && PowerOn)
  {
      digitalWrite(M1,HIGH);
      digitalWrite(M2,LOW);
  }

if(StateChange(States[4], States[5]) && PowerOn)
  {
      digitalWrite(M1,LOW);
      digitalWrite(M2,HIGH);
  }
  Serial.println(liczbaWlacz);
}
