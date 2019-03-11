#include <stdio.h> 
 
void labelArray(int index, int a[], int size, int col, int ctr);
int validArray(int *a, int size);
int max(int a[], int);

int main() {
  int tc, row, col;
  scanf("%d", &tc);  // asking for the number of testcases
  for (int i = 0; i < tc; i++) {
    scanf("%d %d", &row, &col);
    int image[col * row];//use a 1d array for convenience
    for (int ii = 0; ii < row * col; ii++) {
      scanf("%d", &image[ii]);
      //enter the whole array
    }
    //check if nonzero or nonone if true, then invalid input
    if (validArray(image, row*col) ) {
      labelArray(0, image, row * col, col, 2); 
    }
    else printf("INVALID INPUT\n");
  }
  getchar();
  getchar();
}
int validArray(int a[], int size){
  // checks the validity of array
  for(int i = 0; i< size; i++){
    if(a[i]!= 0 &&  a[i]!=1) return 0;
    
  }
  return 1;
}  
// check all neighbors of the array and set the value to the label
void shade(int index, int a[], int size, int col, int ctr, int start) {
  // the additional conditions ensure no out of bounds array
  if (index + 1 < size && a[index + 1] == 1 && (index + 1) % col != 0) {
    a[index + 1] = ctr;
    shade(index + 1, a, size, col, ctr, start);
  }
  if (index + 1 + col < size && a[index + col + 1] == 1 &&
      (index + 1) % col != 0) {
    a[index + 1 + col] = ctr;
    shade(index + 1 + col, a, size, col, ctr, start);
  }
  if (index + col < size && a[index + col] == 1) {
    a[index + col] = ctr;
    shade(index + col, a, size, col, ctr, start);
  }
  if (index + col - 1 < size && a[index + col - 1] == 1 && (index) % col != 0) {
    a[index - 1 + col] = ctr;
    shade(index - 1 + col, a, size, col, ctr, start);
  }
  if (index - 1 < size && a[index - 1] == 1 && (index) % col != 0) {
    a[index - 1] = ctr;
    shade(index - 1, a, size, col, ctr, start);
  }
  if (index - col - 1 < size && a[index - col - 1] == 1 && (index) % col != 0) {
    a[index - 1 - col] = ctr;
    shade(index - 1 - col, a, size, col, ctr, start);
  }
  if (index - col < size && a[index - col] == 1) {
    a[index - col] = ctr;
    shade(index - col, a, size, col, ctr, start);
  }
  if (index + 1 - col < size && a[index + 1 - col] == 1 &&
      (index + 1) % col != 0) {
    a[index + 1 - col] = ctr;
    shade(index + 1 - col, a, size, col, ctr, start);
  }
}

void labelArray(int index, int a[], int size, int col, int ctr) {
  // iterate through the whole array 
  if (a[index] == 1) {
    shade(index, a, size, col, ctr, index);
    ctr++;
  }
  if (index < size) {
    labelArray(index + 1, a, size, col, ctr);
  }

  else
    printf("%d Object%s found\n", ctr - 2, (ctr - 2 == 1) ? "" : "s");// Ensuring we are in compliance to the International English Grammar Standards
}
