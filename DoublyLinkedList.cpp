#include <cstdlib>
#include <iostream>
using namespace std;
struct dll {
  int data;
  struct dll *prev, *next;
};
struct dll *first = NULL;
struct dll *last = NULL;

void insertBeg(int a) {
  struct dll *newnode;
  newnode = new dll();
  newnode->data = a;
  newnode->next = NULL;
  newnode->prev = NULL;
  if (first == NULL) {
    first = last = newnode;
  } else {
    newnode->next = first;
    first->prev = newnode;
    first = newnode;
  }
  cout << first->data << " was inserted at the beginning " << endl;
  return;
}
void insertEnd(int a) {
  struct dll *newnode;
  newnode = new dll;
  newnode->data = a;
  newnode->next = NULL;
  newnode->prev = NULL;
  if (first == NULL) {
    first = last = newnode;

  } else {
    newnode->prev = last;
    last->next = newnode;
    last = newnode;
  }
  cout << last->data << " Was inserted at the end" << endl;
}
void insertPos(int a, int pos) {
  int i;
  dll *newnode, *temp;
  newnode = new dll();
  newnode->data = a;
  newnode->next = NULL;
  newnode->prev = NULL;
  if (first == NULL) {
    first = last = newnode;
  } else if (pos == 1) {
    insertBeg(a);
  } else {
    temp = first;
    for (i = 1; i < pos - 1 && temp->next != NULL; i++) {
      temp = temp->next;
    }
    newnode->next = temp->next;
    newnode->prev = temp;
    if (temp->next != NULL) {
      temp->next->prev = newnode;
    } else {

      last = newnode;
    }

    temp->next = newnode;
  }
  cout << newnode->data << " was inserted at position " << pos << endl;
}

void delBeg()

{
  struct dll *temp;
  if (first == NULL) {
    cout << "List is Empty! " << endl;

  } else if (first->next == NULL) {
    temp = first;
    first = last = NULL;

  } else {
    temp = first;

    first = first->next;
    first->prev = NULL;
  }
  cout << temp->data << " was deleted from the beginning " << endl;
  delete temp;
}
void delEnd() {
  struct dll *temp;
  if (first == NULL) {
    cout << "List is Empty! " << endl;
  } else if (first->next == NULL) {
    temp = first;

    first = last = NULL;

  } else {
    temp = last;

    last = last->prev;
    last->next = NULL;
  }
  cout << temp->data << " was deleted from the end" << endl;
  delete temp;
}
void delPos(int pos) {
  dll *temp;
  dll *tempp;

  if (first == NULL) {
    cout << "List is Empty!" << endl;
    return;
  }

  if (pos == 1) {
    temp = first;
    first = first->next;

    if (first != NULL)
      first->prev = NULL;
    else
      last = NULL;

    delete temp;
  } else {
    temp = first;
    for (int i = 1; i < pos - 1 && temp != NULL; i++) {
      temp = temp->next;
    }

    if (temp == NULL || temp->next == NULL) {
      cout << "Invalid position!" << endl;
      return;
    }

    tempp = temp->next;

    temp->next = tempp->next;
    if (tempp->next != NULL)
      tempp->next->prev = temp;
    else
      last = temp;

    delete tempp;
  }
}
void search(int key) {
  int flag = 0;
  if (first == NULL) {
    cout << "List is Empty!" << endl;

  } else {
    dll *temp = first;
    while (temp != NULL) {
      if (temp->data = key) {
        flag = 1;
        cout << "Element found! " << endl;
        break;
      }

      temp->prev = temp;
      temp = temp->next;
    }
    if (flag == 0) {
      cout << "Element not found! " << endl;
    }
  }
}

void display() {
  struct dll *temp;
  temp = first;
  if (first == NULL) {
    cout << "List is Empty! " << endl;
  } else {
    while (temp != NULL) {
      cout << temp->data << " < - > ";
      temp = temp->next;
    }
    cout << " NULL";
    cout << endl;
  }
}

int main() {
  insertBeg(10);
  insertEnd(29);
  insertBeg(20);
  display();
  delBeg();
  display();
  insertBeg(20);
  insertEnd(21);
  display();
  insertPos(19, 3);
  display();
  delEnd();
  display();
  insertBeg(25);
  display();
  delPos(2);
  display();
  search(10);

  return 0;
}