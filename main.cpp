#include <iostream>

using namespace std;

void drawGameBoard(char *gameArray);
void inputMove(char *gameArray, string *findIndex, string input, char *playerType);
void switchPlayer(char *playerType);

int main()
{
    char gameArray[9] = {'*', '*', '*', '*', '*', '*', '*', '*', '*'};
    string findIndex[9] = {"a1", "a2", "a3", "b1", "b2", "b3", "c1", "c2", "c3"};
    char playerType = 'X';
    string input;
    bool gameLoop = true;

    while (gameLoop == true)
    {
        drawGameBoard(gameArray);
        cout << playerType << " to move, input cell above (ex) a1" << endl;
        cin >> input;
        inputMove(gameArray, findIndex, input, &playerType);
        switchPlayer(&playerType);
    }
    return 0;
}

void drawGameBoard(char *gameArray)
{
    cout << "  1 2 3" << endl;
    cout << "a " << gameArray[0] << " " << gameArray[1] << " " << gameArray[2] << endl;
    cout << "b " << gameArray[3] << " " << gameArray[4] << " " << gameArray[5] << endl;
    cout << "c " << gameArray[6] << " " << gameArray[7] << " " << gameArray[8] << endl;
}

void inputMove(char *gameArray, string *findIndex, string input, char *playerType)
{
    for (int i = 0; i < 9; i++)
    {
        if (findIndex[i] == input)
        {
            gameArray[i] = *playerType;
            return;
        }
    }
    cout << "please enter a valid input" << endl;
}

void switchPlayer(char *playerType)
{
    if (*playerType == 'X')
    {
        *playerType = 'O';
    }
    else
        *playerType = 'X';
}