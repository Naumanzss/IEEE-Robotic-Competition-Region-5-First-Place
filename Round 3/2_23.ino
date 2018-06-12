//void goFwd_LSSPTest(float dis, float del) {
//  varint(fwd, dis , del, straight, rightmotors, leftmotors);
//  while (flag1 == true) {
//    if (testSensors()) trackSensorsSPTest(del);
//  }
//}


void goFwd(float dis, long del) {
  var(fwd, dis , del, straight, rightmotors, leftmotors);

}
void goFwd_LS(float dis, float del) {
  varint(fwd, dis , del, straight, rightmotors, leftmotors);
  while (flag1 == true) {
    if (testSensors()) trackSensors(del);
  }
}

void goFwd_LSSP0(float dis, float del) {
  varint(fwd, dis , del, straight, rightmotors, leftmotors);
  while (flag1 == true) {
    if (testSensors()) trackSensorsSP0(del);
  }
  if ( comingBack == 0)goFwd(2, 600);
}

void goFwd_LSSP1(float dis, float del) {
  varint(fwd, dis , del, straight, rightmotors, leftmotors);
  while (flag1 == true) {
    if (testSensors()) trackSensorsSP1(del);
  }
   if ( comingBack == 0)goFwd(2, 600);
}

void goFwd_LSSP2(float dis, float del) {
  varint(fwd, dis , del, straight, rightmotors, leftmotors);
  while (flag1 == true) {
    if (testSensors()) trackSensorsSP2(del);
  }
  if ( comingBack == 0)goFwd(2, 600);
}

void goFwd_LSSP3(float dis, float del) {
  varint(fwd, dis , del, straight, rightmotors, leftmotors);
  while (flag1 == true) {
    if (testSensors()) trackSensorsSP3(del);
  }
  if ( comingBack == 0)goFwd(2, 600);
}

void goFwd_LSSP4(float dis, float del) {
  varint(fwd, dis , del, straight, rightmotors, leftmotors);
  while (flag1 == true) {
    if (testSensors()) trackSensorsSP4(del);
  }
  if ( comingBack == 0)goFwd(2, 600);
}

void goFwd_LSSP5(float dis, float del) {
  varint(fwd, dis , del, straight, rightmotors, leftmotors);
  while (flag1 == true) {
    if (testSensors()) trackSensorsSP5(del);
  }
  if ( comingBack == 0)goFwd(2, 600);
}

/// for horizontal lines with N

void goFwd_LSSP0N(float dis, float del) {
  varint(fwd, dis , del, straight, rightmotors, leftmotors);
  while (flag1 == true) {
    if (testSensors()) trackSensorsSP0N(del);
  }
  if ( comingBack == 0)goFwd(1.5, 600);
}

void goFwd_LSSP1N(float dis, float del) {
  varint(fwd, dis , del, straight, rightmotors, leftmotors);
  while (flag1 == true) {
    if (testSensors()) trackSensorsSP1N(del);
  }
  if ( comingBack == 0)goFwd(1.5, 600);
}

void goFwd_LSSP2N(float dis, float del) {
  varint(fwd, dis , del, straight, rightmotors, leftmotors);
  while (flag1 == true) {
    if (testSensors()) trackSensorsSP2N(del);
  }
  if ( comingBack == 0)goFwd(1.5, 600);
}

void goFwd_LSSP3N(float dis, float del) {
  varint(fwd, dis , del, straight, rightmotors, leftmotors);
  while (flag1 == true) {
    if (testSensors()) trackSensorsSP3N(del);
  }
  if ( comingBack == 0)goFwd(1.5, 600);
}

void goFwd_LSSP4N(float dis, float del) {
  varint(fwd, dis , del, straight, rightmotors, leftmotors);
  while (flag1 == true) {
    if (testSensors()) trackSensorsSP4N(del);
  }
  if ( comingBack == 0)goFwd(1.5, 600);
}

void goFwd_LSSP5N(float dis, float del) {
  varint(fwd, dis , del, straight, rightmotors, leftmotors);
  while (flag1 == true) {
    if (testSensors()) trackSensorsSP5N(del);
  }
  if ( comingBack == 0)goFwd(1.5, 600);
}

void pickupSP0N(){
  goFwd_LSSP0N (100, del);
  delay(800);
//  recenter();
  goRevForCoinN();
  delay(50);
  recenter();
  delay(50);
  pickup();
}

void pickupSP1N(){
  goFwd_LSSP1N (100, del);
  delay(800);
//  recenter();
  goRevForCoinN();
  delay(50);
  recenter();
  delay(50);
  pickup();
}

void pickupSP2N() {
  goFwd_LSSP2N (100, del);
  delay(800);
//  recenter();
  goRevForCoinN();
  delay(50);
  recenter();
  delay(50);
  pickup();
}

void pickupSP3N() {
  goFwd_LSSP3N (100, del);
  delay(800);
//  recenter();
  goRevForCoinN();
  delay(50);
  recenter();
  delay(50);
  pickup();
}

void pickupSP4N() {
  goFwd_LSSP4N (100, del);
  delay(800);
//  recenter();
  goRevForCoinN();
  delay(50);
  recenter();
  delay(50);
  pickup();
}


void pickupSP0() {
  goFwd_LSSP0 (100, del);
  delay(800);
  recenter();
  delay(100);
  goRevForCoin();
  delay(100);
  recenter();
  delay(100);
  pickup();
}

void pickupSP1() {
  goFwd_LSSP1 (100, del);
  delay(800);
  recenter();
  delay(100);
  goRevForCoin();
  delay(100);
  recenter();
  delay(100);
  pickup();
}

void pickupSP2() {
  goFwd_LSSP2 (100, del);
  delay(800);
  recenter();
  delay(100);
  goRevForCoin();
  delay(100);
  recenter();
  delay(100);
  pickup();
}

void pickupSP3() {
  goFwd_LSSP3 (100, del);
  delay(800);
  recenter();
  delay(100);
  goRevForCoin();
  delay(100);
  recenter();
  delay(100);
  pickup();
}

void pickupSP4() {
  goFwd_LSSP4 (100, del);
  delay(800);
  recenter();
  delay(100);
  goRevForCoin();
  delay(100);
  recenter();
  delay(100);
  pickup();
}


void returnToColor() {
  degree = box - nextColor[bc] ;
  if (degree == 1) turnacc (rotright, 135, del);
  else if (degree == 2 || degree == -6)turnacc (rotright, 90, del);
  else if (degree == 3 || degree == -5)turnacc (rotright, 45, del);
  else if (degree == 4 || degree == -4);
  else if (degree == 5 || degree == -3)turnacc (rotleft, 45, del);
  else if (degree == 6 || degree == -2)turnacc (rotleft, 90, del);
  else if (degree == -1) turnacc (rotleft, 135, del);
  else if (degree == 0) turnacc (rotleft, 180, del);
  
  gotoColor();
  dropit();
  
}

void gotoColor(){
  if ((nextColor[bc]%2) == 0){
    goFwd_LS(4, 375);
    goFwd_LS(30, 200);
    mov(fwd, 2 ,375);
  }
  else if ((nextColor[bc]%2) == 1) {
    goFwd_LS(7, 375);
    goFwd_LS(41, 200);
    mov(fwd, 3 ,375); 
 }
}

void gotoMiddle() {
  
  comingBack = 1;
  if (sp == 0)goFwd_LSSP1(100, del);
   else if (sp == 1) goFwd_LSSP2(100,del);
   else if (sp == 2) goFwd_LSSP3(100,del);
   else if (sp == 3)goFwd_LSSP4(100, del);
 
  if(greycoin == 0)  {
    goFwd_LS(9, del);
    goFwd_LS(2, 500);
  }
  else if (greycoin == 1){
    goFwd_LS(5, del);
    goFwd_LS(1, 500);
    dropit();
    goFwd_LS(4, del);
    goFwd_LS(1, 500);
    
  }
  greycoin = 0;
  comingBack = 0;
}

void gotoMiddleN() {
  comingBack = 1;
  if (sp == 0)goFwd_LSSP1N(100, del);
  else if (sp == 1) goFwd_LSSP2N(100,del);
  else if (sp == 2) goFwd_LSSP3N(100,del);
  else if (sp == 3) goFwd_LSSP4N(100,del);
 
  if(greycoin == 0)  {
    goFwd_LS(7, del);
    goFwd_LS(2, 500);
  }
  else if (greycoin == 1){
    goFwd_LS(4, del);
    goFwd_LS(1, 500);
    dropit();
    goFwd_LS(3, del);
    goFwd_LS(1, 500);
    
  }
  greycoin = 0;
  comingBack = 0;
}

void gotoMiddleR() {
  comingBack = 1;
  if (box%2 == 0){
  goFwd_LSSP4N( 100, del);
    goFwd_LS(9, del);
    goFwd_LS(2, 500);
  }
  else if (box%2 == 1){
    goFwd_LSSP4( 100, del);
    goFwd_LS(9, del);
    goFwd_LS(2, 500);
  }
  greycoin = 0;
  comingBack = 0;
}

void gotoMiddleRN() {
  comingBack = 1;
  goFwd_LSSP4N( 100, del);
 
  if(greycoin == 0)  {
    goFwd_LS(7, del);
    goFwd_LS(2, 500);
  }
  else if (greycoin == 1){
    goFwd_LS(4, del);
    goFwd_LS(1, 500);
    dropit();
    goFwd_LS(3, del);
    goFwd_LS(1, 500);
    
  }
  greycoin = 0;
  comingBack = 0;
}

void gotoMiddleRNC() {
  comingBack = 1;
   if (box%2 == 0){
    goFwd_LSSP4N( 100, del);
    goFwd_LS(7, del);
    goFwd_LS(2, 500);
   }
    else if (box%2 == 1){
      goFwd_LSSP4( 100, del);
      goFwd_LS(9, del);
      goFwd_LS(2, 500);
    }
   
  comingBack = 0;
}




void returnToColor_2() {
  degree = box - box1 ;
  if (degree == 1) turn (rotright, 135, del);
  else if (degree == 2 || degree == -6)turn (rotright, 90, del);
  else if (degree == 3 || degree == -5)turn (rotright, 45, del);
  else if (degree == 4 || degree == -4);
  else if (degree == 5 || degree == -3)turn (rotleft, 45, del);
  else if (degree == 6 || degree == -2)turn (rotleft, 90, del);
  else if (degree == -1) turn (rotleft, 135, del);
  else if (degree == 0) turn (rotleft, 180, del);


  goFwd_LSSP5( 100, del);
  nextColor[bc] = box1;
  comingBack = 0;
}


void rotate(){
//  comingBack = 0;
  degree = box - box1;
  if (degree == 1) turnacc (rotright, 135, del);
  else if (degree == 2 || degree == -6)turnacc(rotright, 90, del);
  else if (degree == 3 || degree == -5)turnacc (rotright, 45, del);
  else if (degree == 4 || degree == -4);
  else if (degree == 5 || degree == -3)turnacc (rotleft, 45, del);
  else if (degree == 6 || degree == -2)turnacc (rotleft, 90, del);
  else if (degree == -1|| degree == 7) turnacc (rotleft, 135, del);
  else if (degree == 0) turnacc (rotleft, 180, del);
 
}

void recenter(){
    int counterrecenter = 4;
    while(counterrecenter){
    fixSensors();
    if(pos < 3.5) strafe(straferight, 0.1 , 800);
    if(pos > 3.5) strafe(strafeleft, 0.1 , 800);
    if(pos == 3.5)goto out;
    if(pos < 3.5) strafe(straferight, 0.1 , 800);
    if(pos > 3.5) strafe(strafeleft, 0.1 , 800);
    counterrecenter--;
  }
  out:
  ;
  
}


void allCoinsDoneR(){
  goFwd_LS(6,del);
  turnacc (rotleft, 180, del);
  gotoMiddleR();
  
}

void allCoinsDoneRN(){
  goFwd_LS(4.5,del);
  turnacc (rotleft, 180, del);
  gotoMiddleRN();
  
}

void homeRecenter(){
  sensorOnAt = 125;
  strafe(strafeleft, 22 , 400); 
  while(true){
  fixSensors();
  if (sensorValues[0] > sensorOnAt && sensorValues[1] > sensorOnAt)goto line1;
  else strafe(straferight, 0.5 , 400);
  }
line1:
  strafe(straferight, 7 , 400);
}


void detectColor(){
    CI = 2;
  while(CI)
  {
  colorIs();
  CI--;}
}

void goRevForCoin(){

  while(true){
    fixSensors();
    mov(rev, 0.1, 600);
    if (sensorValues[2] > sensorOnAt && sensorValues[5] > sensorOnAt)goto out5;
  }
  out5: ;
mov(rev, 1.62, 600);

}

void goRevForCoinN(){

  while(true){
    fixSensors();
    mov(rev, 0.1, 600);
    if (sensorValues[2] > sensorOnAt && sensorValues[5] > sensorOnAt)goto out6;
  }
  out6: ;
mov(rev, 0.9, 600);

}

void checkIfNoCoin(){
  if(color1 == 10){
  dropit();
  mov(rev, 0.2, 800);
  pickup();
  detectColor();
  if(color1 == 10){
  dropit();
  mov(rev, 0.2, 800);
  pickup();
  detectColor();
  if(color1 == 10)color1 = 8;
   }
  }
}


//void check(){
//  boxcheck = box;
// while(boxcheck>0){
//  strafe(strafeleft, 1 , 800);
//  strafe(straferight, 1 , 800);
//  boxcheck--;
//  delay(1000);
// }
//}


void pickup(){
      moveServoDown();
      magnetOff();
      delay(500);
      magnetOn();
      delay (1000);
      moveServoUp();
      delay(800);
}

void dropit(){
  moveServoDown();
  delay(500);
  magnetOff();
  delay(200);
  moveServoUp();
}

void moveServoUp(){
  digitalWrite(27, LOW);
}

void moveServoDown(){
  digitalWrite(27, HIGH);
}


void magnetOn(){
   digitalWrite(31, LOW);
}

void magnetOff(){
   digitalWrite(31, HIGH);
}
