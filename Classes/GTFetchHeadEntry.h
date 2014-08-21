//
//  GTFetchHeadEntry.h
//  ObjectiveGitFramework
//
//  Created by Pablo Bendersky on 8/14/14.
//  Copyright (c) 2014 GitHub, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>

@class GTRepository;
@class GTOID;
@class GTReference;

/// A class representing an entry on the FETCH_HEAD file, as returned by the callback of git_repository_fetchhead_foreach.
@interface GTFetchHeadEntry : NSObject

/// The reference of this fetch entry.
@property (nonatomic, readonly, strong) GTReference *reference;

/// The remote URL where this entry was originally fetched from.
@property (nonatomic, readonly, copy) NSString *remoteURL;

/// The target OID of this fetch entry (what we need to merge with)
@property (nonatomic, readonly, strong) GTOID *targetOID;

/// Flag indicating if we need to merge this entry or not.
@property (nonatomic, getter = isMerge, readonly) BOOL merge;

/// Initializes a GTFetchHeadEntry.
///
/// reference - Reference on the repository
/// remoteURL - URL where this was originally fetched from
/// targetOID - Target OID
/// merge     - Indicates if this is pending a merge.
- (instancetype)initWithReference:(GTReference *)reference remoteURL:(NSString *)remoteURL targetOID:(GTOID *)targetOID isMerge:(BOOL)merge;

/// Returns a new GTFetchHeadEntry instance.
///
/// reference - Reference on the repository
/// remoteURL - URL where this was originally fetched from
/// targetOID - Target OID
/// merge     - Indicates if this is pending a merge.
///
/// Returns a new GTFetchHeadEntry already initialized.
+ (instancetype)fetchEntryWithReference:(GTReference *)reference remoteURL:(NSString *)remoteURL targetOID:(GTOID *)targetOID isMerge:(BOOL)merge;

@end
