#include<bits/stdc++.h>
using namespace std;

bool contains(string str1, string str2) {
 return (str1.find(str2) != string::npos);
}

int main(){
    ifstream myfile;
    myfile.open("test.csv");
    vector<string> dict;
    while(myfile.good()){
        string line;
        getline(myfile, line);
        stringstream ss(line);
        string word;
        getline(ss, word, ',');
        dict.push_back(word);
    }
    myfile.close();
    string word;
    cin>>word;
    map<int,string> ans;
    for(int i=0;i<dict.size();i++){
        string pattern = dict[i];
        int count=0;
        for(int j=0;j<pattern.size()&&j<word.size();j++){
            if(pattern[j]==word[j]){
                count++;
            }
        }
        ans.insert({count,pattern});
    }
    int i=0;
    for(auto it=ans.rbegin();it!=ans.rend();it++){
        i++;
        if(i>5){
            break;
        }
        if(it->first>0)
        cout<<it->second<<endl;
    }
    return 0;
}