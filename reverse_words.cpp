#include <bits/stdc++.h>

using namespace std;

string reverseWords(string s) {
        
        string reverse;
        stack<char> st;
        string word = "";
        for(auto it : s){
            if(it == ' '){
                for(char x : word){
                st.push(x);
                }
                while(!st.empty()){
                    reverse.push_back(st.top());
                    st.pop();
                }
                word="";
                reverse.push_back(it);
            }
            else{
                word += it;
            }
        }
        for(char x : word){
            st.push(x);
        }
        while(!st.empty()){
            reverse.push_back(st.top());
            st.pop();
        }
    return reverse;

}
        

int main(){
    string  s = "Let's take LeetCode contest";
    string reverse = reverseWords(s);
    cout<<"a";
}