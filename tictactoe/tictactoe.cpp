
#include <iostream>

using namespace std;

void make_move( char board[ 3 ][ 3 ], bool turn, char &player );
void draw_board( char board[ 3 ][ 3 ] );
void check_win( char board[ 3 ][ 3 ], int &winner );
void clear_board( char board[ 3 ][ 3 ] );

int main()
{
    char board[ 3 ][ 3 ] = { 0 };
    char player = 0;
    bool turn = 1;
    int winner = 0;
    char replay = 'y';

    while ( replay == 'y' )
    {
        winner = 0;
        turn = 1;
        player = 0;
        clear_board( board );
        draw_board( board );

        while ( !winner )
        {
            turn = !turn;
            make_move( board, turn, player );
            draw_board( board );
            check_win( board, winner );
        }

        if ( winner == 1 )
        {
            cout << "Congrats, Player " << player << "! You've won!!" << endl;
            cout << "Would you like to play again? y/n: ";
            cin >> replay;
        }
        else
        {
            cout << "Better luck next time! It was a tie!" << endl;
            cout << "Would you like to play again? y/n: ";
            cin >> replay;
        }
    }

    return 0;
}

void make_move( char board[ 3 ][ 3 ], bool turn, char &player )
{
    int row, col;

    if ( !turn )
    {
        player = 'X';
    }
    else
    {
        player = 'O';
    }

    cout << "Player " << player << ", Please enter your row: ";
    cin >> row;
    cout << "Player " << player << ", Please enter your column: ";
    cin >> col;

    row -= 1;
    col -= 1;

    while ( board[ row ][ col ] == 'X' || board[ row ][ col ] == 'O' )
    {
        cout << "Coordinate taken. Please choose new coordinates." << endl;

        cout << "Player " << player << ", Please enter your row: ";
        cin >> row;
        cout << "Player " << player << ", Please enter your column: ";
        cin >> col;

        row -= 1;
        col -= 1;
    }

    board[ row ][ col ] = player;
}

void draw_board( char board[ 3 ][ 3 ] )
{
    int r, c;

    system( "cls" );

    cout << endl;
    cout << "    1   2   3" << endl;

    for ( r = 0; r < 3; r++ )
    {
        cout << " ";
        for ( c = 0; c < 3; c++ )
        {
            if ( c == 0 )
            {
                cout << " " << r + 1 << " ";
            }

            cout << board[ r ][ c ];

            if ( c < 2 )
            {
                cout << " | ";
            }
        }
        if ( r < 2 )
        {
            cout << endl << " " << "  -----------" << endl;
        }
    }

    cout << endl << endl;

}
void check_win( char board[ 3 ][ 3 ], int & winner )
{
    if (    ( board[ 0 ][ 0 ] == 'X' && board[ 0 ][ 1 ] == 'X' && board[ 0 ][ 2 ] == 'X' )
         || ( board[ 1 ][ 0 ] == 'X' && board[ 1 ][ 1 ] == 'X' && board[ 1 ][ 2 ] == 'X' )
         || ( board[ 2 ][ 0 ] == 'X' && board[ 2 ][ 1 ] == 'X' && board[ 2 ][ 2 ] == 'X' )
         || ( board[ 0 ][ 0 ] == 'X' && board[ 1 ][ 0 ] == 'X' && board[ 2 ][ 0 ] == 'X' )
         || ( board[ 0 ][ 1 ] == 'X' && board[ 1 ][ 1 ] == 'X' && board[ 2 ][ 1 ] == 'X' )
         || ( board[ 0 ][ 2 ] == 'X' && board[ 1 ][ 2 ] == 'X' && board[ 2 ][ 2 ] == 'X' )
         || ( board[ 0 ][ 0 ] == 'X' && board[ 1 ][ 1 ] == 'X' && board[ 2 ][ 2 ] == 'X' )
         || ( board[ 0 ][ 2 ] == 'X' && board[ 1 ][ 1 ] == 'X' && board[ 2 ][ 0 ] == 'X' )
         || ( board[ 0 ][ 0 ] == 'O' && board[ 0 ][ 1 ] == 'O' && board[ 0 ][ 2 ] == 'O' )
         || ( board[ 1 ][ 0 ] == 'O' && board[ 1 ][ 1 ] == 'O' && board[ 1 ][ 2 ] == 'O' )
         || ( board[ 2 ][ 0 ] == 'O' && board[ 2 ][ 1 ] == 'O' && board[ 2 ][ 2 ] == 'O' )
         || ( board[ 0 ][ 0 ] == 'O' && board[ 1 ][ 0 ] == 'O' && board[ 2 ][ 0 ] == 'O' )
         || ( board[ 0 ][ 1 ] == 'O' && board[ 1 ][ 1 ] == 'O' && board[ 2 ][ 1 ] == 'O' )
         || ( board[ 0 ][ 2 ] == 'O' && board[ 1 ][ 2 ] == 'O' && board[ 2 ][ 2 ] == 'O' )
         || ( board[ 0 ][ 0 ] == 'O' && board[ 1 ][ 1 ] == 'O' && board[ 2 ][ 2 ] == 'O' )
         || ( board[ 0 ][ 2 ] == 'O' && board[ 1 ][ 1 ] == 'O' && board[ 2 ][ 0 ] == 'O' )
         )
    {
        winner = 1;
    }
    else if (    ( board[ 0 ][ 0 ] == 'X' || board[ 0 ][ 0 ] == 'O' )
              && ( board[ 0 ][ 1 ] == 'X' || board[ 0 ][ 1 ] == 'O' )
              && ( board[ 0 ][ 2 ] == 'X' || board[ 0 ][ 2 ] == 'O' )
              && ( board[ 1 ][ 0 ] == 'X' || board[ 1 ][ 0 ] == 'O' )
              && ( board[ 1 ][ 1 ] == 'X' || board[ 1 ][ 1 ] == 'O' )
              && ( board[ 1 ][ 2 ] == 'X' || board[ 1 ][ 2 ] == 'O' )
              && ( board[ 2 ][ 0 ] == 'X' || board[ 2 ][ 0 ] == 'O' )
              && ( board[ 2 ][ 1 ] == 'X' || board[ 2 ][ 1 ] == 'O' )
              && ( board[ 2 ][ 2 ] == 'X' || board[ 2 ][ 2 ] == 'O' )
              )
    {
        winner = 2;
    }
    else
    {
        winner = 0;
    }
}

void clear_board( char board[ 3 ][ 3 ] )
{
    int r, c;

    for ( r = 0; r < 3; r++ )
    {
        for ( c = 0; c < 3; c++ )
        {
            board[ r ][ c ] = 0;
        }
    }
}