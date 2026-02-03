#include <iostream>
#include <vector>
// using namespace std;



// bubble sort 

/*
void bubblesort(std::vector<int> &vec1,int x){

    for(int i=0;i<=x;i++){
        bool swapped = true;
        for(int j=0;j<x-i;j++){
            if(vec1[j]>vec1[j+1]){
                swapped = false;

                int temp = vec1[j+1];
                vec1[j+1]=vec1[j];
                vec1[j]=temp;
            }
        }
        if(swapped){
            break;
        }
    }



}

int main(){

    std::vector<int> vec1 ={7, 3, 12, 1, 9, 5, 15, 2, 8, 6};
    int x = vec1.size()-1;
    bubblesort(vec1,x);
    for(auto ele : vec1){

        std::cout<<ele<<" ";
    }
    
    return 0;
}

*/






// selection sort

/*
void selectionsort(std::vector<int> &vec1,int x){
    int i,j,min;
    
    

    for(i=0;i<x;i++){
        min = i;

        for(j=i+1;j<x;j++){

            if(vec1[min]>vec1[j]){

                min = j;

            }
        }

        int temp = vec1[min];
        vec1[min]=vec1[i];
        vec1[i] = temp;

        
    }


}


int main(){


    std::vector<int> vec1={7, 3, 12, 1, 9, 5, 15, 2, 8, 6};
    int x = vec1.size();
    selectionsort(vec1,x);
    for(auto ele : vec1){

        std::cout<<ele<<" ";

    }

    return 0;
}
*/





// insertion sort 

/*
void insertionsort( std::vector<int> &vec1,int x){
    int i,j;


    for(i=0;i<x;i++){
        j=i;

        while(j>0 && vec1[j-1]>vec1[j]){

            int temp = vec1[j];
            vec1[j]=vec1[j-1];
            vec1[j-1]=temp;
            j--;

        }

    }


    
}

int main(){


    std::vector<int> vec1={7, 3, 12, 1, 9, 5, 15, 2, 8, 6};
    int x = vec1.size();
    insertionsort(vec1,x);
    for(auto ele : vec1){

        std::cout<<ele<<" ";

    }

    return 0;
}
*/

void merge(std::vector<int> &vec1,int l,int mid,int u){
    std::vector<int> vec2;

    int m = l;
    int n = mid+1;
    


    while(m<=mid && n<=u){

        if(vec1[m]>vec1[n]){
            vec2.push_back(vec1[n]);
            n++;

        }
        else{
            vec2.push_back(vec1[m]);
            m++;


        }

    }

    while(m<=mid){
        vec2.push_back(vec1[m]);
        m++;
    }

    while(n<=u){
        vec2.push_back(vec1[n]);
        n++;
    }

    

    for(int i=l;i<=u;i++){
        vec1[i]=vec2[i-l];
    }


}


void divide(std::vector<int> &vec1,int l,int u){

    int mid = l + (u-l)/2;

    if(l>=u){
        return;
    }

    divide(vec1,l,mid);
    divide(vec1,mid+1,u);
    merge(vec1,l,mid,u);
}




int main(){


    std::vector<int> vec1={7, 3, 12, 1, 9, 5, 15, 2, 8, 6};
    int x = vec1.size();
    int l = 0;
    int u = x-1;
    divide(vec1,l,u);
    for(auto ele : vec1){

        std::cout<<ele<<" ";

    }

    return 0;
}





