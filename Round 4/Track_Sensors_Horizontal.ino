
void trackSensorsSP0N(long del) {
   if(cnt >= 60){
  if ( posCount > 3){    
    delay(2);
    if( posCount > 3){
            steps = 0;
        }}}
        
  float turnRatio = straight + ( pos - 3.5) * .2;
  float temp = del * turnRatio;

  noInterrupts();
  OCR3A = temp * 16;;
  OCR4A = del * 16;
  TCNT3 = 0;
  TCNT4 = 0;
  interrupts();

}

void trackSensorsSP1N(long del) {
 if(cnt >= 60){
  if (posCount > 3){ 
      delay(2);
    if( posCount > 3) c = 1;}
  if (posCount == 2 && c == 1) c1 = 1;
  if (posCount > 3 && c1 == 1) {
        delay(2);
    if( posCount > 3&& c1 == 1){
    steps = 0;
    resetVal();
  }}}
  float turnRatio = straight + ( pos - 3.5) * .2;
  float temp = del * turnRatio;

  noInterrupts();
  OCR3A = temp * 16;;
  OCR4A = del * 16;
  TCNT3 = 0;
  TCNT4 = 0;
  interrupts();

}



void trackSensorsSP2N(long del) {
  if(cnt >= 60){
  if (posCount > 3){
     delay(2);
    if( posCount > 3) c = 1;}
  if (posCount == 2 && c == 1) c1 = 1;
  if (posCount > 3 && c1 == 1){
      delay(2);
    if( posCount > 3  && c1 == 1) c2 = 1;}
  if (posCount == 2 && c2 == 1) c3 = 1;
  if (posCount > 3 && c3 == 1) {
    delay(2);
    if( posCount > 3  && c3 == 1){
    steps = 0;
    resetVal();
  }}}
  float turnRatio = straight + ( pos - 3.5) * .2;
  float temp = del * turnRatio;

  noInterrupts();
  OCR3A = temp * 16;;
  OCR4A = del * 16;
  TCNT3 = 0;
  TCNT4 = 0;
  interrupts();

}

void trackSensorsSP3N(long del) {
  if(cnt >= 60){
   if (posCount > 3){
     delay(2);
    if( posCount > 3) c = 1;}
  if (posCount == 2 && c == 1) c1 = 1;
  if (posCount > 3 && c1 == 1){
      delay(2);
    if( posCount > 3  && c1 == 1) c2 = 1;}
  if (posCount == 2 && c2 == 1) c3 = 1;
  if (posCount > 3 && c3 == 1) {
    delay(2);
    if( posCount > 3  && c3 == 1) c4 = 1;}
  if (posCount == 2 && c4 == 1) c5 = 1; 
  if (posCount > 3 && c5 == 1) {
    delay(2);
    if (posCount > 3 && c5 == 1) {
    steps = 0;
    resetVal();
  }}}

  float turnRatio = straight + ( pos - 3.5) * .2;
  float temp = del * turnRatio;

  noInterrupts();
  OCR3A = temp * 16;;
  OCR4A = del * 16;
  TCNT3 = 0;
  TCNT4 = 0;
  interrupts();

}

void trackSensorsSP4N(long del) {
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
    resetVal();
  }}}

  float turnRatio = straight + ( pos - 3.5) * .2;
  float temp = del * turnRatio;

  noInterrupts();
  OCR3A = temp * 16;;
  OCR4A = del * 16;
  TCNT3 = 0;
  TCNT4 = 0;
  interrupts();

}

void trackSensorsSP5N(long del) {
    if(cnt >= 60){
  if (posCount > 3){
     delay(2);
    if( posCount > 3)c = 1;}
  if (posCount == 2 && c == 1) c1 = 1;
  if (posCount > 3 && c1 == 1){
      delay(2);
    if( posCount > 3  && c1 == 1)c2 = 1;}
  if (posCount == 2 && c2 == 1) c3 = 1;
  if (posCount > 3 && c3 == 1){
    delay(2);
    if( posCount > 3  && c3 == 1) c4 = 1;}
  if (posCount == 2 && c4 == 1) c5 = 1; 
  if (posCount > 3 && c5 == 1){
    delay(2);
  if (posCount > 3 && c5 == 1) c6 = 1;}
  if (posCount == 2 && c6 == 1) c7 = 1;
  if (posCount > 3 && c7 == 1){
      delay(2);
  if (posCount > 3 && c7== 1)c8 = 1;}
  if (posCount == 2 && c8 == 1) c9 = 1;
  if (posCount > 3 && c9 == 1) {
    delay(2);
     if (posCount > 3 && c9 == 1){
      steps = 0;
      resetVal();
  }}}
  
  float turnRatio = straight + ( pos - 3.5) * .2; 
  float temp = del * turnRatio;

  noInterrupts();
  OCR3A = temp * 16;;
  OCR4A = del * 16;
  TCNT3 = 0;
  TCNT4 = 0;
  interrupts();

}



void trackSensors(long del) {

  float turnRatio = straight + ( pos - 3.5) * .2;
  float temp = del * turnRatio;

  noInterrupts();
  OCR3A = temp * 16;;
  OCR4A = del * 16;
  TCNT3 = 0;
  TCNT4 = 0;
  interrupts();

}


