# C语言性能测试

## 开发环境

- **编译器**：GCC (GNU Compiler Collection)
- **版本要求**：GCC 4.8+ 或兼容编译器
- **操作系统**：Linux, macOS, Windows (使用MinGW或Cygwin)

### Ubuntu 22.04安装命令

```bash
# 更新软件包列表
sudo apt update

# 安装GCC编译器
sudo apt install -y gcc

# 验证安装
gcc --version
```

## 依赖

- 无外部依赖，仅使用C标准库

## 编译命令

```bash
gcc -O2 -o test test.c
```

**参数说明**：
- `-O2`：启用优化级别2，平衡编译时间和运行性能
- `-o test`：指定输出可执行文件名为`test`
- `test.c`：源文件名

## 运行命令

```bash
./test
```

## 代码说明

- 测试内容：100万次队列操作，包括随机字符生成、入队和条件出队
- 数据结构：自定义循环队列（基于数组实现）
- 随机数生成：自定义Xorshift随机数生成器

## 输出示例

```
C: 5.944982 milliseconds
```

## 注意事项

1. 使用`-O2`优化级别可以获得更好的性能
2. 编译生成的`test`文件会被`.gitignore`忽略
3. 运行前确保当前目录下没有同名的`test`文件
4. 可以使用`gcc --version`检查GCC版本