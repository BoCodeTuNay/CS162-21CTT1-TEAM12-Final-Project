struct Date {
	int year;
	int month;
	int day;
};
void output_date(Date date);
bool check_leap_year(int year);
int day_of_month(int month, int year);
bool check_date(Date date);
void enter_date(Date& date);