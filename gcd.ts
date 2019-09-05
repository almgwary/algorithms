// How to find GCD of two numbers?
const gcd = (a, b) => {
   console.log({a,b});
   if (b == 0)
       return a;
   //  This means b <= a
   return gcd(b, a % b);
}
console.log('result:', gcd(24, 18) );

/**
{a: 24, b: 18}
{a: 18, b: 6}
{a: 6, b: 0}
result:6
**/

// How to find GCD of a list of numbers?
let list = [4, 6, 14, 10];
let list_gcd = (arr) => {
 let result = arr[0];
 for(let i = 1 ; i < arr.length ; i++){
    result = gcd(result, arr[i]);
 }
 return result ; 
}

console.log(list_gcd(list));

/**
{a: 4, b: 6}
{a: 6, b: 4}
{a: 4, b: 2}
{a: 2, b: 0}
{a: 2, b: 14}
{a: 14, b: 2}
{a: 2, b: 0}
{a: 2, b: 10}
{a: 10, b: 2}
{a: 2, b: 0}
2
**/
console.log(list_gcd([21, 42, 9]));

/**
{a: 21, b: 42}
{a: 42, b: 21}
{a: 21, b: 0}
{a: 21, b: 9}
{a: 9, b: 3}
{a: 3, b: 0}
3
**/
