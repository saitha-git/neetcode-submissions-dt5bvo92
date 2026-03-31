class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int top = 0;
        int n = matrix.size();
        int bottom = n-1; // COLS and ROWS are equal

        while(top < bottom) {
            for(int c=0; c<n; c++) {
                int temp = matrix[top][c];
                matrix[top][c] = matrix[bottom][c];
                matrix[bottom][c] = temp;
            }
            top++;
            bottom--;
        }
#if 1
        int r=0;
        int c=0;
        while ((r<n) && (c<n)) {

            for(int i=c+1; i<n; i++) {
                int temp = matrix[r][i];

                cout << matrix[r][i] << endl;
                cout << matrix[i][c] << endl;

                matrix[r][i] = matrix[i][c];
                matrix[i][c] = temp;
            }
            
            r++;
            c++;
        }
#endif
    }
};
