//  when we write return statement inside a function, the function gets terminated at that point, no lines are executed after that. all the function calls which were done previously are executed.
// after the base case, the function calls start to come out of the stack (LIFO) and are completed
// thus, no stack overflow is there.

// the functions that are yet to be completed are stored in stack space 
#include <bits/stdc++.h>
 using namespace std;
 


void printnum(int count){

    if(count==3){
        return;
    }

    cout<<count<<endl;
    count++;
    printnum(count);

}

 int main(){
    int count=0;

    printnum(count);


    return 0;
}