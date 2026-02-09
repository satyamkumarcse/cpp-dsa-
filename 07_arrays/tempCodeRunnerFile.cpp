
int main(){

    
    vector<int> vec={1,2,3,1,0,1,1,1,3,3};
    // vector<int> vec={1,0,1,0,1};
    // vector<int> vec={0,0,0};
    int k =6; 
    int x = vec.size();
    int sum=0;
    int j=0;
    int count=0;


    for(int i=0;i<x;i++){
        sum=0;
        for(int j=i;j<x;j++){
            sum+=vec[j];
             if(sum==k){
            count++;
        }


        }

    }

    cout<<count;

    return 0; 

}

