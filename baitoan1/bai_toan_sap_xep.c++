#include<bits/stdc++.h>
using namespace std;

//merge sort
void merge(int arr[], int begin, int end) {
	int mid = begin + (end - begin) / 2;
	int left = mid - begin + 1,
		right = end - mid;
	int *arr_left = new int[left],
	    *arr_right = new int[right];
	for (int i = 0; i < left; i++) {
		arr_left[i] = arr[begin + i];
	}
	for (int i = 0; i < right; i++) {
		arr_right[i] = arr[mid + i + 1];
	}
	int index_left = 0;
	int index_right = 0;
	int index_merge = begin;
	while (index_left < left && index_right < right ) {
		if (arr_left[index_left] <= arr_right[index_right]) {
			arr[index_merge] = arr_left[index_left];
			index_left++;
		}
		else {
			arr[index_merge] = arr_right[index_right];
			index_right++;
		}
		index_merge++;
	}
	while (index_left < left) {
		arr[index_merge] = arr_left[index_left];
		index_left++;
		index_merge++;
	}
	while (index_right < right) {
		arr[index_merge] = arr_right[index_right];
		index_right++;
		index_merge++;
	}
	delete[] arr_left;
	delete[] arr_right;
}

void merge_sort(int arr[], int begin, int end) {
	if (begin >= end) {
		return;
	}
	int mid = begin + (end - begin) / 2;
	merge_sort(arr, begin , mid);
	merge_sort(arr, mid + 1, end);
	merge(arr, begin, end);
}

//buble sort

void buble_sort(int n, int arr[]) {
	for (int i = n-1; i > 0; i--) {
		for (int j = 1; j <=i; j++) {
			if (arr[j-1]>arr[j]) {
				int tmp = arr[j-1];
				arr[j-1] = arr[j];
				arr[j] = tmp;
			}
		}
	}
} 

//insert_sort

void insert_sort(int n, int arr[]) {
	int i, key, j;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
} 

//quick_sort

void quick_sort(int arr[], int start, int end) {
	int i = start;
	int key = arr[start];
	for (int j = start; j <= end; j++) {
		if (arr[j] < key ) {
			i++;
			swap(arr[i], arr[j]);
		}
	}
	swap(arr[start], arr[i]);
	
	if (start < end) {
		quick_sort(arr, start, i-1);
		quick_sort(arr, i+1, end);
	}
}

//heap_sort

void heap(int arr[], int n, int i) {
	int max = i;
	int left_child = 2*i + 1;
	int right_child = 2*i + 2;
	if (left_child < n && arr[left_child] > arr[max]) {
		max = left_child;
	}
	if (right_child < n && arr[right_child] > arr[max]) {
		max = right_child;
	}
	if (max != i) {
		swap(arr[max], arr[i]);
		heap(arr, n, max);
	}
}

void heap_sort(int arr[], int n) {
	for (int i = n/2 -1; i >= 0; i--) {
		heap(arr, n, i);
	}
	for (int i = n-1; i > 0; i--) {
		swap(arr[0], arr[i]);
		heap(arr, i, 0);
	}
}

//print

void print(int n, int arr[]) {
	cout<<endl;
	cout<<"Day so sau khi da sap xep: ";
	for (int i = 0; i < n; i++) {
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}

//main

int main() {
	srand(time(NULL));
	clock_t start, end; // bien lay thoi gian he thong
	ifstream file; // doc file
	ofstream out_file; // ghi file
	int n; // lua chon de sap xep theo thuat toan nao
	int *arr; // day can sap xep
	int m; // so luong phan tu 
	int chose; // lua chon phuong thuc nhap input
	while(true) {
		cout<<"--Chuong trinh sap xep theo mot so thuat toan--"<<endl;
		cout<<"--Lua chon thuat toan"<<endl;
		cout<<"1. Buble sort"<<endl;
		cout<<"2. Insert sort"<<endl;
		cout<<"3. Quick sort"<<endl;
		cout<<"4. Heap sort"<<endl;
		cout<<"5. Merge sort"<<endl;
	
		cout<<"Nhap thuat toan ban muon chon: ";
		cin>>n;
	
		cout<<"Chon phuong thuc nhap input "<<endl;
		cout<<"1. Nhap tu ban phim"<<endl;
		cout<<"2. Sinh ngau nhien"<<endl;
		cout<<"3. Doc file"<<endl;
		cout<<"Chon: ";
		cin>>chose;
				
		switch(chose) {
			case 1:
				{	cout<<"Nhap vao so luong phan tu: ";
					cin>>m;
					arr = new int[m];
					for (int i = 0; i < m; i++) {
						cin>>arr[i];
					}
				}
				break;
				
			case 2: 
				{
					cout<<"Nhap vao so luong phan tu: ";
					cin >> m;
					arr = new int[m];
					for (int i = 0; i < m; i++) {
						arr[i] = rand();
					}	
				}
				break;
				
			case 3:
				{
					file.open("data.txt");
					file >> m;
					arr = new int[m];
					for (int i = 0; i < m; i++) {
						file >> arr[i];
					}
				}
				break;		
		}
	
		switch(n) {
			case 1:
				{   start = clock();
					buble_sort(m, arr);
					end = clock();
					// tinh toan thoi gian thuc hien thuat toan
					double time_to_solve = (double)(end-start)/CLOCKS_PER_SEC ;
					// xuat file
					out_file.open("output.txt", ios_base::out);
					out_file << time_to_solve<<endl;
					for (int i = 0; i < m; i++) {
						out_file << arr[i]<<" "; 
					}
					out_file.close();
					// in ket qua ra console
					print(m, arr);
				}			 
				break;
			
			case 2:
				{
					start = clock();
					insert_sort(m, arr);
					end = clock();
					// tinh toan thoi gian thuc hien thuat toan
					double time_to_solve = (double)(end-start)/CLOCKS_PER_SEC ;
					// xuat file
					out_file.open("output.txt", ios_base::out);
					out_file << time_to_solve<<endl;
					for (int i = 0; i < m; i++) {
						out_file << arr[i]<<" "; 
					}
					out_file.close();
					// in ket qua ra console
					print(m, arr);
				}
				break;
			
			case 3:
				{
					start = clock();
					quick_sort(arr, 0, m-1);
					end = clock();
					// tinh toan thoi gian thuc hien thuat toan
					double time_to_solve = (double)(end-start)/CLOCKS_PER_SEC ;
					// xuat file
					out_file.open("output.txt", ios_base::out);
					out_file << time_to_solve<<endl;
					for (int i = 0; i < m; i++) {
						out_file << arr[i]<<" "; 
					}
					out_file.close();
					// in ket qua ra console
					print(m, arr);
				}
				break;
				
			case 4:
				{
					start = clock();
					heap_sort(arr, m);
					end = clock();
					// tinh toan thoi gian thuc hien thuat toan
					double time_to_solve = (double)(end-start)/CLOCKS_PER_SEC ;
					// xuat file
					out_file.open("output.txt", ios_base::out);
					out_file << time_to_solve<<endl;
					for (int i = 0; i < m; i++) {
						out_file << arr[i]<<" "; 
					}
					out_file.close();
					// in ket qua ra console
					print(m, arr);
				}
				break;
				
			case 5:
				{
					start = clock();
					merge_sort(arr, 0, m-1);
					end = clock();
					// tinh toan thoi gian thuc hien thuat toan
					double time_to_solve = (double)(end-start)/CLOCKS_PER_SEC ;
					// xuat file
					out_file.open("output.txt", ios_base::out);
					out_file << time_to_solve<<endl;
					for (int i = 0; i < m; i++) {
						out_file << arr[i]<<" "; 
					}
					out_file.close();
					// in ket qua ra console
					print(m, arr);
				}
				break;
		}	
		
		file.close();
		delete[] arr;
	}
}