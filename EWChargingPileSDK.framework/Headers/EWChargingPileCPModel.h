//
//  EWChargingPileCPModel.h
//  EWBluetoothDemo
//
//  Created by developer on 2023/4/13.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface EWChargingPileCPModel : NSObject

// 12V最大值
@property (nonatomic, assign) float max12V;
// 12V最小值
@property (nonatomic, assign) float min12V;
// 9V最大值
@property (nonatomic, assign) float max9V;
// 9V最小值
@property (nonatomic, assign) float min9V;
// 6V最大值
@property (nonatomic, assign) float max6V;
// 6V最小值
@property (nonatomic, assign) float min6V;

@end

NS_ASSUME_NONNULL_END
