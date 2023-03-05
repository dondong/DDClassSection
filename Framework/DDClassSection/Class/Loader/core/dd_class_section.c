//
//  dd_class_section.c
//  DDClassSection
//
//  Created by dondong on 2023/3/5.
//

#include "dd_class_section.h"
#import <string.h>
#import <mach-o/dyld.h>
#import <mach-o/getsect.h>

Class *dd_copy_section_classes(const char *segname, const char *sectname, unsigned int *outCount)
{
    unsigned int count = 0;
    for (int i = 0; i < _dyld_image_count(); ++i) {
        const struct mach_header *mhp = _dyld_get_image_header(i);
        unsigned long size = 0;
        getsectiondata((const struct mach_header_64 *)mhp, segname, sectname, &size);
        count += (unsigned int)size / sizeof(uintptr_t);
    }
    if (NULL != outCount) {
        *outCount = count;
    }
    int index = 0;
    Class *ret = malloc(sizeof(Class) * count);
    memset(ret, 0, sizeof(Class) * count);
    for (int i = 0; i < _dyld_image_count(); ++i) {
        const struct mach_header *mhp = _dyld_get_image_header(i);
        unsigned long size = 0;
        uintptr_t *ptr = (uintptr_t *)getsectiondata((const struct mach_header_64 *)mhp, segname, sectname, &size);
        unsigned int count = (unsigned int)size / sizeof(uintptr_t);
        for (int j = 0; j < count; ++j, ++index) {
            ret[index] = (Class)(void *)ptr[j];
        }
    }
    return ret;
}
