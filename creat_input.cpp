#include "creat_input.h"

Format_input::Format_input(char* p,int g)
{
    path = p;
    group_num = g;
}

void Format_input::read_format_txt()
{
    FILE *I;
    I = fopen(path, "r");
    int count = 1;
    regex reg("[0-9]+");
    smatch num;
    while (!feof(I))
    {
        char*a;
        string s="";
        do
        {
            fgets(a, 1, (FILE *)I);
            s = s + *a;
        } while (*a != ' ' && *a != '\n');
        Type T;
        if (s[0] == 'i')
        {
            T.kind = 0;
            regex_match(s, num, reg);
            T.a = stoi(num[0]);
            T.b = stoi(num[1]);
        }
        else if (s[0] == 'c')
            T.kind = 1;
        else 
        {
            T.kind = 2;
            regex_match(s, num, reg);
            T.a = stoi(num[0]);
            T.b = stoi(num[1]);
        }
        T.line = count;
        input.push_back(T);
        if (*a == '\n')
            count++;
    }
}

void Format_input::creat_input(char *p)
{
    FILE *O;
    O = fopen(p, "w");
    int count = 1;
    for (int i = 0; i < input.size(); i++)
    {
        switch (input[i].kind)
        {
            case 0:
            {
                int r = rand() % input[i].b + input[i].a;
                fprintf(O, "%d ", r);
                break;
            }
            case 1:
            {
                int r1 = rand() % 90 + 65; int r2 = rand() % 122 + 97; int r3 = rand() % 1;
                char c;
                if (r3 == 0)
                    c = r1;
                else
                    c = r2;
                fprintf(O, "%c ", c);
                break;
            }
            case 2:
            {
                string s = "";
                int len = rand() % input[i].b + input[i].a;
                for (int i=0;i<len;i++)
                {
                    int r1 = rand() % 90 + 65; int r2 = rand() % 122 + 97; int r3 = rand() % 1;
                    char c;
                    if (r3 == 0) c = r1;
                    else c = r2;
                    s = s + c;
                }
                fprintf(O, "%s ", s);
                break;
            }
            default:
                break;
        }

        if (input[i].line!=count)
        {
            count++;
            fprintf(O, "\n");
        }
    }
}

int main()
{
    Format_input f("/input/4A/stdin_format.txt",1);
    f.read_format_txt();
    f.creat_input("input.txt");
}