#ifndef NE6882SERIAL_GLOBAL_H
#define NE6882SERIAL_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(NE6882SERIAL_LIBRARY)
#  define NE6882SERIALSHARED_EXPORT Q_DECL_EXPORT
#else
#  define NE6882SERIALSHARED_EXPORT Q_DECL_IMPORT
#endif

#define DEF_MSGTYPE_REQUEST 1
#define DEF_MSGTYPE_RESULT 2

enum class NE6882_CMD{
    CMD_UNKNOWN = 0,
    CMD_START,
    CMD_STOP,
    CMD_QUERY,
    CMD_SET,
    CMD_SET_IR,
    CMD_SET_PEQ,
    CMD_REQUEST,
    CMD_COMPENSATION,
    CMD_CALIBRATE,
    CMD_OFFSET,
    CMD_VERSION,
    CMD_GET_IR,
    CMD_GET_PEQ,
    CMD_MAX
};

enum class NE6882_STATE{
    STATE_UNKNOWN = 0,
    STATE_GROUP_IDLE,
    STATE_GROUP_TESTING,
    STATE_GROUP_TESTOVER,
    STATE_GROUP_STEP,
    STATE_GROUP_SELFCHECK,
    STATE_STEP_TESTING,
    STATE_STEP_OK,
    STATE_STEP_NG,
    STATE_STEP_NULL,
    STATE_STEP_ERROR,
    STATE_MAX
};

enum class NE6882_ITEM{
    ITEM_UNKNOWN = 0,
    ITEM_IR,
    ITEM_PEQ,
    ITEM_MAX
};

typedef struct NE6882Data{
    NE6882_CMD cmdType;
    NE6882_STATE groupState;
    NE6882_STATE testState;
    int msgType;
    bool resultState;
    NE6882_ITEM testItem;
    float fVolt;
    float fCurrent;
    float fIrLow;
    float fIrHigh;
    float fTestTime;
    float fComp;
    int nConnectMode;   //0 继续 1 停止 2 单步
    quint8 strVersion[8];
    float fTestVal;
    int nIrUnit;    //0 mohm 1 ohm 2 Mohm 3Gohm
    int nFailStep;
    int nStepNo;
}NE6882Msg;

typedef void(*requsetCallback)(const NE6882Msg p_data, unsigned int p_User);

#endif // NE6882SERIAL_GLOBAL_H
