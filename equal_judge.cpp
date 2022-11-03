#include "equal_judge.h"

equal_Judge::equal_Judge(string &o1_p,string &o2_p)
{
    o1_path = o1_p;
    o2_path = o2_p;
}

bool equal_Judge::is_equal()
{
    FILE *O1, *O2;
    O1 = fopen(o1_path.data(), "r");
    O2 = fopen(o2_path.data(), "r");

    bool e = true;

    char s1[100], s2[100];
    //cout << o1_path << " " << o2_path << endl;
    while (!feof(O1) && !feof(O2))
    {
        fscanf(O1, "%s", s1);
        fscanf(O2, "%s", s2);
        //cout << s1 << " " << s2 << endl;
        if (strcmp(s1, s2) != 0)
            e = false;
        
    }

    //if (feof(O1) || feof(O2)) e = false;

    //cout << "result:" << e << endl;
    fclose(O1);
    fclose(O2);

    return e;
    
}