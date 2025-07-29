#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
  int *array;
  int capacity;
  int size;
} Stack;

Stack* create_stack(int capacity);
void destroy_stack(Stack* stack);
bool is_full(Stack* stack);
bool is_empty(Stack* stack);
bool push(Stack* stack, int num);
bool pop(Stack* stack, int *num);
bool top(Stack* stack, int *num);

int main(void) {
  Stack *stack = create_stack(5);
  if (!push(stack, 10)) {
    printf("Push Failed\n");
  }
  if (!push(stack, 20)) {
    printf("Push Failed\n");
  }
  if (!push(stack, 30)) {
    printf("Push Failed\n");
  }
  if (!push(stack, 40)) {
    printf("Push Failed\n");
  }
  if (!push(stack, 50)) {
    printf("Push Failed\n");
  }
  if (!push(stack, 10)) {
    printf("Push Failed - Stack Overflow\n");
  }

  int pop_val = 0;
  for (int i=0; i <5; i++) {
    pop(stack, &pop_val);
    printf("Popped value: %d\n", pop_val);
  }

  if (!pop(stack, &pop_val)) {
    printf("Tried to pop an empty stack!\n");
  }

  destroy_stack(stack);
  return 0;
}

Stack* create_stack(int capacity) {
  if (capacity <= 0) return NULL;
  Stack *stack = malloc(sizeof(Stack));
  if (!stack) return NULL;

  stack->array = malloc(sizeof(int) * capacity);
  if (!stack->array) return NULL;

  stack->capacity = capacity;
  stack->size = 0;
  return stack;
}

void destroy_stack(Stack *stack) {
  free(stack->array);
  free(stack);
}

bool is_full(Stack *stack) {
  return (stack->size == stack->capacity);
}

bool is_empty(Stack *stack) {
  return (stack->size <= 0);
}

bool push(Stack *stack, int num) {
  if (is_full(stack)) return false;
  stack->array[stack->size++] = num;
  return true;
}

bool pop(Stack *stack, int *num) {
  if (is_empty(stack)) return false;
  *num = stack->array[--(stack->size)];
  return true;
}

bool top(Stack *stack, int *num) {
  if (is_empty(stack)) return false;
  *num = stack->array[stack->size-1];
  return true;
}
