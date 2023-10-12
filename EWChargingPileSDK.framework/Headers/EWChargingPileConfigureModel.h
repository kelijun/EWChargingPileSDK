//
//  EWChargingPileConfigureModel.h
//  EWBluetoothDemo
//
//  Created by keli on 2022/12/8.
//

#import <Foundation/Foundation.h>
#import "EWChargingPileProfiles.h"

NS_ASSUME_NONNULL_BEGIN

@interface EWChargingPileConfigureModel : NSObject
/// 充电桩名称
@property (nonatomic, strong) NSString *name;
/// 充电模式
@property (nonatomic, assign) EWCPChargingMode mode;
/// 系统开关
@property (nonatomic, assign) BOOL systemSwitch;
/// NFC开关
@property (nonatomic, assign) BOOL nfcSwitch;
/////RFID卡模式
//@property (nonatomic, assign) EWChargingPileRFIDMode rfidMode;

@end

NS_ASSUME_NONNULL_END
