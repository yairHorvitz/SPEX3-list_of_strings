#include <stdio.h>

#include "StrList.h"
#define WORD_MAX_SIZE 100

int main(void) {
  int input;
  int index;
  int num_elements;
  char data[WORD_MAX_SIZE];
  StrList *list = StrList_alloc();
  do {
    if (scanf("%d", &input) != 1) {
      printf("Invalid input\n");
      break;
    }
    switch (input) {
      case 1:
        if (scanf("%d", &num_elements) != 1) {
          printf("Invalid input\n");
          break;
        }
        for (int i = 0; i < num_elements; i++) {
          if (scanf("%s", data) != 1) {
            printf("Invalid input\n");
            break;
          }
          StrList_insertLast(list, data);
        }
        break;
      case 2:
        if (scanf("%d %s", &index, data) != 2) {
          printf("Invalid input\n");
          break;
        }
        StrList_insertAt(list, data, index);
        break;
      case 3:
        StrList_print(list);
        break;
      case 4:
        printf("%ld\n", StrList_size(list));
        break;
      case 5:
        if (scanf("%d", &index) != 1) {
          printf("Invalid input\n");
          break;
        }
        StrList_printAt(list, index);
        break;
      case 6:
        printf("%d\n", StrList_printLen(list));
        break;
      case 7:
        if (scanf("%s", data) != 1) {
          printf("Invalid input\n");
          break;
        }
        printf("%d\n", StrList_count(list, data));
        break;
      case 8:
        if (scanf("%s", data) != 1) {
          printf("Invalid input\n");
          break;
        }
        StrList_remove(list, data);
        break;
      case 9:
        if (scanf("%d", &index) != 1) {
          printf("Invalid input\n");
          break;
        }
        StrList_removeAt(list, index);
        break;
      case 10:
        StrList_reverse(list);
        break;
      case 11:
        StrList_free(list);
        list = StrList_alloc();
        break;
      case 12:
        StrList_sort(list);
        break;
      case 13:
        printf(StrList_isSorted(list) ? "true\n" : "false\n");
    }

  } while (input != 0);

  StrList_free(list);
  return 0;
}