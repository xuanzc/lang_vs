using System;
using System.Collections.Generic;
using System.Diagnostics;

class Program
{
    const int LOOP_COUNT = 1000000;
    const string CHARSET = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
    // 使用静态只读字段，因为Length属性不是编译时常量
    private static readonly int CHARSET_LENGTH = CHARSET.Length;
    
    // 静态Random对象，避免频繁创建
    private static readonly Random _random = new Random();
    
    static void Main()
    {
        Queue<char> q = new Queue<char>(1000); // 预分配容量
        Stopwatch stopwatch = Stopwatch.StartNew();
        
        for (int i = 0; i < LOOP_COUNT; i++)
        {
            // 生成随机字符并入队（内联实现，减少函数调用开销）
            char c = CHARSET[_random.Next(CHARSET_LENGTH)];
            q.Enqueue(c);
            
            // 如果队列超过999，出队
            if (q.Count > 999)
            {
                q.Dequeue();
            }
        }
        
        stopwatch.Stop();
        Console.WriteLine($"C#: {stopwatch.Elapsed.TotalMilliseconds} milliseconds");
    }
}