#include "commontest.h"

QString getOutputModeName(const int p_language, const int p_outputmode)
{
    switch(p_outputmode)
    {
    case ENM_OUTPUT_THREEPHASE:
        return "三相标准";
    case ENM_OUTPUT_DISCRETE:
        return "三相分立";
    case ENM_OUTPUT_IMBANLANCE:
        return "三相不平衡";
    case ENM_OUTPUT_SINGLE:
        return "合并单相";
    default:
        return "";
    }
}

QString getTestModeName(const int p_language, const int p_testmode)
{
    switch(p_testmode)
    {
    case ENM_TESTMODE_GENERAL:
        return "常规三相";
    case ENM_TESTMODE_STEPLADDER:
        return "阶梯";
    case ENM_TESTMODE_STEP:
        return "步阶";
    case ENM_TESTMODE_GRADIENT:
        return "渐变";
    case ENM_TESTMODE_THROUGH:
        return "低压穿越";
    default:
        return "";
    }
}
