#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node {
  int val;
  struct Node* next;
} Node;

void destroy_LL(Node* cur);
bool is_empty(Node* head);
bool insert_end(Node** head, int val);
bool insert_begin(Node** head, int val);
bool pop_end(Node** head, int *val);
bool pop_begin(Node** head, int *val);
void display(Node* head);

int main(void) {
  Node* head = NULL;

  insert_begin(&head, 2);
  insert_begin(&head, 1);
  insert_end(&head, 3);
  insert_end(&head, 4);

  display(head);

  int pop_val = 0;
  while (!is_empty(head)) {
    if (!pop_end(&head, &pop_val)) {
      printf("Failed to pop");
    }
    printf("Popped: %d\n", pop_val);
  }

  if (pop_end(&head, &pop_val)) {
    printf("We are popping from empty!!!");
  }

  display(head);

  insert_begin(&head, 2);
  insert_begin(&head, 1);
  insert_end(&head, 3);
  insert_end(&head, 4);

  while (!is_empty(head)) {
    if (!pop_begin(&head, &pop_val)) {
      printf("Failed to pop");
    }
    printf("Popped: %d\n", pop_val);
  }

  destroy_LL(head);
  return 0;
}

void destroy_LL(Node* cur) {
  while (cur) {
    Node* temp = cur;
    cur = cur->next;
    free(temp);
  }
}

bool is_empty(Node* head) {
  return (head == NULL);
}

bool insert_end(Node** head, int val) {
  if (!(*head)) return insert_begin(head, val);
  Node* temp = *head;
  while (temp->next) temp = temp->next;

  Node* tail = malloc(sizeof(Node));
  if (!tail) return false;

  tail->val = val;
  tail->next = NULL;
  temp->next = tail;
  return true;
}

bool insert_begin(Node** head, int val) {
  Node* new = malloc(sizeof(Node));
  if (!new) return false;

  new->val = val;
  new->next = *head;
  *head = new;
  return true;
}

bool pop_end(Node** head, int *val) {
  if (!(*head)) return false;
  if (!(*head)->next) {
    *val = (*head)->val;
    free(*head);
    *head = NULL;
    return true;
  }

  Node* temp = *head;
  while (temp->next->next) temp = temp->next;

  *val = temp->next->val;
  Node* to_free = temp->next;
  temp->next = NULL;
  free(to_free);

  return true;

}

bool pop_begin(Node** head, int *val) {
  if (!(*head)) return false;
  *val = (*head)->val;
  Node* to_free = *head;
  *head = (*head)->next;
  free(to_free);
  return true;
}

void display(Node* head) {
  Node* temp = head;
  while (temp) {
    printf("%d -> ", temp->val);
    temp = temp->next;
  }
  printf("NULL\n");
}
