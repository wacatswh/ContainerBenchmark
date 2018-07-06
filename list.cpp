#include <iostream>
#include <list>
#include <iterator>
#include <ctime>
#include <cstdlib>

using namespace std;

int main(int argc, char *argv[])
{
    list<int> list;

    const int itemCount = atoi(argv[1]); 

//------------------------------------------------------------------

    /*
        Test the performance of std::list in inserting by:
        1) Inserting in ascending order
        2) Inserting in descending order
        3) Inserting in random number
    */

    // Insert items into std::list in ascending order

    clock_t time = clock();    

    for(int i = 0; i < itemCount; i++)
        list.push_back(i + 1);
    
    cout << "Time insert " << itemCount << " integers ascending: ";
    cout << float( clock() - time ) / CLOCKS_PER_SEC << endl;

    // Insert items into std::list in descending order

    time = clock();

    for(int i = itemCount; i != 0; i--)
        list.push_back(itemCount);

    cout << "Time insert " << itemCount << " integers descending: ";
    cout << float( clock() - time ) / CLOCKS_PER_SEC << endl;    

     // Insert items into std::list in random order

    time = clock();

    for(int i = 0; i < itemCount; i++)
        list.push_back(rand() % itemCount);

    cout << "Time insert " << itemCount << " integers random: ";   
    cout << float( clock() - time ) / CLOCKS_PER_SEC << endl; 

//------------------------------------------------------------------

    /*
        Test the performance of std::list by:
        1) Random access to its 1/3th element
        2) Random access to its 1/2th element
        3) Search the largest element
        4) Search the smallest element
    */

    // Random access to its 1/3th element

    const int oneThird = list.size() / 3; 
										// Index of 1/3th element
    int oneThirdValue;                  // Value of 1/3th element
    int count = 0;                      // General use counter

    time = clock();
    
    for(std::list<int>::const_iterator iterator = list.begin();
        iterator != list.end(); ++iterator, count++)
    {
        if(count == oneThird)
        {
            oneThirdValue = *iterator; 
            break;
        }
    }  
    
    cout << "Time random access to 1/3th element: ";
    cout << float( clock() - time ) / CLOCKS_PER_SEC << endl;

    // Random access to its 1/2th element
    
    const int oneHalf = list.size() / 2;// Index of 1/2th element
    int oneHalfValue;                   // Value of 1/2th element
    count = 0;                          // Reset counter value 

    time = clock();

    for(std::list<int>::const_iterator iterator = list.begin();
        iterator != list.end(); ++iterator, count++)
    {
        if(count == oneHalf)
        {
            oneHalfValue = *iterator;   
            break;
        }
    } 

    cout << "Time random access to 1/2th element: ";
    cout << float( clock() - time ) / CLOCKS_PER_SEC << endl;

    // Search the largest element 

    int largest = list.front();         // Assign to first element

    time = clock();

    for(std::list<int>::const_iterator iterator = list.begin();
        iterator != list.end(); ++iterator)
    {
        if(*iterator > largest)
            largest = *iterator;
    } 

    cout << "Time searching largest element: ";
    cout << float( clock() - time ) / CLOCKS_PER_SEC << endl;

    // Search the smallest element

    int smallest = list.front();        // Assign to first element

    time = clock();

    for(std::list<int>::const_iterator iterator = list.begin();
        iterator != list.end(); ++iterator)
    {
        if(smallest > *iterator)
            smallest = *iterator;
    }

    cout << "Time searching smallest element: ";
    cout << float( clock() - time ) / CLOCKS_PER_SEC << endl;

//------------------------------------------------------------------

    /*
        Test the performance of std::list by:
        1) Random access to and delete its 1/3th element
        2) Random access to and delete largest element
        3) Delete all elements by clear()
    */

    // Random access to and delete its 1/3th element

    count = 0;                          // Reuse count and set to 0

    time = clock();

    for(std::list<int>::const_iterator iterator = list.begin();
        iterator != list.end(); ++iterator, count++)
    {
        if(count == oneThird) 
        {
            list.erase(iterator);
            break;
        } 
    }

    cout << "Time random access and delete 1/3th element: ";
    cout << float( clock() - time ) / CLOCKS_PER_SEC << endl;

    // Random search and delete largest element

    std::list<int>::const_iterator itrLargest = list.begin();     
                                        // Assign to first element

    time = clock();

    for(std::list<int>::const_iterator iterator = list.begin();
        iterator != list.end(); ++iterator)
    {
        if(*iterator > *itrLargest)
            itrLargest = iterator;
    }

    list.erase(itrLargest);

    cout << "Time random access and delete largest element: ";
    cout << float( clock() - time ) / CLOCKS_PER_SEC << endl;

    // Delete all element by clear()
    
    time = clock();

    list.clear();

    cout << "Time clearing all element: ";
    cout << float( clock() - time ) / CLOCKS_PER_SEC << endl;

    return 0;
}
