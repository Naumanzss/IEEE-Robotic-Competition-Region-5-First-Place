
void trackSensorsSP4H(long del) {
  if(cnt >= 60){
  if (posCount > 3){
     delay(2);
    if( posCount > 3) c = 1;}
  if (posCount == 2 && c == 1) c1 = 1;
  if (posCount > 3 && c1 == 1){
      delay(2);
    if( posCount > 3  && c1 == 1)c2 = 1;}
  if (posCount == 2 && c2 == 1) c3 = 1;
  if (posCount > 3 && c3 == 1) {
    delay(2);
    if( posCount > 3  && c3 == 1) c4 = 1;}
  if (posCount == 2 && c4 == 1) c5 = 1; 
  if (posCount > 3 && c5 == 1) {
    delay(2);
  if (posCount > 3 && c5 == 1) c6 = 1;}
  if (posCount == 2 && c6 == 1) c7 = 1;
  if (posCount > 3 && c7 == 1){
      delay(2);
  if (posCount > 3 && c7== 1) {
    steps = 0;
    if ( comingBack == 0)goFwd(1, 600);
    resetVal();
  }}}

  float turnRatio = straight;
  float temp = del * turnRatio;

  noInterrupts();
  OCR3A = temp * 16;;
  OCR4A = del * 16;
  TCNT3 = 0;
  TCNT4 = 0;
  interrupts();

}

void goFwd_LSSP4H(float dis, float del) {
  varint(fwd, dis , del, straight, rightmotors, leftmotors);
  while (flag1 == true) {
    if (testSensors()) trackSensorsSP4H(del);
  }
  goFwd(1, 600);
}
