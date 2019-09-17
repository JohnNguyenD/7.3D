// This is first sensor

if(digitalRead(Sense1) == HIGH){
digitalWrite(LampIn, LOW); //Interior lamp ON
if(lockLow){
// Wait for transition
lockLow = false;
Serial.println("\n\n");
Serial.print("Active");
Serial.println(" ");
Serial.println("\n\n");
delay(50);
}
takeLowTime = true;

}
// This is second sensor

if (digitalRead(Sense2) == HIGH) {
digitalWrite(LampOut, LOW); //Exterior Lamp ON
if (lockLow) {
// Wait for transition
lockLow = false;
Serial.println("\n\n");
Serial.print("Active");
Serial.println("\n\n");
delay(50);
}
takeLowTime = true;

}
// This is the third sensors
if (digitalRead(Sense3) == HIGH) {
digitalWrite(LampOut, LOW); //Exterior Lamp ON
if (lockLow) {
// Wait for transition
lockLow = false;
Serial.println("\n\n");
Serial.print("Active");
Serial.println("\n\n");
delay(50);
}
takeLowTime = true;

}

if(digitalRead(SenseOut) == LOW){
digitalWrite(LampOut, HIGH); //The relay turns off
if(takeLowTime){
lowIn = millis(); //save the time of the transition from high to LOW
takeLowTime = false; //make sure this is only done at the start of a LOW phase
}
}
//if the sensor is low for more than the given pause,
//we assume that no more motion is going to happen
if(!lockLow && millis() - lowIn > pause){
//makes sure this block of code is only executed again after
//a new motion sequence has been detected
lockLow = true;
Serial.println("\n\n");
Serial.print("Outdoor Light OFF");
Serial.println("\n\n");
delay(50);
}

if(digitalRead(SenseIn) == LOW){
digitalWrite(LampIn, HIGH); //The relay turns off
if(takeLowTime){
lowIn = millis(); //save the time of the transition from high to LOW
takeLowTime = false; //make sure this is only done at the start of a LOW phase
}
}
