int relayFans = 2;
int button1 = 3;
int relayHeat = 4;
int button2 = 5;
int button3 = 6;

unsigned long fanStartTime = 0;
unsigned long heatToggleTime = 0;

bool heatState = HIGH;

void setup() {
  pinMode(relayFans, OUTPUT);
  pinMode(relayHeat, OUTPUT);
  pinMode(button1, INPUT_PULLUP);
  pinMode(button2, INPUT_PULLUP);
  pinMode(button3, INPUT_PULLUP);
  digitalWrite(relayFans, HIGH);
  digitalWrite(relayHeat, HIGH);
}

void loop() {
  if (digitalRead(button1) == HIGH) { 
    fanStartTime = millis(); 
    digitalWrite(relayFans, LOW); 
  }
  
 
  if (millis() - fanStartTime >= 10000) {
    digitalWrite(relayFans, HIGH); 
  }

  if (digitalRead(button2) == LOW) { 
    fanStartTime = millis(); 
    digitalWrite(relayFans, LOW); 
  }
  
 
  if (millis() - fanStartTime >= 16000) {
    digitalWrite(relayFans, HIGH);
  }

  if (digitalRead(button3) == LOW) { 
    fanStartTime = millis(); 
    digitalWrite(relayFans, LOW); 
  }
  
  if (millis() - fanStartTime >= 20000) {
    digitalWrite(relayFans, HIGH); 
  }
  
  if (millis() - fanStartTime < 10000) {
    if (millis() - heatToggleTime >= 2000) {
      heatToggleTime = millis(); 
      heatState = !heatState; 
      digitalWrite(relayHeat, heatState);
    }
  }
}
