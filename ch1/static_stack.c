#include <stdlib.h>


typedef struct {
  void* value;
  int size;
} item_t;

typedef struct {
  item_t *base;
  item_t *top;
  int size;
} stack_t;


stack_t *create_stack(int size, int size_item)
{
  stack_t *st;

  st = (stack_t *) malloc(sizeof(stack_t));
  st->base = (item_t *) malloc(size*sizeof(item_t));
  st->base->size = size_item;
  st->base->value = (void *) malloc(size_item);
  st->size = size;
  st->top = st->base;

  return st;
}


int stack_empty(stack_t *st)
{
  return st->top == st->base;
}


int push(item_t x, stack_t *st)
{
  if (st->top < st->base + st->size) {
    *(st->top);
    st->top++;
    return 0;
  } else
    return -1;
}


item_t pop(stack_t *st)
{
  st->top--;
  return *(st->top);
}


item_t peek(stack_t *st)
{
  return *(st->top - 1);
}


void free_stack(stack_t *st)
{
  free(st->base->value);
  free(st->base);
  free(st);
}
