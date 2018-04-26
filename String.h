#ifndef __STRING_H_
#define __STRING_H_

#include <iostream>

class	String
{ 
public:
	///
	unsigned		getLength() const;

	/// ctors/dtor
				String();
				String( char symbol );
				String( const char* symbolArray );
				String( const String& string );
				~String();

	/// index operators
	char			operator[] ( unsigned index ) const;
	char&			operator[] ( unsigned index );

	/// assigment operators
	String&			operator= ( const String& rhs);
	String&			operator+= ( const String& rhs);

	/// catenation operators
	friend			String			operator+ ( const String& lhs, const String& rhs );
	friend			String			operator+ ( const String& lhs, const char*	 rhs );
	friend			String			operator+ ( const String& lhs,		 char	 rhs );
	friend			String			operator+ ( const char*	  lhs, const String& rhs );
	friend			String			operator+ (		  char	  lhs, const String& rhs );

	/// comparators
	friend			bool			operator> ( const String& lhs, const String& rhs );
	friend			bool			operator> ( const String& lhs, const char*	 rhs );
	friend			bool			operator> ( const String& lhs,		 char	 rhs );
	friend			bool			operator> ( const char*	  lhs, const String& rhs );
	friend			bool			operator> (		  char	  lhs, const String& rhs );

	/// input/output operators
	friend			std::ostream&	operator<< ( std::ostream& lhs, const String& rhs);
	friend			std::istream&	operator>> ( std::istream& lhs,		  String& rhs);

private:
	/// symbols in string
	char*			data;

	/// string lenght
	unsigned		length;

};


#endif	// __STRING_H_
