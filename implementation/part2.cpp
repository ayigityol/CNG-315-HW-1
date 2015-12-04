#include <iostream>
#include <functional>
#include <cstdio>
#include <algorithm>

using namespace std;
long* find_sum_parts(long* , long , long );


long b_search(long* array, long size1, long size2, long val)
{
	if ((size2-size1) == 1)
	{
		if (array[size1] != val)
			return -1;
		else
			return size1;
	}
	else
	{
		if ((array[(size1+size2)/2] > val))
			return b_search(array, size1, (size1+size2)/2, val);
		else
			return b_search(array, (size1+size2)/2, size2, val);
	}
}
int main(){
    vector<long> inputVector {};
    string line;
	long i =0 ;
	FILE * file;
	file = fopen("input2.txt","r");
	long  value;
	long  sum = 0;
	
	if(file != NULL){
		while(fscanf(file," %li",&value)!=EOF){
			inputVector.push_back(value);
		}
	}
	sum = inputVector.back();
	long* array = &inputVector[0];
	long* resultIndex = find_sum_parts(array, inputVector.size(), sum);
	if(resultIndex != NULL)
		cout << " " << (resultIndex - array);
	return 0;
}


long* find_sum_parts(long* array, long size, long sum){
	
	for(long i = 0; i<size;i++) {
		
        long a = b_search(array, 0, size, sum-array[i]);
        if(a != -1) {
        	cout << i;
        	return &array[a];	
		}
    }
    
	return NULL;
}
