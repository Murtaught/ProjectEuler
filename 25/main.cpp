#include <iostream>
#include <vector>
using namespace std;

class BigInt
{
    typedef vector<char> CONTAINER_TYPE;
    mutable CONTAINER_TYPE cont;

private:
    // Housekeeping
    void resize(size_t new_size) const
    {
        size_t old_size = cont.size();

        if (new_size > old_size)
        {
            cont.resize(new_size, 0);
        }
    }

    void trim() const
    {
        while ( cont.back() == 0 )
            cont.pop_back();
    }

public:
    BigInt()
        : cont(1, 0) // [0]
    {}

    BigInt(BigInt const& other)
        : cont(other.cont)
    {}

    BigInt& operator=(BigInt const& other)
    {
        cont = other.cont;
        return *this;
    }

    BigInt(string const& s)
    {
        size_t length = s.length();
        cont.resize(length);

        for (size_t i = 0; i < length; ++i)
            cont[i] = s[length - i - 1] - '0';
    }

    // Methods:
    string to_string()
    {
        trim();

        string s(cont.size(), '0');
        for (size_t i = 0; i < cont.size(); ++i)
            s[i] = cont[cont.size() - i - 1] + '0';

        return s;
    }

    void add(BigInt const& other)
    {
        size_t max_size = max(cont.size(), other.cont.size());

        resize(max_size + 1);
        other.resize(max_size + 1);

        int carry = 0;
        for (size_t i = 0; i < max_size; ++i)
        {
            int tmp = cont[i] + other.cont[i] + carry;
            carry   = tmp / 10;
            cont[i] = tmp % 10;
        }

        cont[max_size] = carry;
    }

    size_t digits_amount()
    {
        trim();
        return cont.size();
    }
};

int main()
{
    unsigned int num = 3;
    BigInt a("1"), b("1"), c("2");

    while ( c.digits_amount() < 1000 )
    {
        a = b;
        b = c;
        c.add(a);

        ++num;
    }

    cout << "First Fibonacci number to have 1000 digits is " << num << endl;

    return 0;
}

