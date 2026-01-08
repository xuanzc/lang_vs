# Java语言性能测试

## 开发环境

- **JDK**：Java Development Kit
- **版本要求**：JDK 8+ 或 OpenJDK 8+
- **安装方式**：
  - 从官网下载安装包：https://www.oracle.com/java/technologies/downloads/
  - 或使用包管理器安装OpenJDK
- **IDE推荐**：IntelliJ IDEA, Eclipse, NetBeans
- **操作系统**：Linux, macOS, Windows

### Ubuntu 22.04安装命令

#### 安装OpenJDK 17（推荐，Ubuntu 22.04默认版本）

```bash
# 更新软件包列表
sudo apt update

# 安装OpenJDK 17 JDK
sudo apt install -y openjdk-17-jdk

# 验证安装
java --version
javac --version
```

#### 安装其他版本的OpenJDK（可选）

```bash
# 安装OpenJDK 11 JDK
sudo apt install -y openjdk-11-jdk

# 安装OpenJDK 8 JDK
sudo apt install -y openjdk-8-jdk
```

#### 设置默认Java版本（可选）

```bash
# 列出已安装的Java版本
sudo update-alternatives --config java

# 按照提示输入对应编号选择默认版本

# 同样设置javac的默认版本
sudo update-alternatives --config javac
```

## 依赖

- 无外部依赖，仅使用Java标准库

## 编译命令

### 使用javac编译

```bash
javac Test.java
```

**参数说明**：
- `Test.java`：源文件名
- 编译后生成`Test.class`文件

### 使用javac编译并指定输出目录

```bash
javac -d . Test.java
```

**参数说明**：
- `-d .`：指定编译输出目录为当前目录

## 运行命令

### 使用java运行

```bash
java Test
```

**参数说明**：
- `Test`：类名（不含`.class`扩展名）

### 使用java -cp指定类路径

```bash
java -cp . Test
```

**参数说明**：
- `-cp .`：指定类路径为当前目录

## 代码说明

- 测试内容：100万次队列操作，包括随机字符生成、入队和条件出队
- 数据结构：使用数组模拟循环队列
- 随机数生成：自定义Xorshift随机数生成器

## 输出示例

```
Java: 21.707181 milliseconds
Sum: 87855
```

## 注意事项

1. 编译生成的`.class`文件会被`.gitignore`忽略
2. 可以使用`java --version`或`javac --version`检查Java版本
3. 确保编译和运行时使用相同版本的Java
4. 对于复杂项目，推荐使用构建工具如Maven或Gradle
5. 可以使用`javac -verbose Test.java`查看详细编译过程
6. 可以使用`java -Xmx512m Test`指定JVM最大内存

## 代码优化说明

本项目中的Java代码已经过优化：

1. 使用基本类型数组替代容器类，避免自动装箱/拆箱
2. 实现了高效的Xorshift随机数生成器
3. 减少了方法调用，直接操作数组
4. 避免了频繁的对象创建
5. 添加了防止编译器优化的代码，确保测试结果准确

这些优化措施显著提高了Java代码的性能表现。