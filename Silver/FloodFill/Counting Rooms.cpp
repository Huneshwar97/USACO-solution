#include<bits/stdc++.h>

using namespace std;

const int MAX_N = 1000;

int grid[MAX_N][MAX_N];  // the grid itself
int row_num;
int col_num;
bool visited[MAX_N][MAX_N];  // keeps track of which nodes have been visited
int curr_size = 0;  // reset to 0 each time we start a new component

void floodfill(int r, int c, int color){
	if (
		(r < 0 || r >= row_num || c < 0 || c >= col_num)  // if out of bounds
		|| grid[r][c] != color  // wrong color
		|| visited[r][c]  // already visited this square
	) return;

	visited[r][c] = true; // mark current square as visited
	 // increment the size for each square we visit

	// recursively call flood fill for neighboring squares
	floodfill(r, c + 1, color);
	floodfill(r, c - 1, color);
	floodfill(r - 1, c, color);
	floodfill(r + 1, c, color);
}

int main() {
	/*
	 * input code and other problem-specific stuff here
	 */
	 cin >> row_num >> col_num;char ch;
	for (int r = 0; r < row_num; r++) {
		for (int c = 0; c < col_num; c++) {
			cin >> ch;
			if(ch == '#'){
			    grid[r][c]=0;
			}
			else{
			    grid[r][c]=1;
			}
		}
	}
	for (int i = 0; i < row_num; i++) {
		for (int j = 0; j < col_num; j++) {
			if (!visited[i][j]  && grid[i][j]) {
				curr_size ++;
				/*
				 * start a flood fill if the square hasn't already been visited,
				 * and then store or otherwise use the component size
				 * for whatever it's needed for
				 */
				floodfill(i, j, grid[i][j]);
			}
		}
	}
	cout<<curr_size<<"\n";
	return 0;
}