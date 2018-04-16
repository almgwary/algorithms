// recursion

// a function is said to be a recursive if it calls itself.

// the following function should print statment n times recursivly 
function sayIamRecursive(n) {

    // Base case
    if (n < 1) return;
    // logic
    console.log("I am recursive");
    // sub problem - never go to infinity
    sayIamRecursive(--n);
}
// sayIamRecursive(3)

// calculate factorial
function factorial(n) {
    if (n <= 1) return 1;
    return n * factorial(n - 1);
}
//factorial(3)


function printLine(n) {
    var s = '';
    if (n < 1) {
        s += "\n"; return s;
    };
    return s += "*" + printLine(n - 1)
}
function triangle(n) {
    if (n < 1) return;
    triangle(n - 1)
    console.log(printLine(n));
}
// triangle(10)


// 4n+1 Series Next(N) if n is odd then n = 3 * n +1 . if n is even then n = n/2. if n==1, stop
// E.g. 22 11 34 17 52 26 13 40 20 10 5 16 8 4 2 1
// Given n, find length of 3n+1 sequence, E.g. F3_1(22) = 16 ;

function f3_1(n) {
    //   console.log(n)
    if (n <= 1) return 1;
    if (n % 2 === 0) return 1 + f3_1(n / 2);
    else return 1 + f3_1(3 * n + 1);
}

// console.log( f3_1(22))

// recusive integer
function recusivNumber(n) {
    console.log(n)
    if (n <= 0) return '';
    return (n % 10) + recusivNumber(Math.floor(n / 10));



}

//console.log(recusivNumber(12345678900))
