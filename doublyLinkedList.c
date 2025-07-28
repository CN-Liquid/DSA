#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

struct DLL {
  int value;
  struct DLL *next;
  struct DLL *previous;
};

struct DLL *first;
struct DLL *last;

bool isEmpty() {

  if (first == NULL) {
    return true;
  } else {
    return false;
  }
}

void insert_beg(int value) {

  struct DLL *NewNode = malloc(sizeof(struct DLL));

  NewNode->value = value;
  if (first == NULL) {
    first = last = NewNode;
  }
  NewNode->previous = NULL;
  NewNode->next = first;
  first->previous = NewNode;
  first = NewNode;
}

void insert_last(int value) {
  struct DLL *NewNode = malloc(sizeof(struct DLL));

  NewNode->value = value;

  NewNode->previous = last;

  last->next = NewNode;

  NewNode->next = NULL;

  last = NewNode;
}

void del_beg() {

  if (first == NULL) {
    printf("The list is empty");
  } else {

    struct DLL *tmp = first;
    first = first->next;
    first->previous = NULL;
    free(tmp);
  }
}

void del_last() {
  if (first == NULL) {
    printf("The list is empty");
  } else {

    struct DLL *tmp = last;
    last = last->previous;
    last->next = NULL;
    free(tmp);
  }
}

void display() {
  struct DLL *tmp = first;
  if (isEmpty()) {
    printf("The list is empty");
    return;
  }
  while (tmp != NULL) {
    printf("%d -- ", tmp->value);
    tmp = tmp->next;
  }
  printf("%p", tmp);
  printf("\n");
}

void search_fw(int value) {
  int index = 0;
  if (isEmpty()) {
    printf("The list is empty");
  } else {
    struct DLL *tmp = first;
    while (tmp != NULL) {
      if (tmp->value == value) {
        printf("%d found at index %d\n", value, index + 1);
      }
      index++;
      tmp = tmp->next;
    }
  }
}

int size() {
  int index = 0;
  if (isEmpty()) {
    return 0;
  } else {
    struct DLL *tmp = first;
    while (tmp != NULL) {
      index++;
      tmp = tmp->next;
    }
    return index;
  }
}
void search_bw(int value) {
  int index = size();
  if (isEmpty()) {
    printf("The list is empty");
  } else {
    struct DLL *tmp = last;
    while (tmp != NULL) {
      if (tmp->value == value) {
        printf("%d found at index %d\n", value, index);
      }
      index--;
      tmp = tmp->previous;
    }
  }
}

int main() {
  insert_beg(1);
  insert_beg(2);
  insert_last(3);
  insert_last(4);
  insert_last(5);
  del_beg();
  del_last();

  insert_last(3);
  insert_last(3);
  display();
  search_bw(3);

  return 0;
}