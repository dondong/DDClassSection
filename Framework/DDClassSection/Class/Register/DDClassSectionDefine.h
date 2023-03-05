//
//  DDClassSectionDefine.h
//  DDClassSection
//
//  Created by dondong on 2023/3/4.
//

#ifndef DDClassSectionDefine_h
#define DDClassSectionDefine_h
#import "DDClassDefine.h"
#ifdef __cplusplus
extern "C" {
#endif
#define DDClassSection(className, segmentName, sectionName) \
__attribute__((dllimport)) struct _class_t OBJC_CLASS_$_ ##className;\
struct _class_t * __ ##className  __attribute((used, section(""#segmentName", "#sectionName""))) = &OBJC_CLASS_$_ ##className;
#ifdef __cplusplus
}
#endif
#endif /* DDClassSectionDefine_h */
