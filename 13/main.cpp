#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

const int AMOUNT = 100;

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

    void add(BigInt const& other)
    {
        int max_length = other.length;
        if (length > max_length)
            max_length = length;

        resize(max_length + 1);
        other.resize(max_length + 1);

        int carry = 0;
        for (int i = 0; i < max_length; ++i)
        {
            int tmp = digits[i] + other.digits[i] + carry;
            carry     = tmp / 10;
            digits[i] = tmp % 10;
        }

        digits[max_length] = carry;
    }
};

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    BigInt sum;
    for (int amount = 0; amount < AMOUNT; ++amount)
    {
        string summand_str;
        cin >> summand_str;

        printf("(%d/%d) Adding %s... ",
               amount + 1, AMOUNT, summand_str.c_str());

        BigInt summand( summand_str );
        sum.add(summand);

        cout << "done.  ::= " << sum.to_string() << endl;
    }

    cout << "\nResult: " << sum.to_string() << endl;

    fclose(stdout);
    return 0;
}

