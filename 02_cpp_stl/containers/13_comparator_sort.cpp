// sorting logic 

// typical o(n^2) sorting algo 

void bubbleSort(int arr[], int n) {
  
    for (int i = 0; i < n - 1; i++) {
      
        for (int j = 0; j < n - i - 1; j++) {
        
            if (arr[j] > arr[j + 1])   //in such sorting algorithm, this thing is very certain. a[1]>a[2], adjacent elements are compared and swapped
            // > for ascending 
            // < for dscending
            {   
                swap(arr[j], arr[j + 1]);   
            }
        }
    }
}


// this entire logic of sorting by comparing the adjacent element is compressed in shifted in a function called as compartor function

bool swap(int a,int b){
    if(a>b) return true;
    return false;
}




void bubbleSort(int arr[], int n) {
  
    for (int i = 0; i < n - 1; i++) {
      
        for (int j = 0; j < n - i - 1; j++) {
        
            if (swap(a[i],a[j]))   //in such sorting algorithm, this thing is very certain. a[1]>a[2], adjacent elements are compared and swapped
            // > for ascending 
            // < for dscending
            {   
                swap(arr[j], arr[j + 1]);   
            }
        }
    }
}