void checkButtons(void) {
  btn1State = digitalRead(btn1);
  btn2State = digitalRead(btn2);
  btn3State = digitalRead(btn3);
  
  if(btn1State == LOW && btn1LastState != btn1State && fileIndex > 0) {
    fileIndex--;
  }
  
  if(btn2State == LOW && btn2LastState != btn2State) {
    fileIndex = 0;
  }
  
  if(btn3State == LOW && btn3LastState != btn3State) {
    fileIndex++;
  }

  btn1LastState = btn1State;
  btn2LastState = btn2State;
  btn3LastState = btn3State;
}
