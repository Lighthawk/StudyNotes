# ASM GDB 调测

## 0、常规操作
```shell
gdb filename
(gdb) help 命令名
(gdb) shell linux命令名 参数  # 不退出gdb执行linux
```
- #### 参考链接

  - [汇编指令——用GDB调试汇编](https://zhuanlan.zhihu.com/p/259625135)
## 1、断点调试

```shell
(gdb) break / b ...				# 增加断点
(gdb) clear ... 				# 清除某个断点，同添加断点格式
(gdb) delete					# 清除所有断点
(gdb) info breakpoints/break	# 查看断点
(gdb) disable/enable			# 断点禁用/启用
```

| 表达形式        | 含义                                      | 例如                              |
| --------------- | ----------------------------------------- | --------------------------------- |
| line            | 当前源文件的行号                          | b 20                              |
| function        | 指定函数的开始处                          | b funcName<br>b fileName:funcName |
| label           | 指定标号处？                              | ?                                 |
| -offset/+offset | 当前行之前的偏移量处/当前行之后的偏移量处 | b +2/-2                           |
| *address        | 地址表达式指定的程序地址位置              |                                   |

## 2、单步执行

```shell
(gdb) run/r					# 开始运行
(gdb) continue/c			# 断点后继续
(gdb) jump/j				# 跳转到指定位置
(gdb) kill					# 停止执行
(gdb) step/s 条数			   # 单步进入(step into)，如果遇到有调测信息的子函数，则进入
							# 若想提前结束，finish (step out)
							# 若想直接执行完后续循环体，until/u
							# 若不想执行后续子程序，return
(gdb) next/n 条数			   # 单步通过(step over)，单步一条语句
(gdb) step|next + 条数	   # 执行xx条数后暂停
							# stepi|nexti 机器指令为单位的一个语句
							# 对于汇编，step == stepi, next == nexti
```

## 3、查看数据

### （1）查看信息

```shell
(gdb) help info						# info 帮助
(gdb) info/i ...					# info 任何想看内容
(gdb) i registers/r					# 查看除浮点寄存器和向量寄存器以外的其它寄存器名称和内容
(gdb) i float/vector/all-register	# 查看浮点/向量/所有寄存器
(gdb) i frame/locals/break			# 查看当前堆帧/局部变量/断点
```

### （2）查看表达式

```shell
(gdb) p /f (数据类型)变量名
(gdb) p /f &变量名
```

| (gdb) print/p /f 表达式 | 说明                                             |
| ----------------------- | ------------------------------------------------ |
| 无格式                  | 按原表达式的数据类型输出                         |
| x/d/u/t/f               | 十六进制/有符号十进制/无符号十进制/二进制/浮点数 |
| c                       | 字符                                             |
| a                       | 地址                                             |
| s                       | 字符串                                           |

| (gdb) p /f $寄存器名 | 说明                          |
| -------------------- | ----------------------------- |
| $pc                  | 程序计数器                    |
| $sp                  | 栈指针                        |
| $fp                  | 帧指针?                       |
| $ps                  | 处理器状态?                   |
| $cpsr                | 特指arm处理器状态(此时无 $ps) |
| %eax / %ebp          | p $eax 或 p $ebp              |

| 其它                        | 说明                                                   |
| --------------------------- | ------------------------------------------------------ |
| (gdb) p /f (数据类型)变量名 | 显示变量值，通常加变量类型，否则提示无类型/无法显示    |
| (gdb) p /f &变量名          | 显示变量的存储器地址                                   |
| (gdb) display               | 跟踪观察变量，程序暂停时，display列表中命令会自动显示? |
| (gdb) watch                 | 如果变量变了，才关注用watch设置观察点?                 |

### （3）查看内存

```shell
(gdb) examine/x /nfu 地址
# f 是输出格式，同 print; f 也可以是 i(处理器指令)，利用i，可以得到指定地址处的反汇编指令代码。如何操作？
# n 表示查看内存区域数，默认1，十进制，负值表示地址前的区域
# u 给出内存单位，可以是 b(1字节)/h(半字,2字节)/w(字,4字节)/g(大字,8字节)
# x 查看后，下次查看默认这次的区域长度
# 如果 f 位置为 i，则 u 无意义，可以省略
# 如果 s 字符串输出格式，u 默认是字节 b，也可以用 h 或 w 表示临时输出16位或32位单位的字符串
# 地址，代码区指令标号 -> 显示标号位置内容; &数据区变量名 -> 显示变量值; $通用寄存器名 -> 表示寄存器作为内存指针地址，显示该地址内容
# 默认地址通常是上次查看后的位置，有些指令设置默认地址
```

### （4）查看源程序语句行

```shell
(gdb) list 位置					# 显示指定位置前后的10行源码，不带参数继续使用，表示继续显示10行，带-表示之前10行
(gdb) list 首位置, 末位置
```

### （5）查看反汇编代码

```shell
(gdb) info line 位置
# 使用 info line 后，查看 x 指令的默认地址，就是该语句的起始地址，用 x/i 可以查看机器指令
# disassemble /m 或 /s，显示源码和反汇编代码，带 /r 显示反汇编和十六进制机器码
# 没有指明地址，默认反汇编当前程序计数器所在函数
# 带一个地址，反汇编该地址所在函数
# 带两个地址，反汇编内存范围内代码
```

### （6）查看栈帧

```shell
# 调用子函数都会创建栈帧
# 栈帧在内存地址，由帧指针寄存器($fp)保存; armv8 64位执行状态用 x29 作为栈指针
(gdb) backtrace/bt	# 显示调用栈，别名 info stack 和 where
(gdb) frame/f		# 显示当前栈帧简短描述
(gdb) info frame	# 显示完整栈帧描述
					# (包括栈帧地址、下层级栈帧地址、上层级栈帧地址、源码使用的汇编语言、帧参数地址、局部变量、保存的程序计数器、栈帧保护的寄存器)
```

## 4、修改数据

```shell
(gdb) set var $寄存器名=表达式
(gdb) set var *地址=表达式
(gdb) set var 局部变量名=表达式
# gdb 不能 set/print 直接给全局变量复制，但可以通过 print 或 x 获得其地址，进而 set 该地址赋值，间接修改
```

## 5、layout窗口分割

| 命令                         | 说明                                                     |
| ---------------------------- | -------------------------------------------------------- |
| (gdb) layout src             | 显示源代码窗口                                           |
| (gdb) layout asm             | 显示汇编窗口                                             |
| (gdb) layout regs            | 显示源代码/汇编和寄存器窗口                              |
| (gdb) layout split           | 显示源代码和汇编窗口                                     |
| (gdb) layout next            | 显示下一个layout                                         |
| (gdb) layout prev            | 显示上一个layout                                         |
| (gdb) update                 | 更新源码窗口和当前执行点                                 |
| (gdb) refresh                | 刷新所有窗口                                             |
| ctrl + L                     | 刷新窗口                                                 |
| ctrl + x, 再按 2             | 双窗口模式，显示两个窗口                                 |
| ctrl + x, 再按 a             | 回到传统模式，即退出layout，回到执行layout之前的调试窗口 |
| (gdb) winheight name+/- line | 调整源码窗口高度，name可以为 cmd\|src\|asm\|regs         |
| (gdb) focus name             | 切换当前窗口，name可以为 cmd\|src\|asm\|regs             |
| (gdb) info win               | 显示窗口大小                                             |

## 6、调试示例

```shell
# 内存查看
>i registers $rip                           查看rip寄存器的内容 
>x /i $rip                                      以指令方式查看rip寄存器 
>x /16xw xxx                                以16进制方式，每块的数据类型word，连续显式16个word数据值 
>x /16xb $rip+0x83d623 
>x /s $rdx                                                                         以字符串的方式显示寄存器rdx中的值 
>p /t dst->dev->features                                                打印嵌套结构体中的变量 
>p &((struct sock*)0)->sk_route_caps                             打印出结构体内子项的偏移 
>p  *(struct tcphdr *)(skb->head+skb->transport_header)    打印出结构体的所有值 
>p  *(fn)@12                                                                     打印数组 
>p ((struct proc_inode *)((char *)inode-0x38))->op         打印container_of（）功能 
>set console_printk[0]=4                                                  改变内存中的值 
>set  disassembly-flavor  intel                      设置为intel反汇编模块 
>set print pretty on                                       设置 漂亮格式打印输出 
>ptype  struct workqueue_struct                  显示结构体定义

```

```shell
# 条件断点
# 使用简单的条件断点
>b  10 if index == 3        

# 使用复杂的条件断点
>commands 22                        
->if (vport->port_no!=4)
->bt
->c
->else
->bt
->end
```

```shell
# 内核模块调试
# 查看指定内核模块的内存加载地址
#cat /proc/modules |grep tun                                                                            
# 为指定模块加载symbol文件
>add-symbol-file /home/dawei/nzuta/nzuta.ko  0xffffffffa0423000       

```

## 7、调试脚本

#### （1）.gdbinit

> 通常放在 ~/.gdbinit 中，主要用于 gdb 高级配置，显示配置等，
>
> 内容摘自：[gdbinit 使用(转)_如何生效gdbinit-CSDN博客](https://blog.csdn.net/lord_is_layuping/article/details/89402963)

```shell
# 保存历史命令
set history filename ./.gdb_history
set history save on
 
 
# 记录执行gdb的过程
set logging file ./.log.txt
set logging on
 
 
# 退出时不显示提示信息
#set confirm off
 
 
# 打印数组的索引下标
set print array-indexes on
 
 
# 每行打印一个结构体成员
set print pretty on
 
 
# 退出并保留断点
define qbp
save breakpoints ./.gdb_bp
quit
end
document qbp
Exit and save the breakpoint
end
 
 
# 保留历史工作断点
define downbp
save breakpoints ./.gdb_bp
end
document downbp
Save the historical work breakpoint
end
 
 
# 加载历史工作断点
define loadbp
source ./.gdb_bp
end
document loadbp
Load the historical work breakpoint
end
```



#### （2） cmd.gdb

> 启动 gdb 调试时，可以通过命令灌入已有的 gdb 脚本，一键到达期望的 debug 点，对于反复调测复杂工程比较有用
>
> 内容摘自：[用gdb脚本进行自动化调试_gdb本来就支持自定义脚本辅助调试-CSDN博客](https://blog.csdn.net/nirendao/article/details/105910753)

```shell
gdb --batch --command=cmd.gdb --args test.exe <add necessary parameters here>
# 1. “–batch” 的含义是，该gdb命令将在命令行中运行，运行结束后，光标仍停留在命令行；
# 假设不加 “–batch”, 则命令执行结束后，会停留再gdb的互动界面 (假设脚本最后没有 quit 语句。因以上脚本最后有quit，所以即使不在batch模式，也# 依然会退出gdb到达命令行。)
# 2. “–command” 指定gdb脚本
# 3. 若已在 “–args” 中指定了运行参数，则不要在gdb脚本的 run 命令后再指定运行参数了；否则，run命令中的运行参数会覆盖 “–args” 中的运行参数。

```

