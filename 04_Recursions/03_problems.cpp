// // print name N time using recursion

#include <bits/stdc++.h>
 using namespace std;

//  void printer(string name,int x){
    
//     if(x==0){
//         return ;
//     }
//     else{

//     cout<<name<<endl;
    
//     printer(name,x-1);


//     }
     
//  }

//  int main(){

//     int x;
   

//     cout<<"enter how many times you want to print: ";
//     cin>>x;



//     string name;
//     cout<<"enter the name : ";
//     cin>>name;

//     printer(name,x);



//     return 0;
//  }


//  time complexity -> O(n)  (for n input, function run n times)
// space complexity -> O(n) (before base case, for n-1 input the stack space was piled up (occupied) with n-1 function calls)






// print linearly from 1 to N 




// #include <bits/stdc++.h>

//  using namespace std;

//   void printer(int i,int x){
    
//     if(i>x){
//         return ;
//     }
//     else{
//         cout<<i<<endl;
//     printer(i+1,x);


//     }
    
//  }


//  int main(){


//     int x;

//     cout<<"enter till which number you want to print:  ";
//     cin>>x;


//     printer(1,x);

//     return 0;
//  }





// from N to 1 linearly 




// #include <bits/stdc++.h>

//  using namespace std;

//   void printer(int i,int x){
    
//     if(i<1){
//         return ;
//     }
    
//         // cout<<i<<endl;  // 4 3 2 1
//     printer(i-1,x);
//      cout<<i<<endl;   // 1 2 3 4


//  }


//  int main(){


//     int x;

//     cout<<"enter till which number you want to print:  ";
//     cin>>x;


//     printer(x,x);

//     return 0;
//  }



// back tracking concept 

// the code inside a user defined function, written after recursive call is not executed.
//  In recursion, code before the recursive call runs while going down the calls.
// Code after the recursive call runs while coming back up.

// That single rule explains everything.







 

// print from 1 to N using a temp vble (intuitive)

 




// #include <bits/stdc++.h>

//  using namespace std;

//   void printer(int x,int temp){
    

    
//     if(x==0){
//         return ;
//     }
//     else{

//     cout<<temp-x+1<<endl;
    
//     printer(x-1,temp);


//     }
    
//  }


//  int main(){
    
//     int x;

//     cout<<"enter till which number you want to print:  ";
//     cin>>x;
//     int temp = x;
    
//     printer(x,temp);

//     return 0;
//  }








// alternate code with less parametres 

// #include <bits/stdc++.h>

//  using namespace std;

//   void printer(int x){
    
//     if(x==0){
//         return ;
//     }
//     else{
//         cout<<x<<endl;
//     printer(x-1);


//     }
    
//  }


//  int main(){


//     int x;

//     cout<<"enter till which number you want to print:  ";
//     cin>>x;


//     printer(x);

//     return 0;
//  }





// sum of first N number - parameterised way 



// Parameterized recursion means:
// An extra parameter (accumulator) is passed to the recursive function.
// The accumulator stores the intermediate result.
// The final answer is obtained at the base case, not during return.
// Return values are usually not used to build the result.
// This approach is often used to simulate iteration using recursion




// #include <bits/stdc++.h>
//  using namespace std;

// int sumfind(int x,int sum){

//     if(x==0){
//         return sum;
//     }

//     return sumfind(x-1,sum+x);

//  }


//  int main(){


//     int x;
//     int sum=0;

//     cout<<"enter the number till you want to find sum of:  ";
//     cin>>x;

   

//     int y =  sumfind(x,sum);
//     cout<<y;



//     return 0;
//  }




// sum of n number - fucntional way 

// functional way meaning : 
// No accumulator parameter.
// No printing inside recursion.
// Final answer comes only via return value.





// #include <bits/stdc++.h>
//  using namespace std;

// int sumfind(int x){

//     if(x==0){
//         return 0;
//     }

//     return x + sumfind(x-1);

//  }





//  int main(){


//     int x;
//     int sum=0;

//     cout<<"enter the number till you want to find sum of:  ";
//     cin>>x;


//     int d = sumfind(x);
//     cout<<d;
    

//     return 0;
//  }

















// factorial using recursion 




// #include <bits/stdc++.h>
//  using namespace std;

// int factorial(int x){

//     if(x==0){
//         return 1;
//     }

//     return x*factorial(x-1);

//  }


//  int main(){


//         int x;

//     cout<<"enter the number you want to find factorial of:  ";
//     cin>>x;

   

//     int y =  factorial(x);
//     cout<<y;



//     return 0;
//  }

 
// time & space complexity - O(n);

 

//  KEY RULE TO REMEMBER (VERY IMPORTANT)

// If a function returns a value, you must either:
// store it in a variable, or
// print it directly.
// Calling the function alone is not enough.



// reversing an array using recursion (2 pointer / 2 variable approach)
// this will be done by recursion using two pointers




// void reverse(int arr1[],int a,int b){
//     if(a>b){
//         return;
//     }
   

//     int temp = arr1[a];
//     arr1[a]=arr1[b];
//     arr1[b]=temp;

//     reverse(arr1,a+1,b-1);

    
// }


// int main(){
    

//     int arr1[10]={14,32,67,54,77,56,45,34,88,56};
//     int x = 10;
    

//      reverse(arr1,0,x-1);     // in case of a void function, just call it, dont equate it to int x, etc....

//     for(int i=0;i<x;i++){
//         cout<<arr1[i]<<" ";
//     }

//     return 0;
     
// }


  


// now same question using single variable 





// void reverse(int arr1[],int a,int x){

//     if(a>=x/2){
//         return;

//     }

//     int temp = arr1[a];
//     arr1[a]=arr1[x-a-1];
//     arr1[x-a-1]=temp;
     

//     reverse(arr1,a+1,x); 

    
// }


// int main(){
    
//     int arr1[10]={14,32,67,54,77,56,45,34,88,56};
//     int x=sizeof(arr1)/sizeof(arr1[0]);
    
    
//     reverse(arr1,0,x);    

//     for(int i=0;i<x;i++){ 
//         cout<<arr1[i]<<" ";
//     }

//     return 0;
     
// }


// remember that arrays are passed by refrence



// string is palindrome or not using function recursion
// a string on reversal reads the same 



bool palindromecheck(string word, int i,int x){


    if(i>=x/2){

        return true;
    }

    if(word[i]!=word[x-i-1]){
        return false;
    }
  
    return palindromecheck(word,i+1,x);


} 




int main(){

    string word;
    int i;

    cout<<"enter string word to check palindrome: ";
    cin>>word;


    int x = word.length();

    bool z = palindromecheck(word,0,x);

    cout<<z;
 

}

