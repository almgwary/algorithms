/********************************************
*   18-May-2015
*   almgwary
*********************************************/


#include <bits/stdc++.h>
using namespace std;

string arr [4] = {"0","1","2"};

vector <string> creatSerial(int num , int limit)
{
    if(num ==  1 )                          // end of recurion creat vector for evry number
    {
        vector <string> v (limit+1);
        for(int i = 0 ; i  <= limit ; ++i)
            v[i] =  arr [i] ;
        return v;
    }

    long long int totalNum = pow(limit+1 ,num ) ;//calcuat total size
    vector<string> serials (totalNum) ;
    vector <string> nextPart = creatSerial (num-1 ,limit) ; //get next part from recurion
    int siz =  nextPart.size();

    //add all part to each number
    limit = 0 ;
    for(long long int i = 0  ; i < totalNum ; i )
    {
        for(long long int j = 0 ; j<siz ; ++ j)
        {
            serials[i]= arr[limit]  + nextPart[j];
            i++;
        }
        limit++;
    }
    return  serials ;
}


int main()
{
    //freopen("in.txt", "rt", stdin);
	freopen("out2.txt", "wt", stdout);

    int length ;
    cin>>length;
    // 2 is the base start from zero its value exist in arr
    for(string s :  creatSerial (length , 2))
    {
        cout<<s<<endl;
    }
    return 0;
}
