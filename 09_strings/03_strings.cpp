// 1614. Maximum Nesting Depth of the Parentheses

// optimal solution 

class Solution {
public:
    int maxDepth(string s) {

        int x = s.size();
        int count=0;
        int temp=0;
    
        for(auto c: s){
            

            if(c=='('){count++;}
            else if(c==')'){count--;}
            else{continue;}

            temp = max(temp,count);
        }

        return temp;
        
    }
};


/*

Function	Checks
isdigit(ch)	only digits
isalpha(ch)	only letters
isalnum(ch)	letters or digits
islower(ch)	lowercase
isupper(ch)	uppercase
tolower(ch)	convert to lowercase
toupper(ch)	convert to uppercase

*/



// 8. string to int 




// wrong approach & solution
class Solution {
public:
    int myAtoi(string s) {

        int x = s.size();
        string result="";

        for(int i=0;i<x;i++){
            if(s[i]==' '){continue;}
            if(s[i]=='+' || s[i]=='-'){
                if(result==""){result+=s[i];}
                else{break;}
            }
            if(s[i]=='0' && result.size()==0){continue;}
            if(s[i]>='0' && s[i]<='9'){result+=s[i];}
            if(!isdigit(s[i])){break;}
        }

        int y = stoi(result);

        return y;
        
    }
};


// stoi(result) : cant process "+" or "-"
// im skipping all while spaces instead of leading

// input : 12 34 
// should result is 12 , but my code would give 1234 



/* Leading zero logic is incorrect

Your code:

if(s[i]=='0' && result.size()==0){continue;}


Problem:
Fails when sign exists.
Example:

"-012"
result = "-"
result.size() != 0
so zero is added correctly, but logic is fragile and unnecessary.
Leading zeros should be handled naturally.*/


// the answer should come as 0, if nothing is added 


/*Mistake 4: stoi(result) can crash

Your code:

int y = stoi(result);
This crashes if:

Example 1:

Input: "abc"
result = ""
stoi("") → crash


Example 2:

Input: "+"
result = "+"
stoi("+") → crash


Example 3:

Input: "-"
stoi("-") → crash

You must check before calling stoi.*/



// i forget to write code for rounding of INT_MAX OR INT_MIN CASES










// optimal solution 


/*Correct approach structure

Proper order must be:

Skip leading spaces
Handle sign
Read digits
Handle overflow
Return result*/

class Solution {
public:
    int myAtoi(string s) {

        int i = 0;
        int n = s.size();

        // skip leading spaces
        while(i < n && s[i] == ' ') {
            i++;
        }

        // sign
        int sign = 1;
        if(i < n && (s[i] == '+' || s[i] == '-')) {
            if(s[i] == '-') sign = -1;
            i++;
        }

        long result = 0;

        // digits
        while(i < n && isdigit(s[i])) {

            result = result * 10 + (s[i] - '0');

            // overflow check
            if(sign * result >= INT_MAX)
                return INT_MAX;

            if(sign * result <= INT_MIN)
                return INT_MIN;

            i++;
        }

        return sign * result;
    }
};



// lower bound implementation code

#include <iostream>
#include <vector>
using namespace std;


int main(){
    // vector<int> nums={1,2,3,3,7,8,9,9,9,11};
    vector<int> nums={1,2,3,3,5,8,8,9,10,10,11};
    int target = 9;

    int low=0;
    int high=nums.size()-1;
    int m=0;

    if(target>nums[high]){cout<<"lower bound dont exist";}
    
    while(low<=high){
         m=low+(high-low)/2;

        
        if(nums[m]>=target){

            high=m-1;

        }
        else{

            low=m+1;
        }

    }

    cout<<low;


}
