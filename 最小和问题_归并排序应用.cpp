#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
using namespace std;

void swap(int &a, int &b) {
	int temp = a;
	a = b;
	b = temp;
}

int minsum(vector<int> &a) {
	int sum = 0;
	for (size_t i = 0; i < a.size(); i++){
		for (size_t j = 0; j < i; j++){
			if (a[i] > a[j]) sum += a[j];
		}
	}
	return sum;

}

int merge(vector<int> &a, int left,int mid, int right) {
	if (left >= right || a.size() < 2) return 0;
    vector<int> temp;
	int l = left;
	int r = mid + 1;
	int sum = 0;
	while (l<=mid && r <= right){ 
		sum += (a[l] < a[r]) ? a[l] * (right - r+1) : 0;
		temp.push_back((a[l] < a[r] ? a[l++] : a[r++]));
		
	}
	while (l<=mid){ temp.push_back(a[l++]);}
	while (r<=right){ temp.push_back(a[r++]);}

	for (size_t i =0;i<temp.size();){
		a[left++] = temp[i++];
	}
	cout <<endl<< "temp: ";
	for (auto ax:temp)
	{
		cout << ax << " ";
	}
	cout << endl;
	return sum;
}

int sort(vector<int> &a,int left, int right) {
	if (left >= right || a.size() < 2) return 0;
	int mid = left + (right - left)/2;
	return sort(a, left, mid) + sort(a, mid + 1, right)+merge(a, left, mid, right);
}

int minsum2(vector<int> &a) {



	return 0;
}

int main(int argc, char ** argv) {
	
	//初始化列表
	srand(int(time(0)));
	vector<int> a,b;
	int s = rand() % 20;
	for (int i = 0; i < s; i++) {
		a.push_back(rand() % 100);
		b.push_back(a[i]);
	}
	cout << "original vector :";
	for (vector<int>::iterator it = a.begin(); it != a.end();){
		cout << *it++ << " ";
	}
	

	
	int sum = sort(a, 0, a.size()-1);
	cout << endl;
	cout << "sorted vector :";
	for (vector<int>::iterator it = a.begin(); it != a.end();) {
		cout << *it++ << " ";
	}
	cout << "\nsum:  " << sum << endl;
	cout << "\nminnsum:  " << minsum(b) << endl;


	system("pause");

}



/***********************************

void merge(vector<int> &a, int left,int mid, int right) {
	if (left >= right || a.size() < 2) return;
	vector<int> temp;
	int l = left;
	int r = mid + 1;
	while (l<=mid && r <= right){ temp.push_back((a[l] < a[r] ? a[l++] : a[r++]));}
	while (l<=mid){ temp.push_back(a[l++]);}
	while (r<=right){ temp.push_back(a[r++]);}

	for (size_t i =0;i<temp.size();){
		a[left++] = temp[i++];
	}
	cout <<endl<< "temp: ";
	for (auto ax:temp)
	{
		cout << ax << " ";
	}
	cout << endl;
}

void mergesort(vector<int> &a,int left, int right) {

	if (left >= right || a.size() < 2) return;
	int mid = left + (right - left)/2;
	mergesort(a, left, mid);
	mergesort(a, mid + 1, right);
	merge(a, left, mid, right);
	cout << endl;
}



************************************/