/**
	*	Two Dimensional Board for Tic-Tac-Toe
	*
	*	This board will function as the states for a single board instance of Tic-
	*	Tac-Toe.
	*/


#include <iostream>

using namespace std ;

class Board2D
{
	private:
		int		size ;		//	size of the board
		int		player ;	//	player number, 1 or 2, 0 for none
		int	*	board ;		//	the board itself

	public:
		Board2D		() 									;
		Board2D		( int )							;
		Board2D		( int , int [] [] )	;
		~Board2D	()									;

		bool		isEqual			( Board2D )					;
		bool		isTerminal	()									;
		int			getPlayer		() 									;
		int			getSize			()									;
		float		utility			()									;
		vector	action			()									;
		Board2D	copy				()									;
		Board2D	result			( int , int , int )	;
		void		setPlayer		( int )							;
		void		setAt				( int , int , int )	;
		void		setSize			( int )							;
} ;


/**
	*	Board2D
	*
	*	Creates a new 3x3 Tic-Tac-Toe board for play.
	*
	*	NEED TO VERIFY THAT A CONSTRUCTOR CAN CALL A CONSTRUCTOR
	*/
Board2D::Board2D ()
{
	Board2D ( 3 ) ;
}

/**
	*	Board2D
	*
	*	Creates a new nxn Tic-Tac-Toe board for play. Initializes the board for
	*	player 1.
	*
	*	NEED TO VERIFY HOW TO DO A MULTI DIMENSIONAL ARRAY. I KNOW IT WILL INVOLVE
	*	POINTERS.
	*/
Board2D::Board2D ( int n )
{
	setSize 	( n ) ;
	setPlayer ( 1 ) ;
	int [ n ] [ n ] b = 0 ;
	board = b ;
}