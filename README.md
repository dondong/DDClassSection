
## Example

#Register
```objective-c
#define DemoRegisterClass(className) DDClassSection(className, __DATA, __dd_class_list)
```
#Loader
```objective-c
NSArray *clsList = [DDClassSection getClassListInSegment:@"__DATA" section:@"__dd_class_list"];
for (Class cls in clsList) {
    // do somethinge
}
```

## Author

dondong, the-last-choice@qq.com

## License

DDMemoryKit is available under the MIT license. See the LICENSE file for more info.
