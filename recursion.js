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


// Given grid of positive numbers, start 0,0 and end at n,n . move only  to right and sown -  find path with sum of numbers is maximum.
/*

15
24
// 1 + 5 = 6

542
678
189
//5+6+7+8+9
*/
let grid = [[5,4,2],
            [6,7,8],
            [1,8,9]];
function maxPath(x,y){
    const n = 3 ; 
    
    let d= 0, r = 0;
    //calculate d
    if(y+1 < n) 
       d = maxPath(x,y+1);
    //calculate r
    if(x+1 < n) 
        r = maxPath(x+1,y);

    return grid[x][y] + Math.max(d , r) ;     

}

// console.log(maxPath(0,0))

// maze , you have grid of .,x,d,s where you can walk on  . and not x , find the minimum .s to reach d  and you starting from s
// use backtracking and not revisit visited cell for a single path
var maze = [
    ['.','.','X','.','.'],
    ['.','.','.','.','.'],
    ['.','.','.','.','.'],
    ['.','.','.','.','.'],
    ['.','.','.','D','.']
]
const n2 = 5 ;
function findeMazeD(x,y){

    if( x >= n2 || x < 0 || y >= n2 || y < 0 || maze[x][y] === 'X'|| maze[x][y] === 'V') return 10000000 ;
    if(maze[x][y]==='D') {
        return 1 ;
    } 
    if(maze[x][y]=='.'){
        maze[x][y]='V';
    }
    let resultD = (findeMazeD(x,y+1)) + 1 ; // down
    let resultU = (findeMazeD(x,y-1)) + 1 ; // up
    let resultL = (findeMazeD(x-1,y)) + 1 ; // left
    let resultR = (findeMazeD(x+1,y)) + 1 ; // right
    
    if(maze[x][y]=='V'){
        maze[x][y]='.';
    }
    return Math.min(resultD ,resultU ,resultL ,resultR ); 
}

console.log(findeMazeD(0,1))



