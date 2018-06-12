//void trackSensors(long del) {
//  
//  float turnRatio = straight + ( pos - 3.5) * .3;
//  float temp = del * turnRatio;
//
//  noInterrupts();
//  OCR3A = temp * 16;;
//  OCR4A = del * 16;
//  TCNT3 = 0;
//  TCNT4 = 0;
//  interrupts();
//
//}


void pickupSP_1() {
  goFwd_LSSP_1 (100, del);
    delay(100);
   mov(rev, 3, del+100);
   delay (600);
}

void pickupSP_2() {
  goFwd_LSSP_2 (100, del);
  delay(1000);
  mov(rev, 3, del+100);
  delay (600);
}

void pickupSP_3() {
  goFwd_LSSP_3 (100, del);
  delay(1000);
  mov(rev, 3, del+100);
  delay (600);
}

void pickupSP_4() {
  goFwd_LSSP_4 (100, del);
  delay(1000);
  mov(rev, 3, del+100);
  delay (600);
}


void goFwd_LSSP_0(float dis, float del) {
  varint(fwd, dis , del, straight, rightmotors, leftmotors);
  while (flag1 == true) {
    if (testSensors()) trackSensorsSP_0(del);
  }
}


void goFwd_LSSP_1(float dis, float del) {
  varint(fwd, dis , del, straight, rightmotors, leftmotors);
  while (flag1 == true) {
    if (testSensors()) trackSensorsSP_1(del);
  }
}

void goFwd_LSSP_2(float dis, float del) {
  varint(fwd, dis , del, straight, rightmotors, leftmotors);
  while (flag1 == true) {
    if (testSensors()) trackSensorsSP_2(del);
  }
}

void goFwd_LSSP_3(float dis, float del) {
  varint(fwd, dis , del, straight, rightmotors, leftmotors);
  while (flag1 == true) {
    if (testSensors()) trackSensorsSP_3(del);
  }
}

void goFwd_LSSP_4(float dis, float del) {
  varint(fwd, dis , del, straight, rightmotors, leftmotors);
  while (flag1 == true) {
    if (testSensors()) trackSensorsSP_4(del);
  }
}

void goFwd_LSSP_5(float dis, float del) {
  varint(fwd, dis , del, straight, rightmotors, leftmotors);
  while (flag1 == true) {
    if (testSensors()) trackSensorsSP_5(del);
  }
}

void trackSensorsSP_0(long del) {
  if ((sensorValues[2] > sensorOnAt) && (sensorValues[3] > sensorOnAt) && (sensorValues[4] > sensorOnAt) && (sensorValues[5] > sensorOnAt)) {
    steps = 0;

  }
  float turnRatio = straight + ( pos - 3.5) * .3;
  float temp = del * turnRatio;

  noInterrupts();
  OCR3A = temp * 16;;
  OCR4A = del * 16;
  TCNT3 = 0;
  TCNT4 = 0;
  interrupts();

}

void trackSensorsSP_1(long del) {

  if ((sensorValues[2] > sensorOnAt) && (sensorValues[3] > sensorOnAt) && (sensorValues[4] > sensorOnAt) && (sensorValues[5] > sensorOnAt))  c = 1;
  if (posCount == 2 && c == 1) c1 = 1;
  if ((sensorValues[2] > sensorOnAt) && (sensorValues[3] > sensorOnAt) && (sensorValues[4] > sensorOnAt) && (sensorValues[5] > sensorOnAt) && c1 == 1) {
    steps = 0;
    resetVal();
  }
  float turnRatio = straight + ( pos - 3.5) * .3;
  float temp = del * turnRatio;

  noInterrupts();
  OCR3A = temp * 16;;
  OCR4A = del * 16;
  TCNT3 = 0;
  TCNT4 = 0;
  interrupts();

}


void trackSensorsSP_2(long del) {
  if ((sensorValues[2] > sensorOnAt) && (sensorValues[3] > sensorOnAt) && (sensorValues[4] > sensorOnAt) && (sensorValues[5] > sensorOnAt)) c = 1;
  if (posCount == 2 && c == 1) c1 = 1;
  if ((sensorValues[2] > sensorOnAt) && (sensorValues[3] > sensorOnAt) && (sensorValues[4] > sensorOnAt) && (sensorValues[5] > sensorOnAt) && c1 == 1) c2 = 1;
  if (posCount == 2 && c2 == 1) c3 = 1;
  if ((sensorValues[2] > sensorOnAt) && (sensorValues[3] > sensorOnAt) && (sensorValues[4] > sensorOnAt) && (sensorValues[5] > sensorOnAt) && c3 == 1) {
    steps = 0;
    resetVal();
  }
  float turnRatio = straight + ( pos - 3.5) * .3;
  float temp = del * turnRatio;

  noInterrupts();
  OCR3A = temp * 16;;
  OCR4A = del * 16;
  TCNT3 = 0;
  TCNT4 = 0;
  interrupts();

}

void trackSensorsSP_3(long del) {
  if ((sensorValues[2] > sensorOnAt) && (sensorValues[3] > sensorOnAt) && (sensorValues[4] > sensorOnAt) && (sensorValues[5] > sensorOnAt)) c = 1;
  if (posCount == 2 && c == 1) c1 = 1;
  if ((sensorValues[2] > sensorOnAt) && (sensorValues[3] > sensorOnAt) && (sensorValues[4] > sensorOnAt) && (sensorValues[5] > sensorOnAt) && c1 == 1) c2 = 1;
  if (posCount == 2 && c2 == 1) c3 = 1;
  if ((sensorValues[2] > sensorOnAt) && (sensorValues[3] > sensorOnAt) && (sensorValues[4] > sensorOnAt) && (sensorValues[5] > sensorOnAt) && c3 == 1) c4 = 1;
  if (posCount == 2 && c4 == 1) c5 = 1; \
  if ((sensorValues[2] > sensorOnAt) && (sensorValues[3] > sensorOnAt) && (sensorValues[4] > sensorOnAt) && (sensorValues[5] > sensorOnAt) && c5 == 1) {
    steps = 0;
    resetVal();
  }

  float turnRatio = straight + ( pos - 3.5) * .3;
  float temp = del * turnRatio;

  noInterrupts();
  OCR3A = temp * 16;;
  OCR4A = del * 16;
  TCNT3 = 0;
  TCNT4 = 0;
  interrupts();

}


void trackSensorsSP_4(long del) {
  if ((sensorValues[2] > sensorOnAt) && (sensorValues[3] > sensorOnAt) && (sensorValues[4] > sensorOnAt) && (sensorValues[5] > sensorOnAt)) c = 1;
  if (posCount == 2 && c == 1) c1 = 1;
  if ((sensorValues[2] > sensorOnAt) && (sensorValues[3] > sensorOnAt) && (sensorValues[4] > sensorOnAt) && (sensorValues[5] > sensorOnAt) && c1 == 1) c2 = 1;
  if (posCount == 2 && c2 == 1) c3 = 1;
  if ((sensorValues[2] > sensorOnAt) && (sensorValues[3] > sensorOnAt) && (sensorValues[4] > sensorOnAt) && (sensorValues[5] > sensorOnAt) && c3 == 1) c4 = 1;
  if (posCount == 2 && c4 == 1) c5 = 1;
  if ((sensorValues[2] > sensorOnAt) && (sensorValues[3] > sensorOnAt) && (sensorValues[4] > sensorOnAt) && (sensorValues[5] > sensorOnAt) && c5 == 1) c6 = 1;
  if (posCount == 2 && c6 == 1) c7 = 1;
  if ((sensorValues[2] > sensorOnAt) && (sensorValues[3] > sensorOnAt) && (sensorValues[4] > sensorOnAt) && (sensorValues[5] > sensorOnAt) && c7 == 1) {
    steps = 0;
    resetVal();
  }

  float turnRatio = straight + ( pos - 3.5) * .3;
  float temp = del * turnRatio;

  noInterrupts();
  OCR3A = temp * 16;;
  OCR4A = del * 16;
  TCNT3 = 0;
  TCNT4 = 0;
  interrupts();

}

void trackSensorsSP_5(long del) {
  if ((sensorValues[2] > sensorOnAt) && (sensorValues[3] > sensorOnAt) && (sensorValues[4] > sensorOnAt) && (sensorValues[5] > sensorOnAt)) c = 1;
  if (posCount == 2 && c == 1) c1 = 1;
  if ((sensorValues[2] > sensorOnAt) && (sensorValues[3] > sensorOnAt) && (sensorValues[4] > sensorOnAt) && (sensorValues[5] > sensorOnAt) && c1 == 1) c2 = 1;
  if (posCount == 2 && c2 == 1) c3 = 1;
  if ((sensorValues[2] > sensorOnAt) && (sensorValues[3] > sensorOnAt) && (sensorValues[4] > sensorOnAt) && (sensorValues[5] > sensorOnAt) && c3 == 1) c4 = 1;
  if (posCount == 2 && c4 == 1) c5 = 1;
  if ((sensorValues[2] > sensorOnAt) && (sensorValues[3] > sensorOnAt) && (sensorValues[4] > sensorOnAt) && (sensorValues[5] > sensorOnAt) && c5 == 1) c6 = 1;
  if (posCount == 2 && c6 == 1) c7 = 1;
  if ((sensorValues[2] > sensorOnAt) && (sensorValues[3] > sensorOnAt) && (sensorValues[4] > sensorOnAt) && (sensorValues[5] > sensorOnAt) && c7 == 1)c8 = 1;
  if (posCount == 2 && c8 == 1) c9 = 1;
  if ((sensorValues[2] > sensorOnAt) && (sensorValues[3] > sensorOnAt) && (sensorValues[4] > sensorOnAt) && (sensorValues[5] > sensorOnAt) && c9 == 1) {
    steps = 0;
    resetVal();
  }

  float turnRatio = straight + ( pos - 3.5) * .3;
  float temp = del * turnRatio;

  noInterrupts();
  OCR3A = temp * 16;;
  OCR4A = del * 16;
  TCNT3 = 0;
  TCNT4 = 0;
  interrupts();

}
