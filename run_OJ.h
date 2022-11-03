#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>
#include <string.h>

using namespace std;

class run_OJ
{
public:
    string e_path, i_path, o_path; //exectuable file,input file,output file
    run_OJ(string &e_p, string &i_p, string &o_p);
    void creat_output();
};