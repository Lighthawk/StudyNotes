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

- ###### yum install -y gcc g++ cmake make nasm perf strace tree git man-pages dos2unix


## 构建工具

- ###### 1、bazel
- ###### 2、

###### 留意
- ###### 1、yasm 不容易安装，一般先不搞

## /etc/profile
```shell
TMOUT=0
# WindTerm 记得配置 live 保活
```