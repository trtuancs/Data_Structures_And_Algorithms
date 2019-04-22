// Problem 02
inline void ReHeapDown(int arr[], int n, int cur)
{
	int l = 2 * cur + 1;
	while (l < n) {
		int largest = l;
		int r = 2 * cur + 2; // right = 2*i + 2 
		if (r < n && arr[r] > arr[l])
			largest = r;

		// If largest is not root 
		if (arr[largest] > arr[cur])
		{			
			int temp = arr[cur];
			arr[cur] = arr[largest];
			arr[largest] = temp;
			cur = largest;
			l = 2 * cur + 1; // left = 2*i + 1 
		}
		else return;
	}
	
}



void HeapSort(int* a, int n)
{
	int position = n/2 -1;
	while(position >= 0){
		ReHeapDown(a,n,position);
		position = position -1;
	}
	int last = n-1;
	while(last > 0){
		int temp = a[0];
		a[0] = a[last];
		a[last] = temp;
		ReHeapDown(a,last,0);
 		last = last -1;
	}
	
}
