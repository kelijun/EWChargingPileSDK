//
//  EWChargingPileAppointmentModel.h
//  EwayBLETools
//
//  Created by developer on 2024/1/4.
//

#import <Foundation/Foundation.h>
#import "EWChargingPileProfiles.h"

NS_ASSUME_NONNULL_BEGIN

@interface EWChargingPileAppointmentModel : NSObject
/// 运行类型（NO为每天，YES为每周）
@property (nonatomic, assign) BOOL isDay;
/// 按周运行数组（按天运行时该数组为空，0为周一，1为周二，以此类推）
@property (nonatomic, strong) NSArray <NSNumber *> *weekArray;
/// 开始充电时间 -- 传当日开始时间的时间戳
@property (nonatomic, assign) NSTimeInterval startTime;
/// 结束充电时间 -- 传当日结束时间的时间戳
@property (nonatomic, assign) NSTimeInterval endTime;
/// 运行状态
@property (nonatomic, assign) EWChargingPileAppointmentType state;
@end



NS_ASSUME_NONNULL_END
