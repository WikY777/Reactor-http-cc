# ReactorHttp-Cpp
本项目基于主从 Reactor 多线程模型，实现支持 select/poll/epoll 三种 IO 多路复用的高并发 HTTP 静态服务器，提供 C 面向过程、C++ 面向对象两套实现，用于处理静态资源 GET 请求。

## 项目结构
- common：公共工具、日志、基础封装
- reactor：Reactor事件循环核心，epoll封装
- tcp：TCP连接封装，Buffer缓冲区，半包粘包处理
- http：HTTP请求解析、响应构造
- thread：线程池实现
- main.cpp：程序入口
- CMakeLists.txt：编译脚本

## 环境
Ubuntu Linux, C++17, CMake

## 编译
```bash
mkdir build && cd build
cmake ..
make

