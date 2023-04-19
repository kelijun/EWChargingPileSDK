//
//  EWChargingPileProfiles.h
//  EWBluetoothDemo
//
//  Created by keli on 2022/12/9.
//

#ifndef EWChargingPileProfiles_h
#define EWChargingPileProfiles_h

#import <EWBluetoothSDk/EWBluetoothSDK.h>

@class EWChargingPileInfoModel, EWChargingPileConfigureModel, EWChargingPileStatusModel, EWChargingPileSwitchErrorModel, EWChargingPileCPModel;

typedef NS_ENUM(NSUInteger, EWCPMethodType) {
    EWCPMethodTypeStart = 0,       // 启动
    EWCPMethodTypeProudctID,       // 获取产品ID
    EWCPMethodTypeNumbe,           // 获取设备编号
    EWCPMethodTypeVersion,         // 获取设备编号
    EWCPMethodTypeSyncTime,        // 同步时间
    EWCPMethodTypeSyncTimeZone,    // 同步时区
    EWCPMethodTypeGetConfigure,    // 获取配置
    EWCPMethodTypeConfigure,       // 配置
    EWCPMethodTypeStartCharging,   // 开始充电
    EWCPMethodTypeUnlock,          // 解锁充电桩
    EWCPMethodTypeAppointment,     // 预约充电
    EWCPMethodTypeStatistics,      // 统计数据
    EWCPMethodTypeMonitor,         // 监控充电桩状态
    EWCPMethodTypeGetNetworkStatus,// 获取网络状态
    EWCPMethodTypeConnectNetwork,  // 连接到网络
    EWCPMethodTypeNetworkName,     // 配置网络名称
    EWCPMethodTypeNetworkPassword, // 配置网络密码
    EWCPMethodTypeConfigureAPN,    // 配置APN数据
    EWCPMethodTypeReadAPN,         // 读取APN数据
};

typedef NS_ENUM(NSUInteger, EWCPCommandType) {
    EWCPCommandTypeStart = 22,          // 启动
    EWCPCommandTypeStop = 33,          // 停止
    EWCPCommandTypeProudctID = 0x00,    // 获取产品ID
    EWCPCommandTypeNumber = 0x01,       // 获取设备编号
    EWCPCommandTypeVersion = 0x02,      // 获取设备编号
    EWCPCommandTypeSyncTime = 0x03,     // 同步时间
    EWCPCommandTypeConfigure = 0x04,    // 配置
    EWCPCommandTypeControl = 0x05,      // 控制
    EWCPCommandTypeMonitor = 0x06,      // 监控状态
    EWCPCommandTypeStatistics = 0x07,   // 统计数据
    EWCPCommandTypeNetwork = 0x08,      // 配置网络
    EWCPCommandTypeConfigureAPN = 0x09, // 配置APN
    EWCPCommandTypeReadAPN = 0x0A,      // 阅读APN
    EWCPCommandTypeSyncTimeZone = 0x0B, // 同步时间
    EWCPCommandTypeConfigureUserID = 0x0C,// 同步时间
    EWCPCommandTypeConfigureModelCode = 0x0D,// 配置机型编码及SN码
    EWCPCommandTypeConfigureUrlAddress = 0x0E,// 配置服务器地址
    EWCPCommandTypeDeviceInfo = 0x0F,// 读写设备信息
    EWCPCommandTypeConfigureReportErrorSwitch = 0x10, //配置报错开关
    EWCPCommandTypeCPAdjustment = 0x11, //CP调节
    EWCPCommandTypeUpgrade = 0xF0,      // OTA升级
};

typedef NS_ENUM(NSUInteger, EWCPCurrentType) {
    EWCPCurrentTypeAC = 0x00, // 交流电
    EWCPCurrentTypeDC = 0x01, // 直流电
};

typedef NS_ENUM(NSUInteger, EWCPActivationStatus) {
    EWCPActivationStatusNotActive = 0x00, // 未激活
    EWCPActivationStatusOnline = 0x01,    // 在线
    EWCPActivationStatusOffline = 0x02,   // 离线
};

typedef NS_ENUM(NSUInteger, EWCPWiFiStatus) {
    EWCPWiFiStatusDisconnect = 0x00,     // 未连接
    EWCPWiFiStatusConnecting = 0x01,     // 连接中
    EWCPWiFiStatusConnected = 0x02,      // 已连接
    EWCPWiFiStatusConnectFailed = 0x03,  // 连接失败
    EWCPWiFiStatusDisabled = 0x04,       // 不可用
    EWCPWiFiStatusUnknow = 0x99,         // 未知
};

typedef NS_ENUM(NSUInteger, EWCPChargingMode) {
    EWCPChargingModeRemote = 0x01, // 网络或者蓝牙控制
    EWCPChargingModeNow = 0x02,    // 即插即用
    EWCPChargingModeUnknow = 0x99, // 未知
};

typedef NS_ENUM(NSUInteger, EWCPControlCharging) {
    EWCPControlChargingNo = 0x00,    // 不控制
    EWCPControlChargingStart = 0x01, // 开始充电
    EWCPControlChargingStop = 0x02,  // 停止充电
    EWCPControlChargingPause = 0x03, // 结束充电
    EWCPControlChargingUnlock = 0x04, // 废弃⚠️
    EWCPControlChargingAppointment = 0x0A, // 废弃⚠️
    EWCPControlChargingRepeatAppointment = 0x0B,// 重复预约
    EWCPControlChargingCancelAppointment = 0x0C,// 取消预约
    EWCPControlChargingDuration = 0x0D,  // 时长充电
    EWCPControlChargingLeakageProtection = 0x7F,// 漏电保护功能使能设置
};

// 蓝牙
typedef NS_ENUM(NSUInteger, EWChargingPileStatus) {
    EWChargingPileStatusDormancy = 0x00,   // 休眠
    EWChargingPileStatusStandby = 0x01,    // 待机
    EWChargingPileStatusRunning = 0x02,    // 运行
    EWChargingPileStatusAppointment = 0x03,// 预约中
    EWChargingPileStatusError = 0x04,      // 报错锁定
    EWChargingPileStatusEStop = 0x05,      // 急停
    EWChargingPileStatusUpgrading = 0x06,  // 升级中
};


typedef NS_ENUM(NSUInteger, EWChargingGunStatus) {
    EWChargingGunStatusNo = 0x00,             // 未插入
    EWChargingGunStatusInsertAndUnlcok = 0x01,// 已插入，未锁（或无锁）
    EWChargingGunStatusInsertAndLock = 0x02,  // 已插入，已锁
};

typedef NS_ENUM(NSUInteger, EWChargingStatus) {
    EWChargingStatusNo = 0x00,       // 未充电
    EWChargingStatusCharging = 0x01, // 正在充电
    EWChargingStatusEnd = 0x02,      // 充电完成
    EWChargingStatusPause = 0x03,    // 充电暂停
};

typedef NS_ENUM(NSUInteger, EWChargingError) {
    EWChargingErrorNo = 0x00, // 无错误
    EWChargingError1 = 0x01,  // 接地故障
    EWChargingError2 = 0x02,  // 漏电保护
    EWChargingError3 = 0x03,  // 输入过压
    EWChargingError4 = 0x04,  // 输入欠压
    EWChargingError5 = 0x05,  // 过流
    EWChargingError6 = 0x06,  // CP异常
    EWChargingError7 = 0x07,  // 紧急停机
    EWChargingError8 = 0x08,  // 电子锁异常
    EWChargingError9 = 0x09,  // 火-零线反接
    EWChargingError10 = 0x0A,  // 温度传感器1故障
    EWChargingError11 = 0x0B,  // 温度传感器2故障
    EWChargingError12 = 0x0C,  // 温度传感器3故障
    EWChargingError20 = 0x14,  // 继电器开路
    EWChargingError21 = 0x15,  // 继电器粘连
    EWChargingError22 = 0x16,  // 继电器过温
    EWChargingError23 = 0x17,  // 继电器机械故障（继电器开合粘连）
    EWChargingError30 = 0x1E,  // EEPROM
    EWChargingError31 = 0x1F,  // MCB通讯故障
};

// 蓝牙状态回调
typedef void (^EWBluetoothDidUpdateStateHandler)(EWBluetoothState state);
// 发现充电桩回调(蓝牙广播号)
typedef void (^EWScanChargingPileHandler)(NSString *_Nullable chargingPileName);
// 充电桩消失回调(蓝牙广播号)
typedef void (^EWChargingPileDisappearHandler)(NSString *_Nullable chargingPileName);
// 停止扫描充电桩回调(是否成功)
typedef void (^EWStopScanChargingPileHandler)(BOOL success);
// 充电桩信息更新回调(蓝牙广播号，信息模型，错误信息)
typedef void (^EWChargingPileInfoHandler)(NSString * _Nullable chargingPileName, EWChargingPileInfoModel * _Nullable infoModel, NSError * _Nullable error);
// 充电桩配置回调(蓝牙广播号，信息模型，错误信息)
typedef void (^EWChargingPileConfigureHandler)(NSString * _Nullable chargingPileName, EWChargingPileConfigureModel *_Nullable configureModel, NSError * _Nullable error);

// 监控充电桩状态(名称，状态模型，错误信息)
typedef void (^EWChargingPileMonitorStatusHandler)(NSString * _Nullable chargingPileName, EWChargingPileStatusModel * _Nullable statusModel, NSError * _Nullable error);

// 获取充电桩 Wi-Fi 状态(名称，Wi-Fi 状态，错误信息)
typedef void (^EWChargingPileWiFiStatusHandler)(NSString * _Nullable chargingPileName, EWCPWiFiStatus status, NSError * _Nullable error);
// 获取充电桩Wi-Fi信息(名称，Wi-Fi，错误信息)
typedef void (^EWChargingPileWiFiInformationHandler)(NSString * _Nullable chargingPileName, NSString * _Nullable wifiName,  NSError * _Nullable error);
// 获取Wi-Fi(名称，Mac，数据)
typedef void (^EWWifiInformationHandler)(NSString * _Nullable wifiName, NSString * _Nullable mac, NSData * _Nullable data, NSError * _Nullable error);
// 获取APN信息(名称，APN数据，错误)
typedef void (^EWGetChargingPileAPNInformationHandler)(NSString * _Nullable bluetoothName, NSData * _Nullable APNData, NSError * _Nullable error);
// 充电桩机型编码及SN码回调(名称，机型编码，SN码，错误)
typedef void (^EWChargingPilerModelAndSNCodeHandler)(NSString * _Nullable chargingPileName, NSString * _Nullable modelCode, NSString * _Nullable SNCode, NSError * _Nullable error);
// 充电桩服务器地址回调(名称，服务器地址，错误)
typedef void (^EWChargingPilerUrlAddressHandler)(NSString * _Nullable chargingPileName, NSString * _Nullable urlAddress, NSError * _Nullable error);
//报错开关配置回调（名称，开关数据，错误）
typedef void (^EWChargingPileSwitchErrorHandler)(NSString * _Nullable chargingPileName, EWChargingPileSwitchErrorModel * _Nullable switchErrorModel, NSError * _Nullable error);
//CP调节回调（名称，开关数据，错误）
typedef void (^EWChargingPileCPAdjustmentHandler)(NSString * _Nullable chargingPileName, EWChargingPileCPModel * _Nullable cpModel, NSError * _Nullable error);

// 充电桩成功失败结果回调(名称，成功否，错误)
typedef void (^EWChargingPilerResultHandler)(NSString * _Nullable chargingPileName, BOOL resul, NSError * _Nullable error);
// 升级回调(名称，进度，当前时间，总时间，错误信息)
typedef void (^EWChargingPileUpgradeHandler)(NSString * _Nullable chargingPileName, double progress, NSInteger currentTime, NSInteger totalTime, NSError * _Nullable error);
#endif /* EWChargingPileProfiles_h */
