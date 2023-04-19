//
//  EWChargingPileMQTT.h
//  EWChargingPileSDK
//
//  Created by keli on 2023/4/11.
//

#import <Foundation/Foundation.h>
#import "EWChargingPileProfiles.h"
#import "EWChargingPileDelegate.h"
#import "EWChargingPileMQTTInfoModel.h"
#import "EWChargingPileMQTTStatusModel.h"

NS_ASSUME_NONNULL_BEGIN

@interface EWChargingPileMQTT : NSObject
/// MQTT 服务器地址
@property (nonatomic, strong) NSString *host;
/// MQTT 服务器端口
@property (nonatomic, assign) UInt32 port;
/// 是否启用安全传输，默认为 NO
@property (nonatomic, assign) BOOL tls;
/// 超过多少时间进行重发
@property (nonatomic, assign) double dupTimeout;
/// 运行线程
@property (nonatomic, strong) dispatch_queue_t queue;
/// 代理
@property (nonatomic, weak) id<EWChargingPileDelegate> delegate;


/// 单例
+ (instancetype)share;

/// 配置key和密钥
/// - Parameters:
///   - appId: appId
///   - appSecret: appSecret
- (void)ew_configureChargingPileAppId:(NSString *)appId
                            appSecret:(NSString *)appSecret;


/// 充电桩 MQTT 认证
/// - Parameters:
///   - clientId: 客户端ID
///   - userID: 用户ID
///   - userName: 用户名
///   - password: 密码
- (void)ew_chargingPileCertificationWithClientId:(nonnull NSString *)clientId
                                          userID:(nullable NSString *)userID
                                        userName:(nullable NSString *)userName
                                        password:(nullable NSString *)password;


///  充电桩订阅主题，请在认证成功后调用
/// - Parameters:
///   - productCode: 机型码
///   - deviceNum: 设备编号
- (void)ew_subscribeToTopicWithProductCode:(nonnull NSString *)productCode
                                 deviceNum:(nonnull NSString *)deviceNum;

#pragma mark - 发布主题
/// 获取设备信息
/// - Parameters:
///   - productCode: 机型码
///   - deviceNum: 设备编号
- (void)ew_getChargingInfoWithProductCode:(nonnull NSString *)productCode
                                deviceNum:(nonnull NSString *)deviceNum;


/// 配置充电模式
/// - Parameters:
///   - mode: 充电模式
///   - productCode: 机型码
///   - deviceNum: 设备编号
- (void)ew_configureChargingMode:(EWCPChargingMode)mode
                     productCode:(nonnull NSString *)productCode
                       deviceNum:(nonnull NSString *)deviceNum;


/// 配置NFC开关
/// - Parameters:
///   - nfcSwitch: NFC 开关
///   - productCode: 机型码
///   - deviceNum: 设备编号
- (void)ew_configureNFCSwitch:(BOOL)nfcSwitch
                  productCode:(nonnull NSString *)productCode
                    deviceNum:(nonnull NSString *)deviceNum;


/// 同步时间
/// - Parameters:
///   - productCode: 机型码
///   - deviceNum: 设备编号
- (void)ew_syncChargingPileTimeWithProductCode:(nonnull NSString *)productCode
                                     deviceNum:(nonnull NSString *)deviceNum;


/// 开始充电
/// - Parameters:
///   - power: 充电功率
///   - productCode: 机型码
///   - deviceNum: 设备编号
- (void)ew_startChargingWithPower:(NSNumber *)power
                      productCode:(nonnull NSString *)productCode
                        deviceNum:(nonnull NSString *)deviceNum;


/// 预约充电
/// - Parameters:
///   - startTime:开始时间戳，毫秒
///   - endTime: 结束时间戳，毫秒
///   - powerArray: 功率数组
///   - productCode: 机型码
///   - deviceNum: 设备编号
- (void)ew_appointmentChargingWithStartTime:(NSTimeInterval)startTime
                                    endTime:(NSTimeInterval)endTime
                         chargingPowerArray:(NSArray <NSNumber *>*)powerArray
                                productCode:(nonnull NSString *)productCode
                                  deviceNum:(nonnull NSString *)deviceNum;

/// 时长充电
/// - Parameters:
///   - startTime:开始时间戳，毫秒
///   - endTime: 结束时间戳，毫秒
///   - power: 功率
///   - productCode: 机型码
///   - deviceNum: 设备编号
- (void)ew_durationChargingWithStartTime:(NSTimeInterval)startTime
                                 endTime:(NSTimeInterval)endTime
                                   power:(NSNumber *)power
                             productCode:(nonnull NSString *)productCode
                               deviceNum:(nonnull NSString *)deviceNum;

/// 结束充电
/// - Parameters:
///   - productCode: 机型码
///   - deviceNum: 设备编号
- (void)ew_endChargingWithProductCode:(nonnull NSString *)productCode
                            deviceNum:(nonnull NSString *)deviceNum;


/// 监控充电桩
/// - Parameters:
///   - productCode: 机型码
///   - deviceNum: 设备编号
- (void)ew_monitorChargingPileWithProductCode:(nonnull NSString *)productCode
                                    deviceNum:(nonnull NSString *)deviceNum;

/// 充电桩 OTA 升级
/// - Parameters:
///   - type:  固件版本类型(1网络模块 2主控模块 3功率模块)
///   - vaersion: 版本号，可用于匹配固件版本
///   - url: 固件下载地址
///   - md5: 文件md5编码
///   - productCode: 机型码
///   - deviceNum: 设备编号
- (void)ew_chargingPileUpdateWithType:(NSInteger)type
                              version:(CGFloat)version
                          downloadUrl:(nonnull NSString *)url
                                  md5:(nonnull NSString *)md5
                          productCode:(nonnull NSString *)productCode
                            deviceNum:(nonnull NSString *)deviceNum;
@end

NS_ASSUME_NONNULL_END
