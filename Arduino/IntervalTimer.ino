/*
  IntervalShot
 */

//シャッター全押しを２番に設定
#define FULL_RELEASE_PIN (2)
//インターバルタイムを60秒に設定
#define INTERVAL_TIME (86400000)
//#define INTERVAL_TIME (60000) 
//#define INTERVAL_TIME (1080000)
//    60000->60s
//  3600000->60m=1h
// 21600000-> 6h
// 43200000->12h
// 86400000->24h


unsigned long shoot_time; 

void setup() {                
  pinMode(FULL_RELEASE_PIN, OUTPUT);
  digitalWrite(FULL_RELEASE_PIN,LOW);
  shoot_time = millis() + INTERVAL_TIME;  
}

void loop() {
          //全押し（写真撮影）
         digitalWrite(FULL_RELEASE_PIN,HIGH);
         delay(1000);
   
         //スイッチオフ
         digitalWrite(FULL_RELEASE_PIN,LOW);
     
         //次の撮影時間を設定　
         delay(INTERVAL_TIME);
   
         //次の撮影時間を設定
         shoot_time = millis() + INTERVAL_TIME;
}
