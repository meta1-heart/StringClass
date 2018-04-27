
#include "String.h"
#include <ctime>
#include <stdlib.h>
using namespace std;

String& generateStrings( unsigned N, unsigned L )
{
	String* strings = new String[N];
	for ( unsigned i = 0; i < N; i++ )
	{
		unsigned randomLength = rand() % L + 1;
		for ( unsigned j = 0; j<randomLength; j++ )
		{
			unsigned chooser = rand() % 2;
			char c = ( char )( ( chooser * ( rand() % 26 + 97 ) ) + ( ( chooser + 1 ) % 2 ) * ( rand() % 26 + 65 ) );
			strings[i] += c;
		}
	}
	return *strings;
}

void bubbleSort( String* arr, unsigned amount )
{
	String* temp = new String();

	for ( unsigned i = 0; i < amount - 1; ++i )
	{
		for ( unsigned j = 0; j < amount - 1; ++j )
		{
			if ( arr[j + 1] > arr[j] )
			{
				*temp = arr[j + 1];
				arr[j + 1] = arr[j];
				arr[j] = *temp;
			}
		}
	}
	delete temp;
}

void printStrings( String* arr, unsigned amount )
{
	for ( unsigned i = 0; i < amount; ++i )
	{
		cout << i + 1 << ") " << arr[i] << endl;
	}
}

char UI()
{
	char choice;

	cout << endl << endl << " --- String Test --- ";
	cout << endl << endl;
	cout << "(1) Generate strings and sort them" << endl;
	cout << "(0) Exit application" << endl  << endl;
	cout << "Enter a selection: ";

	cin >> choice;
	return choice;
}

void runApp()
{
	srand ( time( 0 ) );
	int N, L;
	cout << endl << "I will generate N random English strings with length from 1 to L" << endl << endl
		<< "Define amount N = ";
	cin >> N;
	if ( N <= 0 ) throw 2;
	cout << endl << endl << "Define maximum length L = ";
	cin >> L;
	if ( L <= 0 ) throw 3;
	String* strings = &generateStrings( N, L );
	cout << endl << "=======================";
	cout << endl << "Initial set of strings:" << endl << endl;
	printStrings(strings, N);
	bubbleSort(strings, N);
	cout << "=======================";
	cout << endl << endl << "Sorted set of strings:" << endl << endl;
	printStrings( strings, N );
	cout << "=======================";
	delete[] strings;
}

int main() {
	bool exit = false;
	char ui;
	do
	{
		ui = UI();
		try
		{
			switch ( ui )
			{
			case '1': runApp(); break;
			case '0': exit = true; break;
			default: cout << endl << "!!! Invalid selection. Should be 1 or 0 !!!"; break;
			}
		}
		catch (int e)
		{
			switch (e)
			{
			case 1 : cout << "Error " << e << ": String element index out of bounds" << endl; break;
			case 2: cout << "Error " << e << ": N must be greater than 0" << endl; break;
			case 3: cout << "Error " << e << ": L must be greater than 0" << endl; break;
			default: cout << "Error " << e << ": Uncaught error" << endl; break;
			}
			
		}
	} while ( !exit );
	return 0;
}
