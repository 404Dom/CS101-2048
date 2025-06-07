#include <iostream>
#include <random>
#include <iomanip>
using namespace std;

// moves everything to the left, combines adj tiles
void move_left(int board[][5], int numrows = 5)
{
    const int BLANK = 0;
    for (int r = 0; r < numrows; r++)
    {
        int current = 0;
        int free_loc = 0;
        // shifting begins
        while (current < 5)
        {
            if (board[r][current] == BLANK)
            {
                current++;      // if blank, move on
            }
            else
            {
                // moves non-BLANK elements to the front
                board[r][free_loc] = board[r][current];
                if (current != free_loc)
                {
                    board[r][current] = BLANK;  // clear old spot
                }
                current++;
                free_loc++;
            }

            // if two of the same numbers are detectd, merge
            if (current < 5 && free_loc > 0 && board[r][current] != BLANK && board[r][current] == board[r][free_loc - 1])
            {
                board[r][free_loc - 1] *= 2;    // double
                board[r][current] = BLANK;      // clear the merged
                current++;  // move on
            }
        }

        // Fill the remaining cells with blanks (0)
        for (int c = free_loc; c < 5; c++)
            board[r][c] = BLANK;
    }
}

// moves everything to the right, combines adj tiles
void move_right(int board[][5], int numrows = 5)
{
    const int BLANK = 0;
    for (int r = 0; r < numrows; r++)
    {
        int current = 4;
        int free_loc = 4;
        // same as left but backwards
        while (current >= 0)
        {
            if (board[r][current] == BLANK)
            {
                current--;      // if blank, move on
            }
            else
            {
                board[r][free_loc] = board[r][current];
                if (current != free_loc)
                {
                    board[r][current] = BLANK;      // clears old spot
                }
                current--;
                free_loc--;

                // if two of the same numbers are detected, merge
                if (current >= 0 && board[r][current] == board[r][free_loc + 1])
                {
                    board[r][free_loc + 1] *= 2;    // double
                    board[r][current] = BLANK;      // clear the merged
                    current--;  // move on
                }
            }
        }
        // fills in the blanks at the end
        for (int c = free_loc; c >= 0; c--)
            board[r][c] = BLANK;
    }
}

// moves everything up, combines adj tiles
void move_up(int board[][5], int numrows = 5)
{
    const int BLANK = 0;
    for (int c = 0; c < 5; c++)
    {
        int current = 0;
        int free_loc = 0;

        while (current < numrows)
        {
            if (board[current][c] == BLANK)
            {
                current++;      // skip blanks
            }
            else
            {
                board[free_loc][c] = board[current][c];
                if (current != free_loc)
                {
                    board[current][c] = BLANK;      // clears old spot
                }
                current++;
                free_loc++;
                // merge if match found
                if (current < numrows && board[current][c] == board[free_loc - 1][c])
                {
                    board[free_loc - 1][c] *= 2;        // doubles
                    board[current][c] = BLANK;      // clears merged
                    current++;      // move on
                }
            }
        }
        // fills rest of column with BLANK
        for (int r = free_loc; r < numrows; r++)
            board[r][c] = BLANK;
    }
}

// moves everything down, combines adj tiles
void move_down(int board[][5], int numrows = 5)
{
    const int BLANK = 0;
    for (int c = 0; c < 5; c++)
    {
        int current = numrows - 1;
        int free_loc = numrows - 1;

        while (current >= 0)
        {
            if (board[current][c] == BLANK)
            {
                current--;      // skip blanks
            }
            else
            {
                board[free_loc][c] = board[current][c];
                if (current != free_loc)
                {
                    board[current][c] = BLANK;      // clear old spot
                }
                current--;
                free_loc--;
                // merge if match found above
                if (current >= 0 && board[current][c] == board[free_loc + 1][c])
                {
                    board[free_loc + 1][c] *= 2;        // doubles
                    board[current][c] = BLANK;      // clears merged
                    current--;      // moves on
                }
            }
        }
        // fills rest of column with BLANKs
        for (int r = free_loc; r >= 0; r--)
            board[r][c] = BLANK;
    }
}

void print_board(int board[][5], int numrows = 5)
{
    cout << endl << "\t-----------------------------------------" << endl;

    for (int r = 0; r < numrows; r++)
    {
        for (int c = 0; c < 5; c++)
        {
            if (board[r][c] > 0)
                cout << "\t|" << right << setw(6) << setfill(' ') << board[r][c];
            else
                cout << "\t|" << right << setw(6) << setfill(' ') << " ";

            //cout << board[r][c] << "\t|\t";
        }
        cout << "\t|" << endl;
        cout << "\t-----------------------------------------" << endl;
    }

    cout << "\t" << endl << endl;
}


void insert_random(int board[][5], int numrows = 5)
{
    int r, c;
    //count empty
    int empty_count = 0;
    for (int r = 0; r < numrows; r++)
    {
        for (int c = 0; c < 5; c++)
        {
            if (board[r][c] == 0)
                empty_count++;
        }
    }

    if (empty_count > 0)
    {
        while (true)
        {
            //generate random location r, c
            r = rand() % numrows;
            c = rand() % numrows;
            //check if empty
            if (board[r][c] == 0)
            {
                //add number randomly {2,4}
                board[r][c] = 2 * (1 + (rand() % 2));
                break;
            }
        }

    }
}

