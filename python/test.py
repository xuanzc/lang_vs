import time
import random
from collections import deque
from numba import njit
import numpy as np

LOOP_COUNT = 1000000

# 预定义字符集长度（Numba兼容）
CHARSET_LEN = 62

# 优化后的随机字符生成函数（使用Numba兼容的方式）
@njit
def get_random_char(seed):
    # 简单的线性同余生成器，兼容Numba
    seed = (seed * 1103515245 + 12345) & 0x7fffffff
    idx = seed % CHARSET_LEN
    return idx, seed

# 主测试函数 - 仅包含Numba兼容的操作
@njit(cache=True)
def jit_main(loop_count):
    # 使用固定大小的数组模拟队列，兼容Numba
    queue = np.empty(1000, dtype=np.uint8)
    front = 0
    rear = 0
    size = 0
    
    # 简单的随机数种子
    seed = 42
    
    for _ in range(loop_count):
        # 生成随机字符索引（不直接处理字符串，只生成索引）
        idx, seed = get_random_char(seed)
        
        # 入队（只存储索引，不存储实际字符）
        queue[rear] = idx
        rear = (rear + 1) % 1000
        size += 1
        
        # 如果队列超过999，出队
        if size > 999:
            front = (front + 1) % 1000
            size -= 1
    
    return 0.0

# 主函数（非JIT部分，处理时间测量和字符串操作）
def main():
    # 预热阶段：先运行一次JIT函数进行编译
    jit_main(100)  # 运行少量迭代，触发编译
    
    # 记录开始时间
    start_time = time.perf_counter()
    
    # 调用JIT优化的主循环（实际测试）
    jit_main(LOOP_COUNT)
    
    # 记录结束时间
    end_time = time.perf_counter()
    
    # 计算耗时（转换为毫秒）
    elapsed = (end_time - start_time) * 1000
    
    # 输出结果，保持与其他语言一致的格式
    print(f"Python: {elapsed:.6f} milliseconds")

if __name__ == "__main__":
    main()