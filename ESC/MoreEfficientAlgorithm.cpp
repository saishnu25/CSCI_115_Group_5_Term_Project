#include <iostream>
#include <vector>
#include <time.h>
#include <cstdlib>
#include <iomanip>
using namespace std;

void bruteForceSum(vector<int> x, int sum){
	for(int i = 0; i < x.size()-1; i++){
		for(int j = i+1; j < x.size(); j++){
			if(x[i] + x[j] == sum){
				cout << "Elements at [" << i << "] and [" << j << "] total to " << sum << endl;
				cout << "Element at [" << i << "] is equal to " << x[i] << " and element at [" << j << "] is equal to " << x[j] << endl;
				return;
			}
		}
	}
	cout << "There are no values in this list that sum to " << sum << endl;
}

bool existsZeroF(vector<int> x, int pos){
	for(int i = pos; i < x.size(); i++){
		if(x[i] == 0){
			return true;
		}
	}
	return false;
}

void findPairSum(vector<int> x, int sum){
	int max = 0;
	int midChecker = 0;
	int elementHolder = 0;
	vector<int> minList, midList;
	bool existsZero = false;
	for(int i = 0; i < x.size(); i++){
		if(x[i] == 0){
			existsZero = true;
		}
		
		if(x[i] <= sum/2){
			minList.push_back(x[i]);
		}
	    if(x[i] > sum/2 && x[i] < sum){
			midList.push_back(x[i]);
		}
		if(x[i] == sum/2){
			midChecker++;
			if(midChecker == 1){
				elementHolder = i;
			}
			if(midChecker >= 2){
				cout << "Element Holder at: " << i << " and at: " << elementHolder << endl;
				cout << "Their values are both: " << x[elementHolder] << endl;
				return;
			}
		}
		if(x[i] == sum && (existsZero || existsZeroF(x, i))){
			cout << "There is an element equal to 0 and an element equal to the sum at: " << i << endl ; 
			return;
		}
		if(max < x[i]){
			max = x[i];
		}
	}
	if((max*2+1) < sum){
		cout << "Sum is to large for this list " << endl;
		return;
	}
	for(int i = minList.size()-1; i >= 0; i--){
		for(int j = 0; j < midList.size(); j++){
			if(minList[i] + midList[j] == sum){
				cout << "Elements at [" << i << "] and [" << j << "] total to " << sum << endl;
				cout << "Element at [" << i << "] is equal to " << minList[i] << " and element at [" << j << "] is equal to " << midList[j] << endl;
				return;
			}
		}
	}
	cout << "There are no values in this list that sum to " << sum << endl;
}

int main(){
	//Time Variables
	clock_t start;
	clock_t end;
	double runTime;
	////////////////
	// Random Seed
	srand(time(0));
	// Variables
	vector<int> x; 		// 3 test
	vector<int> y;
	vector<int> z;
	int elemNumOne;		// Input number for tests 1 - 3
	int randNumMax;		// Max number possible in unsorted list
	int sum;
	
	// Test One Sorted //////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	cout << "--Testing part 1: Sorted--" << endl;
	cout << "Input Number of elements in test 1: ";
	cin >> elemNumOne;
	for(int i = 0; i <= elemNumOne; i++){	
		x.push_back(i);
	}
	cout << "Input Sum we are trying to find:    ";
	cin >> sum;
	cout << "\nBrute Force Method: " << endl;
	start = clock();
	bruteForceSum(x, sum);
	end = clock();
	runTime = double(end - start) / double(CLOCKS_PER_SEC);
	cout << "Run time for Test 1 (Brute Force): " << runTime << setprecision(6) << endl << endl;
	
	// Testing new function
	cout << "More Efficient Algorithm: " << endl;
	start = clock();
	findPairSum(x, sum);
	end = clock();
	runTime = double(end - start) / double(CLOCKS_PER_SEC);
	cout << "Run time for Test 1 (More Efficient Algorithm): " << runTime << setprecision(6) << endl << endl << endl;
	
	
	
	// Test Two Reverse Sorted //////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	cout << "--Testing part 2: Reverse Sorted--" << endl;
	cout << "Input Number of elements in test 2: ";
	cin >> elemNumOne;
	for(int i = 0; i <= elemNumOne; i++){	
		y.push_back(elemNumOne - i);
	}
	cout << "Input Sum we are trying to find:    ";
	cin >> sum;
	cout << "\nBrute Force Method: " << endl;
	start = clock();
	bruteForceSum(y, sum);
	end = clock();
	runTime = double(end - start) / double(CLOCKS_PER_SEC);
	cout << "Run time for Test 2 (Brute Force): " << runTime << setprecision(6) << endl << endl;
	
	// Testing new function
	cout << "More Efficient Algorithm: " << endl;
	start = clock();
	findPairSum(x, sum);
	end = clock();
	runTime = double(end - start) / double(CLOCKS_PER_SEC);
	cout << "Run time for Test 2 (More Efficient Algorithm): " << runTime << setprecision(6) << endl << endl << endl;
	
	
	
	// Test Tree Unsorted Random //////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	cout << "--Testing part 3: Unsorted--" << endl;
	cout << "Input number of elements in test 3: ";
	cin >> elemNumOne;
	cout << "Input max number for random inputs: ";
	cin >> randNumMax;
	for(int i = 0; i <= elemNumOne; i++){	
		z.push_back(rand()%(randNumMax+1));
	}
	cout << "Input Sum we are trying to find:    ";
	cin >> sum;
	cout << "\nBrute Force Method: " << endl;
	start = clock();
	bruteForceSum(z, sum);
	end = clock();
	runTime = double(end - start) / double(CLOCKS_PER_SEC);
	cout << "Run time for Test 3 (Brute Force): " << runTime << setprecision(6) << endl << endl;
	
	// Testing new function
	cout << "More Efficient Algorithm: " << endl;
	start = clock();
	findPairSum(z, sum);
	end = clock();
	runTime = double(end - start) / double(CLOCKS_PER_SEC);
	cout << "Run time for Test 3 (More Efficient Algorithm): " << runTime << setprecision(6);

	return 0;
}
