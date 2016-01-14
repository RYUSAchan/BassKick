//main.cpp

#include <memory.h>
#include <string>
#include <iostream>
#include <fstream>
#include <vector>

#define MEM_MAX 32768

// BB  >
// KK  <
// B   +
// K   -
// BK  ,
// .   .
// B.  [
// K.  ]

using namespace std;

int main( int argc, char *argv[] )
{
	fstream fs;
	vector< char > code;
	string token;

	if( argc < 2 ) {
		cout << "E.R.R.O.R" << endl;
		cout << "任意のキーで終了";
		getchar();
		return 0;
	}

	fs.open( argv[ 1 ] );
	
	if( !fs ) {
		cout << "E.R.R.O.R." << endl;
		cout << "任意のキーで終了";
		getchar();
		return 0;
	}
	
	while( !fs.eof() ) {
		fs >> token;
		if( token == "BB" ) {
			code.push_back( 1 );
		} else if( token == "KK" ) {
			code.push_back( 2 );
		} else if( token == "B" ) {
			code.push_back( 3 );
		} else if( token == "K" ) {
			code.push_back( 4 );
		} else if( token == "BK" ) {
			code.push_back( 5 );
		} else if( token == "." ) {
			code.push_back( 6 );
		} else if( token == "B." ) {
			code.push_back( 7 );
		} else if( token == "K." ) {
			code.push_back( 8 );
		} else {
			cout << "S.Y.N.T.A.X.E.R.R.O.R." << endl;
			cout << "任意のキーで終了";
			getchar();
			return 0;
		}
	}

	fs.close();

	char* mem = new char[ MEM_MAX ];
	memset( mem, 0, MEM_MAX );
	char* p = mem;

	for( vector< char >::iterator it = code.begin();
		it != code.end(); ++it )
	{
		switch( *it )
		{
		case 1:
			++p;
			break;
		case 2:
			--p;
			break;
		case 3:
			++( *p );
			break;
		case 4:
			--( *p );
			break;
		case 5:
			cin >> *p;
			break;
		case 6:
			cout << *p;
			break;
		case 7:
			if( !( *p ) ) {
				++it;
				for( int t = 1; t; ++it )
				{
					if( ( *it ) == 7 ) { ++t; }
					if( ( *it ) == 8 ) { --t; }
				}
			}
			break;
		case 8:
			if( *p ) {
				--it;
				for( int t = 1; t; --it )
				{
					if( ( *it ) == 7 ) { --t; }
					if( ( *it ) == 8 ) { ++t; }
				}
			}
			break;
		}
	}

	cout << endl << endl;

	delete[] mem;

	cout << "任意のキーで終了";
	getchar();

	return 0;
}