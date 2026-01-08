# Rust语言性能测试

## 开发环境

- **工具链**：Rust toolchain (包含rustc编译器和cargo构建工具)
- **版本要求**：Rust 1.56+ (支持2021版语法)
- **安装方式**：使用rustup安装（推荐）
  ```bash
  curl --proto '=https' --tlsv1.2 -sSf https://sh.rustup.rs | sh
  ```
- **操作系统**：Linux, macOS, Windows

### Ubuntu 22.04安装命令

#### 方法1：使用apt包管理器安装（推荐，简单快捷）

```bash
# 更新软件包列表
sudo apt update

# 安装Rust开发环境
sudo apt install -y rustc cargo

# 验证安装
rustc --version
cargo --version
```

#### 方法2：使用rustup安装（官方推荐，支持多版本管理）

```bash
# 更新软件包列表
sudo apt update

# 安装必要的依赖项
sudo apt install -y curl build-essential libssl-dev libffi-dev 

# 安装Rust toolchain
curl --proto '=https' --tlsv1.2 -sSf https://sh.rustup.rs | sh

# 配置环境变量（当前会话）
source $HOME/.cargo/env

# 永久配置环境变量（将以下行添加到~/.bashrc或~/.zshrc）
echo 'export PATH="$HOME/.cargo/bin:$PATH"' >> ~/.bashrc

# 验证安装
rustc --version
cargo --version
```

## 依赖

- 无外部依赖，仅使用Rust标准库

## 编译命令

### 使用rustc直接编译

```bash
rustc -O test.rs
```

**参数说明**：
- `-O`：启用优化，相当于`-C opt-level=2`
- `test.rs`：源文件名

### 使用cargo构建

```bash
cargo build --release
```

**参数说明**：
- `--release`：启用发布模式，生成优化的可执行文件

## 运行命令

### 直接运行可执行文件

```bash
./test
```

### 使用cargo运行

```bash
cargo run --release
```

## 代码说明

- 测试内容：100万次队列操作，包括随机字符生成、入队和条件出队
- 数据结构：使用Rust标准库的`VecDeque`
- 随机数生成：自定义线性同余生成器（线程安全）

## 输出示例

```
Rust: 6.334495 milliseconds
```

## 注意事项

1. 使用`-O`或`--release`优化可以获得更好的性能
2. 编译生成的`test`文件和`target`目录会被`.gitignore`忽略
3. 可以使用`rustc --version`或`cargo --version`检查Rust版本
4. 首次运行cargo会创建`Cargo.lock`文件，记录依赖版本
5. 使用`cargo clean`可以清理编译生成的文件

## Cargo.toml说明

项目包含`Cargo.toml`文件，用于cargo构建系统：

- 定义了项目名称、版本和作者
- 指定了Rust版本要求
- 声明了无外部依赖

可以使用`cargo check`命令快速检查代码语法错误，不生成可执行文件。