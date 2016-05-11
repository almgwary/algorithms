//============================================================================
// Name        : MergSort.cpp
// Author      : Almgwary
// Date        : 21-May-2015
//============================================================================

#include <bits/stdc++.h>

using namespace std;


vector<int> merge_sort (vector <int> numbers , int length){ //nlog(n)
    if(length == 1) return numbers ;
    vector <int> A (numbers.begin() , numbers.begin()+length/2) ,
                 B  ( numbers.begin()+length/2 , numbers.end()) ;

    vector <int > sorted_A = merge_sort(A , length/2) ,
                  sorted_B = merge_sort(B , (length+1)/2) ;
    vector <int> result (length) ;
    int i_A = 0 , i_B = 0 ;
    for(int i = 0 ; i < length ; ++i ){
        if( i_A <= length/2 && sorted_A[i_A] < sorted_B[i_B]){
            result[i] = sorted_A[i_A];
            ++i_A;
        }else {
        result[i]=sorted_B[i_B];
        ++i_B;
        }
    }
    return result ;

}
int main()
{
    vector <int> v ;
    v.push_back(5);
    v.push_back(6);
    v.push_back(2);
    v.push_back(0);
    v.push_back(8);
    v.push_back(9);

    for(int i : merge_sort(v , 6))
        cout<<i <<" " ;

    return 0;
}
