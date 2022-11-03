#include "Platform.h"

int main()
{
    int tnum;
    cout << "please confirm the number of testcases:";
    cin >> tnum;
    Platform *p = new Platform(tnum);
    p->Run();
}