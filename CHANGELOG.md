Changelog
# v2.1.1 2020/05/10

## TapBootstrap
### Feature
* 新增篝火测试资格校验接口
    ``` objectivec
        [TapBootstrap getTestQualification:^(BOOL isQualified, NSError *_Nullable error) {
        if (error) {
            // 网络异常或未开启篝火测试
        } else {
            if (isQualified) {
                // 有篝火测试资格
            }
        }
    }];
    ```
* 引入TapDB库时，在 `[TapBootstrap initWithConfig:config];` 接口默认初始化 TapDB，可以通过 TapDBConfig 配置 channel、gameVersion、enable 参数
    ``` objectivec
    TapDBConfig * dbConfig = [TapDBConfig new];
    dbConfig.channel = @"channel";// 游戏渠道
    dbConfig.gameVersion = @"x.y.z"; // 游戏版本号
    dbConfig.enable = YES; // 是否开启
    tapConfig.dbConfig = dbConfig;
    ```

### Breaking changes
* TapConfig 新增 clientSecret 字段，必填
* TapBootstrapLoginType 删除 Apple 和 Guest 类型
* 删除绑定接口
    ``` objectivec
    + (void)bind:(TapBootstrapBindType)type permissions:(NSArray *)permissions;
    ```

## TapMoment
### Feature
* 新增打开特定页面的接口（打开场景化入口等） 
    ``` objectivec
     [TapMoment directlyOpen:mconfig page:TapMomentPageShortcut extras:@{ TapMomentPageShortcutKey: @"sceneid" }];
    ```

## TapDB
### Feature
* 新增 IDFA 开关，默认关闭
    ``` objectivec
    // 开启 IDFA
    [TapDB setAdvertiserIDCollectionEnabled:YES];
    ```
---
## v2.0.0 2020/04/08