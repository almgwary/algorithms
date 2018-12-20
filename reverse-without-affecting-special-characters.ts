/**
 * Reverse an array without affecting special characters
 * Given a string, that contains special character together with alphabets (‘a’ to ‘z’ and ‘A’ to ‘Z’), reverse the string in a way that special characters are not affected.
 * 
 * Examples:
 * 
 * Input:   str = "a,b$c"
 * Output:  str = "c,b$a"
 * Note that $ and , are not moved anywhere.  
 * Only subsequence "abc" is reversed
 * 
 * Input:   str = "Ab,c,de!$"
 * Output:  str = "ed,c,bA!$"
 */

let text = "ab$ck#m", s ="\"!#$%&'()*+,-./:;<=>?@[\]^_`{|}~";
let isS = (str)=>{
  return s.indexOf(str)>-1;
},
swp = (first, last)=>{
     text = text.substr(0, first)
           + text[last]
           + text.substring(first+1, last)
           + text[first]
           + text.substr(last+1);
  console.log(first, last,text+"" )
  return text+"";
},
len = text.length, lg=0, rg=text.length - 1, steps = 0;
 

while(lg<rg){
  ++steps;
  if(isS(text[rg]))--rg;
  else if(isS(text[lg]))++lg; 
  else{
    // swap
    swp(lg,rg);
    --rg;
    ++lg;
  }
}
    
console.log("steps:"+steps);
console.log("text:"+text);
