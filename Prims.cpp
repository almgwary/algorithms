//============================================================================
// Name        : prim Numbers
// Author      : Almgwary
//============================================================================
#include <bits/stdc++.h>
using namespace std;

int numOfPrims=1;
vector <int>prims(100000000,-1);
void testAndAdd(int number)
{
    int sqRoot = sqrt(number);
    bool isPrim=true;
    for(int i=0;prims[i]<= sqRoot &&i<numOfPrims;++i){
        if(number%prims[i]==0)
        {
            isPrim=false;
            break;
        }
    }
    if(isPrim)prims[numOfPrims++]=number;
}
int main()
{
    prims[0]=2;
    for(int i=2;i<100000000;++i){
        testAndAdd(i);
        cout << prims[numOfPrims-1] << endl;
    }
        cout << prims[numOfPrims-1] << endl;


    return 0;
}
