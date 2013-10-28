#include <iostream>
#include <string>
using namespace std;
typedef unsigned int uint;

string pronounce_int(uint num)
{
    if (num < 10)
    {
        static const string PRONOUNCE10[10]
            = { "zero", "one", "two", "three",
                "four", "five", "six", "seven",
                "eight", "nine" };

        return PRONOUNCE10[num];
    }

    if (num < 20)
    {
        static const string PRONOUNCE20[10]
            = { "ten", "eleven", "twelve", "thirteen",
                "fourteen", "fifteen", "sixteen", "seventeen",
                "eighteen", "nineteen" };

        return PRONOUNCE20[num - 10];
    }

    if (num < 100) // and >= 20
    {
        uint tens  = num / 10;
        uint units = num % 10;

        static const string PRONOUNCE_TENS[10]
            = { "???", "???", "twenty", "thirty",
                "forty", "fifty", "sixty", "seventy",
                "eighty", "ninety" };

        if ( units > 0 )
            return PRONOUNCE_TENS[tens] + " " + pronounce_int(units);
        else
            return PRONOUNCE_TENS[tens];
    }

    if (num < 1000) // and >= 100
    {
        uint hundreds = num / 100;
        uint units    = num % 100;

        string tmp = pronounce_int(hundreds) + " hundred";

        if (units > 0)
            tmp += " and " + pronounce_int(units);

        return tmp;
    }

    if (num == 1000)
    {
        return "one thousand";
    }

    return "???";
}

uint count_letters(string const& s)
{
    uint sum = 0;
    for (uint i = 0; i < uint(s.size()); ++i)
        if ( 'a' <= s[i] && s[i] <= 'z' )
            ++sum;

    return sum;
}

int main()
{
    uint sum = 0;

    for (int i = 1; i <= 1000; ++i)
    {
        string s = pronounce_int( i );
        //cout << i << ": " << s << endl;

        sum += count_letters(s);
    }

    cout << "Totally " << sum << " letters." << endl;

    return 0;
}

