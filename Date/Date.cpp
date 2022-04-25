#include "Date.h"
#include "..\Constants\Constants.h"
#include <stdlib.h>
#include <string.h>
//format date là yyyy/mm/dd nhe ông
Date::Date()
{
	day = 1;
	month = 1;
	year = 2020;
}

Date::Date(string date) {
		year = stoi(date.substr(0, 4)); // from MINH: kiểm tra 4 ký tự này có phải chữ số không, có thể dùng hàm checkDigit trong Constants.h
		month = stoi(date.substr(5, 2)); // tương tự...
		day = stoi(date.substr(8, 2)); // tương tự...
}
void Date::output_date()
{
	cout << year << "/" << month << "/" << day; // quy ước format lại
}

//*Kiem tra nam nhuan
bool check_leap_year(int year)
{
	return ((year % 4 == 0) && (year % 100 != 0) || (year % 400 == 0));
}
//*So ngay cua thang
int day_of_month(int month, int year)
{
	switch (month)
	{
	case 1:case 3:case 5:case 7:case 8:case 10:case 12:	return 31;
	case 4:case 6:case 9:case 11: return 30;
	default:
		if (check_leap_year(year))
		{
			return 29;
		}
		else return 28;
		break;
	}
}
//*Kiem tra tinh hop le cua ngay thang
bool check_date(Date date)
{
	if (date.year <= 0 || date.month <= 0)
	{
		return false;
	}
	if (date.month < 1 || date.month>12)
	{
		return false;
	}
	if (date.day <= 0 || date.day > day_of_month(date.month, date.year))
	{
		return false;
	}
	return true;
}
// Nhap ngay
void Date::enter_date() {
	char tmp[11];
	auto validDate = [](char* date) -> bool {
		if (strlen(date) != 10) return false;
		if (date[4] != '/' || date[7] != '/') return false;
		char* fi = date; fi[4] = '0'; fi[7] = '0';
		if (!checkDigit(fi)) return false;
		Date dat;
		char* day = (fi + 8);
		dat.day = atoi(day);
		char* month = (fi + 5);
		dat.month = (atoi(month) - dat.day) / 1000;
		int x = atoi(fi);
		x = (x - dat.month*1000 - dat.day)/1000000;
		dat.year = x;
		if (!check_date(dat)) return false;
		return true;
	};
	bool cont{ false };
	do {
		std::cout << "Enter the date (format: yyyy/mm/dd): ";
		// check for bad input
		fflush(stdin);
		std::cin.get(tmp, 11 , '\n');
		if (std::cin.fail() || std::cin.get() != '\n' || !validDate(tmp)) {
			std::cin.clear();
			fflush(stdin);
			std::cout << "The date is invalid. Please try again.\n";
			cont = true;
		}
		else cont = false;
	} while (!cont);
	tmp[4] = '0'; tmp[7] = '0';
	char* d = (tmp + 8);
	day = atoi(d);
	char* m = (tmp + 5);
	month = (atoi(m) - day) / 1000;
	long long x = atoi(tmp);
	x = (x - month*1000 - day) / 1000000;
	year = x;
}
//*Check xem ngay da cho co nam giua 2 ngay khac khong
bool ifDate(Date date, Date start, Date end) {
	if ((date.year>start.year)&&(date.year<=end.year)||(date.year>=start.year)&&(date.year<end.year)) {
		return true;
	} else if ((date.year==start.year)&&(date.year==end.year)) {
		if ((date.month>start.month)&&(date.month<=end.month)||(date.month>=start.month)&&(date.month<end.month)) {
		return true;
		} else if ((date.month==start.month)&&(date.month==end.month)){
			if ((date.day>=start.day)&&(date.day<=end.day)){
				return true;
			}
		}
	}
	return false;
}

// return true: A >= B, false: B < A
bool cmpDate(Date A, Date B)
{
	if (A.year > B.year)
		return true;
	else if (A.year == B.year)
	{
		if (A.month > B.month)
			return true;
		else if (A.month == B.month)
		{
			if (A.day > B.day)
				return true;
			else if (A.day == B.day)
				return false;
			else
				return false;
		}
		else
			return false;
	}
	else
		return false;
}


Date getCurrentDate() {
	Date cur; 
	time_t now = time(0);
	tm* tmp = localtime(&now);
	cur.year = 1900 + tmp->tm_year;
	cur.month = tmp->tm_mon + 1;
	cur.day = tmp->tm_mday;
	return cur;
}
