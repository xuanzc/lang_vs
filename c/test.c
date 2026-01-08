#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define QUEUE_SIZE 1000
#define LOOP_COUNT 1000000
#define CHARSET_SIZE 62

// 预定义字符集
const char charset[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";

// 循环队列结构
typedef struct {
    char data[QUEUE_SIZE];
    int front;
    int rear;
    int size;
} Queue;

// 更快的随机数生成器（Xorshift算法）
static inline unsigned int xorshift32(unsigned int *state) {
    unsigned int x = *state;
    x ^= x << 13;
    x ^= x >> 17;
    x ^= x << 5;
    *state = x;
    return x;
}

// 内联初始化队列
static inline void init_queue(Queue *queue) {
    queue->front = 0;
    queue->rear = 0;
    queue->size = 0;
}

// 内联入队
static inline void enqueue(Queue *queue, char c) {
    queue->data[queue->rear] = c;
    queue->rear = (queue->rear + 1) % QUEUE_SIZE;
    queue->size++;
}

// 内联出队
static inline char dequeue(Queue *queue) {
    char c = queue->data[queue->front];
    queue->front = (queue->front + 1) % QUEUE_SIZE;
    queue->size--;
    return c;
}

int main() {
    Queue queue;
    struct timespec start, end;
    double cpu_time_used;
    unsigned int rng_state = (unsigned int)time(NULL);
    volatile int total = 0; // 用于防止编译器优化
    
    // 初始化队列
    init_queue(&queue);
    
    // 使用高精度计时
    clock_gettime(CLOCK_MONOTONIC, &start);
    
    for (int i = 0; i < LOOP_COUNT; i++) {
        // 生成随机字符（使用更快的Xorshift算法）
        unsigned int rand_val = xorshift32(&rng_state);
        // 使用位运算替代mod运算，提高效率
        int index = rand_val % CHARSET_SIZE;
        char c = charset[index];
        
        // 入队
        enqueue(&queue, c);
        
        // 如果队列超过999，出队
        if (queue.size > 999) {
            total += dequeue(&queue); // 使用volatile变量防止优化
        }
    }
    
    // 结束计时
    clock_gettime(CLOCK_MONOTONIC, &end);
    
    // 计算耗时（转换为毫秒）
    cpu_time_used = (end.tv_sec - start.tv_sec) * 1000.0;
    cpu_time_used += (end.tv_nsec - start.tv_nsec) / 1000000.0;
    
    // 输出结果，与其他语言格式一致
    printf("C: %f milliseconds\n", cpu_time_used);
    // 使用volatile变量防止编译器优化（不影响输出）
    volatile int dummy = total;
    
    return 0;
}