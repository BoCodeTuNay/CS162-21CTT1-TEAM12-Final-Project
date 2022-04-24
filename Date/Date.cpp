#include "Date.h"

// from MINH: Đầu tiên cần quy ước format hiển thị ngày là dd/mm/yyyy, hay là dd-mm-yyyy, hay là yyyy-mm-dd.
// vì format trong hàm enter_date() một kiểu và format trong hàm output_date lại một kiểu
// Viết format đó ở đầu file này nhé

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
void output_date(Date date)
{
	cout << date.day << "/" << date.month << "/" << date.year; // quy ước format lại
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
	string tmp;
	cout << "Enter the date (example: 2020-12-31): "; // from MINH: không cần dòng này vì chỗ nào gọi hàm này sẽ tự cout trước khi gọi
	cin >> tmp; // from MINH: Kiểm tra bad input (không nhập gì, nhập sai format date đã quy ước, ký tự lạ). Có thể dùng char[] thay string

	year = stoi(tmp.substr(0, 4)); // from MINH: kiểm tra 4 ký tự này có phải chữ số không, có thể dùng hàm checkDigit trong Constants.h
	month = stoi(tmp.substr(5, 2)); // tương tự
	day = stoi(tmp.substr(8, 2)); // tương tự
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


Date getCurrentDate() {
	Date cur; 
	time_t now = time(0);
	tm* tmp = localtime(&now);
	cur.year = 1900 + tmp->tm_year;
	cur.month = tmp->tm_mon + 1;
	cur.day = tmp->tm_mday;
	return cur;
}
