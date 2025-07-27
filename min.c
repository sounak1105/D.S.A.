#include <stdio.h>

#define CAPACITY 10

typedef struct stack {
    int arr[CAPACITY];
    int min[CAPACITY];
    int top_idx;
} stack_t;

stack_t s = {
                .top_idx = -1
            };

// O(1)
void push(int in) {
    if (s.top_idx == (CAPACITY - 1)) {
        printf("Stack Overflow\n");
        return;
    }
    s.top_idx += 1;
    s.arr[s.top_idx] = in;
    s.min[s.top_idx]=s.arr[s.top_idx];
    if (in < s.min[s.top_idx-1] && 0<s.top_idx)
        s.min[s.top_idx]=in;
    else if(in > s.min[s.top_idx-1] && 0<s.top_idx)
        s.min[s.top_idx]=s.min[s.top_idx-1];
    else if(s.top_idx==0)
        s.min[s.top_idx]=s.arr[s.top_idx];
    return;
}

// O(1)
int pop() {
    if (0 > s.top_idx) {
        printf("stack underflow\n");
        return -1;
    }
    int pop_elem = s.arr[s.top_idx];
    s.arr[s.top_idx] = -1;
    s.min[s.top_idx]=-1;
    s.top_idx -= 1;
    return pop_elem;
}

// O(1)
int top() {
    return s.arr[s.top_idx];
}

// O(1)
int min() {
    return s.min[s.top_idx];
}

int main(int argc, char *argv[]) {
    int ret;

    push(10); // O(1)
    push(20);
    push(30);
    pop();
    ret = pop();
    if (ret != -1) {
        printf("Popped: %d\n", ret);
    }
    ret = top();
    printf("Top value: %d\n", ret);
//    push(2);
    printf("%d \n",s.top_idx);
    ret=min();
    printf("Minimum value: %d \n",ret);
    return 0;
}


/*
stack_t s;
s.push(30)
s.push(20);
s.push(10);
s.min() -> 10
s.pop(); -> 10
s.min(20);
s.push(60);
s.top(); ->
*/
