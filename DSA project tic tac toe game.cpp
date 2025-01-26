#include <iostream>
#include <string>
using namespace std;
//ARZOO NAVEED
//MOMINA HAROON
// Define the TreeNode structure
struct TreeNode {
    char board[3][3]; // Stores the state of the Tic-Tac-Toe board
    TreeNode* left;   // Pointer to the left child
    TreeNode* right;  // Pointer to the right child
    TreeNode(char b[3][3]) {
    for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
    board[i][j] = b[i][j];}}
    left = NULL;
    right = NULL;}};
// Function Prototypes
string PlayerInputWithTree(char Ttt[][3], string*, string*, TreeNode*&);
string Winner(char Ttt[][3], string, string);
void Display(string*, string, string);
TreeNode* insert(TreeNode* root, char newBoard[3][3]);
void printTree(TreeNode* root);
int main() {
    char Ttt[3][3]{
    {'-', '-', '-'},
    {'-', '-', '-'},
    {'-', '-', '-'}};
    string Plyr1;
    string Plyr2;
    TreeNode* root = NULL; // Root of the tree
    cout << "\t\t\t\t     ***  TIC - TAC - TOE  ***\n\n";
    cout << "\t\t\t\t        Welcome to our Game\n\n";
    // Player information
    cout << "Enter player 1 name : ";
    getline(cin, Plyr1);
    cout << "Enter player 2 name : ";
    getline(cin, Plyr2);
    // Input Location format
    cout << "\nChoose following format to enter input\n\n";
    cout << " 1 | 2 | 3 " << endl;
    cout << " 4 | 5 | 6 " << endl;
    cout << " 7 | 8 | 9 " << endl << endl;
    // Input
    string winner = PlayerInputWithTree(Ttt, &Plyr1, &Plyr2, root);
    // Output
    Display(&winner, Plyr1, Plyr2);
    // Display all game states stored in the tree
    cout << "\nAll Game States:\n";
    printTree(root);}
    string PlayerInputWithTree(char Ttt[][3], string* P1, string* P2, TreeNode*& root) {
    string p1, p2;
    char ReptValu[10]{};
    string Win;
    for (int i = 0; i < 5; i++) {
    // Player 1 Input
    cout << *P1 << " turn : ";
    do {cin >> p1;
    if (p1.length() == 1 && p1[0] >= '1' && p1[0] <= '9' && p1[0] != ReptValu[0] && p1[0] != ReptValu[1] &&
    p1[0] != ReptValu[2] && p1[0] != ReptValu[3] && p1[0] != ReptValu[4] && p1[0] != ReptValu[5] &&
    p1[0] != ReptValu[6] && p1[0] != ReptValu[7] && p1[0] != ReptValu[8]) {
    break;
    } else {
    cout << "\nInvalid or occupied position. Try again: ";}
    } while (true);
    // Update the board for Player 1
    int pos = p1[0] - '1';
    Ttt[pos / 3][pos % 3] = 'X';
    // Insert the updated board into the tree
    root = insert(root, Ttt);
    // Check for a winner
    Win = Winner(Ttt, *P1, *P2);
    // Display the board
    for (int row = 0; row < 3; row++) {
    for (int col = 0; col < 3; col++) {
    cout << " " << Ttt[row][col];
    if (col < 2) cout << " |";}
    cout << endl;}
    cout << "\n";
    if (Win == *P1 || Win == *P2) break; // End game if there's a winner
    ReptValu[i] = p1[0];
    if (i == 4) { // No more moves possible
    Win = "Draw";
    break;}
    // Player 2 Input
    cout << *P2 << " turn : ";
    do {
    cin >> p2;
    if (p2.length() == 1 && p2[0] >= '1' && p2[0] <= '9' && p2[0] != ReptValu[0] && p2[0] != ReptValu[1] &&
    p2[0] != ReptValu[2] && p2[0] != ReptValu[3] && p2[0] != ReptValu[4] && p2[0] != ReptValu[5] &&
    p2[0] != ReptValu[6] && p2[0] != ReptValu[7] && p2[0] != ReptValu[8]) {
    break;} else {
    cout << "\nInvalid or occupied position. Try again: ";}
    } while (true);
    // Update the board for Player 2
    pos = p2[0] - '1';
    Ttt[pos / 3][pos % 3] = 'O';
    // Insert the updated board into the tree
    root = insert(root, Ttt);
    // Check for a winner
    Win = Winner(Ttt, *P1, *P2);
    // Display the board
    for (int row = 0; row < 3; row++) {
    for (int col = 0; col < 3; col++) {
    cout << " " << Ttt[row][col];
    if (col < 2) cout << " |";}
    cout << endl;}
    cout << "\n";
    if (Win == *P1 || Win == *P2) break; // End game if there's a winner
    ReptValu[i + 5] = p2[0];}
    return Win;}
    TreeNode* insert(TreeNode* root, char newBoard[3][3]) {
    if (!root) {
    return new TreeNode(newBoard);}
    // Insert logic can be improved to handle specific scenarios
    if (!root->left) {
    root->left = new TreeNode(newBoard);} else {
    root->right = new TreeNode(newBoard);}
    return root;}
    void printTree(TreeNode* root) {
    if (!root) return;
    for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
    cout << root->board[i][j] << " ";}
    cout << endl;}
    cout << "-----\n";
    printTree(root->left);
    printTree(root->right);}
    string Winner(char Ttt[][3], string P1, string P2) {
    // Check rows, columns, and diagonals for a winner
    for (int i = 0; i < 3; i++) {
    if (Ttt[i][0] == Ttt[i][1] && Ttt[i][1] == Ttt[i][2] && Ttt[i][0] != '-') return (Ttt[i][0] == 'X') ? P1 : P2;
    if (Ttt[0][i] == Ttt[1][i] && Ttt[1][i] == Ttt[2][i] && Ttt[0][i] != '-') return (Ttt[0][i] == 'X') ? P1 : P2;}
    if (Ttt[0][0] == Ttt[1][1] && Ttt[1][1] == Ttt[2][2] && Ttt[0][0] != '-') return (Ttt[0][0] == 'X') ? P1 : P2;
    if (Ttt[0][2] == Ttt[1][1] && Ttt[1][1] == Ttt[2][0] && Ttt[0][2] != '-') return (Ttt[0][2] == 'X') ? P1 : P2;
    return "";}
    void Display(string* W, string P1, string P2) {
    if (*W == P1 || *W == P2) {
    cout << "\n\nWinner of the game is: " << *W << endl;
    } else {
    cout << "\n\nGame is a Draw!" << endl;}
    cout << "\nThank you for playing!\n";}

