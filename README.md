# lvgl-simulator-x

lvgl simulator for MacOSX && Windows && Linux.

开箱即用的 LVGL 模拟器集合，支持 MacOSX Windows Linux

## 特性

- 开箱即用
- 代码提示
- 构建支持 IDE、CMake、命令行
- 跨平台，可在各个平台保持一致的开发体验
- 代码隔离，在 PC 上调试好后，可一键 copy 文件到生产

## 安装

使用 Git 拉取代码到本地：`git clone --recurse-submodules git@github.com:LanFly/lvgl-simulator-x.git`

## 开发

将你的业务代码全部放在 `src` 目录下，默认的入口函数是 `void app_start()`

## 配置

LVGL 的配置在 `lv_conf.h` 文件，你可以修改它

## 编译

请根据对应平台的教程进行

### MacOS

#### 前提准备

在 MacOS 下使用 `X11` 进行图形绘制，所以首先你要安装它。这非常简单，下载安装包 [Quartz](https://www.xquartz.org/) 根据提示安装就行

安装 CMake，同样根据官网教程进行安装，最后别忘记了设置支持命令行模式

> 未来会支持 Xcode

#### 命令行编译

1. 在项目根目录创建 `build` 文件夹
2. `cd build` 进入文件夹
3. `cmake ../`
4. 最后编译 `make`
5. 编译好后运行 `./lvgl-sim` 就能看到了

> 小提示：第一次运行需要启动 X11 Server，会有一段时间界面没响应，不是卡住了，稍等一会就行，后面再次启动就很快了

#### VS Code

如果你不喜欢使用命令行，可以使用 Visual Studio Code 图形化界面，在扩展中安装 CMake tool 插件，然后所有操作都在 VSCode 完成

### Windows

马上来

### Linux

基本和 MacOS 是一样的，有些 Linux 发行版已经预装了 X11，所以可以直接编译

## 调试

默认编译的目标是可调试，建议使用 VSCode 进行开发和调试，后续也会支持 XCode 和 Visual Studio

### 使用 VSCode 调试

直接点击侧边栏的 调试，选择 `LLDB Debug` 就行

## 触摸和键盘事件

在下个版本中支持，马上
