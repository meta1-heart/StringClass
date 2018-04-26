
#include "String.h"

String::String()
{
	length = 0;
	data = new char[0];
}

String::String( char symbol )
{
	length = 1;
	data = new char( symbol );
}

String::String( const char* symbolArray )
{
	if ( symbolArray )
	{
		unsigned n = 0;
		//
		while ( symbolArray[n] != '\0' ) n++;
		length = n;
		data = new char[n];
		//
		for ( unsigned i = 0; i < n; i++ )
			data[i] = symbolArray[i];
	} else
	{
		length = 0;
		data = new char[0];
	}
}

String::String( const String& string )
{
	length = string.getLength();
	data = new char[length];
	//
	for ( unsigned i = 0; i < length; i++ )
		data[i] = string[i];
}

String::~String()
{
	delete[] data;
}

unsigned String::getLength() const
{
	return length;
}

char String::operator[] ( unsigned index ) const
{
	if ( index > length ) throw 1;
	return data[index];
}

char& String::operator[] ( unsigned index )
{
	if ( index > length ) throw 1;
	return data[index];
}

String& String::operator= ( const String& rhs )
{
	if ( this == &rhs ) return *this;
	delete[] data;
	length = rhs.getLength();
	data = new char[length];
	//
	for ( unsigned i = 0; i < length; i++ )
		data[i] = rhs[i];
	return *this;
}

String& String::operator+= ( const String& rhs )
{
	unsigned lengthSum = length + rhs.getLength();
	char* newString = new char[lengthSum];
	//
	for ( unsigned i = 0; i < length; i++ )
		newString[i] = data[i];
	//
	for ( unsigned i = 0; i < rhs.getLength(); i++ )
		newString[length + i] = rhs[i];
	delete data;
	length = lengthSum;
	data = newString;
	return *this;
}

String operator+ ( const String& lhs, const String& rhs )
{
	return String( lhs ) += rhs;
}

String operator+ ( const String& lhs, char rhs)
{
	return String( lhs ) += String( rhs );
}

String operator+ ( const String& lhs, const char* rhs)
{
	return String (lhs) += String(rhs);
}

String operator+ ( char lhs, const String& rhs)
{
	return String( lhs ) += rhs;
}

String operator+ ( const char* lhs, const String& rhs)
{
	return String( lhs ) += rhs;
}

bool operator> ( const String& lhs, const String& rhs )
{
	unsigned minLength = ( lhs.getLength() < rhs.getLength() ) ? 
		lhs.getLength() : rhs.getLength();
	unsigned n = 0;
	//
	while ( n < minLength )
	{
		if ( lhs[n] == rhs[n] )
		{
			n++;
			continue;
		}
		else if ( ( 'A' <= lhs[n] && lhs[n] <= 'Z' || 'a' <= lhs[n] && lhs[n] <= 'z' ) &&
			  ( 'A' <= rhs[n] && rhs[n] <= 'Z' || 'a' <= rhs[n] && rhs[n] <= 'z' ) )
		{
			char lhsChar = ( lhs[n] & ~32 );
			char rhsChar = ( rhs[n] & ~32 );
			//
			if ( lhsChar != rhsChar )
			{
				return lhsChar > rhsChar;
			}
			else
			{
				n++;
				continue;
			}
		}
		break;
	}
	return lhs[n] > rhs[n];
}

bool operator> ( const String& lhs, char rhs )
{
	return lhs > String(rhs);
}

bool operator> ( const String& lhs, const char* rhs )
{
	return lhs > String( rhs );
}

bool operator> ( char lhs, const String& rhs )
{
	return String( lhs ) > rhs;
}

bool operator> ( const char* lhs, const String& rhs )
{
	return String( lhs ) > rhs;
}

std::ostream& operator<< ( std::ostream& lhs, const String& rhs )
{
	if ( rhs.getLength() > 0 )
	{
		for ( unsigned i = 0; i < rhs.getLength(); i++ )
			lhs << rhs[i];
	}
	else
	{
		lhs << "";
	}
	return lhs;
}

std::istream& operator>> ( std::istream& lhs, String& rhs )
{
	char* newString = new char[1000];
	lhs >> newString;
	rhs = String( newString );
	delete[] newString;
	return lhs;
}
