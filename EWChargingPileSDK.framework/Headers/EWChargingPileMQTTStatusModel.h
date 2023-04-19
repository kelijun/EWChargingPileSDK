//
//  EWChargingPileMQTTStatusModel.h
//  EWChargingPileSDK
//
//  Created by keli on 2023/4/13.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface EWChargingPileMQTTStatusModel : NSObject
// 充电电量
@property (nonatomic, assign) CGFloat degrees;
// 充电电压
@property (nonatomic, assign) CGFloat voltage;
// 充电电流
@property (nonatomic, assign) CGFloat electricCurrent;
// 充电功率
@property (nonatomic, assign) CGFloat power;
// 时长，单位：秒（s）
@property (nonatomic, assign) NSInteger duration;
// 温度
@property (nonatomic, assign) CGFloat temperature;
// 湿度 （Alex版本没有）
@property (nonatomic, assign) CGFloat humidity;
// WIFI信号强度
@property (nonatomic, assign) CGFloat wifiRssi;
// 4G信号强度（0-4，-1代表不可用）
@property (nonatomic, assign) NSInteger imt4gRssi;
@end

@interface EWChargingCompletedModel : NSObject
// 用户id
@property (nonatomic, strong) NSString *userId;
// 充电度数
@property (nonatomic, assign) CGFloat degrees;
// 充电时长，秒
@property (nonatomic, assign) NSInteger duration;
// 开始时间戳，毫秒
@property (nonatomic, assign) NSTimeInterval startTime;
// 结束充电时间戳，毫秒
@property (nonatomic, assign) NSTimeInterval endTime;
// 停充原因
@property (nonatomic, strong) NSString *stopReason;
// 时区
@property (nonatomic, assign) NSInteger zone;
// 错误码
@property (nonatomic, strong) NSArray *errCode;
@end

NS_ASSUME_NONNULL_END
