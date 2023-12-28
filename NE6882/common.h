#ifndef COMMON_H
#define COMMON_H

#define DEF_TESTITEM_MAX 24

#define UI_ACCEPTED 1
#define UI_REJECTED 0

enum class JSON_STRUCTTYPE{
    ENM_ITEM_UNKNOWN = 0,
    ENM_ITEM_SYSTEM,
    ENM_ITEM_TEST,
    ENM_ITEM_MAX
};

enum class TEST_ITEM{
    ENM_ITEM_UNKNOWN = 0,
    ENM_ITEM_IR,
    ENM_ITEM_PEQ,
    ENM_ITEM_MAX
};


#endif // COMMON_H
