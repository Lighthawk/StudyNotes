# vscode配置

大部分直接通过首选项里搜索即可

- ###### 常用

  > 字体：Cascadia Code
  >
  > 字号：15px

- ###### 插件

  >ASM Code Lens
  >
  >Bazel
  >
  >C/C++
  >
  >C/C++ Extension Pack
  >
  >CMake
  >
  >CMake Tools
  >
  >Highlight
  >
  >indent-rainbow
  >
  >IntelliCode
  >
  >Markdown All in One
  >
  >Rainbow Brackets
  >
  >SFTP
  >
  >GDB syntax
  >
  >vscode-pdf

- ###### 连接linux

  - wsl，插件安装后，在wsl插件中可以直接进入linux环境，并直接使用环境上的工具

  - 另一台linux服务器：
  
    > 通过配置 ssh，使得 Windows 上的 Vscode 连到 Linux 上，并打开远端 Linux 里的目录，使用里面的工具
    >
    > 参考博客：[vscode的远程开发与调试——以C/Ｃ＋＋为例_vscode c++远程调试-CSDN博客](https://blog.csdn.net/lengye7/article/details/129401570)
    >
    > 1、首先先在 Linux 更改 ssh 配置：
    >
    > vim /etc/ssh/sshd_config  # 打开 ssh 配置
    >
    > AllowTcpForwarding yes    # 开启，否则远程端口转发会失败（参考博客：[SSH端口转发三种方式看这个就够了_allowtcpforwarding-CSDN博客](https://blog.csdn.net/weixin_43103300/article/details/116277005)）
    >
    > systemctl restart sshd    # 重启ssh服务
    >
    > 2、安装插件：Remote - SSH
    >
    > 3、打开插件配置，写入正确的配置文件：
    >
    > Host <显示的服务器名字>
    >     HostName <服务器的ip>
    >     Port 22
    >     User <ssh登录的用户名>
    >
    > 4、随后连接远端即可（详细操作看博客咯）
    >
    > 5、推荐配置免密登录：
    >
    > （1）拷贝 Windows 当前用户的公钥，一般在 C:\Users\用户名\\\.ssh\id_rsa.pub 文件里；如果没有，在 powershell/cmd 里输入：ssh-keygen -t rsa 后，一路回车即可
    >
    > （2）在 Linux 远端服务器，输入：echo "（1）中复制的公钥内容" >> ~/.ssh/authorized_keys。如果是root登录，
    >
    > （3）再次从Windows连接Linux或打开Linux目录时，就没有密码提示了



