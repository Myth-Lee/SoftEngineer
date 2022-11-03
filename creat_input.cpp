#include "creat_input.h"

Format_input::Format_input(string &p)
{
    path = p;
}

void Format_input::read_format_txt()
{
    FILE *I;
    I = fopen(path.data(), "r");
    int count = 1;
    char s[30];
    char c[2]; 
    int len = 0;
    while (fgets(c, 2, I) != NULL)
    {
        if (c[0] != ' ' && c[0] != '\n') 
        {
            s[len] = c[0];
            len++;
            continue;
        }
        s[len] = '\0';
        len = 0;
        add_input(s, count);
        if (c[0] == '\n')
            count++;
    }
    add_input(s, count);
    fclose(I);
}

void Format_input::add_input(char s[],int count)
{
    Type T;
    if (s[0] == 'i')
    {
        T.kind = 0;
        string num1, num2;
        int pos = 0;
        for (int i = 4; i < strlen(s);i++) if (s[i]==',')
                pos = i;
        for (int i = 4; i < strlen(s) - 1; i++)
        {
            if (i < pos)
            {
                num1 += s[i];
            }
            else if (i > pos)
            {
                num2 += s[i];
            }
        }
        T.a = stoi(num1);
        T.b = stoi(num2);
    }
    else if (s[0] == 'c') T.kind = 1;
    else
    {
        T.kind = 2;
        string num1, num2;
        int pos = 0;
        for (int i = 7; i < strlen(s);i++) if (s[i]==',')
                pos = i;
        for (int i = 7; i < strlen(s) - 1; i++)
        {
            if (i < pos)
            {
                num1 += s[i];
            }
            else if (i > pos)
            {
                num2 += s[i];
            }
        }
        T.a = stoi(num1);
        T.b = stoi(num2);
    }
    T.line = count;
    input.push_back(T);
}

void Format_input::creat_input(char *p)
{
    FILE *O;
    O = fopen(p, "w");
    int count = 1;
    for (int i = 0; i < input.size(); i++)
    {
        if (input[i].line!=count)
        {
            count++;
            fprintf(O, "\n");
        }
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
                int r1 = 'a' + rand() % 26; int r2 = 'A' + rand() % 26; int r3 = rand() % 2;
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
                char s[100];
                int len = rand() % input[i].b + input[i].a;
                //cout << len << endl;
                for (int i = 0; i < len; i++)
                {
                    int r1 = 'a' + rand() % 26; int r2 = 'A' + rand() % 26; int r3 = rand() % 2;
                    char c;
                    if (r3 == 0) c =(char)r1;
                    else c =(char)r2;
                    s[i] = c;
                }
                s[len] = '\0';
                fprintf(O, "%s ", s);
                break;
            }
            default:
                break;
        }
    }
    fclose(O);
}
