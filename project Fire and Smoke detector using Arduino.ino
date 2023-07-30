int gas_sensor = A0, flame_sensor = 7;
int buzzer = 11;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(flame_sensor, INPUT);
  pinMode(buzzer, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (digitalRead(flame_sensor) == HIGH) {
    Serial.println("Fire detected");
    digitalWrite(buzzer, HIGH);

  } else {
    Serial.println("NO Fire");
    digitalWrite(buzzer, LOW);
  }
  if (analogRead(gas_sensor) == HIGH) {
    Serial.println("Smoke detected");
    digitalWrite(buzzer, HIGH);
  } else {
    Serial.println("NO smoke");
    digitalWrite(buzzer, LOW);
  }
}
