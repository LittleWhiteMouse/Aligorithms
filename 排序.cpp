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

void bubble_sort(vector<int> &a) {
	if (a.size() < 2) return;
	//ÿ���ҵ�����С��Ԫ�ر��ŵ�ĩβ
	for (int end = a.size() - 1; end > 0; --end)
	{
		for (int i = 0; i < end; i++)
		{
			if (a[i] < a[i + 1]) swap(a[i], a[i + 1]);
		}

	}

/************************�Լ�д�İ汾******************************
	for (size_t i = 0; i < a.size(); i++){
		for (size_t j = 0; j < a.size() - i - 1; ++j)
		{
			if (a[j] < a[j + 1]) swap(a[j], a[j + 1]);
		}
	}
*******************************************************/
}

void select_sort(vector<int> &a) {
	if (a.size() < 2)return;
	for (int end = a.size()-1; end > 0; --end)
	{
		int min = end;
		for (int j = 0; j < end; j++)
		{
			if (a[j] < a[min]) min = j;
		}
		swap(a[min], a[end]);
	}
}

void insert_sort(vector<int> &a) {
	if (a.size() < 2)return;
	for (size_t i = 1; i < a.size(); i++)
	{
		for (size_t j = i - 1; j >= 0 && a[j] < a[j + 1]; j--)
		{
			swap(a[j], a[j + 1]);
		}
	}
}

//�鲢����
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

//��������
vector<int> partition(vector<int> &a,int l,int r) {
	// �����һ����Ϊ������ֵ
	int left = l-1;
	int right = r;
	while (l < right)
	{
		if (a[l] < a[r]) { swap(a[l], a[left + 1]); left++; l++; }
		else if (a[l] == a[r]) l++;
		else if (a[l] > a[r]) { swap(a[l], a[right - 1]); right--; };
	}
	swap(a[right], a[r]);
	return { left,right+1};
}
void quicksort(vector<int>&a, int left, int right) {
	if (a.size() < 2 || left >= right) return;
	vector<int> ind = partition(a, left, right);
	quicksort(a, left, ind[0]);
	quicksort(a, ind[1], right);
}

//������
void bigRoot(vector<int> &a,int index) {
	for (int i = 1; i <= index; i++)
	{
		if (a[i]>a[(i-1)/2])
		{
			int l = i;
			while(a[l]>a[(l-1)/2]){
				swap(a[l], a[(l - 1)/2]);
				l = (l-1)/2;
			}
		}
	}
}
void downHill(vector<int> &a,int index) {
	int i = 0;
	while (2*i+1<=index)
	{
		int larger = ((2 * i + 2) <= index && (a[2 * i + 1] < a[2 * i + 2])) ? (2 * i + 2) : (2 * i + 1);
		if (a[i] <= a[larger]) {
			swap(a[i], a[larger]);
			i = larger;
		}
		else break;
	}
}
void heapsort(vector<int> &a) {
	if (a.size() < 2)return;
	int index = a.size() - 1;

	bigRoot(a, a.size() - 1);
	while (index>0)
	{
		swap(a[0], a[index--]);
		downHill(a, index);
	}
}


int main(int argc, char ** argv) {
	//��ʼ���б�
	srand(int(time(0)));
	vector<int> a;
	int s = rand() % 20;
	for (int i = 0; i < s; i++) {
		a.push_back(rand()%100);
	}

	cout << "original vector :";
	for (vector<int>::iterator it = a.begin();it!=a.end();)
	{
		cout << *it++ <<" ";
	}
	cout << endl;

	
	//bubble_sort(a);//ð������
	//select_sort(a);//ѡ������
	//insert_sort(a);//��������
	//mergesort(a,0,a.size()-1);//�鲢����
	//quicksort(a,0,a.size()-1);//��������
	//heapsort(a);//������
	
	cout << "size : " <<a.size()<< " sort result: ";
	for (auto i:a){	cout << i << " ";}
	cout << endl;








	system("pause");
}



