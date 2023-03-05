//
//  ViewController.m
//  DDClassSection
//
//  Created by dondong on 2023/3/4.
//

#import "ViewController.h"
#import "DDClassSectionDefine.h"
#import "DDClassSection.h"
#import "DDTestProtocol.h"

@interface ViewController ()

@end
#define SegmentName "__DATA"
#define SectionName "__ddclsli"
#define DemoRegisterClass(className) DDClassSection(className, __DATA, __dd_class_list)
DemoRegisterClass(DDLazyClass)
DemoRegisterClass(DDNonlazyClass)
//DDClassSection(DDLazyClass, __DATA, __dd_class_list)
//DDClassSection(DDNonlazyClass, __DATA, __dd_class_list)
@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    NSArray *clsList = [DDClassSection getClassListInSegment:@"__DATA" section:@"__dd_class_list"];
    for (Class cls in clsList) {
        if ([cls respondsToSelector:@selector(registerClass)]) {
            [cls registerClass];
        }
    }
}


@end
