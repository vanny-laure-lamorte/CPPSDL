using namespace std;

#include <iostream>

// Function prototypes
void createGrid(int grille[4][4]);
void displayGrid(int grille[4][4]);


int main(int argc, char const *argv[])
{
    int grid[4][4];

    // Initial Grid
    createGrid(grid); 

    // Display Grid
    displayGrid(grid);

    return 0;
}

void createGrid(int grid[4][4]){
 for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            grid[i][j] = 0; 
        }
    }
}

void displayGrid (int grid[4][4]) {
    cout << "Grille 4x4 :" ; endl

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            cout << grid[i][j] << " "; 
        }
        cout << endl;  
    }

}
