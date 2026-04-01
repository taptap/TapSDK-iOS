# TapSDKv3 iOS 


## 仓库介绍

本仓库为 TapSDK v3 在 iOS 平台的产物仓库，包含 TapTap 登录、更新唤起、合规认证、数据分析等完整模块。开发者在根据 TapTap 开发者中心接入文档集成相关业务功能时，可通过本仓库获取并下载所需的依赖库文件


### 获取 SDK

进入 [Releases](https://github.com/taptap/tapsdk-v3-ios/releases) 页面，选择需要的版本及模块下载。

每个版本通常包含：

* 各模块的 `*.framework` 依赖库文件 和 `*.bundle` 资源文件
* 更新说明（Release Notes）


## 接入文档

完整的集成指南、API 参考和使用示例，请访问：
**[接入文档](https://developer.taptap.cn/docs/v3/sdk/)**


## 接入方式

### 1. 下载 framework 和 bundle 文件

在 Xcode 工程中添加下载的 `*.framework`静态库，注意添加时选择 Embed 方式为 Do Not Embed，导入下载的 `*.bundle` 资源文件

### 2. 配置工程

* 在 Build Setting 中的 Other Link Flag 中添加 -ObjC

* 在工程中添加 libz.1.tbd 和 libc++.tbd 依赖

如 SDK 依赖其他库，请根据文档额外添加依赖。


## 支持与反馈

如有问题或需求，请通过以下方式联系我们：

- 开发者中心：[TapTap 开发者中心](https://developer.taptap.cn/)
- 工单咨询：[提交工单](https://developer.taptap.cn/docs/store/#%E4%BA%8C%E5%B7%A5%E5%8D%95%E5%92%A8%E8%AF%A2)



