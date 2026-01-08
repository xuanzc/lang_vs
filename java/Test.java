import java.util.Arrays;

public class Test {
    private static final int LOOP_COUNT = 1000000;
    private static final int QUEUE_SIZE = 1000;
    private static final char[] CHARSET = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789".toCharArray();
    private static final int CHARSET_LENGTH = CHARSET.length;
    
    // 更快的随机数生成器（Xorshift算法）
    private static long xorShiftSeed = System.nanoTime();
    
    private static int fastRandom() {
        xorShiftSeed ^= (xorShiftSeed << 21);
        xorShiftSeed ^= (xorShiftSeed >>> 35);
        xorShiftSeed ^= (xorShiftSeed << 4);
        return (int) xorShiftSeed;
    }
    
    public static void main(String[] args) {
        // 使用基本类型数组模拟队列，避免自动装箱/拆箱
        char[] queue = new char[QUEUE_SIZE];
        int front = 0;
        int rear = 0;
        int size = 0;
        
        long startTime = System.nanoTime();
        
        for (int i = 0; i < LOOP_COUNT; i++) {
            // 使用更快的随机数生成器
            int randVal = Math.abs(fastRandom());
            // 使用位运算替代模运算（如果CHARSET_LENGTH是2的幂，可以使用位运算）
            int index = randVal % CHARSET_LENGTH;
            char c = CHARSET[index];
            
            // 入队（直接操作数组，避免方法调用）
            queue[rear] = c;
            rear = (rear + 1) % QUEUE_SIZE;
            size++;
            
            // 如果队列超过999，出队（直接操作数组，避免方法调用）
            if (size > 999) {
                front = (front + 1) % QUEUE_SIZE;
                size--;
            }
        }
        
        long endTime = System.nanoTime();
        double elapsed = (endTime - startTime) / 1_000_000.0;
        
        // 输出结果，并使用队列内容避免编译器优化
        System.out.printf("Java: %.6f milliseconds%n", elapsed);
        
        // 防止编译器优化掉整个循环
        long sum = 0;
        for (char ch : queue) {
            sum += ch;
        }
        System.out.println("Sum: " + sum);
    }
}