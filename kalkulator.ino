int number1;
int number2;
int result;
char operation;

void setup()
{
	Serial.begin(9600);
}

void loop()
{
  while(Serial.available() >0)
  {
    number1 = Serial.parseInt();
    operation = Serial.read();
    number2 = Serial.parseInt();
    
    if(number1>99 || number2>99)
    {
      Serial.println("Wprowadz liczbe dwu cyfrowa!");
      break;
    }
    
    if(operation == '/' && number2==0)
    {
      Serial.println("Nie mozna dzielic przez 0!");
      break;
    }
    Calculate();
    Serial.print("Wynik: ");
    Serial.print(result);
    Serial.println();
  }
}

void Calculate() { 
  
  switch (operation) {
    
    case '+' :
    result = number1 + number2;
    break; 
    
    case '-' : 
    result = number1 - number2; 
    break; 
    
    case '*' : 
    result = number1 * number2;
    break; 
    
    case '/' :
    result = number1 / number2; 
    break;
    
    default :
    Serial.println("Wprowadz poprawny symbol");
    result = 0;
    break;
  }
}