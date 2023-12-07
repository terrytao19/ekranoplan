#ifndef RTW_HEADER_sixdof_h_
#define RTW_HEADER_sixdof_h_
#ifndef sixdof_COMMON_INCLUDES_
#define sixdof_COMMON_INCLUDES_
#include <stdlib.h>
#include <stddef.h>
#include "sl_AsyncioQueue/AsyncioQueueCAPI.h"
#include "sl_fileio_rtw.h"
#include "simtarget/slSimTgtSlFileioRTW.h"
#include "rtwtypes.h"
#include "sigstream_rtw.h"
#include "simtarget/slSimTgtSigstreamRTW.h"
#include "simtarget/slSimTgtSlioCoreRTW.h"
#include "simtarget/slSimTgtSlioClientsRTW.h"
#include "simtarget/slSimTgtSlioSdiRTW.h"
#include "simstruc.h"
#include "fixedpoint.h"
#include "raccel.h"
#include "slsv_diagnostic_codegen_c_api.h"
#include "rt_logging_simtarget.h"
#include "dt_info.h"
#include "ext_work.h"
#endif
#include "sixdof_types.h"
#include "rt_nonfinite.h"
#include "rtGetNaN.h"
#include "rtw_modelmap_simtarget.h"
#include "rt_defines.h"
#include <string.h>
#include "zero_crossing_types.h"
#define MODEL_NAME sixdof
#define NSAMPLE_TIMES (3) 
#define NINPUTS (0)       
#define NOUTPUTS (0)     
#define NBLOCKIO (64) 
#define NUM_ZC_EVENTS (0) 
#ifndef NCSTATES
#define NCSTATES (12)   
#elif NCSTATES != 12
#error Invalid specification of NCSTATES defined in compiler command
#endif
#ifndef rtmGetDataMapInfo
#define rtmGetDataMapInfo(rtm) (*rt_dataMapInfoPtr)
#endif
#ifndef rtmSetDataMapInfo
#define rtmSetDataMapInfo(rtm, val) (rt_dataMapInfoPtr = &val)
#endif
#ifndef IN_RACCEL_MAIN
#endif
typedef struct { real_T ewh2czgzt2 [ 3 ] ; real_T ffht1uab1p [ 3 ] ; real_T
av1jt30k31 [ 3 ] ; real_T eisyorlq2r ; real_T m0diztvarb ; real_T ncckp5giye
; real_T m1c2gjrdhf ; real_T gyndz2ty42 ; real_T jlifrmbka3 ; real_T
c2nosomft5 ; real_T c4zgqksn3s ; real_T m30uwutjd5 ; real_T amv5xbxcgx ;
real_T ctr2i5cu0j ; real_T pvv2cmskei ; real_T gst3ni0ebl ; real_T agbvtgnrv4
; real_T hjhp5kuoxj ; real_T glpu5b5wth ; real_T ej2atzfwl0 [ 3 ] ; real_T
ldelskn1jo [ 3 ] ; real_T ljudbp5sfm ; real_T mhbhj1bpzc ; real_T ezi3wqgg1t
; real_T j4csspowr5 ; real_T es5qqkki5l ; real_T lda1u2jc0p ; real_T
hxc25hdudb ; real_T crwpdhv3lp ; real_T aq2in4etwi ; real_T lg5hpscltc [ 6 ]
; real_T h1saod1n1q ; real_T f4k3dw2w0v ; real_T m5psfntta4 ; real_T
m3gvnxject ; real_T l0izt2oa2m ; real_T jfnjrao1g3 ; real_T fwckhvycxa [ 3 ]
; real_T ddcf0ek4jw [ 6 ] ; real_T cmwuafgi05 ; real_T aoodyqcbut [ 3 ] ;
real_T k1afspykmn [ 3 ] ; real_T lc5ruufnmk [ 3 ] ; real_T ckb3sq150e ;
real_T hrq2k5iwyr ; real_T knqqe5buxf ; real_T pxzonjrd4i ; real_T deddzxm4gc
; real_T o0ugrkeqpd [ 36 ] ; real_T ijvi5t5r0z ; real_T i5zbjzuhhx ; real_T
kwxg3amuly ; real_T b1n2m12ywt ; real_T bx1plzk1jh ; real_T eej5dfdnuw ;
real_T leydlmjwwh ; real_T exx2dadn0g ; real_T ebpprftokq ; real_T b152zcpgbp
; real_T l0yxgnvu5h ; real_T lokluenstr ; real_T jd2mqrgdxl [ 2 ] ; real_T
c04goqj2sf ; real_T jhen0kkdwf ; } B ; typedef struct { p1ga5fgg1t kjy5vllogw
; real_T blkvfyc1ut ; real_T dbof0j1l1z ; real_T epsgdxius2 ; real_T
i5vdoafna1 ; real_T f21v3dtx13 ; real_T odzrzx3nyk ; real_T ko2emyti4i ;
real_T hx53qo0tyb ; real_T hoflvlpyvq ; real_T bsuso3aou5 ; hnn0xl5fkk
kqs40q3ion ; struct { void * LoggedData ; } ot01cjf44p ; struct { void *
LoggedData ; } ienxpx13ox ; struct { void * LoggedData ; } lonsi5tvy2 ;
struct { void * LoggedData ; } bopkytftsp ; struct { void * LoggedData ; }
mukxshufya ; struct { void * LoggedData ; } i2ymfnvraf ; struct { void *
LoggedData ; } fpsvbqvcgs ; struct { void * LoggedData ; } cl0ejounxl ;
struct { void * LoggedData ; } ac4mtsmytw ; struct { void * LoggedData ; }
jswy3gs4if ; struct { void * LoggedData ; } m5knzhq5rr ; struct { void *
LoggedData ; } a0xwp4frij ; struct { void * LoggedData ; } o11ub12fkb ;
struct { void * LoggedData ; } lpwv0ihuhs ; struct { void * LoggedData ; }
bo3mponwcp ; struct { void * LoggedData ; } mtyb0k5fng ; struct { void *
LoggedData ; } g4ynicugn1 ; struct { void * LoggedData ; } glbmpk0lvf ;
struct { void * LoggedData ; } kmvfsayspc ; struct { void * LoggedData ; }
pxgw4feuo1 ; struct { void * LoggedData ; } gaotct0bee ; struct { void *
LoggedData ; } iql4ez3dau ; struct { void * FilePtr ; } atwrl0cbxb ; struct {
void * LoggedData ; } bdydrqopie ; struct { void * LoggedData ; } k4za1xg10g
; struct { void * LoggedData ; } gibulb434z ; struct { void * AQHandles ; }
f0qoodbnbc ; int32_T j2zbeu35vc ; int32_T ih0gu0a4vg ; struct { int_T Count ;
int_T Decimation ; } no2vyppbyo ; int_T n33rcmsjab ; int_T jye5a0flet [ 2 ] ;
int_T ejk4nu5buq ; int8_T mhy0u4hbsx ; int8_T ljddttc2rd ; uint8_T lvfkgpske1
; uint8_T ecfpev5hmr ; boolean_T mqsusrzct3 ; boolean_T gzmh1uauzr ;
boolean_T a0cdktfgmq ; boolean_T jhvamlflm5 ; boolean_T pz1vk2xm02 ;
boolean_T ovkmgmp3yk ; } DW ; typedef struct { real_T f50afzevjg [ 3 ] ;
real_T kc2egwi14h [ 3 ] ; real_T o2igygaiml [ 3 ] ; real_T ajbdf0rme2 [ 3 ] ;
} X ; typedef struct { real_T f50afzevjg [ 3 ] ; real_T kc2egwi14h [ 3 ] ;
real_T o2igygaiml [ 3 ] ; real_T ajbdf0rme2 [ 3 ] ; } XDot ; typedef struct {
boolean_T f50afzevjg [ 3 ] ; boolean_T kc2egwi14h [ 3 ] ; boolean_T
o2igygaiml [ 3 ] ; boolean_T ajbdf0rme2 [ 3 ] ; } XDis ; typedef struct {
real_T gxbd5k5ga1 ; real_T fyia3f0ajs ; real_T f1gbjogenh ; real_T pugigtm5ja
; real_T lfvmfu5zzq [ 2 ] ; real_T leel0qnkh1 [ 2 ] ; real_T d1cz5eqy4p ;
real_T p25sjuw5vw ; } ZCV ; typedef struct { rtwCAPI_ModelMappingInfo mmi ; }
DataMapInfo ; struct P_ { real_T Apolar ; real_T CD0 ; real_T CL0 ; real_T
CLDe ; real_T CLa ; real_T CLa_dot ; real_T CLq ; real_T CYDr ; real_T CYb ;
real_T ClDa ; real_T ClDr ; real_T Clb ; real_T Clp ; real_T Clr ; real_T Cm0
; real_T CmDe ; real_T Cma ; real_T Cma_dot ; real_T Cmq ; real_T CnDa ;
real_T CnDr ; real_T Cnb ; real_T Cnp ; real_T Cnr ; real_T Euler_0 [ 3 ] ;
real_T ISA_T0 ; real_T ISA_g ; real_T ISA_hmax ; real_T ISA_lapse ; real_T
ISA_rho0 ; real_T Ixx ; real_T Iyy ; real_T Izz ; real_T Pos_0 [ 3 ] ; real_T
chord ; real_T mass ; real_T span ; real_T DiscretePIDController4_D ; real_T
DiscretePIDController_D ; real_T DiscretePIDController1_D ; real_T
DiscretePIDController2_D ; real_T DiscretePIDController3_D ; real_T
DiscretePIDController4_DifferentiatorICPrevScaledInput ; real_T
DiscretePIDController_DifferentiatorICPrevScaledInput ; real_T
DiscretePIDController1_DifferentiatorICPrevScaledInput ; real_T
DiscretePIDController4_I ; real_T DiscretePIDController_I ; real_T
DiscretePIDController1_I ; real_T DiscretePIDController2_I ; real_T
DiscretePIDController3_I ; real_T
DiscretePIDController2_InitialConditionForFilter ; real_T
DiscretePIDController3_InitialConditionForFilter ; real_T
DiscretePIDController4_InitialConditionForIntegrator ; real_T
DiscretePIDController_InitialConditionForIntegrator ; real_T
DiscretePIDController1_InitialConditionForIntegrator ; real_T
DiscretePIDController2_InitialConditionForIntegrator ; real_T
DiscretePIDController3_InitialConditionForIntegrator ; real_T
DiscretePIDController4_LowerSaturationLimit ; real_T
DiscretePIDController1_LowerSaturationLimit ; real_T
DiscretePIDController3_LowerSaturationLimit ; real_T DiscretePIDController2_N
; real_T DiscretePIDController3_N ; real_T DiscretePIDController4_P ; real_T
DiscretePIDController_P ; real_T DiscretePIDController1_P ; real_T
DiscretePIDController2_P ; real_T DiscretePIDController3_P ; real_T
DiscretePIDController4_UpperSaturationLimit ; real_T
DiscretePIDController1_UpperSaturationLimit ; real_T
DiscretePIDController3_UpperSaturationLimit ; real_T SliderGain_gain ; real_T
SliderGain1_gain ; real_T SliderGain_gain_hyc34xasfz ; real_T
SliderGain1_gain_mv1hpouzrh ; real_T SliderGain_gain_bsd0ykrtc0 ; real_T
WindZ_XData [ 3002 ] ; real_T WindZ_YData [ 3002 ] ; real_T u_Gain ; real_T
WindY_XData [ 3002 ] ; real_T WindY_YData [ 3002 ] ; real_T u_Gain_lth2troxad
; real_T WindX_XData [ 3002 ] ; real_T WindX_YData [ 3002 ] ; real_T _Gain ;
real_T MatrixGain6_Gain [ 9 ] ; real_T ubvbwb_IC [ 3 ] ; real_T
Integrator_gainval ; real_T Tsamp_WtEt ; real_T Integrator_gainval_gsc5ke3qa1
; real_T Tsamp_WtEt_eenah0djpv ; real_T Integrator_gainval_pgxpxjbdlc ;
real_T Tsamp_WtEt_i0xopibhwa ; real_T Switch_Threshold ; real_T
Integrator_gainval_fn0merchw3 ; real_T Filter_gainval ; real_T
Integrator_gainval_kdbzsgvpvb ; real_T Filter_gainval_elrzqrryfc ; real_T
u2_Gain ; real_T R2D3_Gain ; real_T R2D2_Gain ; real_T R2D1_Gain ; real_T
D2R_Gain ; real_T Deg2Rad_Gain ; real_T Gain4_Gain ; real_T Deg2Rad2_Gain ;
real_T Gain1_Gain ; real_T pqr_IC [ 3 ] ; real_T Switch_Threshold_hwgs5rnbxi
; real_T Gain_Gain ; real_T Limitaltitude_LowerSat ; real_T
Gain_Gain_mqy02r1o31 ; real_T Deg2Rad1_Gain ; real_T Gain1_Gain_nqisqcqfrw ;
real_T Gain1_Gain_ftpoywohzv ; real_T Gain1_Gain_e2mkjz4tqt ; real_T
Gain2_Gain ; real_T Gain4_Gain_ljfjkw1syf ; real_T Deg2Rad3_Gain ; real_T
Gain3_Gain ; real_T Gain3_Gain_jhgwt4xcre ; real_T Gain4_Gain_fd51wengpv ;
real_T Gain1_Gain_dpix5mof3i ; real_T Gain4_Gain_ohs20inw3v ; real_T
Gain4_Gain_n3uynydxab ; real_T Gain3_Gain_gjw5qqxglj ; real_T Gain5_Gain ;
real_T Throttle2RPM_Gain ; real_T mps2fps_Gain ; real_T Saturation_UpperSat ;
real_T Saturation_LowerSat ; real_T lbs2kg_Gain ; real_T Saturation1_UpperSat
; real_T Saturation1_LowerSat ; real_T R2D2_Gain_jrhz3pfqfv ; real_T
Gain_Gain_a1wggbqhys [ 9 ] ; real_T Gain1_Gain_mlyplvcvro [ 9 ] ; real_T
Gain2_Gain_kp2d4nocmq [ 9 ] ; real_T Gain3_Gain_kf22pabip4 ; real_T
R2D1_Gain_g0cjd2kme4 ; real_T Zpositiveisdown_Gain [ 9 ] ; real_T R2D_Gain ;
real_T nowind_Value [ 3 ] ; real_T Constant4_Value ; real_T Constant1_Value [
9 ] ; real_T Constant4_Value_lvvzxuwh5z ; real_T Constant_Value ; real_T
Deg2Rad4_Gain ; real_T Gain2_Gain_b4uvpqpdbd ; real_T Gain1_Gain_nbhhfd3fwa ;
real_T Cmq1_Value ; real_T Cmq1_Value_dqzexw0fvg ; real_T
Gain1_Gain_dd3z2ich2e ; real_T Cmq1_Value_hei4fwlj0u ; real_T
Cmq1_Value_acz4kovyrj ; real_T Constant_Value_cqthaabju2 ; real_T
Constant1_Value_g5jniqvvpl ; real_T Gain3_Gain_jo4inzsfgw ; real_T
Gain3_Gain_fosanw5ymw ; real_T Weightmatrix_Value [ 3 ] ; real_T
Constant_Value_ibkcrpfjyo [ 6 ] ; real_T Constant1_Value_a4soj351ll [ 21 ] ;
real_T Constant2_Value ; real_T Constant3_Value [ 12 ] ; real_T
Constant_Value_d3cgtfumsg ; real_T airpseed_desired_Value ; real_T
h_desired_Value ; uint8_T ManualSwitch1_CurrentSetting ; } ; extern const
char_T * RT_MEMORY_ALLOCATION_ERROR ; extern B rtB ; extern X rtX ; extern DW
rtDW ; extern P rtP ; extern mxArray * mr_sixdof_GetDWork ( ) ; extern void
mr_sixdof_SetDWork ( const mxArray * ssDW ) ; extern mxArray *
mr_sixdof_GetSimStateDisallowedBlocks ( ) ; extern const
rtwCAPI_ModelMappingStaticInfo * sixdof_GetCAPIStaticMap ( void ) ; extern
SimStruct * const rtS ; extern const int_T gblNumToFiles ; extern const int_T
gblNumFrFiles ; extern const int_T gblNumFrWksBlocks ; extern rtInportTUtable
* gblInportTUtables ; extern const char * gblInportFileName ; extern const
int_T gblNumRootInportBlks ; extern const int_T gblNumModelInputs ; extern
const int_T gblInportDataTypeIdx [ ] ; extern const int_T gblInportDims [ ] ;
extern const int_T gblInportComplex [ ] ; extern const int_T
gblInportInterpoFlag [ ] ; extern const int_T gblInportContinuous [ ] ;
extern const int_T gblParameterTuningTid ; extern DataMapInfo *
rt_dataMapInfoPtr ; extern rtwCAPI_ModelMappingInfo * rt_modelMapInfoPtr ;
void MdlOutputs ( int_T tid ) ; void MdlOutputsParameterSampleTime ( int_T
tid ) ; void MdlUpdate ( int_T tid ) ; void MdlTerminate ( void ) ; void
MdlInitializeSizes ( void ) ; void MdlInitializeSampleTimes ( void ) ;
SimStruct * raccel_register_model ( ssExecutionInfo * executionInfo ) ;
#endif
