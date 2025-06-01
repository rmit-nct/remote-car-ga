// Thêm bộ thư viện
// Add the library.


#define CUSTOM_SETTINGS
#define INCLUDE_GAMEPAD_MODULE
#include "MKL_Dabble.h"

#define MOTORLEFT1 6 //! D6
#define MOTORLEFT2 7 //! D7 (~)
#define MOTORRIGHT1 4 //! D4 (~)
#define MOTORRIGHT2 5 //! D5


#define TX_PIN 12
#define RX_PIN 13

// Khai báo module.
// Declare module.
SoftwareSerial mySoftwareSerial(RX_PIN, TX_PIN);
MKE_M15_SSerial(mySoftwareSerial);

String value;

void setup()
{
  // Khởi động LCD
  // LCD start
  pinMode(MOTORLEFT1, OUTPUT);
  pinMode(MOTORLEFT2, OUTPUT);
  pinMode(MOTORRIGHT1, OUTPUT);
  pinMode(MOTORRIGHT2, OUTPUT);
  

  // Khởi động kết nối Serial UART ở tốc độ 115200 để truyền dữ liệu lên máy tính.
  // Start the Serial UART connection at 115200 to transfer data to the computer.
  Serial.begin(115200);
  Serial.println("Start");

  // Khởi tạo module
  // init module
  
  // MKE_M15.setBaudrate(9600); // safe speed for SoftwareSerial is 9600
  // MKE_M15.setName("MKE-M15"); // max 12 characters
  mySoftwareSerial.begin(9600);
  Dabble.begin(mySoftwareSerial);
  
}




void loop()
{
  Dabble.processInput();

  if (GamePad.isUpPressed())
  {
    // value = "UP";
    runforward();
  }
  else if (GamePad.isDownPressed())
  {
    // value = "DOWN";
    runbackward();
  }
  else if (GamePad.isLeftPressed())
  {
    // value = "LEFT";
    runleft();
  }
  else if (GamePad.isRightPressed())
  {
    // value = "RIGHT";
    runright();
  }
  else{
    // value = "0";
    stop();
  }

  if(value == "0") return;

  // Hiển thị giá trị của module lên máy tính.
  // Show the module value on Arduno Serial Monitor
  // Serial.println(value);

  //Gửi giá trị module lên LCD
  //Show the module value on LCD

  // Chờ 50ms
  // Wait 50ms  
  delay(50);
}

void stop(){

  digitalWrite(MOTORRIGHT1, LOW);
  digitalWrite(MOTORRIGHT2, LOW);

  digitalWrite(MOTORLEFT1, LOW);
  digitalWrite(MOTORLEFT2, LOW);

}


void runforward(){
  digitalWrite(MOTORRIGHT1, LOW);
  digitalWrite(MOTORRIGHT2, HIGH);

  digitalWrite(MOTORLEFT1, LOW);
  digitalWrite(MOTORLEFT2, HIGH);

}


void runbackward(){
  digitalWrite(MOTORRIGHT1, HIGH);
  digitalWrite(MOTORRIGHT2, LOW);

  digitalWrite(MOTORLEFT1, HIGH);
  digitalWrite(MOTORLEFT2, LOW);

}



void runleft(){
  digitalWrite(MOTORRIGHT1, LOW);
  digitalWrite(MOTORRIGHT2, HIGH);

  digitalWrite(MOTORLEFT1, HIGH);
  digitalWrite(MOTORLEFT2, LOW);

}



void runright(){
  digitalWrite(MOTORRIGHT1, HIGH);
  digitalWrite(MOTORRIGHT2, LOW);

  digitalWrite(MOTORLEFT1, LOW);
  digitalWrite(MOTORLEFT2, HIGH);

}



