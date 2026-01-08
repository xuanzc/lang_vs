# C#语言性能测试

## 开发环境

- **SDK**：.NET SDK
- **版本要求**：.NET 6.0+ 或 .NET Framework 4.7.2+
- **安装方式**：
  - 从官网下载安装包：https://dotnet.microsoft.com/download
  - 或使用包管理器安装
- **IDE推荐**：Visual Studio, Visual Studio Code (with C# extension), Rider
- **操作系统**：Linux, macOS, Windows

### Ubuntu 22.04安装命令

```bash
# 更新软件包列表
sudo apt update

# 安装必要的依赖项
sudo apt install -y apt-transport-https 

# 添加Microsoft包源密钥
wget https://packages.microsoft.com/config/ubuntu/22.04/packages-microsoft-prod.deb -O packages-microsoft-prod.deb
sudo dpkg -i packages-microsoft-prod.deb
rm packages-microsoft-prod.deb

# 更新软件包列表，包含Microsoft包源
sudo apt update

# 安装.NET SDK 8.0（最新LTS版本）
sudo apt install -y dotnet-sdk-8.0

# 验证安装
dotnet --version
```

### 可选：安装特定版本的.NET SDK

```bash
# 安装.NET SDK 6.0（LTS版本）
sudo apt install -y dotnet-sdk-6.0

# 安装.NET SDK 7.0
sudo apt install -y dotnet-sdk-7.0
```

## 依赖

- 无外部依赖，仅使用.NET标准库

## 编译命令

### 使用dotnet build编译

```bash
dotnet build -c Release
```

**参数说明**：
- `-c Release`：指定构建配置为Release（优化构建）
- `csharp.csproj`：项目文件（自动查找）

### 生成自包含可执行文件

```bash
dotnet publish -c Release -r linux-x64 --self-contained true
```

**参数说明**：
- `-r linux-x64`：指定运行时标识符（根据目标平台调整）
- `--self-contained true`：生成包含运行时的自包含可执行文件

## 运行命令

### 使用dotnet run运行

```bash
dotnet run -c Release
```

**参数说明**：
- `-c Release`：使用Release配置运行

### 直接运行编译后的程序

```bash
./bin/Release/net8.0/csharp
```

**说明**：
- 路径可能根据.NET版本和配置略有不同

## 代码说明

- 测试内容：100万次队列操作，包括随机字符生成、入队和条件出队
- 数据结构：使用.NET标准库的`Queue<char>`
- 随机数生成：使用.NET标准库的`Random`类（静态实例）

## 输出示例

```
C#: 15.0721 milliseconds
```

## 注意事项

1. 使用Release配置可以获得更好的性能
2. 编译生成的`bin`和`obj`目录会被`.gitignore`忽略
3. 可以使用`dotnet --version`检查.NET SDK版本
4. 项目文件`csharp.csproj`定义了项目的基本配置
5. 首次运行会下载必要的.NET运行时组件（如果需要）

## 项目文件说明

`csharp.csproj`文件包含以下主要配置：

- 项目SDK类型（`Microsoft.NET.Sdk`）
- 目标框架（如`.NET 8.0`）
- 输出类型（控制台应用）
- 其他编译选项

可以通过编辑此文件来修改项目配置，例如更改目标框架版本。