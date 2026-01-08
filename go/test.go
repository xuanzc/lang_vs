package main

import (
	"fmt"
	"time"
)

const (
	loopCount  = 1000000
	queueSize  = 1000
	charset    = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789"
	charsetLen = len(charset)
)

// 简单的线性同余生成器，比math/rand更快
var rngState uint64

func fastRand() uint64 {
	rngState = rngState*6364136223846793005 + 1
	return rngState
}

func main() {
	// 初始化随机数种子
	rngState = uint64(time.Now().UnixNano())

	// 使用切片模拟队列，预分配容量
	queue := make([]byte, 0, queueSize)
	start := time.Now()

	for i := 0; i < loopCount; i++ {
		// 生成随机字符（使用更快的随机数生成）
		idx := int(fastRand() % uint64(charsetLen))
		c := charset[idx]

		// 入队
		queue = append(queue, c)

		// 如果队列超过999，出队（直接切片，避免链表操作）
		if len(queue) > 999 {
			queue = queue[1:]
		}
	}

	elapsed := time.Since(start)
	fmt.Printf("Go: %f milliseconds\n", elapsed.Seconds()*1000.0)
}
