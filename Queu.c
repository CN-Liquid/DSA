#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#define MAX 5
struct queue {
  int FRONT;
  int REAR;
  bool loop;
  int data[MAX + 1];
};

bool isNull(struct queue *q) {
  if ((q->loop == false) && (q->FRONT == q->REAR)) {
    return true;
  }

  else {
    return false;
  }
}

bool isFull(struct queue *q) {
  if ((q->loop == true) && (q->FRONT == q->REAR)) {
    return true;
  }

  else {

    return false;
  }
}
bool enqueue(struct queue *q, int elem) {

  if (isFull(q)) {
    printf("The queue is full\n");
    return false;
  }

  else {

    q->data[q->REAR] = elem;
    q->REAR = (q->REAR + 1) % (MAX + 1);
    if (q->REAR == MAX) {
      q->loop = true;
      q->REAR = (q->REAR + 1) % (MAX + 1);
    }

    return true;
  }
}

int dequeue(struct queue *q) {
  if (isNull(q)) {
    printf("The queue has no elements\n");

  }

  else {

    int data = q->data[q->FRONT];
    q->FRONT = (q->FRONT + 1) % (MAX + 1);
    if (q->FRONT == MAX) {
      q->loop = false;
      q->FRONT = (q->FRONT + 1) % (MAX + 1);
    }
    return data;
  }
}
enum choice { en, de, ex };
int main() {
  struct queue q = {0, 0};
  q.loop = false;

  int temp;
  int input;
  while (1) {
    printf("1) Enqueue\n2) Dequeue\n3) Exit\n");
    scanf("%d", &temp);

    enum choice c = (enum choice)(temp - 1);

    switch (c) {
    case en:
      printf("Enter the positive integer : ");
      scanf("%d", &input);
      enqueue(&q, input);
      for (int i = 0; i < MAX; i++) {
        printf("%d\t", q.data[i]);
      }
      printf("\n");
      break;

    case de:
      dequeue(&q);
      for (int i = 0; i < MAX; i++) {
        printf("%d\t", q.data[i]);
      }
      printf("\n");
      break;

    case ex:
      exit(0);
      break;

    default:
      printf("Invalid input");
      break;
    }
  }

  return 0;
}