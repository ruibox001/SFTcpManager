//
//  UdpSocket.h
//  SmartHome3.0
//
//  Created by 王声远 on 15/6/27.
//  Copyright (c) 2015年 anody. All rights reserved.
//

#import <Foundation/Foundation.h>

//公用日志打印LOG
#ifdef DEBUG
#define HYString [NSString stringWithFormat:@"%s", __FILE__].lastPathComponent
#define SLOG(...) printf("%s 第%d行: %s\n", [HYString UTF8String] ,__LINE__, [[NSString stringWithFormat:__VA_ARGS__] UTF8String]);
#else
#define SLOG(...)
#endif

@class TcpSocket;

@protocol TcpSocketDelegate <NSObject>
@optional

- (void)tcpSocket:(TcpSocket *)udpSocket receverData:(NSString *)data;
- (void)tcpSocket:(TcpSocket *)udpSocket connectStatus:(BOOL)connect;

@end

@interface TcpSocket : NSObject

@property (nonatomic,weak) id <TcpSocketDelegate> delegate;

+ (instancetype) shareTcpSocket;

- (void)connect:(NSString *)host port:(int)port;

- (void)disConnect;

- (BOOL)isConnected;

- (void)reConnect;

- (void)sendData:(NSData *)data;

@end
