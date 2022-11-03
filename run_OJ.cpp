#include "run_OJ.h"

run_OJ::run_OJ(string &e_p, string &i_p, string &o_p)
{
    e_path = e_p;
    i_path = i_p;
    o_path = o_p;
}

void run_OJ::creat_output()
{
    int pos = 0;
    for (int i = e_path.size(); i > 0;i--)
    {
        if (e_path[i] == '/') 
        {
            pos = i;
            break;
        }
    }
    string locate = e_path.substr(0, pos);
    string exec = e_path.substr(pos + 1, e_path.size() - pos);
    //cout << locate << " " << exec << endl;
    string cmd = "cd " + locate + " && " + "./" + exec;
    //cout << cmd << endl;
    freopen(i_path.data(), "r", stdin);    //从input.txt 中读入数据
    freopen(o_path.data(),"w",stdout);  // 将最后数据写入output.txt中
    system(cmd.data());
    freopen("/dev/tty", "r", stdin);
    freopen("/dev/tty", "w", stdout);
}