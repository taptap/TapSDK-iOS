//
//  TapDBViewController.m
//  TdsDemo
//
//  Created by Bottle K on 2020/12/29.
//

#import "TapDBViewController.h"
#import <TapDB/TapDB.h>

@interface TapDBViewController ()
@property (nonatomic, strong) UILabel *nameLabel;
@property (nonatomic, strong) UILabel *levelLabel;
@property (nonatomic, strong) UILabel *serverLabel;
@property (nonatomic, strong) UILabel *chargeLabel;
@property (nonatomic, strong) UILabel *eventLabel;

@property (nonatomic, strong) UITextField *nameText;
@property (nonatomic, strong) UITextField *levelText;
@property (nonatomic, strong) UITextField *serverText;

@property (nonatomic, strong) UIButton *nameButton;
@property (nonatomic, strong) UIButton *levelButton;
@property (nonatomic, strong) UIButton *serverButton;
@property (nonatomic, strong) UIButton *chargeButton;
@property (nonatomic, strong) UIButton *eventButton;
@end

@implementation TapDBViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    self.view.backgroundColor = [UIColor whiteColor];
    [self.view addSubview:self.nameLabel];
    [self.view addSubview:self.levelLabel];
    [self.view addSubview:self.serverLabel];
    [self.view addSubview:self.chargeLabel];
    [self.view addSubview:self.eventLabel];
    
    [self.view addSubview:self.nameText];
    [self.view addSubview:self.levelText];
    [self.view addSubview:self.serverText];
    
    [self.view addSubview:self.nameButton];
    [self.view addSubview:self.levelButton];
    [self.view addSubview:self.serverButton];
    [self.view addSubview:self.chargeButton];
    [self.view addSubview:self.eventButton];
    
    [TapDB onStartWithClientId:@"clientid" channel:@"taptap" version:@"2.0.0" isCN:true];
    
}

- (UILabel *)nameLabel {
    if (!_nameLabel) {
        _nameLabel = [[UILabel alloc] initWithFrame:CGRectMake(10, 10, 50, 20)];
        _nameLabel.text = @"name";
    }
    return _nameLabel;
}

- (UILabel *)levelLabel {
    if (!_levelLabel) {
        _levelLabel = [[UILabel alloc] initWithFrame:CGRectMake(10, 60, 50, 20)];
        _levelLabel.text = @"level";
    }
    return _levelLabel;
}

- (UILabel *)serverLabel {
    if (!_serverLabel) {
        _serverLabel = [[UILabel alloc] initWithFrame:CGRectMake(10, 110, 50, 20)];
        _serverLabel.text = @"server";
    }
    return _serverLabel;
}

- (UILabel *)chargeLabel {
    if (!_chargeLabel) {
        _chargeLabel = [[UILabel alloc] initWithFrame:CGRectMake(10, 160, 50, 20)];
        _chargeLabel.text = @"chargr";
    }
    return _chargeLabel;
}

- (UILabel *)eventLabel {
    if (!_eventLabel) {
        _eventLabel = [[UILabel alloc] initWithFrame:CGRectMake(10, 210, 50, 20)];
        _eventLabel.text = @"event";
    }
    return _eventLabel;
}

- (UITextField *)nameText {
    if (!_nameText) {
        _nameText = [[UITextField alloc] initWithFrame:CGRectMake(80, 10, 100, 20)];
        _nameText.text = @"nameTest";
        _nameText.backgroundColor = [UIColor lightGrayColor];
    }
    return _nameText;
}

- (UITextField *)levelText {
    if (!_levelText) {
        _levelText = [[UITextField alloc] initWithFrame:CGRectMake(80, 60, 100, 20)];
        _levelText.text = @"1";
        _levelText.backgroundColor = [UIColor lightGrayColor];
    }
    return _levelText;
}

- (UITextField *)serverText {
    if (!_serverText) {
        _serverText = [[UITextField alloc] initWithFrame:CGRectMake(80, 110, 100, 20)];
        _serverText.text = @"serverTest";
        _serverText.backgroundColor = [UIColor lightGrayColor];
    }
    return _serverText;
}

- (UIButton *)nameButton {
    if (!_nameButton) {
        _nameButton = [[UIButton alloc] initWithFrame:CGRectMake(200, 10, 100, 20)];
        [_nameButton setTitle:@"set Name" forState:UIControlStateNormal];
        _nameButton.layer.cornerRadius = 5;
        _nameButton.layer.masksToBounds = YES;
        _nameButton.backgroundColor = [UIColor colorWithRed:0.08 green:0.73 blue:0.78 alpha:1.00];
        [_nameButton addTarget:self action:@selector(nameButtonAction) forControlEvents:UIControlEventTouchUpInside];
    }
    return _nameButton;
}

- (UIButton *)levelButton {
    if (!_levelButton) {
        _levelButton = [[UIButton alloc] initWithFrame:CGRectMake(200, 60, 100, 20)];
        [_levelButton setTitle:@"set Level" forState:UIControlStateNormal];
        _levelButton.layer.cornerRadius = 5;
        _levelButton.layer.masksToBounds = YES;
        _levelButton.backgroundColor = [UIColor colorWithRed:0.08 green:0.73 blue:0.78 alpha:1.00];
        [_levelButton addTarget:self action:@selector(levelButtonAction) forControlEvents:UIControlEventTouchUpInside];
    }
    return _levelButton;
}

- (UIButton *)serverButton {
    if (!_serverButton) {
        _serverButton = [[UIButton alloc] initWithFrame:CGRectMake(200, 110, 100, 20)];
        [_serverButton setTitle:@"set Server" forState:UIControlStateNormal];
        _serverButton.layer.cornerRadius = 5;
        _serverButton.layer.masksToBounds = YES;
        _serverButton.backgroundColor = [UIColor colorWithRed:0.08 green:0.73 blue:0.78 alpha:1.00];
        [_serverButton addTarget:self action:@selector(serverButtonAction) forControlEvents:UIControlEventTouchUpInside];
    }
    return _serverButton;
}

- (UIButton *)chargeButton {
    if (!_chargeButton) {
        _chargeButton = [[UIButton alloc] initWithFrame:CGRectMake(200, 160, 100, 20)];
        [_chargeButton setTitle:@"on Charge" forState:UIControlStateNormal];
        _chargeButton.layer.cornerRadius = 5;
        _chargeButton.layer.masksToBounds = YES;
        _chargeButton.backgroundColor = [UIColor colorWithRed:0.08 green:0.73 blue:0.78 alpha:1.00];
        [_chargeButton addTarget:self action:@selector(chargeButtonAction) forControlEvents:UIControlEventTouchUpInside];
    }
    return _chargeButton;
}

- (UIButton *)eventButton {
    if (!_eventButton) {
        _eventButton = [[UIButton alloc] initWithFrame:CGRectMake(200, 210, 100, 20)];
        [_eventButton setTitle:@"on Event" forState:UIControlStateNormal];
        _eventButton.layer.cornerRadius = 5;
        _eventButton.layer.masksToBounds = YES;
        _eventButton.backgroundColor = [UIColor colorWithRed:0.08 green:0.73 blue:0.78 alpha:1.00];
        [_eventButton addTarget:self action:@selector(eventButtonAction) forControlEvents:UIControlEventTouchUpInside];
    }
    return _eventButton;
}

- (void)nameButtonAction{
    
    

    
    [TapDB setName:self.nameText.text];
}

- (void)levelButtonAction{
    [TapDB setLevel:[self.levelText.text intValue]];
}

- (void)serverButtonAction{
    [TapDB setServer:self.serverText.text];
}

- (void)chargeButtonAction{
    [TapDB onChargeSuccess:@"22222" product:@"product2" amount:3 currencyType:@"rmb" payment:@"10"];
}

- (void)eventButtonAction{
    NSDictionary* dic = @{@"aaa":@"xxx",@"bbb":@"yyy"};
    [TapDB onEvent:@"testEvent2" properties:dic];

}

/*
#pragma mark - Navigation

// In a storyboard-based application, you will often want to do a little preparation before navigation
- (void)prepareForSegue:(UIStoryboardSegue *)segue sender:(id)sender {
    // Get the new view controller using [segue destinationViewController].
    // Pass the selected object to the new view controller.
}
*/

@end
