//
//  dd_class_section.h
//  DDClassSection
//
//  Created by dondong on 2023/3/5.
//

#ifndef dd_class_section_h
#define dd_class_section_h

#import <objc/runtime.h>

Class *dd_copy_section_classes(const char *segname, const char *sectname, unsigned int *outCount);

#endif /* dd_class_section_h */
