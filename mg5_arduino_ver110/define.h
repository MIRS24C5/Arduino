/* 変数型の定義 */
typedef enum {
  STP = 0,
  STR,
  ROT
} run_state_t;

typedef struct {
  unsigned char val[7];
} serial_data_t;

typedef struct {
  unsigned char val[6];
} middle_data_t;

typedef struct {
  signed short val[3];
} command_data_t;

/* ピン配置 */
#define PIN_ENC_A_L  2
#define PIN_ENC_B_L  4
#define PIN_ENC_A_R  3
#define PIN_ENC_B_R  7
#define PIN_DIR_R    8
#define PIN_PWM_R    9
#define PIN_DIR_L   12
#define PIN_PWM_L   11
#define PIN_SW      10
#define PIN_LED     13
#define PIN_BATT    19

/* パラメータ */
// 動作周期 [ms]
#define T_CTRL 10 

// タイヤ半径 [cm] 
// test_run_ctrl()のSTRモードでの走行距離もともに補正する
#define R_TIRE     4.0 

// タイヤ間隔 [cm]
// test_run_ctrl()のROTモードでの回転角をもとに補正する
#define D_TIRE    32.0

// エンコーダ分解能 (A相立上り/立下りを利用するため2倍)
#define ENC_RANGE (2048*2) 

// ギア比　（該当するものを選択）
// 1/14 ギア  
#define GEAR_RATIO 1.0

// 左タイヤに対する右タイヤの回転比
#define L_R_RATIO  1.0 

// バッテリ入力の分圧比
#define V_RATIO 0.5 
