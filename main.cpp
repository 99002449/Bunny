#include<bits/stdc++.h>
#include "bunny.h"
#include "functions.h"
using namespace std;

//Other functions

int main()
{
    list<bunny> thelist;
    bunny a[5];
    for(int i=0; i<5; i++)
    {
        thelist.push_back(a[i]);
    }
    while(1)
    {
        checkRadioactivity(thelist);
        getchar();
        GenerateNextTurn(thelist);
        delete_extra(thelist);
        getchar();
        breeding(thelist);
    }
    return 0;
}

