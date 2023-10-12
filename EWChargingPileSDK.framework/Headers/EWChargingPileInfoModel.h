//
//  EWChargingPileInfoModel.h
//  EWBluetoothDemo
//
//  Created by keli on 2022/12/7.
//

#import <Foundation/Foundation.h>
#import "EWChargingPileProfiles.h"

NS_ASSUME_NONNULL_BEGIN
@class EWChargingPileVersionInfoModel;
@interface EWChargingPileInfoModel : NSObject
// 充电桩名称
@property (nonatomic, strong) NSString *name;
// 产品ID
@property (nonatomic, strong) NSString *productCode;
// 设备编号
@property (nonatomic, strong) NSString *deviceNum;
// 版本信息
@property (nonatomic, strong) EWChargingPileVersionInfoModel *versionInfo;

// 电流类型
@property (nonatomic, assign) EWCPCurrentType currentType;
// 额定电压
@property (nonatomic, assign) NSInteger ratedVoltage;
// 额定功率
@property (nonatomic, assign) float ratedPower;
// 额定电流
@property (nonatomic, assign) NSInteger ratedCurrent;
//充电连接方式
@property (nonatomic, assign) EWCPChargingConnectionMode chargingConnectionMode;
//相线类型
@property (nonatomic, assign) EWCPPhaseLineType phaseLineType;
//计量模块类型
@property (nonatomic, assign) EWCPMeasurementModuleType measurementModuleType;
//4G模块类型
@property (nonatomic, assign) EWCP4GModuleType module4GType;
//以太网类型
@property (nonatomic, assign) EWCPEthernetModuleType ethernetModuleType;

- (NSDictionary *)dicFromObject:(NSObject *)object;

@end

@interface EWChargingPileVersionInfoModel : NSObject
// 主控芯片供应商
@property (nonatomic, strong) NSString *mainChipManufacturer;
// 主控芯片型号
@property (nonatomic, strong) NSString *mainChipModel;
// 主控芯片硬件版本1.0
@property (nonatomic, assign) float mainChipHardware;
// 主控芯片软件版本1.2
@property (nonatomic, assign) float mainChipSoftware;
// MCB芯片供应商
@property (nonatomic, strong) NSString *MCBChipManufacturer;
// MCB芯片型号
@property (nonatomic, strong) NSString *MCBChipModel;
// MCB芯片硬件版本
@property (nonatomic, assign) float MCBChipHardware;
// 网络模块芯片软件版本
@property (nonatomic, assign) float MCBChipSoftware;
// 网络模块芯片供应商
@property (nonatomic, strong) NSString *networkChipManufacturer;
// 网络模块芯片型号
@property (nonatomic, strong) NSString *networkChipModel;
// 网络模块芯片硬件版本
@property (nonatomic, assign) float networkChipHardware;
// 网络模块芯片软件版本
@property (nonatomic, assign) float networkChipSoftware;
@end

NS_ASSUME_NONNULL_END
