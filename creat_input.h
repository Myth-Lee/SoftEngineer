#include <iostream>
#include <stdio.h>
#include <vector>
#include <regex>

using namespace std;

struct Type
{
    int kind; //0 int, 1 char, 2 string
    int a, b;
    int line;
};

class Format_input
{
public:
    vector<Type> input;
    int group_num; // the random input groups'num
    char *path;
    Format_input(char *p, int g);
    void read_format_txt();
    void creat_input(char *p);
};