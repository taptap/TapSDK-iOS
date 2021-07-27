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

@interface ViewController ()<TapMomentDelegate>

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
    [profileButton setTitle:@"登陆状态" forState:UIControlStateNormal];
    [profileButton setTitleColor:UIColor.blackColor forState:UIControlStateNormal];
    [profileButton addTarget:self action:@selector(checkLoginStatus:) forControlEvents:UIControlEventTouchUpInside];
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
    config.clientId = @"Client ID";
    config.clientToken=@"Client Token";
    config.region = TapSDKRegionTypeCN;
    config.serverURL = @"Server URL";
    [TapBootstrap initWithConfig:config];
    
    TapDBConfig * dbConfig = [[TapDBConfig alloc]init];
    
    dbConfig.enable = true;
    dbConfig.channel=@"";
    dbConfig.gameVersion=@"";
    dbConfig.advertiserIDCollectionEnabled=true;
    config.dbConfig = dbConfig;
    
    config.region = TapSDKRegionTypeCN;
    [TapBootstrap initWithConfig:config];
    
    //开启动态
    [TapMoment setDelegate:self];
   
}

#pragma mark - 登录相关
/**
 登录
 */
- (void)taptapLogin:(UIButton *)button {
    [TDSUser loginByTapTapWithPermissions:@[@"public_profile"] callback:^(TDSUser * _Nullable user, NSError * _Nullable error) {
        if (user) {
            // 开发者可以调用 user 的方法获取更多属性。
            NSString *userId = user.objectId;  // 用户唯一标识
            NSString *username = user[@"nickname"];  // 昵称
            NSString *avatar = user[@"avatar"];  // 头像
            NSLog(@"userId: %@, username: %@, avatar: %@", userId, username, avatar);
        } else {
            NSLog(@"%@", error);
        }
    }];
}


/**
 判定登陆状态
 */
- (void)checkLoginStatus:(UIButton *)button {
    TDSUser *currentUser = [TDSUser currentUser];
    if (currentUser == nil) {
        // 未登录
        NSLog(@"登陆状态：未登陆");
    } else {
        // 已登录
        NSLog(@"登陆状态：已登陆");
    }
}

/**
 登出
 */
- (void)taptapLogout:(UIButton *)button {
    [TDSUser logOut];
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
