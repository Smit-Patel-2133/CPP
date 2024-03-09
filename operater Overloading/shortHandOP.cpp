#include <iostream>
using namespace std;
class Marks
{
private:
    int Mark;

public:
    Marks()
    {
        Mark = 0;
    }

    Marks(int m)
    {
        Mark = m;
    }
    void Display()
    {
        cout << "your mark is" << Mark << endl;
    }
    void operator+=(int incMark)
    {
        Mark += incMark; // member of Mark class
        // another way
        // Mark = Mark+incMark;
    }
    friend void operator-=(Marks &curObj, int redmark); // friend of Marks class so we need to pass the parameters
};
void operator-=(Marks &curObj, int redmark)
{
    curObj.Mark -= redmark;
    // another way
    // curObj.Mark = curObj.Mark - redmark;
}
int main()
{
    Marks Smit_marks(90);
    Smit_marks.Display();
    Smit_marks += 30;
    Smit_marks.Display();
    Smit_marks -= 30;
    Smit_marks.Display();

    return 0;
}
