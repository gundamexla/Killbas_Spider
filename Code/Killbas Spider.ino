#include <SoftwareSerial.h>
#include <DFPlayer_Mini_Mp3.h>

#define SW1 2
#define SW2 4
#define SW3 7

int flag = 0;
int f1,f2,f3;
int m1 = 1,m2 = 1,m3 = 1;

int initcnt = 0; 

int henshinCnt;

void setup() {
  // put your setup code here, to run once:
    pinMode(SW1, INPUT);
    pinMode(SW2, INPUT);
    pinMode(SW3, INPUT);
    Serial.begin (9600);
    mp3_set_serial (Serial);      //set Serial for DFPlayer-mini mp3 module
    delay(1);                     // delay 1ms to set volume
    mp3_set_volume (20);          // value 0~30
    delay(100); 
    mp3_play(1); //전원이 켜지면 들리는 사운드.
}

void loop() {
  //mp3_set_volume (15); 
 
  f1 = digitalRead(SW1);
  f2 = digitalRead(SW2);
  f3 = digitalRead(SW3);
  
  
  if((f1 == LOW)&&(f2 == HIGH)&&(f3 == HIGH)) {
    if(m1 == 1){
      mp3_play(2);
      m1 = 0;
      initcnt = 1;
      Serial.print("play 1\n");
    }
  }
  else if ((f1 == HIGH)&&(initcnt == 1)){
    //mp3_stop();
    mp3_play(6);
    m1 = 1;
    initcnt = 0;
    Serial.print("1\n");
  }
 //delay(2500);

  if((f1 == LOW)&&(f2 == LOW)&&(f3 == HIGH)&&(m3 == 1)) {
    if(m2 == 1){
      mp3_play(3); // 벨트에 꽂을 때.
      m2 = 0;
      Serial.print("play 2\n");
    }
  }
  else if ((f2 == HIGH) && (m2 == 0)){
    //mp3_stop();
    mp3_play(6);
    m2 = 1;
    Serial.print("2\n");
  }
  //delay(1500);


  if((f1 == LOW)&&(f2 == LOW)&&(f3 == LOW)&&(flag==0)) {
    if(m3 == 1){
      mp3_play(4); // 변신음
      m3= 0;
      Serial.print("play 3\n");
      flag = 1;
    }
  }
  else if((f3 == HIGH)&&(flag == 1)){
    while(digitalRead(SW3) == HIGH);
      m3 = 1;
      if(m3 == 1){
        mp3_play(5); // 필살기음
        m3= 0;
        Serial.print("play 4\n");
      }
    
  }
  else if ((f2 == HIGH)&& (m3 == 0)){
    //mp3_stop();
    mp3_play(6);
    m3 = 1;
    flag = 0;
    Serial.print("3\n");
  }
  
  /*if((f1 == LOW)&&(f2 == LOW)&&(f3 == LOW)) {
    henshinCnt = 1;
    flag = 1;
    delay(500);
    
    if(m3 == 1){
      if(flag == 1){
        mp3_play(4); // 변신음
        Serial.print("play 3\n");
        if (f2 == HIGH){ //
         // mp3_stop();
          mp3_play(6);
          m3 = 1;
          flag = 0;
          henshinCnt = 0;
          Serial.print("3\n");
        }
        //  delay(9500);
      }
      m3 = 0;
     }
    }
    
    else if ((f3 == LOW)&&(henshinCnt == 1)&&(m3 == 1)){
      flag++;
      if(flag > 1){
         //mp3_set_volume (25); 
          mp3_play(5); // 필살기 음
          Serial.print("play 4\n");
          //delay(5500);
      }
    }*/
    
   /*else if ((f2 == HIGH) && (m3 == 0)){
     //mp3_stop();
     mp3_play(6);
     m3 = 1;
     flag = 0;
     henshinCnt = 0;
     Serial.print("4\n");
   }*/
    //Serial.print("bug\n");
}

/*
   mp3_play ();     //start play
   mp3_play (5);    //play "mp3/0005.mp3"
   mp3_next ();     //play next
   mp3_prev ();     //play previous
   mp3_set_volume (uint16_t volume);    //0~30
   mp3_set_EQ ();   //0~5
   mp3_pause ();
   mp3_stop ();
   void mp3_get_state ();   //send get state command
   void mp3_get_volume ();
   void mp3_get_u_sum ();
   void mp3_get_tf_sum ();
   void mp3_get_flash_sum ();
   void mp3_get_tf_current ();
   void mp3_get_u_current ();
   void mp3_get_flash_current ();
   void mp3_single_loop (boolean state);    //set single loop
   void mp3_DAC (boolean state);
   void mp3_random_play ();
 */
