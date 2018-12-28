#include <iostream>
#include <string>
#include <vector>

void print( void ) {} // for when the parameter pack is empty

template<typename T , typename ...Types>
void print( T t , Types... types )
{
	std::cout << t << "\n";
	print(types...);
}

template<typename T , typename ...Types> 
void print_vector( std::vector<T> const& v , void(*func)( Types... types ) )
{
	for( auto const& item : v )
		func( item );
}

int main( void )
{
	void( *int_print )( int ) = &print;
	void( *double_print )( double ) = &print;
	void( *multiple_print )( int , double , std::string ) = &print;

	int_print(12);
	double_print(12.2);
	multiple_print( 12 , 17.7 , "Kinda surprised that this actually works" );

	std::cout << "-------\n";
	
	std::vector<int> test_int  = { 1 , 5 , 7 , 9 , 10 };
	print_vector( test_int , int_print );
	
	std::cout << "------\n";
	std::vector<double> test_double = { 1.12 , 3.33 , 64.99 , 87.01 };
	print_vector( test_double , double_print );
	return 0;
}
