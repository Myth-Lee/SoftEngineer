#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>
#include <string.h>

using namespace std;

class equal_Judge
{
    string o1_path;
    string o2_path;

public:
    equal_Judge(string &o1_p, string &o2_p);
    bool is_equal();
};