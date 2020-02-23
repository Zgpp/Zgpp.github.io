// digital pin 2 has a pushbutton attached to it. Give it a name:
int pushButton = 2;
int ledpin = 3;
int ledpin1 = 5;
int ledpin2 = 6;
boolean pressed = false;
int counter = 0;
int ledcounter = 200;
boolean flipflop = false;

// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  // make the pushbutton's pin an input:
  pinMode(pushButton, INPUT);
  pinMode(ledpin, OUTPUT);
}

// the loop routine runs over and over again forever:
void loop() {
  // read the input pin:
  int buttonState = digitalRead(pushButton);
  // print out the state of the button:
  Serial.print("buttonState: ");
  Serial.print(buttonState); // is either 1 or 0
  delay(1); //delay in between reads for stability
  //HIGH = 1 and LOW = 0
  //digitalWrite(ledpin, buttonstate);

  //If user is pressing button
  if (buttonState == HIGH) {
    pressed = true;

  }

  if (buttonState == LOW && pressed == true) {
    //Do something
    pressed = false;
    Serial.print(" Pressed");
    counter = counter + 1;
  }
  Serial.print("counter");
  Serial.print(counter);

  Serial.println();

  if (counter == 0) {
    digitalWrite(ledpin, LOW);
    digitalWrite(ledpin1, LOW);
    digitalWrite(ledpin2, LOW);
  } else if (counter == 1) {
    analogWrite(ledpin, ledcounter);
    analogWrite(ledpin1, ledcounter);
    analogWrite(ledpin2, ledcounter);
  } else if (counter == 2) {
    
    //sequence
    if (flipflop == false) {
      ledcounter = ledcounter + 2; // same as counter++;
    } else {
      ledcounter = ledcounter - 2;
    }

    if (ledcounter >= 200) {
      //counter = 0;
      flipflop = true;
    }

    if (ledcounter <= 0) {
      flipflop = false;
    }

    analogWrite(ledpin, ledcounter);
    analogWrite(ledpin1, ledcounter);
    analogWrite(ledpin2, ledcounter);
    delay(1);
  } else {
    //else reads if not 0 or 1 or 2 then run code below
    counter = 0;
  }
}
