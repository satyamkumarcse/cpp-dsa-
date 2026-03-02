// basic concepts 

/*
accessing a string literal (char) : t.c & s.c is o(1)
substring : o(k) is t.c and s.c
concatenation : o(n+m) , n & m are their length
*/

/*

stoi()   → string → int
stol()   → string → long
stoll()  → string → long long
stoul()  → string → unsigned long
stoull() → string → unsigned long long

to_string() → any number → string

*/


// string to int boilerplate 

// string x = "45";
// int y = 0;

// for(int i = 0; i < x.size(); i++){
//     y = 10*y + (x[i] - '0');
// }


// int to string boilerplate 



// int y = 6709;
// string result = "";

// while(y>0){
//     int z = y%10;
//     result+=z+'0';
//     y/=10;
// }
// reverse(result.begin(),result.end());
// 




// substring function 
string s = "abcdef";

string x = s.substr(2, 3);

// output: x = "cde"



// If length exceeds limit
string s = "abcdef";

string x = s.substr(3, 100);
// "def"
// It safely takes until end.

// t.c = o(k) : k is length of substring 
// k = length of substring

// Reason:
// substr creates a new string
// copies each character (operation peformed k times)


/*Space Complexity (S.C.)
O(k)

because a new string of size k is created.
It does NOT modify original string.*/














// remove outermost parenthesis 


// eg
// (()())(())
// (()()) : (()) 

// a partition is made
// then remove outermost : we get answer as -> ()()()


// create counter variable c1 
// whenever there is a opening bracket c1++
// whenever there is a closing bracket c1--
// c1 becomes 0 at a point
// so that becomes a seprate component



//  (()())(())

// 1 2 3 2 1 0   1 2 1 0

// optimal solution

class Solution {
public:
    string removeOuterParentheses(string s) {

        string temp="";
        int count=0;

        for(int i=0;i<s.length();i++){

            if(s[i]=='('){
                count++;
            }
            if(s[i]==')'){
                count--;
            }

            if(count==1 && s[i]=='('){
                continue;
                
            }

            if(count!=0){
                temp+=s[i];
            }

        }

        return temp;

    }

};







// reverse words of a string 

// better solution 
// a string can be reverse using a stack 
// or by create stemp = "" and then reverse for loop stemp+=s[i];


// Whenever skipping spaces in string parsing, always use:

// while(i<n && s[i]==' ')

// brute solution



class Solution {
public:
    string reverseWords(string s) {

        vector<string> s1;
        string word="";

        int n = s.size();
        int i=0;

        while(i<n){

            while(i<n && s[i]==' '){
                i++;
            }

            if(i>=n){break;}

            while(i<n && s[i]!=' '){
                word+=s[i++];
            }
            s1.push_back(word);
             word="";
            
        }

        reverse(s1.begin(),s1.end());

        string result="";

        for(int j=0;j<s1.size();j++){
            result+=s1[j];
            if(j!=s1.size()-1){result+=" ";}


        }

        return result;

    }

};

// t.c = o(n)
// s.c = o(n)



// brute force solution 

class Solution {
public:
    string reverseWords(string s) {

        int n = s.size();
        int i = n-1;

        string result = "";
        string fresult="";

        while(i>=0){

            while(i>=0 && s[i]==' '){
                i--;
            }

            if(i<0){
                break;
            }

            while(i>=0 && s[i]!=' '){
                result+=s[i--];
            }

         
            int l=0;
            int h=result.size()-1;

            while(l<h){
                  swap(result[l],result[h]);
                l++;
                h--;

            }
            
            fresult+=result;
            fresult+=" ";
            result="";
        
        }

        string ffresult="";

        for(int i=0;i<fresult.size()-1;i++){

            ffresult+=fresult[i];
        }

        return ffresult;
        
    }
};


// optimal solution

class Solution {
public:
    string reverseWords(string s) {

        reverse(s.begin(),s.end());

        int n = s.length();
        string result = "";
        string finalresult ="";
        int i = 0;

        while(i<n){

            while(i<n && s[i]==' '){
                i++;
            }
            if(i>=n){break;}

            while(i<n && s[i]!=' '){
                result+=s[i++];
            }
            reverse(result.begin(),result.end());
            if(!finalresult.empty()){
                finalresult+=' ';
            }
            finalresult+=result;
            result="";


        }

        return finalresult;

    }
             
};



// isomorphic strings 

// brute force approach 
// add , egg 
// add => agg => add....
// this approach create a lot of string thus not memory efficient




// optimal approach 
// hashmap can be used to check if you have encountered a character before 
// hashmap works in o(1) t.c to check if your character exist in some sample space 
// instead of forming new string, just make entires in the hashmap 

// eg- library 
//     privacy 

/*
Hash map 

l -> p
i -> r
b -> i
r -> v
a -> a

now.. r has to be mapped with c, but r has already been mapped with 'v'
so we cant overwrite the value of r once again (this is the point where we will stop and say that these 2 strings are not isomorphic) because we have already replaced the value of r once, we cant replace it twice

edge case - b a d c 
            k i k p 

b -> k 
a -> i 
d -> k 
c -> p

we have to not only check for the keys, but for the values as well
k cant be mapped twice
*/


/*
ISOMORPHIC STRINGS EXPLANATION (LC 205) - USING PLAIN ARRAY LOGIC

---

## CORE IDEA

Two strings are isomorphic if:

1. Each character in s maps to exactly one character in t
2. No two different characters in s map to the same character in t

This is called a ONE TO ONE mapping.

Example VALID:
s = "egg"
t = "add"

e -> a
g -> d

Example INVALID:
s = "foo"
t = "bar"

o maps to a and later tries to map to r (not allowed)

---

## WHY ARRAY OF SIZE 256

Each character has an ASCII value between 0 and 255.

Example:
'a' = 97
'b' = 98
'x' = 120

So we use array index directly using ASCII value.

Example:
mapST['a'] means mapST[97]

---

## WHAT THESE TWO ARRAYS DO

int mapST[256];   // maps character from s to t
int mapTS[256];   // maps character from t to s

Initialize all values to -1

-1 means NO mapping exists yet

Example after mapping a -> x

mapST[97] = 120
mapTS[120] = 97

---

## SUCCESS CASE STEP BY STEP

Example:
s = "egg"
t = "add"

ASCII values:
e = 101
g = 103
a = 97
d = 100

Initially:
mapST = -1 everywhere
mapTS = -1 everywhere

STEP 1:
i = 0
c1 = 'e' = 101
c2 = 'a' = 97

mapST[101] == -1
mapTS[97] == -1

Create mapping:
mapST[101] = 97
mapTS[97] = 101

Meaning:
e -> a

STEP 2:
i = 1
c1 = 'g' = 103
c2 = 'd' = 100

mapST[103] == -1
mapTS[100] == -1

Create mapping:
mapST[103] = 100
mapTS[100] = 103

Meaning:
g -> d

STEP 3:
i = 2
c1 = 'g' = 103
c2 = 'd' = 100

mapST[103] != -1
mapTS[100] != -1

Check consistency:
mapST[103] == 100 correct
mapTS[100] == 103 correct

Continue

Result: TRUE

---

## FAIL CASE 1

Example:
s = "foo"
t = "bar"

ASCII:
f = 102
o = 111
b = 98
a = 97
r = 114

STEP 1:
f -> b
mapST[102] = 98
mapTS[98] = 102

STEP 2:
o -> a
mapST[111] = 97
mapTS[97] = 111

STEP 3:
o -> r

Check:
mapST[111] already = 97
but new is 114

Mismatch

Return FALSE

Reason:
o cannot map to two different characters

---

## FAIL CASE 2

Example:
s = "ab"
t = "aa"

STEP 1:
a -> a
mapST[97] = 97
mapTS[97] = 97

STEP 2:
b -> a

Check:
mapTS[97] already used

Return FALSE

Reason:
two characters cannot map to same character

---

## CORE RULES

Rule 1:
One character maps to only one character

Rule 2:
One character cannot be mapped from two characters

---

## HOW CHAR IS STORED IN INT ARRAY

char automatically converts to ASCII integer

Example:
mapST['a'] = 'x'

Actually stores:
mapST[97] = 120

---

## FINAL SIMPLE CODE USING ARRAY
*/
bool isIsomorphic(string s, string t) {


if (s.length() != t.length()) {
    return false;
}

int mapST[256];
int mapTS[256];

for (int i = 0; i < 256; i++) {
    mapST[i] = -1;
    mapTS[i] = -1;
}

for (int i = 0; i < s.length(); i++) {

    int c1 = s[i];
    int c2 = t[i];

    if (mapST[c1] == -1 && mapTS[c2] == -1) {

        mapST[c1] = c2;
        mapTS[c2] = c1;
    }
    else {

        if (mapST[c1] != c2 || mapTS[c2] != c1) {
            return false;
        }
    }
}

return true;


}
/*
---

## TIME AND SPACE

Time Complexity: O(n)
Space Complexity: O(1)

---

## FINAL UNDERSTANDING

These arrays act like lookup tables.

Index = ASCII value of character
Value = ASCII value of mapped character

This ensures perfect one to one mapping.
*/

/*
ADS
EGG

assume:
A-1
E-3
D-4
G-5
S-7



1-3
3-1

4-5
5-4

7-5
5-7 (CANT BE DONE) SO RETURN FALSE


*/









// 796 - rotate string 

// better solution 

class Solution {
public:
    bool rotateString(string s, string goal) {

        if(s.length()!=goal.length()){
            return false;
        }

        int x = s.length();
        string temp = s;     // temp string stores a copy of s : o(n) is space complexity 
    
        for(int i=0;i<s.length();i++){                  // o(n)

            reverse(temp.begin(), temp.begin() + i);     // o(i)
            reverse(temp.begin() + i, temp.end());       // o(n-i)
            reverse(temp.begin(), temp.end());      //    o(n)


            if(temp==goal){
                return true;
            }
            temp=s;
            

        }

        return false;
   
    }
};

// t.c = o(n^2)
// s.c = o(n)


// /If goal is a rotation of s, then goal must be a substring of s + s.



// another brute force solution 



class Solution {
public:
    bool rotateString(string s, string goal) {

        if(s.length()!=goal.length()){
            return false;
        }

    string sub = s+s;
    int j=0;

    for(int i=0;i<s.length();i++){

        if(goal == sub.substr(j,goal.length())){
            return true;
        }
        j++;

    }

    return false;
        
    }
};

// Each substr() call creates a new string, which is why it's O(n) per iteration , and in total o(n^2)




// optimal solution 
// The find() function in C++ is used to search for a substring or character inside a string.
// string.find(what_to_find, start_position)


string s = "hello world";

int pos = s.find("world");

cout << pos;

/*Output: 
6
Because "world" starts at index 6.*/


Example 3. When substring is not found
string s = "hello";

int pos = s.find("abc");

cout << pos;


// Output:
// 18446744073709551615

// This is called string::npos.
// It means NOT FOUND.



// optimal solution 

class Solution {
public:
    bool rotateString(string s, string goal) {

        if(s.length()!=goal.length()){
            return false;
        }

    string sub = s+s;

    if(sub.find(goal)!=string::npos){
        return true;
    }
    
   

    return false;
        
    }
};



