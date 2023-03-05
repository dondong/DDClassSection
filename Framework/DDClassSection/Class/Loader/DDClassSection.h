//
//  DDClassSection.h
//  DDClassSection
//
//  Created by dondong on 2023/3/5.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface DDClassSection : NSObject
+ (NSArray<Class> *)getClassListInSegment:(nonnull NSString *)segName section:(nonnull NSString *)sectName;
@end

NS_ASSUME_NONNULL_END
