//
//  EWChargingPileUsageModel.h
//  EwayBLETools
//
//  Created by developer on 2024/1/2.
//

#import <Foundation/Foundation.h>
//#import "EWChargingPileProfiles.h"

NS_ASSUME_NONNULL_BEGIN

@interface EWChargingPileUsageModel : NSObject
/// 总开机时长
@property (nonatomic, assign) NSInteger totalStartTime;
/// 总充电时长
@property (nonatomic, assign) NSInteger totalChargingTime;
/// 本次开机时长
@property (nonatomic, assign) NSInteger thisStartTime;
/// 网络同步时间
@property (nonatomic, assign) NSInteger netSyncTime;
/// 当前电流
@property (nonatomic, assign) NSInteger current;
/// 日志总数
@property (nonatomic, assign) NSInteger totalLogs;
/// 已存储日志总数
@property (nonatomic, assign) NSInteger storedLogs;
/// 当前日志存储的位置
@property (nonatomic, assign) NSInteger storageLocation;
/// 存储循环数
@property (nonatomic, assign) NSInteger storedCycles;
@end

NS_ASSUME_NONNULL_END
