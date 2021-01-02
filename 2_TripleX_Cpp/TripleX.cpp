/*
This example is to give introduction to cpp.
*/

#include <iostream> //Preprocessor Directive (Used before compiling)
                    //Preprocessor Directive(starts with #) doesnot need a semicolon at the end

void PrintIntroduction(int Difficulty){
    std::cout<< "\n\nYou are a secret agent breaking in to a level"<<Difficulty<<std::endl;
    std::cout<< "Enter the secret code to continue"<<std::endl;

}

bool PlayGame(int Difficulty){
    
    PrintIntroduction(Difficulty);

    const int CodeA = rand()%Difficulty+Difficulty;
    const int CodeB = rand()%Difficulty+Difficulty;
    const int CodeC = rand()%Difficulty+Difficulty;

    const int CodeSum = CodeA+CodeB+CodeC;
    const int CodeProduct = CodeA*CodeB*CodeC;

    std::cout <<"There are 3 numbers in the code"<<std::endl;
    std::cout <<"The codes sum up to: " << CodeSum <<std::endl;
    std::cout <<"The codes multiply to: "<<CodeProduct <<std::endl;

    int GuessA,GuessB,GuessC;
    //Enter the Guess
    std::cin>> GuessA >> GuessB >> GuessC;

    int GuessSum = GuessA + GuessB + GuessC;
    int GuessProduct = GuessA * GuessB *GuessC;

    if(GuessSum == CodeSum && GuessProduct == CodeProduct)
    {
        std::cout<<"You win !!!"<<std::endl;
        return true;
    }
    else
    {
        std::cout<<"You lose!"<<std::endl;
        return false;
    }
}

int main()
{   
    int const MaxLevel = 5;

    int LevelDifficulty=1;
    while (LevelDifficulty<=MaxLevel)
    {   
        bool bLevelComplete = PlayGame(LevelDifficulty);
        std::cin.clear();   // Clears any errors
        std::cin.ignore(); //Discards the buffer
        if(bLevelComplete){
            ++LevelDifficulty;
        }
    }
    
    std::cout<<"\n Great Agent !! You cracked the code. Now get out of there !!!"<<std::endl;
    return 0;
}
