//
//  EWChargingPileDelegate.h
//  EWBluetoothDemo
//
//  Created by 柯里 on 2023/1/15.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN
@class EWChargingPileMQTTInfoModel, EWChargingPileMQTTStatusModel, EWChargingPileProfiles ,EWChargingCompletedModel;
@protocol EWChargingPileDelegate <NSObject>

#pragma mark - MQTT
/// MQTT 连接成功
- (void)ew_mqttConnected;

/// MQTT 连接失败
/// - Parameter error: 错误信息
- (void)ew_mqttConnectionFailedWithError:(NSError *)error;

/// MQTT 关闭连接
- (void)ew_mqttDisconnected;

/// MQTT 设备信息更新
/// - Parameter infoModel: 信息模型
- (void)ew_mqttChargingPileInfoUpdate:(EWChargingPileMQTTInfoModel *)infoModel;

/// MQTT 充电模式改变
/// - Parameter chargingMode: 充电模式
- (void)ew_mqttChargingPileCharingModeChange:(EWCPChargingMode)chargingMode;

/// MQTT NFC开关状态改变
/// - Parameter nfcSwitch: 充电模式
- (void)ew_mqttChargingPileNFCSwitchStatusChange:(BOOL)nfcSwitch;

/// MQTT 充电桩状态改变
/// - Parameter status: 充电桩状态
- (void)ew_mqttChargingPileStatusChange:(EWChargingPileStatus)status;

/// MQTT 充电枪状态改变
/// - Parameter status: 充电枪状态
- (void)ew_mqttChargingGunStatusChange:(EWChargingGunStatus)status;

/// MQTT 充电状态改变
/// - Parameter chargingMode: 充电状态
- (void)ew_mqttChargingStatusChange:(EWChargingStatus)status;

/// MQTT 充电开关改变
/// - Parameter chargingSwitch: 充电开关
- (void)ew_mqttChargingSwitchStatusChange:(BOOL)chargingSwitch;

/// MQTT 充电状态模型改变
/// - Parameter chargingMode: 充电状态模型
- (void)ew_mqttChargingStatusModelChange:(EWChargingPileMQTTStatusModel *)statusModel;

/// MQTT 充电完成
/// - Parameter chargingMode: 充电状态
- (void)ew_mqttChargingCompleted:(EWChargingCompletedModel *)model;
@end

NS_ASSUME_NONNULL_END
