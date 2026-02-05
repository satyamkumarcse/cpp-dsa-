/*

void as a function return type: void main(){}

When a function returns void, it does not return any value.
meaning: The function performs an action but does not return anything to the caller.


format specifiers:


%d - int 
%f - float 
%c - string
%s - char 
%p - pointer


output:

printf("%d", c);     // if im printing a value, its format specifiers has to be written

Output function
Prints the value of variable c to the screen (after reading it)



input:

scanf("%d", &c);

Input function

&c = memory location of variable c
scanf needs the address because it writes new data into the variable

Without &, the program does not know where to store the input
Reads an integer from the user and stores it in variable c.



*/




// #include <stdio.h>
// #include <math.h>


// 1) program to add 2 numbers

// void main(){
//     printf("hello world\n");

//     int a=2,b=3,c;
//     c=a+b;
//     printf("%d",c);
// }




// 2) program to swap values present in 2 variables "a" and "b"

// void main(){

//     int a,b,t=0;
//     scanf("%d",&a);
//     scanf("%d",&b);
    
//     t=a;
//     a=b;
//     b=t;
//     // printf("%d\n",a);
//     // printf("%d",b);
//     // we can also combine 2 print statements
//     // printf("%d\n%d",a,b);



// }



// 3) calculate area of a circle


// void main(){

   
//     float area,r,pi=3.14;
//     scanf("%f",&r);

//     area = pi*r*r;


//     printf("%f",area);

    


// }



//  4) program to calculate simple intrest. 

// void main(){

//     float p,r,t,ans,s=100;
//     scanf("%f",&p);
//     scanf("%f",&r);
//     scanf("%f",&t);
//     ans = (p*r*t)/s;

//     printf("%f",ans);


// }


//    5) program to take input of student's id,name,branch. marks in 5 subjects. and calculate total and avg marks.



// #include <stdio.h>
// #include <string.h>

// int main(){
//     char name[30];   // this declares an array, which can take 30 character input. 
//     int id;           
//     char branch[5];
//     int s1,s2,s3,s4,s5;
    
//     float sum;
//     float avg;



//     printf("----------------- Grade calculator -----------------\n");
//     printf("enter your name :");
//     scanf("%s",name);               // dont use ampersand (&) in case of char.
//     printf("enter you collage id : ");
//     scanf("%d",&id);
//     printf("enter branch name: ");
//     scanf("%s",branch);
//     printf("enter marks of 5 subjects");
//     scanf("%d %d %d %d %d",&s1,&s2,&s3,&s4,&s5);     // we dont use \n in scanf.
//     sum = s1+s2+s3+s4+s5;
//     avg = sum/5;
//     printf("total marks scored out of 500 is :%f\n",sum);
//     printf("avg marks scored is : %f\n",avg);


// }

// for taking input with more than 1 character ie- string, we use char name[10];

//  to get length of a string 
// strlen(str)


//  to store string inputs 
// char str[20];


// int to string
// sprintf(str,"%d",x);    (destination,format,value) 


// string to int 
// atoi(str)


// ascii value of '0' is 48.  


// #include <stdio.h>
// #include <stdbool.h>

// int main() {
//     int x;
//     scanf("%d", &x);

//     if (x % 2 == 0) {
//         int sum = 0;
//         int temp = x;

//         while (temp > 0) {
//             sum += temp % 10;
//             temp /= 10;
//         }

//         printf("Sum of digits: %d", sum);
//     }
//     else {
//         char result[20];
//         int count = 0;
//         int temp = x;

//         while (temp > 0) {
//             result[count] = (temp % 10) + '0';
//             count++;
//             temp /= 10;
//         }

//         result[count] = '\0';

//         printf("Reversed number: %s", result);
//     }

//     return 0;
// }






// switch case program 

// You are using GCC

// #include <stdio.h>

// int main(){
    
//     int mode=0;
//     float intensity=0;
    
//     scanf("%d",&mode);
//     scanf("%f",&intensity);
    
//     switch(mode){
        
//         case 1: printf("Intensity: %.2f",intensity*1.5);
//         break;
    
    
        
//         case 2: printf("Intensity: %.2f",intensity*2);
//         break;
    
    
        
//         case 3: printf("Intensity: %.2f",intensity*1.8);
//         break;
        
//         default: printf("Invalid");
//     }
    
    
    
//     return 0;
// }




// for n=5

//     1
//    232
//   34543
//  4567654
// 567898765





// #include <stdio.h>
// int main(){
//     int n;
//     scanf("%d",&n);
    
//     for(int i=1;i<=n;i++){
//         for(int s=1;s<=n-i;s++){
//             printf(" ");
//         }
        
        
//         for(int j=i;j<=2*i-1;j++){
//             printf("%d",j);
//         }
        
//         for(int j=2*i-2;j>=i;j--){
            
//             printf("%d",j);
//         }
//         printf("\n");
//     }
//     return 0;
// }




// #include <stdio.h>
// int main(){
//     int upper,lower,target,j,k,i;
//     int count=0;
    
//     scanf("%d %d %d",&upper,&lower,&target);
//     for(i=upper;i<=lower;i++){
        
//         k=i;
//         while(k>0){
            
//             j = k%10;
//             if(j>target){
//                 count++;
//             }
//             k/=10;
//         }
        
        
        
//         }
        
//         printf("%d",count);
        
    
    
    
//     return 0;
// }



// switch case 


// You are using GCC


// #include <stdio.h>
// int main(){
    
//     char choice;
//     float time,size,flying,distance;
    
//     scanf("%c",&choice);
    
//     switch(choice){
        
//         case 'd': 
//         scanf("%f",&time);
//         printf("Distance: %.2f m",343*time);
        
//         break;
        
//         case 'D': 
//         scanf("%f",&time);
//         printf("Distance: %.2f m",343*time);
        
//         break;
        
//         case 'b': 
//         scanf("%f",&size);
//         printf("Weight: %.2f lb",5*size);
//         break;
        
//         case 'B': 
//         scanf("%f",&size);
//         printf("Weight: %.2f lb",5*size);
//         break;
        
//         case 'f':
//         scanf("%f",&flying);
//         scanf("%f",&distance);
//         printf("Altitude: %.2f m",flying*distance);
//         break;
        
//         case 'F':
//         scanf("%f",&flying);
//         scanf("%f",&distance);
//         printf("Altitude: %.2f m",flying*distance);
//         break;
        
//         default:
//         printf("Invalid");
//         break;
        
        
        
//     }
// }



// //  Whenever %c is the first input, always use " %c"
// // %d %f these automatically ignore whitespaces, this " " is not required to give.



// #include <stdio.h>

// int main(){
//     char a,b;
//     int c;
//     int j,k;
//     int i=0;
//     scanf("%c",&a);   
//     scanf(" %c",&b);   // " %c" instead of "%c" in order to ignore the \n present in the buffer. 
//     scanf("%d",&c);
   

//         do{if(i%2==0){
//             for(j=0;j<=i;j++){
//             printf("%c",a);
//         }
            
//         }
//         else if(i%2!=0){
//             for(k=0;k<=i;k++){
//             printf("%c",b);
        
//     }
    
            
//         }
             
            
//     printf(" ");
//             i++;
            
            
//         }while(i<c);
    
    
  
    
//     return 0;
    
    
// }





// #include <stdio.h>
// int main(){
//     int code;
//     scanf("%d",&code);
//     float factor;
//     scanf("%f",&factor);
    
//     switch(code){
//         case 1: if(factor<50.0){
//             printf("Priority: High");}
//             else{
//                 printf("Priority: Low");
//             }
//             break;
//         case 2: if(factor>80.0){
//             printf("Priority: High");}
//             else{
//                 printf("Priority: Low");
//             }
//             break;
//         case 3: if(factor>80.0){
//             printf("Priority: High");}
//             else{
//                 printf("Priority: Low");
//             }
//             break;
//      default: printf("Invalid");
        
//     }
    
    
    
    
//     return 0;
// }


// Runtime initialization of arrays in C

// #include <stdio.h>

// int main(){

    // int i;
    // int sub[6];

    // for(i=0;i<6;i++){
    //     printf("enter the ele : sub[%d] ", i);
    //     scanf("%d", &sub[i]);

    // }
    // printf("\nthe entered elements are: ");

    // for(int j=0;j<5;j++){
    //     printf("%d ",sub[j]);
        
    // }


    // int sub[10],i,n,total=0;
    // float average;

    // printf("enter the number of subject : ");
    // scanf("%d",&n);


    // for(i=0;i<n;i++){

    //     printf("enter marks for sub[%d] ",i+1);
    //     scanf("%d",&sub[i]);
    //     total+=sub[i];

    // }
    // printf("marks of each subject: ");

    // for(i=0;i<n;i++){
    //     printf("%d ", sub[i]);
        
    // }

    // average = total/n;


    // printf("\naverage is: %f ",average);






// #include <stdio.h>
// int main()
// {
//     int i, s[4][2];

//     for(i=0;i<=3;i++)
//     {
//         printf("Enter roll no. and marks: ");
//         scanf("%d %d", &s[i][0], &s[i][1]);
//     }

//     for(i=0;i<=3;i++)
//         printf("\n The entered value %d %d", s[i][0], s[i][1]);

//     return 0;
// }







// #include <stdio.h>

// int main(){
    
//     int x;
//     scanf("%d",&x);
    
//     int arr[x];
    
//     for(int i=0;i<x;i++){
    
//             scanf("%d",&arr[i]);
        
        
//     }
    
//     for(int i=0;i<sizeof(arr)/sizeof(arr[0]);i++){
//         if(i!=2){
//             printf("%d ",arr[i]);
            
//         }
        
//     }
    
    
    
//     return 0;
// }





//  program to merge two sorted arrays into a single sorted array. 






// #include <stdio.h>
// #include <stdbool.h>
          
// int main(){
    
//     int x,y;
//     scanf("%d",&x);
//     int arr1[x];
//     for(int i=0;i<x;i++){
//         scanf("%d",&arr1[i]);
//     }
//     scanf("%d",&y);
//     int arr2[y];
//     for(int i=0;i<y;i++){
//         scanf("%d",&arr2[i]);
//     }
    
//     int arr3[x+y];
//      for(int i=0;i<x;i++){
//         arr3[i]=arr1[i];
//     }
    
//      for(int i=x;i<x+y;i++){
//         arr3[i]=arr2[i-x];
//     }
    

// }

  


    
    // int i,j,swapped;
    
    // for( i=0;i<x+y-1;i++){
    //     bool swapped = false;
    
    // for(j=0;j<x+y-1-i;j++){
    //     if(arr3[j]>arr3[j+1]){
            
    //         int temp = arr3[j];
    //         arr3[j]=arr3[j+1];
    //         arr3[j+1] = temp;
    //         swapped = true;
    //     }
    // }
    // }
    
    
   
    
    
//     for(int i=0;i<x+y;i++){
//         printf("%d ",arr3[i]);
//     }
    
    
    

//     return 0;
// }







// and an integer M and rotates the array to the right by M

// #include <stdio.h>
// int main(){
    
//     int x,y,i;
//     scanf("%d",&x);
//     int arr[x];
    
//     for(i=0;i<x;i++){
//         scanf("%d",&arr[i]);
//     }
    
//     scanf("%d",&y);
    
//     int arr1[x];
    
//     for(i=0;i<x;i++){
//         if(i<y){
//             arr1[i]=arr[x-y+i];
            
//         }
//         else{
//             arr1[i]=arr[i-y];
            
//         }
        
        
//     }
    
//      for(i=0;i<x;i++){
//         printf("%d ",arr1[i]);
//     }
    
// }






// #include <stdio.h>
// #define size 10

// int main(){

//     int arr[size]={12,45,74,24,57,68,77,89,65,33};

//     int max = 99999;

//     for(int i=0;i<size;i++){

//         if(arr[i]<max){
//             max = arr[i];
//         }
//     }

//     printf("the element that is minimum is: %d",max);



// }



// #include <stdio.h>
// #define m 10
// #define n 15

// int main(){

//     int m1[m][n];
//     int m2[m][n];
//     int m3[m][n];

//     for(int i=0;i<m;i++){
//         for(int j=0;j<n;j++){

//             scanf("%d",&m1[i][j]);       // done add whitespace "%d " in scanf 
//         }
//     }


//     for(int i=0;i<m;i++){
//         for(int j=0;j<n;j++){

//             scanf(" %d",&m2[i][j]);
//         }
//     }


//     for(int i=0;i<m;i++){
//         for(int j=0;j<n;j++){

//             m3[i][j] = m1[i][j] + m2[i][j];
//         }
//     }

//     for(int i=0;i<m;i++){
//         for(int j=0;j<n;j++){

//             printf("%d ",m3[i][j]);
//         }
//         printf("\n");
//     }




//     return 0;
// }


// #include <stdio.h>

// int main() {
//     char name[100], x;
//     int ch = 0;

//     printf("Enter a line: ");

//     do {
//         x = getchar();
//         name[ch] = x;
//         ch++;
//     } while (x != '\n');

//     ch -= 1;              // remove newline
//     name[ch] = '\0';     // string terminator

//     printf("You entered: %s", name);

//     return 0;
// }



/*
getchar() reads on character at a time from input
This program reads a full line of text character by character using getchar and stores it in a character array. A loop repeatedly calls getchar, saves the returned character into the array at the current index, and increments the index counter until the newline character '\n' is encountered, which happens when the user presses Enter. At this point, the array contains all typed characters plus the newline. Since a valid C string must end with the null character '\0' and not with '\n', the index is reduced by one to move back to the position where the newline was stored, and that position is replaced with '\0'. This effectively removes the newline and correctly terminates the string, making the stored input a proper C string that can be printed or processed further. 
*/




// #include <stdio.h>
// #include <string.h>

// int main(){

//     char s1[10] = "satyam";
//     char s2[10] = "manishhhh";

//     strcpy(s1,s2);    // copy content of s2 to s1   (destination,source)

//     printf("%s\n",s1);
//     printf("%s\n",s2);

//     printf("%d",strlen(s1));    // returns length of string
//     printf("\n");
//     printf("%d\n",strlen(s2));


//     // strcmp() , compares 2 strings and return 0 if they are identical, non zero otherwise  

//     if(strcmp(s1,s2)==0){
//         printf("strings are identical\n");  
//     }
//     else{
//         printf("strings are not identical\n");
//     }


//     // strcat() , joins or concatenates two strings together
    
//      char s11[10] = "satyam ";
//     char s22[10] = "kumar";

//     strcat(s11,s22);    // string s22 is appended at the end of s11

//       printf("%s\n",s11);


//     return 0;
// }


// #include <stdio.h>
// #include <string.h>

// int main() {
//     char str[100], rev[100];
//     int len, i;

//     printf("Enter a string: ");
//     scanf("%s", str);

//     len = strlen(str);

//     for(i = 0; i < len; i++) {
//         rev[i] = str[len - i - 1];
//     }
//     rev[len] = '\0'; 

//     if(strcmp(str, rev) == 0)
//         printf("Palindrome"); 
//     else
//         printf("Not Palindrome");

//     return 0;
// }




// reads a string containing any character (short code);
/*
char line[81];

scanf("%[^\n]",line);

*/




// count number of occurences of upper case letter in 1 line of sentence.

// #include <stdio.h>
// #include <string.h>
// #include <ctype.h>

// int main(){

//     char intro[100];
//     int count=0;
//     int s,i;

//     scanf("%[^\n]",intro);

//      s = strlen(intro);

//     for(i=0;i<s;i++){
//         if(isupper(intro[i])){
//             count++;
//         }
//     }

//     printf("the count is %d",count);


//     return 0;
// }


//  in entire text para 

// EOF is an integer constant, usually -1.   (ie- till,  end of file)
// #include <stdio.h>
// #include <string.h>
// #include <ctype.h>

// int main(){

//     char intro[100];
//     int count=0,l=0;
//     int s,i,k;

//     while((k=getchar()) != '@'){     // @ or EOF  
//         intro[l]=k;
//         l++;
//     }
    
    
//     intro[l]='\0';

//      s = strlen(intro);

//     for(i=0;i<s;i++){
//         if(isupper(intro[i])){
//             count++;
//         }
//     }

//     printf("the count is %d",count);


//     return 0;
// }




/*


do {
   // block scope
   int k = getchar();
} while (k != EOF);
       // ^ this condition is outside the block scope



*/


// pascals trianlge code

/*#include <stdio.h>
int main(){
    
    int rows;
    printf("enter rows:");
    scanf("%d",&rows);
    int i=0;
    
   
    
    while(i<rows){
         int spaces = rows-i-1;
         while(spaces--){
             printf(" ");
             
             
         }
         
         int num = 1;
         int c=0;
         
         while(c<=i){
             printf("%d ",num);
             num = num*(i-c)/(c+1);
             c++;
             
         }
         
         printf("\n");
         i++;
         
        
    }
    
    i = rows - 2;
      
    while(i>=0){
        int spaces = rows - i - 1;
        
        while(spaces>0){
            printf(" ");
            spaces--;
            
        }
        
        
        
        
         int num = 1;
         int c=0;
         
         while(c<=i){
             printf("%d ",num);
             num = num*(i-c)/(c+1);
             c++;
             
         }
         
         printf("\n");
         i--;
        
        
    }

    return 0;
}
*/

// magic square verification program 

/*
#include <stdio.h>

#define MAX 10

int checkMagic(int a[MAX][MAX], int n);

int main() {
    int n, a[MAX][MAX];
    printf("Enter order of square matrix: ");
    scanf("%d", &n);

    printf("Enter matrix elements:\n");
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    if(checkMagic(a, n))
        printf("Magic Square\n");
    else
        printf("Not a Magic Square\n");

    return 0;
}

int checkMagic(int a[MAX][MAX], int n) {
    int sum = 0;

    // Sum of first row as reference
    for(int j = 0; j < n; j++)
        sum += a[0][j];

    // Check all rows
    for(int i = 1; i < n; i++) {
        int rowSum = 0;
        for(int j = 0; j < n; j++)
            rowSum += a[i][j];

        if(rowSum != sum)
            return 0;
    }

    // Check all columns
    for(int j = 0; j < n; j++) {
        int colSum = 0;
        for(int i = 0; i < n; i++)
            colSum += a[i][j];

        if(colSum != sum)
            return 0;
    }

    // Check main diagonal
    int diag1 = 0;
    for(int i = 0; i < n; i++)
        diag1 += a[i][i];

    if(diag1 != sum)
        return 0;

    // Check secondary diagonal
    int diag2 = 0;
    for(int i = 0; i < n; i++)
        diag2 += a[i][n - i - 1];

    if(diag2 != sum)
        return 0;

    return 1;
}
*/



// find a word is present in string of array and return its place 


/*
You are storing multiple strings.
In C, a string itself is a 1D array of characters.
So when you store many strings, you need an array of strings. That becomes a 2D char array.


Expression	  Meaning	     Type
arr	       all strings 	      2D
arr[i]	    one string	      1D
arr[i][j]	one character	char


0 - false 
1 - true 
*/


/*
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(){

    int num;
    scanf("%d",&num);
    char arr[num][101];    // for storing multiple string, 2d array of char 

    for(int i=0;i<num;i++){
        scanf("%s",arr[i]);
    }

    char target[101];
    int found=0;

    scanf("%s",target);

    for(int i=0;i<num;i++){
        if(strcmp(arr[i],target)==0){
            printf("Found in row: %d",i+1);
            found=1;
            break;

        }
    }

    if(!found){
        printf("Not found");
    }

    return 0;
}
*/


/*
#include <stdio.h>
int main(){

    int matrix[3][3];

    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            scanf("%d",&matrix[i][j]);
        }
    }

    for(int i=0;i<3;i++){
        int sum=0;
        for(int j=0;j<3;j++){
            sum+=matrix[i][j];
        }
        printf("Sum of row %d: %d\n",i,sum);
    }

    return 0;
}
    */




/*   
#include <stdio.h>

int main(){

    int num;
    scanf("%d",&num);
    int arr1[num][num];

     for(int i=0;i<num;i++){
        for(int j=0;j<num;j++){
            scanf("%d",&arr1[i][j]);
        }
    }

     for(int i=0;i<num;i++){
        for(int j=0;j<num;j++){
            if(j>i){
                arr1[i][j]=0;
            }
        }
    }

     for(int i=0;i<num;i++){
        for(int j=0;j<num;j++){
            printf("%d ",arr1[i][j]);
           
        }
        printf("\n");
    }
    return 0;
}
*/



/*
#include <stdio.h>
#include <stdbool.h>

int main(){

    int num;
    scanf("%d",&num);
    int m1[num][num];

    for(int i=0;i<num;i++){
        for(int j=0;j<num;j++){
            scanf("%d",&m1[i][j]);
        }
    }
    printf("Original matrix:\n");


    for(int i=0;i<num;i++){
        for(int j=0;j<num;j++){
            printf("%d ",m1[i][j]);
        }
        printf("\n");
    }

    int t1[num][num];

    for(int i=0;i<num;i++){
        for(int j=0;j<num;j++){
            t1[j][i]=m1[i][j];
        }
    }
    printf("Transpose matrix:\n");


    for(int i=0;i<num;i++){
        for(int j=0;j<num;j++){
            printf("%d ",t1[i][j]);
            
        }
        printf("\n");
    }

    bool symmetric = true;

     for(int i=0;i<num;i++){
        for(int j=0;j<num;j++){
            if(m1[i][j]!=t1[i][j]){
                symmetric = false;
                break;
            }
        }
    }

    if(symmetric){
        printf("Matrix is Symmetric!");
    }
    else{
        printf("Matrix is not Symmetric!");

    }
    return 0;

}
*/



// code for setting all elements of row and colume to 0.

// #include <stdio.h>

// int main() {
//     int r, c;
//     scanf("%d %d", &r, &c);

//     int a[r][c];

//     for(int i = 0; i < r; i++){
//         for(int j = 0; j < c; j++){
//             scanf("%d", &a[i][j]);
//         }
//     }

//     int row[r], col[c];

//     for(int i = 0; i < r; i++)
//         row[i] = 0;

//     for(int j = 0; j < c; j++)
//         col[j] = 0;

//     // Step 1: mark rows and columns that contain zero
//     for(int i = 0; i < r; i++){
//         for(int j = 0; j < c; j++){
//             if(a[i][j] == 0){
//                 row[i] = 1;
//                 col[j] = 1;
//             }
//         }
//     }

//     // Step 2: set elements to zero based on marks 
//     for(int i = 0; i < r; i++){
//         for(int j = 0; j < c; j++){ 
//             if(row[i] == 1 || col[j] == 1){  
//                 a[i][j] = 0;
//             }
//         }
//     }

//     // Print result
//     for(int i = 0; i < r; i++){
//         for(int j = 0; j < c; j++){
//             printf("%d ", a[i][j]);
//         }
//         printf("\n");
//     }

//     return 0;
// }



// code for not printing a selected row and colume 

// #include <stdio.h>

// int main() {
//     int T;              // T here is number of test cases 
//     scanf("%d", &T);

//     while(T--) {
//         int R, C;
//         scanf("%d %d", &R, &C);

//         int a[R][C];

//         for(int i = 0; i < R; i++){
//             for(int j = 0; j < C; j++){
//                 scanf("%d", &a[i][j]);
//             }
//         }

//         int ri, ci;
//         scanf("%d %d", &ri, &ci);   // already 0-based

//         for(int i = 0; i < R; i++){
//             if(i == ri) continue;

//             for(int j = 0; j < C; j++){
//                 if(j == ci) continue;

//                 printf("%d ", a[i][j]);
//             }
//             printf("\n");
//         }
//     }

//     return 0;
// }


// code for printing sum of quanrdrants in a matrix of n x n order, n is even 




/*
#include <stdio.h>

int main() {
    int T;
    scanf("%d", &T);

    while(T--) {
        int N;
        scanf("%d", &N);

        int a[N][N];

        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                scanf("%d", &a[i][j]);
            }
        }

        int mid = N / 2; 

        int tl = 0, tr = 0, bl = 0, br = 0;

        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){

                if(i < mid && j < mid)
                    tl += a[i][j];
                else if(i < mid && j >= mid)
                    tr += a[i][j];
                else if(i >= mid && j < mid)
                    bl += a[i][j];
                else
                    br += a[i][j];
            }
        }

        printf("%d %d %d %d\n", tl, tr, bl, br);
    }

    return 0;
}
*/



/*in numericals of functions that have header snippet and fill code section, we are only required to fill the function prototype the int main(){return 0;} we dont have to write.*/

// neon number detector 



// int neon(int n) {

//     int square = n * n;
//     int sum = 0;

//     while (square > 0) {
//         sum += square % 10;
//         square /= 10;
//     }

//     return (sum == n);
// }




// fibonacci number 

// return last digit of fibbonaci(x) using recursion or iteration


/**/

// #include <stdio.h>

// int fibolastdigit(int num){

//     if(num==1 || num==2){
//         return 1;
//     }
// // recursion
//     // return fibolastdigit(num-1)+fibolastdigit(num-2);

// // iteration
//     int a=1;
//     int b=1;
//     int c;    

//     /*
//     eg-
//     F(7) = 13
//     F(8) = 21
//     F(9) = 34
//     F(7)%10 = 3
//     F(8)%10 = 1
//     F(9)%10= 4
//     we only care about storing last digit, cause thats asked, storing actual number not possible exceeds range of int.
//     */
//     for(int i=2;i<num;i++){
//         c = (a+b)%10;
//         a = b;
//         b = c;

        
//     }

//     return c;

// }


// int main(){

//     int x = 13;

//     int y = fibolastdigit(x);

    

//     printf("%d",y);
// }





// #include <stdio.h>
// #include <stdbool.h>

// bool isDuckNumber(char s[]) {

//     // Rule 1: must not start with 0
//     if(s[0] == '0')
//         return false;

//     // Rule 2: must contain at least one 0
//     for(int i = 1; s[i] != '\0'; i++){
//         if(s[i] == '0')
//             return true;
//     }

//     return false;
// }

// int main(){

//     char num[50];
//     scanf("%s", num);

//     if(isDuckNumber(num)){
//         printf("%s is a duck number", num);
//     }
//     else{
//         printf("%s is not a duck number", num);
//     }

//     return 0;
// }

// // is even and is multiple of 10 program

// #include <stdio.h>

// void iseven(int x){
//     if(x % 2 == 0)
//         printf("Even\n");
//     else
//         printf("Not even");
// }

// void ismultiple(int x){
//     if(x % 10 == 0)
//         printf("Multiple of 10");
//     else
//         printf("Not a multiple of 10");
// }

// int main(){

//     int x;
//     scanf("%d", &x);

//     iseven(x);

//     if(x % 2 == 0){
//         ismultiple(x);
//     }

//     return 0;
// }


// 5,76 yes, 13 no, automorphic test


// #include <stdio.h>

// int isAutomorphic(int x){

//     int temp = x*x;

    
//     int power = 1;
//     int num = x;

//     while(num>0){
//         num/=10;
//         power*=10;
        
//     }

//     if(temp%power==x){
//         return 1;
//     }
//     else{
//         return 0;
//     }
// }



// int main(){

//     int x;
//     scanf("%d",&x);

//     if(isAutomorphic(x)){
//         printf("yes");
//     }
//     else{
//         printf("no");
//     }

//     return 0;
// }






/*
Yes. Correct.

* `strlen(s)` → returns length of string (excluding `'\0'`)
* `strcpy(dest, src)` → copies `src` into `dest`
* `strcmp(a, b)` → compares two strings

  * returns `0` if equal
  * negative if `a < b`
  * positive if `a > b`
* `strcat(dest, src)` → appends `src` to end of `dest`

All are in:

```c
#include <string.h>
```

*/







// string concatenation without library 


// #include <stdio.h>

// int main() {
//     char a[50] = "Hello ";
//     char b[] = "World";

//     int i = 0;
//     int j = 0;

//     while(a[i] != '\0') {
//         i++;
//     }

//     while(b[j] != '\0') {
//         a[i] = b[j];
//         i++;
//         j++;
//     }

//     a[i] = '\0';

//     printf("%s", a);
//     return 0;
// }




// consonants,vowel,digits,speacial character code 





// #include <stdio.h>
// #include <ctype.h>

// int main() {
//     char s[151];

//     int vowels = 0;
//     int consonants = 0;
//     int digits = 0;
//     int special = 0;

//     scanf("%[^\n]", s);

//     int i = 0;

//     while(s[i] != '\0') {

//         char ch = tolower(s[i]);

//         if( (ch >= 'a' && ch <= 'z') ) {

//             if( ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u') {
//                 vowels++;
//             }
//             else {
//                 consonants++;
//             }
//         }
//         else if(ch >= '0' && ch <= '9') {
//             digits++;
//         }
//         else {
//             special++;
//         }

//         i++;
//     }

//     printf("Vowels: %d\n", vowels);
//     printf("Consonants: %d\n", consonants);
//     printf("Digits: %d\n", digits);
//     printf("Special Characters: %d", special);

//     return 0;
// }





// number to roman conversion 




// #include <stdio.h>

// int main() {

//     int n;
//     scanf("%d", &n);

//     if(n <= 0){
//         printf("Invalid");
//         return 0;
//     }

//     int values[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
//     char *symbols[] = {
//         "M", "CM", "D", "CD",
//         "C", "XC", "L", "XL",
//         "X", "IX", "V", "IV", "I"
//     };

//     for(int i = 0; i < 13; i++){
//         while(n >= values[i]){
//             printf("%s", symbols[i]);
//             n -= values[i];
//         }
//     }

//     return 0;
// }



// 




#include <stdio.h>
#include <string.h>
#include <stdbool.h>


int main(){

    int n;
    int temp =0;
    scanf("%d",&n);

    char arr[10][101];   // 2D of char can store multiple string words

    for(int i=0;i<n;i++){
        scanf("%s",arr[i]);
    }

    char s[101];
    scanf("%s",s);

    bool found = false;

    for(int i=0;i<n;i++){
        if(strcmp(s,arr[i])==0){
            found = true;
            temp =i;
            break;
        }
    }

    if(found){
        printf("Found in row: %d",temp+1);
    }
    else{
        printf("Not found");
    }
}




/*pointers and related concepts*/


#include <stdio.h>

int main() {
    int num[] = {24, 34, 12, 44, 56, 17};
    int *p = num;   // pointer to an arr (num)

    for(int i = 0; i <= 5; i++){
        printf("%d ", *(p + i));
        printf("%p ", (p + i));   // prints memory address
    }

    return 0;
}



*(i + num)  ==  num[i]
i[num]     ==  num[i]
printf("%d %d", num[i], num[i]);


// remainder and quotient using pointers 

#include <stdio.h>

int main() {

    int a, b;
    int quotient, remainder;

    int *pa = &a;
    int *pb = &b;

    scanf("%d %d", pa, pb);

    quotient = (*pa) / (*pb);
    remainder = (*pa) % (*pb);

    printf("%d %d", quotient, remainder);

    return 0;
}



// area of rectangle using pointers 


#include <stdio.h>

int main() {

    int length, breadth;
    int area;

    int *pL = &length;
    int *pB = &breadth;

    scanf("%d %d", pL, pB);

    area = (*pL) * (*pB);

    printf("%d", area);

    return 0;
}

// double -> 8 bytes occupy (use for more precision in decimal)
// float -> 4 bytes 

/*menu driven banking program using pointers arithemetric*/

#include <stdio.h>
#include <stdbool.h>

int main() {

    int balance = 0;
    int choice, amount;

    int *pBalance = &balance;

    while(true) {

        scanf("%d", &choice);

        if(choice == 1) {   // Deposit
            scanf("%d", &amount);
            *pBalance = *pBalance + amount;
            printf("Deposit successful.\n");
        }
        else if(choice == 2) {   // Withdraw
            scanf("%d", &amount);

            if(amount <= *pBalance) {
                *pBalance = *pBalance - amount;
                printf("Withdrawal successful.\n");
            }
            else {
                printf("Insufficient balance.\n");
            }
        }
        else if(choice == 3) {   // Display balance
            printf("Current Balance: %d\n", *pBalance);
        }
        else if(choice == 4) {   // Exit
            printf("Exiting program.");
            break;
        }
        else {   // Invalid choice
            printf("Invalid choice.\n");
        }
    }

    return 0;
}


// population and name of 3 cities, average of population


#include <stdio.h>

int main() {

    char city[3][50];
    int population[3];

    int *pPop = population;
    int total = 0;

    for(int i = 0; i < 3; i++) {
        scanf("%s %d", city[i], (pPop + i));
    }

    for(int i = 0; i < 3; i++) {
        total = total + *(pPop + i);
    }

    double average = total / 3.0;

    printf("%d\n", total);
    printf("%.2lf", average);

    return 0;
}



// two array, transaction and binary bit array, if bit = 1, result = - transaction , otherwise no change 


#include <stdio.h>

void applySign(int *transactions, int *sign, int n) {

    for(int i = 0; i < n; i++) {
        if(*(sign + i) == 1) {
            *(transactions + i) = -(*(transactions + i));
        }
    }
}

int main() {

    int n;
    scanf("%d", &n);

    int transactions[20];
    int sign[20];

    for(int i = 0; i < n; i++) {
        scanf("%d", &transactions[i]);
    }

    for(int i = 0; i < n; i++) {
        scanf("%d", &sign[i]);
    }

    applySign(transactions, sign, n);

    for(int i = 0; i < n; i++) {
        printf("%d ", transactions[i]);
    }

    return 0;
}





/*
Input: 3 
2 3 4 
Output: 12 8 6 
Explanation: 
Total Product = 2 * 3 * 4 = 24
*/

#include <stdio.h>

int main() {

    int n;
    scanf("%d", &n);

    int arr[10];
    int *p = arr;

    for(int i = 0; i < n; i++) {
        scanf("%d", (p + i));
    }

    int prod = 1;

    // calculate total product using pointer arithmetic
    for(int i = 0; i < n; i++) {
        prod *= *(p + i);
    }

    // modify each element
    for(int i = 0; i < n; i++) {
        *(p + i) = prod / *(p + i);
    }

    // print modified array
    for(int i = 0; i < n; i++) {
        printf("%d ", *(p + i));
    }

    return 0;
}






// max difference between any 2 elements of arrays 

#include <stdio.h>

int maxDiff(int *p,int n){
    int max = *p;
    int min = *p;
    
    for(int i=0;i<n;i++){
        if(*(p+i)>max){
            max = *(p+i);
            
        }
        if(*(p+i)<min){
            min = *(p+i);
        }
    }
    
    return max - min;

}


int main(){
    int n;
    scanf("%d",&n);
    
    int arr1[n];
    
    int *p = arr1;
    
    for(int i=0;i<n;i++){
        scanf("%d",(p+i));
    }
    
    int x = maxDiff(p,n);
    
    printf("%d",x);
    
    return 0;
    
}