#include <iostream>
#include <ctime>
void PrintIntroduction(int Diffiuclty)
{
    //print wlcome massage to the terminal
    std::cout << "\n\nYou are a secret agent breaking into a level "<<Diffiuclty;
    std::cout << " secure server room...\nYou need to enter the correct codes to continud...\n\n";
}

bool PlyaerGame(int Diffiuclty)
{
    PrintIntroduction(Diffiuclty);

    //Declarer three number in code
    const int CodeA = rand() % Diffiuclty+Diffiuclty;
    const int CodeB = rand() % Diffiuclty+Diffiuclty;
    const int CodeC = rand() % Diffiuclty+Diffiuclty;

    const int CodeSum = CodeA + CodeB + CodeC;
    const int CodeProduct = CodeA * CodeB * CodeC;

    //print the sum and product to the terminal

    std::cout << "+There are three number in the code";
    std::cout << "\n+The code add-up to: " << CodeSum;
    std::cout << "\n+The code multiply to give: " << CodeProduct << std::endl;

    //stor plyaer guess
    int GuessA, GuessB, GuessC;
    std::cin >> GuessA >> GuessB >> GuessC;

    std::cout << "You entered: " << GuessA << GuessB << GuessC;
    int GuessSum = GuessA + GuessB + GuessC;
    int GuessProduct = GuessA * GuessB * GuessC;

    //Check if the plyaer guess is correct
    if (GuessSum == CodeSum && GuessProduct == CodeProduct)
    {

        std::cout << "\n*** Well done agen! You have extracted a file! keep going***";
        return true;
    }
    else
    {

        std::cout << "\n***You enter the wronge code!Cunform agen!***";
        return false;
    }
}

int main()
{
    srand(time(NULL));//Creat new randm number sequence based on time of day

    int LevelDiffculty = 1;
    int const MaxDifficulty = 5;

    while (LevelDiffculty<=MaxDifficulty)//loop game until all levels completed
    {
        bool bLevelComplete = PlyaerGame(LevelDiffculty);
     std::cin.clear(); // Clear any errors
     std::cin.ignore();//Discards the buffer

     if (bLevelComplete)
     {
         ++LevelDiffculty;
     }
     
    }
    std::cout<<"\n***YOU WIN THE GAME***";
    return 0;
}