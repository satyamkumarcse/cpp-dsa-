// revise - second smallest ele in array 

/*
#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int main(){


    vector<int> vec={13,34,23,56,43,56,78,76,11,22,12};

    int smallest = vec[0];
    int ssmallest = INT_MAX;

    for(int i=1;i<vec.size();i++){

        if(vec[i]<smallest){
            ssmallest = smallest;
            smallest = vec[i];
        }
        else if(vec[i]>smallest && vec[i]<ssmallest){
            ssmallest = vec[i];

        }

    }

    cout<<ssmallest;




    return 0;
}
*/


#include <iostream>
#include <vector>
#include <climits>

using namespace std;



// int main(){

//     vector<int> vec1 = {1,1,2,3};
//     vector<int> vec2 = {2,3,4,4};

//     vector<int> result;

//     int i = 0;
//     int j = 0;
//     int x = vec1.size();
//     int y = vec2.size();


//     while(i<x && j<y){

//         if(vec1[i]<vec2[j]){
//             if(result.size()==0 || result.back()!=vec1[i]){
//                 result.push_back(vec1[i]);
//             }
//             i++;
        
//         }
//         else{
//             if(result.size()==0 || result.back()!=vec2[j]){
//                 result.push_back(vec2[j]);
//             }
//             j++;
//         }
        
       
        

//     }

//     while(i<x){
//           if(vec1[i]<vec2[j]){
//             if(result.size()==0 || result.back()!=vec1[i]){
//                 result.push_back(vec1[i]);
//             }
//             i++;
//     }

//     while(i<y){
//          if(result.size()==0 || result.back()!=vec2[j]){
//                 result.push_back(vec2[j]);
//             }
//             j++;
//         }
        

//     }

//     for(auto ele : result){
//         cout<<ele<<" ";
//     }

//     return 0; 

// }




// int main(){

//     vector<int> vec1={1,2,2,3,3,4,5,6};
//     vector<int> vec2={2,3,3,5,6,6,7};
//     vector<int> result;


//     int i = 0;
//     int j = 0;

//     int n1 = vec1.size();
//     int n2 = vec2.size();


//     while(i<n1 && j<n2){

//         if(vec1[i]<vec2[j]){
//             i++;
//         }
//         else if(vec1[i]>vec2[j]){
//             j++;

//         }
//         else{

//             if(result.size()==0 || result.back()!=vec1[i]){
                
//             result.push_back(vec1[i]);
        


//     }
//     i++;
//     j++;

// }

// }

//     for(auto ele : result){
//         cout<<ele<<" ";
//     }
    
//     return 0;
// }



