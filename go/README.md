# Go语言性能测试

## 开发环境

- **编译器**：Go编译器 (gc)
- **版本要求**：Go 1.16+ (支持模块系统)
- **安装方式**：
  - 从官网下载安装包：https://golang.org/dl/
  - 或使用包管理器安装
- **操作系统**：Linux, macOS, Windows

### Ubuntu 22.04安装命令

#### 使用apt包管理器安装（推荐）

```bash
# 更新软件包列表
sudo apt update

# 安装Go编译器
sudo apt install -y golang-go

# 验证安装
go version
```

#### 从官网下载最新版本（可选）

```bash
# 下载Go 1.21.5（最新稳定版，根据需要调整版本）
wget https://go.dev/dl/go1.21.5.linux-amd64.tar.gz

# 解压到/usr/local
sudo tar -C /usr/local -xzf go1.21.5.linux-amd64.tar.gz

# 配置环境变量（当前会话）
export PATH=$PATH:/usr/local/go/bin

# 永久配置环境变量（将以下行添加到~/.bashrc或~/.zshrc）
echo 'export PATH="$PATH:/usr/local/go/bin"' >> ~/.bashrc

# 验证安装
go version
```

## 依赖

- 无外部依赖，仅使用Go标准库

## 编译命令

### 使用go build编译

```bash
go build -o test test.go
```

**参数说明**：
- `-o test`：指定输出可执行文件名为`test`
- `test.go`：源文件名

### 使用go install安装

```bash
go install test.go
```

**说明**：
- 将编译后的可执行文件安装到`$GOPATH/bin`或`$GOBIN`目录

## 运行命令

### 直接运行可执行文件

```bash
./test
```

### 使用go run直接运行

```bash
go run test.go
```

**说明**：
- 编译并立即运行，不生成可执行文件

## 代码说明

- 测试内容：100万次队列操作，包括随机字符生成、入队和条件出队
- 数据结构：使用切片模拟队列操作
- 随机数生成：自定义Xorshift随机数生成器

## 输出示例

```
Go: 8.151746 milliseconds
```

## 注意事项

1. Go编译器会自动优化代码，无需显式指定优化级别
2. 编译生成的`test`文件会被`.gitignore`忽略
3. 可以使用`go version`检查Go版本
4. 使用`go env`可以查看Go环境变量
5. 对于简单程序，推荐使用`go run`快速运行

## Go模块说明

本项目为简单的单文件程序，未使用Go模块。如果需要将其转换为模块：

1. 初始化模块：
   ```bash
   go mod init github.com/username/lang_vs/go
   ```

2. 添加依赖（如果有）：
   ```bash
   go get github.com/your/dependency
   ```

3. 构建程序：
   ```bash
   go build
   ```