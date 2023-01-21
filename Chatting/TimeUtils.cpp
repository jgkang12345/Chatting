#include "TimeUtils.h"
#include <time.h>
#include <ctime>
#include <sys/timeb.h>
#include <iostream>
#include <Windows.h>
#include <string>
double TimeUtils::CurrentTickSum()
{
   SYSTEMTIME cur_time;
   GetLocalTime(&cur_time);
   
   std::string year = std::to_string(cur_time.wYear);
   std::string month = std::to_string(cur_time.wMonth);
   if (month.size() == 1)
   {
	   month = "0" + month;
   }
   std::string day = std::to_string(cur_time.wDay);
   if (day.size() == 1)
   {
	   day = "0" + day;
   }
   std::string hour = std::to_string(cur_time.wHour);
   if (hour.size() == 1)
   {
	   hour = "0" + hour;
   }
   std::string minute = std::to_string(cur_time.wMinute);
   if (minute.size() == 1)
   {
	   minute = "0" + minute;
   }
   std::string second = std::to_string(cur_time.wSecond);
   if (second.size() == 1)
   {
	   second = "0" + second;
   }
   std::string ms = std::to_string(cur_time.wMilliseconds);
   if (ms.size() == 1)
   {
	   ms = "00" + ms;
   }
   else if (ms.size() == 2)
   {
	   ms = "0" + ms;
   }
   double time = std::stod(year + month + day + hour + minute + second + ms);
   return time;
}
