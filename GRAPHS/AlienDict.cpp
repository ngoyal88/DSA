#include <bits/stdc++.h>
using namespace std;

    vector<int> topoSort(vector<int> adj[],int n){
        string ans;
        vector<int> indegree(n,0);
        queue<int> q;
        vector<int> topo;
        
        for(int i=0;i<n;i++){
            for(auto it: adj[i]){
                indegree[it]++;
            }
        }
        for(int i=0;i<n;i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int node = q.front();
            q.pop();
            topo.push_back(node);
            for(auto it: adj[node]){
                indegree[it]--;
                if(indegree[it] == 0){
                    q.push(it);
                }
            }
        }
        return topo;
        
    }
    string findOrder(string dict[], int N, int K) {
        string ans;
        vector<int> adj[K];
        for(int i=0;i<N-1;i++){
            string s1 = dict[i];
            string s2 = dict[i+1];
            int len = min(s1.size(),s2.size());
            for(int j=0;j<len;j++){
                if(s1[j] != s2[j]){
                    adj[s1[j] - 'a'].push_back(s2[j] - 'a');
                    break;
                }
            }
        }
        vector<int>  vec = topoSort(adj,K);
        for(auto it : vec){
            ans+= char(it+'a'); 
        }
        return ans;
    }


//{ Driver Code Starts.
string order;
bool f(string a, string b) {
    int p1 = 0;
    int p2 = 0;
    for (int i = 0; i < min(a.size(), b.size()) and p1 == p2; i++) {
        p1 = order.find(a[i]);
        p2 = order.find(b[i]);
        //	cout<<p1<<" "<<p2<<endl;
    }

    if (p1 == p2 and a.size() != b.size()) return a.size() < b.size();

    return p1 < p2;
}

// Driver program to test above functions
int main() {
        int N, K;
        cin >> N >> K;
        string dict[N];
        for (int i = 0; i < N; i++) cin >> dict[i];
        
        string ans =findOrder(dict, N, K);
        cout<<ans<<endl;
        order = "";
        for (int i = 0; i < ans.size(); i++) order += ans[i];

        string temp[N];
        std::copy(dict, dict + N, temp);
        sort(temp, temp + N, f);

        bool f = true;
        for (int i = 0; i < N; i++)
            if (dict[i] != temp[i]) f = false;

        if(f)cout << 1;
        else cout << 0;
        cout << endl;
    return 0;
}
