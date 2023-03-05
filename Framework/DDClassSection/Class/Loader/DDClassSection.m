//
//  DDClassSection.m
//  DDClassSection
//
//  Created by dondong on 2023/3/5.
//

#import "DDClassSection.h"
#import "dd_class_section.h"

@implementation DDClassSection
+ (NSArray<Class> *)getClassListInSegment:(nonnull NSString *)segName section:(nonnull NSString *)sectName
{
    NSMutableArray *classList = [NSMutableArray array];
    unsigned int count = 0;
    Class *list = dd_copy_section_classes([segName cStringUsingEncoding:NSUTF8StringEncoding], [sectName cStringUsingEncoding:NSUTF8StringEncoding], &count);
    for (int i = 0; i < count; ++i) {
        [classList addObject:list[i]];
    }
    if (NULL != list) {
        free(list);
    }
    return [NSArray arrayWithArray:classList];
}
@end
