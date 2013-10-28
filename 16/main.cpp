#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

const int POWER = 1000;

class BigInt
{
private:
    mutable int   length;
    mutable char *digits;

    // Forbidden
    BigInt(BigInt const& other);
    BigInt& operator=(BigInt const& other);

    // Housekeeping
    void resize(int new_size) const
    {
        if (new_size > length)
        {
            char *tmp_buf = new char[new_size];

            for (int i = 0; i < length; ++i)
                tmp_buf[i] = digits[i];
            for (int i = length; i < new_size; ++i)
                tmp_buf[i] = 0;

            delete[] digits;
            digits = tmp_buf;

            length = new_size;
        }
    }

    void trim() const
    {
        while ( digits[length - 1] == 0 )
            --length;
    }

public:
    BigInt()
    {
        length = 1;
        digits = new char[1];
        digits[0] = 0;
    }

    BigInt(string const& s)
    {
        length = s.length();
        digits = new char[length];

        for (int i = 0; i < length; ++i)
            digits[i] = s[length - i - 1] - '0';
    }

    ~BigInt()
    {
        delete digits;
    }

    // Methods:
    string to_string()
    {
        trim();

        string s(length, '0');
        for (int i = 0; i < length; ++i)
            s[i] = digits[length - i - 1] + '0';

        return s;
    }

    void x2()
    {
        int carry = 0;
        for (int i = 0; i < length; ++i)
        {
            int tmp = 2 * digits[i] + carry;
            carry     = tmp / 10;
            digits[i] = tmp % 10;
        }

        if ( carry != 0 )
        {
            resize(length + 1);
            digits[length - 1] = carry;
        }
    }

    int sum_of_digits()
    {
        int sum = 0;
        for (int i = 0; i < length; ++i)
            sum += digits[i];

        return sum;
    }
};
int main()
{
    BigInt x("1");

    cout << "2^0 = 1" << endl;
    for (int p = 1; p <= POWER; ++p)
    {
        x.x2();
        cout << "2^" << p << " = " << x.to_string() << endl;
    }

    cout << "\nSum of digits of 2^" << POWER << " is " << x.sum_of_digits() << endl;

    return 0;
}

