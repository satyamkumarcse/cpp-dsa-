#include <iostream>
using namespace std;

int main(){

      string s = "gdufuffsyfsthedgg";
      int x = 'a';

      bool detect[26]= {false};
      int arr[26]={0};

      for(int i=0;i<s.length();i++){
        arr[s[i]-x]+=1;
      }

      for(int i=0;i<s.length();i++){
        if(detect[s[i]-x]){
            continue;
        }
        else{
            cout<<"frequency of "<<s[i]<<" is "<<arr[s[i]-x]<<endl;
            detect[s[i]-x]=true;
            
        }
      }


    return 0;
}