//
//  EWChargingPileStatusModel.h
//  EWBluetoothDemo
//
//  Created by keli on 2022/12/9.
//

#import <Foundation/Foundation.h>
#import "EWChargingPileProfiles.h"
NS_ASSUME_NONNULL_BEGIN

@interface EWChargingPileStatusModel : NSObject
/// 充电桩状态
@property (nonatomic, assign) EWChargingPileStatus chargingPileStatus;
/// 充电枪状态
@property (nonatomic, assign) EWChargingGunStatus chargingGunStatus;
/// 充电状态
@property (nonatomic, assign) EWChargingStatus chargingStatus;
/// 电压 V
@property (nonatomic, assign) CGFloat voltage;
/// 电流 A
@property (nonatomic, assign) CGFloat electricCurrent;
/// 功率 kw
@property (nonatomic, assign) CGFloat power;
/// 时长 s
@property (nonatomic, assign) NSInteger duration;
/// 度数
@property (nonatomic, assign) CGFloat degrees;
/// 温度 摄氏度
@property (nonatomic, assign) CGFloat temperature;
/// 湿度 %
@property (nonatomic, assign) CGFloat humidity;
/// 错误个数
@property (nonatomic, assign) NSInteger errorCount;
/// 错误码数组
@property (nonatomic, strong) NSArray <NSNumber *> *errorArray;;
@end

NS_ASSUME_NONNULL_END
