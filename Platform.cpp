#include "Platform.h"

Platform::Platform(int testcases)
{
    testcase_num = testcases;
    FILE *I, *E;
    E = fopen("output/equal.csv", "w");
    I = fopen("output/inequal.csv", "w");
    fprintf(E, "%s %s\n","file1","file2");
    fprintf(I, "%s %s\n", "file1","file2");
    fclose(E);
    fclose(I);
}

void Platform::Run()
{
    GetFileNames("/home/os/SoftEngineer/lab/input", foldname);
    for (int i = 0; i < foldname.size();i++)
    //for (int i = 0; i < 1;i++)
    {
        filename.clear();
        GetFileNames(foldname[i], filename);
        //cout << filename.size() << endl;
        for (int j = 0; j < filename.size(); j++)
        {
            string s = filename[j];
            int len = s.size();
            string tail = s.substr(len - 10, 10);
            if (tail == "format.txt")
            {
                // phase 1: creat input file
                inputname.clear();
                string I = foldname[i] + "/input1.txt";
                for (int k = 1; k < testcase_num + 1; k++) // how many gourps of testcase
                {
                    I.replace(I.size() - 5, 1, to_string(k));
                    //cout << I << endl;
                    Format_input *f = new Format_input(filename[j]);
                    f->read_format_txt();
                    f->creat_input(I.data());
                    inputname.push_back(I);
                    delete f;
                }
            }
            else if (tail.substr(tail.size() - 3,3) == "cpp")
            {
                //creat executable file
                Compile(filename[j]);
            }
        }
        // output.txt initial
        outputname.clear();
        for (int l = 0; l < ename.size(); l++) 
        {
            // creat output.txt
            string o = ename[l];
            o = o + ".txt";
            outputname.push_back(o);
            FILE *O;
            O = fopen(o.data(), "w");
            fclose(O);
        }
        // OJ pair initial
        pair.clear();
        for (int a = 0; a < outputname.size(); a++)
        {
            for (int b = a + 1; b < outputname.size();b++)
            {
                OJ_pair p;
                p.o1 = outputname[a];
                p.o2 = outputname[b];
                p.equal = true;
                pair.push_back(p);
            }
        }
        for (int m = 0; m < testcase_num; m++) // how many gourps of testcase
        {
            // phase 2: execute OJ program
            //cout << "executable file num:" << ename.size() << endl;
            for (int n = 0; n < ename.size(); n++)
            {
                run_OJ *r = new run_OJ(ename[n], inputname[m], outputname[n]);
                r->creat_output();
                delete r;
                //cout << n << " ";
            }
            //phase 3: judge whether equal
            int count = 0;
            //cout << "output.txt file num:" << outputname.size() << endl;
            for (int a = 0; a < outputname.size(); a++)
            {
                for (int b = a + 1; b < outputname.size();b++)
                {
                    equal_Judge *e = new equal_Judge(outputname[a],outputname[b]);
                    //cout << e->is_equal();
                    pair[count].equal = pair[count].equal && e->is_equal();
                    count++;
                    delete e;
                }
            }
        }
        //write to the csv file
        int count = 0;
        for (int a = 0; a < outputname.size(); a++)
        {
            for (int b = a + 1; b < outputname.size();b++)
            {
                write_csv(outputname[a], outputname[b], pair[count].equal);
                count++;
            }
        }

    }
}

void Platform::write_csv(string &c1, string &c2,bool e)
{
    c1 = c1.replace(c1.size() - 3, 3, "cpp");
    c2 = c2.replace(c2.size() - 3, 3, "cpp");
    FILE *E, *I;
    E = fopen("output/equal.csv", "a+");
    I = fopen("output/inequal.csv", "a+");
    if (e)
    {
        fprintf(E, "%s %s\n", c1.data(), c2.data());
    }
    else
    {
        fprintf(I, "%s %s\n", c1.data(),c2.data());
    }
    fclose(E);
    fclose(I);
}

void Platform::Compile(string &path)
{
    string o,f;
    o = path;
    int len = (path).length();
    o[len - 3] = 'o';
    o.erase(o.end() - 2, o.end());
    string cmd = "g++ -c -o " + o + " " + path;
    char *c;
    c = cmd.data();
    system(c);
    f = o;
    f.erase(f.end() - 2, f.end());
    string cmd2 = "g++ -o " + f + " " + o + " -g";
    c = cmd2.data();
    system(c);
    ename.push_back(f);
}


void Platform::GetFileNames(string path,vector<string>& filenames)
{
    DIR *pDir;
    struct dirent* ptr;
    if(!(pDir = opendir(path.c_str())))
        return;
    while((ptr = readdir(pDir))!=0) {
        if (strcmp(ptr->d_name, ".") != 0 && strcmp(ptr->d_name, "..") != 0)
            filenames.push_back(path + "/" + ptr->d_name);
    }
    closedir(pDir);
}

