#include <iostream>
#include <fstream>
#include <cmath>
#include <ctime>
//string kullandým
#define EXIT_SUCCESS 1
#define EXIT_FAIL 0
#define ASCIIstart 0
#define ASCIIstop 127

using namespace std;

struct letterStruct{
	char letter;
	int seen1;
	int seen2;
} typedef alphabet;

void initialize(alphabet *);
long make_anagram(string, string);
int main(){;

	string line1, line2;
	ifstream file;
	
	file.open("input.txt");
		
	if(file.is_open()){
		getline(file, line1);
		getline(file, line2);
		cout<<make_anagram(line1, line2);
	}
	else{
		cout<<"input.txt cannot be opened!\nProgram will be terminated!";
		return EXIT_FAIL;
	}
	return EXIT_SUCCESS;
}


void initialize(alphabet *array){
	int i = ASCIIstart;
	
	for(i; i<ASCIIstop; i++){
		array[i].letter = i;
		array[i].seen1 = 0;
		array[i].seen2 = 0;
	}
	
}

long make_anagram(string first_string, string second_string){
	long deletedCounter;
	long i = 0;
	alphabet *array; //lookuptable

	array = new alphabet[ASCIIstop-ASCIIstart]; 
	initialize(array);
	
	while(first_string[i]!= '\0'){
		array[first_string[i]].seen1++;
		i++;
	}
	i=0;
	while(second_string[i]!= '\0'){
		array[second_string[i]].seen2++;
		i++;
	}
	
	for(i=ASCIIstart; i<ASCIIstop; i++){
		if(array[i].seen1 != array[i].seen2)
			deletedCounter+=abs(array[i].seen1-array[i].seen2);
	}


	return deletedCounter;
}
