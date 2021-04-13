//
//  ViewController.m
//  TapSDK-iOS-Demo
//
//  Created by zw on 2021/4/13.
//

#import "ViewController.h"
#import <TapBootstrapSDK/TapBootstrapSDK.h>
#import <TapMomentSDK/TapMomentSDK.h>
#import "TapDBViewController.h"

@interface ViewController ()<TapLoginResultDelegate, TapMomentDelegate, TapUserStatusChangedDelegate>

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
    
    UIButton *loginButton = [[UIButton alloc] initWithFrame:CGRectMake(100, 50, 100, 50)];
    loginButton.contentHorizontalAlignment = UIControlContentHorizontalAlignmentLeft;
    [loginButton setTitle:@"登录" forState:UIControlStateNormal];
    [loginButton setTitleColor:UIColor.blackColor forState:UIControlStateNormal];
    [loginButton addTarget:self action:@selector(taptapLogin:) forControlEvents:UIControlEventTouchUpInside];
    [self.view addSubview:loginButton];
    
    
    UIButton *logoutButton = [[UIButton alloc] initWithFrame:CGRectMake(100, 150, 100, 50)];
    logoutButton.contentHorizontalAlignment = UIControlContentHorizontalAlignmentLeft;
    [logoutButton setTitle:@"登出" forState:UIControlStateNormal];
    [logoutButton setTitleColor:UIColor.blackColor forState:UIControlStateNormal];
    [logoutButton addTarget:self action:@selector(taptapLogout:) forControlEvents:UIControlEventTouchUpInside];
    [self.view addSubview:logoutButton];

    UIButton *profileButton = [[UIButton alloc] initWithFrame:CGRectMake(100, 250, 300, 50)];
    profileButton.contentHorizontalAlignment = UIControlContentHorizontalAlignmentLeft;
    [profileButton setTitle:@"获取用户最新信息" forState:UIControlStateNormal];
    [profileButton setTitleColor:UIColor.blackColor forState:UIControlStateNormal];
    [profileButton addTarget:self action:@selector(fetchProfile:) forControlEvents:UIControlEventTouchUpInside];
    [self.view addSubview:profileButton];

    UIButton *momentButton = [[UIButton alloc] initWithFrame:CGRectMake(100, 350, 100, 50)];
    momentButton.contentHorizontalAlignment = UIControlContentHorizontalAlignmentLeft;
    [momentButton setTitle:@"打开动态" forState:UIControlStateNormal];
    [momentButton setTitleColor:UIColor.blackColor forState:UIControlStateNormal];
    [momentButton addTarget:self action:@selector(taptapMoment:) forControlEvents:UIControlEventTouchUpInside];
    [self.view addSubview:momentButton];

    UIButton *momentRedPoint = [[UIButton alloc] initWithFrame:CGRectMake(100, 450, 300, 50)];
    momentRedPoint.contentHorizontalAlignment = UIControlContentHorizontalAlignmentLeft;
    [momentRedPoint setTitle:@"获取动态未读数" forState:UIControlStateNormal];
    [momentRedPoint setTitleColor:UIColor.blackColor forState:UIControlStateNormal];
    [momentRedPoint addTarget:self action:@selector(taptapMomentRedPoint:) forControlEvents:UIControlEventTouchUpInside];
    [self.view addSubview:momentRedPoint];
    
    UIButton *dbButton = [[UIButton alloc] initWithFrame:CGRectMake(100, 550, 300, 50)];
    dbButton.contentHorizontalAlignment = UIControlContentHorizontalAlignmentLeft;
    [dbButton setTitle:@"进入TapDB测试" forState:UIControlStateNormal];
    [dbButton setTitleColor:UIColor.blackColor forState:UIControlStateNormal];
    [dbButton addTarget:self action:@selector(toTapDB:) forControlEvents:UIControlEventTouchUpInside];
    [self.view addSubview:dbButton];

    [self initTapSDK];
}


#pragma mark - 初始化
- (void)initTapSDK {
    
    //初始化SDK
    TapConfig *config = TapConfig.new;
    config.clientId = @"0RiAlMny7jiz086FaU";
    config.region = TapSDKRegionTypeCN;
    [TapBootstrap initWithConfig:config];
    //设置登录回调
    [TapBootstrap registerLoginResultDelegate:self];
    [TapBootstrap registerUserStatusChangedDelegate:self];
    
    //开启动态
    [TapMoment initWithClientId:config.clientId];
    [TapMoment setDelegate:self];
    
//    //示例代码
//    BOOL isInit = [TapBootstrap isInitialized];
//    [TapBootstrap getUser:^(TapUser * _Nullable userInfo, NSError * _Nullable error) {
//        if(error){
//            NSLog(@"获取用户信息失败 %@", error);
//        }else{
//            NSLog(@"获取用户信息成功 %@", userInfo);
//        }
//    }];
//    [TapBootstrap setPreferredLanguage:0];
    //AccessToken *accessToken = [TapBootstrap getCurrentToken];
//    if(accessToken == nil){
//        //未登录，请登录
//    }else{
//        //已经登录
//    }
//
//    TapMomentConfig * tconfig = TapMomentConfig.new;
//    tconfig.orientation = TapMomentOrientationDefault;
//    TapMomentImageData *postData = TapMomentImageData.new;
//    postData.images = @[@"file://..."];
//    postData.content = @"我是图片描述";
//    [TapMoment publish:tconfig content:(postData)];
//    [TapMoment close];
//    [TapMoment closeWithTitle:@"title" content:@"content" showConfirm:YES];
}

#pragma mark - 登录相关
/**
 登录
 */
- (void)taptapLogin:(UIButton *)button {
    TapBootstrapLoginType loginType = TapBootstrapLoginTypeTapTap;
    [TapBootstrap login:(loginType) permissions:@[@"public_profile"]];
}

/**
 登出
 */
- (void)taptapLogout:(UIButton *)button {
    [TapBootstrap logout];
}

/**
 获取用户信息
 */
- (void)fetchProfile:(UIButton *)button {
    [TapBootstrap getUserDetails:^(TapUserDetails *_Nullable userDetail, NSError *_Nullable error) {
        if (error) {
            NSLog(@"获取用户信息失败 %@", error);
        } else {
            NSLog(@"获取用户信息成功 %@", userDetail.name);
        }
    }];
}

#pragma mark - TapBootstrap
// 实现回调方法
// 登录成功回调
// @param token token 对象
- (void)onLoginSuccess:(AccessToken *)token{
    NSLog (@"onLoginSuccess");
}

// 登录取消
- (void)onLoginCancel{
    NSLog (@"onLoginCancel");
}

// 登录失败
// @param error 失败原因
- (void)onLoginError:(NSError *)error{
    NSLog (@"onLoginError");
}

- (void)onLogout:(NSError *)error{
    NSLog (@"onLogout");
}

// 如果是因为出错导致的退登，则返回错误信息
- (void)onBind:(NSError *)error{
    NSLog (@"onBind");
}

#pragma mark - 动态相关
/**
 打开动态
 */
- (void)taptapMoment:(UIButton *)button {
    TapMomentConfig *mConfig = TapMomentConfig.new;
    mConfig.orientation = TapMomentOrientationDefault;
    [TapMoment open:mConfig];
}

- (void)taptapMomentRedPoint:(UIButton *)button {
    NSLog(@"小红点请求");
    [TapMoment fetchNotification];
}

#pragma mark - DB相关

- (void)toTapDB:(UIButton *)button {
    TapDBViewController *dbController = [TapDBViewController new];
//    [self showViewController:dbController sender:nil];
    [self presentViewController:dbController animated:YES completion:nil];
}


#pragma mark - TapMomentDelegate

- (void)onMomentCallbackWithCode:(NSInteger)code msg:(NSString *)msg
{
    NSLog (@"msg:%@, code:%i" ,msg, code);
}

@end
