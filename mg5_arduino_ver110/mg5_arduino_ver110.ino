/*
  Ver1.00 から変更点
  - define.h の ENC_RANGE と GEAR_RATION の値を変更
  - vel_ctrl の Kp, Ki のディフォルト値を変更
  - run_ctrl の Ks_p, Ks_d のディフォルト値を変更
 */

#include "define.h"

void setup() {
  io_open();
  encoder_open();
  motor_open();
  raspi_open();
  Serial.begin(9600);
}

static float ground_dis = 0.0;

void loop() {

  if(Serial.available() > 0){
    String inStr = Serial.readStringUntil('\n');
    ground_dis = inStr.toFloat();
  }
  
  /*
  いずれか一つの関数を有効にする。
  どの関数も無限ループになっている。しがたってこの loop 関数は実際にはループしない。
  */

  /* RasPi からの指令で動作させるとき、slave を有効にする。*/
  //slave();
  
  /* --------------機能のテスト---------------------------------------------
    テスト関数 test_*() のいずれかを有効にする。
    実行時にシリアルモニタを立ち上げて値を確認する。
  ------------------------------------------------------------------------- */

  /* モータ動作テスト 引数：左モータのPWM値、右モータのPWM値　（範囲は -255～255）*/
  //test_motor(25, 25);

  /* エンコーダテスト（モータを回転させて行う）*/
  //motor_set(50, 50) ; test_encoder();
  /* 距離計のテスト（モータを回転させて行う）*/
  //motor_set(50, 50) ; test_distance();

  /* 速度制御のテスト　引数：左モータの速度[cm/s]、右モータの速度[cm/s] */
  //test_vel_ctrl(25, 25);
  /* 走行制御のテスト　
    引数：モード（直進：STR or 回転：ROT)、速度[cm/s] or 角速度[deg/s]、距離[cm] or 角度 の速度[deg] 
    距離 > 0 ：前進、角度 < 0 ：後退　（速度は常に > 0）
    角度 > 0 ：反時計回り、角度 < 0 ：時計回り　（角速度は常に > 0）
  */
  //test_run_ctrl(STR, 10, 40);
  //test_run_ctrl(ROT, 45, 90);

  //Serial.println(ground_dis);
  
  if(ground_dis <= 30 && ground_dis >= 0){
    //Serial.println("x");
    test_run_ctrl(STR, 5, 5);
    //Serial.println("a");
  }
  reset();
  //ground_dis = 0.0;
  delay(1000);
  //Serial.println("b");
  //Serial.println("done");
  
  /* バッテリー値の確認 */
  //test_batt();

  /* シリア通信のエンコード、デコーダ値の確認 */
  //test_encoder();
  //test_decode();

}
