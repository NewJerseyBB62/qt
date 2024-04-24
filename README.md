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