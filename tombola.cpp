#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

int main()
{
    //First part: tombola card generation
    cout<<"Ciao, questo programma ti permette di giocare a Tombola. Numero massimo di giocatori: 10."<<endl;
    cout<<"Inserisci il numero di giocatori: ";
    int quantity_players;
    cin>>quantity_players;
    cout<<endl;

    int cell[10][3][9]; 
    srand(time(0));     

    for(int i=0; i<quantity_players; i++)
    {

        //Array to track used numbers in each column
        int used_numbers[9];
        for(int c=0; c<9; c++)
            used_numbers[c]=-1;

        for(int row=0; row<3; row++)
        {
            int limit_number=0; // limit of numbers per row

            for(int column=0; column<9; column++)
            {
                
                bool flag=rand()%2;
                if(limit_number>=5) 
                    flag=1;

                switch(column)
                {
                    case 0:
                        if(flag== 1)
                        {
                            cell[i][row][column]=-1;
                        }
                        else
                        {
                            int number;
                            do
                            {
                                number = rand()%9+1;
                            } while(number==used_numbers[column]);

                            cell[i][row][column]=number;
                            used_numbers[column]=number;
                            limit_number++;
                        }
                        break;

                    case 1:
                        if(flag==1)
                        {
                            cell[i][row][column]=-1;
                        }
                        else
                        {
                            int number;
                            do
                            {
                                number=rand()%10+10;
                            } while(number==used_numbers[column]);

                            cell[i][row][column]=number;
                            used_numbers[column]=number;
                            limit_number++;
                        }
                        break;

                    case 2:
                        if(flag==1)
                        {
                            cell[i][row][column]=-1;
                        }
                        else
                        {
                            int number;
                            do
                            {
                                number=rand()%10+20;
                            } while(number==used_numbers[column]);

                            cell[i][row][column]=number;
                            used_numbers[column]=number;
                            limit_number++;
                        }
                        break;

                    case 3:
                        if(flag==1)
                        {
                            cell[i][row][column]=-1;
                        }
                        else
                        {
                            int number;
                            do
                            {
                                number=rand()%10+30;
                            } while(number==used_numbers[column]);

                            cell[i][row][column]=number;
                            used_numbers[column]=number;
                            limit_number++;
                        }   
                        break;

                    case 4:
                        if(flag==1)
                        {
                            cell[i][row][column]=-1;
                        }
                        else
                        {
                            int number;
                            do
                            {
                                number=rand()%10+40;
                            } while(number==used_numbers[column]);

                            cell[i][row][column]=number;
                            used_numbers[column]=number;
                            limit_number++;
                        }
                        break;

                    case 5:
                        if(flag==1)
                        {
                            cell[i][row][column]=-1;
                        }
                        else
                        {
                            int number;
                            do
                            {
                                number=rand()%10+50;
                            } while(number==used_numbers[column]);

                            cell[i][row][column]=number;
                            used_numbers[column]=number;
                            limit_number++;
                        }
                        break;

                    case 6:
                        if(flag==1)
                        {
                            cell[i][row][column]=-1;
                        }
                        else
                        {
                            int number;
                            do
                            {
                                number=rand()%10+60;
                            } while(number==used_numbers[column]);

                            cell[i][row][column]=number;
                            used_numbers[column]=number;
                            limit_number++;
                        }
                        break;

                    case 7:
                        if(flag==1)
                        {
                            cell[i][row][column]=-1;
                        }
                        else
                        {
                            int number;
                            do
                            {
                                number=rand()%10+70;
                            } while(number==used_numbers[column]);

                            cell[i][row][column]=number;
                            used_numbers[column]=number;
                            limit_number++;
                        }
                        break;

                    case 8:
                        if(flag==1)
                        {
                            cell[i][row][column]=-1;
                        }
                        else
                        {
                            int number;
                            do
                            {
                                number=rand()%11+80;
                            } while(number==used_numbers[column]);

                            cell[i][row][column]=number;
                            used_numbers[column]=number;
                            limit_number++;
                        }
                        break;

                    default:
                        cout << "Something went wrong!" << endl;
                        break;
                }

            } // end for column iteration
			
        } // end for row iteration

        cout<<"Scheda del giocatore " <<i+1 <<endl;
        for(int row=0; row< 3; row++)
        {
            cout<<"--------------------------------"<<endl;
            
            for(int col = 0; col < 9; col++)
            {
                if(cell[i][row][col] == -1)
                    cout << "   ";
                else if (cell[i][row][col] < 10 && cell[i][row][col] > 0)
                    cout << cell[i][row][col] << "  ";
                else
                    cout << cell[i][row][col] << " ";
            }
            cout << endl;
        }

        cout << endl;
    } // end for players iteration

    









    return 0;
}
