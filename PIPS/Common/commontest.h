#ifndef COMMONTEST_H
#define COMMONTEST_H

#include <QString>
#include <QList>


//小数位数
#define DEF_DECIMAL_VOLTAGE 1
#define DEF_DECIMAL_CURRENT 1
#define DEF_DECIMAL_FREQ 2
#define DEF_DECIMAL_POWER 3
#define DEF_DECIMAL_CFPF 3
#define DEF_DECIMAL_TIME 1

#define DEF_UNIT_VOLTAGE QStringLiteral(" V")
#define DEF_UNIT_CURRENT QStringLiteral(" A")
#define DEF_UNIT_FREQ QStringLiteral(" Hz")
#define DEF_UNIT_POWER QStringLiteral(" KW")
#define DEF_UNIT_APPARENTPOWER QStringLiteral(" KVA")
#define DEF_UNIT_TIME QStringLiteral(" S")

enum TestMode{
    ENM_TESTMODE_UNKNOWN = -1,
    ENM_TESTMODE_GENERAL,
    ENM_TESTMODE_STEPLADDER,
    ENM_TESTMODE_STEP,
    ENM_TESTMODE_GRADIENT,
    ENM_TESTMODE_THROUGH,
    ENM_TESTMODE_SYSTEM,
    ENM_TESTMODE_MAX
};

enum OutputMode{
    ENM_OUTPUT_UNKNOWN = -1,
    ENM_OUTPUT_THREEPHASE,
    ENM_OUTPUT_DISCRETE,
    ENM_OUTPUT_IMBANLANCE,
    ENM_OUTPUT_SINGLE,
    ENM_OUTPUT_MAX
};

enum LANGUAGE{
    ENM_LANGUAGE_UNKNOWN = 0x10,
    ENM_LANGUAGE_CH,
    ENM_LANGUAGE_EN,
    ENM_LANGUAGE_MAX
};

enum CMDCTRL{
    ENM_CMD_UNKNOWN = 0x100,
    ENM_CMD_START,
    ENM_CMD_STOP,
    ENM_CMD_SET,
    ENM_CMD_HARMONICSSET,
    ENM_CMD_HARMONICSUPDATE,
    ENM_CMD_MAX
};

enum LOGTYPE{
    ENM_LOG_UNKNOWN = 0x1000,
    ENM_LOG_GENERAL_START,
    ENM_LOG_GENERAL_STOP,
    ENM_LOG_GENERAL_SAVE,
    ENM_LOG_STEPLADDER_START,
    ENM_LOG_STEPLADDER_STOP,
    ENM_LOG_STEPLADDER_SAVE,
    ENM_LOG_STEP_START,
    ENM_LOG_STEP_STOP,
    ENM_LOG_STEP_SAVE,
    ENM_LOG_GRADIENT_START,
    ENM_LOG_GRADIENT_STOP,
    ENM_LOG_GRADIENT_SAVE,
    ENM_LOG_THROUGH_START,
    ENM_LOG_THROUGH_STOP,
    ENM_LOG_THROUGH_SAVE,
    ENM_LOG_HARMONICS_SAVE,
    ENM_LOG_SYSTEM_SAVE,
    ENM_LOG_USER_LOGIN,
    ENM_LOG_MAX
};


typedef struct GeneralTable{
    int VoltageLevel;
    int OutputMode;
    int StepNo;
    float StartTimeU;
    float StartTimeV;
    float StartTimeW;
    int EnableU;
    int EnableV;
    int EnableW;
    float VoltageU;
    float VoltageV;
    float VoltageW;
    float FrequencyU;
    float FrequencyV;
    float FrequencyW;
    int WaveFormU;
    int WaveFormV;
    int WaveFormW;
    float AnglesUV;
    float AnglesUW;
    float AnglesVW;
}GeneralData;

typedef struct StepLadderTable
{
    int OutputMode;
    float StartVoltageU;
    float StartVoltageV;
    float StartVoltageW;
    float StepVoltageU;
    float StepVoltageV;
    float StepVoltageW;
    float StartFrequencyU;
    float StartFrequencyV;
    float StartFrequencyW;
    float StepFrequencyU;
    float StepFrequencyV;
    float StepFrequencyW;
    int WaveFormU;
    int WaveFormV;
    int WaveFormW;
    float AnglesUV;
    float AnglesUW;
    float AnglesVW;
    float StepTimeU;
    float StepTimeV;
    float StepTimeW;
    int StepCountU;
    int StepCountV;
    int StepCountW;
}StepLadderData;

typedef struct StepTable
{
    int OutputMode;
    int StepNo;
    int Phase; // 1/2/3/0 U/V/W/0
    float VoltageU;
    float VoltageV;
    float VoltageW;
    float FrequencyU;
    float FrequencyV;
    float FrequencyW;
    int WaveFormU;
    int WaveFormV;
    int WaveFormW;
    float AnglesUV;
    float AnglesUW;
    float AnglesVW;
    float StepTimeU;
    float StepTimeV;
    float StepTimeW;
}StepData;

typedef struct GradientTable
{
    int OutputMode;
    int StepNo;
    int Phase; // 1/2/3/0 U/V/W/0
    float StartVoltageU;
    float StartVoltageV;
    float StartVoltageW;
    float StopVoltageU;
    float StopVoltageV;
    float StopVoltageW;
    float StartFrequencyU;
    float StartFrequencyV;
    float StartFrequencyW;
    float StopFrequencyU;
    float StopFrequencyV;
    float StopFrequencyW;
    int WaveFormU;
    int WaveFormV;
    int WaveFormW;
    float AnglesUV;
    float AnglesUW;
    float AnglesVW;
    float StepTimeU;
    float StepTimeV;
    float StepTimeW;
}GradientData;

typedef struct ThroughTable
{
    int OutputMode;
    int StepNo;
    int Phase; // 1/2/3/0 U/V/W/0
    int DropPhase;  //0 UVW /1 U /2 V /3 W /4 UV /5 UW /6 VW
    float StartVoltage;
    float StartFrequency;
    float StartTime;
    float Angles;
    float ZeroVoltage;
    float ZeroTime;
    float DropVoltage;
    float DropTime;
    float RecoveryVoltage;
    float RecoveryTime;
    float StopTime;
    int WaveFormU;
    int WaveFormV;
    int WaveFormW;
}ThroughData;

typedef struct HarmonicsTable
{
    int StepNo;
    int Times;
    float Percent;
    float Angles;
}HarmonicsData;

typedef struct ConfigInfo
{
    int Language;   //0 cn 1 en
    int Theme;
    int LinePhase;  //0line 1phase
    float OvercurrentLimit;
    float LineImpedance;
    bool LockCheck;
    int LockTime;
    QString LockPwd;
    QString SerialPort;
    bool CommCheck;
    int Baudrate;
    int Addr;
    int Protocol;
    QString Company;
    QString Address;
    QString Phone;
    QString Email;
    QString TCPIP;
    int TCPPort;
    bool NeutralMode;
    int Serialization;
    bool ThreePhase;
    bool ThreePhaseDiscrete;
    bool ThreePhaseUnbalance;
    bool SinglePhase;
    bool Harmonics;
    QString DeviceMode;
    QString Support;
    int AntiShock;  // 0 1 2
    float ShockMult1; //0.1-2.5
    float VoltageDrop1; //0 - 0.99
    float RetardTime;
    float ShockMult2; //0.1-2.5
    float VoltageDrop2; //0 - 0.99
    float HoldTime;
    bool OCFold;
    int GeneralStep;
    int GeneralOutputMode;
    int StepLadderOutputMode;
    int StepOutputMode;
    int StepStartNo;
    int StepStopNo;
    int StepCycleTimes;
    int GradientOutputMode;
    int GradientStartNo;
    int GradientStopNo;
    int GradientCycleTimes;
    int ThroughStep;
    int ThroughOutputMode;
    int ThroughStartNo;
    int ThroughStopNo;
    int ThroughCycleTimes;
}ConfigData;

typedef struct TestCtrlInfo{
    int StepNo;
    int OutputMode;
    int StartNo;
    int StopNo;
    int CycleTimes;
} TestCtrl;

typedef struct LogInfo{
    int TestMode;
    int OutputMode;
    int OperationType;
    QString Time;
    float IGBT;
    float Transformer;
    int FanSpeed;
}LogData;

union CanDataType{
    //常规
    struct{
        int M1_nVoltageLevel;
        int M1_nWaveForm1;
        int M1_nWaveForm2;
        int M1_nWaveForm3;
        int M1_nEnble1;
        int M1_nEnble2;
        int M1_nEnble3;
        int M1_nIdle1;
        float M1_fVoltage1;
        float M1_fVoltage2;
        float M1_fVoltage3;
        float M1_fFrequency1;
        float M1_fFrequency2;
        float M1_fFrequency3;
        float M1_fAngles1;
        float M1_fAngles2;
        float M1_fAngles3;
        float M1_fStartTime1;
        float M1_fStartTime2;
        float M1_fStartTime3;
        float M1_fIdle1;
        float M1_fIdle2;
        float M1_fIdle3;
        float M1_fIdle4;
        float M1_fIdle5;
        float M1_fIdle6;
    };
    //阶梯
    struct{
        int M2_nWaveForm1;
        int M2_nWaveForm2;
        int M2_nWaveForm3;
        int M2_nStepCount1;
        int M2_nStepCount2;
        int M2_nStepCount3;
        int M2_nIdle1;
        int M2_nIdle2;
        float M2_fStartVoltage1;
        float M2_fStartVoltage2;
        float M2_fStartVoltage3;
        float M2_fStepVoltage1;
        float M2_fStepVoltage2;
        float M2_fStepVoltage3;
        float M2_fStartFrequency1;
        float M2_fStartFrequency2;
        float M2_fStartFrequency3;
        float M2_fStepFrequency1;
        float M2_fStepFrequency2;
        float M2_fStepFrequency3;
        float M2_fAngles1;
        float M2_fAngles2;
        float M2_fAngles3;
        float M2_fTime1;
        float M2_fTime2;
        float M2_fTime3;
    };
    //步阶
    struct{
        int M3_nWaveForm1;
        int M3_nWaveForm2;
        int M3_nWaveForm3;
        int M3_nCycle1;
        int M3_nIdle1;
        int M3_nIdle2;
        int M3_nIdle3;
        int M3_nIdle4;
        float M3_fVoltage1;
        float M3_fVoltage2;
        float M3_fVoltage3;
        float M3_fFrequency1;
        float M3_fFrequency2;
        float M3_fFrequency3;
        float M3_fAngles1;
        float M3_fAngles2;
        float M3_fAngles3;
        float M3_fTime1;
        float M3_fTime2;
        float M3_fTime3;
        float M3_fIdle1;
        float M3_fIdle2;
        float M3_fIdle3;
        float M3_fIdle4;
        float M3_fIdle5;
        float M3_fIdle6;
    };
    //渐变
    struct{
        int M4_nWaveForm1;
        int M4_nWaveForm2;
        int M4_nWaveForm3;
        int M4_nCycle1;
        int M4_nIdle1;
        int M4_nIdle2;
        int M4_nIdle3;
        int M4_nIdle4;
        float M4_fStartVoltage1;
        float M4_fStartVoltage2;
        float M4_fStartVoltage3;
        float M4_fStopVoltage1;
        float M4_fStopVoltage2;
        float M4_fStopVoltage3;
        float M4_fStartFrequency1;
        float M4_fStartFrequency2;
        float M4_fStartFrequency3;
        float M4_fStopFrequency1;
        float M4_fStopFrequency2;
        float M4_fStopFrequency3;
        float M4_fAngles1;
        float M4_fAngles2;
        float M4_fAngles3;
        float M4_fTime1;
        float M4_fTime2;
        float M4_fTime3;
    };
    //低压穿越
    struct{
        int M5_nWaveForm1;
        int M5_nWaveForm2;
        int M5_nWaveForm3;
        int M5_nDropPhase;
        int M5_nCycle1;
        int M5_nIdle1;
        int M5_nIdle2;
        int M5_nIdle3;
        float M5_fStartVoltage;
        float M5_fStartFrequency;
        float M5_fStartTime;
        float M5_fAngles;
        float M5_fZeroVoltage;
        float M5_fZeroTime;
        float M5_fDropVoltage;
        float M5_fDropTime;
        float M5_fRecoveryVoltage;
        float M5_fRecoveryTime;
        float M5_fStopTime;
        float M5_fIdle1;
        float M5_fIdle2;
        float M5_fIdle3;
        float M5_fIdle4;
        float M5_fIdle5;
        float M5_fIdle6;
        float M5_fIdle7;
    };
    //系统设置
    struct{
        int M6_nPhase;  //  线电压
        int M6_nOCFold;  //OC FOLD
        int M6_nAntiShock;  // 抗冲击策略
        int M6_nIdle1;
        int M6_nIdle2;
        int M6_nIdle3;
        int M6_nIdle4;
        int M6_nIdle5;
        float M6_fOvercurrentLimit; //过流设置
        float M6_fLineImpedance;    //线路阻抗
        float M6_fShockMult;        //冲击倍数
        float M6_fVoltageDrop;           //降压百分百
        float M6_fRetardTime;      //缓升 保持时间
        float M6_fIdle1;
        float M6_fIdle2;
        float M6_fIdle3;
        float M6_fIdle4;
        float M6_fIdle5;
        float M6_fIdle6;
        float M6_fIdle7;
        float M6_fIdle8;
        float M6_fIdle9;
        float M6_fIdle10;
        float M6_fIdle11;
        float M6_fIdle12;
        float M6_fIdle13;
    };
    struct{
        int nData[8];
        float fData[18];
    };
};

typedef struct HarmonicsGroup
{
    float Percent[39];
    float Angles[39];
}HarmonicsGroupData;

typedef struct CanSend{
    int Cmd;
    int TestMode;
    int OutputMode;
    int Group;
    QList<CanDataType> TestData;
    QList<HarmonicsGroupData> AllHarmonics;
}CanSendData;

union PrintData{
    struct{
        unsigned char status;
        unsigned char step1;
        unsigned char step2;
        unsigned char step3;
        unsigned int fanSpeed;
        float stepTime1;
        float stepTime2;
        float stepTime3;
        float voltage1;
        float voltage2;
        float voltage3;
        float current1;
        float current2;
        float current3;
        float power1;
        float power2;
        float power3;
        float power4;
        float apparentPower1;
        float apparentPower2;
        float apparentPower3;
        float pf1;
        float pf2;
        float pf3;
        float cf1;
        float cf2;
        float cf3;
        float lpeak1;
        float lpeak2;
        float lpeak3;
        float lineVoltage1;
        float lineVoltage2;
        float lineVoltage3;
        float igbt;
        float transformer;
    };
    struct{
        unsigned int nData[2];
        float fData[30];
    };
};

QString getOutputModeName(const int p_language, const int p_outputmode);

QString getTestModeName(const int p_language, const int p_testmode);

#endif // COMMONTEST_H
