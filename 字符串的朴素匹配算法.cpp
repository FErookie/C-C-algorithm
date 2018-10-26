#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main(){
	string target = "xyxababcaxxxababca";
	string P = "ababca";

	vector<int> array_find;
	for(int i = 0 ; i < target.length() ; i++){
		int flag = 1;
		if(target[i] == P[0]){
			for(int j = 0 ; j < P.length() ; j++){
				if(target[i + j] != P[j]){
					flag = 0;
					break;
				}
			}
			if(flag == 1){
				array_find.push_back(i);
			}
		}
	}
	for(int i = 0 ; i < array_find.size() ; i++){
		cout << array_find[i] << endl;
	}

	return 0;
}
