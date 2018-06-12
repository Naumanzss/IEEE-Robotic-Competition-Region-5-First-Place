  
ISR(TIMER1_COMPA_vect) //timer overflow ISR
{
  // TCNT1 = 57536; //65536-16*500
  if (flag1 == true) {
    PORTL ^= allmotors;
    cnt++;
    if (cnt > steps) {
      flag1 = false;
    }
  }
}


void resetVal() {
  c = 0; c1 = 0, c2 = 0, c3 = 0, c4 = 0, c5 = 0, c6 = 0, c7 = 0, c8 = 0, c9 = 0,
  c10 = 0, c11 = 0;
}

void movint( byte dir, float dist, float del) {
  PORTL = dir;
  float stepf = dist * steps_per_inch;
  steps = stepf;


  noInterrupts();           // disable all interrupts
  TCCR1A = 0;
  TCCR1B = 0;
  TCNT1  = 0;

  OCR1A = del * 16;            // compare match register 16MHz/256/2Hz
  TCCR1B |= (1 << WGM12);   // CTC mode
  TCCR1B |= (1 << CS10);    // 1 prescaler
  TIMSK1 |= (1 << OCIE1A);  // enable timer compare interrupt
  interrupts();
  cnt = 0;
  flag1 = true;
}


void turnint (byte dir, float deg, long del)
{
  PORTL = dir;
  float stepf = deg * steps_per_degree;
  steps = stepf;

  noInterrupts();           // disable all interrupts
  TCCR1A = 0;
  TCCR1B = 0;
  TCNT1  = 0;

  OCR1A = del * 16;            // compare match register 16MHz/256/2Hz
  TCCR1B |= (1 << WGM12);   // CTC mode
  TCCR1B |= (1 << CS10);    // 1 prescaler
  TIMSK1 |= (1 << OCIE1A);  // enable timer compare interrupt
  interrupts();
  cnt = 0;
  flag1 = true;
}

void strafeint (byte dir, float dist, long del)
{
  PORTL = dir;
  float stepf = dist * steps_per_inch;
  steps = stepf;


  noInterrupts();           // disable all interrupts
  TCCR1A = 0;
  TCCR1B = 0;
  TCNT1  = 0;

  OCR1A = del * 16;            // compare match register 16MHz/256/2Hz
  TCCR1B |= (1 << WGM12);   // CTC mode
  TCCR1B |= (1 << CS10);    // 1 prescaler
  TIMSK1 |= (1 << OCIE1A);  // enable timer compare interrupt
  interrupts();
  cnt = 0;
  flag1 = true;
}


void varint (byte dir, float dist, long del, float ratio, byte master, byte slave)
{
  PORTL = dir;
  float stepf = dist * steps_per_inch;
  steps = stepf;

  //int mastercount = 0, slavecount = 0, stepcount = 0;
  float temp = del * ratio;
  mastermove = master;
  slavemove = slave;
  ocvar3 = 16 * temp;
  ocvar4 = 16 * del;
  cnt = 0;
  temp = 0;
  stepf = 0;

  noInterrupts();           // disable all interrupts
  TCCR3A = 0;
  TCCR3B = 0;
  TCCR4A = 0;
  TCCR4B = 0;
  OCR3A = ocvar3;
  OCR4A = ocvar4;            // compare match register 16MHz/256/2Hz
  TCCR3B |= (1 << WGM32);   // CTC mode
  TCCR3B |= (1 << CS30);    // 1 prescaler
  TIMSK3 |= (1 << OCIE3A);  // enable timer compare interrupt
  TCCR4B |= (1 << WGM42);   // CTC mode
  TCCR4B |= (1 << CS40);    // 1 prescaler
  TIMSK4 |= (1 << OCIE4A);  // enable timer compare interrupt
  interrupts();
  flag1 = true;

}

ISR(TIMER4_COMPA_vect) //timer overflow ISR
{
  if (flag1 == true) {
    PORTL ^= mastermove;
    cnt++;
    if ( cnt >= steps ) {
      flag1 = false;
      cnt = 0;
      steps = 0;
    }
  }
}

ISR(TIMER3_COMPA_vect) //timer overflow ISR
{
  if (flag1 == true) {
    PORTL ^= slavemove;

  }
}




void mov(byte dir, float dist, long del)
{
  PORTL = dir;
  float stepf = dist * steps_per_inch;
  long steps = stepf;

  for ( int i = 0; i < steps ; i++)
  {
    PORTL ^= allmotors;
    delayMicroseconds(del);

  }
}

void accint (byte dir, float dist, long del, float ratio, byte master, byte slave)
{
  PORTL = dir;
  float stepf = dist * steps_per_inch;
  steps = stepf;

  //int mastercount = 0, slavecount = 0, stepcount = 0;
  float temp = del * ratio;
  mastermove = master;
  slavemove = slave;
  ocvar3 = 16 * temp;
  ocvar4 = 16 * del;
  cnt = 0;
  temp = 0;
  stepf = 0;

  noInterrupts();           // disable all interrupts
  TCCR3A = 0;
  TCCR3B = 0;
  TCCR4A = 0;
  TCCR4B = 0;
  OCR3A = ocvar3;
  OCR4A = ocvar4;            // compare match register 16MHz/256/2Hz
  TCCR3B |= (1 << WGM32);   // CTC mode
  TCCR3B |= (1 << CS30);    // 1 prescaler
  TIMSK3 |= (1 << OCIE3A);  // enable timer compare interrupt
  TCCR4B |= (1 << WGM42);   // CTC mode
  TCCR4B |= (1 << CS40);    // 1 prescaler
  TIMSK4 |= (1 << OCIE4A);  // enable timer compare interrupt
  interrupts();
  flag1 = true;

}

void turn(byte dir, float deg, long del)
{
  PORTL = dir;
  stepf = deg * steps_per_degree;
  steps = stepf;

  for ( int i = 0; i < steps ; i++)
  {
    PORTL ^= allmotors;
    delayMicroseconds(del);

  }
}


void strafe (byte dir, float dist, long del)
{
  PORTL = dir;
  float stepf = dist * steps_per_inch;
  long steps = stepf;

  for ( int i = 0; i < steps ; i++)
  {
    PORTL ^= allmotors;
    delayMicroseconds(del);

  }
}

void pivot (byte dir, float dist, long del, byte motors)
{
  PORTL = dir;
  float stepf = dist * steps_per_inch;
  long steps = stepf;

  for ( int i = 0; i < steps ; i++)
  {
    PORTL ^= motors;
    delayMicroseconds(del);

  }
}
void var (byte dir, float dist, long del, float ratio, byte master, byte slave)
{
  PORTL = dir;
  float stepf = dist * steps_per_inch;
  steps = stepf;

  int mastercount = 0, slavecount = 0, stepcount = 0;
  float temp = del * ratio;
  long slavedelay = temp;

  while ( stepcount < steps)
  {
    if (mastercount >  del)
    {
      PORTL ^= master; //stop masterwheels;
      mastercount = 0;
      stepcount++;

    }
    if (slavecount > slavedelay)
    { PORTL ^= slave; //stop slave wheels
      slavecount = 0; // reset
    }
    mastercount++;
    slavecount++;
  }
}



void acc(byte dir, float dist, long del, int N) {
  PORTL = dir;

  float stepf = dist * steps_per_inch;
  long steps = stepf;
  float accdist = N * (N + 1) * 1.5 * startdist;
  float residist = dist - accdist;
  if (residist < 0) {
    N = sqrt(dist / startdist * 2. / 3.);
    accdist = N * (N + 1) * 1.5 * startdist;
    residist = dist - accdist;

  }

  //for acceleration
  for (int i = 1; i <= N ; i++) {

    var(dir, startdist * i, del / i, 1.0, rightmotors, leftmotors);

  }
  var(dir, residist, del / N, 1.0, rightmotors, leftmotors);

  for (int i = N; i > 0 ; i--) {

    var(dir, startdist * i, del / i, 1.0, rightmotors, leftmotors);

  }



}

void error(int number)
{
  Serial.print("**");
  Serial.print(number);
  Serial.print("**");
}

void selfCal() {
 // int calArray[8] = {100, 100, 100, 100, 100, 100, 100,100};
 int calArray[8] = {240, 180, 124, 180, 184, 248, 240, 300};
  qtrrc.calibrate();
  for (int i = 0 ; i < NUM_SENSORS; i++) {
    qtrrc.calibratedMinimumOn[i] = calArray[i];
    qtrrc.calibratedMaximumOn[i] = TIMEOUT;
  }
}

void autoCal() {
  mov(fwd ,12 , 1600);

  while (flag1 == true) {
    qtrrc.calibrate();       // reads all sensors 10 times at 2500 us per read (i.e. ~25 ms per call)
  }

  mov(rev , 12 , 1600);
  while (flag1 == true) {
    qtrrc.calibrate();       // reads all sensors 10 times at 2500 us per read (i.e. ~25 ms per call)
  }

  //  digitalWrite(13, LOW);     // turn off Arduino's LED to indicate we are through with calibration
  Serial.begin(9600);

  Serial.print("Calibrated MIN: \n");
  for (int i = 0; i < NUM_SENSORS; i++)
  {
    Serial.print(qtrrc.calibratedMinimumOn[i]);
    Serial.print(' ');
  }
  Serial.println();

  Serial.print("Calibrated MAX: \n");
  for (int i = 0; i < NUM_SENSORS; i++)
  {
    Serial.print(qtrrc.calibratedMaximumOn[i]);
    Serial.print(" ");
  }
  Serial.println();
  Serial.println();


}

int testSensors() {
  unsigned int position = qtrrc.readLine(sensorValues);
  countEventOn = 0;
  countEventOff = 0;
  posSum = 0;
  posCount = 0;
  for (unsigned char i = 0; i < NUM_SENSORS; i++)
  {
    if (sensorValues[i] > sensorOnAt) {
      sensorOn[i] = true;
      posSum += i;
      posCount ++;
    }
    else
    {
      sensorOn[i] = false;
    }

    if (posCount > 0) pos = posSum / posCount;
    else pos = oldPos;
  }
  for (int i = 0 ; i < NUM_SENSORS; i++)
  {
    if (sensorOn[i] == true && oldSensorOn[i] == false) {
      countEventOn++;
    }
    if (sensorOn[i] == false && oldSensorOn[i] == true) {
      countEventOff++;
    }
  }
  for (unsigned char i = 0; i < NUM_SENSORS; i++)
  {
    oldSensorOn[i] = sensorOn[i];
  }

  oldPos = pos;
  return (countEventOn + countEventOff);
}


void fixSensors() {
  unsigned int position = qtrrc.readLine(sensorValues);
  posSum = 0;
  posCount = 0;
  for (int i = 0; i < NUM_SENSORS; i++) {
    if (sensorValues[i] > sensorOnAt) {
      oldSensorOn[i] = true;
      posSum += i;
      posCount ++;
    }
    else
    {
      oldSensorOn[i] = false;
    }
  }
  if (posCount > 0) pos = posSum / posCount;
  else pos = 3.5;
  oldPos = pos;
}


void myacc(byte dir, float dis, long del2)
{
  del2 = 400;
  PORTL = dir;
  stepf = dis * steps_per_inch;
  steps = stepf;
  float steps1 = 0.1 * steps;
  float steps2 = 0.8 *steps;
  float steps3 = 0.1 *steps;
    for ( int i = 0; i < steps1 ; i++)
  {
    PORTL ^= allmotors;
    delayMicroseconds(del2);

  }

      for ( int i = 0; i < steps2 ; i++)
  {
    PORTL ^= allmotors;
    del2 = del2 - (i/60) * (i/60);
    if (del2 <=200) del2 = 200;
    delayMicroseconds(del2);

  }

      for ( int i = 0; i < steps3 ; i++)
  {
    del2 = 400;
    PORTL ^= allmotors;
    delayMicroseconds(del2);

  }
}

void myacc1(byte dir, float dis, long del2)
{
  del2 = 400;
  PORTL = dir;
  stepf = dis * steps_per_inch;
  steps = stepf;
  float steps1 = 0.1 * steps;
  float steps2 = 0.7 *steps;
  float steps3 = 0.2 *steps;
    for ( int i = 0; i < steps1 ; i++)
  {
    PORTL ^= allmotors;
    delayMicroseconds(del2);

  }

      for ( int i = 0; i < steps2 ; i++)
  {
    PORTL ^= allmotors;
    del2 = del2 - (i/60) * (i/60);
    if (del2 <=200) del2 = 200;
    delayMicroseconds(del2);

  }

      for ( int i = 0; i < steps3 ; i++)
  {
    del2 = 500;
    PORTL ^= allmotors;
    delayMicroseconds(del2);

  }
}


void turnacc(byte dir, float deg, long del2)
{
  del2 = 400;
  PORTL = dir;
  stepf = deg * steps_per_degree;
  steps = stepf;
  float steps1 = 0.1 * steps;
  float steps2 = 0.8 *steps;
  float steps3 = 0.1 *steps;
    for ( int i = 0; i < steps1 ; i++)
  {
    PORTL ^= allmotors;
    delayMicroseconds(del2);

  }

      for ( int i = 0; i < steps2 ; i++)
  {
    PORTL ^= allmotors;
    del2 = del2 - (i/60) * (i/60);
    if (del2 <=200) del2 = 200;
    delayMicroseconds(del2);

  }

      for ( int i = 0; i < steps3 ; i++)
  {
    del2 = 400;
    PORTL ^= allmotors;
    delayMicroseconds(del2);

  }
}
