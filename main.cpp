#include <iostream>

using namespace std;

void drawGameBoard(char *gameArray);
bool inputMove(char *gameArray, string *findIndex, string input, char playerType, int size);
bool checkVictory(char *gameArray, char playerType);
bool checkDraw(char *gameArray, int size);

int main()
{
    char gameArray[9] = {'*', '*', '*', '*', '*', '*', '*', '*', '*'};
    string findIndex[9] = {"a1", "a2", "a3", "b1", "b2", "b3", "c1", "c2", "c3"};
    int size = sizeof(findIndex) / sizeof(findIndex[0]);
    char playerType = 'X';
    string input;
    bool gameLoop = true;

    while (gameLoop == true)
    {
        drawGameBoard(gameArray);
        cout << playerType << " to move, input cell above (ex) a1" << endl;
        cin >> input;
        if (inputMove(gameArray, findIndex, input, playerType, size))
        {
            if (checkVictory(gameArray, playerType))
            {
                drawGameBoard(gameArray);
                cout << playerType << " wins" << endl;
                gameLoop = false;
            }
            else if (checkDraw(gameArray, size))
            {
                drawGameBoard(gameArray);
                cout << "draw game" << endl;
                gameLoop = false;
            }
            else
            {
                playerType = (playerType == 'X') ? 'O' : 'X';
            }
        }
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

bool inputMove(char *gameArray, string *findIndex, string input, char playerType, int size)
{
    for (int i = 0; i < size; i++)
    {
        if (findIndex[i] == input)
        {
            if (gameArray[i] == '*')
            {
                gameArray[i] = playerType;
                return true;
            }
        }
    }
    cout << "please enter a valid input" << endl;
    return false;
}

bool checkVictory(char *gameArray, char playerType)
{
    for (int i = 0; i < 3; i++)
    {
        if (gameArray[i * 3] == playerType && gameArray[i * 3 + 1] == playerType && gameArray[i * 3 + 2] == playerType)
            return true;
        if (gameArray[i] == playerType && gameArray[i + 3] == playerType && gameArray[i + 6] == playerType)
            return true;
    }

    if (gameArray[0] == playerType && gameArray[4] == playerType && gameArray[8] == playerType)
        return true;
    if (gameArray[2] == playerType && gameArray[4] == playerType && gameArray[6] == playerType)
        return true;

    return false;
}

bool checkDraw(char *gameArray, int size)
{
    for (int i = 0; i < size; i++)
    {
        if (gameArray[i] == '*')
        {
            return false;
        }
    }
    return true;
}
