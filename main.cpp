#include <iostream>
#include <string>


void print( void ) {} // for when the parameter pack is empty

template<typename T , typename ...Types>
void print( T t , Types... types )
{
	std::cout << t << "\n";
	print(types...);
}

int main( void )
{
	void( *int_print )( int ) = &print;
	void( *double_print )( double ) = &print;
	void( *multiple_print )( int , double , std::string ) = &print;

	int_print(12);
	double_print(12.2);
	multiple_print( 12 , 17.7 , "Kinda surprised that this actually works");
	
	return 0;
}
