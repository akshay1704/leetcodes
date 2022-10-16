#include<bits/stdc++.h>
using namespace std;

class Heap
{
    private:
        vector <int> heap;
        int left(int parent);
        int right(int parent);
        int parent(int child);
        void heapifyup(int index);
        void heapifydown(int index);
    public:
        Heap()
        {}
        void Insert(int element);
        void DeleteMin();
        int ExtractMin();
        void DisplayHeap();
        int Size();
};

int Heap::Size()
{
    return heap.size();
}

void Heap::Insert(int element)
{
    heap.push_back(element);
    heapifyup(heap.size() -1);
}

void Heap::DeleteMin()
{
    if (heap.size() == 0)
    {
        cout<<"Heap is Empty"<<endl;
        return;
    }
    heap[0] = heap.at(heap.size() - 1);
    heap.pop_back();
    heapifydown(0);
    cout<<"Element Deleted"<<endl;
}

int Heap::ExtractMin()
{
    if (heap.size() == 0)
    {
        return -1;
    }
    else
        return heap.front();
}
 
void Heap::DisplayHeap()
{
    vector <int>::iterator pos = heap.begin();
    cout<<"Heap -->  ";
    while (pos != heap.end())
    {
        cout<<*pos<<" ";
        pos++;
    }
    cout<<endl;
}

int Heap::left(int parent)
{
    int l = 2 * parent + 1;
    if(l < heap.size())
        return l;
    else
        return -1;
}

int Heap::right(int parent)
{
    int r = 2 * parent + 2;
    if(r < heap.size())
        return r;
    else
        return -1;
}

int Heap::parent(int child)
{
    int p = (child - 1)/2;
    if(child == 0)
        return -1;
    else
        return p;
}
 
void Heap::heapifyup(int in)
{
    if (in >= 0 && parent(in) >= 0 && heap[parent(in)] > heap[in])
    {
        int temp = heap[in];
        heap[in] = heap[parent(in)];
        heap[parent(in)] = temp;
        heapifyup(parent(in));
    }
}

void Heap::heapifydown(int in)
{
    int child = left(in);
    int child1 = right(in);
    if (child >= 0 && child1 >= 0 && heap[child] > heap[child1])
    {
       child = child1;
    }
    if (child > 0)
    {
        int temp = heap[in];
        heap[in] = heap[child];
        heap[child] = temp;
        heapifydown(child);
    }
}


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
