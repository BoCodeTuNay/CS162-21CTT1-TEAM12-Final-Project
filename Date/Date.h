#include <iostream>
using namespace std;
struct Date {
	int year;
	int month;
	int day;
	Date();
	Date(string date);

	void enter_date();
};
void output_date(Date date);
bool check_leap_year(int year);
int day_of_month(int month, int year);
bool check_date(Date date);
bool ifDate(Date date, Date start, Date end);
Date getThisDate();