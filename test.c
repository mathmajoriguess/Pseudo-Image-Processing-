#include <stdio.h>

int inputChecker(int *, int);
void recur(int *, int, int, int, int);
int neighborLabel(int *, int, int, int);
void forLabeling(int *, int, int, int, int);

int main()
{

  int tc, row, col, size, image[100], label = 2;
  // int *pointerlabel = &label;

  do
  {
    scanf("%i", &tc);
  } while (tc < 0);

  for (int i = 0; i < tc; i++) //this loop is for the creation of the supposedly image inputted by the user
  {
    scanf("%d %d", &row, &col);
    size = row * col;
    int image[size];
    for (int ii = 0; ii < size; ii++) //this loop is the asking for the values of the pixels of the image
    {
      scanf("%d", &image[ii]);
    }
  }

  inputChecker(image, size);
  if (row > 0 && col > 0)
  {
    recur(image, size, col, 0, label);
  }
  else if (inputChecker)
    printf("INVALID INPUT\n");
  else
    printf("INVALID INPUT\n");

  getchar();
  getchar();
}

int inputChecker(int image[], int size)
{
  int flag = 0;
  for (int i = 0; i < size; i++)
  {
    if (image[i] > 0 && image[i] < 1)
      flag = 1;
    break;
  }

  if (flag == 1)
    return 1;
  else
    return 0;
}

void recur(int image[], int size, int col, int index, int label)
{
  for (index = 0; index < size; index++)
  {
    if (image[index] == 1)
    {
      forLabeling(image, size, col, index, label);
      // label++;
    }
    label++;
  }
  printf("%i objects found", label-1);
}

int neighborLabel(int image[], int size, int col, int index)
{
  int thereIs = 0;
  if (index == 0 || index == (col - 1) || index == size - col ||
      index == size - 1)
  {
    if (index - col - 1 >= 2 || index - col >= 2 || index - col + 1 >= 2 ||
        index - 1 >= 2 || index + 1 >= 2 || index + col - 1 >= 2 ||
        index + col >= 2 || index + col + 1 >= 2)
    {
      thereIs = 1;
    }
    else
      thereIs = 0;
  }
  else if (index < col - 1 || index % col == 0 || (index + 1) % col == 0 ||
           (index < size - 1 && index > size - col))
  {
    if (index - col - 1 >= 2 || index - col >= 2 || index - col + 1 >= 2 ||
        index - 1 >= 2 || index + 1 >= 2 || index + col - 1 >= 2 ||
        index + col >= 2 || index + col + 1 >= 2)
    {
      thereIs = 1;
    }
    else
      thereIs = 0;
  }
  else
  {
    if (index - col - 1 >= 2 || index - col >= 2 || index - col + 1 >= 2 ||
        index - 1 >= 2 || index + 1 >= 2 || index + col - 1 >= 2 ||
        index + col >= 2 || index + col + 1 >= 2)
    {
      thereIs = 1;
    }
    else
      thereIs = 0;
  }

  return thereIs;
}

void forLabeling(int image[], int size, int col, int index, int label)
{
  if (image[index] == 1)
  {
    image[index] == label;

    neighborLabel(image, size, col, index);

    if (neighborLabel)
    { // neighborLabel(image, size, col, index - col - 1);
      if (image[index - col - 1] == 1 && neighborLabel)
        forLabeling(image, size, col, index - col - 1, label);

      if (image[index - col] == 1 && neighborLabel)
        forLabeling(image, size, col, index - col, label);

      if (image[index - col + 1] == 1 && neighborLabel)
        forLabeling(image, size, col, index - col + 1, label);

      if (image[index - 1] == 1 && neighborLabel)
        forLabeling(image, size, col, index - 1, label);

      if (image[index + 1] == 1 && neighborLabel)
        forLabeling(image, size, col, index + 1, label);

      if (image[index + col - 1] == 1 && neighborLabel)
        forLabeling(image, size, col, index + col - 1, label);

      if (image[index + col] == 1 && neighborLabel)
        forLabeling(image, size, col, index + col, label);

      if (image[index + col + 1] == 2 && neighborLabel)
        forLabeling(image, size, col, index + col + 1, label);
    }

    else
    {
      forLabeling(image, size, col, index + 1, label);
    }
  }
}