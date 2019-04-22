// Problem 01
void InsertionSort(int* a, int n) {	
    int j,k;
    for(int i = 1; i < n; i++)
    {
        int k = a[i];
        j = i-1;
        while(j>=0 && a[j] > k){
            a[j+1]= a[j];
            j = j-1;
        }
        a[j+1] = k;
    }
}

