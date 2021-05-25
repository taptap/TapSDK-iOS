//
//  TapFriendsViewController.m
//  TapSDK-iOS-Demo
//
//  Created by 张伟 on 2021/5/20.
//

#import "TapFriendsViewController.h"
#import <TapFriendSDK/TapFriendSDK.h>
@interface TapFriendsViewController ()<ComponentMessageDelegate>

@end



@implementation TapFriendsViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    UIButton *addFriend = [[UIButton alloc] initWithFrame:CGRectMake(100, 50, 100, 50)];
    addFriend.contentHorizontalAlignment = UIControlContentHorizontalAlignmentLeft;
    [addFriend setTitle:@"添加好友" forState:UIControlStateNormal];
    [addFriend setTitleColor:UIColor.blackColor forState:UIControlStateNormal];
    [addFriend addTarget:self action:@selector(addFriendButton:) forControlEvents:UIControlEventTouchUpInside];
    [self.view addSubview:addFriend];
    
    
    UIButton *deleteFriend = [[UIButton alloc] initWithFrame:CGRectMake(100, 150, 100, 50)];
    deleteFriend.contentHorizontalAlignment = UIControlContentHorizontalAlignmentLeft;
    [deleteFriend setTitle:@"删除好友" forState:UIControlStateNormal];
    [deleteFriend setTitleColor:UIColor.blackColor forState:UIControlStateNormal];
    [deleteFriend addTarget:self action:@selector(deleteFriendButton:) forControlEvents:UIControlEventTouchUpInside];
    [self.view addSubview:deleteFriend];

    UIButton *block = [[UIButton alloc] initWithFrame:CGRectMake(100, 250, 300, 50)];
    block.contentHorizontalAlignment = UIControlContentHorizontalAlignmentLeft;
    [block setTitle:@"拉黑好友" forState:UIControlStateNormal];
    [block setTitleColor:UIColor.blackColor forState:UIControlStateNormal];
    [block addTarget:self action:@selector(blockButton:) forControlEvents:UIControlEventTouchUpInside];
    [self.view addSubview:block];

    UIButton *unBlock = [[UIButton alloc] initWithFrame:CGRectMake(100, 350, 100, 50)];
    unBlock.contentHorizontalAlignment = UIControlContentHorizontalAlignmentLeft;
    [unBlock setTitle:@"取消拉黑" forState:UIControlStateNormal];
    [unBlock setTitleColor:UIColor.blackColor forState:UIControlStateNormal];
    [unBlock addTarget:self action:@selector(unBlockButton:) forControlEvents:UIControlEventTouchUpInside];
    [self.view addSubview:unBlock];

    UIButton *getFollowing = [[UIButton alloc] initWithFrame:CGRectMake(100, 450, 300, 50)];
    getFollowing.contentHorizontalAlignment = UIControlContentHorizontalAlignmentLeft;
    [getFollowing setTitle:@"获取关注列表" forState:UIControlStateNormal];
    [getFollowing setTitleColor:UIColor.blackColor forState:UIControlStateNormal];
    [getFollowing addTarget:self action:@selector(getFollowingButton:) forControlEvents:UIControlEventTouchUpInside];
    [self.view addSubview:getFollowing];
    
    UIButton *generateFriendInvitation = [[UIButton alloc] initWithFrame:CGRectMake(100, 500, 300, 50)];
    generateFriendInvitation.contentHorizontalAlignment = UIControlContentHorizontalAlignmentLeft;
    [generateFriendInvitation setTitle:@"获取好友邀请链接" forState:UIControlStateNormal];
    [generateFriendInvitation setTitleColor:UIColor.blackColor forState:UIControlStateNormal];
    [generateFriendInvitation addTarget:self action:@selector(generateFriendInvitationButton:) forControlEvents:UIControlEventTouchUpInside];
    [self.view addSubview:getFollowing];
    
    UIButton *searchUser = [[UIButton alloc] initWithFrame:CGRectMake(100, 550, 300, 50)];
    searchUser.contentHorizontalAlignment = UIControlContentHorizontalAlignmentLeft;
    [searchUser setTitle:@"搜索用户" forState:UIControlStateNormal];
    [searchUser setTitleColor:UIColor.blackColor forState:UIControlStateNormal];
    [searchUser addTarget:self action:@selector(searchUserButton:) forControlEvents:UIControlEventTouchUpInside];
    [self.view addSubview:searchUser];

    
}

- (void)addFriendButton:(UIButton *)button {
    [TapFriends addFriend:@"tds id" handler:^(NSError * _Nullable error) {
        if (error!=nil){
            NSLog (@"添加成功");
        }
    }];
}


- (void)deleteFriendButton:(UIButton *)button {
    [TapFriends deleteFriend:@"tds id" handler:^(NSError * _Nullable error) {
        if (error!=nil){
            NSLog (@"删除成功");
        }
    }];
}

- (void)blockButton:(UIButton *)button {
    [TapFriends blockUser:@"tds id" handler:^(NSError * _Nullable error) {
        if (error!=nil){
            NSLog (@"拉黑成功");
        }
    }];

}

- (void)unBlockButton:(UIButton *)button {
    [TapFriends unblockUser:@"tds id" handler:^(NSError * _Nullable error) {
        if (error!=nil){
            NSLog (@"取消拉黑成功");
        }
    }];
}

- (void)getFollowingButton:(UIButton *)button {
    [TapFriends getFollowingList:0 mutualAttention:true limit:100 handler:^(NSArray<TapUserRelationShip *> * _Nullable userList, NSError * _Nullable error) {
        if (error!=nil){
            for (int i=0; userList.count; i++) {
                NSLog(@"%@", userList[0]);
            }
        }
    }];

}
- (void)generateFriendInvitationButton:(UIButton *)button {
    [TapFriends generateFriendInvitationWithHandler:^(NSString *_Nullable invitationString, NSError *_Nullable error) {
        if (error) {
            NSLog(@"error:%@", error);
        } else {
            NSLog(@"url %@", invitationString);
        }
    }];

}
- (void)searchUserButton:(UIButton *)button {
   
    [TapFriends searchUserWithUserId:@"tdsid" handler:^(TapUserRelationShip *_Nullable user, NSError *_Nullable error) {
        if (error) {
            NSLog(@"error:%@", error);
        } else {
            NSString *str = @"";
            NSLog(@"friend list %@ %@ %@ %@", str, user.isBlocked ? @"yes" : @"no", user.isFollowed ? @"yes" : @"no", user.isFollowing ? @"yes" : @"no");
        }
    }];

}


- (void)onMessageWithCode:(NSInteger)code extras:(NSDictionary *)extras
{
    NSLog(@"code %@, %@", code,extras);
}

@end
