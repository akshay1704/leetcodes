

#include <bits/stdc++.h>
using namespace std;

bool sortby(const pair<int,int> &a, const pair<int,int> &b){
    return ((a.second-a.first)<(b.second-b.first));
}

int minimizeSegment(vector<pair<int, int> > A,
					pair<int, int> X)
{

	vector<pair<int,int>> B = A;
	A.push_back(pair(INT_MAX,INT_MAX));
	sort(A.begin(), A.end());
    vector<pair<int,int>> out;
	int start = X.first;

	int end = start - 1;
    int index = 0;
	int max_count = 0;
	vector<int> index_array;

	for (int i = 0; i < A.size();) {
		if (A[i].first <= start) {   
			end = max(A[i].second, end);
            if(end == A[i].second && A[i].first>=A[index].first){
                index = i;
            }
			i++;
			max_count = 0;
		}
		else {
			max_count++;
			if(max_count > A.size()){
				break;
			}
            out.push_back(pair(A[index].first,A[index].second));
			index_array.push_back(index);
			start = end;
			if(end == X.second){
        		break;
			}
            }
	}
	if(end != X.second){
        return -1;
	}
	int length = out.size();
	reverse(out.begin(),out.end());
	for(int j=0;j<length;j++){
		pair<int,int> x = out.back();
		out.pop_back();
		cout<<x.first<<" to "<<x.second<<endl;
	}

	return 1;
}


int main()
{
	vector<pair<int, int> > A = {
		{ 0,60}, { 0,35}, {40,120}, { 55,140}, { 60,120},{100,160},{130,160}
	};
	vector<pair<int, int>> :: iterator it;
	vector<pair<int,pair<int,int>>> index_map;
	pair<int,pair<int,int>> idx;
	int i = 0;
	for(it = A.begin(); it!=A.end();it++){
		idx.first = i;
		idx.second = *it;
		index_map.push_back(idx);
		i++;
	}
	pair<int, int> X = { 0, 160 };
	cout << minimizeSegment(A, X);

	return 0;
}
