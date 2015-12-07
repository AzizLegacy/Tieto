#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <stdio.h>
#include <cstdint>
#include <stdint.h>
using namespace std;

/*
 * When the right bound crosses the left bound, all elements to the left of the left bound are less than the pivot, and all elements
 * to the right are greater or equal to the pivot.
 */


int * QuickSort(int *array, int left,  int right)
{
	// [0, 12, 1, 7, 5, 9, 4]
	// [-2, -1, 0, 7, 2, 3, 7]

	if (right - left < 1) //Replaces two ifs below!! :D
		return 0;

	int i = left;
	int j = right;
	int pivot =  (left + right) / 2;

	while (i <= j)
	{
		while(array[i] < array[pivot])
			++i;
		while(array[j] > array[pivot])
			--j;

		if (i <= j)
		{
			swap(array[i], array[j]);
			++i;
			--j;
		}
	};

	//if (left < j)
		QuickSort(array, left, j);
	//if (i < right)
		QuickSort(array, i, right);

	return array;
}

int * QuickSort_2(int *tab, int length)
{
	if ( length < 2)
		return 0;

	int i = 0;
	int j = length - 1;
	int pivot = tab[length / 2];

	while(1)			// lub while( i < j ) i usunąć else'a.
	{
		while (tab[i] < pivot)
			++i;
		while (tab[j] > pivot)
			--j;

		if(i < j)
		{
			swap(tab[j], tab[i]);
			++i;
			--j;
		}
		else
			break;
	}

	QuickSort_2(tab, i);
	QuickSort_2(tab + i, length - i);

	return tab;
}


/*int * QuickSort_3(int *array, int right,  int left = 0)
{
	int i = left;
	int j = right;
	int pivot =  (left + right) / 2;

	while (i <= j)
	{
		while(array[i] < array[pivot])
			++i;
		while(array[j] > array[pivot])
			--j;

		if (i <= j)
		{
			swap(array[i], array[j]);
			++i;
			--j;
		}
	};

	if (left < j)
		QuickSort(array, j);
	if (i < right)
		QuickSort(array, i, right);

	return array;
} */


void Insertion_Sort()
{
	int tab[] = {12, 0, 7, 2, 8};
	int final_tab[6] = {0};

	final_tab[0] = tab[0];

	int element_to_take = 1;
	int end_of_FA = 0;

	while(1)
	{
		if(element_to_take > (sizeof(tab) / sizeof(tab[0])) - 1 )
			break;
		if (tab[element_to_take] > final_tab[end_of_FA])
		{
			final_tab[end_of_FA + 1] = tab[element_to_take];
			++element_to_take;
			++end_of_FA;
		}
		else
		{
			int c = end_of_FA;
			do
			{
				if (element_to_take > (sizeof(tab) / sizeof(tab[0])) - 1)
				{
					break;
				}

				if (c == 0) //If element is the smallest
				{
					final_tab[c + 1] = final_tab[c];
					final_tab[c] = tab[element_to_take];
					++element_to_take;
					++end_of_FA;
					c = end_of_FA;
				}
				else
				{
					final_tab[c + 1] = final_tab[c]; //Przesuń w prawo.
					--c;
				}
			} while (tab[element_to_take] < final_tab[c]);

			final_tab[c + 1] = tab[element_to_take];
			++element_to_take;
			++end_of_FA;
		}

	}
	for( int i = 0; i < sizeof(tab) / sizeof(tab[0]); ++i)
	{
		cout << final_tab[i] << " ";
	}
}


void Insertion_Sort_2()
{
	int tab[] = {12, 0, 7, 2, 8, -4, 20};
	int length_of_array, element_to_take, traversal;

	for( int i = 0; i < sizeof(tab) / sizeof(tab[0]); ++i)
		cout << tab[i] << " "; cout << "\nSorting: " << endl;

	length_of_array = sizeof(tab) / sizeof(tab[0]);

	for( element_to_take = 1; element_to_take < length_of_array; ++element_to_take)
	{
		traversal = element_to_take;

		while( traversal > 0 && tab[traversal] < tab[traversal - 1])
		{
			swap(tab[traversal], tab[traversal-1]);
			--traversal;
		}
	}



	for( int i = 0; i < sizeof(tab) / sizeof(tab[0]); ++i)
	{
		cout << tab[i] << " ";
	}

}

void Selection_Sort()
{
	int tab[] = { 22, 31, -131, 20, -13, 5353, 21, -44, 0};

	int sorted_numbers = 0, length = sizeof(tab) / sizeof(tab[0]);
	int min = tab[0], min_index = 0; bool found = false;

	while(1)
	{
		found = false;
		for(int n = sorted_numbers + 1; n < length; ++n )
		{
			if(tab[n] < min)
			{
				min = tab[n];
				min_index = n; //save index
				found  = true;
			}
		}
		if(found == true)
			swap (tab[min_index], tab[sorted_numbers]);

		++sorted_numbers;

		if(sorted_numbers < length)
			min = tab[sorted_numbers];

		if(sorted_numbers == length)
			break;
	}

	for( int i = 0; i < sizeof(tab) / sizeof(tab[0]); ++i)
	{
		cout << tab[i] << " ";
	}
}

void Selection_Sort_2() //skrócić wersję wyżej.
{
	int tab[] = { 22, 31, -131, 20, -13, 5353, 21, -44, 0};

	int sorted_numbers = 0, length = sizeof(tab) / sizeof(tab[0]);
	int min = tab[0], min_index = 0; bool found;

	while( sorted_numbers < length )
	{
		found = false;
		for(int n = sorted_numbers + 1; n < length; ++n )
		{
			if(tab[n] < min)
			{
				min = tab[n];
				min_index = n; //save index
				found  = true;
			}
		}
		if(found == true)
			swap (tab[min_index], tab[sorted_numbers]);

		++sorted_numbers;

		min = tab[sorted_numbers];
	}

	for( int i = 0; i < sizeof(tab) / sizeof(tab[0]); ++i)
	{
		cout << tab[i] << " ";
	}
}

void pass_array(int *x)
{
	cout << "Sizeof array: " << sizeof(x) / sizeof(x[0]) << endl;
}

void pass_array_2(int x[])
{
	cout << "Sizeof array: " << sizeof(x) / sizeof(x[0]) << endl;
}

void pass_array_3(int x[5])
{
	cout << "Sizeof array: " << sizeof(x) / sizeof(x[0]) << endl;
}

void pass_array_4(int (&x)[5]) //Means this function can take in an array of size 5. You can pass a reference to the actual array itself while maintaing it's sizeof() status.
{
	cout << "Sizeof array: " << sizeof(x) / sizeof(x[0]) << endl;
}

void pass_array_5(int (*x)[5])
{
	cout << "Sizeof array: " << sizeof(x) / sizeof(x[0]) << endl;
	//To access elements you need to do: (*x)[i]
}

void Pass_Array_with_Sizeof_Possible()
{
	cout << endl << endl;
	int tab_2[] = {4, 8, 12, 16, 20};
	pass_array(tab_2);
	pass_array_2(tab_2);
	pass_array_3(tab_2);
	pass_array_4(tab_2);
	//pass_array_5(tab_2); Fix this!!

	/*
	 * I think the decision was for the sake of efficiency. One wouldn't want to do this most of the time. It's the same reasoning as why there are no unsigned doubles.
	 * However, I think a second reason is due to:
	 * the evolution of C from earlier languages like B and BCPL, where arrays were actually implemented as a pointer to the array data
	 *
	 */
}

void QuickSort_Iterative()
{
	/*
	 * The classic quick-sort is done in 5 stages:
    find a 'pivot value'.
    move all values less than (or equal to) the pivot value to 'the left'.
    move all values larger than the pivot to 'the right'.
    quick-sort the values less than(or equal)
    quick-sort the values larger than.
	 */


	int tab[] = {5, 7, 3, 2, 9};
	cout << "Start Array: " << endl;
	for (int x = 0; x < sizeof(tab) / sizeof(tab[0]); ++x)
		cout << tab[x] << " " << endl;


	int length_of_array = sizeof(tab) / sizeof(tab[0]);

	int left = 0, right = length_of_array - 1;


	while(1)
	{

		int pivot = tab[length_of_array / 2];

		while(1)
		{
			while(tab[left] < pivot)
				++left;
			while(tab[right] > pivot)
				--right;
			if(left < right)
			{
				swap (tab[left], tab[right]);
				++left;
				--right;
			}
			else if(left > right)
			{
				break;
			}

		}
	}

	cout << "Final Array: " << endl;
	for (int x = 0; x < sizeof(tab) / sizeof(tab[0]); ++x)
		cout << tab[x] << " " << endl;


}

class Holding_Numbers
{
public:
	int x, y;
	Holding_Numbers () : x(7), y(16) {} ;
};

Holding_Numbers global_object;

void Loop_Optimalizations()
{


	//1. Worse case - performance. Best readability :D
	for(int i = 0; i < global_object.x; ++i)
	{

	}


	//2. Faster, better cache usage
	int a = global_object.x;
	for(int i = 0; i < a; ++i)
	{

	}


	//3.Thanks to having a constant, compiler can load the variable to register(?), and it does not need to compute it every iteration of loop! :)
	const int aa = global_object.x;
	for(int i = 0; i < aa; ++i)
	{

	}


	//4. Rather than counting up to the number of iterations, you want to count down to zero. This means that the number of iterations is only needed
	//once at the start of the loop, it doesn't have to be stored after that. At assembler level it often eliminates the need for an explicit comparison,
	//as the decrement operation will usually set flags that indicate whether the counter was zero both before (carry flag) and after (zero flag)
	//the decrement.
	cout << endl;
	for(int i = global_object.x; i-- > 0; ) //if we had (x > 0; x--), than we wouldn't have gotten 0 number, but 7.
	{
		cout << i << endl;
	}



	cout << endl;
	//5. Same effect as 2., but it keeps variable life only to the loop. :)
	for(int i = 0, n = global_object.x; i < n; ++i)
	{
		cout << i << endl;
	}

}

class Pointer_Class
{

public:
	int a;
	Pointer_Class() : a(7) {};
};

void Save_Memory_Address()
{
	Pointer_Class *object = new Pointer_Class;

	unsigned int address = *(unsigned int*)(void*)&object; //Without long, we cannot cast it without *&

	unsigned long int address_2 = (unsigned long int) (void*) object; //With long, we do not need so much shit :D

	cout <<"Object address: " << object << endl; //Will be in hex, after translating to decimal it will be the same as below.
	cout << address << endl;
	cout << address_2 << endl;

	cout << ( *(Pointer_Class*) address_2).a << endl; //AWESOME!! :D
}

void Save_Memory_Address_2()
{
	unsigned long int address = (long unsigned int) (void*)(new Pointer_Class);
	cout << ( *(Pointer_Class*) address).a << endl;
}

void Save_Memory_Address_3()
{
	Pointer_Class *object = new Pointer_Class;

	union
	{
		Pointer_Class *object;
		unsigned long int address;
	} uniek;

	uniek.object = object;

	cout << ( *(Pointer_Class*) uniek.address).a << endl;
}

int main()
{
	/*vector<int>
	tab_1 {4, 10, 15, 24, 26},
	tab_2 {0, 9, 12, 20},
	tab_3 {5, 18, 22, 30};

	vector<int> array;
	array.insert(array.end(), tab_1.begin(), tab_1.end());
	array.insert(array.end(), tab_2.begin(), tab_2.end());
	array.insert(array.end(), tab_3.begin(), tab_3.end());


	vector<int> array {0, 3, 1, 7, 5, 9, 4};

	for( auto e : array)
	{
		cout << e << " ";
	}cout << endl;

	void QuickSort(vector<int> &array, int right)
								^ Is there a posibilty to pass only second half of a vector?
	*/

	/*
	//int tab[] = {0, 12, 1, 7, 5, 9, 4};
	int *tab = new int[7]; 		tab[0] = 0; tab[1] = 12; tab[2] = 1; tab[3] = 7; tab[4] = 5; tab[5] = 9; tab[6] = 4;
	//int *tab = new int[7]; 		tab[0] = -2; tab[1] = -1; tab[2] = 0; tab[3] = 7; tab[4] = 2; tab[5] = 3; tab[6] = 7;

	//tab = QuickSort(tab, 0, 6);
	//tab = QuickSort_2(tab, 7);

	cout << endl;
	for(int i = 0; i < 7; ++i)
		cout <<  tab[i] << " "; cout << endl;

	 */


	//Insertion_Sort();
	//Insertion_Sort_2();
	//Selection_Sort();
	//Selection_Sort_2();

	//QuickSort_Iterative();

	//Loop_Optimalizations();

	//Save_Memory_Address();
	//Save_Memory_Address_2();
	Save_Memory_Address_3();
	cout << endl << endl << "Bye bye." << endl;
	return 0;
}
