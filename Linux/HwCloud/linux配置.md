# linux通用配置

## OpenEuler源

> /etc/yum.repos.d/openEuler.repo 需要更改：
>
> https://repo.huaweicloud.com/openeuler/openEuler-22.03-LTS-SP2
>
> %s/xxx/repo.huaweicloud.com\/openeuler/g
>
> rpm下载：
>
> https://repo.huaweicloud.com/openeuler/


## OS tools

> yum install -y gcc g++ cmake make nasm perf strace tree git man-pages dos2unix


## 构建工具

> bazel


## 留意

> 1、yasm 不容易安装，一般先不搞



## /etc/profile

```shell
TMOUT=0
# WindTerm 记得配置 live 保活

# 配合其他开源编译和安装目录，手动添加 LD_LIBRARY_PATH，比如 ffmpeg
export LD_LIBRARY_PATH=/usr/local/lib:/usr/local/lib64:$LD_LIBRARY_PATH
```



## 不常用命令备忘

```shell
# 关机
poweroff
```

