#include <iostream>
#include <string>
#include <assert.h>
using namespace std;

int strcmp(string p1 , string p2){
	if(p1.length() != p2.length()){
		cout << "this string length is not equal" << endl;
		return -1;
	}
	int i = 0;
	while(i < p1.length()){
		if(p1[i] != p2[i]){
			cout << "there is some charast is not equal" << endl;
			return 9999;
		}
		i++;
	}
	return 0;
};

int main(){
	cout << strcmp("weqw1" , "weqwe");
	return 0;
}
