#!/bin/bash

echo "=== 编译所有程序 ==="

# 编译C程序
echo "编译C程序..."
gcc -O2 -o c/test c/test.c 2>/dev/null
if [ $? -eq 0 ]; then
    echo "C程序编译成功"
else
    echo "C程序编译失败"
fi

# 编译C++程序
echo "编译C++程序..."
g++ -O2 -o cpp/test cpp/test.cpp 2>/dev/null
if [ $? -eq 0 ]; then
    echo "C++程序编译成功"
else
    echo "C++程序编译失败"
fi

# 编译Rust程序
echo "编译Rust程序..."
cd rust && rustc -O test.rs 2>/dev/null && cd ..
if [ $? -eq 0 ]; then
    echo "Rust程序编译成功"
else
    echo "Rust程序编译失败"
fi

# 编译Go程序
echo "编译Go程序..."
cd go && go build -o test test.go 2>/dev/null && cd ..
if [ $? -eq 0 ]; then
    echo "Go程序编译成功"
else
    echo "Go程序编译失败"
fi

# 编译C#程序
echo "编译C#程序..."
cd csharp && dotnet build -c Release 2>/dev/null && cd ..
if [ $? -eq 0 ]; then
    echo "C#程序编译成功"
else
    echo "C#程序编译失败"
fi

# 编译Java程序
echo "编译Java程序..."
cd java && javac Test.java 2>/dev/null && cd ..
if [ $? -eq 0 ]; then
    echo "Java程序编译成功"
else
    echo "Java程序编译失败"
fi

echo -e "\n=== 运行所有程序 ==="

# 运行C程序
echo "运行C程序..."
./c/test

# 运行C++程序
echo "运行C++程序..."
./cpp/test

# 运行Rust程序
echo "运行Rust程序..."
./rust/test

# 运行Go程序
echo "运行Go程序..."
./go/test

# 运行C#程序
echo "运行C#程序..."
cd csharp && dotnet run -c Release 2>/dev/null && cd ..

# 运行Java程序
echo "运行Java程序..."
cd java && java Test 2>/dev/null && cd ..

# 运行Python程序
echo "运行Python程序..."
python3 python/test.py

echo -e "\n=== 测试完成 ==="