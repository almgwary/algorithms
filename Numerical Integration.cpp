 /**
 * Problem     : Numerical Integration
 * Author      : Almgwary
 * Date        : 26-Mar-2016
 * Thin        : --M
 **/

#include <bits/stdc++.h>
using namespace std;
/**
 * family of algorithms to calculate the numerical value of defined integral
 * lesson link: https://www.youtube.com/watch?v=fatX6i5JYM4
 *              https://raw.githubusercontent.com/mostafa-saad/ArabicCompetitiveProgramming/master/04%20Math/18_Numerical_Integration.pdf
 */

double f(double x){
    return x*x;
 //return exp(-x*x);
}

/**
Q-  why (w over 2) ?
A-  The brute force one? draw the computed area
	e.g. assume x1 = 0 and x2 = 6 and w = 2
	you will notice we added extra area at w=0 and w=6﻿
 */

double brute_force_inegration(double x1,double x2){
    double area=0;
    double width=(x2-x1)/1000000;
    for(double xi=x1+width/2; xi<=x2-width/2 ; xi+= width){
            //cout<<xi<<endl;
        area += width * f(xi);
    }

    return area ;
}



double simpson_f(double a, double b){
    return (f(a) + 4*f((a+b)/2) + f(b)) * (b-a)/6;
}

double adabtiv_simpson_integration (double a, double b){
    double midPoint =  (a+b)/2;
    double  left_simpson    = simpson_f(a,midPoint),
            right_simpson   = simpson_f(midPoint,b),
            all = simpson_f(a,b);

            if(fabs(left_simpson+right_simpson-all)<1e-12)  // 1e-12 accuracy
                return all;

            return adabtiv_simpson_integration(a,midPoint) + adabtiv_simpson_integration(midPoint,b);

}


 int main(int argc, char* argv[])
 {

    double x1=0,x2=10;
    cout<<brute_force_inegration(x1,x2)<<endl;
    cout<<adabtiv_simpson_integration(x1,x2)<<endl;
    return 0;
  }
