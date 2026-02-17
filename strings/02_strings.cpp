

// sort characters for frequency 
// brute force 

/*
string a = "hi"
string b = " hello"

a.append(b) : appends a full string "hello"
a.append(b,2,3) : appends substring "ell" 
a.append(3,'x')  : "hixxx"


*/


class Solution {
public:
    string frequencySort(string s) {

        vector<int> vec(256,0);
        string res="";

        for(int i=0;i<s.length();i++){

            vec[s[i]]++;
        }

        while(true){

            int currentchar =0;
            int maxchar = 0;

            for(int i=0;i<256;i++){
           

            if(vec[i]>currentchar){
                currentchar = vec[i];
                maxchar = i;
            }

        }
          res.append(currentchar,maxchar);
        vec[maxchar]=0;

         if(currentchar==0){break;}



        }

      
        return res;

       
    }
};

/*
Final Answer (Interview Format)

Time Complexity: O(N)
Space Complexity: O(1) {auxiliary}

*/

// Time: O(N * 256) approx O(N) but inefficient scanning repeatedly
// Space: O(256) = O(1)
/*why s.c = o(1)

vector<int> freq(256, 0);
This is a fixed size vector. Its size is always 256, regardless of input string length.

Key rule for space complexity
Space complexity counts only extra space that grows with input size.



// concept 

/*
1. Sorting basics
2. Comparators
3. Pair and vector of pairs
4. Why sorting works in this problem
5. Bucket sort concept
6. Why bucket sort is optimal
7. Full connection to LC 451

---

# Part 1: Sorting Basics

Sorting means arranging elements in some order.

Example:

```
[5, 2, 8, 1]
```

Ascending sort:

```
[1, 2, 5, 8]
```

Descending sort:

```
[8, 5, 2, 1]
```

In C++, sorting is done using:

```cpp
sort(start, end);
```

Example:

```cpp
vector<int> v = {5, 2, 8, 1};

sort(v.begin(), v.end());
```

Result:

```
[1, 2, 5, 8]
```

Time complexity:

```
O(N log N)
```

---

# Part 2: Sorting with custom rule (Comparator)

Sometimes default sorting is not enough.

Example:

```
vector<pair<char,int>> v =
{
    {'a', 3},
    {'b', 1},
    {'c', 2}
};
```

We want to sort based on frequency (second value).

Default sort sorts by first element (char), not what we want.

So we use comparator.

---

# Part 3: Comparator concept

Comparator tells sort HOW to compare two elements.

Syntax:

```cpp
sort(begin, end, comparator)
```

Comparator returns true if order is correct.

Example comparator:

```cpp
bool comp(pair<char,int> a, pair<char,int> b)
{
    return a.second > b.second;
}
```

Meaning:

Sort in descending order of frequency.

---

# Part 4: Lambda comparator (modern C++)

Instead of separate function, we write inside sort:

```cpp
sort(vec.begin(), vec.end(),
[](pair<char,int>& a, pair<char,int>& b)
{
    return a.second > b.second;
});
```

Meaning:

Sort based on frequency descending.

---

# Part 5: Why pair is used

We store:

```
character and frequency together
```

Example:

Input:

```
"tree"
```

Frequency:

```
t → 1
r → 1
e → 2
```

Store as:

```
('t',1)
('r',1)
('e',2)
```

Stored in:

```cpp
vector<pair<char,int>>
```
*/


// better solution: 

class Solution {
public:
    string frequencySort(string s) {

        unordered_map<char,int> m1;

        for(auto c : s){
            m1[c]++;
        }

        vector<pair<char,int>> vec1(m1.begin(),m1.end());

        sort(vec1.begin(),vec1.end(),[](pair<char,int> a,pair<char,int>b){return a.second>b.second;});   // o(n) = o(n log n)

        string result = "";

        for(auto it : vec1){

            result.append(it.second,it.first);
        }

        return result;
        
    }
};

/*
unordered_map<char, int> freq; 
Step 2: copying map to vector O(K)
K = unique characters 
worst case K = N


*/
/*Comparison with your frequency array solution


// better solution takes
unordered_map + sort approach:
Time: O(N log N) worst case when N=K , otherwise O(N + NlogK)
Space: O(N)



frequency array approach:
Time: O(N)
Space: O(1)

frequency array is faster when charset is limited (ASCII).*/



/*
---

# Part 6: Better Approach Logic (Sorting method)

Steps:

Step 1: Count frequency

```
unordered_map<char,int> freq;
```

Step 2: Convert map to vector

```
vector<pair<char,int>> vec(freq.begin(), freq.end());
```

Step 3: Sort vector based on frequency

```
sort(vec.begin(), vec.end(), comparator)
```

Step 4: Build result string

```
append characters freq times
```

Example:

```
('e',2)
('t',1)
('r',1)
```

Result:

```
"eetr"
```

Time complexity:

```
O(N log N)
```

---

# Part 7: Why this is not optimal

Sorting takes:

```
O(N log N)
```

We can do better using bucket sort.

---

# Part 8: Bucket Sort Concept

Bucket sort uses frequency index directly.

Key idea:

Frequency range is limited.

Example:

```
string length = 4

max frequency possible = 4
```

So create buckets:

```
bucket[0]
bucket[1]
bucket[2]
bucket[3]
bucket[4]
```

Each bucket stores characters with that frequency.

---

Example:

Input:

```
tree
```

Frequency:

```
t → 1
r → 1
e → 2
```

Buckets:

```
bucket[1] = t, r
bucket[2] = e
```

---

Now traverse from highest to lowest frequency:

```
bucket[4]
bucket[3]
bucket[2] → e
bucket[1] → t, r
```

Result:

```
eetr
```

No sorting needed.

---

# Part 9: Why bucket sort is O(N)

Steps:

Count freq → O(N)
Fill buckets → O(N)
Traverse buckets → O(N)

Total:

```
O(N)
```

Better than sorting.

---

# Part 10: Visual diagram

Input:

```
tree
```

Frequency map:

```
t → 1
r → 1
e → 2
```

Bucket array:

```
index    characters
0
1        t r
2        e
3
4
```

Traverse reverse:

```
2 → e
1 → t r
```

Result:

```
eetr
```

---

# Part 11: Why bucket sort is optimal here

Because:

Frequency range is limited:

```
0 to N
```

We use frequency as index directly.

No comparison sorting needed.

Comparison sorting lower bound is:

```
O(N log N)
```

Bucket sort avoids comparisons.

So time becomes:

```
O(N)
```

---

# Part 12: Full comparison summary

Brute force:

Repeated scanning
Time: O(N * 256)

Better (sorting):

Uses comparator
Time: O(N log N)

Optimal (bucket sort):

No sorting
Direct indexing
Time: O(N)

---

# Part 13: Interview understanding summary

Sorting approach logic:

Store (char, freq), sort based on freq.

Bucket sort logic:

Store characters at index equal to freq, traverse reverse.

*/

// optimal Solution

