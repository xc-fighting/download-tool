#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<string> split(string input, string delimeter) {
	vector<string> result;
	int startIdx = 0;
	int pos = -1;
	int dlen = delimeter.size();
	while((pos = input.find(delimeter, startIdx)) != -1) {
		//cout<<pos<<endl;
		string token = input.substr(startIdx, pos - startIdx);
		if(token.size() > 0) {
			result.push_back(token);
		}
		
		startIdx = pos + dlen;
	}
	return result;
}

void recursive(unordered_map<string,vector<string>>& graph, vector<string>& result, int remain, string start, string curStr) {
     if(remain == 0) {
         result.push_back(curStr);
         return;
     }
     
     
     vector<string> neighbors = graph[start];
     for(int idx = 0; idx < neighbors.size(); idx++) {
     	recursive(graph, result, remain-1, neighbors[idx], curStr + " " + neighbors[idx]);
     }
     return;
}

vector<string> genString(string input, string start, int len) {
	vector<string> group = split(input, " ");
	unordered_map<string, vector<string>> graph;
	for(int idx = 0; idx < group.size() - 1; idx++) {
		string first = group[idx];
		string second = group[idx+1];
        if(graph.find(first) == graph.end()) {
        	graph[first] = vector<string>();
        }
        graph[first].push_back(second);
	}

	for(auto entry: graph) {
		cout<<entry.first<<endl;
		for(int idx = 0; idx < entry.second.size(); idx++) {
			cout<<entry.second[idx]<<" ";
		}
		cout<<endl;
	}
    vector<string> result;
    recursive(graph, result, len-1, start, start);
    return result;

}


int main() {
   vector<string> res = genString("this is a sentence it is not a good one and it is also bad", "sentence", 5);
   for(int idx = 0; idx < res.size(); idx++) {
   	   cout<<res[idx]<<endl;
   }

}