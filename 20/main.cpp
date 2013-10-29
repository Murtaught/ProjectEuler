#include <cstdio>
#include <iostream>
#include <string>
using namespace std;
typedef unsigned long long int uint64;

const int N = 100;

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

    void short_multiply(int mult)
    {
        uint64 carry = 0;
        for (int i = 0; i < length; ++i)
        {
            uint64 tmp = mult * digits[i] + carry;
            carry     = tmp / 10;
            digits[i] = tmp % 10;
        }

        while (carry != 0)
        {
            resize(length + 1);
            digits[length - 1] = carry % 10;
            carry /= 10;
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
    BigInt tmp("1");

    for (int i = 2; i <= N; ++i)
        tmp.short_multiply(i);

    cout << "Sum of digits of " << N << "! is " << tmp.sum_of_digits() << endl;

    return 0;
}

