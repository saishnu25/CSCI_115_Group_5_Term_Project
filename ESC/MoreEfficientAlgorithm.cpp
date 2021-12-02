#include <iostream>
#include <vector>
#include <time.h>
#include <cstdlib>
#include <iomanip>
using namespace std;

bool bruteForceSum(vector<int> x, int sum){
	bool check = false;
	for(int i = 0; i < x.size()-1; i++){
		for(int j = i+1; j < x.size(); j++){
			if(x[i] + x[j] == sum){
				check =  true;
			}
		}
	}
	return check;
}

bool findPairSum(vector<int> x, int sum){
	int max = 0;
	int min = x[0];
	int midChecker = 0;
	int elementHolder = 0;
	vector<int> minList, midList;
	bool existsZero = false;
	for(int i = 0; i < x.size(); i++){
		if(x[i] == 0){
			existsZero = true;
		}
	}
	for(int i = 0; i < x.size(); i++){
		if(x[i] == sum/2){
			midChecker++;
			if(midChecker == 1){
				elementHolder = i;
			}
			if(midChecker >= 2){
				return true;
			}
		}
		if(x[i] <= sum/2){
			minList.push_back(x[i]);
		}
	    	if(x[i] > sum/2 && x[i] < sum){
			midList.push_back(x[i]);
		}
		if(x[i] == sum && existsZero){
			return true;
		}
		if(max < x[i]){
			max = x[i];
		}
		if(min > x[i]){
			min = x[i];
		}
	}
	if((max*2+1) < sum){
		return false;
	}
	if(min > sum){
		return false ;
	}
	if(minList[0] > minList[minList.size()-1])
		for(int i = 0; i < minList.size(); i++){
			for(int j = 0; j < midList.size(); j++){
				if(minList[i] + midList[j] == sum){
					return true;
				}
			}
	}
	else{
		for(int i = minList.size()-1; i >= 0; i--){
			for(int j = 0; j < midList.size(); j++){
				if(minList[i] + midList[j] == sum){
					return true;
				}
			}
		}
	}
	return false;
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
	cout << "\nBrute Force Method: ";
	start = clock();
	bruteForceSum(x, sum);
	end = clock();
	runTime = double(end - start) / double(CLOCKS_PER_SEC);
	cout << bruteForceSum(x, sum) << endl;
	cout << "Run time for Test 1 (Brute Force): " << runTime << setprecision(6) << endl << endl;
	
	// Testing new function
	cout << "More Efficient Algorithm: ";
	start = clock();
	findPairSum(x, sum);
	end = clock();
	runTime = double(end - start) / double(CLOCKS_PER_SEC);
	cout << findPairSum(x, sum) << endl;
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
	cout << "\nBrute Force Method: ";
	start = clock();
	bruteForceSum(y, sum);
	end = clock();
	runTime = double(end - start) / double(CLOCKS_PER_SEC);
	cout << bruteForceSum(y, sum) << endl;
	cout << "Run time for Test 2 (Brute Force): " << runTime << setprecision(6) << endl << endl;
	
	// Testing new function
	cout << "More Efficient Algorithm: ";
	start = clock();
	findPairSum(y, sum);
	end = clock();
	runTime = double(end - start) / double(CLOCKS_PER_SEC);
	cout << findPairSum(y, sum) << endl;
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
	cout << "\nBrute Force Method: ";
	start = clock();
	bruteForceSum(z, sum);
	end = clock();
	runTime = double(end - start) / double(CLOCKS_PER_SEC);
	cout << bruteForceSum(z, sum) << endl;
	cout << "Run time for Test 3 (Brute Force): " << runTime << setprecision(6) << endl << endl;
	
	// Testing new function
	cout << "More Efficient Algorithm: ";
	start = clock();
	findPairSum(z, sum);
	end = clock();
	runTime = double(end - start) / double(CLOCKS_PER_SEC);
	cout << findPairSum(z, sum) << endl;
	cout << "Run time for Test 3 (More Efficient Algorithm): " << runTime << setprecision(6);

	return 0;
}
