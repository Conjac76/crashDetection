#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>
#include <LiquidCrystal.h>
#include <Wire.h>

/*
* Uses Adafruit mpu6060 library
* https://github.com/adafruit/Adafruit_MPU6050
*/
Adafruit_MPU6050 mpu;

const int rs = 7, en = 6, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

int accellx[2] = { NULL };
int accelly[2] = { NULL };
void setup(void) {
  Serial.begin(115200);
 
  lcd.begin(16, 2);
  lcd.clear();
  /* pin 13 is for the additional led */
  pinMode(13, OUTPUT);
  pinMode(8, INPUT);
  digitalWrite(8, HIGH);
  pinMode(9, INPUT);
  digitalWrite(9, HIGH);

  /* ensure MPU6050 is noticed by the arduino */
  if (!mpu.begin()) {
    Serial.println("no gyro");
    while (1) {
      delay(10);
    }
  }
  Serial.println("working");

  /* accelerometer range 8g
  * this is the limit for accelerometer
  lower number, higher sensitivity
*/
  mpu.setAccelerometerRange(MPU6050_RANGE_8_G);

  /*  gyro range 500 deg
  *  this is the limit for gyro range
  lower number, higher sensitivity
*/
  mpu.setGyroRange(MPU6050_RANGE_500_DEG);

  /* filter bandwidth 21 Hz
  * in order to filter out high frequency noise
  */ not sure why 21 Hz however thats what adafruit uses
  mpu.setFilterBandwidth(MPU6050_BAND_21_HZ);
  delay(100);
}
  /* Holds current time */
  unsigned long currentMillis;
  /* Holds  difference between (currentMillis - startMillis) */
  unsigned long elapsedMillis;
  /* Holds total time */
  unsigned long startMillis;

  int i = 0;