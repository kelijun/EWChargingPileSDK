//
//  EWChargingPileSwitchErrorModel.h
//  EWBluetoothDemo
//
//  Created by developer on 2023/4/12.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface EWChargingPileSwitchErrorModel : NSObject

/// 接地故障
@property (nonatomic, assign) BOOL earthFaultSwitch;
/// 漏电保护
@property (nonatomic, assign) BOOL leakageSwitch;
/// 输入过压
@property (nonatomic, assign) BOOL overvoltageSwitch;
/// 输入欠压
@property (nonatomic, assign) BOOL undervoltageSwitch;
/// 过流
@property (nonatomic, assign) BOOL overcurrentSwitch;
/// CP电压异常
@property (nonatomic, assign) BOOL cpVoltageErrorSwitch;
/// 紧急停机
@property (nonatomic, assign) BOOL emergencyStopSwitch;
/// 电子锁异常
@property (nonatomic, assign) BOOL eLockErrorSwitch;
/// 火-零反接
@property (nonatomic, assign) BOOL fireZeroReverseSwitch;
/// 温度传感器1故障
@property (nonatomic, assign) BOOL firstTempSensorErrorSwitch;
/// 温度传感器2故障
@property (nonatomic, assign) BOOL secondTempSensorErrorSwitch;
/// 温度传感器3故障
@property (nonatomic, assign) BOOL thirdTempSensorErrorSwitch;
/// 室内温度过高
@property (nonatomic, assign) BOOL highIndoorTempSwitch;
/// 漏电保护器校验错误
@property (nonatomic, assign) BOOL leakageCheckErrorSwitch;
/// 继电器开路
@property (nonatomic, assign) BOOL relayOpenCircuitSwitch;
/// 继电器粘连
@property (nonatomic, assign) BOOL relayAdhesionSwitch;
/// 继电器过温
@property (nonatomic, assign) BOOL relayOverTempSwitch;
/// EEPROM错误
@property (nonatomic, assign) BOOL eepromErrorSwitch;
/// MCB通讯故障
@property (nonatomic, assign) BOOL mcbCommunicationErrorSwitch;


@end

NS_ASSUME_NONNULL_END
