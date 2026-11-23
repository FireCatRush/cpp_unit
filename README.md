C++ Tutorials

## 目录结构

```
learncpp/
├─ chapter4/ chapter5/ ...   源码
├─ build/                    编译产物（已在 .gitignore 里）
├─ Makefile                  编译规则（自动扫描源码，新增文件不用改）
├─ build.bat                 一键编译全部，双击就能跑
└─ cp_and_run.bat            编译并运行
```

## 怎么用

新开一章、新写一个练习，不用再手敲 gcc 命令：

- 双击 `build.bat`：只编译有改动的文件，exe 放到 `build\` 下。
- 双击 `cp_and_run.bat`：编译并运行“最近修改”的那个 `.cpp`。
- 把 `.cpp` 文件拖到 `cp_and_run.bat` 上：编译并运行这一个。
- 在命令行里（先 `cd learncpp`）：

```
cp_and_run.bat chapter8\8.6\main.cpp
cp_and_run.bat chapter8\8.6\main.cpp 参数1 参数2
build.bat
build.bat clean
mingw32-make
mingw32-make clean
```

## 规则

- 所有 `chapter*` 下的 `.cpp` 都会被自动扫描，新增文件不用改 Makefile。
- 目录里**没有** `main.cpp`：每个 `.cpp` 各自编成一个独立的 exe。
- 目录里**有** `main.cpp`：整个目录链接成一个 exe，名字取目录名（多文件练习）。
- 产物路径照抄源码目录：

```
chapter4/4.10.Q2_prime-number.cpp -> build/chapter4/4.10.Q2_prime-number.exe
chapter7/7.x/q2/main.cpp          -> build/chapter7/7.x/q2/q2.exe
```

- 只有注释、还没写 `main()` 的练习只编译成 `.o`，不会报一堆链接错误。
- 改了 `.h` 会自动重编引用它的 `.cpp`（`-MMD -MP`），不用手动清理。

## 改编译选项

Makefile 开头几行：

```
CXXSTD   := -std=c++20
WARN     := -Wall -Wextra -Wpedantic
OPT      := -O2
```

依赖的是 MinGW 的 `g++` 和 `mingw32-make`（两者都要在 PATH 里）。链接必须用
`g++` 而不是 `gcc`，否则 C++ 标准库不会被链进去，会出现 `undefined reference to std::cout`。
