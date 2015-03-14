//
//  PGActionBrowserProvider.h
//  XCActionBar
//
//  Created by Pedro Gomes on 10/03/2015.
//  Copyright (c) 2015 Pedro Gomes. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "PGConstants.h"

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
@protocol PGActionProvider;
@protocol PGActionBrowserProviderDelegate <NSObject>

- (void)actionProviderDidNotifyOfIndexRebuildNeeded:(id<PGActionProvider>)provider;

@end
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
@protocol PGActionProvider <NSObject>

@property (nonatomic, weak) id<PGActionBrowserProviderDelegate> delegate;

- (void)prepareActionsOnQueue:(dispatch_queue_t)indexerQueue
            completionHandler:(PGGeneralCompletionHandler)completionHandler;
- (void)prepareActionsWithCompletionHandler:(PGGeneralCompletionHandler)completionHandler;

- (NSString *)actionCategory;
- (NSString *)actionGroupName;

- (NSArray *)findAllActions;
- (NSArray *)findActionsMatchingExpression:(NSString *)expression;

@end
