//
//  EWChargingPile.h
//  EWBluetoothDemo
//
//  Created by keli on 2022/12/6.
//

#import "EWChargingPileProfiles.h"
#import "EWChargingPileInfoModel.h"
#import "EWChargingPileConfigureModel.h"
#import "EWChargingPileStatusModel.h"
#import "EWChargingPileSwitchErrorModel.h"
#import "EWChargingPileCPModel.h"
#import "EWChargingPileUsageModel.h"
#import "EWChargingPileLogModel.h"
#import "EWChargingPileAppointmentModel.h"

// 升级文件
#import <EWYmodemSDK/EWPeripheral+YModem.h>

NS_ASSUME_NONNULL_BEGIN

@interface EWChargingPile : NSObject
// 蓝牙状态发生变化
@property (nonatomic, copy) EWBluetoothDidUpdateStateHandler bluetoothDidUpdateStateHandler;

/// 单例
+ (instancetype)share;


/// 配置key和密钥
/// - Parameters:
///   - appId: appId
///   - appSecret: appSecret
- (void)ew_configureChargingPileAppId:(NSString *)appId
                            appSecret:(NSString *)appSecret;

///配置搜索配置
- (void)ew_configChargingPileScanWithName: (NSString *)filterName;


/// 扫描附近的充电桩
/// - Parameter handler: 扫描回调
- (void)ew_scanChargingPileHandler:(EWScanChargingPileHandler)handler;

/// 附近的充电桩消失，消失后无法连接，请同步删除保存的充电桩
/// - Parameter handler: 扫描回调
- (void)ew_chargingPileDisappearHandler:(EWChargingPileDisappearHandler)handler;

/// 停止扫描附近的充电桩
/// - Parameter handler: 成功回调
- (void)ew_stopScanChargingPileHandler:(EWStopScanChargingPileHandler)handler;

/// 启动充电桩模块
/// - Parameters:
///   - chargingPileName: 充电桩蓝牙广播号
///   - handler: 启动是否成功回调
- (void)startChargingPileModule:(NSString *)chargingPileName
                        handler:(EWChargingPilerResultHandler)handler;

/// 启动充电桩模块(不搜索直接连接)
/// - Parameters:
///   - chargingPileName: 充电桩蓝牙广播号
///   - handler: 启动是否成功回调
- (void)startChargingPileModuleWithoutScan:(NSString *)chargingPileName
                                      uuid: (NSString *)uuid
                                   handler:(EWChargingPilerResultHandler)handler;

/// 关闭充电桩模块
/// - Parameter chargingPileName: 充电桩蓝牙广播号
- (void)ew_stopChargingPileModule:(NSString *)chargingPileName;

/// 充电桩断开，包含被动及主动断开
/// - Parameter handler: 断开回调
- (void)ew_chargingPileDisconnectedHandler:(EWChargingPilerResultHandler)handler;

/// 通过充电桩蓝牙广播号检查充电桩连接状态，YES连接，NO未连接
/// - Parameter chargingPileName:充电桩蓝牙广播号
- (BOOL)checkConnectionStatusOfChargingPile:(NSString *)chargingPileName;

/// 获取产品ID
/// - Parameters:
///   - chargingPileName: 充电桩蓝牙广播号
///   - handler: 启动是否成功回调
- (void)ew_getChargingPileProductID:(NSString *)chargingPileName
                            handler:(EWChargingPileInfoHandler)handler;

/// 获取充电桩编号
/// - Parameters:
///   - chargingPileName: 充电桩蓝牙广播号
///   - handler: 充电桩信息更新回调
- (void)ew_getChargingPileNumber:(NSString *)chargingPileName
                         handler:(EWChargingPileInfoHandler)handler;

/// 获取充电桩版本信息
/// - Parameters:
///   - chargingPileName: 充电桩蓝牙广播号
///   - handler: 充电桩信息更新回调
- (void)ew_getChargingPilVersion:(NSString *)chargingPileName
                          handler:(EWChargingPileInfoHandler)handler;

/// 同步设备时间
/// - Parameters:
///   - chargingPileName: 充电桩蓝牙广播号
///   - timeDate: 时间
///   - handler: 启动是否成功回调
- (void)ew_syncChargingPileTime:(NSString *)chargingPileName
                      timeDate:(NSDate *)timeDate
                       handler:(EWChargingPilerResultHandler)handler;

/// 同步设备时区
/// - Parameters:
///   - chargingPileName: 充电桩蓝牙广播号
///   - timeZone: 与标准时区的偏差+-24
///   - handler: 启动是否成功回调
- (void)ew_syncChargingPileTimezone:(NSString *)chargingPileName
                          timezone:(NSInteger)timezone
                           handler:(EWChargingPilerResultHandler)handler;


/// 获取充电桩配置
/// - Parameters:
///   - chargingPileName: 充电桩蓝牙广播号
///   - handler: 充电桩配置回调
- (void)ew_getChargingPileConfigure:(NSString *)chargingPileName
                            handler:(EWChargingPileConfigureHandler)handler;

/// 配置充电桩
/// - Parameters:
///   - chargingPileName: 充电桩蓝牙广播号
///   - mode: 充电模式
///   - systemSwitch: 系统开关
///   - nfcSwitch: nfc开关
///   - rfidMode：RFID卡模式
///   - handler: 充电桩配置回调
- (void)ew_configureChargingPile:(NSString *)chargingPileName
                    ChargingMode:(EWCPChargingMode)mode
                    systemSwitch:(BOOL)systemSwitch
                       nfcSwitch:(BOOL)nfcSwitch
                        rfidMode:(EWChargingPileRFIDMode)rfidMode
                         handler:(EWChargingPileConfigureHandler)handler;

/// 充电控制
/// - Parameters:
///   - chargingPileName: 充电桩蓝牙广播号
///   - control: 控制开始充电、结束充电、暂停充电
///   - power: 充电功率，单位KW，为0使用默认功率，仅在开始充电时有效
///   - handler: 控制回调
- (void)ew_chargingPileControlCharging:(NSString *)chargingPileName
                               control:(EWCPControlCharging)control
                         chargingPower:(CGFloat)power
                               handler:(EWChargingPilerResultHandler)handler;

/// 充电桩解锁/锁定
/// - Parameters:
///   - chargingPileName: 充电桩蓝牙广播号
///   - handler: 解锁回调
- (void)ew_chargingPilelockState:(NSString *)chargingPileName
                       isLock: (BOOL) islock
                      handler:(EWChargingPilerResultHandler)handler;

/// 预约充电（废弃）
/// - Parameters:
///   - chargingPileName: 充电桩蓝牙广播号
///   - startTime: 开始时间
///   - stopTime: 结束时间
///   - powerArray: 每小时的功率
///   - isRepeat: 是否每天重复执行
///   - handler: 预约充电回调
- (void)ew_chargingPileAppointmentCharging:(NSString *)chargingPileName
                         chargingStartDate:(NSDate *)startDate
                          chargingStopDate:(NSDate *)stopDate
                        chargingPowerArray:(NSArray <NSString *>*)powerArray
                                  isRepeat:(BOOL)isRepeat
                                   handler:(EWChargingPilerResultHandler)handler;

/// 预约充电 （废弃）
/// - Parameters:
///   - chargingPileName: 充电桩蓝牙广播号
///   - startTime: 开始时间（时间戳）
///   - stopTime: 结束时间（时间戳）
///   - powerArray: 每小时的功率
///   - isRepeat: 是否每天重复执行
///   - handler: 预约充电回调
- (void)ew_chargingPileAppointmentCharging:(NSString *)chargingPileName
                         chargingStartTime:(NSTimeInterval)startTime
                          chargingStopTime:(NSTimeInterval)stopTime
                        chargingPowerArray:(NSArray <NSString *>*)powerArray
                                  isRepeat:(BOOL)isRepeat
                                   handler:(EWChargingPilerResultHandler)handler;

/// 取消预约充电（废弃）
/// - Parameters:
///   - chargingPileName: 充电桩蓝牙广播号
///   - handler: 取消预约充电回调
- (void)ew_chargingPileCancelAppointmentCharging:(NSString *)chargingPileName
                                         handler:(EWChargingPilerResultHandler)handler;

/// 时长充电
/// - Parameters:
///   - chargingPileName: 充电桩蓝牙广播号
///   - startTime: 开始时间（时间戳）
///   - stopTime: 结束时间（时间戳）
///   - powerArray: 功率表（不传使用默认功率）
///   - isRepeat: 是否每天重复执行
///   - handler: 充电回调
- (void)ew_chargingPileDurationCharging:(NSString *)chargingPileName
                      chargingStartTime:(NSTimeInterval)startTime
                       chargingStopTime:(NSTimeInterval)stopTime
                     chargingPowerArray:(nullable NSArray <NSString *>*)powerArray
                                handler:(EWChargingPilerResultHandler)handler;

/// 时长充电
/// - Parameters:
///   - chargingMinutes: 充电分钟
///   - chargingPileName: 充电桩名称
///   - powerArray: 充电功率
///   - handler: 充电回调
- (void)ew_chargingBySpecifyDuration:(NSInteger)chargingMinutes
                        chargingPile:(NSString *)chargingPileName
                  chargingPowerArray:(nullable NSArray <NSString *>*)powerArray
                             handler:(EWChargingPilerResultHandler)handler;


/// 监控充电桩状态，请在主线程刷新UI，如果不使用请务必调用stopMonitorChargingPileStatus:handler
/// - Parameters:
///   - chargingPileName: 充电桩蓝牙广播号
///   - handler: 监控充电桩状态回调
- (void)ew_monitorChargingPileStatus:(NSString * _Nonnull)chargingPileName
                             handler:(EWChargingPileMonitorStatusHandler)handler;

/// 停止监控充电桩状态
/// - Parameters:
///   - chargingPileName: 充电桩蓝牙广播号
///   - handler: 成功回调
- (void)ew_stopMonitorChargingPileStatus:(NSString * _Nonnull)chargingPileName
                                 handler:(EWChargingPilerResultHandler)handler;

/// 获取充电桩 Wi-Fi 状态
/// - Parameters:
///   - chargingPileName: 充电桩蓝牙广播号
///   - handler: 获取充电桩 Wi-Fi 状态回调
- (void)ew_getChargingPileWiFiStatus:(NSString *)chargingPileName
                             handler:(EWChargingPileWiFiStatusHandler)handler;

/// 给充电桩传输 Wi-Fi 信息
/// - Parameters:
///   - chargingPileName: 充电桩蓝牙广播号
///   - SSID: Wi-Fi名称
///   - password: Wi-Fi密码
///   - handler: 获取充电桩 Wi-Fi 状态回调
- (void)ew_transmitWiFiInformationToChargingPile:(NSString *)chargingPileName
                                            SSID:(NSString *)SSID
                                        password:(nullable NSString *)password
                                         handler:(EWChargingPileWiFiStatusHandler)handler;

/// 充电桩连接 Wi-Fi
/// - Parameters:
///   - chargingPileName: 充电桩蓝牙广播号
///   - handler: 获取充电桩 Wi-Fi 状态回调
- (void)ew_chargingPileConnectionWiFi:(NSString *)chargingPileName
                              handler:(EWChargingPileWiFiStatusHandler)handler;

/// 断开充电桩 Wi-Fi
/// - Parameters:
///   - chargingPileName: 充电桩蓝牙广播号
///   - handler: 获取充电桩 Wi-Fi 状态回调
- (void)ew_disconnectChargingPileWiFi:(NSString *)chargingPileName
                              handler:(EWChargingPileWiFiStatusHandler)handler;

/// 获取充电桩Wi-Fi信息
/// - Parameters:
///   - chargingPileName: 充电桩蓝牙广播号
///   -  handler: 获取充电桩 Wi-Fi 信息回调
- (void)ew_getChargingPileWiFiInformation:(NSString *)chargingPileName
                                  handler:(EWChargingPileWiFiInformationHandler)handler;

/// 重置充电桩 Wi-Fi
/// - Parameters:
///   - chargingPileName: 充电桩蓝牙广播号
///   -  handler: 重置回调
- (void)ew_resetChargingPileWiFi:(NSString *)chargingPileName
                         handler:(EWChargingPilerResultHandler)handler;

/// 获取手机Wi-Fi信息
/// - Parameter handler: 获取手机 Wi-Fi 信息回调
- (void)ew_getWifiInformationHandler:(EWWifiInformationHandler)handler;

/// 配置ICCID
/// - Parameters:
///   - chargingPileName: 充电桩蓝牙广播号
///   - isWrite: 是否写入
///   - ICCID: ICCID字符串
///   -  handler: 配置ICCID回调
- (void)configureChargingPileICCID:(NSString *)chargingPileName
                           isWrite:(BOOL)isWrite
                            ICCID: (nullable NSString *)ICCIDString
                              handler:(EWChargingPileICCIDHandler)handler;

/// 配置APN信息（4G模块专用，预留）
/// - Parameters:
///   - chargingPileName: 充电桩蓝牙广播号
///   - APNString: APN信息 字符串类型
///   - handler: 配置APN信息回调
//- (void)configureChargingPileAPNInformation:(NSString *)chargingPileName
//                                    APNData:(NSData *)APNData
//                                    handler:(EWChargingPilerResultHandler)handler;

/// 配置用户ID
/// - Parameters:
///   - userID: 用户ID
///   - chargingPileName: 充电桩蓝牙广播号
///   - handler: 配置成功回调
- (void)ew_configureUserIDWithuserID:(NSString *)userID
                        chargingPile:(NSString *)chargingPileName
                             handler:(EWChargingPilerResultHandler)handler;

/// 获取漏电保护开关状态
/// - Parameters:
///   - chargingPileName: 充电桩蓝牙广播号
///   - handler: 开关状态回调
- (void)ew_getLeakageProtectionSwitchWithChargingPile:(NSString *)chargingPileName
                                              handler:(EWChargingPilerResultHandler)handler;

/// 配置漏电保护开关
/// - Parameters:
///   - isOn: 是否打开开关
///   - chargingPileName: 充电桩蓝牙广播号
///   - handler: 回调
- (void)ew_configureLeakageProtectionSwitch:(BOOL)isOn
                               chargingPile:(NSString *)chargingPileName
                                    handler:(EWChargingPilerResultHandler)handler;

/// 重置充电桩
/// - Parameters:
///   - chargingPileName: 充电桩蓝牙广播号
///   - handler: 回调
- (void)ew_resetChargingPileWithChargingPile:(NSString *)chargingPileName
                                     handler:(EWChargingPilerResultHandler)handler;


/// 配置机型编码及SN码
/// - Parameters:
///   - chargingPileName: 充电桩蓝牙广播号
///   - isWrite: 是否写入
///   - modelcode: 机型编码
///   - SNCode: SN码
///   - handler: 回调
- (void)ew_configureModelCodeAndSNWithChargingPile:(NSString *)chargingPileName
                                           isWrite:(BOOL)isWrite
                                         modelCode:(nullable NSString *)modelcode
                                            SNCode:(nullable NSString *)SNCode
                                           handler:(EWChargingPilerModelAndSNCodeHandler)handler;


/// 配置 MQTT 服务器地址
/// - Parameters:
///   - chargingPileName: 充电桩名字
///   - urlAddress: MQTT 服务器地址
///   - handler: 回调
- (void)ew_configureUrlAddressWithChargingPile:(NSString *)chargingPileName
                                    urlAddress:(NSString *)urlAddress
                                       handler:(EWChargingPilerUrlAddressHandler)handler;

/// 获取服务器地址
/// - Parameters:
///   - chargingPileName: 充电桩名字
///   - handler: 回调
- (void)ew_getUrlAddressWithChargingPile:(NSString *)chargingPileName
                                 handler:(EWChargingPilerUrlAddressHandler)handler;


/// 获取设备信息
/// - Parameters:
///   - chargingPileName: 充电桩名字
///   - handler: 回调
- (void)ew_getChargingPileInfo:(NSString *)chargingPileName
                       handler:(EWChargingPileInfoHandler)handler;


/// 配置设备信息
/// - Parameters:
///   - chargingPileName: 充电桩名字
///   - deviceInfoModel: 设备信息
///   - handler: 回调
- (void)ew_configureChargingPileInfo:(NSString *)chargingPileName
                     deviceInfoModel:(EWChargingPileInfoModel *)deviceInfoModel
                             handler:(EWChargingPileInfoHandler)handler;



/// 配置报错开关
///   - chargingPileName: 充电桩名字
///   - isWrite: 是否写入
///   - switchErrorModel: 错误开关配置
///   - handler: 回调
- (void)ew_configureSwitchErrorWithChargingPile: (NSString *)chargingPileName
                                        isWrite: (BOOL)isWrite
                                    switchError: (nullable EWChargingPileSwitchErrorModel *)switchErrorModel
                                        handler: (EWChargingPileSwitchErrorHandler)handler;

///配置CP调节
///   - chargingPileName: 充电桩名字
///   - isWrite: 是否写入
///   - cpAdjustment: CP调节配置
///   - handler: 回调
- (void)ew_configureCPAdjustmentWithChargingPile: (NSString *)chargingPileName
                                         isWrite: (BOOL)isWrite
                                         cpAdjustment: (nullable EWChargingPileCPModel *)cpModel
                                         handler: (EWChargingPileCPAdjustmentHandler) handler;

///读取NFC卡号
///   - chargingPileName: 充电桩名字
///   - cardNum: 要读取的卡序号
///   - handler: 回调
- (void)ew_readChargingPileNFCNumWithChagringPile: (NSString *)chargingPileName
                                          cardNum: (NSInteger)num
                                           handle: (EWChargingPileNFCNumHandler) handler;

///写入NFC卡号
///   - chargingPileName: 充电桩名字
///   - cardNum: 要写入的卡序号
///   - nfcCard: 要写入的卡号
///   - handler: 回调
- (void)ew_writeChagringPileNFCNumWithChargingPile: (NSString *)chargingPileName
                                           cardNum: (NSInteger)num
                                           nfcCard: (NSString *)nfcCard
                                            handle: (EWChargingPilerResultHandler)handler;

///进入/退出NFC保存卡号模式
///   - chargingPileName: 充电桩名字
///   - mode: 进入/退出保存、清除卡号模式
///   - handler: 回调
- (void)ew_configureChargingPileNFCModeWithChargingPile: (NSString *)chargingPileName
                                                 mode: (EWChargingPileSetRFIDMode)rfidMode
                                                 handle: (EWChargingPileNFCModeHandler)handler;
///配置多个服务器地址
///   - chargingPileName: 充电桩名字
///   - isWrite: 写/读
///   - serverID: 服务器编号
///   - url: 服务器地址
///   - handler: 回调
- (void)ew_configureChargingPileServerWithChargingPile: (NSString *)chargingPileName
                                               isWrite: (BOOL)isWrite
                                              serverID: (EWChargingPileServerID)serverID
                                                   url: (NSString *)urlAddress
                                                handle: (EWChargingPilerServerHandler)handler;

/// 配置MQTT账号密码
/// - Parameters:
///   - chargingPileName: 微逆蓝牙广播号
///   - isWrite: 是否写入
///   - account: mqtt账号
///   - password: mqtt密码
///   - key: mqtt密钥
///   - handler: 回调
- (void)ew_configureAccountAndPasswordWithChargingPile:(NSString *)chargingPileName
                                           isWrite:(BOOL)isWrite
                                                account:(nullable NSString *)account
                                               password:(nullable NSString *)password
                                                   key:(nullable NSString *) key
                                               handler:(EWChargingPileAccountAndPasswordHandler)handler;

/// 配置警告开关
/// - Parameters:
///   - chargingPileName: 充电桩名字
///   - isWrite: 是否写入
///   - switchErrorModel: 警告开关配置
///   - handler: 回调
- (void)ew_configureSwitchWarnWithChargingPile: (NSString *)chargingPileName
                                        isWrite: (BOOL)isWrite
                                    switchWarn: (nullable EWChargingPileSwitchErrorModel *)switchWarnModel
                                        handler: (EWChargingPileSwitchErrorHandler)handler;

/// 设置充电电流
/// - Parameters:
///   - chargingPileName: 充电桩名字
///   - isWrite: 是否写入
///   - maxCurrent: 最大电流
///   - handler: 回调
- (void)ew_configureMaxCurrentWithChargingPile:(NSString *)chargingPileName
                                       isWrite:(BOOL)isWrite
                                    maxCurrent:(NSInteger)maxCurrent
                                       handler: (EWChargingPileMaxCurrentHandler)handler;

/// 读取设备使用情况
/// - Parameters:
///   - chargingPileName: 充电桩名字
///   - handler: 回调
- (void)ew_readUsageInfoWithChargingPile: (NSString *)chargingPileName
                                             handler: (EWChargingPileUsageHandler)handler;

/// 读取设备日志
/// - Parameters:
///   - chargingPileName: 充电桩名字
///   - logID: 要查询的日志id
///   - handler: 回调
- (void)ew_readLogWithChargingPile: (NSString *)chargingPileName
                           logID: (NSInteger)num
                           handler: (EWChargingPileLogHandler)handler;

/// 删除设备日志
/// - Parameters:
///   - chargingPileName: 充电桩名字
///   - handler: 回调
- (void)ew_deleteLogWithChargingPile: (NSString *)chargingPileName
                             handler: (EWChargingPileDeleteLogHandler)handler;

/// 配置预约充电
/// - Parameters:
///   - chargingPileName: 充电桩名字
///   - isWrite: 是否写入
///   - timeZone: 与标准时区的偏差+-24
///   - currentTime: 当前时间的毫秒时间戳
///   - bookArray: 预约信息
///   - handler: 回调
- (void)ew_configBookInfoWithChargingPile: (NSString *)chargingPileName
                                  isWrite: (BOOL)isWrite
                                 timezone:(NSInteger)timezone
                              currentTime:(NSTimeInterval)currentTime
                                bookArray:(NSArray <EWChargingPileAppointmentModel *>*)bookArray
                                  handler: (EWChargingPileAppointmentHandler)handler;

/// 配置预约充电（传入字典）
/// - Parameters:
///   - chargingPileName: 充电桩名字
///   - isWrite: 是否写入
///   - timeZone: 与标准时区的偏差+-24
///   - currentTime: 当前时间的毫秒时间戳
///   - bookDicArr: 预约信息字典
///   - handler: 回调
- (void)ew_configBookInfoWithChargingPile: (NSString *)chargingPileName
                                  isWrite: (BOOL)isWrite
                                 timezone:(NSInteger)timezone
                              currentTime:(NSTimeInterval)currentTime
                                bookDicArr:(NSArray<NSDictionary *> *)bookDicArr
                                  handler: (EWChargingPileAppointmentHandler)handler;

/// OTA升级
/// - Parameters:
///   - chargingPileName: 充电桩蓝牙广播号
///   - upgradeDelegate: 升级代理
///   - filePath: 文件路径
///   - handler: 回调
- (void)chargingPileUpdate:(NSString *)chargingPileName
           upgradeDelegate:(id<EWPeripheralUpgradeDelegate>)upgradeDelegate
                  filePath:(NSString *)filePath
                   handler:(EWChargingPileUpgradeHandler)handler;

@end

NS_ASSUME_NONNULL_END
