void noColorOnTheBox(){
   if(coins[1][0]  == true || coins[1][1] == true || coins[1][2] == true){
        gotoMiddleR(); 
        box1 = 1;
        rotate();
        box = box1;
        gotoColor();    
    }
   else if(coins[2][0]  == true || coins[2][1] == true || coins[2][2] == true){
      gotoMiddleR(); 
      box1 = 2;
      rotate();
      box = box1;
      gotoColor();
    }
   else if(coins[3][0]  == true || coins[3][1] == true || coins[3][2] == true){
        gotoMiddleR(); 
        box1 = 3;
        rotate();
        box = box1;
        gotoColor();
    }
    else if(coins[5][0]  == true || coins[5][1] == true || coins[5][2] == true){
      gotoMiddleR();
      box1 = 5;
      rotate();
      box = box1;
      gotoColor();     
    }
    else if(coins[6][0]  == true || coins[6][1] == true || coins[6][2] == true){
        gotoMiddleR(); 
        box1 = 6;
        rotate();
        box = box1;
        gotoColor();      
    }
    else if(coins[7][0]  == true || coins[7][1] == true || coins[7][2] == true){
      gotoMiddleR(); 
      box1 = 7;
      rotate();
      box = box1;
      gotoColor();      
    }
}

