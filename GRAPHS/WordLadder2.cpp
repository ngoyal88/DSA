#include<bits/stdc++.h>
using namespace std;
    vector<vector<string>> findSequences(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> st(wordList.begin() ,wordList.end());
        queue<vector<string>> q;
        q.push({beginWord});
        st.erase(beginWord);
        vector<string> used_on_level;
        used_on_level.push_back(beginWord);
        vector<vector<string>> ans;
        int level = 0 ;
        
        while(!q.empty()){
            vector<string> vec = q.front();
            q.pop();
            
            if(vec.size() > level){
                level++;
                for(auto it : used_on_level){
                    st.erase(it);
                }
                used_on_level.clear();
            }
            string word = vec.back();
            if(word == endWord){
                if(ans.size() == 0){
                    ans.push_back(vec);
                }
                else if(ans[0].size() == vec.size()){
                    ans.push_back(vec);
                }
            }
            for(int i=0;i<word.size();i++){
                char original = word[i];
                for(char ch = 'a' ; ch<= 'z' ; ch++){
                    word[i] = ch;
                    if(st.count(word)>0 ){
                        vec.push_back(word);
                        q.push(vec);
                        used_on_level.push_back(word);
                        vec.pop_back();
                    }
                }
                word[i] = original;
            }
        }
        return ans;
    }
bool comp(vector<string> a, vector<string> b)
{
    string x = "", y = "";
    for(string i: a)
        x += i;
    for(string i: b)
        y += i;
    
    return x<y;
}

int main(){

        int n=5;
		vector<string>wordList = {"des","der","dfr","dgt","dfs"};
		string startWord = "der", targetWord = "dfs";
		vector<vector<string>> ans =findSequences(startWord, targetWord, wordList);
		if(ans.size()==0)
		    cout<<-1<<endl;
		else
		{
		    sort(ans.begin(), ans.end(), comp);
            for(int i=0; i<ans.size(); i++)
            {
                for(int j=0; j<ans[i].size(); j++)
                {
                    cout<<ans[i][j]<<" ";
                }
                cout<<endl;
            }
		}
	return 0;
}