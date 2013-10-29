#include <iostream>
#include <string>
using namespace std;

enum Month
{
    January   = 0,
    February  = 1, // 29 days in leap years
    March     = 2,
    April     = 3,
    May       = 4,
    June      = 5,
    July      = 6,
    August    = 7,
    September = 8,
    October   = 9,
    November  = 10,
    December  = 11
};

enum WeekDay
{
    Monday,
    Tuesday,
    Wednesday,
    Thursday,
    Friday,
    Saturday,
    Sunday
};

template<typename T>
T next_(T day, int mod, int amount = 1)
{
    return T( (int(day) + amount) % mod );
}

bool is_leap(int year)
{
    return ((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0);
}

int month_length(Month month, int year)
{
    static const int MONTH_LENGTH[] =
    { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

    if ( month == February && is_leap(year) )
        return 29;
    else
        return MONTH_LENGTH[month];
}

class Date
{
    friend int operator-(Date const&, Date const&);

private:
    int     day;   // starting from 1
    Month   month; // starting from 0
    int     year;  // absolute, e.g. 1973

    WeekDay weekday;

    void find_weekday()
    {
        // 1 Jan 1900 was a Monday.
        Date known(1, January, 1900, int(Monday));

        while (known < *this)
            known.next_day();

        weekday = known.weekday;
    }

public:
    // ctors
    Date(int d, Month m, int y, int weekday = -1)
        : day(d), month(m), year(y)
    {
        if ( weekday != -1 )
            this->weekday = WeekDay(weekday);
        else
            find_weekday();
    }

    Date(Date const& other)
        : day(other.day),
          month(other.month),
          year(other.year),
          weekday(other.weekday)
    {}

    // comparison
    bool operator<(Date const& other)
    {
        if (year < other.year)
            return true;

        if (year == other.year)
        {
            if (month < other.month)
                return true;

            if (month == other.month)
            {
                return (day < other.day);
            }
            else
                return false;
        }
        else
            return false;
    }

    bool operator==(Date const& other)
    {
        return (year  == other.year)  &&
               (month == other.month) &&
               (day   == other.day);
    }

    bool operator<=(Date const& other) { return operator<(other) || operator==(other); }
    bool operator >(Date const& other) { return !operator<(other) && !operator==(other); }
    bool operator>=(Date const& other) { return operator>(other) || operator==(other); }

    bool operator!=(Date const& other) { return !operator==(other); }

    // methods
    void next_day(int amount = 1)
    {
        day += amount;
        weekday = next_(weekday, 7, amount);

        while ( day > month_length(month, year) )
        {
            day -= month_length(month, year);

            //month = Month((int(month) + 1) % 12);
            month = next_(month, 12);

            if ( month == January )
                ++year;
        }
    }

    void next_month()
    {
        next_day( month_length(month, year) );
    }

    WeekDay day_of_the_week()
    {
        return weekday;
    }

    string to_string()
    {
        static const string MONTHS_STR[] =
        { "Jan", "Feb", "Mar", "Apr", "May", "Jun",
          "Jul", "Aug", "Sep", "Oct", "Nov", "Dec" };

        static const string WEEKDAYS_STR[] =
        { "Mon", "Tue", "Wed", "Thu", "Fri", "Sat", "Sun" };

        return string(WEEKDAYS_STR[weekday]) + ", " +
               std::to_string(day) + " " +
               string(MONTHS_STR[month]) + " " +
               std::to_string(year);
    }
};

int main()
{
    Date start(1, January, 1901);
    Date finish(31, December, 2000);

    int sundays = 0;

    Date cur = start;
    do {
        if ( cur.day_of_the_week() == Sunday )
            ++sundays;

        cout << cur.to_string() << endl;
        cur.next_month();

    } while (cur <= finish);

    cout << sundays << " sundays fell on the 1st of the month during XX century." << endl;

    return 0;
}

