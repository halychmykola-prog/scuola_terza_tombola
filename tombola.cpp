#include <iostream>
#include <ctime>
#include <cstdlib>
#include <unistd.h>

using namespace std;

int main()
{
 

    cout << "Ciao, questo programma ti permette di giocare a Tombola." << endl;

    int cell[2][3][9];
    srand(time(0));


    for(int i = 0; i < 2; i++)
    {
        int used_numbers[9];
        for(int c = 0; c < 9; c++)
            used_numbers[c] = -1;

        for(int row = 0; row < 3; row++)
        {
            
            bool selected[9] = {false};
            int chosen = 0;

            while(chosen < 5)
            {
                int col = rand() % 9;
                if(!selected[col])
                {
                    selected[col] = true;
                    chosen++;
                }
            }

         
            for(int column = 0; column < 9; column++)
            {
                if(!selected[column])
                {
                    cell[i][row][column] = -1;
                    continue;
                }

                int number;
                do
                {
                    switch(column)
                    {
                        case 0: number = rand() % 9 + 1; break;
                        case 1: number = rand() % 10 + 10; break;
                        case 2: number = rand() % 10 + 20; break;
                        case 3: number = rand() % 10 + 30; break;
                        case 4: number = rand() % 10 + 40; break;
                        case 5: number = rand() % 10 + 50; break;
                        case 6: number = rand() % 10 + 60; break;
                        case 7: number = rand() % 10 + 70; break;
                        case 8: number = rand() % 11 + 80; break;
                    }
                } while(number == used_numbers[column]);

                cell[i][row][column] = number;
                used_numbers[column] = number;
            }
        }

        
        cout << "Scheda del giocatore " << i + 1 << endl;
        for(int row = 0; row < 3; row++)
        {
            cout << "------------------------------" << endl;
            for(int col = 0; col < 9; col++)
            {
                if(cell[i][row][col] == -1)
                    cout << "   ";
                else if(cell[i][row][col] < 10)
                    cout << cell[i][row][col] << "  ";
                else
                    cout << cell[i][row][col] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }

   
    int count_numbers[2] = {0};

    for(int i = 0; i < 2; i++)
        for(int row = 0; row < 3; row++)
            for(int col = 0; col < 9; col++)
                if(cell[i][row][col] != -1)
                    count_numbers[i]++;

   
    cout << "Are you ready to start the game? (y/n): ";
    char ready;
    cin >> ready;

    if(ready != 'y' && ready != 'Y')
    {
        cout << "Gioco finito" << endl;
        return 0;
    }

    int extracted_numbers[90] = {0};
    bool winner_found = true;
    int winner_player = -1;

    while(winner_found)
    {
        int randnumber = rand() % 90 + 1;
        if(extracted_numbers[randnumber - 1] != 0)
            continue;

        extracted_numbers[randnumber - 1] = randnumber;
        cout << "Numero estratto: " << randnumber << endl << endl;

        for(int i = 0; i < 2; i++)
        {
            for(int row = 0; row < 3; row++)
            {
                for(int col = 0; col < 9; col++)
                {
                    if(cell[i][row][col] == randnumber)
                    {
                        cell[i][row][col] = 0;
                        count_numbers[i]--;

                        if(count_numbers[i] == 0)
                        {
                            winner_found = false;
                            winner_player = i + 1;
                        }
                    }
                }
            }
        }

      
        for(int i = 0; i < 2; i++)
        {
            cout << "Scheda del giocatore " << i + 1 << endl;
            for(int row = 0; row < 3; row++)
            {
                cout << "------------------------------" << endl;
                for(int col = 0; col < 9; col++)
                {
                    if(cell[i][row][col] == -1)
                        cout << "   ";
                    else if(cell[i][row][col] == 0)
                        cout << " X ";
                    else if(cell[i][row][col] < 10)
                        cout << cell[i][row][col] << "  ";
                    else
                        cout << cell[i][row][col] << " ";
                }
                cout << endl;
            }
            cout << endl;
        }

        sleep(3);
    }

    cout << "Complimenti al giocatore " << winner_player << " che ha fatto tombola!" << endl;
    return 0;
}
	
