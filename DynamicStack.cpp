#include <iostream>
using namespace std;

class dyanmicStack {
private:
  int data;
  dyanmicStack *next;
  static dyanmicStack *Top;

public:
  dyanmicStack() : data(0), next(NULL) {}
  ~dyanmicStack() {}

  void push(int element) {
    dyanmicStack *newnode = new dyanmicStack();
    if (newnode == NULL) {
      cout << "Memory allocation failed\n";
      return;
    }
    newnode->data = element;
    newnode->next = Top;
    Top = newnode;
  }

  void pop() {
    if (Top == NULL) {
      cout << "Stack is empty!\n";
      return;
    }
    dyanmicStack *temp = Top;
    cout << "The pop data is " << temp->data << endl;
    Top = Top->next;
    delete temp;
  }

  void display() {
    dyanmicStack *temp = Top;
    while (temp != NULL) {
      cout << temp->data << " -> ";
      temp = temp->next;
    }
    cout << "NULL";
    cout << endl;
  }
};

dyanmicStack *dyanmicStack::Top = NULL;

int main() {
  dyanmicStack s;
  s.push(10);
  s.push(20);
  s.push(1);
  s.display();
  s.pop();
  s.display();
  return 0;
}