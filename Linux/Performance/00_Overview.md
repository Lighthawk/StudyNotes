# 00、总览 - 想任何情况下，能剖开linux看到里面到底在做什么

## Linux Performance Tools
![Linux Performance Tools](.assets\v2-22400eb0948e28e986ee3a6d9fa5b588_r.jpg)

##


## ebpf Tools
![Linux Performance Tools](.assets\v2-9d70261114d9a29d55d152e265299108_720w.webp)

##

- 大佬的链接 [Link](https://www.brendangregg.com/linuxperf.html)：
- 静态代码检测工具或平台：cppcheck、PC-lint、Coverity、QAC C/C++、Clang-Tidy、Clang Static Analyzer、SonarQube+sonar-cxx（推荐）、Facebook的inferprofiling工具：gnu prof、Oprofile、google gperftools（推荐）、perf、intel VTune、AMD CodeAnalyst
- 内存泄漏：valgrind、AddressSanitizer（推荐）、mtrace、dmalloc、ccmalloc、memwatch、debug_new
- CPU使用率：pidstat（推荐）、vmstat、mpstat、top、sar
- 上下文切换：pidstat（推荐）、vmstat
- 网络I/O：dstat、tcpdump（推荐）、sar
- 磁盘I/O：iostat（推荐）、dstat、sar系
- 统调用追踪：strace（推荐）
- 网络吞吐量：iftop、nethogs、sar
- 网络延迟：ping
- 文件系统空间：df
- 内存容量：free、vmstat（推荐）、sar
- 进程内存分布：pmap
- CPU负载：uptime、top
- 软中断硬中断：/proc/softirqs、/proc/interrupts