//
//  DDNonlazyClass.m
//  DDClassSection
//
//  Created by dondong on 2023/3/5.
//

#import "DDNonlazyClass.h"

@implementation DDNonlazyClass
+ (void)load
{
    NSLog(@"+[DDNonlazyClass load");
}

+ (void)registerClass
{
    NSLog(@"register DDNonlazyClass");
}
@end
