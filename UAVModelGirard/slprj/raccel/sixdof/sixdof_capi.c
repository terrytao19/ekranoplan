#include "rtw_capi.h"
#ifdef HOST_CAPI_BUILD
#include "sixdof_capi_host.h"
#define sizeof(s) ((size_t)(0xFFFF))
#undef rt_offsetof
#define rt_offsetof(s,el) ((uint16_T)(0xFFFF))
#define TARGET_CONST
#define TARGET_STRING(s) (s)
#ifndef SS_UINT64
#define SS_UINT64 19
#endif
#ifndef SS_INT64
#define SS_INT64 20
#endif
#else
#include "builtin_typeid_types.h"
#include "sixdof.h"
#include "sixdof_capi.h"
#include "sixdof_private.h"
#ifdef LIGHT_WEIGHT_CAPI
#define TARGET_CONST
#define TARGET_STRING(s)               ((NULL))
#else
#define TARGET_CONST                   const
#define TARGET_STRING(s)               (s)
#endif
#endif
static const rtwCAPI_Signals rtBlockSignals [ ] = { { 0 , 6 , TARGET_STRING (
"sixdof/Waypoint Follower" ) , TARGET_STRING ( "" ) , 2 , 0 , 0 , 0 , 0 } , {
1 , 0 , TARGET_STRING ( "sixdof/A//C/Fcn1" ) , TARGET_STRING ( "" ) , 0 , 0 ,
0 , 0 , 0 } , { 2 , 0 , TARGET_STRING ( "sixdof/A//C/Fcn2" ) , TARGET_STRING
( "" ) , 0 , 0 , 0 , 0 , 0 } , { 3 , 0 , TARGET_STRING ( "sixdof/A//C/R2D1" )
, TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 4 , 0 , TARGET_STRING (
"sixdof/A//C/R2D2" ) , TARGET_STRING ( "" ) , 0 , 0 , 1 , 0 , 0 } , { 5 , 0 ,
TARGET_STRING ( "sixdof/A//C/R2D3" ) , TARGET_STRING ( "" ) , 0 , 0 , 1 , 0 ,
0 } , { 6 , 0 , TARGET_STRING ( "sixdof/Airspeed Controller/Subtract4" ) ,
TARGET_STRING ( "airspeed_error" ) , 0 , 0 , 0 , 0 , 0 } , { 7 , 0 ,
TARGET_STRING ( "sixdof/Altitude Controller/Subtract" ) , TARGET_STRING (
"altitude_error" ) , 0 , 0 , 0 , 0 , 0 } , { 8 , 0 , TARGET_STRING (
"sixdof/Altitude Controller/Subtract1" ) , TARGET_STRING ( "pitch_error" ) ,
0 , 0 , 0 , 0 , 0 } , { 9 , 3 , TARGET_STRING (
"sixdof/Obstacles/find_new_yaw" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0
} , { 10 , 0 , TARGET_STRING (
"sixdof/Obstacles/find_new_yaw/is_active_c1_sixdof" ) , TARGET_STRING (
"is_active_c1_sixdof" ) , 0 , 1 , 0 , 0 , 0 } , { 11 , 0 , TARGET_STRING (
"sixdof/Obstacles/Switch" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , {
12 , 0 , TARGET_STRING ( "sixdof/Yaw Controller/Subtract2" ) , TARGET_STRING
( "yaw_error" ) , 0 , 0 , 0 , 0 , 0 } , { 13 , 0 , TARGET_STRING (
"sixdof/Yaw Controller/Subtract3" ) , TARGET_STRING ( "roll_error" ) , 0 , 0
, 0 , 0 , 0 } , { 14 , 0 , TARGET_STRING (
"sixdof/A//C/6DoF EoM/Z-positive is down" ) , TARGET_STRING ( "" ) , 0 , 0 ,
1 , 0 , 0 } , { 15 , 0 , TARGET_STRING ( "sixdof/A//C/6DoF EoM/phi theta psi"
) , TARGET_STRING ( "" ) , 0 , 0 , 1 , 0 , 0 } , { 16 , 0 , TARGET_STRING (
"sixdof/A//C/6DoF EoM/ub vb wb" ) , TARGET_STRING ( "" ) , 0 , 0 , 1 , 0 , 0
} , { 17 , 0 , TARGET_STRING ( "sixdof/A//C/6DoF EoM/xe ye ze" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 1 , 0 , 0 } , { 18 , 0 , TARGET_STRING (
"sixdof/A//C/6DoF EoM/Product" ) , TARGET_STRING ( "" ) , 0 , 0 , 1 , 0 , 0 }
, { 19 , 0 , TARGET_STRING ( "sixdof/A//C/Engine model/Constant4" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 20 , 0 , TARGET_STRING (
"sixdof/A//C/Engine model/Static Thrust (lbs)" ) , TARGET_STRING ( "" ) , 0 ,
0 , 0 , 0 , 2 } , { 21 , 0 , TARGET_STRING ( "sixdof/A//C/Engine model/kg2N"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 22 , 0 , TARGET_STRING (
"sixdof/A//C/Engine model/mps2fps" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 ,
0 } , { 23 , 0 , TARGET_STRING ( "sixdof/A//C/Engine model/Saturation1" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 24 , 0 , TARGET_STRING (
"sixdof/A//C/Forces & Moments/Reshape" ) , TARGET_STRING ( "" ) , 0 , 0 , 2 ,
0 , 0 } , { 25 , 0 , TARGET_STRING ( "sixdof/A//C/Output/R2D" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 1 , 0 , 0 } , { 26 , 4 , TARGET_STRING (
"sixdof/Obstacles/near_obstacle/is_obstacle_near" ) , TARGET_STRING ( "" ) ,
0 , 0 , 3 , 0 , 0 } , { 27 , 0 , TARGET_STRING (
"sixdof/Obstacles/near_obstacle/is_obstacle_near/is_active_c2_sixdof" ) ,
TARGET_STRING ( "is_active_c2_sixdof" ) , 0 , 1 , 0 , 0 , 0 } , { 28 , 0 ,
TARGET_STRING ( "sixdof/A//C/6DoF EoM/[V1,2,3,W1,2,3]/V*dot " ) ,
TARGET_STRING ( "" ) , 0 , 0 , 2 , 0 , 0 } , { 29 , 0 , TARGET_STRING (
"sixdof/A//C/Forces & Moments/AoA//Beta/R2D1" ) , TARGET_STRING ( "beta" ) ,
0 , 0 , 0 , 0 , 0 } , { 30 , 0 , TARGET_STRING (
"sixdof/A//C/Forces & Moments/AoA//Beta/R2D2" ) , TARGET_STRING ( "aoa" ) , 0
, 0 , 0 , 0 , 0 } , { 31 , 0 , TARGET_STRING (
"sixdof/A//C/Forces & Moments/AoA//Beta/Math Function" ) , TARGET_STRING ( ""
) , 0 , 0 , 0 , 0 , 0 } , { 32 , 0 , TARGET_STRING (
"sixdof/A//C/6DoF EoM/[V1,2,3,W1,2,3]/A Matrix/Matrix Concatenation2" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 4 , 0 , 1 } , { 33 , 0 , TARGET_STRING (
 "sixdof/Airspeed Controller/Discrete PID Controller4/I Gain/Internal Parameters/Integral Gain"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 2 } , { 34 , 0 , TARGET_STRING (
 "sixdof/Airspeed Controller/Discrete PID Controller4/Saturation/Enabled/Saturation"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 2 } , { 35 , 0 , TARGET_STRING (
 "sixdof/Altitude Controller/Discrete PID Controller/I Gain/Internal Parameters/Integral Gain"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 2 } , { 36 , 0 , TARGET_STRING (
"sixdof/Altitude Controller/Discrete PID Controller/Sum/Sum_PID/Sum" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 2 } , { 37 , 0 , TARGET_STRING (
 "sixdof/Altitude Controller/Discrete PID Controller1/I Gain/Internal Parameters/Integral Gain"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 2 } , { 38 , 0 , TARGET_STRING (
 "sixdof/Altitude Controller/Discrete PID Controller1/Saturation/Enabled/Saturation"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 2 } , { 39 , 0 , TARGET_STRING (
 "sixdof/Yaw Controller/Discrete PID Controller2/I Gain/Internal Parameters/Integral Gain"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 2 } , { 40 , 0 , TARGET_STRING (
 "sixdof/Yaw Controller/Discrete PID Controller2/N Gain/Internal Parameters/Filter Coefficient"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 2 } , { 41 , 0 , TARGET_STRING (
"sixdof/Yaw Controller/Discrete PID Controller2/Sum/Sum_PID/Sum" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 2 } , { 42 , 0 , TARGET_STRING (
 "sixdof/Yaw Controller/Discrete PID Controller3/I Gain/Internal Parameters/Integral Gain"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 2 } , { 43 , 0 , TARGET_STRING (
 "sixdof/Yaw Controller/Discrete PID Controller3/N Gain/Internal Parameters/Filter Coefficient"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 2 } , { 44 , 0 , TARGET_STRING (
"sixdof/Yaw Controller/Discrete PID Controller3/Saturation/Enabled/Saturation"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 2 } , { 45 , 0 , TARGET_STRING (
 "sixdof/A//C/Forces & Moments/Body Frame F & M/Wind frame F& M/Lateral Channel/CY/Gain2"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 46 , 0 , TARGET_STRING (
 "sixdof/A//C/Forces & Moments/Body Frame F & M/Wind frame F& M/Lateral Channel/Cl/Gain1"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 47 , 0 , TARGET_STRING (
 "sixdof/A//C/Forces & Moments/Body Frame F & M/Wind frame F& M/Lateral Channel/Cl/Gain3"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 2 } , { 48 , 0 , TARGET_STRING (
 "sixdof/A//C/Forces & Moments/Body Frame F & M/Wind frame F& M/Lateral Channel/Cn/Gain1"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 49 , 0 , TARGET_STRING (
 "sixdof/A//C/Forces & Moments/Body Frame F & M/Wind frame F& M/Lateral Channel/Cn/Gain3"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 2 } , { 50 , 0 , TARGET_STRING (
 "sixdof/A//C/Forces & Moments/Body Frame F & M/Wind frame F& M/Longitudinal Channel/CL/Gain1"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 2 } , { 51 , 0 , TARGET_STRING (
 "sixdof/A//C/Forces & Moments/Body Frame F & M/Wind frame F& M/Longitudinal Channel/CL/Gain3"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 52 , 1 , TARGET_STRING (
 "sixdof/A//C/Forces & Moments/Body Frame F & M/Wind frame F& M/Longitudinal Channel/CL/Add1"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 53 , 0 , TARGET_STRING (
 "sixdof/A//C/Forces & Moments/Body Frame F & M/Wind frame F& M/Longitudinal Channel/CL/Subtract"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 54 , 0 , TARGET_STRING (
 "sixdof/A//C/Forces & Moments/Body Frame F & M/Wind frame F& M/Longitudinal Channel/CL/Sum"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 55 , 0 , TARGET_STRING (
 "sixdof/A//C/Forces & Moments/Body Frame F & M/Wind frame F& M/Longitudinal Channel/Cm/Gain1"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 2 } , { 56 , 0 , TARGET_STRING (
 "sixdof/A//C/Forces & Moments/Body Frame F & M/Wind frame F& M/Longitudinal Channel/Cm/Gain3"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 57 , 0 , TARGET_STRING (
 "sixdof/Airspeed Controller/Discrete PID Controller4/Filter/Differentiator/Tsamp/Internal Ts/Tsamp"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 2 } , { 58 , 0 , TARGET_STRING (
 "sixdof/Altitude Controller/Discrete PID Controller/Filter/Differentiator/Tsamp/Internal Ts/Tsamp"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 2 } , { 59 , 0 , TARGET_STRING (
 "sixdof/Altitude Controller/Discrete PID Controller1/Filter/Differentiator/Tsamp/Internal Ts/Tsamp"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 2 } , { 60 , 0 , TARGET_STRING (
 "sixdof/A//C/Forces & Moments/Body Frame F & M/Wind frame F& M/Lateral Channel/Cl/roll factors/Slider Gain/Slider Gain"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 61 , 0 , TARGET_STRING (
 "sixdof/A//C/Forces & Moments/Body Frame F & M/Wind frame F& M/Lateral Channel/Cl/roll factors/Slider Gain1/Slider Gain"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 62 , 0 , TARGET_STRING (
 "sixdof/A//C/Forces & Moments/Body Frame F & M/Wind frame F& M/Lateral Channel/Cn/yaw factors/Slider Gain/Slider Gain"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 63 , 0 , TARGET_STRING (
 "sixdof/A//C/Forces & Moments/Body Frame F & M/Wind frame F& M/Lateral Channel/Cn/yaw factors/Slider Gain1/Slider Gain"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 64 , 0 , TARGET_STRING (
 "sixdof/A//C/Forces & Moments/Body Frame F & M/Wind frame F& M/Longitudinal Channel/Cm/Lif due to pitch rate/Slider Gain/Slider Gain"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 0 , 0 , ( NULL ) , ( NULL
) , 0 , 0 , 0 , 0 , 0 } } ; static const rtwCAPI_BlockParameters
rtBlockParameters [ ] = { { 65 , TARGET_STRING ( "sixdof/Constant" ) ,
TARGET_STRING ( "Value" ) , 0 , 5 , 0 } , { 66 , TARGET_STRING (
"sixdof/Constant1" ) , TARGET_STRING ( "Value" ) , 0 , 6 , 0 } , { 67 ,
TARGET_STRING ( "sixdof/Constant2" ) , TARGET_STRING ( "Value" ) , 0 , 0 , 0
} , { 68 , TARGET_STRING ( "sixdof/Constant3" ) , TARGET_STRING ( "Value" ) ,
0 , 7 , 0 } , { 69 , TARGET_STRING ( "sixdof/airpseed_desired" ) ,
TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 70 , TARGET_STRING (
"sixdof/h_desired" ) , TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 71 ,
TARGET_STRING ( "sixdof/A//C/ no wind" ) , TARGET_STRING ( "Value" ) , 0 , 1
, 0 } , { 72 , TARGET_STRING ( "sixdof/A//C/R2D1" ) , TARGET_STRING ( "Gain"
) , 0 , 0 , 0 } , { 73 , TARGET_STRING ( "sixdof/A//C/R2D2" ) , TARGET_STRING
( "Gain" ) , 0 , 0 , 0 } , { 74 , TARGET_STRING ( "sixdof/A//C/R2D3" ) ,
TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 75 , TARGET_STRING (
"sixdof/A//C/Manual Switch1" ) , TARGET_STRING ( "CurrentSetting" ) , 1 , 0 ,
0 } , { 76 , TARGET_STRING (
"sixdof/Airspeed Controller/Discrete PID Controller4" ) , TARGET_STRING ( "P"
) , 0 , 0 , 0 } , { 77 , TARGET_STRING (
"sixdof/Airspeed Controller/Discrete PID Controller4" ) , TARGET_STRING ( "I"
) , 0 , 0 , 0 } , { 78 , TARGET_STRING (
"sixdof/Airspeed Controller/Discrete PID Controller4" ) , TARGET_STRING ( "D"
) , 0 , 0 , 0 } , { 79 , TARGET_STRING (
"sixdof/Airspeed Controller/Discrete PID Controller4" ) , TARGET_STRING (
"InitialConditionForIntegrator" ) , 0 , 0 , 0 } , { 80 , TARGET_STRING (
"sixdof/Airspeed Controller/Discrete PID Controller4" ) , TARGET_STRING (
"DifferentiatorICPrevScaledInput" ) , 0 , 0 , 0 } , { 81 , TARGET_STRING (
"sixdof/Airspeed Controller/Discrete PID Controller4" ) , TARGET_STRING (
"UpperSaturationLimit" ) , 0 , 0 , 0 } , { 82 , TARGET_STRING (
"sixdof/Airspeed Controller/Discrete PID Controller4" ) , TARGET_STRING (
"LowerSaturationLimit" ) , 0 , 0 , 0 } , { 83 , TARGET_STRING (
"sixdof/Altitude Controller/Discrete PID Controller" ) , TARGET_STRING ( "P"
) , 0 , 0 , 0 } , { 84 , TARGET_STRING (
"sixdof/Altitude Controller/Discrete PID Controller" ) , TARGET_STRING ( "I"
) , 0 , 0 , 0 } , { 85 , TARGET_STRING (
"sixdof/Altitude Controller/Discrete PID Controller" ) , TARGET_STRING ( "D"
) , 0 , 0 , 0 } , { 86 , TARGET_STRING (
"sixdof/Altitude Controller/Discrete PID Controller" ) , TARGET_STRING (
"InitialConditionForIntegrator" ) , 0 , 0 , 0 } , { 87 , TARGET_STRING (
"sixdof/Altitude Controller/Discrete PID Controller" ) , TARGET_STRING (
"DifferentiatorICPrevScaledInput" ) , 0 , 0 , 0 } , { 88 , TARGET_STRING (
"sixdof/Altitude Controller/Discrete PID Controller1" ) , TARGET_STRING ( "P"
) , 0 , 0 , 0 } , { 89 , TARGET_STRING (
"sixdof/Altitude Controller/Discrete PID Controller1" ) , TARGET_STRING ( "I"
) , 0 , 0 , 0 } , { 90 , TARGET_STRING (
"sixdof/Altitude Controller/Discrete PID Controller1" ) , TARGET_STRING ( "D"
) , 0 , 0 , 0 } , { 91 , TARGET_STRING (
"sixdof/Altitude Controller/Discrete PID Controller1" ) , TARGET_STRING (
"InitialConditionForIntegrator" ) , 0 , 0 , 0 } , { 92 , TARGET_STRING (
"sixdof/Altitude Controller/Discrete PID Controller1" ) , TARGET_STRING (
"DifferentiatorICPrevScaledInput" ) , 0 , 0 , 0 } , { 93 , TARGET_STRING (
"sixdof/Altitude Controller/Discrete PID Controller1" ) , TARGET_STRING (
"UpperSaturationLimit" ) , 0 , 0 , 0 } , { 94 , TARGET_STRING (
"sixdof/Altitude Controller/Discrete PID Controller1" ) , TARGET_STRING (
"LowerSaturationLimit" ) , 0 , 0 , 0 } , { 95 , TARGET_STRING (
"sixdof/Obstacles/Switch" ) , TARGET_STRING ( "Threshold" ) , 0 , 0 , 0 } , {
96 , TARGET_STRING ( "sixdof/Rotation Angles to Quaternions/1//2" ) ,
TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 97 , TARGET_STRING (
"sixdof/Yaw Controller/Discrete PID Controller2" ) , TARGET_STRING ( "P" ) ,
0 , 0 , 0 } , { 98 , TARGET_STRING (
"sixdof/Yaw Controller/Discrete PID Controller2" ) , TARGET_STRING ( "I" ) ,
0 , 0 , 0 } , { 99 , TARGET_STRING (
"sixdof/Yaw Controller/Discrete PID Controller2" ) , TARGET_STRING ( "D" ) ,
0 , 0 , 0 } , { 100 , TARGET_STRING (
"sixdof/Yaw Controller/Discrete PID Controller2" ) , TARGET_STRING ( "N" ) ,
0 , 0 , 0 } , { 101 , TARGET_STRING (
"sixdof/Yaw Controller/Discrete PID Controller2" ) , TARGET_STRING (
"InitialConditionForIntegrator" ) , 0 , 0 , 0 } , { 102 , TARGET_STRING (
"sixdof/Yaw Controller/Discrete PID Controller2" ) , TARGET_STRING (
"InitialConditionForFilter" ) , 0 , 0 , 0 } , { 103 , TARGET_STRING (
"sixdof/Yaw Controller/Discrete PID Controller3" ) , TARGET_STRING ( "P" ) ,
0 , 0 , 0 } , { 104 , TARGET_STRING (
"sixdof/Yaw Controller/Discrete PID Controller3" ) , TARGET_STRING ( "I" ) ,
0 , 0 , 0 } , { 105 , TARGET_STRING (
"sixdof/Yaw Controller/Discrete PID Controller3" ) , TARGET_STRING ( "D" ) ,
0 , 0 , 0 } , { 106 , TARGET_STRING (
"sixdof/Yaw Controller/Discrete PID Controller3" ) , TARGET_STRING ( "N" ) ,
0 , 0 , 0 } , { 107 , TARGET_STRING (
"sixdof/Yaw Controller/Discrete PID Controller3" ) , TARGET_STRING (
"InitialConditionForIntegrator" ) , 0 , 0 , 0 } , { 108 , TARGET_STRING (
"sixdof/Yaw Controller/Discrete PID Controller3" ) , TARGET_STRING (
"InitialConditionForFilter" ) , 0 , 0 , 0 } , { 109 , TARGET_STRING (
"sixdof/Yaw Controller/Discrete PID Controller3" ) , TARGET_STRING (
"UpperSaturationLimit" ) , 0 , 0 , 0 } , { 110 , TARGET_STRING (
"sixdof/Yaw Controller/Discrete PID Controller3" ) , TARGET_STRING (
"LowerSaturationLimit" ) , 0 , 0 , 0 } , { 111 , TARGET_STRING (
"sixdof/A//C/6DoF EoM/Z-positive is down" ) , TARGET_STRING ( "Gain" ) , 0 ,
8 , 0 } , { 112 , TARGET_STRING ( "sixdof/A//C/6DoF EoM/pqr" ) ,
TARGET_STRING ( "InitialCondition" ) , 0 , 1 , 0 } , { 113 , TARGET_STRING (
"sixdof/A//C/6DoF EoM/ub vb wb" ) , TARGET_STRING ( "InitialCondition" ) , 0
, 1 , 0 } , { 114 , TARGET_STRING ( "sixdof/A//C/Engine model/Constant4" ) ,
TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 115 , TARGET_STRING (
"sixdof/A//C/Engine model/Throttle2RPM" ) , TARGET_STRING ( "Gain" ) , 0 , 0
, 0 } , { 116 , TARGET_STRING ( "sixdof/A//C/Engine model/lbs2kg" ) ,
TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 117 , TARGET_STRING (
"sixdof/A//C/Engine model/mps2fps" ) , TARGET_STRING ( "Gain" ) , 0 , 0 , 0 }
, { 118 , TARGET_STRING ( "sixdof/A//C/Engine model/Saturation" ) ,
TARGET_STRING ( "UpperLimit" ) , 0 , 0 , 0 } , { 119 , TARGET_STRING (
"sixdof/A//C/Engine model/Saturation" ) , TARGET_STRING ( "LowerLimit" ) , 0
, 0 , 0 } , { 120 , TARGET_STRING ( "sixdof/A//C/Engine model/Saturation1" )
, TARGET_STRING ( "UpperLimit" ) , 0 , 0 , 0 } , { 121 , TARGET_STRING (
"sixdof/A//C/Engine model/Saturation1" ) , TARGET_STRING ( "LowerLimit" ) , 0
, 0 , 0 } , { 122 , TARGET_STRING (
"sixdof/A//C/Forces & Moments/Weight matrix" ) , TARGET_STRING ( "Value" ) ,
0 , 9 , 0 } , { 123 , TARGET_STRING ( "sixdof/A//C/Output/R2D" ) ,
TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 124 , TARGET_STRING (
"sixdof/Obstacles/near_obstacle/Constant" ) , TARGET_STRING ( "Value" ) , 0 ,
0 , 0 } , { 125 , TARGET_STRING (
"sixdof/A//C/Forces & Moments/AoA//Beta/Constant" ) , TARGET_STRING ( "Value"
) , 0 , 0 , 0 } , { 126 , TARGET_STRING (
"sixdof/A//C/Forces & Moments/AoA//Beta/R2D1" ) , TARGET_STRING ( "Gain" ) ,
0 , 0 , 0 } , { 127 , TARGET_STRING (
"sixdof/A//C/Forces & Moments/AoA//Beta/R2D2" ) , TARGET_STRING ( "Gain" ) ,
0 , 0 , 0 } , { 128 , TARGET_STRING (
"sixdof/A//C/ISA Atmosphere & Winds/ISA/Limit  altitude" ) , TARGET_STRING (
"LowerLimit" ) , 0 , 0 , 0 } , { 129 , TARGET_STRING (
"sixdof/A//C/ISA Atmosphere & Winds/Wind model/Matrix Gain6" ) ,
TARGET_STRING ( "Gain" ) , 0 , 8 , 0 } , { 130 , TARGET_STRING (
"sixdof/A//C/6DoF EoM/[V1,2,3,W1,2,3]/A Matrix/Constant1" ) , TARGET_STRING (
"Value" ) , 0 , 8 , 0 } , { 131 , TARGET_STRING (
"sixdof/A//C/6DoF EoM/[V1,2,3,W1,2,3]/A Matrix/Constant4" ) , TARGET_STRING (
"Value" ) , 0 , 0 , 0 } , { 132 , TARGET_STRING (
"sixdof/A//C/6DoF EoM/[V1,2,3,W1,2,3]/Sigma/Gain" ) , TARGET_STRING ( "Gain"
) , 0 , 8 , 0 } , { 133 , TARGET_STRING (
"sixdof/A//C/6DoF EoM/[V1,2,3,W1,2,3]/Sigma/Gain1" ) , TARGET_STRING ( "Gain"
) , 0 , 8 , 0 } , { 134 , TARGET_STRING (
"sixdof/A//C/6DoF EoM/[V1,2,3,W1,2,3]/Sigma/Gain2" ) , TARGET_STRING ( "Gain"
) , 0 , 8 , 0 } , { 135 , TARGET_STRING (
"sixdof/A//C/6DoF EoM/[V1,2,3,W1,2,3]/Sigma/Gain3" ) , TARGET_STRING ( "Gain"
) , 0 , 0 , 0 } , { 136 , TARGET_STRING (
"sixdof/A//C/Forces & Moments/Body Frame F & M/Transfer to body frame/D2R" )
, TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 137 , TARGET_STRING (
"sixdof/A//C/Forces & Moments/Body Frame F & M/Wind frame F& M/Deg2Rad" ) ,
TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 138 , TARGET_STRING (
"sixdof/A//C/Forces & Moments/Body Frame F & M/Wind frame F& M/Deg2Rad1" ) ,
TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 139 , TARGET_STRING (
"sixdof/A//C/Forces & Moments/Body Frame F & M/Wind frame F& M/Deg2Rad2" ) ,
TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 140 , TARGET_STRING (
"sixdof/A//C/Forces & Moments/Body Frame F & M/Wind frame F& M/Deg2Rad3" ) ,
TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 141 , TARGET_STRING (
"sixdof/A//C/Forces & Moments/Body Frame F & M/Wind frame F& M/Deg2Rad4" ) ,
TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 142 , TARGET_STRING (
"sixdof/A//C/Forces & Moments/Body Frame F & M/Wind frame F& M/Gain" ) ,
TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 143 , TARGET_STRING (
"sixdof/A//C/Forces & Moments/Body Frame F & M/Wind frame F& M/Gain1" ) ,
TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 144 , TARGET_STRING (
"sixdof/A//C/Forces & Moments/Body Frame F & M/Wind frame F& M/Gain2" ) ,
TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 145 , TARGET_STRING (
"sixdof/A//C/Forces & Moments/Body Frame F & M/Wind frame F& M/Gain3" ) ,
TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 146 , TARGET_STRING (
"sixdof/A//C/Forces & Moments/Body Frame F & M/Wind frame F& M/Gain4" ) ,
TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 147 , TARGET_STRING (
"sixdof/A//C/Forces & Moments/Body Frame F & M/Wind frame F& M/Gain5" ) ,
TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 148 , TARGET_STRING (
"sixdof/A//C/ISA Atmosphere & Winds/Wind model/GetWind/   " ) , TARGET_STRING
( "Gain" ) , 0 , 0 , 0 } , { 149 , TARGET_STRING (
"sixdof/A//C/ISA Atmosphere & Winds/Wind model/GetWind/   1" ) ,
TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 150 , TARGET_STRING (
"sixdof/A//C/ISA Atmosphere & Winds/Wind model/GetWind/   2" ) ,
TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 151 , TARGET_STRING (
"sixdof/A//C/ISA Atmosphere & Winds/Wind model/GetWind/WindX" ) ,
TARGET_STRING ( "InputValues" ) , 0 , 10 , 0 } , { 152 , TARGET_STRING (
"sixdof/A//C/ISA Atmosphere & Winds/Wind model/GetWind/WindX" ) ,
TARGET_STRING ( "Table" ) , 0 , 10 , 0 } , { 153 , TARGET_STRING (
"sixdof/A//C/ISA Atmosphere & Winds/Wind model/GetWind/WindY" ) ,
TARGET_STRING ( "InputValues" ) , 0 , 10 , 0 } , { 154 , TARGET_STRING (
"sixdof/A//C/ISA Atmosphere & Winds/Wind model/GetWind/WindY" ) ,
TARGET_STRING ( "Table" ) , 0 , 10 , 0 } , { 155 , TARGET_STRING (
"sixdof/A//C/ISA Atmosphere & Winds/Wind model/GetWind/WindZ" ) ,
TARGET_STRING ( "InputValues" ) , 0 , 10 , 0 } , { 156 , TARGET_STRING (
"sixdof/A//C/ISA Atmosphere & Winds/Wind model/GetWind/WindZ" ) ,
TARGET_STRING ( "Table" ) , 0 , 10 , 0 } , { 157 , TARGET_STRING (
 "sixdof/Airspeed Controller/Discrete PID Controller4/Integrator/Discrete/Integrator"
) , TARGET_STRING ( "gainval" ) , 0 , 0 , 0 } , { 158 , TARGET_STRING (
 "sixdof/Altitude Controller/Discrete PID Controller/Integrator/Discrete/Integrator"
) , TARGET_STRING ( "gainval" ) , 0 , 0 , 0 } , { 159 , TARGET_STRING (
 "sixdof/Altitude Controller/Discrete PID Controller1/Integrator/Discrete/Integrator"
) , TARGET_STRING ( "gainval" ) , 0 , 0 , 0 } , { 160 , TARGET_STRING (
 "sixdof/Yaw Controller/Discrete PID Controller2/Filter/Disc. Forward Euler Filter/Filter"
) , TARGET_STRING ( "gainval" ) , 0 , 0 , 0 } , { 161 , TARGET_STRING (
"sixdof/Yaw Controller/Discrete PID Controller2/Integrator/Discrete/Integrator"
) , TARGET_STRING ( "gainval" ) , 0 , 0 , 0 } , { 162 , TARGET_STRING (
 "sixdof/Yaw Controller/Discrete PID Controller3/Filter/Disc. Forward Euler Filter/Filter"
) , TARGET_STRING ( "gainval" ) , 0 , 0 , 0 } , { 163 , TARGET_STRING (
"sixdof/Yaw Controller/Discrete PID Controller3/Integrator/Discrete/Integrator"
) , TARGET_STRING ( "gainval" ) , 0 , 0 , 0 } , { 164 , TARGET_STRING (
 "sixdof/A//C/Forces & Moments/Body Frame F & M/Wind frame F& M/Longitudinal Channel/Gain"
) , TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 165 , TARGET_STRING (
 "sixdof/A//C/Forces & Moments/Body Frame F & M/Wind frame F& M/Longitudinal Channel/Gain1"
) , TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 166 , TARGET_STRING (
 "sixdof/A//C/Forces & Moments/Body Frame F & M/Wind frame F& M/Lateral Channel/CY/Gain1"
) , TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 167 , TARGET_STRING (
 "sixdof/A//C/Forces & Moments/Body Frame F & M/Wind frame F& M/Lateral Channel/CY/Gain2"
) , TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 168 , TARGET_STRING (
 "sixdof/A//C/Forces & Moments/Body Frame F & M/Wind frame F& M/Lateral Channel/Cl/Gain1"
) , TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 169 , TARGET_STRING (
 "sixdof/A//C/Forces & Moments/Body Frame F & M/Wind frame F& M/Lateral Channel/Cl/Gain3"
) , TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 170 , TARGET_STRING (
 "sixdof/A//C/Forces & Moments/Body Frame F & M/Wind frame F& M/Lateral Channel/Cl/Gain4"
) , TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 171 , TARGET_STRING (
 "sixdof/A//C/Forces & Moments/Body Frame F & M/Wind frame F& M/Lateral Channel/Cn/Gain1"
) , TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 172 , TARGET_STRING (
 "sixdof/A//C/Forces & Moments/Body Frame F & M/Wind frame F& M/Lateral Channel/Cn/Gain3"
) , TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 173 , TARGET_STRING (
 "sixdof/A//C/Forces & Moments/Body Frame F & M/Wind frame F& M/Lateral Channel/Cn/Gain4"
) , TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 174 , TARGET_STRING (
 "sixdof/A//C/Forces & Moments/Body Frame F & M/Wind frame F& M/Longitudinal Channel/CL/Constant"
) , TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 175 , TARGET_STRING (
 "sixdof/A//C/Forces & Moments/Body Frame F & M/Wind frame F& M/Longitudinal Channel/CL/Constant1"
) , TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 176 , TARGET_STRING (
 "sixdof/A//C/Forces & Moments/Body Frame F & M/Wind frame F& M/Longitudinal Channel/CL/Gain1"
) , TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 177 , TARGET_STRING (
 "sixdof/A//C/Forces & Moments/Body Frame F & M/Wind frame F& M/Longitudinal Channel/CL/Gain3"
) , TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 178 , TARGET_STRING (
 "sixdof/A//C/Forces & Moments/Body Frame F & M/Wind frame F& M/Longitudinal Channel/CL/Gain4"
) , TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 179 , TARGET_STRING (
 "sixdof/A//C/Forces & Moments/Body Frame F & M/Wind frame F& M/Longitudinal Channel/CL/Switch"
) , TARGET_STRING ( "Threshold" ) , 0 , 0 , 0 } , { 180 , TARGET_STRING (
 "sixdof/A//C/Forces & Moments/Body Frame F & M/Wind frame F& M/Longitudinal Channel/Cm/Gain1"
) , TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 181 , TARGET_STRING (
 "sixdof/A//C/Forces & Moments/Body Frame F & M/Wind frame F& M/Longitudinal Channel/Cm/Gain3"
) , TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 182 , TARGET_STRING (
 "sixdof/A//C/Forces & Moments/Body Frame F & M/Wind frame F& M/Longitudinal Channel/Cm/Gain4"
) , TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 183 , TARGET_STRING (
 "sixdof/Airspeed Controller/Discrete PID Controller4/Filter/Differentiator/Tsamp/Internal Ts/Tsamp"
) , TARGET_STRING ( "WtEt" ) , 0 , 0 , 0 } , { 184 , TARGET_STRING (
 "sixdof/Altitude Controller/Discrete PID Controller/Filter/Differentiator/Tsamp/Internal Ts/Tsamp"
) , TARGET_STRING ( "WtEt" ) , 0 , 0 , 0 } , { 185 , TARGET_STRING (
 "sixdof/Altitude Controller/Discrete PID Controller1/Filter/Differentiator/Tsamp/Internal Ts/Tsamp"
) , TARGET_STRING ( "WtEt" ) , 0 , 0 , 0 } , { 186 , TARGET_STRING (
 "sixdof/A//C/Forces & Moments/Body Frame F & M/Wind frame F& M/Lateral Channel/Cl/roll factors/Slider Gain"
) , TARGET_STRING ( "gain" ) , 0 , 0 , 0 } , { 187 , TARGET_STRING (
 "sixdof/A//C/Forces & Moments/Body Frame F & M/Wind frame F& M/Lateral Channel/Cl/roll factors/Slider Gain1"
) , TARGET_STRING ( "gain" ) , 0 , 0 , 0 } , { 188 , TARGET_STRING (
 "sixdof/A//C/Forces & Moments/Body Frame F & M/Wind frame F& M/Lateral Channel/Cn/yaw factors/Slider Gain"
) , TARGET_STRING ( "gain" ) , 0 , 0 , 0 } , { 189 , TARGET_STRING (
 "sixdof/A//C/Forces & Moments/Body Frame F & M/Wind frame F& M/Lateral Channel/Cn/yaw factors/Slider Gain1"
) , TARGET_STRING ( "gain" ) , 0 , 0 , 0 } , { 190 , TARGET_STRING (
 "sixdof/A//C/Forces & Moments/Body Frame F & M/Wind frame F& M/Longitudinal Channel/Cm/Lif due to pitch rate/Slider Gain"
) , TARGET_STRING ( "gain" ) , 0 , 0 , 0 } , { 191 , TARGET_STRING (
 "sixdof/A//C/Forces & Moments/Body Frame F & M/Wind frame F& M/Lateral Channel/Cl/roll factors/roll rate fact/Cmq1"
) , TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 192 , TARGET_STRING (
 "sixdof/A//C/Forces & Moments/Body Frame F & M/Wind frame F& M/Lateral Channel/Cl/roll factors/yaw rate fact/Cmq1"
) , TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 193 , TARGET_STRING (
 "sixdof/A//C/Forces & Moments/Body Frame F & M/Wind frame F& M/Lateral Channel/Cn/yaw factors/roll rate fact/Cmq1"
) , TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 194 , TARGET_STRING (
 "sixdof/A//C/Forces & Moments/Body Frame F & M/Wind frame F& M/Lateral Channel/Cn/yaw factors/yaw rate fact/Cmq1"
) , TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 0 , ( NULL ) , ( NULL ) , 0 ,
0 , 0 } } ; static int_T rt_LoggedStateIdxList [ ] = { - 1 } ; static const
rtwCAPI_Signals rtRootInputs [ ] = { { 0 , 0 , ( NULL ) , ( NULL ) , 0 , 0 ,
0 , 0 , 0 } } ; static const rtwCAPI_Signals rtRootOutputs [ ] = { { 0 , 0 ,
( NULL ) , ( NULL ) , 0 , 0 , 0 , 0 , 0 } } ; static const
rtwCAPI_ModelParameters rtModelParameters [ ] = { { 195 , TARGET_STRING (
"Apolar" ) , 0 , 0 , 0 } , { 196 , TARGET_STRING ( "CD0" ) , 0 , 0 , 0 } , {
197 , TARGET_STRING ( "CL0" ) , 0 , 0 , 0 } , { 198 , TARGET_STRING ( "CLDe"
) , 0 , 0 , 0 } , { 199 , TARGET_STRING ( "CLa" ) , 0 , 0 , 0 } , { 200 ,
TARGET_STRING ( "CLa_dot" ) , 0 , 0 , 0 } , { 201 , TARGET_STRING ( "CLq" ) ,
0 , 0 , 0 } , { 202 , TARGET_STRING ( "CYDr" ) , 0 , 0 , 0 } , { 203 ,
TARGET_STRING ( "CYb" ) , 0 , 0 , 0 } , { 204 , TARGET_STRING ( "ClDa" ) , 0
, 0 , 0 } , { 205 , TARGET_STRING ( "ClDr" ) , 0 , 0 , 0 } , { 206 ,
TARGET_STRING ( "Clb" ) , 0 , 0 , 0 } , { 207 , TARGET_STRING ( "Clp" ) , 0 ,
0 , 0 } , { 208 , TARGET_STRING ( "Clr" ) , 0 , 0 , 0 } , { 209 ,
TARGET_STRING ( "Cm0" ) , 0 , 0 , 0 } , { 210 , TARGET_STRING ( "CmDe" ) , 0
, 0 , 0 } , { 211 , TARGET_STRING ( "Cma" ) , 0 , 0 , 0 } , { 212 ,
TARGET_STRING ( "Cma_dot" ) , 0 , 0 , 0 } , { 213 , TARGET_STRING ( "Cmq" ) ,
0 , 0 , 0 } , { 214 , TARGET_STRING ( "CnDa" ) , 0 , 0 , 0 } , { 215 ,
TARGET_STRING ( "CnDr" ) , 0 , 0 , 0 } , { 216 , TARGET_STRING ( "Cnb" ) , 0
, 0 , 0 } , { 217 , TARGET_STRING ( "Cnp" ) , 0 , 0 , 0 } , { 218 ,
TARGET_STRING ( "Cnr" ) , 0 , 0 , 0 } , { 219 , TARGET_STRING ( "Euler_0" ) ,
0 , 9 , 0 } , { 220 , TARGET_STRING ( "ISA_T0" ) , 0 , 0 , 0 } , { 221 ,
TARGET_STRING ( "ISA_g" ) , 0 , 0 , 0 } , { 222 , TARGET_STRING ( "ISA_hmax"
) , 0 , 0 , 0 } , { 223 , TARGET_STRING ( "ISA_lapse" ) , 0 , 0 , 0 } , { 224
, TARGET_STRING ( "ISA_rho0" ) , 0 , 0 , 0 } , { 225 , TARGET_STRING ( "Ixx"
) , 0 , 0 , 0 } , { 226 , TARGET_STRING ( "Iyy" ) , 0 , 0 , 0 } , { 227 ,
TARGET_STRING ( "Izz" ) , 0 , 0 , 0 } , { 228 , TARGET_STRING ( "Pos_0" ) , 0
, 1 , 0 } , { 229 , TARGET_STRING ( "chord" ) , 0 , 0 , 0 } , { 230 ,
TARGET_STRING ( "mass" ) , 0 , 0 , 0 } , { 231 , TARGET_STRING ( "span" ) , 0
, 0 , 0 } , { 0 , ( NULL ) , 0 , 0 , 0 } } ;
#ifndef HOST_CAPI_BUILD
static void * rtDataAddrMap [ ] = { & rtB . lokluenstr , & rtB . l0izt2oa2m ,
& rtB . jfnjrao1g3 , & rtB . cmwuafgi05 , & rtB . fwckhvycxa [ 0 ] , & rtB .
ej2atzfwl0 [ 0 ] , & rtB . eisyorlq2r , & rtB . m1c2gjrdhf , & rtB .
c2nosomft5 , & rtB . c04goqj2sf , & rtDW . ecfpev5hmr , & rtB . amv5xbxcgx ,
& rtB . ctr2i5cu0j , & rtB . agbvtgnrv4 , & rtB . k1afspykmn [ 0 ] , & rtB .
ffht1uab1p [ 0 ] , & rtB . av1jt30k31 [ 0 ] , & rtB . ewh2czgzt2 [ 0 ] , &
rtB . ldelskn1jo [ 0 ] , & rtB . ijvi5t5r0z , & rtB . h1saod1n1q , & rtB .
m5psfntta4 , & rtB . f4k3dw2w0v , & rtB . m3gvnxject , & rtB . lg5hpscltc [ 0
] , & rtB . lc5ruufnmk [ 0 ] , & rtB . jd2mqrgdxl [ 0 ] , & rtDW . lvfkgpske1
, & rtB . ddcf0ek4jw [ 0 ] , & rtB . mhbhj1bpzc , & rtB . ljudbp5sfm , & rtB
. j4csspowr5 , & rtB . o0ugrkeqpd [ 0 ] , & rtB . ckb3sq150e , & rtB .
ncckp5giye , & rtB . hrq2k5iwyr , & rtB . jlifrmbka3 , & rtB . knqqe5buxf , &
rtB . m30uwutjd5 , & rtB . pxzonjrd4i , & rtB . pvv2cmskei , & rtB .
gst3ni0ebl , & rtB . deddzxm4gc , & rtB . hjhp5kuoxj , & rtB . glpu5b5wth , &
rtB . i5zbjzuhhx , & rtB . kwxg3amuly , & rtB . hxc25hdudb , & rtB .
eej5dfdnuw , & rtB . aq2in4etwi , & rtB . ezi3wqgg1t , & rtB . ebpprftokq , &
rtB . jhen0kkdwf , & rtB . lda1u2jc0p , & rtB . es5qqkki5l , & rtB .
crwpdhv3lp , & rtB . b152zcpgbp , & rtB . m0diztvarb , & rtB . gyndz2ty42 , &
rtB . c4zgqksn3s , & rtB . b1n2m12ywt , & rtB . bx1plzk1jh , & rtB .
leydlmjwwh , & rtB . exx2dadn0g , & rtB . l0yxgnvu5h , & rtP .
Constant_Value_ibkcrpfjyo [ 0 ] , & rtP . Constant1_Value_a4soj351ll [ 0 ] ,
& rtP . Constant2_Value , & rtP . Constant3_Value [ 0 ] , & rtP .
airpseed_desired_Value , & rtP . h_desired_Value , & rtP . nowind_Value [ 0 ]
, & rtP . R2D1_Gain_g0cjd2kme4 , & rtP . R2D2_Gain_jrhz3pfqfv , & rtP .
R2D3_Gain , & rtP . ManualSwitch1_CurrentSetting , & rtP .
DiscretePIDController4_P , & rtP . DiscretePIDController4_I , & rtP .
DiscretePIDController4_D , & rtP .
DiscretePIDController4_InitialConditionForIntegrator , & rtP .
DiscretePIDController4_DifferentiatorICPrevScaledInput , & rtP .
DiscretePIDController4_UpperSaturationLimit , & rtP .
DiscretePIDController4_LowerSaturationLimit , & rtP . DiscretePIDController_P
, & rtP . DiscretePIDController_I , & rtP . DiscretePIDController_D , & rtP .
DiscretePIDController_InitialConditionForIntegrator , & rtP .
DiscretePIDController_DifferentiatorICPrevScaledInput , & rtP .
DiscretePIDController1_P , & rtP . DiscretePIDController1_I , & rtP .
DiscretePIDController1_D , & rtP .
DiscretePIDController1_InitialConditionForIntegrator , & rtP .
DiscretePIDController1_DifferentiatorICPrevScaledInput , & rtP .
DiscretePIDController1_UpperSaturationLimit , & rtP .
DiscretePIDController1_LowerSaturationLimit , & rtP . Switch_Threshold , &
rtP . u2_Gain , & rtP . DiscretePIDController2_P , & rtP .
DiscretePIDController2_I , & rtP . DiscretePIDController2_D , & rtP .
DiscretePIDController2_N , & rtP .
DiscretePIDController2_InitialConditionForIntegrator , & rtP .
DiscretePIDController2_InitialConditionForFilter , & rtP .
DiscretePIDController3_P , & rtP . DiscretePIDController3_I , & rtP .
DiscretePIDController3_D , & rtP . DiscretePIDController3_N , & rtP .
DiscretePIDController3_InitialConditionForIntegrator , & rtP .
DiscretePIDController3_InitialConditionForFilter , & rtP .
DiscretePIDController3_UpperSaturationLimit , & rtP .
DiscretePIDController3_LowerSaturationLimit , & rtP . Zpositiveisdown_Gain [
0 ] , & rtP . pqr_IC [ 0 ] , & rtP . ubvbwb_IC [ 0 ] , & rtP .
Constant4_Value_lvvzxuwh5z , & rtP . Throttle2RPM_Gain , & rtP . lbs2kg_Gain
, & rtP . mps2fps_Gain , & rtP . Saturation_UpperSat , & rtP .
Saturation_LowerSat , & rtP . Saturation1_UpperSat , & rtP .
Saturation1_LowerSat , & rtP . Weightmatrix_Value [ 0 ] , & rtP . R2D_Gain ,
& rtP . Constant_Value_d3cgtfumsg , & rtP . Constant_Value , & rtP .
R2D1_Gain , & rtP . R2D2_Gain , & rtP . Limitaltitude_LowerSat , & rtP .
MatrixGain6_Gain [ 0 ] , & rtP . Constant1_Value [ 0 ] , & rtP .
Constant4_Value , & rtP . Gain_Gain_a1wggbqhys [ 0 ] , & rtP .
Gain1_Gain_mlyplvcvro [ 0 ] , & rtP . Gain2_Gain_kp2d4nocmq [ 0 ] , & rtP .
Gain3_Gain_kf22pabip4 , & rtP . D2R_Gain , & rtP . Deg2Rad_Gain , & rtP .
Deg2Rad1_Gain , & rtP . Deg2Rad2_Gain , & rtP . Deg2Rad3_Gain , & rtP .
Deg2Rad4_Gain , & rtP . Gain_Gain_mqy02r1o31 , & rtP . Gain1_Gain_ftpoywohzv
, & rtP . Gain2_Gain , & rtP . Gain3_Gain_jhgwt4xcre , & rtP .
Gain4_Gain_ohs20inw3v , & rtP . Gain5_Gain , & rtP . _Gain , & rtP .
u_Gain_lth2troxad , & rtP . u_Gain , & rtP . WindX_XData [ 0 ] , & rtP .
WindX_YData [ 0 ] , & rtP . WindY_XData [ 0 ] , & rtP . WindY_YData [ 0 ] , &
rtP . WindZ_XData [ 0 ] , & rtP . WindZ_YData [ 0 ] , & rtP .
Integrator_gainval , & rtP . Integrator_gainval_gsc5ke3qa1 , & rtP .
Integrator_gainval_pgxpxjbdlc , & rtP . Filter_gainval , & rtP .
Integrator_gainval_fn0merchw3 , & rtP . Filter_gainval_elrzqrryfc , & rtP .
Integrator_gainval_kdbzsgvpvb , & rtP . Gain_Gain , & rtP .
Gain1_Gain_e2mkjz4tqt , & rtP . Gain1_Gain_nqisqcqfrw , & rtP .
Gain2_Gain_b4uvpqpdbd , & rtP . Gain1_Gain_nbhhfd3fwa , & rtP . Gain3_Gain ,
& rtP . Gain4_Gain_ljfjkw1syf , & rtP . Gain1_Gain_dd3z2ich2e , & rtP .
Gain3_Gain_gjw5qqxglj , & rtP . Gain4_Gain_n3uynydxab , & rtP .
Constant_Value_cqthaabju2 , & rtP . Constant1_Value_g5jniqvvpl , & rtP .
Gain1_Gain , & rtP . Gain3_Gain_jo4inzsfgw , & rtP . Gain4_Gain , & rtP .
Switch_Threshold_hwgs5rnbxi , & rtP . Gain1_Gain_dpix5mof3i , & rtP .
Gain3_Gain_fosanw5ymw , & rtP . Gain4_Gain_fd51wengpv , & rtP . Tsamp_WtEt ,
& rtP . Tsamp_WtEt_eenah0djpv , & rtP . Tsamp_WtEt_i0xopibhwa , & rtP .
SliderGain_gain , & rtP . SliderGain1_gain , & rtP .
SliderGain_gain_hyc34xasfz , & rtP . SliderGain1_gain_mv1hpouzrh , & rtP .
SliderGain_gain_bsd0ykrtc0 , & rtP . Cmq1_Value , & rtP .
Cmq1_Value_dqzexw0fvg , & rtP . Cmq1_Value_hei4fwlj0u , & rtP .
Cmq1_Value_acz4kovyrj , & rtP . Apolar , & rtP . CD0 , & rtP . CL0 , & rtP .
CLDe , & rtP . CLa , & rtP . CLa_dot , & rtP . CLq , & rtP . CYDr , & rtP .
CYb , & rtP . ClDa , & rtP . ClDr , & rtP . Clb , & rtP . Clp , & rtP . Clr ,
& rtP . Cm0 , & rtP . CmDe , & rtP . Cma , & rtP . Cma_dot , & rtP . Cmq , &
rtP . CnDa , & rtP . CnDr , & rtP . Cnb , & rtP . Cnp , & rtP . Cnr , & rtP .
Euler_0 [ 0 ] , & rtP . ISA_T0 , & rtP . ISA_g , & rtP . ISA_hmax , & rtP .
ISA_lapse , & rtP . ISA_rho0 , & rtP . Ixx , & rtP . Iyy , & rtP . Izz , &
rtP . Pos_0 [ 0 ] , & rtP . chord , & rtP . mass , & rtP . span , } ; static
int32_T * rtVarDimsAddrMap [ ] = { ( NULL ) } ;
#endif
static TARGET_CONST rtwCAPI_DataTypeMap rtDataTypeMap [ ] = { { "double" ,
"real_T" , 0 , 0 , sizeof ( real_T ) , ( uint8_T ) SS_DOUBLE , 0 , 0 , 0 } ,
{ "unsigned char" , "uint8_T" , 0 , 0 , sizeof ( uint8_T ) , ( uint8_T )
SS_UINT8 , 0 , 0 , 0 } } ;
#ifdef HOST_CAPI_BUILD
#undef sizeof
#endif
static TARGET_CONST rtwCAPI_ElementMap rtElementMap [ ] = { { ( NULL ) , 0 ,
0 , 0 , 0 } , } ; static const rtwCAPI_DimensionMap rtDimensionMap [ ] = { {
rtwCAPI_SCALAR , 0 , 2 , 0 } , { rtwCAPI_VECTOR , 2 , 2 , 0 } , {
rtwCAPI_MATRIX_COL_MAJOR , 4 , 2 , 0 } , { rtwCAPI_MATRIX_COL_MAJOR , 6 , 2 ,
0 } , { rtwCAPI_MATRIX_COL_MAJOR , 8 , 2 , 0 } , { rtwCAPI_VECTOR , 10 , 2 ,
0 } , { rtwCAPI_MATRIX_COL_MAJOR , 12 , 2 , 0 } , { rtwCAPI_MATRIX_COL_MAJOR
, 14 , 2 , 0 } , { rtwCAPI_MATRIX_COL_MAJOR , 16 , 2 , 0 } , { rtwCAPI_VECTOR
, 18 , 2 , 0 } , { rtwCAPI_VECTOR , 20 , 2 , 0 } } ; static const uint_T
rtDimensionArray [ ] = { 1 , 1 , 3 , 1 , 6 , 1 , 1 , 2 , 6 , 6 , 1 , 6 , 7 ,
3 , 6 , 2 , 3 , 3 , 1 , 3 , 3002 , 1 } ; static const real_T
rtcapiStoredFloats [ ] = { 0.0 , 0.01 } ; static const rtwCAPI_FixPtMap
rtFixPtMap [ ] = { { ( NULL ) , ( NULL ) , rtwCAPI_FIX_RESERVED , 0 , 0 , (
boolean_T ) 0 } , } ; static const rtwCAPI_SampleTimeMap rtSampleTimeMap [ ]
= { { ( const void * ) & rtcapiStoredFloats [ 0 ] , ( const void * ) &
rtcapiStoredFloats [ 0 ] , ( int8_T ) 0 , ( uint8_T ) 0 } , { ( NULL ) , (
NULL ) , 2 , 0 } , { ( const void * ) & rtcapiStoredFloats [ 1 ] , ( const
void * ) & rtcapiStoredFloats [ 0 ] , ( int8_T ) 1 , ( uint8_T ) 0 } } ;
static rtwCAPI_ModelMappingStaticInfo mmiStatic = { { rtBlockSignals , 65 ,
rtRootInputs , 0 , rtRootOutputs , 0 } , { rtBlockParameters , 130 ,
rtModelParameters , 37 } , { ( NULL ) , 0 } , { rtDataTypeMap ,
rtDimensionMap , rtFixPtMap , rtElementMap , rtSampleTimeMap ,
rtDimensionArray } , "float" , { 2329722005U , 3266266654U , 3273445918U ,
3218276492U } , ( NULL ) , 0 , ( boolean_T ) 0 , rt_LoggedStateIdxList } ;
const rtwCAPI_ModelMappingStaticInfo * sixdof_GetCAPIStaticMap ( void ) {
return & mmiStatic ; }
#ifndef HOST_CAPI_BUILD
void sixdof_InitializeDataMapInfo ( void ) { rtwCAPI_SetVersion ( ( *
rt_dataMapInfoPtr ) . mmi , 1 ) ; rtwCAPI_SetStaticMap ( ( *
rt_dataMapInfoPtr ) . mmi , & mmiStatic ) ; rtwCAPI_SetLoggingStaticMap ( ( *
rt_dataMapInfoPtr ) . mmi , ( NULL ) ) ; rtwCAPI_SetDataAddressMap ( ( *
rt_dataMapInfoPtr ) . mmi , rtDataAddrMap ) ; rtwCAPI_SetVarDimsAddressMap (
( * rt_dataMapInfoPtr ) . mmi , rtVarDimsAddrMap ) ;
rtwCAPI_SetInstanceLoggingInfo ( ( * rt_dataMapInfoPtr ) . mmi , ( NULL ) ) ;
rtwCAPI_SetChildMMIArray ( ( * rt_dataMapInfoPtr ) . mmi , ( NULL ) ) ;
rtwCAPI_SetChildMMIArrayLen ( ( * rt_dataMapInfoPtr ) . mmi , 0 ) ; }
#else
#ifdef __cplusplus
extern "C" {
#endif
void sixdof_host_InitializeDataMapInfo ( sixdof_host_DataMapInfo_T * dataMap
, const char * path ) { rtwCAPI_SetVersion ( dataMap -> mmi , 1 ) ;
rtwCAPI_SetStaticMap ( dataMap -> mmi , & mmiStatic ) ;
rtwCAPI_SetDataAddressMap ( dataMap -> mmi , ( NULL ) ) ;
rtwCAPI_SetVarDimsAddressMap ( dataMap -> mmi , ( NULL ) ) ; rtwCAPI_SetPath
( dataMap -> mmi , path ) ; rtwCAPI_SetFullPath ( dataMap -> mmi , ( NULL ) )
; rtwCAPI_SetChildMMIArray ( dataMap -> mmi , ( NULL ) ) ;
rtwCAPI_SetChildMMIArrayLen ( dataMap -> mmi , 0 ) ; }
#ifdef __cplusplus
}
#endif
#endif
