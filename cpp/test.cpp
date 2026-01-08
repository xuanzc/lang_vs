#include <iostream>
#include <chrono>
#include <deque>
#include <cstdio>

constexpr int LOOP_COUNT = 1000000;
constexpr int QUEUE_SIZE = 1000;
constexpr int CHARSET_SIZE = 62;

// 预定义字符集
constexpr const char charset[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";

// 更快的随机数生成器（Xorshift算法）
class Xorshift32 {
private:
    uint32_t state;
public:
    Xorshift32(uint32_t seed) : state(seed) {}
    
    uint32_t operator()() {
        state ^= state << 13;
        state ^= state >> 17;
        state ^= state << 5;
        return state;
    }
};

int main() {
    // 使用更高效的deque替代queue
    std::deque<char> q;
    
    // 使用更快的Xorshift随机数生成器
    Xorshift32 rng(static_cast<uint32_t>(std::chrono::high_resolution_clock::now().time_since_epoch().count()));
    
    // 记录开始时间
    auto start = std::chrono::high_resolution_clock::now();
    
    for (int i = 0; i < LOOP_COUNT; i++) {
        // 生成随机字符（直接内联，避免函数调用开销）
        uint32_t rand_val = rng();
        int index = rand_val % CHARSET_SIZE;
        char c = charset[index];
        
        // 入队
        q.push_back(c);
        
        // 如果队列超过999，出队
        if (q.size() > 999) {
            q.pop_front();
        }
    }
    
    // 记录结束时间
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> elapsed = end - start;
    
    // 使用printf替代cout，提高输出效率
    printf("C++: %.6f milliseconds\n", elapsed.count());
    
    return 0;
}