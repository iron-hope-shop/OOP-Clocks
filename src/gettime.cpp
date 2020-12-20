/* 
* Chada Tech gettime header file
* @author Brad Jackson
* @description Returns current time in string format, output determined by modHour, modMinute, and modSecond input values (defaults to zero)
*/

#include <ctime>
#include <iostream>
#include <locale>
using namespace std;

string TwelveHour(int modHour, int modMinute, int modSecond)
{
  time_t t = time(nullptr);
  // converts time object to structure to be manipulated
  struct tm *tm = localtime(&t);
  // adds input values to time
  tm->tm_hour += modHour;
  tm->tm_min += modMinute;
  tm->tm_sec += modSecond;
  // renders time to time_t object
  time_t m = mktime(tm);
  // creates character buffer for strftime
  char mbstr[100];
  if (strftime(mbstr, sizeof(mbstr), "%r", localtime(&m)))
  {
    return mbstr;
  }
  return "error";
}

string TwentyFourHour(int modHour, int modMinute, int modSecond)
{
  time_t t = time(nullptr);
  struct tm *tm = localtime(&t);
  tm->tm_hour += modHour;
  tm->tm_min += modMinute;
  tm->tm_sec += modSecond;
  time_t m = mktime(tm);
  char mbstr[100];
  if (strftime(mbstr, sizeof(mbstr), "%H:%M:%S", localtime(&m)))
  {
    return mbstr;
  }
  return "error";
}
