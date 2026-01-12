// recursion -> when a function calls itself until a specified condition is met.


/*


f(){

    f()
}


*/


#include <bits/stdc++.h>
 using namespace std;


void printnum(int x){

    cout<<x<<endl;
    printnum(x);

}

 int main(){

    int y = 1;
    printnum(y);


    return 0;
}


// flow of program 

// whenever a program runs, the execution starts from int main(){}
// a user defined function is beign called inside the main function
// when the program reaches the line 30, the function then calls the void function and program reaches there.
// in the void fucntion, there is an act of printing x, so x is shown on the screen and then the recursion act takes place. 
// there is no stop condition mentioned and thus the execution will be done forever (infinite recursion)

// see image 1

// the 1 will technically print for unlimited time, but eventually the system will run out of memory & segmentation fault will be thrown this is called as stack overflow.

// the completion of a function is said to be done after the last line of that fucntion is executed, but in case of recursion, the function call is not completed fully,  at the line 23 , the inner function calls itself again & again.

// the first function call when reaches line 23, makes another call to itself. ie- the first call is not completed. so it waits in the memory 
// this wait is called as stack overflow
// it cant just pile up infinitely.

// stack overflow -> when there is numerous function calls waiting due to recursion or any other reason like declaring lare local arrays , deeply nested function calls. they occupy large space in memory and eventually cause stack overflow








  
