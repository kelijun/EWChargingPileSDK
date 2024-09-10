//
//  EWChargingPileProfiles.h
//  EWBluetoothDemo
//
//  Created by keli on 2022/12/9.
//

#ifndef EWChargingPileProfiles_h
#define EWChargingPileProfiles_h

#import <EWBluetoothSDK/EWBluetoothSDK.h>

@class EWChargingPileInfoModel, EWChargingPileConfigureModel, EWChargingPileStatusModel, EWChargingPileSwitchErrorModel, EWChargingPileCPModel, EWChargingPileUsageModel, EWChargingPileLogModel, EWChargingPileAppointmentModel;

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
    EWCPCommandTypeStart = 44,          // 启动
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
    EWCPCommandTypeReadICCID = 0x0A,      // 读ICCID信息（4G模块专属）
    EWCPCommandTypeSyncTimeZone = 0x0B, // 同步时间
    EWCPCommandTypeConfigureUserID = 0x0C,// 同步时间
    EWCPCommandTypeConfigureModelCode = 0x0D,// 配置机型编码及SN码
    EWCPCommandTypeConfigureUrlAddress = 0x0E,// 配置服务器地址
    EWCPCommandTypeDeviceInfo = 0x0F,// 读写设备信息
    EWCPCommandTypeConfigureReportErrorSwitch = 0x10, //配置报错开关
    EWCPCommandTypeCPAdjustment = 0x11, //CP调节
    EWCPCommandTypeConfigureNFC = 0x13, //配置NFC
    EWCPCommandTypeConfigServerURL = 0x14, //配置多个服务器
    EWCPCommandTypeMQTTAccount = 0x15, //配置MQTT账号密码
    EWCPCommandTypeConfigureWarnSwitch = 0x16, //配置警告开关
    EWCPCommandTypeConfigureMaxCurrent = 0x17, //配置最大电流
    EWCPCommandTypeReadLogData = 0x18, //读取日志数据
    EWCPCommandTypeDeleteLog = 0x19, //删除日志
    EWCPCommandTypeDeviceUsage = 0x1A, //读取设备使用情况
    EWCPCommandTypeConfigureAppointment = 0x1B, //读取/设置预约信息
    EWCPCommandTypeConfigureSoftHardVersion = 0x1D, //读写软硬件版本
    EWCPCommandTypeBleUnlocked = 0x1E, //读写蓝牙解锁
    EWCPCommandTypeConfigSlave = 0x1F, //读写从机地址
    EWCPCommandTypeUpgrade = 0xF0,      // OTA升级
};

typedef NS_ENUM(NSUInteger, EWCPCurrentType) {
    EWCPCurrentTypeAC = 0x00, // 交流电
    EWCPCurrentTypeDC = 0x01, // 直流电
    EWCPCurrentTypeACDC = 0x02, //交流直流一体
};

//充电连接方式
typedef NS_ENUM(NSUInteger, EWCPChargingConnectionMode) {
    EWCPChargingConnectionA = 0x00,
    EWCPChargingConnectionB = 0x01,
    EWCPChargingConnectionC = 0x02,
};

//相线类型
typedef NS_ENUM(NSUInteger, EWCPPhaseLineType) {
    EWCPPhaseLineTypeSingle = 0x00, //单相（1L1N220V）
    EWCPPhaseLineTypeFourLines = 0x01, //三相四线（3L1N线电压380V）
    EWCPPhaseLineTypeThreeLines = 0x02, //三相三线（3L0N线电压380V）
};

//计量模块类型
typedef NS_ENUM(NSUInteger, EWCPMeasurementModuleType) {
    EWCPMeasurementModuleTypeNone = 0x00, //无计量模块
    EWCPMeasurementModuleType8209 = 0x01, //RN8209
    EWCPMeasurementModuleType7302 = 0x02, //RN7302
};

//4G模块类型
typedef NS_ENUM(NSUInteger, EWCP4GModuleType) {
    EWCP4GModuleTypeNone = 0x00, //无4G模块
    EWCP4GModuleType665 = 0x01, //MC665(国内外通用)
    EWCP4GModuleType26E = 0x02, //NT26E(国内)
};

//以太网模块类型
typedef NS_ENUM(NSUInteger, EWCPEthernetModuleType) {
    EWCPEthernetModuleTypeNone = 0x00, //无以太网模块
    EWCPEthernetModuleType5500 = 0x01, //W5500
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
    //EWCPControlChargingNo = 0x00,    // 不控制
    EWCPControlChargingStart = 0x01, // 开始充电
    EWCPControlChargingStop = 0x02,  // 停止充电
    EWCPControlChargingPause = 0x03, // 暂停充电
    EWCPControlChargingUnlock = 0x04, // caseB电子锁解锁
    EWCPControlChargingLock = 0x05,  //caseB电子锁锁定
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
    EWChargingError13 = 0x0D,  // 室内温度过高
    EWChargingError14 = 0x0E,  // 漏电保护器校验错误
    EWChargingError20 = 0x14,  // 继电器开路
    EWChargingError21 = 0x15,  // 继电器粘连
    EWChargingError22 = 0x16,  // 继电器过温
    EWChargingError23 = 0x17,  // 继电器机械故障（继电器开合粘连）
    EWChargingError30 = 0x1E,  // EEPROM
    EWChargingError31 = 0x1F,  // MCB通讯故障
};

//暂时无用 -- 警告代码和错误代码一致
typedef NS_ENUM(NSUInteger, EWChargingWarn) {
    EWChargingWarnNo = 0x00, // 无错误
};

//充电桩RFID卡模式
typedef NS_ENUM(NSUInteger, EWChargingPileServerID) {
    EWChargingPileMQTTServer = 0x00, //MQTT服务器
    EWChargingPileCloudServer = 0x01, //云快充服务器
};

//充电桩RFID卡模式
typedef NS_ENUM(NSUInteger, EWChargingPileRFIDMode) {
    EWCPRFIDNoVerifyCharging = 0x00, //不验证卡号刷卡充电
    EWCPRFIDNoVerifyUploadCard = 0x01, //不验证卡号刷卡传卡号
    EWCPRFIDWithVerifyCharging = 0x02, //验证卡号刷卡充电
    EWCPRFIDWithVerifyUploadCard = 0x03, //验证卡号刷卡传卡号
};

typedef NS_ENUM(NSUInteger, EWChargingPileSetRFIDMode) {
    EWCPOutSetRFID = 0x00, //退出RFID保存卡号模式
    EWCPInSetRFID = 0x01, //进入RFID保存卡模式
    EWCPDeleteRFID = 0x02, //清除卡号
};

typedef NS_ENUM(NSUInteger, EWChargingPileLogType) {
    EWCPErrorLog = 0x01, //故障日志
    EWCPChargingLog = 0x02, //充电记录日志
    EWCPCurrentLog = 0x03, //电流调节日志
    EWCPTimeLog = 0x04, //时间日志
};

typedef NS_ENUM(NSUInteger, EWChargingPileStartEndReason) {
    EWCPStartPlugCharge = 0x01, //开始即插即充
    EWCPStartBle = 0x02, //蓝牙开始
    EWCPStartNet = 0x03, //网络开始
    EWCPStartBook = 0x04, //预约开始
    EWCPCarStopAndRestart = 0x05, //车端停止又开始充电
    EWCPStartNFC = 0x06, //nfc开始
    EWCPStopGun = 0x07, //拔枪停止
    EWCPStopBle = 0x08, //蓝牙停止
    EWCPStopNet = 0x09, //网络停止
    EWCPStopBook = 0x0A, //预约停止
    EWCPStopCar = 0x0B, //车端停止,S2断开
    EWCPStopError = 0x0C, //故障停止
    EWCPStopNFC = 0x0D //nfc停止
};

typedef NS_ENUM(NSUInteger, EWChargingPileAppointmentType) {
    EWCPAppointmentStop = 0x00, //停用
    EWCPAppointmentStart = 0x01, //启用
    EWCPAppointmentRunning = 0x02, //运行中
};

// 蓝牙状态回调
typedef void (^EWBluetoothDidUpdateStateHandler)(EWBluetoothState state);
// 发现充电桩回调(蓝牙广播号)
typedef void (^EWScanChargingPileHandler)(NSString *_Nullable chargingPileName, NSNumber * _Nullable RSSI);
// 充电桩消失回调(蓝牙广播号)
typedef void (^EWChargingPileDisappearHandler)(NSString *_Nullable chargingPileName);
// 停止扫描充电桩回调(是否成功)
typedef void (^EWStopScanChargingPileHandler)(BOOL success);
// 充电桩信息更新回调(蓝牙广播号，信息模型，错误信息)
typedef void (^EWChargingPileInfoHandler)(NSString * _Nullable chargingPileName, EWChargingPileInfoModel * _Nullable infoModel, NSError * _Nullable error);
// 充电桩配置回调(蓝牙广播号，信息模型，配置结果，错误信息)
typedef void (^EWChargingPileConfigureHandler)(NSString * _Nullable chargingPileName, EWChargingPileConfigureModel *_Nullable configureModel, BOOL res, NSError * _Nullable error);

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
// 配置ICCID回调(名称，ICCID数据，错误)
typedef void (^EWChargingPileICCIDHandler)(NSString * _Nullable bluetoothName, NSString * _Nullable ICCID, NSError * _Nullable error);
// 充电桩机型编码及SN码回调(名称，机型编码，SN码，错误)
typedef void (^EWChargingPilerModelAndSNCodeHandler)(NSString * _Nullable chargingPileName, NSString * _Nullable modelCode, NSString * _Nullable SNCode, NSError * _Nullable error);
// 充电桩服务器地址回调(名称，服务器地址，错误)
typedef void (^EWChargingPilerUrlAddressHandler)(NSString * _Nullable chargingPileName, NSString * _Nullable urlAddress, NSError * _Nullable error);
//报错开关配置回调（名称，开关数据，配置结果，错误）
typedef void (^EWChargingPileSwitchErrorHandler)(NSString * _Nullable chargingPileName, EWChargingPileSwitchErrorModel * _Nullable switchErrorModel, BOOL res, NSError * _Nullable error);
//CP调节回调（名称，开关数据，配置结果，错误）
typedef void (^EWChargingPileCPAdjustmentHandler)(NSString * _Nullable chargingPileName, EWChargingPileCPModel * _Nullable cpModel, BOOL res, NSError * _Nullable error);
//读取NFC卡号回调（名称，卡序号，卡号，错误）
typedef void (^EWChargingPileNFCNumHandler)(NSString * _Nullable chargingPileName, NSNumber * _Nullable nfcIndex, NSString * _Nullable nfcNum, NSError * _Nullable error);
//RFID卡模式回调（名称，卡模式，结果，错误）
typedef void (^EWChargingPileNFCModeHandler)(NSString * _Nullable chargingPileName, EWChargingPileSetRFIDMode nfcMode, BOOL result, NSError * _Nullable error);
// 充电桩配置多个服务器地址回调(名称，服务器ID, 服务器地址，错误)
typedef void (^EWChargingPilerServerHandler)(NSString * _Nullable chargingPileName, EWChargingPileServerID serverID,NSString * _Nullable urlAddress, NSError * _Nullable error);
//配置mqtt账号密码回调 (名称，账号，密码，错误)
typedef void (^EWChargingPileAccountAndPasswordHandler)(NSString * _Nullable chargingPileName, NSString * _Nullable account, NSString * _Nullable password, NSString * _Nullable key, NSError * _Nullable error);
// 配置最大电流回调（名称，电流，读取成功失败，错误）
typedef void (^EWChargingPileMaxCurrentHandler)(NSString * _Nullable chargingPileName, NSNumber * _Nullable maxCurrent, BOOL result, NSError * _Nullable error);
// 充电桩使用情况回调(蓝牙广播号，使用情况模型，错误信息)
typedef void (^EWChargingPileUsageHandler)(NSString * _Nullable chargingPileName, EWChargingPileUsageModel * _Nullable usageModel, NSError * _Nullable error);
// 充电桩日志回调(蓝牙广播号，日志模型，错误信息)
typedef void (^EWChargingPileLogHandler)(NSString * _Nullable chargingPileName, EWChargingPileLogModel * _Nullable logModel, NSError * _Nullable error);
// 充电桩删除日志回调(蓝牙广播号，删除结果，错误信息)
typedef void (^EWChargingPileDeleteLogHandler)(NSString * _Nullable chargingPileName, BOOL res, NSError * _Nullable error);
// 充电桩预约回调(蓝牙广播号，当前毫秒时间戳，时区，预约信息，错误信息)
typedef void (^EWChargingPileAppointmentHandler)(NSString * _Nullable chargingPileName, NSTimeInterval currentTime, NSInteger currentTimeZone, NSArray <EWChargingPileAppointmentModel *> * _Nullable appointmentModelArray, NSError * _Nullable error);
// 充电桩UserID回调(名称，UserID，错误)
typedef void (^EWChargingPilerUserIDHandler)(NSString * _Nullable chargingPileName, NSString * _Nullable userID, NSError * _Nullable error);
// 充电桩读写软硬件版本回调(名称，版本编码，错误)
typedef void (^EWChargingPilerSoftHardVersionHandler)(NSString * _Nullable chargingPileName, NSString * _Nullable version, NSError * _Nullable error);
//充电桩读写从机地址回调（名称、从机地址、错误）
typedef void (^EWChargingPilerSlaveHandler)(NSString * _Nullable chargingPileName, NSNumber * _Nullable slaveNum, NSError * _Nullable error);
// 充电桩成功失败结果回调(名称，成功否，错误)
typedef void (^EWChargingPilerResultHandler)(NSString * _Nullable chargingPileName, BOOL result, NSError * _Nullable error);
// 升级回调(名称，进度，当前时间，总时间，错误信息)
typedef void (^EWChargingPileUpgradeHandler)(NSString * _Nullable chargingPileName, double progress, NSInteger currentTime, NSInteger totalTime, NSError * _Nullable error);
#endif /* EWChargingPileProfiles_h */
