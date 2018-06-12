void colorIs(){ 
  pinMode(27, OUTPUT);


  
  // use these three pins to drive an LED
  pinMode(redpin, OUTPUT);
  pinMode(greenpin, OUTPUT);
  pinMode(bluepin, OUTPUT);

  
  
  // thanks PhilB for this gamma table!
  // it helps convert RGB colors to what humans see
  for (int i=0; i<256; i++) {
    float x = i;
    x /= 255;
    x = pow(x, 2.5);
    x *= 255;
      
    if (commonAnode) {
      gammatable[i] = 255 - x;
    } else {
      gammatable[i] = x;      
    }
    //Serial.println(gammatable[i]);
  }




  


  uint16_t clear, red, green, blue;

  tcs.setInterrupt(false);      // turn on LED

  delay(60);  // takes 50ms to read 
  
  tcs.getRawData(&red, &green, &blue, &clear);

  tcs.setInterrupt(true);  // turn off LED

 
  
  
  
  
  
  
  
  
  float r, g, b, sum = clear;
  r = red; r /= sum;
  g = green; g /= sum;
  b = blue; b /= sum;
  r *= 256; g *= 256; b *= 256;
  




  // Figure out some basic hex code for visualization
   

  float color[3] = {r, g, b};

 float D1 = distance(color, RED);
 float D2 = distance(color, GREEN);
 float D3 = distance(color, BLUE);
 float D4 = distance(color, ORANGE);
 float D5 = distance(color, YELLOW);
 float D6 = distance(color, MAGENTA);
 float D7 = distance(color, CYAN);
 float D8 = distance(color, GREY);
       
// 
//
// Serial.println(D1);
//  Serial.println(D2);
//   Serial.println(D3);
//    Serial.println(D4);
//    Serial.println(D5);
//     Serial.println(D6); 
//     Serial.println(D7);
//      Serial.println(D8);

       if(D1 < D2 && D1 < D3 && D1 < D4 && D1 < D5 && D1 < D6 && D1 < D7 && D1 < D8){
//     Serial.println ( "The color is RED" );
     color1 = 7;
   }
   else if (D2 < D1 && D2 < D3 && D2 < D4 && D2 < D5 && D2 < D6 && D2 < D7 && D2 < D8){
//     Serial.println ( "The color is GREEN ");
     color1 = 6;
   }
   else if (D3 < D1 && D3 < D2 && D3 < D4 && D3 < D5 && D3 < D6 && D3 < D7 && D3 < D8){
//     Serial.println ( "The color is BLUE" );
     color1 = 5;
   }
   else if (D4 < D1 && D4 < D2 && D4 < D3 && D4 < D5 && D4 < D6 && D4 < D7 && D4 < D8){
//     Serial.println ( "The color is ORANGE" );
     color1 = 10;
   }
   else if (D5 < D1 && D5 < D2 && D5 < D3 && D5 < D4 && D5 < D6 && D5 < D7 && D5 < D8){
//     Serial.println ( "The color is YELLOW" );
     color1 = 3;
   }
   else if (D6 < D1 && D6 < D2 && D6 < D3 && D6 < D4 && D6 < D5 && D6 < D7 && D6 < D8){
//     Serial.println ( "The color is MAGENTA" );
     color1 = 2;
   }
   else if (D7 < D1 && D7 < D2 && D7 < D3 && D7 < D4 && D7 < D5 && D7 < D6 && D7 < D8){
//     Serial.println ( "The color is CYAN" );
     color1 = 1;
   }
   else if (D8 < D1 && D8 < D2 && D8 < D3 && D8 < D4 && D8 < D5 && D8 < D6 && D8 < D7){
//     Serial.println ( "The color is GREY" );
     color1 = 8;
   }
 
  delay(50);
//  Serial.print("\t");
//  Serial.print((int)r); Serial.print((int)g); Serial.print((int)b);
//  Serial.println();

  //Serial.print((int)r ); Serial.print(" "); Serial.print((int)g);Serial.print(" ");  Serial.println((int)b );

  analogWrite(redpin, gammatable[(int)r]);
  analogWrite(greenpin, gammatable[(int)g]);
  analogWrite(bluepin, gammatable[(int)b]);



//
  
  
  
  }

float distance(float color[], float check[])
{
  float x, y, z, dist;

  x = color[0] - check[0];
  y = color[1] - check[1];
  z = color[2] - check[2];

  dist = pow(pow(x,2) + pow(y,2) + pow(z,2), 0.5);

  return dist;
}


