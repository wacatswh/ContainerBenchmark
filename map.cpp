#include <iostream>
#include <map>
#include <iterator>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <chrono>
#include <algorithm>

using namespace std;

int main(int argc, char* argv[])
{
    map<int, int> quiz;

    const int itemCount = atoi(argv[1]);

//-----------------------------------------------------------------

    /*
        Test the performance of std::map in inserting by:
        1) Inserting in ascending order
        2) Inserting in descending order
        3) Inserting in random number
    */

	int keyAndValue = 1;				// Shared key value

    // Insert items into std::map in ascending order

    clock_t time = clock();
    
    for(; keyAndValue <= itemCount; keyAndValue++)
        quiz.insert(make_pair(keyAndValue, keyAndValue));

    cout << "Time insert " << itemCount << " integers ascending: ";
    cout << float( clock() - time ) / CLOCKS_PER_SEC << endl;

	// Insert items into std::list in descending order

	keyAndValue += itemCount;
		// Add itemCount into it for decrementing value

	time = clock();

	for(int i = 0; i < itemCount; i++, keyAndValue--)
		quiz.insert(make_pair(keyAndValue, keyAndValue));

	cout << "Time insert " << itemCount 
			<< " integers descending: ";
	cout << float( clock() - time ) / CLOCKS_PER_SEC << endl;

	// Insert items into std::map in random order

	vector<int> vec;					// Store random unique int
	int max = itemCount * 3;			// Max key of random group
	int min = (max - itemCount) + 1;
										// Min key of random group

	for(; min <= max; min++)
		vec.push_back(min);				// Store min of rand group

	unsigned seed = chrono::system_clock::now().time_since_epoch().count();
	shuffle(vec.begin(), vec.end(), default_random_engine(seed));
										// Randomize vector values

	time = clock();

	for(int i = 0; i < itemCount; i++)
		quiz.insert(make_pair(vec[i], vec[i]));

	cout << "Time insert " << itemCount << " integers random: ";
	cout << float( clock() - time ) / CLOCKS_PER_SEC << endl;

//-----------------------------------------------------------------

	/*
		Test the performance of std::map by:
		1) Random access to its 1/3th element
		2) Random access to its 1/2th element
		3) Search the largest element
		4) Search the smallest element
	*/

	// Random access to its 1/3th element

	/*
		This case is assuming we already know the key beforehand,
		taking advantage by accessing straight to 
		the element with key.
	*/

	const int oneThird = quiz.size() / 3;
										// Index of 1/3th element
	int oneThirdValue; 					// Value of 1/3th element

	time = clock();

	oneThirdValue = quiz.find(oneThird)->second;
										// Retrieve 1/3th value
	
	cout << "Time direct access to 1/3th element with key: ";
	cout << float( clock() - time ) / CLOCKS_PER_SEC << endl;

	// Random access to its 1/2th element

	/*
		This case is assuming we already know the key beforehand,
		taking advantage by accessing straight to the element 
		with key.
	*/

	const int oneHalf = quiz.size() / 2;// Index of 1/2th element
	int oneHalfValue;					// Value of 1/2th element
	
	time = clock();

	oneHalfValue = quiz.find(oneHalf)->second;

	cout << "Time direct access to 1/2th element with key: ";
	cout << float( clock() - time ) / CLOCKS_PER_SEC << endl;

	// Search the largest element - assume key & value unrelated

	/*
		This will iterate through the whole map.
	*/

	time = clock();

	auto largest = max_element(quiz.begin(), quiz.end(),
			[](const pair<int, int>& p1, const pair<int, int>& p2)
				{return p1.second < p2.second;} );
		// Taken from https://stackoverflow.com/a/9371137

	int largestValue = largest->second;

	cout << "Time searching largest element: ";
	cout << float( clock() - time ) / CLOCKS_PER_SEC << endl;

	// Search the smallest element - assume key & value unrelated

	/*
		This will iterate through the whole map too.	
	*/

	time = clock();

	auto smallest = min_element(quiz.begin(), quiz.end(),
			[](const pair<int, int>& p1, const pair<int, int>& p2)
				{return p1.second < p2.second;} ); 
		// Taken from https://stackoverflow.com/a/26843031

	int smallestValue = smallest->second;

	cout << "Time searching smallest element: ";
	cout << float( clock() - time ) / CLOCKS_PER_SEC << endl;

//-----------------------------------------------------------------
	/*
		Test the performance of std::map by:
		1) Random access to and delete its 1/3th element
		2) Random access to and delete largest element
		3) Delete all elements by clear()
	*/

	// Random access to and delete its 1/3th element	

	/*
		Assuming a key was given beforehand and we want to delete
		the element by its key.
	*/

	time = clock();
		
	auto a = quiz.find(oneThird);
	quiz.erase(a);

	cout << "Time direct access and delete 1/3th element: ";
	cout << float( clock() - time ) / CLOCKS_PER_SEC << endl; 

	// Random search and delete largest element

	/*
		Will iterate through the whole map
	*/
	
	time = clock();

	map<int, int>::iterator itrLargest = quiz.begin();

	for(map<int, int>::iterator itr = quiz.begin(); 
		itr != quiz.end(); ++itr)
	{
		if(itr->second > itrLargest->second)
			itrLargest = itr;
	}
	
	quiz.erase(itrLargest);

	cout << "Time random access and delete element "
			<< "with largest value: ";
	cout << float( clock() - time ) / CLOCKS_PER_SEC << endl;

	// Delete all element by clear()

	time = clock();

	quiz.clear();

	cout << "Time clearing all element: ";
	cout << float( clock() - time ) / CLOCKS_PER_SEC << endl;

    return 0;
}
