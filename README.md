# C/C++编程以及Git操作练习(使用VSCode)
## 1. `VSCode`配置`C/C++`编译
* `.vscode\c_cpp_properties.json`配置`includePath`
* `.vscode\tasks.json`配置`gcc/g++`编译指令
* `.vscode\launch.json`配置Debug具体指令
* `.vscode\settings.json`配置文件编码相关设置
## 2. `VSCode`的`Git`功能使用
* 使用`VSCode`初始化创建本地`Git`库
* `Github`创建远程库
* 在本地`Git`库下运行指令(其中`xxxx`为`Github`对应远程库地址)
```PowerShell
git remote add origin https://github.com/xxxx.git
git push -u origin master
```