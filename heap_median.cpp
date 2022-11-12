#include<bits/stdc++.h>
using namespace std;

void GetMedians(int arr[], int n)
{

	priority_queue<int> max;
	priority_queue<int,vector<int>,greater<int> > min;
	int med = arr[0];
	max.push(arr[0]);

	cout << med << endl;
	for (int i=1; i < n; i++)
	{
		int x = arr[i];
        if(x<med){
            if(max.size()>min.size()){
                min.push(max.top());
                max.pop();
                max.push(x);
            }
            else{
                max.push(x);
            }
        }
        else if(x>med){
            if(min.size()>max.size()){
                max.push(min.top());
                min.pop();
                min.push(x);
            }
            else{
                min.push(x);
            }
        }
        if(min.size() > max.size()){
            med = min.top();
        }
        else{
            med = max.top();
        }
		cout << med << endl;
	}
}


int main()
{
	int arr[] = {110, 80, 10, 30, 90, 100, 20, 40, 35, 70};
	int n = sizeof(arr)/sizeof(arr[0]);
	GetMedians(arr, n);
}
