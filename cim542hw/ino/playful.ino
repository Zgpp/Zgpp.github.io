  int ledpin1 = 3;
  int ledpin2 = 4;
  int ledpin3 = 5;
  int ledpin4 = 6;
  int ledpin5 = 7;
  int ledpin6 = 8;
  int ledpin7 = 9;
  int ledpin8 = 10;
  int ledpin9 = 11;
  int input = 2;
  int plus = 12;
  int equal = 13;
  boolean inputPressed = false;
  boolean plusPressed = false;
  boolean equalPressed = false;
  int counter = 2;
  int firstNumber = 0;
  int secondNumber = 0;
  int result = 0;



void setup()
{
  Serial.begin(9600);
  pinMode(input, INPUT);
  pinMode(plus, INPUT);
  pinMode(equal, INPUT);
  pinMode(ledpin1, OUTPUT);
  pinMode(ledpin2, OUTPUT);
  pinMode(ledpin3, OUTPUT);
  pinMode(ledpin4, OUTPUT);
  pinMode(ledpin5, OUTPUT);
  pinMode(ledpin6, OUTPUT);
  pinMode(ledpin7, OUTPUT);
  pinMode(ledpin8, OUTPUT);
  pinMode(ledpin9, OUTPUT);

}

void loop()
{
  // read the input pin:
  int inputState = digitalRead(input);
  int plusState = digitalRead(plus);
  int equalState = digitalRead(equal);
  
  // print out the state of the input:
  Serial.print("inputState: ");
  Serial.print(inputState); // is either 1 or 0
  delay(1); //delay in between reads for stability

  //If user is pressing inputButton
  if (inputState == HIGH) {
    inputPressed = true;

  }

  if (inputState == LOW && inputPressed == true) {
    //Do something
    inputPressed = false;
    Serial.print(" Pressed");
    counter = counter + 1;
    digitalWrite(counter, HIGH);
  }
  Serial.print("counter");
  Serial.print(counter);
  Serial.println();

  //If user is pressing plusButton
  if (plusState == HIGH){
    plusPressed = true;
  }
  
  if(plusState == LOW && plusPressed == true){
    plusPressed = false;
    firstNumber = counter - 2;
    counter = 2;
    digitalWrite(ledpin1, LOW);
    digitalWrite(ledpin2, LOW);
    digitalWrite(ledpin3, LOW);
    digitalWrite(ledpin4, LOW);
    digitalWrite(ledpin5, LOW);
    digitalWrite(ledpin6, LOW);
    digitalWrite(ledpin7, LOW);
    digitalWrite(ledpin8, LOW);
    digitalWrite(ledpin9, LOW);
  	}
  
  //If user is pressing equalButton
  if (equalState == HIGH){
    equalPressed = true;
  }
  
  if(equalState == LOW && equalPressed == true){
    equalPressed = false;
    secondNumber = counter - 2;
    result = firstNumber + secondNumber;
    for(int i = 0; i <= result ; i++ ){
    	digitalWrite(i + 2, HIGH);
    }
  }
  
}