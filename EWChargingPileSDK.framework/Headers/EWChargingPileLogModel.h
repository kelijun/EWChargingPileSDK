//
//  EWChargingPileLogModel.h
//  EwayBLETools
//
//  Created by developer on 2024/1/2.
//

#import <Foundation/Foundation.h>
#import "EWChargingPileProfiles.h"

NS_ASSUME_NONNULL_BEGIN


@interface EWChargingPileLogModel : NSObject

/// 日志序列号
@property (nonatomic, assign) NSInteger logNum;
/// 日志类型
@property (nonatomic, assign) EWChargingPileLogType logType;
/// 日志数据
@property (nonatomic, strong, nullable) id logData;

@end


@interface EWChargingPileErrorLogModel : NSObject

/// 时间
@property (nonatomic, assign) NSInteger time;
/// 运行状态（YES充电中，NO未充电）
@property (nonatomic, assign) BOOL isCharging;
/// 故障个数
@property (nonatomic, assign) NSInteger errorCount;
/// 故障码数组
@property (nonatomic, strong) NSArray <NSNumber *> *errorArray;

@end


@interface EWChargingPileChargingLogModel : NSObject

//日志时间(秒时间戳)
@property (nonatomic, assign) NSInteger logTime;
/// 开始充电时间(秒时间戳)
@property (nonatomic, assign) NSInteger stratTime;
/// 结束充电时间(秒时间戳)
@property (nonatomic, assign) NSInteger endTime;
/// 平均CP占比（百分比）
@property (nonatomic, assign) CGFloat avgCPPercentage;
/// 平均功率KW
@property (nonatomic, assign) CGFloat avgPower;
/// 平均电压 V
@property (nonatomic, assign) CGFloat avgVoltage;
/// 平均电流 A
@property (nonatomic, assign) CGFloat avgCurrent;
/// 充电度数
@property (nonatomic, assign) CGFloat degrees;
/// 充电时长
@property (nonatomic, assign) NSInteger chargingTime;
/// 开始充电原因
@property (nonatomic, assign) EWChargingPileStartEndReason startReason;
/// 停止充电原因
@property (nonatomic, assign) EWChargingPileStartEndReason stopReason;
/// 警告个数
@property (nonatomic, assign) NSInteger warnCount;
/// 警告码数组
@property (nonatomic, strong) NSArray <NSNumber *> *warnArray;

@end

@interface EWChargingPileCurrentLogModel : NSObject

//日志时间(秒时间戳)
@property (nonatomic, assign) NSInteger logTime;
/// 相对时间
@property (nonatomic, assign) NSInteger time;
/// 设置的电流
@property (nonatomic, assign) CGFloat setCurrent;
/// 实际的电流
@property (nonatomic, assign) CGFloat actualCurrent;
/// CP占比
@property (nonatomic, assign) CGFloat cpPercentage;

@end

@interface EWChargingPileTimeLogModel : NSObject

//日志时间(秒时间戳)
@property (nonatomic, assign) NSInteger logTime;
/// 总开机时长
@property (nonatomic, assign) NSInteger totalTime;
/// 本次开机时长
@property (nonatomic, assign) NSInteger thisTime;
/// 总充电时长
@property (nonatomic, assign) NSInteger totalChargingTime;
/// 本次充电时长
@property (nonatomic, assign) NSInteger thisChargingTime;

@end


NS_ASSUME_NONNULL_END
