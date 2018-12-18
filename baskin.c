#include <stdio.h>
#include <stdlib.h>

int random_number(int min_num, int max_num);
int sayComputer(int numbers[],  int currentIdx);
int setNumbers(int numbers[]);
void printIntro();

int main() {
  int n, i, currentIdx = 0, numbers[32];
  int THIRTY_ONE = 31;

  setNumbers(numbers);
  printIntro();

  while(1) {
    printf("\nHow many numbers will you say?\n");
    while(1) {
      scanf("%d", &n);
      if (n > 3 || n < 1) {
        printf("\nYou must say number between 1 ~ 3.\n");
        printf("\nHow many numbers will you say?\n");
      } else {
        break;
      }
    }

    printf("\nYOU SAY ...\n");
    for (i = 1; i <= n; i++) {
      if (i + currentIdx > THIRTY_ONE) break;
      printf("%d ", numbers[i + currentIdx]);
    }

    printf("\n");

    currentIdx += n;
    if (currentIdx >= THIRTY_ONE) {
      printf("\nCOMPUTER WIN !\n");
      return 0;
    };

    currentIdx = sayComputer(numbers, currentIdx);
    if (currentIdx >= THIRTY_ONE) {
      printf("\nYOU WIN !\n");
      return 0;
    };
  }
}

int random_number(int min_num, int max_num) {
  int result = 0, low_num = 0, hi_num = 0;
  if (min_num < max_num) {
      low_num = min_num;
      hi_num = max_num + 1;
  } else {
      low_num = max_num + 1;
      hi_num = min_num;
  }
  srand(time(NULL));
  result = (rand() % (hi_num - low_num)) + low_num;
  return result;
}

int sayComputer(int numbers[],  int currentIdx) {
  int i;
  int r = random_number(1, 3);

  printf("\nCOMPUTER SAYS ...\n");
  for (i = 1; i <= r; i++) {
    if (i + currentIdx > THIRTY_ONE) break;
    printf("%d ", numbers[i + currentIdx]);
  }

  printf("\n");

  return currentIdx + r;
}

int setNumbers(int numbers[]) {
  int i;
  for (i = 1; i <= THIRTY_ONE; i++) {
    numbers[i] = i;
  }

  return *numbers;
}

void printIntro() {
  printf("\n\n");
  printf("================================================\n");
  printf("             BASKIN RABINSON 31 GAME            \n");
  printf("================================================\n");
  printf("\n");
  printf("================================================\n");
  printf("# Rules #\n");
  printf("================================================\n");
  printf("1. If you say 31 before computer does, you win.\n");
  printf("2. You should say up to three numbers at a time.\n");
  printf("================================================\n");
  printf("\n\n");
  printf("Let's GO!\n");
  printf("\n\n");
}