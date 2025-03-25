# qt
QT 5.9.1 MinGW 32bit
串口控制的检测仪器上位机

电位均衡（直流接地）和绝缘测试项

2023 12.30
升级为QT5.14

2024 02.25
新增readpress程序 读取串口压力传感器值并保持数据库

2024 0424
新增uploadwebapi工程 由qt开发的http post功能，将数据库中的数据读取并以JSON的格式POST到服务器
注意 qt WEBAPI对象与应答对象为异步处理方式，而且无法夸线程使用
	QT 读取无法连接到的sqlserver数据库时阻塞时间较长 需要优化
	
新增electric工程 次工程为读取电参功能软件

2025 0325
安装QT最新版本 QT最新版本需要在线安装
5.15以下版本可以下载离线安装包安装
5.14版本下载方案:
Qt5.14
https://download.qt.io/archive/qt/5.14/5.14.2/qt-opensource-windows-x86-5.14.2.exe
此链接国内无法正常下载，链接拷到迅雷可正常下载。
安装完成后需要更新组件的话可以配置用户自定义档案 配置方法：
https://download.qt.io/static/mirrorlist/  中查找中国镜像地址 点击HTTP
找到以下路径
https://mirrors.ustc.edu.cn/qtproject/online/qtsdkrepository/windows_x86/root/qt/
输入到档案中保存测试。

Qt6.8在线安装教程
在线安装包下载，官网需要填公司信息 直接pass
https://mirrors.tuna.tsinghua.edu.cn/qt/official_releases/online_installers/
在清华大学镜像中找到win64的安装包 下载后安装
安装速度极慢 需要科学网或者配置镜像地址
打开终端 输入C:\Users\14417\Downloads> .\qt-online-installer-windows-x64-online.exe --mirror https://mirrors.ustc.edu.cn/qtproject/
后面的镜像不是清华大学，清华大学镜像安装QT会疯狂报错辣鸡，使用此镜像一边过。
