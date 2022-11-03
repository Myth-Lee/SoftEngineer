#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <iostream>
#include <sys/types.h>
#include <dirent.h>
#include <vector>
#include "creat_input.h"
#include "run_OJ.h"
#include "equal_judge.h"

struct OJ_pair
{
    string o1, o2;
    bool equal;
};

using namespace std;
class Platform
{
public:
    vector<string> foldname;
    vector<string> filename;
    vector<string> ename;
    vector<string> inputname;
    vector<string> outputname;
    vector<OJ_pair> pair;
    int testcase_num;
    Platform(int testcases);
    void Run();
    void Compile(string &path);
    void write_csv(string &c1, string &c2,bool e);
    void GetFileNames(string path, vector<string> &filenames);
};