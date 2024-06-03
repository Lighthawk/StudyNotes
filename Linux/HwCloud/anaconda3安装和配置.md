# anaconda3 安装和配置

# 2024-05-22 Lighthawk@126.com

## 安装 python

```shell
# 先安装 OS 依赖
yum install -y zlib zlib-devel libffi-devel openssl openssl-devel

# 下载 python，编译安装
wget https://www.python.org/ftp/python/3.10.14/Python-3.10.14.tgz
tar -xf Python-3.10.14.tgz
cd Python-3.10.14
./configure --enable-shared  --enable-optimizations
make clean && make -j 32 && make install

# 新版本软连接
rm -rf /usr/bin/python
ln -sf /usr/local/bin/python3 /usr/bin/python

# 修改环境变量
vim /etc/profile
### 其他多余环境变量先注释掉
export PYTHONPATH=${PYTHONPATH}:/usr/local/bin
###
env | grep PYTHON
source /etc/profile
```



## 安装 Anaconda3

```shell
./Anaconda3-2024.02-1-Linux-x86_64.sh
# 一路 yes
```



## 配置 Anaconda3 运行环境

```shell
# 失败的一种配置， -n 和 --prefix 不能一起用，--prefix 不能缩写为 -p，会有配置冲突
conda create -n dcvc_fm --prefix /home/workspace/open_source/DCVC/DCVC-FM/ws python=3.10

# 正确的方法：新建 ws 目录，配置到这里，后面跟着提示走（为啥命令行前面多了个 base ?）：
(base) [root@localhost ws]# conda create --prefix /home/workspace/open_source/DCVC/DCVC-FM/ws python=3.10
WARNING: A directory already exists at the target location '/home/workspace/open_source/DCVC/DCVC-FM/ws'
but it is not a conda environment.
Continue creating environment (y/[n])? y

Channels:
 - defaults
Platform: linux-64
Collecting package metadata (repodata.json): done
Solving environment: done

## Package Plan ##

  environment location: /home/workspace/open_source/DCVC/DCVC-FM/ws

  added / updated specs:
    - python=3.11


The following packages will be downloaded:

    package                    |            build
    ---------------------------|-----------------
    bzip2-1.0.8                |       h5eee18b_6         262 KB
    ca-certificates-2024.3.11  |       h06a4308_0         127 KB
    libffi-3.4.4               |       h6a678d5_1         141 KB
    openssl-3.0.13             |       h7f8727e_1         5.2 MB
    pip-24.0                   |  py311h06a4308_0         3.3 MB
    python-3.11.9              |       h955ad1f_0        32.9 MB
    setuptools-69.5.1          |  py311h06a4308_0         1.3 MB
    sqlite-3.45.3              |       h5eee18b_0         1.2 MB
    tk-8.6.14                  |       h39e8969_0         3.4 MB
    tzdata-2024a               |       h04d1e81_0         116 KB
    wheel-0.43.0               |  py311h06a4308_0         146 KB
    xz-5.4.6                   |       h5eee18b_1         643 KB
    zlib-1.2.13                |       h5eee18b_1         111 KB
    ------------------------------------------------------------
                                           Total:        48.9 MB

The following NEW packages will be INSTALLED:

  _libgcc_mutex      pkgs/main/linux-64::_libgcc_mutex-0.1-main 
  _openmp_mutex      pkgs/main/linux-64::_openmp_mutex-5.1-1_gnu 
  bzip2              pkgs/main/linux-64::bzip2-1.0.8-h5eee18b_6 
  ca-certificates    pkgs/main/linux-64::ca-certificates-2024.3.11-h06a4308_0 
  ld_impl_linux-64   pkgs/main/linux-64::ld_impl_linux-64-2.38-h1181459_1 
  libffi             pkgs/main/linux-64::libffi-3.4.4-h6a678d5_1 
  libgcc-ng          pkgs/main/linux-64::libgcc-ng-11.2.0-h1234567_1 
  libgomp            pkgs/main/linux-64::libgomp-11.2.0-h1234567_1 
  libstdcxx-ng       pkgs/main/linux-64::libstdcxx-ng-11.2.0-h1234567_1 
  libuuid            pkgs/main/linux-64::libuuid-1.41.5-h5eee18b_0 
  ncurses            pkgs/main/linux-64::ncurses-6.4-h6a678d5_0 
  openssl            pkgs/main/linux-64::openssl-3.0.13-h7f8727e_1 
  pip                pkgs/main/linux-64::pip-24.0-py311h06a4308_0 
  python             pkgs/main/linux-64::python-3.11.9-h955ad1f_0 
  readline           pkgs/main/linux-64::readline-8.2-h5eee18b_0 
  setuptools         pkgs/main/linux-64::setuptools-69.5.1-py311h06a4308_0 
  sqlite             pkgs/main/linux-64::sqlite-3.45.3-h5eee18b_0 
  tk                 pkgs/main/linux-64::tk-8.6.14-h39e8969_0 
  tzdata             pkgs/main/noarch::tzdata-2024a-h04d1e81_0 
  wheel              pkgs/main/linux-64::wheel-0.43.0-py311h06a4308_0 
  xz                 pkgs/main/linux-64::xz-5.4.6-h5eee18b_1 
  zlib               pkgs/main/linux-64::zlib-1.2.13-h5eee18b_1 


Proceed ([y]/n)? y


Downloading and Extracting Packages:
                                                                                                                                                                                       
Preparing transaction: done                                                                                                                                                            
Verifying transaction: done                                                                                                                                                            
Executing transaction: done                                                                                                                                                            
#                                                                                                                                                                                      
# To activate this environment, use                                                                                                                                                    
#                                                                                                                                                                                      
#     $ conda activate /home/workspace/open_source/DCVC/DCVC-FM/ws                                                                                                                     
#                                                                                                                                                                                      
# To deactivate an active environment, use                                                                                                                                             
#                                                                                                                                                                                      
#     $ conda deactivate

## 执行 conda activate /home/workspace/open_source/DCVC/DCVC-FM/ws，目录结构变了
conda activate /home/workspace/open_source/DCVC/DCVC-FM/ws
(/home/workspace/open_source/DCVC/DCVC-FM/ws) [root@localhost ws]# 

## 再安装 ws 需要依赖的环境组件，看这么复杂的环境，应该很耗时
conda install pytorch==2.0.0 torchvision==0.15.0 torchaudio==2.0.0 pytorch-cuda=11.8 -c pytorch -c nvidia

## 通常再根据 requirements.txt，安装 python 组件，eg：
pip install -r requirements.txt
# requirements.txt：
# numpy>=1.20.0
# scipy
# matplotlib
# torch>=2.0.0
# tensorboard
# tqdm
# bd-metric
# ptflops

## 至此，conda 环境准备完毕
## 坑点。。。在调测 DCVC-FM 时，python 版本一定不要侥幸心理用高的，后期配置特别容易卡在版本配套上
```



## 删除 Anaconda3 配置

```shell
删除虚拟环境：
conda remove -n env_name --all
或者
conda remove --prefix /home/workspace/open_source/DCVC/DCVC-FM/ws --all

conda remove --help:
Remove the package 'scipy' from the currently-active environment::
    conda remove scipy

Remove a list of packages from an environemnt 'myenv'::
    conda remove -n myenv scipy curl wheel

Remove all packages from environment `myenv` and the environment itself::
    conda remove -n myenv --all

Remove all packages from the environment `myenv` but retain the environment::
    conda remove -n myenv --all --keep-env
```



## Anaconda3 常用命令

>打开终端，并使用以下命令创建一个新的Conda环境：
>conda create --name myenv
>
>
>
>激活新环境：
>conda activate myenv
>
>
>
>安装所需的软件包。例如，要安装numpy，请使用以下命令：
>conda install numpy
>
>
>
>删除所需的软件包。例如，要安装numpy，请使用以下命令：
>
>conda remove numpy
>
>
>
>在环境中运行程序：
>python myprogram.py
>
>
>
>当完成使用环境时，可以使用以下命令停用环境：
>conda deactivate