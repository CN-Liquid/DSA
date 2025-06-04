#include <stdio.h>
#include <stdlib.h>

struct linkedList {

  int value;
  void *next;
};
struct linkedList *first, *last = NULL;

void insert_beg(int value) {
  struct linkedList *New =
      (struct linkedList *)malloc(sizeof(struct linkedList));
  New->value = value;
  New->next = NULL;

  if (first == NULL) {
    first = last = New;
  }

  else {

    New->next = (void *)first;
    first = New;
  }
}

void insert_end(int value) {
  struct linkedList *New =
      (struct linkedList *)malloc(sizeof(struct linkedList));
  New->value = value;
  New->next = NULL;
  if (first == NULL) {

    first = last = New;
  }

  else {
    last->next = New;
    last = New;
  }
}

void insert(int value, int p) {
  struct linkedList *temp = first;
  struct linkedList *New =
      (struct linkedList *)malloc(sizeof(struct linkedList));
  New->value = value;
  New->next = NULL;

  if (p == 1) {
    insert_beg(value);
  }

  else {
    for (int i = 1; i < p - 1; i++) {
      temp = (struct linkedList *)temp->next;
    }
    New->next = temp->next;
    temp->next = New;
  }
}

void del_beg() {
  if (first == NULL) {
    printf("The list is empty");
  }

  else {
    struct linkedList *tmp = first;
    first = first->next;
    free(tmp);
  }
}
void del_end() {
  if (first == NULL) {
    printf("The list is empty");
  }

  else {
    struct linkedList *tmp = first;
    while (tmp->next != last) {
      tmp = tmp->next;
    }
    tmp->next = NULL;
    free(last);
    last = tmp;
  }
}

void del(int p) {
  struct linkedList *temp = first;
  struct linkedList *temp1;
  if (first == NULL) {
    printf("The list is empty");
  }

  else if (first == last) {
    del_beg();
  }

  else {
    for (int i = 1; i < p - 1; i++) {
      temp = (struct linkedList *)temp->next;
    }
    temp1 = temp->next;

    temp->next = ((struct linkedList *)(temp->next))->next;
    free(temp1);
  }
}

void print() {
  if (first == NULL) {
    printf("The linked list is empty\n");
  }

  else {
    struct linkedList *tmp = first;
    while (tmp != NULL) {
      printf("%d\t", tmp->value);
      tmp = (struct linkedList *)tmp->next;
    }
    printf("\n");
  }
}

int main() {

  struct linkedList l;
  insert_beg(1);
  insert_beg(2);
  insert_end(3);
  insert_end(4);
  insert(1, 4);
  del_beg();
  del_end();
  del(2);
  del(1);
  insert_beg(2);
  del(1);
  print();

  return 0;
}