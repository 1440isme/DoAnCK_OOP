#ifndef DATETIME_H
#define DATETIME_H

#include <string>
#include <iostream>
#include <ctime>
using namespace std;

class DateTime {
public:
    int day, month, year, hour, minute;

    DateTime() : day(0), month(0), year(0), hour(0), minute(0) {}
    DateTime(int d, int m, int y, int h, int min)
        : day(d), month(m), year(y), hour(h), minute(min) {}

    void displayDateTime() const {
        cout << day << "/" << month << "/" << year << " " << hour << ":" << minute << endl;
    }

    string toString() const {
        return to_string(day) + "/" + to_string(month) + "/" +
            to_string(year) + " " + to_string(hour) + ":" +
            to_string(minute);
    }

    bool isValid() const {
        if (year < 0 || month < 1 || month > 12 || day < 1 || day > 31 || hour < 0 || hour >= 24 || minute < 0 || minute >= 60)
            return false;
        if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
            return false;
        if (month == 2) {
            bool isLeap = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
            if ((isLeap && day > 29) || (!isLeap && day > 28))
                return false;
        }
        return true;
    }

    bool isLaterThan(const DateTime& other) const {
        if (year > other.year) return true;
        if (year == other.year && month > other.month) return true;
        if (year == other.year && month == other.month && day > other.day) return true;
        if (year == other.year && month == other.month && day == other.day && hour > other.hour) return true;
        if (year == other.year && month == other.month && day == other.day && hour == other.hour && minute > other.minute)
            return true;
        return false;
    }

    DateTime getCurrentDate() {
        time_t now = time(0);
        tm *ltm = localtime(&now);

        static DateTime currentDate(
            ltm->tm_mday,
            1 + ltm->tm_mon,
            1900 + ltm->tm_year,
            ltm->tm_hour,
            ltm->tm_min
        );

        return currentDate;
    }

    int calculateDaysDifference(const DateTime &end, const DateTime &current) {
        auto toDays = [](const DateTime &dt) {
            return dt.year * 365 + dt.month * 30 + dt.day;
        };

        return toDays(current) - toDays(end);
    }
};

#endif
