//
//  AppDelegate.h
//  TapSDK-iOS-Demo
//
//  Created by zw on 2021/4/13.
//

#import <UIKit/UIKit.h>
#import <CoreData/CoreData.h>

@interface AppDelegate : UIResponder <UIApplicationDelegate>

@property (readonly, strong) NSPersistentContainer *persistentContainer;
@property (strong, nonatomic) UIWindow *window;
- (void)saveContext;


@end

