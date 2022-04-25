#pragma once

#include <iostream>
#include <ctime>
#include "..\Constants\Constants.h"
#include <stdlib.h>
#include <string.h>
using namespace std;


struct Date {
	int year;
	int month;
	int day;
	Date();
	Date(string date);

	void enter_date();
	void output_date();
};

bool check_leap_year(int year);
int day_of_month(int month, int year);
bool check_date(Date date);
bool ifDate(Date date, Date start, Date end);
bool cmpDate(Date A, Date B);
Date getCurrentDate();

#include "Date.cpp"