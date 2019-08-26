#include <stdio.h>
int main(void) {
    long entries[1001][1001];
    int n, m, r, s;
    scanf("%d %d %d %d", &n, &m, &r, &s);   //reading
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            scanf("%ld", &entries[i][j]);
    long sum = 0, maxsum = 0;
    char right = 1, down = 0;
    int i = 0, j = 0;
    for(int i1 = 0; i1 < r; i1++)
        for (int j1 = 0; j1 < s; j1++)  //first sub-matrix and initial value for maxsum   
            maxsum += entries[i1][j1];
    sum = maxsum;
    while(1) {      // snake summing - instead of summing elements all over again,
                    // we account only for the difference between the elements between
                    // the previous submatrix and the next one
        down = (j==0 && !right) || (j==m-s && right);   
        if(i == n-r && down)    //exit condition: last line and going down
            break;
        if(down) {
            for(int j1 = 0; j1 < s; j1++){
                sum -= entries[i][j+j1];
                sum += entries[i+r][j+j1];
            }
            i++;
            right = !right;
        }
        else if (right)
        {
            for(int i1 = 0; i1 < r; i1++){
                sum -= entries[i+i1][j];
                sum += entries[i+i1][j+s];
            }
            j++;
        }
        else
        {
            for(int i1 = 0; i1 < r; i1++){
                sum -= entries[i+i1][j+s-1];
                sum += entries[i+i1][j-1];
            }
            j--;
        }
        maxsum = sum>maxsum ? sum:maxsum;   //updates maxsum
    }
    printf("%ld\n", maxsum);
}