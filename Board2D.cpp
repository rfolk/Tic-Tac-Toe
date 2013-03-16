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
		void		setAt				( int , int , int )	;
		void		setPlayer		( int )							;
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

Board2D::Board2D ( int n , int [] [] )
{

}

/**
	*	isTerminal
	*
	*	This checks to see if the board is completely played.
	*/
bool Board2D::isTerminal ()
{
	int p1 = 0 ;
	int p2 = 0 ;

	//	Check the Diagonal "\"
	for ( int i = 0 ; i < size ; i ++ )
	{
		if ( board [ i ] [ i ] == 1 )
			p1 ++ ;
		else if ( board [ i ] [ i ] == 2 )
			p2 ++ ;
	}
	if ( p1 == size || p2 == size )
		return true ;

	//	Check the Diagonal "/"
	p1 = 0 ;
	p2 = 0 ;
	for ( int i = 0 , j = size - 1 ; i < size ; i ++ , j -- )
	{
		if ( board [ i ] [ i ] == 1 )
			p1 ++ ;
		else if ( board [ i ] [ i ] == 2 )
			p2 ++ ;
	}
	if ( p1 == size || p2 == size )
		return true ;

	//	Check the horizontal
	p1 = 0 ;
	p2 = 0 ;
	for ( int i = 0 ; i < size ; i ++ )
	{
		for ( int j = 0 ; j < size ; j ++ )
		{
			if ( board [ i ] [ j ] == 1 )
				p1 ++ ;
			else if ( board [ i ] [ j ] == 2 )
				p2 ++ ;
		}
		if ( p1 == size || p2 == size )
			return true ;
		else
		{
			p1 = 0 ;
			p2 = 0 ;
		}
	}

	//	Check the vertical
	p1 = 0 ;
	p2 = 0 ;
	for ( int i = 0 ; i < size ; i ++ )
	{
		for ( int j = 0 ; j < size ; j ++ )
		{
			if ( board [ j ] [ i ] == 1 )
				p1 ++ ;
			else if ( board [ j ] [ i ] == 2 )
				p2 ++ ;
		}
		if ( p1 == size || p2 == size )
			return true ;
		else
		{
			p1 = 0 ;
			p2 = 0 ;
		}
	}

	//	All spaces are full
	for ( int i = 0 ; i < size ; i ++ )
		for ( int j = 0 ; j < size ; j ++ )
			if ( board [ i ] [ j ] == 0 )
				return false ;

	//	The board is full
	return true ;
}

/**
	*	getPlayer
	*
	*	Get the current player.
	*
	*	@return	player	1 or 2
	*/
int Board2D::setPlayer ( int p )
{
	return player ;
}

/**
	*	getSize
	*
	*	Get the size of the board.
	*
	*	@return	board size (n x n)
	*/
int Board2D::getSize ()
{
	return size ;
}

/**
	*	setPlayer
	*
	*	Set the player to the given value p.
	*
	*	@param	p		player	1 or 2
	*/
void Board2D::setPlayer ( int p )
{
	player = p ;
}

/**
	*	setSize
	*
	*	Set the size of the board to the given value n.
	*
	*	@param	n		board size (n x n)
	*/
void Board2D::setSize ( int n )
{
	size = n ;
}