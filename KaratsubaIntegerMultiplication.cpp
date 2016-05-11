//============================================================================
// Name        : KaratsubaIntegerMultiplication.cpp
// Author      : Almgwary
// Date        : 21-May-2015
//============================================================================

#include <bits/stdc++.h>

using namespace std;


unsigned _power( unsigned val, unsigned _pow=0 ) {
	if ( _pow <= 0 )
		return 1;
	return val * _power( val, _pow-1 );
}


unsigned KaratsubaIntegerMultiplication (unsigned x , unsigned y , unsigned N ){
    if(N < 2) {

        return x*y ;
    }
    unsigned tenPowerN = _power(10,N)  , tenPowerN2  =   _power(10,N/2) ;
    unsigned a = x/tenPowerN2 , b = x%tenPowerN2 ,
        c = y/tenPowerN2 , d = y%tenPowerN2 ;
    unsigned ac = KaratsubaIntegerMultiplication(a ,c , N/2) ,
                  bd = KaratsubaIntegerMultiplication(b ,d , N/2) ,
                  abPcd = KaratsubaIntegerMultiplication(a+b , c+d , N/2 );
    unsigned adPbc = abPcd - ac - bd ;
    return tenPowerN*ac + tenPowerN2*adPbc + bd ;


}
int main()
{
   cout << KaratsubaIntegerMultiplication(5678 ,1234 , 4) << endl;
    return 0;
}
