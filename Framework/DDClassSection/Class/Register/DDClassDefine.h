//
//  DDClassDefine.h
//  DDClassSection
//
//  Created by dondong on 2023/3/4.
//

#ifndef DDClassDefine_h
#define DDClassDefine_h
struct _prop_t {
    const char *name;
    const char *attributes;
};

struct _protocol_t;

struct _objc_method {
    struct objc_selector * _cmd;
    const char *method_type;
    void  *_imp;
};

struct _protocol_t {
    void * isa;  // NULL
    const char *protocol_name;
    const struct _protocol_list_t * protocol_list; // super protocols
    const struct method_list_t *instance_methods;
    const struct method_list_t *class_methods;
    const struct method_list_t *optionalInstanceMethods;
    const struct method_list_t *optionalClassMethods;
    const struct _prop_list_t * properties;
    const unsigned int size;  // sizeof(struct _protocol_t)
    const unsigned int flags;  // = 0
    const char ** extendedMethodTypes;
};

struct _ivar_t {
    unsigned long int *offset;  // pointer to ivar offset location
    const char *name;
    const char *type;
    unsigned int alignment;
    unsigned int  size;
};

struct _class_ro_t {
    unsigned int flags;
    unsigned int instanceStart;
    unsigned int instanceSize;
    unsigned int reserved;
    const unsigned char *ivarLayout;
    const char *name;
    const struct _method_list_t *baseMethods;
    const struct _objc_protocol_list *baseProtocols;
    const struct _ivar_list_t *ivars;
    const unsigned char *weakIvarLayout;
    const struct _prop_list_t *properties;
};

struct _class_t {
    struct _class_t *isa;
    struct _class_t *superclass;
    void *cache;
    void *vtable;
    struct _class_ro_t *ro;
};

struct _category_t {
    const char *name;
    struct _class_t *cls;
    const struct _method_list_t *instance_methods;
    const struct _method_list_t *class_methods;
    const struct _protocol_list_t *protocols;
    const struct _prop_list_t *properties;
};

#endif /* DDClassDefine_h */
