#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        int i,j;
        vector<int> pair;
        vector<vector<int>> total_pairs;
        for(i=0;i<words.size()-1;i++){
            for(j=i+1;j<words.size();j++){
                if(is_palindrome(words[i],words[j])){
                    pair.push_back(i);
                    pair.push_back(j);
                    total_pairs.push_back(pair);
                    pair.clear();
                }
                if(is_palindrome(words[j],words[i])){
                    pair.push_back(j);
                    pair.push_back(i);
                    total_pairs.push_back(pair);
                    pair.clear();
                }
            }

        }
        return total_pairs;
    }
    
    bool is_palindrome(string word1, string word2){
        string word = word1+word2;
        int i=0;
        int j=word.size()-1;
        while(i<=j){
            if(word[i] != word[j]){
            return false;
            }
            i++;
            j--;
        }
        return true;
    };
};


int main(){
    Solution S;
    vector<string> words;
    words.push_back("abcd");
    words.push_back("dcba");
    vector<vector<int>> result = S.palindromePairs(words);
}
