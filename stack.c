#include <stdio.h>
#include <stdlib.h>

typedef struct StackItem
{
	int data;
	struct StackItem* next_ptr;
} STACK_ITEM, * STACK_ITEM_PTR;

typedef struct Stack
{
	STACK_ITEM* front_ptr;
	STACK_ITEM* end_ptr;
} STACK, * STACK_PTR;


int stack_init(STACK* stack_ptr)
{
	stack_ptr->front_ptr = NULL;
	stack_ptr->end_ptr = NULL;
	return 1;
}


int stack_push(STACK_PTR stack_ptr, int data)
{
	if (stack_ptr == NULL) {
		return 0;
	}

	STACK_ITEM_PTR stack_item_ptr = (STACK_ITEM_PTR) malloc(sizeof(STACK_ITEM));
	if (stack_item_ptr == NULL) {
		return 0; // malloc failed
	}

	if (stack_ptr->end_ptr == NULL) {
		stack_ptr->end_ptr = stack_item_ptr;
		stack_item_ptr->next_ptr = NULL;
	} else {
		stack_item_ptr->next_ptr = stack_ptr->front_ptr;
	}

	stack_item_ptr->data = data;
	stack_ptr->front_ptr = stack_item_ptr;
	return 1;
}


int stack_pop(STACK_PTR stack_ptr, int* data)
{
	if (stack_ptr == NULL || stack_ptr->front_ptr == NULL) {
		*data = -1;
		return 0;
	}

	STACK_ITEM_PTR stack_item_ptr = stack_ptr->front_ptr;
	stack_ptr->front_ptr = stack_item_ptr->next_ptr;
	*data = stack_item_ptr->data;

	if (stack_ptr->front_ptr == NULL) {
		stack_ptr->end_ptr = NULL;
	}

	free(stack_item_ptr);
	return 1;
}


int stack_is_empty(STACK_PTR stack_ptr)
{
	if (stack_ptr == NULL) {
		return 1;
	}
	return (stack_ptr->front_ptr != NULL || stack_ptr->end_ptr != NULL) ? 0 : 1;
}


int main()
{
	STACK stack;
	stack_init(&stack);
	stack_push(&stack, 1);
	stack_push(&stack, 2);
	stack_push(&stack, 3);
	stack_push(&stack, 4);
	stack_push(&stack, 5);
	stack_push(&stack, 6);

	int val1 = 0; stack_pop(&stack, &val1); printf("%d, is_empty: %d\n", val1, stack_is_empty(&stack));
	int val2 = 0; stack_pop(&stack, &val2); printf("%d, is_empty: %d\n", val2, stack_is_empty(&stack));
	int val3 = 0; stack_pop(&stack, &val3); printf("%d, is_empty: %d\n", val3, stack_is_empty(&stack));
	int val4 = 0; stack_pop(&stack, &val4); printf("%d, is_empty: %d\n", val4, stack_is_empty(&stack));
	int val5 = 0; stack_pop(&stack, &val5); printf("%d, is_empty: %d\n", val5, stack_is_empty(&stack));
	int val6 = 0; stack_pop(&stack, &val6); printf("%d, is_empty: %d\n", val6, stack_is_empty(&stack));
	int val7 = 0; stack_pop(&stack, &val7); printf("%d, is_empty: %d\n", val7, stack_is_empty(&stack));

	return 1;
}
