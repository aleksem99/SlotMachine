#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

const int REEL_COUNT = 20;
const string symbols[] = {"cherry", "lemon", "orange", "plum", "bell", "bar", "seven", "wild"};
const int SYMBOL_COUNT = 8;

int main()
{
    srand(time(0));

    int reels[REEL_COUNT];
    for (int i = 0; i < REEL_COUNT; i++)
    {
        reels[i] = rand() % SYMBOL_COUNT;
    }

    cout << "Welcome to the Fruit Slot Machine!" << endl;
    cout << "Spinning the reels..." << endl;

    int winnings = 0;
    for (int i = 0; i < REEL_COUNT - 2; i++)
    {
        if (reels[i] == reels[i + 1] && reels[i + 1] == reels[i + 2])
        {
            winnings = 100;
            if (reels[i] == 7)
            {
                winnings = 1000;
            }

            int wildCount = 0;
            for (int j = i; j <= i + 2; j++)
            {
                if (reels[j] == 7)
                {
                    wildCount++;
                }
            }

            if (wildCount == 1)
            {
                winnings *= 2;
            }
            else if (wildCount == 2)
            {
                winnings *= 4;
            }
            else if (wildCount == 3)
            {
                winnings *= 8;
            }

            cout << "You won " << winnings << " coins!" << endl;
            cout << symbols[reels[i]] << " " << symbols[reels[i + 1]] << " " << symbols[reels[i + 2]] << endl;
            break;
        }
    }

    if (winnings == 0)
    {
        cout << "Sorry, better luck next time." << endl;
    }

    return 0;
}