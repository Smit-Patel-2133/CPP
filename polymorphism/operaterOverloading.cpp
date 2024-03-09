#include <iostream>
using namespace std;
class Marks
{
private:
    int intMark;
    int extMark;

public:
    Marks()
    {
        intMark = 0;
        extMark = 0;
    }

    Marks(int im, int em)
    {
        intMark = im;
        extMark = em;
    }
    void Display()
    {
        cout << intMark << endl
             << extMark << endl;
    }
    Marks operator+(Marks m)
    {
        Marks Temp;
        Temp.intMark = intMark + m.intMark;
        Temp.extMark = extMark + m.extMark;
        return Temp;
    }
    Marks operator-(Marks m)
    {
        Marks Temp;
        Temp.intMark = intMark - m.intMark;
        Temp.extMark = extMark - m.extMark;
        return Temp;
    }
    Marks operator*(Marks m)
    {
        Marks Temp;
        Temp.intMark = intMark * m.intMark;
        Temp.extMark = extMark * m.extMark;
        return Temp;
    }
    Marks operator/(Marks m)
    {
        Marks Temp;
        Temp.intMark = intMark / m.intMark;
        Temp.extMark = extMark / m.extMark;
        return Temp;
    }
};
int main()
{
    Marks m1(10, 20), m2(30, 40);
    Marks m3 = m1 + m2;
    Marks m4 = m1 - m2;
    Marks m5 = m1 * m2;
    Marks m6 = m1 / m2;

    m3.Display();
    m4.Display();
    m5.Display();
    m6.Display();
    return 0;
}
