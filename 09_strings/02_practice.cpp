#include <bits/stdc++.h>
using namespace std;

int main(){

    /*
    
    Q4. Devise a C++ code to count the number of unique words in a given string. The string may contain words with special characters such as `!`, `?`, `.`, `,`, `;`, and `:` and digits are not permitted. Special character must occur only at the end of a word. Count words without special characters. Counting must be case insensitive.

    **Sample Input:**
    "How are you dear? Are you better dear?"

    **Output:**
    'are': 2, 'better': 1, 'dear': 2, 'how': 1, 'you': 2
    */

    string s = "How are you dear? Are you better dear?";

    map<string,int> s1;

        
        string res="";
        int i=0;
    while(i<s.size()){

         while(i<s.size() && s[i]!=' ' && isalpha(s[i])){
            res+=tolower(s[i++]);
        }
        if(res!=""){

        s1[res]++;
        
        }
        res="";

        i++;
       

    }
    // sort(res.begin(),res.end(),[]())
       

    for(auto it : s1){
        cout<<it.first<<": "<<it.second<<endl;
    }

}