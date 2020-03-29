#include <TinyPICO.h>
#include <WiFi.h>
#include <TimeLib.h>
#include "constants.h"

tmElements_t target_time = {target_second, target_minute, target_hour-gmt_offset_hours, 0, target_day, target_month, CalendarYrToTm(target_year) };
time_t target_epoch_time = makeTime(target_time);
time_t time_now;
int delta_time_hours;
byte MSB;
byte LSB;

TinyPICO tp = TinyPICO();

#define hoursLED              (27)
#define daysLED               (15)
#define weeksLED              (14)
#define monthsLED             (4)
#define data_pin              (22)
#define clock_pin             (33)
#define latch_pin             (32)
#define not_output_enable_pin (21)

const char* ntpServer = "pool.ntp.org";
const long  gmtOffset_sec = gmt_offset_hours*60*60;
const int   daylightOffset_sec = use_daylight_savings * 3600;

enum time_units
{
  hours,
  days,
  weeks,
  months,
  all
};

void set_time_units(int units)
{
  switch(units)
  {
    case hours:
      digitalWrite(hoursLED, HIGH);
      digitalWrite(daysLED, LOW);
      digitalWrite(weeksLED, LOW);
      digitalWrite(monthsLED, LOW);
      Serial.println(" hours");
      break;
    case days:
      digitalWrite(hoursLED, LOW);
      digitalWrite(daysLED, HIGH);
      digitalWrite(weeksLED, LOW);
      digitalWrite(monthsLED, LOW);
      Serial.println(" days");
      break;
    case weeks:
      digitalWrite(hoursLED, LOW);
      digitalWrite(daysLED, LOW);
      digitalWrite(weeksLED, HIGH);
      digitalWrite(monthsLED, LOW);
      Serial.println(" weeks");
      break;
    case months:
      digitalWrite(hoursLED, LOW);
      digitalWrite(daysLED, LOW);
      digitalWrite(weeksLED, LOW);
      digitalWrite(monthsLED, HIGH);
      Serial.println(" months");
      break;
    case all:
      digitalWrite(hoursLED, HIGH);
      digitalWrite(daysLED, HIGH);
      digitalWrite(weeksLED, HIGH);
      digitalWrite(monthsLED, HIGH);
      Serial.println(" overflow");
      break;
  }
}

void display_reset()
{
  digitalWrite(not_output_enable_pin, HIGH);
  digitalWrite(latch_pin, LOW);
  shiftOut(data_pin, clock_pin, LSBFIRST, 0);
  shiftOut(data_pin, clock_pin, LSBFIRST, 0);
  digitalWrite(latch_pin, HIGH);
  digitalWrite(not_output_enable_pin, LOW);
}

void display_FI()
{
  digitalWrite(latch_pin, LOW);
  shiftOut(data_pin, clock_pin, LSBFIRST, B01100000);
  shiftOut(data_pin, clock_pin, LSBFIRST, B10001110);
  digitalWrite(latch_pin, HIGH);
}

void display_number(int digits)
{
  Serial.print(digits);
  if (digits > 9)
  {
    MSB = digit_to_byte(digits / 10);
    LSB = digit_to_byte(digits % 10);
  }
  else
  {
    MSB = digit_to_byte(-1);
    LSB = digit_to_byte(digits);
  }
  // shift out to seven segment displays
  digitalWrite(latch_pin, LOW);
  shiftOut(data_pin, clock_pin, LSBFIRST, LSB);
  shiftOut(data_pin, clock_pin, LSBFIRST, MSB);
  digitalWrite(latch_pin, HIGH);
}

byte digit_to_byte(int digit)
{
  switch(digit)
  {
    case -1:
      return B00000000;
      break;
    case 0:
      return B11111100;
      break;
    case 1:
      return B01100000;
      break;
    case 2:
      return B11011010;
      break;
    case 3:
      return B11110010;
      break;
    case 4:
      return B01100110;
      break;
    case 5:
      return B10110110;
      break;
    case 6:
      return B10111110;
      break;
    case 7:
      return B11100000;
      break;
    case 8:
      return B11111110;
      break;
    case 9:
      return B11110110;
      break;
    default:
      return B00011110;
      break; 
  }
}

void setup()
{
  pinMode(hoursLED, OUTPUT);
  pinMode(daysLED, OUTPUT);
  pinMode(weeksLED, OUTPUT);
  pinMode(monthsLED, OUTPUT);
  pinMode(data_pin, OUTPUT);
  pinMode(clock_pin, OUTPUT);
  pinMode(latch_pin, OUTPUT);
  pinMode(not_output_enable_pin, OUTPUT);

  display_reset();
  
  Serial.begin(115200);
  Serial.print("Target epoch time: ");
  Serial.println(target_epoch_time);
  
  WiFi.disconnect(true);
  WiFi.mode(WIFI_OFF);
  WiFi.begin(secret_ssid, secret_password);
  delay(100);
  display_FI();
  while (WiFi.status() != WL_CONNECTED)
  {
    Serial.print("Trying to connect to SSID: ");
    Serial.print(secret_ssid);
    Serial.print(" with password: ");
    Serial.println(secret_password);
    delay(500);
    digitalWrite(not_output_enable_pin, !digitalRead(not_output_enable_pin));
  }
  display_reset();
  configTime(gmtOffset_sec, daylightOffset_sec, ntpServer);
  time(&time_now);
  delay(1000);
}

void loop()
{
  time(&time_now);
  Serial.print("Delta seconds: ");
  Serial.println(target_epoch_time - time_now);
  delta_time_hours = abs(target_epoch_time - time_now) / 3600;
  if (delta_time_hours < 1)
  {
    display_number(0);
    set_time_units(hours);
  }
  else if (delta_time_hours < 100)
  {
    display_number(delta_time_hours);
    set_time_units(hours);
  }
  else if (delta_time_hours < 100*24)
  {
    display_number(delta_time_hours/24);
    set_time_units(days);
  }
  else if (delta_time_hours < 100*24*7)
  {
    display_number(delta_time_hours/24/7);
    set_time_units(weeks);
  }
  else if (delta_time_hours < 100*24*(365.24/12))
  {
    display_number(delta_time_hours/24/(365.24/12));
    set_time_units(months);
  }
  else
  {
    display_number(99);
    set_time_units(all);
    delay(10000); // delay 10 seconds
    return;
  }

  delay(120000); // update every 2 minutes

}
