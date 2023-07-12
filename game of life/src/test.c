#include <stdio.h>  
#include <stdlib.h>
#include <unistd.h>
#include <ncurses.h>

#define VERX 80
#define NIZ 25

int count_neighbors(int grid[NIZ][VERX], int row, int col);
void output(int grid[NIZ][VERX]);
void update(int grid[NIZ][VERX]);
int count_neighbors(int grid[NIZ][VERX], int row, int col);

// void output(int grid[NIZ][VERX]){
//     for(int i = 0; i < NIZ; i++){
//         for(int j = 0; j < VERX;j++){
//             printw(grid[i][j] ? "*" : "0");
//         }
//         printw("\n");
//     }
// }

void update(int grid[NIZ][VERX]) {
    int new_grid[NIZ][VERX];

    for (int i = 0; i < NIZ; i++) {
        for (int j = 0; j < VERX; j++) {
            int count = count_neighbors(grid, i, j);

            if (grid[i][j]) {
                new_grid[i][j] = (count == 2 || count == 3);
            } else {
                new_grid[i][j] = (count == 3);
            }
        }
    }

    for (int i = 0; i < NIZ; i++) {
        for (int j = 0; j < VERX; j++) {
            grid[i][j] = new_grid[i][j];
        }
    }
}

int count_neighbors(int grid[NIZ][VERX], int row, int col) {

    int count = 0;

    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            if (i == 0 && j == 0) {
                continue;
            }

            int neighbor_row = (row + i + NIZ) % NIZ;
            int neighbor_col = (col + j + VERX) % VERX;

            count += grid[neighbor_row][neighbor_col];
        }
    }

    return count;
}

int main(){
    initscr();
    halfdelay(2);
    int grid[NIZ][VERX] = {0};
    //char grid2[NIZ][VERX];

    // FILE *file = fopen("file1.txt", "r");
    // for(int i = 0;i < NIZ;i++){
    //     for(int j = 0;j< VERX;j++){
    //         fscanf(file, "%c", &grid2[i][j]);
    //         if(grid2[i][j] == '\n') fscanf(file, "%c", &grid2[i][j]);
    //     }
    // }

    // grid[8][9] = 1;
    // grid[9][10] = 1;
    // grid[10][8] = 1;
    // grid[10][9] = 1;
    // grid[10][10] = 1;

    char q = '0';
    int time = 2;

    while(q != 'q'){
        halfdelay(time);
        q = getch();
        if(q == '-'){
            time += 1;
        }
        if(q == '+'){
            time -= 1;
        }
        clear();
        output(grid);
        update(grid);
    }
    return 0;
}