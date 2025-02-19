# Alpaca的LeetCode笔记

项目结构

```bash
Leetcode/
├── .vscode/                 # VSCode 配置文件
│   ├── settings.json       # 工作区设置
│   ├── tasks.json          # 自定义编译任务
│   └── launch.json         # 调试配置
├── src/                    # 存放题目源码
│   ├── 0001-two-sum.c      # 按题号命名（例：LeetCode 第1题）
│   ├── 0002-add-two-numbers.c
│   ├── ......
│   ├── ......
│   └── utils/             # 公共工具函数（如链表、树结构等）
│       ├── linkedlist.h   # 链表定义
│       └── tree.h         # 二叉树定义
├── tests/                  # 测试用例
│   ├── 0001-two-sum_test.c # 针对题目的测试文件
│   └── test_runner.c       # 统一运行所有测试的主程序
├── bin/                    # 存放编译后的可执行文件
├── CNotes.md				# 部分笔记（大部分思考内容都包含在源码注释中）
└── README.md               # 项目说明
```

该仓库主要使用C语言，我是想就先写着，边写边熟悉C的操作，定期汇总笔记，之前大多数时间使用Java环境，python环境用过一段时间

目前除了感觉指针很啰嗦并没有什么别的感想（20250219编）