#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>
#include <string.h>

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
    string path;
    Format_input(string &p);
    void read_format_txt();
    void add_input(char s[],int count);
    void creat_input(char *p);
};