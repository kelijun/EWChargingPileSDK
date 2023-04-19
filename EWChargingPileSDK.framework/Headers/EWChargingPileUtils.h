//
//  EWChargingPileUtils.h
//  EWBluetoothDemo
//
//  Created by keli on 2023/3/3.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN
@class EWChargingPileStatusModel;
@interface EWChargingPileUtils : NSObject

/// 读取监控状态配置
/// - Parameter data: 数据
+ (EWChargingPileStatusModel *)readMonitorStatusData:(NSData *)data;

/// 获取芯片供应商
/// - Parameter no: 序号
+ (NSString *)getChipManufacturer:(NSInteger)manufacturerNo;

/// 获取芯片型号
/// - Parameters:
///   - manufacturerNo: 序号
///   - modelNo: 型号
+ (NSString *)getChipModelWithManufacturer:(NSInteger)manufacturerNo
                                   modelNo:(NSInteger)modelNo;

@end

NS_ASSUME_NONNULL_END
