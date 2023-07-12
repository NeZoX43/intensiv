#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

void check_orientation(int *ball_or_x, int *ball_or_y, int *ball_x, int *ball_y) {
    if (*ball_or_x == 1 && *ball_or_y == 1) {
        *ball_x += 1;
        *ball_y -= 1;
    } else if (*ball_or_x == 0 && *ball_or_y == 0) {
        *ball_x -= 1;
        *ball_y += 1;
    } else if (*ball_or_x == 1 && *ball_or_y == 0) {
        *ball_x += 1;
        *ball_y += 1;
    } else if (*ball_or_x == 0 && *ball_or_y == 1) {
        *ball_x -= 1;
        *ball_y -= 1;
    } else if (*ball_or_x == 2) {
        *ball_x += 1;
    } else if (*ball_or_x == 3) {
        *ball_x -= 1;
    }
}

void wall(int *ball_or_x, int *ball_or_y) {
    if (*ball_or_x == 1 && *ball_or_y == 1) {
        *ball_or_x = 1;
        *ball_or_y = 0;
    } else if (*ball_or_x == 0 && *ball_or_y == 0) {
        *ball_or_x = 0;
        *ball_or_y = 1;
    } else if (*ball_or_x == 1 && *ball_or_y == 0) {
        *ball_or_x = 1;
        *ball_or_y = 1;
    } else if (*ball_or_x == 0 && *ball_or_y == 1) {
        *ball_or_x = 0;
        *ball_or_y = 0;
    }
}

void display(char cmd, int *ball_x, int *ball_y, int *ball_or_x, int *ball_or_y, int *racket_1, int *racket_2,
             int *score_1, int *score_2, int *winner, int *gameover, const int pole_x, const int pole_y) {
    int flag_orientation = 0;
    int score1_1 = *score_1 / 10;
    int score1_2 = *score_1 % 10;
    int score2_1 = *score_2 / 10;
    int score2_2 = *score_2 % 10;

    if (((score1_1 * 10) + score1_2) >= 21) {
        *gameover = 1;
        *winner = 0;
    } else if (((score2_1 * 10) + score2_2) >= 21) {
        *gameover = 1;
        *winner = 1;
    }
    for (int y = 0; y < pole_y; y++) {
        for (int x = 0; x < pole_x; x++) {
            // движение ракеток
            if ((cmd == 'a' || cmd == 'A') && (*racket_1 >= 3)) {
                *racket_1 -= 1;
                cmd = '0';
            } else if ((cmd == 'z' || cmd == 'Z') && (*racket_1 <= 23)) {
                *racket_1 += 1;
                cmd = '0';
            } else if ((cmd == 'k' || cmd == 'K') && (*racket_2 >= 3)) {
                *racket_2 -= 1;
                cmd = '0';
            } else if ((cmd == 'm' || cmd == 'M') && (*racket_2 <= 23)) {
                *racket_2 += 1;
                cmd = '0';
            }
            // zzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzz
            //  мяч
            if (x == *ball_x && y == *ball_y && flag_orientation == 0) {
                if (*ball_y == 1 || *ball_y == 25) {
                    wall(ball_or_x, ball_or_y);
                    check_orientation(ball_or_x, ball_or_y, ball_x, ball_y);
                    printw("o");
                    flag_orientation = 1;
                } else if (*ball_x <= 2) {
                    printw("o");
                    *score_2 += 1;
                    *ball_x = (pole_x - 2) / 2;
                    *ball_y = (pole_y - 1) / 2;
                    *racket_1 = 13;
                    *racket_2 = 13;
                    *ball_or_x = 0;
                    *ball_or_y = 0;
                    flag_orientation = 1;
                } else if (*ball_x >= 80) {
                    printw("o");
                    *score_1 += 1;
                    *ball_x = (pole_x - 2) / 2;
                    *ball_y = (pole_y - 1) / 2;
                    *racket_1 = 13;
                    *racket_2 = 13;
                    *ball_or_x = 1;
                    *ball_or_y = 0;
                    flag_orientation = 1;
                } else if (*ball_x == 8 && (*ball_y <= (*racket_1 + 2) && *ball_y >= (*racket_1 - 2))) {
                    if (*ball_y == (*racket_1 - 1) || *ball_y == (*racket_1 - 2)) {
                        *ball_or_x = 1;
                        *ball_or_y = 1;
                        check_orientation(ball_or_x, ball_or_y, ball_x, ball_y);
                        printw("o");
                        flag_orientation = 1;
                    } else if (*ball_y == *racket_1) {
                        *ball_or_x = 2;
                        check_orientation(ball_or_x, ball_or_y, ball_x, ball_y);
                        printw("o");
                        flag_orientation = 1;
                    } else if (*ball_y == (*racket_1 + 1) || *ball_y == (*racket_1 + 2)) {
                        *ball_or_x = 1;
                        *ball_or_y = 0;
                        check_orientation(ball_or_x, ball_or_y, ball_x, ball_y);
                        printw("o");
                        flag_orientation = 1;
                    }
                } else if (*ball_x == 74 && (*ball_y <= (*racket_2 + 2) && *ball_y >= (*racket_2 - 2))) {
                    if (*ball_y == (*racket_2 - 1) || *ball_y == (*racket_2 - 2)) {
                        *ball_or_x = 0;
                        *ball_or_y = 1;
                        check_orientation(ball_or_x, ball_or_y, ball_x, ball_y);
                        printw("o");
                        flag_orientation = 1;
                    } else if (*ball_y == *racket_2) {
                        *ball_or_x = 3;
                        check_orientation(ball_or_x, ball_or_y, ball_x, ball_y);
                        printw("o");
                        flag_orientation = 1;
                    } else if (*ball_y == (*racket_2 + 1) || *ball_y == (*racket_2 + 2)) {
                        *ball_or_x = 0;
                        *ball_or_y = 0;
                        check_orientation(ball_or_x, ball_or_y, ball_x, ball_y);
                        printw("o");
                        flag_orientation = 1;
                    }
                }

                else {
                    printw("o");
                    check_orientation(ball_or_x, ball_or_y, ball_x, ball_y);
                    flag_orientation = 1;
                }
            }

            else if (x == 34 && y == 3) {
                printw("%d", score1_1);
            } else if (x == 35 && y == 3) {
                printw("%d", score1_2);
            }

            else if (x == 45 && y == 3) {
                printw("%d", score2_1);
            } else if (x == 46 && y == 3) {
                printw("%d", score2_2);
            }

            else if (x == 40 && y % 2 != 0) {
                printw("|");
            }

            // ракетки
            else if ((x == 7) && (y == *racket_1 - 1 || y == *racket_1 || y == *racket_1 + 1)) {
                printw("#");
            } else if ((x == 75) && (y == *racket_2 - 1 || y == *racket_2 || y == *racket_2 + 1)) {
                printw("#");
            }

            // границы по X
            else if (y == 0 || y == 26) {
                printw("-");
            }
            // границы по Y
            else if (x == 0 || x == 81) {
                printw("|");
            }

            // пробелы
            else
                printw(" ");
        }
        printw("\n");
    }
}

int main(void) {
    initscr();
    halfdelay(1);
    srand(time(0));
    // константы
    const int pole_x = 82, pole_y = 27;
    int score_1 = 00, score_2 = 00;

    int gameover = 0;
    int winner = 2;

    // координаты мяч
    int ball_x = (pole_x - 2) / 2, ball_y = (pole_y - 1) / 2;

    // ориентация мяча
    int ball_or_x = 1, ball_or_y = 1;

    // центры ракеток
    int mid_racket_1 = 13, mid_racket_2 = 13;

    // команда
    char cmd = ' ';
    while (!gameover) {
        display(cmd, &ball_x, &ball_y, &ball_or_x, &ball_or_y, &mid_racket_1, &mid_racket_2, &score_1,
                &score_2, &winner, &gameover, pole_x, pole_y);
        if (winner == 0) {
            printf("Победил первый игрок!!! Счёт %d:%d\n", score_1, score_2);
            return 0;
        } else if (winner == 1) {
            printf("Победил второй игрок!!! Счёт %d:%d\n", score_1, score_2);
            return 0;
        }
        cmd = getch();
        clear();
    }

    return 0;
}