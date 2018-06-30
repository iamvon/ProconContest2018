#ifndef _COLORS_

#define _COLORS_


/* FOREGROUND */

#define RST  "\x1B[0m"

#define KRED  "\x1B[31m"

#define KGRN  "\x1B[32m"

#define KYEL  "\x1B[33m"

#define KBLU  "\x1B[34m"

#define KMAG  "\x1B[35m"

#define KCYN  "\x1B[36m"

#define KWHT  "\x1B[37m"


#define FRED(x) KRED x RST   // Function use to display red string "x"

#define FGRN(x) KGRN x RST   // Function use to display green string "x"

#define FYEL(x) KYEL x RST   // Function use to display yellow string "x"

#define FBLU(x) KBLU x RST   // Function use to display blue string "x"

#define FMAG(x) KMAG x RST   

#define FCYN(x) KCYN x RST

#define FWHT(x) KWHT x RST


#define BOLD(x) "\x1B[1m" x RST

#define UNDL(x) "\x1B[4m" x RST


#endif  /* _COLORS_ */

#include<iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

#define   M      10
#define   N      10
#define   TURN   10

//  Declare A(A1,A2), B(B1,B2), C(C1,C2), D(D1,D2) coordinates as global variables
int A1 = 1, A2 = 1, B1 = M-2, B2 = N-2, C1 = 1, C2 = N-2, D1 = M-2, D2 = 1;  
// Declare point types as global variables   
int tilePointOne = 0, tilePointTwo = 0, areaPointOne = 0, areaPointTwo = 0, sumOne = 0, sumTwo = 0; 
// Declare a char board saving colors of tiles and position of A,B,C,D at each turn
char stateBoard[M][N]; 

int randomNumber(int minNum, int maxNum) {
   return rand()%(maxNum - minNum + 1) + minNum;
}

// Update A(A1,A2) after receiving user input
void updateA(int playerOneStepA) {
   
   switch (playerOneStepA)
   {
       case 1:
           ++A1, --A2; 
           break;
       case 2:
           ++A1; 
           break;
       case 3:
           ++A1, ++A2; 
           break;
       case 4:
           --A2; 
           break;
       case 5:
           break;
       case 6:
           ++A2; 
           break;
       case 7:
           --A1, --A2; 
           break;
       case 8:
           --A1; 
           break;
       case 9:
           --A1, ++A2; 
           break;                        
   }
}

// Update B(B1,B2) after receiving user input
void updateB(int playerOneStepB) {
   
   switch (playerOneStepB)
   {
       case 1:
           ++B1, --B2; 
           break;
       case 2:
           ++B1; 
           break;
       case 3:
           ++B1, ++B2; 
           break;
       case 4:
           --B2; 
           break;
       case 5:
           break;
       case 6:
           ++B2; 
           break;
       case 7:
           --B1, --B2; 
           break;
       case 8:
           --B1; 
           break;
       case 9:
           --B1, ++B2; 
           break;                        
   }
}

// Update C(C1,C2) after receiving user input
void updateC(int playerTwoStepC) {
   
   switch (playerTwoStepC)
   {
       case 1:
           ++C1, --C2; 
           break;
       case 2:
           ++C1; 
           break;
       case 3:
           ++C1, ++C2; 
           break;
       case 4:
           --C2; 
           break;
       case 5:
           break;
       case 6:
           ++C2; 
           break;
       case 7:
           --C1, --C2; 
           break;
       case 8:
           --C1; 
           break;
       case 9:
           --C1, ++C2; 
           break;                        
   }
}

// Update D(D1,D2) after receiving user input
void updateD(int playerTwoStepD) {
   
   switch (playerTwoStepD)
   {
       case 1:
           ++D1, --D2; 
           break;
       case 2:
           ++D1; 
           break;
       case 3:
           ++D1, ++D2; 
           break;
       case 4:
           --D2; 
           break;
       case 5:
           break;
       case 6:
           ++D2; 
           break;
       case 7:
           --D1, --D2; 
           break;
       case 8:
           --D1; 
           break;
       case 9:
           --D1, ++D2; 
           break;                        
   }
}

// Function use to calculate scores of each team
void calculateScore(int scoreBoard[][N]) {
    tilePointOne = 0, tilePointTwo = 0;
     for(int i = 0; i < M; ++i) {
        for(int j = 0; j < N; ++j) {
            if(stateBoard[i][j] == 'A')  {
               tilePointOne += scoreBoard[i][j];
            //    cout << scoreBoard[i][j] << ' ';
            }
            else if(stateBoard[i][j] == 'C')  {
                tilePointTwo += scoreBoard[i][j];
                // cout << scoreBoard[i][j] << ' ';
            }
            // if(stateBoard[i][j] )
        }
    }
}

//  Y: Red - Z: Blue
void showGameBoard(int scoreBoard[][N]) {  
  for(int j = 0; j < N; ++j) cout << "------";
    cout << endl;
    // cout << endl;
    for(int i = 0; i < M; ++i) {
        for(int j = 0; j < N; ++j) {
            cout << "|  ";
            // Show the game board with "@" for tiles's colors and show position of A,B,C,D
            // Save to the state board 'Y' for red tiles and 'Z' for blue tiles
            if((i == A1 && j == A2) || ((i == A1 && j == A2) && stateBoard[i][j] == 'Y' ))  {
                if(stateBoard[i][j] == 'x')  stateBoard[i][j] = 'Y'; 
                // else if(stateBoard[i][j] == 'C')  stateBoard[i][j] = 'x';
                tilePointOne += scoreBoard[i][j];
                cout <<  FRED("A") << "  ";
            }
            else if((i == B1 && j == B2) || ((i == B1 && j == B2) && stateBoard[i][j] == 'Y'))  {
                if(stateBoard[i][j] == 'x')  stateBoard[i][j] = 'Y'; 
                // else if(stateBoard[i][j] == 'C')  stateBoard[i][j] = 'x';
                tilePointOne += scoreBoard[i][j];
                cout <<  FRED("B") << "  ";
            }
            else if((i == C1 && j == C2) || ((i == C1 && j == C2) && stateBoard[i][j] == 'Z'))  {
                if(stateBoard[i][j] == 'x')  stateBoard[i][j] = 'Z'; 
                // else if(stateBoard[i][j] == 'A')  stateBoard[i][j] = 'x';
                tilePointTwo += scoreBoard[i][j];
                cout <<  FBLU("C") << "  ";
            }
            else if((i == D1 && j == D2) || ((i == D1 && j == D2) && stateBoard[i][j] == 'Z'))  {
                if(stateBoard[i][j] == 'x')  stateBoard[i][j] = 'Z'; 
                // else if(stateBoard[i][j] == 'A')  stateBoard[i][j] = 'x';
                tilePointTwo += scoreBoard[i][j];
                cout <<  FBLU("D") << "  ";
            }
            // Show saved "@" in the state board
            else if(stateBoard[i][j] == 'Y')  cout <<  FRED("@") << "  ";
            else if(stateBoard[i][j] == 'Z')   cout <<  FBLU("@") << "  ";
            // Show the rest of game board with scores without tiles
            else if (scoreBoard[i][j] >= 0 && scoreBoard[i][j] < 10) cout << scoreBoard[i][j] << "  ";
            else cout << scoreBoard[i][j] << " ";
        }
        cout << "|  ";
        cout << endl;
        for(int j = 0; j < N; ++j) cout << "------";
        cout << endl;
        // cout << endl;
    }
    // Scan whole the state board for calculating the scores of each team
    calculateScore(scoreBoard); 
}

int main() {
    srand(time(NULL));
    int scoreBoard[M][N], gameBoard[M][N];
    int quarterBoard[M/2][N/2];
    int row = 0, col = 0;
    int countTurn = 0;
    // Declare user input
    int playerOneStepA = 0, playerOneStepB = 0, playerTwoStepC = 0, playerTwoStepD = 0; 
    // Variables for saving A(A1,A2), B(B1,B2), C(C1,C2), D(D1,D2) to check the conflict
    int saveA1 = 1, saveA2 = 1, saveB1 = M-2, saveB2 = N-2, saveC1 = 1, saveC2 = N-2, saveD1 = M-2, saveD2 = 1;
    areaPointOne = 0, areaPointTwo = 0, sumOne = 0, sumTwo = 0; 
    
    // Generate empty state board
    for(int i = 0; i < M; ++i) {
        for(int j = 0; j < N; ++j) {
            stateBoard[i][j] = 'x';
        }
    }
    // Generate score board
    for(int i = 0; i < M/2; ++i) {
        for(int j = 0; j < N/2; ++j) {
            quarterBoard[i][j] = randomNumber(-5, 20);
        }
    }
    for(int i = 0; i < M/2; ++i) {
        for(int j = 0; j < N/2; ++j) {
            scoreBoard[i][j] = quarterBoard[i][j];
        }
    }
    for(int i = 0; i < M/2; ++i) {
        for(int j = N-1; j >= N/2; --j) {
            scoreBoard[i][j] = quarterBoard[row][col];
            ++col;
        }
        col = 0, ++row;
    }
    row = 0, col = 0;
    for(int i = M-1; i >= M/2; --i) {
        for(int j = 0; j < N/2; ++j) {
            scoreBoard[i][j] = quarterBoard[row][col];
            ++col;
        }
        col = 0, ++row;
    } 
    row = 0, col = 0;
    for(int i = M-1; i >= M/2; --i) {
        for(int j = N-1; j >= N/2; --j) {
            scoreBoard[i][j] = quarterBoard[row][col];
            ++col;
        }
        col = 0, ++row;
    }
    // Initialize the game board as score board
    for(int i = 0; i < M; ++i) {
        for(int j = 0; j < N; ++j) {
            gameBoard[i][j] = scoreBoard[i][j];
        }
    }
    // Calculate the first tile points for each team
    tilePointOne = scoreBoard[A1][A2]+scoreBoard[B1][B2], tilePointTwo = scoreBoard[C1][C2]+scoreBoard[D1][D2];

    // run game
    while(countTurn <= TURN) {
       cout << endl;
       for(int j = 0; j < N; ++j) cout << "         ";
       cout << "TURN " << countTurn << endl;
        
       showGameBoard(gameBoard);          
       cout << "                                                                    tilePointOne: " << tilePointOne << "       tilePointTwo: " << tilePointTwo << endl;
       cout << endl;
     //  Save current positions of 2 agents
       saveA1 = A1, saveA2 = A2, saveB1 = B1, saveB2 = B2, saveC1 = C1, saveC2 = C2, saveD1 = D1, saveD2 = D2;
       cout << "Nhập nước đi tương ứng của A,B,C,D (1,2,3,4,5,6,7,8,9): " << endl;
       cin >> playerOneStepA >> playerOneStepB >> playerTwoStepC >> playerTwoStepD;
       updateA(playerOneStepA), updateB(playerOneStepB), updateC(playerTwoStepC), updateD(playerTwoStepD); 
       
       // Check whether 2 agents move to a same position    
       // If 2 agents move to a same position, remain their current positions
       if(A1 == B1 && A2 == B2)   A1 = saveA1, A2 = saveA2, B1 = saveB1, B2 = saveB2;
       if(A1 == C1 && A2 == C2)   A1 = saveA1, A2 = saveA2, C1 = saveC1, C2 = saveC2;
       if(A1 == D1 && A2 == D2)   A1 = saveA1, A2 = saveA2, D1 = saveD1, D2 = saveD2;
       if(B1 == C1 && B2 == C2)   B1 = saveB1, B2 = saveB2, C1 = saveC1, C2 = saveC2;
       if(B1 == D1 && B2 == D2)   B1 = saveB1, B2 = saveB2, D1 = saveD1, D2 = saveD2;
       if(C1 == D1 && C2 == D2)   C1 = saveC1, C2 = saveC2, D1 = saveD1, D2 = saveD2;

       ++countTurn;
    }

    return 0;
}