//
//  EWChargingPileMQTTInfoModel.h
//  EWChargingPileSDK
//
//  Created by keli on 2023/4/12.
//

#import <Foundation/Foundation.h>
#import "EWChargingPileProfiles.h"
NS_ASSUME_NONNULL_BEGIN

@interface EWChargingPileMQTTInfoModel : NSObject
// 激活状态 0 未激活 1 在线 2 离线
@property (nonatomic, assign) EWCPActivationStatus activationStatus;
// 桩状态 0 空闲 1 充电中 2 故障 3 预约中 4 升级中 5 急停
@property (nonatomic, assign) NSInteger pileStatus;
// 枪状态 0 未插入 1 已插入
@property (nonatomic, assign) NSInteger gunStatus;
// 充电状态 0：未充电 1：正在充电 2：充电完成
@property (nonatomic, assign) NSInteger chargeStatus;
// 网络模块固件版本 （4g没有）
@property (nonatomic, strong) NSNumber *netFirmVer;
// 主控模块固件版本
@property (nonatomic, strong) NSNumber *appFirmVer;
// 功率模块固件版本 （交流充电桩没有
@property (nonatomic, strong) NSNumber *mcbFirmVer;
// WiFi名称
@property (nonatomic, strong) NSString *wifiSsid;
// WiFi是否可用 0 是  1 否
@property (nonatomic, assign) NSInteger wifiIsNormal;
// 错误码
@property (nonatomic, strong) NSArray *errCode;
// 可选，经度，使用设备定位时需要上传
@property (nonatomic, assign) CGFloat lon;
//  可选，纬度，使用设备定位时需要上传
@property (nonatomic, assign) CGFloat lat;
// 板子信息，设备的配置信息等，json格式，对象可自定义
@property (nonatomic, strong) NSDictionary *board;

- (instancetype)initModelWithDic:(NSDictionary *)jsonDic;
@end

NS_ASSUME_NONNULL_END
