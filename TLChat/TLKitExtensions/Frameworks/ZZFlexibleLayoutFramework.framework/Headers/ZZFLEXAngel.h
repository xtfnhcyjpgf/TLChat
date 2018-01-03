//
//  ZZFLEXAngel.h
//  ZZFLEXDemo
//
//  Created by 李伯坤 on 2017/12/14.
//  Copyright © 2017年 李伯坤. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ZZFLEXChainSectionModel.h"
#import "ZZFLEXChainViewModel.h"
#import "ZZFLEXChainViewArrayModel.h"
#import "ZZFLEXChainCellEditModel.h"
#import "ZZFLEXChainAllCellsEditModel.h"
#import "ZZFLEXChainDataModel.h"

#define     ZZFLEX_CHAINAPI_TYPE            @property (nonatomic, copy, readonly)

@interface ZZFLEXAngel : NSObject

/// 数据源
@property (nonatomic, strong) NSMutableArray *data;

/// 宿主，可以是tableView或者collectionView
@property (nonatomic, weak, readonly) __kindof UIScrollView *hostView;

/**
 *  根据宿主View初始化
 */
- (instancetype)initWithHostView:(__kindof UIScrollView *)hostView;
- (instancetype)init NS_UNAVAILABLE;

@end

#pragma mark - ## ZZFLEXAngel (API)
@interface ZZFLEXAngel (API)

#pragma mark - # 整体
/// 删除所有元素
ZZFLEX_CHAINAPI_TYPE BOOL (^clear)(void);

/// 删除所有Cell
ZZFLEX_CHAINAPI_TYPE BOOL (^clearAllCells)(void);

#pragma mark - # Section操作
/// 添加section
ZZFLEX_CHAINAPI_TYPE ZZFLEXChainSectionModel *(^addSection)(NSInteger tag);

/// 插入section
ZZFLEX_CHAINAPI_TYPE ZZFLEXChainSectionInsertModel *(^insertSection)(NSInteger tag);

/// 获取/编辑section （可清空、获取数据源等）
ZZFLEX_CHAINAPI_TYPE ZZFLEXChainSectionEditModel *(^sectionForTag)(NSInteger tag);

/// 删除section
ZZFLEX_CHAINAPI_TYPE BOOL (^deleteSection)(NSInteger tag);

/// 判断section是否存在
ZZFLEX_CHAINAPI_TYPE BOOL (^hasSection)(NSInteger tag);


#pragma mark - # Section HeaderFooter 操作
/// 为section添加headerView，传入nil将删除header
ZZFLEX_CHAINAPI_TYPE ZZFLEXChainViewModel *(^setHeader)(NSString *className);

/// 为section添加footerView，传入nil将删除footer
ZZFLEX_CHAINAPI_TYPE ZZFLEXChainViewModel *(^setFooter)(NSString *className);


#pragma mark - # Section Cell 操作
/// 添加cell
ZZFLEX_CHAINAPI_TYPE ZZFLEXChainViewModel *(^ addCell)(NSString *className);
/// 批量添加cell
ZZFLEX_CHAINAPI_TYPE ZZFLEXChainViewArrayModel *(^ addCells)(NSString *className);
/// 添加空白cell
ZZFLEX_CHAINAPI_TYPE ZZFLEXChainViewModel *(^ addSeperatorCell)(CGSize size, UIColor *color);


/// 插入cell
ZZFLEX_CHAINAPI_TYPE ZZFLEXChainViewInsertModel *(^ insertCell)(NSString *className);
/// 批量插入cell
ZZFLEX_CHAINAPI_TYPE ZZFLEXChainViewArrayInsertModel *(^ insertCells)(NSString *className);


/// 删除第一个符合条件的cell
ZZFLEX_CHAINAPI_TYPE ZZFLEXChainCellEditModel *deleteCell;
/// 删除所有符合条件的cell
ZZFLEX_CHAINAPI_TYPE ZZFLEXChainAllCellsEditModel *deleteCells;


/// 更新第一个符合条件的cell高度
ZZFLEX_CHAINAPI_TYPE ZZFLEXChainCellEditModel *updateCell;
/// 更新所有符合条件的cell高度
ZZFLEX_CHAINAPI_TYPE ZZFLEXChainAllCellsEditModel *updateCells;


/// 是否包含cell
ZZFLEX_CHAINAPI_TYPE ZZFLEXChainCellEditModel *hasCell;

#pragma mark - # DataModel 数据源获取
/// 数据源获取
ZZFLEX_CHAINAPI_TYPE ZZFLEXChainDataModel *dataModel;

@end