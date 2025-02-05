#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAX 15
int board[MAX], count = 1, flag = 0;
void queen(int row, int n);
int place(int row, int column);
void print_board(int n);
int main() {
int n;
char c;
printf("\nN Queens Problem Using Backtracking\n");
printf("\nEnter the number of Queens (1 to %d): ", MAX);
scanf("%d", &n);
// Input validation
if (n < 1 || n > MAX) {
printf("Invalid number of queens. Please enter a number between 1 and %d.\n", MAX);
return 1;
}
printf("\nDo you want to display all solutions? (y/n): ");
scanf(" %c", &c); // Added space before %c to consume any leftover newline character
if (c == 'y' || c == 'Y') {
flag = 1;
}
queen(1, n);
printf("\n\nThe total number of solutions is = %d\n", count - 1);
return 0;
}
// Function to check for proper positioning of queens
void queen(int row, int n) {
int column;
for (column = 1; column <= n; column++) {
if (place(row, column)) { // No conflicts, so place queen
board[row] = column;
if (row == n) {
print_board(n);

} else {
queen(row + 1, n);
}
}
}
}
// Function to check conflicts
int place(int row, int column) {
for (int i = 1; i <= row - 1; i++) {
// Checking column conflicts
if (board[i] == column) {
return 0;
}
// Checking diagonal conflicts
else if (abs(i - row) == abs(board[i] - column)) {
return 0;
}
}
return 1; // No conflicts
}
// Function for printing the solution board
void print_board(int n) {
if (flag == 0 && count > 1) {
count++;
} else {
if (flag == 0 && count == 1) {
printf("\n\nOne Unique Solution is:\n\n");
count++;
} else {
printf("\n\nSolution %d:\n\n", count++);
}
for (int i = 1; i <= n; i++) {
printf("\t%d", i);
}
for (int i = 1; i <= n; i++) {
printf("\n\n%d", i);
for (int j = 1; j <= n; j++) {
if (board[i] == j) {
printf("\tQ%d", i); // Queen at i,j position
} else {
printf("\t-"); // Empty slot
}
}
}
}
}