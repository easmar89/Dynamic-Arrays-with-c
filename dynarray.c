#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#define STARTING_CAPACITY 8

typedef struct DA {
  int capacity;
  int size; 
  void **arr;
} DA;


DA* DA_new (void) {
  DA *da = malloc(sizeof(DA));
  void **arr = malloc(sizeof(void*) * STARTING_CAPACITY);
  da->arr = arr;
  da->size = 0;
  da->capacity = STARTING_CAPACITY;

  return da;
}

int DA_size(DA *da) {
  return da->size; 
}

void DA_push (DA* da, void *x) {
  if (da->size == da->capacity) {
    int new_capacity = da->capacity + STARTING_CAPACITY; 
    void** new_arr = malloc(sizeof(void *) * new_capacity);
    for (int i = 0; i < da->size; i++){
      new_arr[i] = da->arr[i];
    }

    free(da->arr);
    da->arr = new_arr;  
    da->capacity = new_capacity;
  } 
  
  da->arr[da->size] = x;
  da->size += 1;
}

void *DA_pop(DA *da) {
  void* popped_value;
  if (da->size > 0){
    popped_value = da->arr[da->size - 1];
    da->size--;
    return popped_value;
  }

  return NULL; 
}

void DA_set(DA *da, void* val, int idx) {
  if (idx >= 0 && idx < da->size) {
    da->arr[idx] = val;
  }
}

void *DA_get(DA *da, int idx) {
  if (idx >= 0 && idx < da->size) {
    return da->arr[idx];
  } else {
    return NULL;
  }
} 

void DA_free(DA *da) {
  free(da->arr);
  free(da);
}

int main() {
    DA *da = DA_new();

    assert(DA_size(da) == 0);

    // basic push and pop test
    int x = 5;
    float y = 12.4;
    DA_push(da, &x);
    DA_push(da, &y);
    assert(DA_size(da) == 2);

    assert(DA_pop(da) == &y);
    assert(DA_size(da) == 1);

    assert(DA_pop(da) == &x);
    assert(DA_size(da) == 0);
    assert(DA_pop(da) == NULL);

    // basic set/get test
    DA_push(da, &x);
    DA_set(da, &y, 0);
    assert(DA_get(da, 0) == &y);
    DA_pop(da);
    assert(DA_size(da) == 0);

    // expansion test
    DA *da2 = DA_new();
    DA_push(da2, &x);
    int i, n = 100 * STARTING_CAPACITY, arr[n];
    for (i = 0; i < n; i++) {
      arr[i] = i;
      DA_push(da, &arr[i]);
    }
    assert(DA_size(da) == n);
    for (i = 0; i < n; i++) {
      assert(DA_get(da, i) == &arr[i]);
    }
    for (; n; n--)
      DA_pop(da);
    assert(DA_size(da) == 0);
    assert(DA_pop(da2) == &x);

    DA_free(da);
    DA_free(da2);
    printf("OK\n");
}