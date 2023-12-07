#include "sixdof.h"
#include "rtwtypes.h"
#include <string.h>
#include "mwmathutil.h"
#include <math.h>
#include "rt_look.h"
#include "rt_look1d.h"
#include "sixdof_private.h"
#include "rt_logging_mmi.h"
#include "sixdof_capi.h"
#include "sixdof_dt.h"
extern void * CreateDiagnosticAsVoidPtr_wrapper ( const char * id , int nargs
, ... ) ; RTWExtModeInfo * gblRTWExtModeInfo = NULL ; void
raccelForceExtModeShutdown ( boolean_T extModeStartPktReceived ) { if ( !
extModeStartPktReceived ) { boolean_T stopRequested = false ;
rtExtModeWaitForStartPkt ( gblRTWExtModeInfo , 2 , & stopRequested ) ; }
rtExtModeShutdown ( 2 ) ; }
#include "slsv_diagnostic_codegen_c_api.h"
#include "slsa_sim_engine.h"
const int_T gblNumToFiles = 1 ; const int_T gblNumFrFiles = 0 ; const int_T
gblNumFrWksBlocks = 0 ;
#ifdef RSIM_WITH_SOLVER_MULTITASKING
boolean_T gbl_raccel_isMultitasking = 1 ;
#else
boolean_T gbl_raccel_isMultitasking = 0 ;
#endif
boolean_T gbl_raccel_tid01eq = 1 ; int_T gbl_raccel_NumST = 3 ; const char_T
* gbl_raccel_Version = "9.9 (R2023a) 19-Nov-2022" ; void
raccel_setup_MMIStateLog ( SimStruct * S ) {
#ifdef UseMMIDataLogging
rt_FillStateSigInfoFromMMI ( ssGetRTWLogInfo ( S ) , & ssGetErrorStatus ( S )
) ;
#else
UNUSED_PARAMETER ( S ) ;
#endif
} static DataMapInfo rt_dataMapInfo ; DataMapInfo * rt_dataMapInfoPtr = &
rt_dataMapInfo ; rtwCAPI_ModelMappingInfo * rt_modelMapInfoPtr = & (
rt_dataMapInfo . mmi ) ; const int_T gblNumRootInportBlks = 0 ; const int_T
gblNumModelInputs = 0 ; extern const char * gblInportFileName ; extern
rtInportTUtable * gblInportTUtables ; const int_T gblInportDataTypeIdx [ ] =
{ - 1 } ; const int_T gblInportDims [ ] = { - 1 } ; const int_T
gblInportComplex [ ] = { - 1 } ; const int_T gblInportInterpoFlag [ ] = { - 1
} ; const int_T gblInportContinuous [ ] = { - 1 } ; int_T enableFcnCallFlag [
] = { 1 , 1 , 1 } ; const char * raccelLoadInputsAndAperiodicHitTimes (
SimStruct * S , const char * inportFileName , int * matFileFormat ) { return
rt_RAccelReadInportsMatFile ( S , inportFileName , matFileFormat ) ; }
#include "simstruc.h"
#include "fixedpoint.h"
#include "slsa_sim_engine.h"
#include "simtarget/slSimTgtSLExecSimBridge.h"
#define pq4ibxz3zz (-1)
B rtB ; X rtX ; DW rtDW ; static SimStruct model_S ; SimStruct * const rtS =
& model_S ; static real_T jbu3wecjlg ( const real_T x [ 3 ] ) ; static real_T
n12li4ectl ( const real_T x [ 2 ] ) ; static real_T jbu3wecjlg ( const real_T
x [ 3 ] ) { real_T absxk ; real_T scale ; real_T t ; real_T y ; scale =
3.3121686421112381E-170 ; absxk = muDoubleScalarAbs ( x [ 0 ] ) ; if ( absxk
> 3.3121686421112381E-170 ) { y = 1.0 ; scale = absxk ; } else { t = absxk /
3.3121686421112381E-170 ; y = t * t ; } absxk = muDoubleScalarAbs ( x [ 1 ] )
; if ( absxk > scale ) { t = scale / absxk ; y = y * t * t + 1.0 ; scale =
absxk ; } else { t = absxk / scale ; y += t * t ; } absxk = muDoubleScalarAbs
( x [ 2 ] ) ; if ( absxk > scale ) { t = scale / absxk ; y = y * t * t + 1.0
; scale = absxk ; } else { t = absxk / scale ; y += t * t ; } return scale *
muDoubleScalarSqrt ( y ) ; } static real_T n12li4ectl ( const real_T x [ 2 ]
) { real_T absxk ; real_T scale ; real_T t ; real_T y ; scale =
3.3121686421112381E-170 ; absxk = muDoubleScalarAbs ( x [ 0 ] ) ; if ( absxk
> 3.3121686421112381E-170 ) { y = 1.0 ; scale = absxk ; } else { t = absxk /
3.3121686421112381E-170 ; y = t * t ; } absxk = muDoubleScalarAbs ( x [ 1 ] )
; if ( absxk > scale ) { t = scale / absxk ; y = y * t * t + 1.0 ; scale =
absxk ; } else { t = absxk / scale ; y += t * t ; } return scale *
muDoubleScalarSqrt ( y ) ; } void rt_mldivide_U1d6x6_U2d6x1_Yd6x1_snf ( const
real_T u0 [ 36 ] , real_T u1 [ 6 ] ) { real_T x [ 36 ] ; real_T s ; real_T
smax ; int32_T c ; int32_T c_p ; int32_T ijA ; int32_T ix ; int32_T iy ;
int32_T jA ; int32_T jj ; int32_T jp1j ; int32_T kAcol ; int8_T ipiv [ 6 ] ;
int8_T ipiv_p ; memcpy ( & x [ 0 ] , & u0 [ 0 ] , 36U * sizeof ( real_T ) ) ;
for ( ix = 0 ; ix < 6 ; ix ++ ) { ipiv [ ix ] = ( int8_T ) ( ix + 1 ) ; } for
( kAcol = 0 ; kAcol < 5 ; kAcol ++ ) { c = kAcol * 7 + 2 ; jj = kAcol * 7 ;
c_p = 6 - kAcol ; iy = 1 ; smax = muDoubleScalarAbs ( x [ jj ] ) ; for ( jA =
2 ; jA <= c_p ; jA ++ ) { s = muDoubleScalarAbs ( x [ ( c + jA ) - 3 ] ) ; if
( s > smax ) { iy = jA ; smax = s ; } } if ( x [ ( c + iy ) - 3 ] != 0.0 ) {
if ( iy - 1 != 0 ) { ipiv [ kAcol ] = ( int8_T ) ( kAcol + iy ) ; iy = (
kAcol + iy ) - 1 ; for ( jA = 0 ; jA < 6 ; jA ++ ) { smax = x [ jA * 6 +
kAcol ] ; x [ kAcol + jA * 6 ] = x [ jA * 6 + iy ] ; x [ iy + jA * 6 ] = smax
; } } iy = c - kAcol ; for ( ix = c ; ix <= iy + 4 ; ix ++ ) { x [ ix - 1 ]
/= x [ jj ] ; } } c_p = 4 - kAcol ; jA = jj ; jj += 6 ; for ( jp1j = 0 ; jp1j
<= c_p ; jp1j ++ ) { if ( x [ jp1j * 6 + jj ] != 0.0 ) { smax = - x [ jp1j *
6 + jj ] ; iy = jA + 8 ; ix = ( jA - kAcol ) + 12 ; for ( ijA = iy ; ijA <=
ix ; ijA ++ ) { x [ ijA - 1 ] += x [ ( ( c + ijA ) - jA ) - 9 ] * smax ; } }
jA += 6 ; } } for ( ix = 0 ; ix < 5 ; ix ++ ) { ipiv_p = ipiv [ ix ] ; if (
ix + 1 != ipiv_p ) { smax = u1 [ ix ] ; u1 [ ix ] = u1 [ ipiv_p - 1 ] ; u1 [
ipiv_p - 1 ] = smax ; } } for ( jA = 0 ; jA < 6 ; jA ++ ) { kAcol = 6 * jA -
1 ; if ( u1 [ jA ] != 0.0 ) { for ( ix = jA + 2 ; ix < 7 ; ix ++ ) { u1 [ ix
- 1 ] -= x [ ix + kAcol ] * u1 [ jA ] ; } } } for ( jA = 5 ; jA >= 0 ; jA --
) { kAcol = 6 * jA ; smax = u1 [ jA ] ; if ( smax != 0.0 ) { u1 [ jA ] = smax
/ x [ jA + kAcol ] ; iy = jA - 1 ; for ( ix = 0 ; ix <= iy ; ix ++ ) { u1 [
ix ] -= x [ ix + kAcol ] * u1 [ jA ] ; } } } } void MdlInitialize ( void ) {
int32_T i ; rtDW . blkvfyc1ut = rtP .
DiscretePIDController4_InitialConditionForIntegrator ; rtDW . dbof0j1l1z =
rtP . DiscretePIDController4_DifferentiatorICPrevScaledInput ; rtDW .
epsgdxius2 = rtP . DiscretePIDController_InitialConditionForIntegrator ; rtDW
. i5vdoafna1 = rtP . DiscretePIDController_DifferentiatorICPrevScaledInput ;
rtDW . f21v3dtx13 = rtP .
DiscretePIDController1_InitialConditionForIntegrator ; rtDW . odzrzx3nyk =
rtP . DiscretePIDController1_DifferentiatorICPrevScaledInput ; rtDW .
ko2emyti4i = rtP . DiscretePIDController2_InitialConditionForIntegrator ;
rtDW . hx53qo0tyb = rtP . DiscretePIDController2_InitialConditionForFilter ;
rtDW . hoflvlpyvq = rtP .
DiscretePIDController3_InitialConditionForIntegrator ; rtDW . bsuso3aou5 =
rtP . DiscretePIDController3_InitialConditionForFilter ; rtX . f50afzevjg [ 0
] = rtP . Pos_0 [ 0 ] ; rtX . kc2egwi14h [ 0 ] = rtP . Euler_0 [ 0 ] ; rtX .
o2igygaiml [ 0 ] = rtP . ubvbwb_IC [ 0 ] ; rtX . ajbdf0rme2 [ 0 ] = rtP .
pqr_IC [ 0 ] ; rtX . f50afzevjg [ 1 ] = rtP . Pos_0 [ 1 ] ; rtX . kc2egwi14h
[ 1 ] = rtP . Euler_0 [ 1 ] ; rtX . o2igygaiml [ 1 ] = rtP . ubvbwb_IC [ 1 ]
; rtX . ajbdf0rme2 [ 1 ] = rtP . pqr_IC [ 1 ] ; rtX . f50afzevjg [ 2 ] = rtP
. Pos_0 [ 2 ] ; rtX . kc2egwi14h [ 2 ] = rtP . Euler_0 [ 2 ] ; rtX .
o2igygaiml [ 2 ] = rtP . ubvbwb_IC [ 2 ] ; rtX . ajbdf0rme2 [ 2 ] = rtP .
pqr_IC [ 2 ] ; rtDW . j2zbeu35vc = pq4ibxz3zz ; rtDW . lvfkgpske1 = 0U ; rtDW
. ih0gu0a4vg = pq4ibxz3zz ; rtDW . ecfpev5hmr = 0U ; rtDW . kjy5vllogw .
WaypointIndex = 1.0 ; for ( i = 0 ; i < 21 ; i ++ ) { rtDW . kjy5vllogw .
WaypointsInternal [ i ] *= 0.0 ; } } void MdlStart ( void ) { int32_T i ; {
bool externalInputIsInDatasetFormat = false ; void * pISigstreamManager =
rt_GetISigstreamManager ( rtS ) ;
rtwISigstreamManagerGetInputIsInDatasetFormat ( pISigstreamManager , &
externalInputIsInDatasetFormat ) ; if ( externalInputIsInDatasetFormat ) { }
} { { { bool isStreamoutAlreadyRegistered = false ; { sdiSignalSourceInfoU
srcInfo ; sdiLabelU loggedName = sdiGetLabelFromChars ( "" ) ; sdiLabelU
origSigName = sdiGetLabelFromChars ( "" ) ; sdiLabelU propName =
sdiGetLabelFromChars ( "" ) ; sdiLabelU blockPath = sdiGetLabelFromChars (
"sixdof/Obstacles/Switch" ) ; sdiLabelU blockSID = sdiGetLabelFromChars ( ""
) ; sdiLabelU subPath = sdiGetLabelFromChars ( "" ) ; sdiDims sigDims ;
sdiLabelU sigName = sdiGetLabelFromChars ( "" ) ; sdiAsyncRepoDataTypeHandle
hDT = sdiAsyncRepoGetBuiltInDataTypeHandle ( DATA_TYPE_DOUBLE ) ; {
sdiComplexity sigComplexity = REAL ; sdiSampleTimeContinuity stCont =
SAMPLE_TIME_CONTINUOUS ; int_T sigDimsArray [ 2 ] = { 1 , 1 } ; sigDims .
nDims = 2 ; sigDims . dimensions = sigDimsArray ; srcInfo . numBlockPathElems
= 1 ; srcInfo . fullBlockPath = ( sdiFullBlkPathU ) & blockPath ; srcInfo .
SID = ( sdiSignalIDU ) & blockSID ; srcInfo . subPath = subPath ; srcInfo .
portIndex = 0 + 1 ; srcInfo . signalName = sigName ; srcInfo . sigSourceUUID
= 0 ; rtDW . f0qoodbnbc . AQHandles = sdiStartAsyncioQueueCreation ( hDT , &
srcInfo , rt_dataMapInfo . mmi . InstanceMap . fullPath ,
"b487d7ff-bd99-4b88-9502-9c33f42849c4" , sigComplexity , & sigDims ,
DIMENSIONS_MODE_FIXED , stCont , "" ) ; sdiCompleteAsyncioQueueCreation (
rtDW . f0qoodbnbc . AQHandles , hDT , & srcInfo ) ; if ( rtDW . f0qoodbnbc .
AQHandles ) { sdiSetSignalSampleTimeString ( rtDW . f0qoodbnbc . AQHandles ,
"0.01" , 0.01 , ssGetTFinal ( rtS ) ) ; sdiSetSignalRefRate ( rtDW .
f0qoodbnbc . AQHandles , 0.0 ) ; sdiSetRunStartTime ( rtDW . f0qoodbnbc .
AQHandles , ssGetTaskTime ( rtS , 1 ) ) ; sdiAsyncRepoSetSignalExportSettings
( rtDW . f0qoodbnbc . AQHandles , 1 , 0 ) ; sdiAsyncRepoSetSignalExportName (
rtDW . f0qoodbnbc . AQHandles , loggedName , origSigName , propName ) ; }
sdiFreeLabel ( sigName ) ; sdiFreeLabel ( loggedName ) ; sdiFreeLabel (
origSigName ) ; sdiFreeLabel ( propName ) ; sdiFreeLabel ( blockPath ) ;
sdiFreeLabel ( blockSID ) ; sdiFreeLabel ( subPath ) ; } } if ( !
isStreamoutAlreadyRegistered ) { } } } } rtDW . kjy5vllogw . LastWaypointFlag
= false ; rtDW . kjy5vllogw . StartFlag = true ; rtDW . kjy5vllogw .
LookaheadFactor = 1.01 ; rtDW . a0cdktfgmq = true ; rtDW . kjy5vllogw .
isInitialized = 1 ; for ( i = 0 ; i < 8 ; i ++ ) { rtDW . kjy5vllogw .
inputVarSize [ 0 ] . f1 [ i ] = 1U ; } rtDW . kjy5vllogw . inputVarSize [ 1 ]
. f1 [ 0 ] = 7U ; rtDW . kjy5vllogw . inputVarSize [ 1 ] . f1 [ 1 ] = 3U ;
for ( i = 0 ; i < 6 ; i ++ ) { rtDW . kjy5vllogw . inputVarSize [ 1 ] . f1 [
i + 2 ] = 1U ; } for ( i = 0 ; i < 8 ; i ++ ) { rtDW . kjy5vllogw .
inputVarSize [ 2 ] . f1 [ i ] = 1U ; } memset ( & rtDW . kjy5vllogw .
WaypointsInternal [ 0 ] , 0 , 21U * sizeof ( real_T ) ) ; rtDW . kjy5vllogw .
NumWaypoints = 0.0 ; rtDW . jhvamlflm5 = true ; rtDW . kqs40q3ion .
isInitialized = 1 ; rtDW . ljddttc2rd = 0 ; { void * fp = ( NULL ) ; const
char * fileNameOriginal = "simout.mat" ; char * fileName = ( char * ) malloc
( 509 ) ; if ( fileName == ( NULL ) ) { ssSetErrorStatus ( rtS ,
"Error allocating memory for file name" ) ; return ; } strcpy ( fileName ,
fileNameOriginal ) ; { const char * blockpath = "sixdof/A//C/Output/To File"
; if ( slIsRapidAcceleratorSimulating ( ) ) { rt_RAccelReplaceToFilename (
blockpath , fileName ) ; } } { const char * errMsg = ( NULL ) ; errMsg =
rtwH5LoggingCollectionCreateInstance ( 1 , & fp , rtliGetLoggingInterval (
ssGetRootSS ( rtS ) -> mdlInfo -> rtwLogInfo ) ) ; if ( errMsg != ( NULL ) )
{ ssSetErrorStatus ( rtS , errMsg ) ; return ; } { int_T dimensions [ 1 ] = {
18 } ; errMsg = rtwH5LoggingCollectionAddElement ( 1 , fp , fileName ,
"simout" , 0 , "" , "linear" , "double" , 1 , dimensions , 0 , 1 , 1 , 0 , 0
, 0 , 0 , 0 , 0 , 0 ) ; } if ( errMsg != ( NULL ) ) { ssSetErrorStatus ( rtS
, errMsg ) ; return ; } } if ( fileName != ( NULL ) ) { free ( fileName ) ; }
rtDW . no2vyppbyo . Count = 0 ; rtDW . no2vyppbyo . Decimation = - 1 ; rtDW .
atwrl0cbxb . FilePtr = fp ; } MdlInitialize ( ) ; } void MdlOutputs ( int_T
tid ) { real_T j2yak2edzf [ 36 ] ; real_T j2yak2edzf_p [ 36 ] ; real_T
b_waypointsIn_data [ 21 ] ; real_T waypoints_data [ 21 ] ; real_T iygdiv1cei
[ 18 ] ; real_T p1wjvujgew [ 18 ] ; real_T khdw5q2wy4 [ 9 ] ; real_T
e2xginouw2 [ 6 ] ; real_T tmp_p [ 6 ] ; real_T b_waypointsIn [ 3 ] ; real_T
ml23bolgnb [ 3 ] ; real_T tmp [ 3 ] ; real_T T [ 2 ] ; real_T bhu1io5c4t [ 2
] ; real_T Constant_Value_ibkcrpfjyo ; real_T an2j0hkqbl_idx_2 ; real_T
dz5vdjb0hd_idx_0 ; real_T dz5vdjb0hd_idx_1 ; real_T jlhwiofgni ; real_T
lambda ; real_T lpi4tapkb5 ; real_T oxy5kmdygt ; real_T varargin_1_data ;
real_T x2 ; real_T y2 ; int32_T b_exponent ; int32_T b_exponent_p ; int32_T
i2 ; int32_T idx ; int32_T ix ; int32_T near ; int8_T inSize [ 8 ] ; int8_T
tmp_data [ 7 ] ; boolean_T x [ 18 ] ; boolean_T distinctWptsIdx [ 7 ] ;
boolean_T y [ 6 ] ; boolean_T exitg1 ; boolean_T guard1 ; boolean_T guard2 ;
boolean_T p ; boolean_T q ; boolean_T tmp_data_p ; rtB . ewh2czgzt2 [ 0 ] =
rtX . f50afzevjg [ 0 ] ; rtB . ewh2czgzt2 [ 1 ] = rtX . f50afzevjg [ 1 ] ;
rtB . ewh2czgzt2 [ 2 ] = rtX . f50afzevjg [ 2 ] ; if ( ssIsSampleHit ( rtS ,
1 , 0 ) ) { } rtB . ffht1uab1p [ 0 ] = rtX . kc2egwi14h [ 0 ] ; rtB .
ffht1uab1p [ 1 ] = rtX . kc2egwi14h [ 1 ] ; rtB . ffht1uab1p [ 2 ] = rtX .
kc2egwi14h [ 2 ] ; if ( ssIsSampleHit ( rtS , 1 , 0 ) ) { } rtB . av1jt30k31
[ 0 ] = rtX . o2igygaiml [ 0 ] ; rtB . av1jt30k31 [ 1 ] = rtX . o2igygaiml [
1 ] ; rtB . av1jt30k31 [ 2 ] = rtX . o2igygaiml [ 2 ] ; rtB . eisyorlq2r =
rtP . airpseed_desired_Value - rtB . av1jt30k31 [ 0 ] ; if ( ssIsSampleHit (
rtS , 1 , 0 ) ) { rtB . m0diztvarb = rtP . DiscretePIDController4_D * rtB .
eisyorlq2r * rtP . Tsamp_WtEt ; lambda = ( rtP . DiscretePIDController4_P *
rtB . eisyorlq2r + rtDW . blkvfyc1ut ) + ( rtB . m0diztvarb - rtDW .
dbof0j1l1z ) ; if ( lambda > rtP .
DiscretePIDController4_UpperSaturationLimit ) { rtB . ncckp5giye = rtP .
DiscretePIDController4_UpperSaturationLimit ; } else if ( lambda < rtP .
DiscretePIDController4_LowerSaturationLimit ) { rtB . ncckp5giye = rtP .
DiscretePIDController4_LowerSaturationLimit ; } else { rtB . ncckp5giye =
lambda ; } } rtB . m1c2gjrdhf = rtP . h_desired_Value - rtB . ewh2czgzt2 [ 2
] ; if ( ssIsSampleHit ( rtS , 1 , 0 ) ) { rtB . gyndz2ty42 = rtP .
DiscretePIDController_D * rtB . m1c2gjrdhf * rtP . Tsamp_WtEt_eenah0djpv ;
rtB . jlifrmbka3 = ( rtP . DiscretePIDController_P * rtB . m1c2gjrdhf + rtDW
. epsgdxius2 ) + ( rtB . gyndz2ty42 - rtDW . i5vdoafna1 ) ; } rtB .
c2nosomft5 = rtB . jlifrmbka3 - rtB . ffht1uab1p [ 1 ] ; if ( ssIsSampleHit (
rtS , 1 , 0 ) ) { rtB . c4zgqksn3s = rtP . DiscretePIDController1_D * rtB .
c2nosomft5 * rtP . Tsamp_WtEt_i0xopibhwa ; lambda = ( rtP .
DiscretePIDController1_P * rtB . c2nosomft5 + rtDW . f21v3dtx13 ) + ( rtB .
c4zgqksn3s - rtDW . odzrzx3nyk ) ; if ( lambda > rtP .
DiscretePIDController1_UpperSaturationLimit ) { rtB . m30uwutjd5 = rtP .
DiscretePIDController1_UpperSaturationLimit ; } else if ( lambda < rtP .
DiscretePIDController1_LowerSaturationLimit ) { rtB . m30uwutjd5 = rtP .
DiscretePIDController1_LowerSaturationLimit ; } else { rtB . m30uwutjd5 =
lambda ; } } dz5vdjb0hd_idx_0 = rtB . ewh2czgzt2 [ 0 ] ; dz5vdjb0hd_idx_1 =
rtB . ewh2czgzt2 [ 1 ] ; rtDW . j2zbeu35vc = pq4ibxz3zz ; near = 0 ; idx = 1
; x2 = rtP . Constant_Value_d3cgtfumsg * muDoubleScalarCos ( rtB . ffht1uab1p
[ 2 ] ) + rtB . ewh2czgzt2 [ 0 ] ; y2 = rtP . Constant_Value_d3cgtfumsg *
muDoubleScalarSin ( rtB . ffht1uab1p [ 2 ] ) + rtB . ewh2czgzt2 [ 1 ] ; for (
i2 = 0 ; i2 < 6 ; i2 ++ ) { lpi4tapkb5 = rtP . Constant3_Value [ i2 ] ;
lambda = dz5vdjb0hd_idx_0 - lpi4tapkb5 ; an2j0hkqbl_idx_2 = rtP .
Constant3_Value [ i2 + 6 ] ; jlhwiofgni = dz5vdjb0hd_idx_1 - an2j0hkqbl_idx_2
; lpi4tapkb5 = x2 - lpi4tapkb5 ; an2j0hkqbl_idx_2 = y2 - an2j0hkqbl_idx_2 ;
Constant_Value_ibkcrpfjyo = rtP . Constant_Value_ibkcrpfjyo [ i2 ] ; if ( (
Constant_Value_ibkcrpfjyo > muDoubleScalarSqrt ( lambda * lambda + jlhwiofgni
* jlhwiofgni ) ) || ( Constant_Value_ibkcrpfjyo > muDoubleScalarSqrt (
lpi4tapkb5 * lpi4tapkb5 + an2j0hkqbl_idx_2 * an2j0hkqbl_idx_2 ) ) ) { near =
1 ; idx = i2 + 1 ; } } rtB . jd2mqrgdxl [ 0 ] = near ; rtB . jd2mqrgdxl [ 1 ]
= idx ; inSize [ 0 ] = 7 ; inSize [ 1 ] = 3 ; for ( idx = 0 ; idx < 6 ; idx
++ ) { inSize [ idx + 2 ] = 1 ; } near = 0 ; exitg1 = false ; while ( ( !
exitg1 ) && ( near < 8 ) ) { if ( rtDW . kjy5vllogw . inputVarSize [ 1 ] . f1
[ near ] != ( uint32_T ) inSize [ near ] ) { for ( idx = 0 ; idx < 8 ; idx ++
) { rtDW . kjy5vllogw . inputVarSize [ 1 ] . f1 [ idx ] = ( uint32_T ) inSize
[ idx ] ; } exitg1 = true ; } else { near ++ ; } } lambda = rtP .
Constant2_Value ; rtDW . kjy5vllogw . LookaheadDistFlag = 0U ; if ( rtP .
Constant2_Value < 0.1 ) { lambda = 0.1 ; rtDW . kjy5vllogw .
LookaheadDistFlag = 1U ; } rtDW . kjy5vllogw . InitialPose [ 0 ] = 0.0 ; rtDW
. kjy5vllogw . InitialPose [ 1 ] = 0.0 ; rtDW . kjy5vllogw . InitialPose [ 2
] = 0.0 ; rtDW . kjy5vllogw . InitialPose [ 3 ] = 0.0 ; rtDW . kjy5vllogw .
NumWaypoints = 7.0 ; guard1 = false ; if ( rtDW . kjy5vllogw . NumWaypoints
!= 7.0 ) { guard1 = true ; } else { if ( rtDW . kjy5vllogw . NumWaypoints <
1.0 ) { idx = 0 ; } else { idx = ( int32_T ) rtDW . kjy5vllogw . NumWaypoints
; } if ( rtDW . kjy5vllogw . NumWaypoints < 1.0 ) { i2 = 0 ; } else { i2 = (
int32_T ) rtDW . kjy5vllogw . NumWaypoints ; } q = false ; p = false ; if (
idx == i2 ) { p = true ; } if ( p && ( idx != 0 ) && ( i2 != 0 ) ) { near = 0
; exitg1 = false ; while ( ( ! exitg1 ) && ( near <= i2 * 3 - 1 ) ) { if ( !
( rtDW . kjy5vllogw . WaypointsInternal [ near / idx * 7 + near % idx ] ==
rtP . Constant1_Value_a4soj351ll [ near / i2 * 7 + near % i2 ] ) ) { p =
false ; exitg1 = true ; } else { near ++ ; } } } if ( p ) { q = true ; } if (
! q ) { guard1 = true ; } } if ( guard1 ) { memcpy ( & rtDW . kjy5vllogw .
WaypointsInternal [ 0 ] , & rtP . Constant1_Value_a4soj351ll [ 0 ] , 21U *
sizeof ( real_T ) ) ; rtDW . kjy5vllogw . WaypointIndex = 1.0 ; } for ( idx =
0 ; idx < 7 ; idx ++ ) { distinctWptsIdx [ idx ] = true ; } for ( idx = 0 ;
idx < 3 ; idx ++ ) { for ( i2 = 0 ; i2 < 6 ; i2 ++ ) { x [ i2 + 6 * idx ] = (
rtP . Constant1_Value_a4soj351ll [ ( ( i2 + 2 ) + 7 * idx ) - 1 ] != rtP .
Constant1_Value_a4soj351ll [ 7 * idx + i2 ] ) ; } } idx = 0 ; i2 = 12 ; for (
near = 0 ; near < 6 ; near ++ ) { y [ near ] = false ; idx ++ ; i2 ++ ; ix =
idx ; exitg1 = false ; while ( ( ! exitg1 ) && ( ix <= i2 ) ) { if ( x [ ix -
1 ] ) { y [ near ] = true ; exitg1 = true ; } else { ix += 6 ; } }
distinctWptsIdx [ near ] = y [ near ] ; } i2 = 0 ; for ( idx = 0 ; idx < 7 ;
idx ++ ) { if ( distinctWptsIdx [ idx ] ) { i2 ++ ; } } near = i2 ; i2 = 0 ;
for ( idx = 0 ; idx < 7 ; idx ++ ) { if ( distinctWptsIdx [ idx ] ) {
tmp_data [ i2 ] = ( int8_T ) idx ; i2 ++ ; } } for ( idx = 0 ; idx < 3 ; idx
++ ) { for ( i2 = 0 ; i2 < near ; i2 ++ ) { b_waypointsIn_data [ i2 + near *
idx ] = rtP . Constant1_Value_a4soj351ll [ 7 * idx + tmp_data [ i2 ] ] ; } }
rtDW . kjy5vllogw . LookaheadDistance = lambda ; if ( near == 0 ) { rtB .
lokluenstr = rtB . ffht1uab1p [ 2 ] ; } else { guard1 = false ; if ( near ==
1 ) { if ( rtDW . kjy5vllogw . StartFlag ) { rtDW . kjy5vllogw . InitialPose
[ 0 ] = rtB . ewh2czgzt2 [ 0 ] ; rtDW . kjy5vllogw . InitialPose [ 1 ] = rtB
. ewh2czgzt2 [ 1 ] ; rtDW . kjy5vllogw . InitialPose [ 2 ] = rtB . ewh2czgzt2
[ 2 ] ; rtDW . kjy5vllogw . InitialPose [ 3 ] = rtB . ffht1uab1p [ 2 ] ; }
b_waypointsIn [ 0 ] = b_waypointsIn_data [ 0 ] - rtB . ewh2czgzt2 [ 0 ] ;
b_waypointsIn [ 1 ] = b_waypointsIn_data [ 1 ] - rtB . ewh2czgzt2 [ 1 ] ;
b_waypointsIn [ 2 ] = b_waypointsIn_data [ 2 ] - rtB . ewh2czgzt2 [ 2 ] ; if
( jbu3wecjlg ( b_waypointsIn ) < 1.4901161193847656E-8 ) { rtB . lokluenstr =
rtB . ffht1uab1p [ 2 ] ; rtDW . kjy5vllogw . StartFlag = false ; } else {
rtDW . kjy5vllogw . StartFlag = false ; rtDW . kjy5vllogw . NumWaypoints =
2.0 ; ix = near + 1 ; for ( idx = 0 ; idx < 3 ; idx ++ ) { waypoints_data [ (
near + 1 ) * idx ] = rtDW . kjy5vllogw . InitialPose [ idx ] ; for ( i2 = 0 ;
i2 < near ; i2 ++ ) { waypoints_data [ ( i2 + ( near + 1 ) * idx ) + 1 ] =
b_waypointsIn_data [ near * idx + i2 ] ; } } guard1 = true ; } } else { ix =
near ; near *= 3 ; if ( near - 1 >= 0 ) { memcpy ( & waypoints_data [ 0 ] , &
b_waypointsIn_data [ 0 ] , ( uint32_T ) near * sizeof ( real_T ) ) ; } guard1
= true ; } if ( guard1 ) { q = false ; if ( rtDW . kjy5vllogw . WaypointIndex
== rtDW . kjy5vllogw . NumWaypoints ) { q = true ; } if ( q ) { rtDW .
kjy5vllogw . LastWaypointFlag = true ; rtDW . kjy5vllogw . WaypointIndex -- ;
} b_waypointsIn [ 0 ] = rtB . ewh2czgzt2 [ 0 ] - waypoints_data [ ( int32_T )
( rtDW . kjy5vllogw . WaypointIndex + 1.0 ) - 1 ] ; b_waypointsIn [ 1 ] = rtB
. ewh2czgzt2 [ 1 ] - waypoints_data [ ( ( int32_T ) ( rtDW . kjy5vllogw .
WaypointIndex + 1.0 ) + ix ) - 1 ] ; b_waypointsIn [ 2 ] = rtB . ewh2czgzt2 [
2 ] - waypoints_data [ ( ( int32_T ) ( rtDW . kjy5vllogw . WaypointIndex +
1.0 ) + ( ix << 1 ) ) - 1 ] ; guard2 = false ; if ( jbu3wecjlg (
b_waypointsIn ) <= 10.0 ) { guard2 = true ; } else { ml23bolgnb [ 0 ] =
waypoints_data [ ( int32_T ) ( rtDW . kjy5vllogw . WaypointIndex + 1.0 ) - 1
] - waypoints_data [ ( int32_T ) rtDW . kjy5vllogw . WaypointIndex - 1 ] ;
ml23bolgnb [ 1 ] = waypoints_data [ ( ( int32_T ) ( rtDW . kjy5vllogw .
WaypointIndex + 1.0 ) + ix ) - 1 ] - waypoints_data [ ( ( int32_T ) rtDW .
kjy5vllogw . WaypointIndex + ix ) - 1 ] ; ml23bolgnb [ 2 ] = waypoints_data [
( ( int32_T ) ( rtDW . kjy5vllogw . WaypointIndex + 1.0 ) + ( ix << 1 ) ) - 1
] - waypoints_data [ ( ( ix << 1 ) + ( int32_T ) rtDW . kjy5vllogw .
WaypointIndex ) - 1 ] ; lpi4tapkb5 = jbu3wecjlg ( ml23bolgnb ) ;
b_waypointsIn [ 0 ] = rtB . ewh2czgzt2 [ 0 ] - waypoints_data [ ( int32_T ) (
rtDW . kjy5vllogw . WaypointIndex + 1.0 ) - 1 ] ; b_waypointsIn [ 1 ] = rtB .
ewh2czgzt2 [ 1 ] - waypoints_data [ ( ( int32_T ) ( rtDW . kjy5vllogw .
WaypointIndex + 1.0 ) + ix ) - 1 ] ; b_waypointsIn [ 2 ] = rtB . ewh2czgzt2 [
2 ] - waypoints_data [ ( ( int32_T ) ( rtDW . kjy5vllogw . WaypointIndex +
1.0 ) + ( ix << 1 ) ) - 1 ] ; lambda = jbu3wecjlg ( b_waypointsIn ) ; if (
muDoubleScalarSign ( ( ( waypoints_data [ ( ( int32_T ) ( rtDW . kjy5vllogw .
WaypointIndex + 1.0 ) + ix ) - 1 ] - waypoints_data [ ( ( int32_T ) rtDW .
kjy5vllogw . WaypointIndex + ix ) - 1 ] ) / lpi4tapkb5 * ( ( rtB . ewh2czgzt2
[ 1 ] - waypoints_data [ ( ( int32_T ) ( rtDW . kjy5vllogw . WaypointIndex +
1.0 ) + ix ) - 1 ] ) / lambda ) + ( waypoints_data [ ( int32_T ) ( rtDW .
kjy5vllogw . WaypointIndex + 1.0 ) - 1 ] - waypoints_data [ ( int32_T ) rtDW
. kjy5vllogw . WaypointIndex - 1 ] ) / lpi4tapkb5 * ( ( rtB . ewh2czgzt2 [ 0
] - waypoints_data [ ( int32_T ) ( rtDW . kjy5vllogw . WaypointIndex + 1.0 )
- 1 ] ) / lambda ) ) + ( waypoints_data [ ( ( int32_T ) ( rtDW . kjy5vllogw .
WaypointIndex + 1.0 ) + ( ix << 1 ) ) - 1 ] - waypoints_data [ ( ( ix << 1 )
+ ( int32_T ) rtDW . kjy5vllogw . WaypointIndex ) - 1 ] ) / lpi4tapkb5 * ( (
rtB . ewh2czgzt2 [ 2 ] - waypoints_data [ ( ( int32_T ) ( rtDW . kjy5vllogw .
WaypointIndex + 1.0 ) + ( ix << 1 ) ) - 1 ] ) / lambda ) ) >= 0.0 ) { guard2
= true ; } else { ml23bolgnb [ 0 ] = waypoints_data [ ( int32_T ) rtDW .
kjy5vllogw . WaypointIndex - 1 ] ; jlhwiofgni = waypoints_data [ ( int32_T )
( rtDW . kjy5vllogw . WaypointIndex + 1.0 ) - 1 ] ; ml23bolgnb [ 1 ] =
waypoints_data [ ( ( int32_T ) rtDW . kjy5vllogw . WaypointIndex + ix ) - 1 ]
; dz5vdjb0hd_idx_0 = waypoints_data [ ( ( int32_T ) ( rtDW . kjy5vllogw .
WaypointIndex + 1.0 ) + ix ) - 1 ] ; ml23bolgnb [ 2 ] = waypoints_data [ ( (
ix << 1 ) + ( int32_T ) rtDW . kjy5vllogw . WaypointIndex ) - 1 ] ;
dz5vdjb0hd_idx_1 = waypoints_data [ ( ( int32_T ) ( rtDW . kjy5vllogw .
WaypointIndex + 1.0 ) + ( ix << 1 ) ) - 1 ] ; } } if ( guard2 ) { rtDW .
kjy5vllogw . WaypointIndex ++ ; q = false ; if ( rtDW . kjy5vllogw .
WaypointIndex == rtDW . kjy5vllogw . NumWaypoints ) { q = true ; } if ( q ) {
rtDW . kjy5vllogw . LastWaypointFlag = true ; rtDW . kjy5vllogw .
WaypointIndex -- ; } ml23bolgnb [ 0 ] = waypoints_data [ ( int32_T ) rtDW .
kjy5vllogw . WaypointIndex - 1 ] ; jlhwiofgni = waypoints_data [ ( int32_T )
( rtDW . kjy5vllogw . WaypointIndex + 1.0 ) - 1 ] ; ml23bolgnb [ 1 ] =
waypoints_data [ ( ( int32_T ) rtDW . kjy5vllogw . WaypointIndex + ix ) - 1 ]
; dz5vdjb0hd_idx_0 = waypoints_data [ ( ( int32_T ) ( rtDW . kjy5vllogw .
WaypointIndex + 1.0 ) + ix ) - 1 ] ; ml23bolgnb [ 2 ] = waypoints_data [ ( (
ix << 1 ) + ( int32_T ) rtDW . kjy5vllogw . WaypointIndex ) - 1 ] ;
dz5vdjb0hd_idx_1 = waypoints_data [ ( ( int32_T ) ( rtDW . kjy5vllogw .
WaypointIndex + 1.0 ) + ( ix << 1 ) ) - 1 ] ; } lambda = ( ( ( rtB .
ewh2czgzt2 [ 0 ] - ml23bolgnb [ 0 ] ) * ( jlhwiofgni - ml23bolgnb [ 0 ] ) + (
rtB . ewh2czgzt2 [ 1 ] - ml23bolgnb [ 1 ] ) * ( dz5vdjb0hd_idx_0 - ml23bolgnb
[ 1 ] ) ) + ( rtB . ewh2czgzt2 [ 2 ] - ml23bolgnb [ 2 ] ) * (
dz5vdjb0hd_idx_1 - ml23bolgnb [ 2 ] ) ) / ( ( ( jlhwiofgni - ml23bolgnb [ 0 ]
) * ( jlhwiofgni - ml23bolgnb [ 0 ] ) + ( dz5vdjb0hd_idx_0 - ml23bolgnb [ 1 ]
) * ( dz5vdjb0hd_idx_0 - ml23bolgnb [ 1 ] ) ) + ( dz5vdjb0hd_idx_1 -
ml23bolgnb [ 2 ] ) * ( dz5vdjb0hd_idx_1 - ml23bolgnb [ 2 ] ) ) ; if ( lambda
< 0.0 ) { b_waypointsIn [ 0 ] = rtB . ewh2czgzt2 [ 0 ] - ml23bolgnb [ 0 ] ;
b_waypointsIn [ 1 ] = rtB . ewh2czgzt2 [ 1 ] - ml23bolgnb [ 1 ] ;
b_waypointsIn [ 2 ] = rtB . ewh2czgzt2 [ 2 ] - ml23bolgnb [ 2 ] ; lambda =
jbu3wecjlg ( b_waypointsIn ) ; } else if ( lambda > 1.0 ) { b_waypointsIn [ 0
] = rtB . ewh2czgzt2 [ 0 ] - jlhwiofgni ; b_waypointsIn [ 1 ] = rtB .
ewh2czgzt2 [ 1 ] - dz5vdjb0hd_idx_0 ; b_waypointsIn [ 2 ] = rtB . ewh2czgzt2
[ 2 ] - dz5vdjb0hd_idx_1 ; lambda = jbu3wecjlg ( b_waypointsIn ) ; } else {
b_waypointsIn [ 0 ] = rtB . ewh2czgzt2 [ 0 ] - ( ( jlhwiofgni - ml23bolgnb [
0 ] ) * lambda + ml23bolgnb [ 0 ] ) ; b_waypointsIn [ 1 ] = rtB . ewh2czgzt2
[ 1 ] - ( ( dz5vdjb0hd_idx_0 - ml23bolgnb [ 1 ] ) * lambda + ml23bolgnb [ 1 ]
) ; b_waypointsIn [ 2 ] = rtB . ewh2czgzt2 [ 2 ] - ( ( dz5vdjb0hd_idx_1 -
ml23bolgnb [ 2 ] ) * lambda + ml23bolgnb [ 2 ] ) ; lambda = jbu3wecjlg (
b_waypointsIn ) ; } if ( rtDW . kjy5vllogw . LastWaypointFlag ) { lambda = (
( ( rtB . ewh2czgzt2 [ 0 ] - ml23bolgnb [ 0 ] ) * ( jlhwiofgni - ml23bolgnb [
0 ] ) + ( rtB . ewh2czgzt2 [ 1 ] - ml23bolgnb [ 1 ] ) * ( dz5vdjb0hd_idx_0 -
ml23bolgnb [ 1 ] ) ) + ( rtB . ewh2czgzt2 [ 2 ] - ml23bolgnb [ 2 ] ) * (
dz5vdjb0hd_idx_1 - ml23bolgnb [ 2 ] ) ) / ( ( ( jlhwiofgni - ml23bolgnb [ 0 ]
) * ( jlhwiofgni - ml23bolgnb [ 0 ] ) + ( dz5vdjb0hd_idx_0 - ml23bolgnb [ 1 ]
) * ( dz5vdjb0hd_idx_0 - ml23bolgnb [ 1 ] ) ) + ( dz5vdjb0hd_idx_1 -
ml23bolgnb [ 2 ] ) * ( dz5vdjb0hd_idx_1 - ml23bolgnb [ 2 ] ) ) ;
b_waypointsIn [ 0 ] = rtB . ewh2czgzt2 [ 0 ] - ( ( jlhwiofgni - ml23bolgnb [
0 ] ) * lambda + ml23bolgnb [ 0 ] ) ; b_waypointsIn [ 1 ] = rtB . ewh2czgzt2
[ 1 ] - ( ( dz5vdjb0hd_idx_0 - ml23bolgnb [ 1 ] ) * lambda + ml23bolgnb [ 1 ]
) ; b_waypointsIn [ 2 ] = rtB . ewh2czgzt2 [ 2 ] - ( ( dz5vdjb0hd_idx_1 -
ml23bolgnb [ 2 ] ) * lambda + ml23bolgnb [ 2 ] ) ; lambda = jbu3wecjlg (
b_waypointsIn ) ; } y2 = muDoubleScalarAbs ( lambda ) ; if (
muDoubleScalarIsInf ( y2 ) || muDoubleScalarIsNaN ( y2 ) ) { x2 = ( rtNaN ) ;
} else if ( y2 < 4.4501477170144028E-308 ) { x2 = 4.94065645841247E-324 ; }
else { frexp ( y2 , & b_exponent ) ; x2 = ldexp ( 1.0 , b_exponent - 53 ) ; }
y2 = muDoubleScalarAbs ( lambda ) ; if ( muDoubleScalarIsInf ( y2 ) ||
muDoubleScalarIsNaN ( y2 ) ) { y2 = ( rtNaN ) ; } else if ( y2 <
4.4501477170144028E-308 ) { y2 = 4.94065645841247E-324 ; } else { frexp ( y2
, & b_exponent_p ) ; y2 = ldexp ( 1.0 , b_exponent_p - 53 ) ; } if ( rtDW .
kjy5vllogw . LookaheadDistance <= muDoubleScalarMax ( muDoubleScalarSqrt ( x2
) , 5.0 * y2 ) + lambda ) { rtDW . kjy5vllogw . LookaheadDistance = rtDW .
kjy5vllogw . LookaheadFactor * lambda ; } lambda = ( ( jlhwiofgni -
ml23bolgnb [ 0 ] ) * ( jlhwiofgni - ml23bolgnb [ 0 ] ) + ( dz5vdjb0hd_idx_0 -
ml23bolgnb [ 1 ] ) * ( dz5vdjb0hd_idx_0 - ml23bolgnb [ 1 ] ) ) + (
dz5vdjb0hd_idx_1 - ml23bolgnb [ 2 ] ) * ( dz5vdjb0hd_idx_1 - ml23bolgnb [ 2 ]
) ; x2 = ( ( ( jlhwiofgni - ml23bolgnb [ 0 ] ) * ( ml23bolgnb [ 0 ] - rtB .
ewh2czgzt2 [ 0 ] ) + ( dz5vdjb0hd_idx_0 - ml23bolgnb [ 1 ] ) * ( ml23bolgnb [
1 ] - rtB . ewh2czgzt2 [ 1 ] ) ) + ( dz5vdjb0hd_idx_1 - ml23bolgnb [ 2 ] ) *
( ml23bolgnb [ 2 ] - rtB . ewh2czgzt2 [ 2 ] ) ) * 2.0 ; y2 = x2 * x2 - ( ( (
( ml23bolgnb [ 0 ] - rtB . ewh2czgzt2 [ 0 ] ) * ( ml23bolgnb [ 0 ] - rtB .
ewh2czgzt2 [ 0 ] ) + ( ml23bolgnb [ 1 ] - rtB . ewh2czgzt2 [ 1 ] ) * (
ml23bolgnb [ 1 ] - rtB . ewh2czgzt2 [ 1 ] ) ) + ( ml23bolgnb [ 2 ] - rtB .
ewh2czgzt2 [ 2 ] ) * ( ml23bolgnb [ 2 ] - rtB . ewh2czgzt2 [ 2 ] ) ) - rtDW .
kjy5vllogw . LookaheadDistance * rtDW . kjy5vllogw . LookaheadDistance ) * (
4.0 * lambda ) ; lambda = muDoubleScalarMax ( ( - x2 + muDoubleScalarSqrt (
y2 ) ) / 2.0 / lambda , ( - x2 - muDoubleScalarSqrt ( y2 ) ) / 2.0 / lambda )
; jlhwiofgni = ( 1.0 - lambda ) * ml23bolgnb [ 0 ] + lambda * jlhwiofgni ;
dz5vdjb0hd_idx_0 = ( 1.0 - lambda ) * ml23bolgnb [ 1 ] + lambda *
dz5vdjb0hd_idx_0 ; rtB . lokluenstr = muDoubleScalarAtan2 ( dz5vdjb0hd_idx_0
- rtB . ewh2czgzt2 [ 1 ] , jlhwiofgni - rtB . ewh2czgzt2 [ 0 ] ) ; rtDW .
kjy5vllogw . LastWaypointFlag = false ; } } rtDW . ih0gu0a4vg = pq4ibxz3zz ;
bhu1io5c4t [ 0 ] = rtB . ewh2czgzt2 [ 0 ] - rtP . Constant3_Value [ ( int32_T
) rtB . jd2mqrgdxl [ 1 ] - 1 ] ; bhu1io5c4t [ 1 ] = rtB . ewh2czgzt2 [ 1 ] -
rtP . Constant3_Value [ ( int32_T ) rtB . jd2mqrgdxl [ 1 ] + 5 ] ; lpi4tapkb5
= n12li4ectl ( bhu1io5c4t ) ; T [ 0 ] = bhu1io5c4t [ 0 ] / lpi4tapkb5 +
muDoubleScalarCos ( rtB . lokluenstr ) ; T [ 1 ] = bhu1io5c4t [ 1 ] /
lpi4tapkb5 + muDoubleScalarSin ( rtB . lokluenstr ) ; lpi4tapkb5 = n12li4ectl
( T ) ; T [ 0 ] /= lpi4tapkb5 ; T [ 1 ] /= lpi4tapkb5 ; lambda =
muDoubleScalarAtan2 ( T [ 1 ] , T [ 0 ] ) ; i2 = 0 ; if ( ( lambda < -
3.1415926535897931 ) || ( lambda > 3.1415926535897931 ) ) { for ( idx = 0 ;
idx < 1 ; idx ++ ) { i2 ++ ; } } if ( i2 - 1 >= 0 ) { if (
muDoubleScalarIsNaN ( lambda + 3.1415926535897931 ) || muDoubleScalarIsInf (
lambda + 3.1415926535897931 ) ) { y2 = ( rtNaN ) ; } else if ( lambda +
3.1415926535897931 == 0.0 ) { y2 = 0.0 ; } else { y2 = muDoubleScalarRem (
lambda + 3.1415926535897931 , 6.2831853071795862 ) ; q = ( y2 == 0.0 ) ; if (
! q ) { x2 = muDoubleScalarAbs ( ( lambda + 3.1415926535897931 ) /
6.2831853071795862 ) ; q = ! ( muDoubleScalarAbs ( x2 - muDoubleScalarFloor (
x2 + 0.5 ) ) > 2.2204460492503131E-16 * x2 ) ; } if ( q ) { y2 = 0.0 ; } else
if ( lambda + 3.1415926535897931 < 0.0 ) { y2 += 6.2831853071795862 ; } }
varargin_1_data = y2 ; } if ( i2 - 1 >= 0 ) { tmp_data_p = ( (
varargin_1_data == 0.0 ) && ( lambda + 3.1415926535897931 > 0.0 ) ) ; } if (
tmp_data_p && ( i2 - 1 >= 0 ) ) { varargin_1_data = 6.2831853071795862 ; } i2
= 0 ; if ( ( lambda < - 3.1415926535897931 ) || ( lambda > 3.1415926535897931
) ) { for ( idx = 0 ; idx < 1 ; idx ++ ) { lambda = varargin_1_data -
3.1415926535897931 ; i2 ++ ; } } rtB . c04goqj2sf = lambda ; if (
ssIsModeUpdateTimeStep ( rtS ) ) { rtDW . mqsusrzct3 = ( rtB . jd2mqrgdxl [ 0
] > rtP . Switch_Threshold ) ; } if ( rtDW . mqsusrzct3 ) { rtB . amv5xbxcgx
= rtB . c04goqj2sf ; } else { rtB . amv5xbxcgx = rtB . lokluenstr ; } rtB .
ctr2i5cu0j = rtB . amv5xbxcgx - rtB . ffht1uab1p [ 2 ] ; if ( ssIsSampleHit (
rtS , 1 , 0 ) ) { rtB . pvv2cmskei = ( rtP . DiscretePIDController2_D * rtB .
ctr2i5cu0j - rtDW . hx53qo0tyb ) * rtP . DiscretePIDController2_N ; rtB .
gst3ni0ebl = ( rtP . DiscretePIDController2_P * rtB . ctr2i5cu0j + rtDW .
ko2emyti4i ) + rtB . pvv2cmskei ; } rtB . agbvtgnrv4 = rtB . gst3ni0ebl - rtB
. ffht1uab1p [ 0 ] ; if ( ssIsSampleHit ( rtS , 1 , 0 ) ) { rtB . hjhp5kuoxj
= ( rtP . DiscretePIDController3_D * rtB . agbvtgnrv4 - rtDW . bsuso3aou5 ) *
rtP . DiscretePIDController3_N ; lambda = ( rtP . DiscretePIDController3_P *
rtB . agbvtgnrv4 + rtDW . hoflvlpyvq ) + rtB . hjhp5kuoxj ; if ( lambda > rtP
. DiscretePIDController3_UpperSaturationLimit ) { rtB . glpu5b5wth = rtP .
DiscretePIDController3_UpperSaturationLimit ; } else if ( lambda < rtP .
DiscretePIDController3_LowerSaturationLimit ) { rtB . glpu5b5wth = rtP .
DiscretePIDController3_LowerSaturationLimit ; } else { rtB . glpu5b5wth =
lambda ; } } rtB . ej2atzfwl0 [ 0 ] = rtP . R2D3_Gain * rtB . ffht1uab1p [ 0
] ; rtB . ej2atzfwl0 [ 1 ] = rtP . R2D3_Gain * rtB . ffht1uab1p [ 1 ] ; rtB .
ej2atzfwl0 [ 2 ] = rtP . R2D3_Gain * rtB . ffht1uab1p [ 2 ] ; if (
ssIsSampleHit ( rtS , 1 , 0 ) ) { } khdw5q2wy4 [ 0 ] = muDoubleScalarCos (
rtB . ffht1uab1p [ 2 ] ) * muDoubleScalarCos ( rtB . ffht1uab1p [ 1 ] ) ;
khdw5q2wy4 [ 3 ] = muDoubleScalarCos ( rtB . ffht1uab1p [ 2 ] ) *
muDoubleScalarSin ( rtB . ffht1uab1p [ 1 ] ) * muDoubleScalarSin ( rtB .
ffht1uab1p [ 0 ] ) - muDoubleScalarSin ( rtB . ffht1uab1p [ 2 ] ) *
muDoubleScalarCos ( rtB . ffht1uab1p [ 0 ] ) ; khdw5q2wy4 [ 6 ] =
muDoubleScalarCos ( rtB . ffht1uab1p [ 2 ] ) * muDoubleScalarSin ( rtB .
ffht1uab1p [ 1 ] ) * muDoubleScalarCos ( rtB . ffht1uab1p [ 0 ] ) +
muDoubleScalarSin ( rtB . ffht1uab1p [ 2 ] ) * muDoubleScalarSin ( rtB .
ffht1uab1p [ 0 ] ) ; khdw5q2wy4 [ 1 ] = muDoubleScalarSin ( rtB . ffht1uab1p
[ 2 ] ) * muDoubleScalarCos ( rtB . ffht1uab1p [ 1 ] ) ; khdw5q2wy4 [ 4 ] =
muDoubleScalarSin ( rtB . ffht1uab1p [ 2 ] ) * muDoubleScalarSin ( rtB .
ffht1uab1p [ 1 ] ) * muDoubleScalarSin ( rtB . ffht1uab1p [ 0 ] ) +
muDoubleScalarCos ( rtB . ffht1uab1p [ 2 ] ) * muDoubleScalarCos ( rtB .
ffht1uab1p [ 0 ] ) ; khdw5q2wy4 [ 7 ] = muDoubleScalarSin ( rtB . ffht1uab1p
[ 2 ] ) * muDoubleScalarSin ( rtB . ffht1uab1p [ 1 ] ) * muDoubleScalarCos (
rtB . ffht1uab1p [ 0 ] ) - muDoubleScalarCos ( rtB . ffht1uab1p [ 2 ] ) *
muDoubleScalarSin ( rtB . ffht1uab1p [ 0 ] ) ; khdw5q2wy4 [ 2 ] = -
muDoubleScalarSin ( rtB . ffht1uab1p [ 1 ] ) ; khdw5q2wy4 [ 5 ] =
muDoubleScalarCos ( rtB . ffht1uab1p [ 1 ] ) * muDoubleScalarSin ( rtB .
ffht1uab1p [ 0 ] ) ; khdw5q2wy4 [ 8 ] = muDoubleScalarCos ( rtB . ffht1uab1p
[ 1 ] ) * muDoubleScalarCos ( rtB . ffht1uab1p [ 0 ] ) ; lambda = rtB .
av1jt30k31 [ 1 ] ; y2 = rtB . av1jt30k31 [ 0 ] ; x2 = rtB . av1jt30k31 [ 2 ]
; for ( idx = 0 ; idx < 3 ; idx ++ ) { rtB . ldelskn1jo [ idx ] = (
khdw5q2wy4 [ idx + 3 ] * lambda + khdw5q2wy4 [ idx ] * y2 ) + khdw5q2wy4 [
idx + 6 ] * x2 ; } if ( rtP . ManualSwitch1_CurrentSetting == 1 ) {
ml23bolgnb [ 0 ] = rtP . nowind_Value [ 0 ] ; ml23bolgnb [ 1 ] = rtP .
nowind_Value [ 1 ] ; ml23bolgnb [ 2 ] = rtP . nowind_Value [ 2 ] ; } else {
lpi4tapkb5 = rtP . _Gain * rt_Lookup ( & rtP . WindX_XData [ 0 ] , 3002 , rtB
. ewh2czgzt2 [ 2 ] , & rtP . WindX_YData [ 0 ] ) ; Constant_Value_ibkcrpfjyo
= rtP . u_Gain_lth2troxad * rt_Lookup ( & rtP . WindY_XData [ 0 ] , 3002 ,
rtB . ewh2czgzt2 [ 2 ] , & rtP . WindY_YData [ 0 ] ) ; x2 = rtP . u_Gain *
rt_Lookup ( & rtP . WindZ_XData [ 0 ] , 3002 , rtB . ewh2czgzt2 [ 2 ] , & rtP
. WindZ_YData [ 0 ] ) ; for ( idx = 0 ; idx < 3 ; idx ++ ) { ml23bolgnb [ idx
] = ( rtP . MatrixGain6_Gain [ idx + 3 ] * Constant_Value_ibkcrpfjyo + rtP .
MatrixGain6_Gain [ idx ] * lpi4tapkb5 ) + rtP . MatrixGain6_Gain [ idx + 6 ]
* x2 ; } } khdw5q2wy4 [ 0 ] = muDoubleScalarCos ( rtB . ffht1uab1p [ 2 ] ) *
muDoubleScalarCos ( rtB . ffht1uab1p [ 1 ] ) ; khdw5q2wy4 [ 1 ] =
muDoubleScalarCos ( rtB . ffht1uab1p [ 2 ] ) * muDoubleScalarSin ( rtB .
ffht1uab1p [ 1 ] ) * muDoubleScalarSin ( rtB . ffht1uab1p [ 0 ] ) -
muDoubleScalarSin ( rtB . ffht1uab1p [ 2 ] ) * muDoubleScalarCos ( rtB .
ffht1uab1p [ 0 ] ) ; khdw5q2wy4 [ 2 ] = muDoubleScalarCos ( rtB . ffht1uab1p
[ 2 ] ) * muDoubleScalarSin ( rtB . ffht1uab1p [ 1 ] ) * muDoubleScalarCos (
rtB . ffht1uab1p [ 0 ] ) + muDoubleScalarSin ( rtB . ffht1uab1p [ 2 ] ) *
muDoubleScalarSin ( rtB . ffht1uab1p [ 0 ] ) ; khdw5q2wy4 [ 3 ] =
muDoubleScalarSin ( rtB . ffht1uab1p [ 2 ] ) * muDoubleScalarCos ( rtB .
ffht1uab1p [ 1 ] ) ; khdw5q2wy4 [ 4 ] = muDoubleScalarSin ( rtB . ffht1uab1p
[ 2 ] ) * muDoubleScalarSin ( rtB . ffht1uab1p [ 1 ] ) * muDoubleScalarSin (
rtB . ffht1uab1p [ 0 ] ) + muDoubleScalarCos ( rtB . ffht1uab1p [ 2 ] ) *
muDoubleScalarCos ( rtB . ffht1uab1p [ 0 ] ) ; khdw5q2wy4 [ 5 ] =
muDoubleScalarSin ( rtB . ffht1uab1p [ 2 ] ) * muDoubleScalarSin ( rtB .
ffht1uab1p [ 1 ] ) * muDoubleScalarCos ( rtB . ffht1uab1p [ 0 ] ) -
muDoubleScalarCos ( rtB . ffht1uab1p [ 2 ] ) * muDoubleScalarSin ( rtB .
ffht1uab1p [ 0 ] ) ; khdw5q2wy4 [ 6 ] = - muDoubleScalarSin ( rtB .
ffht1uab1p [ 1 ] ) ; khdw5q2wy4 [ 7 ] = muDoubleScalarCos ( rtB . ffht1uab1p
[ 1 ] ) * muDoubleScalarSin ( rtB . ffht1uab1p [ 0 ] ) ; khdw5q2wy4 [ 8 ] =
muDoubleScalarCos ( rtB . ffht1uab1p [ 1 ] ) * muDoubleScalarCos ( rtB .
ffht1uab1p [ 0 ] ) ; lpi4tapkb5 = rtB . ldelskn1jo [ 0 ] - ml23bolgnb [ 0 ] ;
Constant_Value_ibkcrpfjyo = rtB . ldelskn1jo [ 1 ] - ml23bolgnb [ 1 ] ; x2 =
rtB . ldelskn1jo [ 2 ] - ml23bolgnb [ 2 ] ; for ( idx = 0 ; idx < 3 ; idx ++
) { ml23bolgnb [ idx ] = ( khdw5q2wy4 [ idx + 3 ] * Constant_Value_ibkcrpfjyo
+ khdw5q2wy4 [ idx ] * lpi4tapkb5 ) + khdw5q2wy4 [ idx + 6 ] * x2 ; } rtB .
ljudbp5sfm = muDoubleScalarAtan ( ml23bolgnb [ 2 ] / ml23bolgnb [ 0 ] ) * rtP
. R2D2_Gain ; rtB . mhbhj1bpzc = muDoubleScalarAtan ( ml23bolgnb [ 1 ] /
muDoubleScalarSqrt ( muDoubleScalarPower ( ml23bolgnb [ 0 ] , 2.0 ) +
muDoubleScalarPower ( ml23bolgnb [ 2 ] , 2.0 ) ) ) * rtP . R2D1_Gain ;
bhu1io5c4t [ 0 ] = rtP . D2R_Gain * rtB . ljudbp5sfm ; bhu1io5c4t [ 1 ] = rtP
. D2R_Gain * rtB . mhbhj1bpzc ; lambda = rtP . Deg2Rad_Gain * rtB .
ljudbp5sfm ; if ( ssIsSampleHit ( rtS , 1 , 0 ) ) { oxy5kmdygt = rtP .
Deg2Rad2_Gain * rtB . m30uwutjd5 ; rtB . ezi3wqgg1t = rtP . CLDe * oxy5kmdygt
* rtP . Gain1_Gain ; } dz5vdjb0hd_idx_0 = rtX . ajbdf0rme2 [ 0 ] ;
dz5vdjb0hd_idx_1 = rtX . ajbdf0rme2 [ 1 ] ; an2j0hkqbl_idx_2 = rtX .
ajbdf0rme2 [ 2 ] ; y2 = ( muDoubleScalarPower ( ml23bolgnb [ 0 ] , 2.0 ) +
muDoubleScalarPower ( ml23bolgnb [ 1 ] , 2.0 ) ) + muDoubleScalarPower (
ml23bolgnb [ 2 ] , 2.0 ) ; rtB . j4csspowr5 = muDoubleScalarSqrt ( y2 ) ; rtB
. es5qqkki5l = ( ( ( rtP . CLa * lambda * rtP . Gain4_Gain + rtP . CL0 ) +
rtB . ebpprftokq ) + rtB . ezi3wqgg1t ) + rtX . ajbdf0rme2 [ 1 ] * rtP .
chord / rtB . j4csspowr5 * rtP . CLq ; rtB . lda1u2jc0p = rtB . ewh2czgzt2 [
2 ] - rtP . span ; if ( ssIsModeUpdateTimeStep ( rtS ) ) { rtDW . gzmh1uauzr
= ( rtB . lda1u2jc0p > rtP . Switch_Threshold_hwgs5rnbxi ) ; } if ( rtDW .
gzmh1uauzr ) { x2 = rtB . es5qqkki5l ; } else { x2 = rtB . ewh2czgzt2 [ 2 ] ;
if ( ssIsMajorTimeStep ( rtS ) ) { if ( rtDW . ljddttc2rd != 0 ) {
ssSetBlockStateForSolverChangedAtMajorStep ( rtS ) ;
ssSetContTimeOutputInconsistentWithStateAtMajorStep ( rtS ) ; rtDW .
ljddttc2rd = 0 ; } } else if ( rtB . ewh2czgzt2 [ 2 ] < 0.0 ) { x2 = 0.0 ;
rtDW . ljddttc2rd = 1 ; } rtB . jhen0kkdwf = ( muDoubleScalarLog ( x2 ) * rtP
. Constant1_Value_g5jniqvvpl + rtP . Constant_Value_cqthaabju2 ) + rtB .
es5qqkki5l ; x2 = rtB . jhen0kkdwf ; } if ( ssIsModeUpdateTimeStep ( rtS ) )
{ rtDW . n33rcmsjab = rtB . ewh2czgzt2 [ 2 ] >= rtP . ISA_hmax ? 1 : rtB .
ewh2czgzt2 [ 2 ] > rtP . Limitaltitude_LowerSat ? 0 : - 1 ; } jlhwiofgni = (
rtP . ISA_T0 - ( rtDW . n33rcmsjab == 1 ? rtP . ISA_hmax : rtDW . n33rcmsjab
== - 1 ? rtP . Limitaltitude_LowerSat : rtB . ewh2czgzt2 [ 2 ] ) * rtP .
ISA_lapse ) * ( 1.0 / rtP . ISA_T0 ) ; if ( jlhwiofgni < 0.0 ) { lpi4tapkb5 =
- muDoubleScalarPower ( - jlhwiofgni , 5.2613240418118465 ) ; } else {
lpi4tapkb5 = muDoubleScalarPower ( jlhwiofgni , 5.2613240418118465 ) ; } y2 =
lpi4tapkb5 / jlhwiofgni * rtP . ISA_rho0 * y2 * rtP . Constant_Value * rtP .
span * rtP . chord ; jlhwiofgni = rtP . Deg2Rad1_Gain * rtB . mhbhj1bpzc ; if
( ssIsSampleHit ( rtS , 1 , 0 ) ) { lpi4tapkb5 = rtP . Deg2Rad3_Gain * rtB .
glpu5b5wth ; rtB . hxc25hdudb = rtP . ClDa * lpi4tapkb5 * rtP . Gain3_Gain ;
rtB . crwpdhv3lp = rtP . CmDe * oxy5kmdygt * rtP . Gain1_Gain_dpix5mof3i ;
rtB . aq2in4etwi = rtP . CnDa * lpi4tapkb5 * rtP . Gain3_Gain_gjw5qqxglj ; }
khdw5q2wy4 [ 0 ] = muDoubleScalarCos ( bhu1io5c4t [ 0 ] ) * muDoubleScalarCos
( bhu1io5c4t [ 1 ] ) ; khdw5q2wy4 [ 1 ] = muDoubleScalarSin ( bhu1io5c4t [ 1
] ) ; khdw5q2wy4 [ 2 ] = muDoubleScalarSin ( bhu1io5c4t [ 0 ] ) *
muDoubleScalarCos ( bhu1io5c4t [ 1 ] ) ; khdw5q2wy4 [ 3 ] = -
muDoubleScalarCos ( bhu1io5c4t [ 0 ] ) * muDoubleScalarSin ( bhu1io5c4t [ 1 ]
) ; khdw5q2wy4 [ 4 ] = muDoubleScalarCos ( bhu1io5c4t [ 1 ] ) ; khdw5q2wy4 [
5 ] = - muDoubleScalarSin ( bhu1io5c4t [ 0 ] ) * muDoubleScalarSin (
bhu1io5c4t [ 1 ] ) ; khdw5q2wy4 [ 6 ] = - muDoubleScalarSin ( bhu1io5c4t [ 0
] ) ; khdw5q2wy4 [ 7 ] = 0.0 ; khdw5q2wy4 [ 8 ] = muDoubleScalarCos (
bhu1io5c4t [ 0 ] ) ; lpi4tapkb5 = ( x2 * x2 * rtP . Apolar + rtP . CD0 ) *
rtP . Gain_Gain * y2 * rtP . Gain_Gain_mqy02r1o31 ; Constant_Value_ibkcrpfjyo
= ( rtP . CYb * jlhwiofgni * rtP . Gain1_Gain_nqisqcqfrw + rtB . i5zbjzuhhx )
* y2 * rtP . Gain1_Gain_ftpoywohzv ; x2 = rtP . Gain1_Gain_e2mkjz4tqt * x2 *
y2 * rtP . Gain2_Gain ; for ( idx = 0 ; idx < 3 ; idx ++ ) { b_waypointsIn [
idx ] = ( khdw5q2wy4 [ idx + 3 ] * Constant_Value_ibkcrpfjyo + khdw5q2wy4 [
idx ] * lpi4tapkb5 ) + khdw5q2wy4 [ idx + 6 ] * x2 ; } khdw5q2wy4 [ 0 ] =
muDoubleScalarCos ( rtB . ffht1uab1p [ 2 ] ) * muDoubleScalarCos ( rtB .
ffht1uab1p [ 1 ] ) ; khdw5q2wy4 [ 1 ] = muDoubleScalarCos ( rtB . ffht1uab1p
[ 2 ] ) * muDoubleScalarSin ( rtB . ffht1uab1p [ 1 ] ) * muDoubleScalarSin (
rtB . ffht1uab1p [ 0 ] ) - muDoubleScalarSin ( rtB . ffht1uab1p [ 2 ] ) *
muDoubleScalarCos ( rtB . ffht1uab1p [ 0 ] ) ; khdw5q2wy4 [ 2 ] =
muDoubleScalarCos ( rtB . ffht1uab1p [ 2 ] ) * muDoubleScalarSin ( rtB .
ffht1uab1p [ 1 ] ) * muDoubleScalarCos ( rtB . ffht1uab1p [ 0 ] ) +
muDoubleScalarSin ( rtB . ffht1uab1p [ 2 ] ) * muDoubleScalarSin ( rtB .
ffht1uab1p [ 0 ] ) ; khdw5q2wy4 [ 3 ] = muDoubleScalarSin ( rtB . ffht1uab1p
[ 2 ] ) * muDoubleScalarCos ( rtB . ffht1uab1p [ 1 ] ) ; khdw5q2wy4 [ 4 ] =
muDoubleScalarSin ( rtB . ffht1uab1p [ 2 ] ) * muDoubleScalarSin ( rtB .
ffht1uab1p [ 1 ] ) * muDoubleScalarSin ( rtB . ffht1uab1p [ 0 ] ) +
muDoubleScalarCos ( rtB . ffht1uab1p [ 2 ] ) * muDoubleScalarCos ( rtB .
ffht1uab1p [ 0 ] ) ; khdw5q2wy4 [ 5 ] = muDoubleScalarSin ( rtB . ffht1uab1p
[ 2 ] ) * muDoubleScalarSin ( rtB . ffht1uab1p [ 1 ] ) * muDoubleScalarCos (
rtB . ffht1uab1p [ 0 ] ) - muDoubleScalarCos ( rtB . ffht1uab1p [ 2 ] ) *
muDoubleScalarSin ( rtB . ffht1uab1p [ 0 ] ) ; khdw5q2wy4 [ 6 ] = -
muDoubleScalarSin ( rtB . ffht1uab1p [ 1 ] ) ; khdw5q2wy4 [ 7 ] =
muDoubleScalarCos ( rtB . ffht1uab1p [ 1 ] ) * muDoubleScalarSin ( rtB .
ffht1uab1p [ 0 ] ) ; khdw5q2wy4 [ 8 ] = muDoubleScalarCos ( rtB . ffht1uab1p
[ 1 ] ) * muDoubleScalarCos ( rtB . ffht1uab1p [ 0 ] ) ; oxy5kmdygt = rtP .
Weightmatrix_Value [ 1 ] ; x2 = rtP . Weightmatrix_Value [ 0 ] ; lpi4tapkb5 =
rtP . Weightmatrix_Value [ 2 ] ; for ( idx = 0 ; idx < 3 ; idx ++ ) { tmp [
idx ] = ( khdw5q2wy4 [ idx + 3 ] * oxy5kmdygt + khdw5q2wy4 [ idx ] * x2 ) +
khdw5q2wy4 [ idx + 6 ] * lpi4tapkb5 ; } khdw5q2wy4 [ 0 ] = muDoubleScalarCos
( bhu1io5c4t [ 0 ] ) * muDoubleScalarCos ( bhu1io5c4t [ 1 ] ) ; khdw5q2wy4 [
1 ] = muDoubleScalarSin ( bhu1io5c4t [ 1 ] ) ; khdw5q2wy4 [ 2 ] =
muDoubleScalarSin ( bhu1io5c4t [ 0 ] ) * muDoubleScalarCos ( bhu1io5c4t [ 1 ]
) ; khdw5q2wy4 [ 3 ] = - muDoubleScalarCos ( bhu1io5c4t [ 0 ] ) *
muDoubleScalarSin ( bhu1io5c4t [ 1 ] ) ; khdw5q2wy4 [ 4 ] = muDoubleScalarCos
( bhu1io5c4t [ 1 ] ) ; khdw5q2wy4 [ 5 ] = - muDoubleScalarSin ( bhu1io5c4t [
0 ] ) * muDoubleScalarSin ( bhu1io5c4t [ 1 ] ) ; khdw5q2wy4 [ 6 ] = -
muDoubleScalarSin ( bhu1io5c4t [ 0 ] ) ; khdw5q2wy4 [ 7 ] = 0.0 ; khdw5q2wy4
[ 8 ] = muDoubleScalarCos ( bhu1io5c4t [ 0 ] ) ; lpi4tapkb5 = ( ( ( ( rtP .
Clb * jlhwiofgni * rtP . Gain4_Gain_ljfjkw1syf + rtB . hxc25hdudb ) + rtB .
kwxg3amuly ) + dz5vdjb0hd_idx_0 * rtP . Cmq1_Value * rtP . span / rtB .
j4csspowr5 * rtB . b1n2m12ywt ) + an2j0hkqbl_idx_2 * rtP .
Cmq1_Value_dqzexw0fvg * rtP . span / rtB . j4csspowr5 * rtB . bx1plzk1jh ) *
y2 * rtP . span * rtP . Gain3_Gain_jhgwt4xcre ; Constant_Value_ibkcrpfjyo = (
( ( ( rtP . Cma * lambda * rtP . Gain4_Gain_fd51wengpv + rtP . Cm0 ) + rtB .
b152zcpgbp ) + rtB . crwpdhv3lp ) + dz5vdjb0hd_idx_1 * rtP . chord / rtB .
j4csspowr5 * rtB . l0yxgnvu5h ) * y2 * rtP . chord * rtP .
Gain4_Gain_ohs20inw3v ; x2 = ( ( ( ( rtP . Cnb * jlhwiofgni * rtP .
Gain4_Gain_n3uynydxab + rtB . aq2in4etwi ) + rtB . eej5dfdnuw ) +
dz5vdjb0hd_idx_0 * rtP . Cmq1_Value_hei4fwlj0u * rtP . span / rtB .
j4csspowr5 * rtB . leydlmjwwh ) + an2j0hkqbl_idx_2 * rtP .
Cmq1_Value_acz4kovyrj * rtP . span / rtB . j4csspowr5 * rtB . exx2dadn0g ) *
y2 * rtP . span * rtP . Gain5_Gain ; for ( idx = 0 ; idx < 3 ; idx ++ ) { rtB
. lg5hpscltc [ idx ] = b_waypointsIn [ idx ] + tmp [ idx ] ; rtB . lg5hpscltc
[ idx + 3 ] = ( khdw5q2wy4 [ idx + 3 ] * Constant_Value_ibkcrpfjyo +
khdw5q2wy4 [ idx ] * lpi4tapkb5 ) + khdw5q2wy4 [ idx + 6 ] * x2 ; } if (
ssIsSampleHit ( rtS , 1 , 0 ) ) { rtB . h1saod1n1q = rtP . Throttle2RPM_Gain
* rtB . ncckp5giye * 0.00146 - 4.088 ; } rtB . f4k3dw2w0v = rtP .
mps2fps_Gain * rtB . j4csspowr5 ; if ( ssIsModeUpdateTimeStep ( rtS ) ) {
rtDW . jye5a0flet [ 0 ] = rtB . h1saod1n1q >= rtP . Saturation_UpperSat ? 1 :
rtB . h1saod1n1q > rtP . Saturation_LowerSat ? 0 : - 1 ; rtDW . jye5a0flet [
1 ] = rtB . f4k3dw2w0v >= rtP . Saturation_UpperSat ? 1 : rtB . f4k3dw2w0v >
rtP . Saturation_LowerSat ? 0 : - 1 ; } bhu1io5c4t [ 0 ] = rtDW . jye5a0flet
[ 0 ] == 1 ? rtP . Saturation_UpperSat : rtDW . jye5a0flet [ 0 ] == - 1 ? rtP
. Saturation_LowerSat : rtB . h1saod1n1q ; if ( bhu1io5c4t [ 0 ] < 0.0 ) {
lpi4tapkb5 = - muDoubleScalarSqrt ( - bhu1io5c4t [ 0 ] ) ; } else {
lpi4tapkb5 = muDoubleScalarSqrt ( bhu1io5c4t [ 0 ] ) ; } rtB . m5psfntta4 = (
bhu1io5c4t [ 0 ] - ( rtDW . jye5a0flet [ 1 ] == 1 ? rtP . Saturation_UpperSat
: rtDW . jye5a0flet [ 1 ] == - 1 ? rtP . Saturation_LowerSat : rtB .
f4k3dw2w0v ) * 0.0238 * lpi4tapkb5 ) * rtP . lbs2kg_Gain * rtP . ISA_g ; if (
ssIsModeUpdateTimeStep ( rtS ) ) { rtDW . ejk4nu5buq = rtB . m5psfntta4 >=
rtP . Saturation1_UpperSat ? 1 : rtB . m5psfntta4 > rtP .
Saturation1_LowerSat ? 0 : - 1 ; } rtB . m3gvnxject = rtDW . ejk4nu5buq == 1
? rtP . Saturation1_UpperSat : rtDW . ejk4nu5buq == - 1 ? rtP .
Saturation1_LowerSat : rtB . m5psfntta4 ; if ( ssIsSampleHit ( rtS , 1 , 0 )
) { } rtB . l0izt2oa2m = muDoubleScalarSqrt ( muDoubleScalarPower ( rtB .
ldelskn1jo [ 0 ] , 2.0 ) + muDoubleScalarPower ( rtB . ldelskn1jo [ 1 ] , 2.0
) ) ; if ( ssIsSampleHit ( rtS , 1 , 0 ) ) { } rtB . jfnjrao1g3 = rtB .
ldelskn1jo [ 2 ] ; if ( ssIsSampleHit ( rtS , 1 , 0 ) ) { } rtB . fwckhvycxa
[ 0 ] = rtP . R2D2_Gain_jrhz3pfqfv * dz5vdjb0hd_idx_0 ; rtB . fwckhvycxa [ 1
] = rtP . R2D2_Gain_jrhz3pfqfv * dz5vdjb0hd_idx_1 ; rtB . fwckhvycxa [ 2 ] =
rtP . R2D2_Gain_jrhz3pfqfv * an2j0hkqbl_idx_2 ; if ( ssIsSampleHit ( rtS , 1
, 0 ) ) { } for ( idx = 0 ; idx < 3 ; idx ++ ) { khdw5q2wy4 [ 3 * idx ] = (
rtP . Gain_Gain_a1wggbqhys [ idx + 3 ] * dz5vdjb0hd_idx_1 + rtP .
Gain_Gain_a1wggbqhys [ idx ] * dz5vdjb0hd_idx_0 ) + rtP .
Gain_Gain_a1wggbqhys [ idx + 6 ] * an2j0hkqbl_idx_2 ; khdw5q2wy4 [ 3 * idx +
1 ] = ( rtP . Gain1_Gain_mlyplvcvro [ idx + 3 ] * dz5vdjb0hd_idx_1 + rtP .
Gain1_Gain_mlyplvcvro [ idx ] * dz5vdjb0hd_idx_0 ) + rtP .
Gain1_Gain_mlyplvcvro [ idx + 6 ] * an2j0hkqbl_idx_2 ; khdw5q2wy4 [ 3 * idx +
2 ] = ( rtP . Gain2_Gain_kp2d4nocmq [ idx + 3 ] * dz5vdjb0hd_idx_1 + rtP .
Gain2_Gain_kp2d4nocmq [ idx ] * dz5vdjb0hd_idx_0 ) + rtP .
Gain2_Gain_kp2d4nocmq [ idx + 6 ] * an2j0hkqbl_idx_2 ; } for ( idx = 0 ; idx
< 9 ; idx ++ ) { oxy5kmdygt = khdw5q2wy4 [ idx ] ; p1wjvujgew [ idx ] =
oxy5kmdygt ; lambda = rtP . Gain3_Gain_kf22pabip4 * oxy5kmdygt ; p1wjvujgew [
idx + 9 ] = lambda ; iygdiv1cei [ idx ] = lambda ; iygdiv1cei [ idx + 9 ] =
oxy5kmdygt ; } tmp_p [ 0 ] = rtB . m3gvnxject ; tmp_p [ 1 ] = rtB .
ijvi5t5r0z ; tmp_p [ 2 ] = rtB . ijvi5t5r0z ; tmp_p [ 3 ] = rtB . ijvi5t5r0z
; tmp_p [ 4 ] = rtB . ijvi5t5r0z ; tmp_p [ 5 ] = rtB . ijvi5t5r0z ; for ( idx
= 0 ; idx < 6 ; idx ++ ) { j2yak2edzf [ 6 * idx ] = p1wjvujgew [ 3 * idx ] ;
j2yak2edzf [ 6 * idx + 3 ] = iygdiv1cei [ 3 * idx ] ; j2yak2edzf [ 6 * idx +
1 ] = p1wjvujgew [ 3 * idx + 1 ] ; j2yak2edzf [ 6 * idx + 4 ] = iygdiv1cei [
3 * idx + 1 ] ; j2yak2edzf [ 6 * idx + 2 ] = p1wjvujgew [ 3 * idx + 2 ] ;
j2yak2edzf [ 6 * idx + 5 ] = iygdiv1cei [ 3 * idx + 2 ] ; } for ( idx = 0 ;
idx < 6 ; idx ++ ) { for ( i2 = 0 ; i2 < 6 ; i2 ++ ) { oxy5kmdygt = 0.0 ; for
( b_exponent = 0 ; b_exponent < 6 ; b_exponent ++ ) { oxy5kmdygt +=
j2yak2edzf [ 6 * b_exponent + i2 ] * rtB . o0ugrkeqpd [ 6 * idx + b_exponent
] ; } j2yak2edzf_p [ i2 + 6 * idx ] = oxy5kmdygt ; } } e2xginouw2 [ 0 ] =
ml23bolgnb [ 0 ] ; e2xginouw2 [ 3 ] = dz5vdjb0hd_idx_0 ; e2xginouw2 [ 1 ] =
ml23bolgnb [ 1 ] ; e2xginouw2 [ 4 ] = dz5vdjb0hd_idx_1 ; e2xginouw2 [ 2 ] =
ml23bolgnb [ 2 ] ; e2xginouw2 [ 5 ] = an2j0hkqbl_idx_2 ; for ( idx = 0 ; idx
< 6 ; idx ++ ) { oxy5kmdygt = 0.0 ; for ( i2 = 0 ; i2 < 6 ; i2 ++ ) {
oxy5kmdygt += j2yak2edzf_p [ 6 * i2 + idx ] * e2xginouw2 [ i2 ] ; } rtB .
ddcf0ek4jw [ idx ] = ( rtB . lg5hpscltc [ idx ] + tmp_p [ idx ] ) -
oxy5kmdygt ; } rt_mldivide_U1d6x6_U2d6x1_Yd6x1_snf ( rtB . o0ugrkeqpd , rtB .
ddcf0ek4jw ) ; if ( ssIsSampleHit ( rtS , 1 , 0 ) ) { } rtB . cmwuafgi05 =
rtP . R2D1_Gain_g0cjd2kme4 * rtB . ddcf0ek4jw [ 5 ] ; if ( ssIsSampleHit (
rtS , 1 , 0 ) ) { } rtB . aoodyqcbut [ 0 ] = ( dz5vdjb0hd_idx_1 *
muDoubleScalarSin ( rtB . ffht1uab1p [ 0 ] ) * muDoubleScalarTan ( rtB .
ffht1uab1p [ 1 ] ) + dz5vdjb0hd_idx_0 ) + an2j0hkqbl_idx_2 *
muDoubleScalarCos ( rtB . ffht1uab1p [ 0 ] ) * muDoubleScalarTan ( rtB .
ffht1uab1p [ 1 ] ) ; rtB . aoodyqcbut [ 1 ] = dz5vdjb0hd_idx_1 *
muDoubleScalarCos ( rtB . ffht1uab1p [ 0 ] ) - an2j0hkqbl_idx_2 *
muDoubleScalarSin ( rtB . ffht1uab1p [ 0 ] ) ; rtB . aoodyqcbut [ 2 ] =
dz5vdjb0hd_idx_1 * muDoubleScalarSin ( rtB . ffht1uab1p [ 0 ] ) /
muDoubleScalarCos ( rtB . ffht1uab1p [ 1 ] ) + an2j0hkqbl_idx_2 *
muDoubleScalarCos ( rtB . ffht1uab1p [ 0 ] ) / muDoubleScalarCos ( rtB .
ffht1uab1p [ 1 ] ) ; oxy5kmdygt = rtB . ldelskn1jo [ 1 ] ; lambda = rtB .
ldelskn1jo [ 0 ] ; y2 = rtB . ldelskn1jo [ 2 ] ; for ( idx = 0 ; idx < 3 ;
idx ++ ) { rtB . k1afspykmn [ idx ] = ( rtP . Zpositiveisdown_Gain [ idx + 3
] * oxy5kmdygt + rtP . Zpositiveisdown_Gain [ idx ] * lambda ) + rtP .
Zpositiveisdown_Gain [ idx + 6 ] * y2 ; } if ( ssIsSampleHit ( rtS , 1 , 0 )
) { } rtB . lc5ruufnmk [ 0 ] = rtP . R2D_Gain * rtB . ffht1uab1p [ 0 ] ; rtB
. lc5ruufnmk [ 1 ] = rtP . R2D_Gain * rtB . ffht1uab1p [ 1 ] ; rtB .
lc5ruufnmk [ 2 ] = rtP . R2D_Gain * rtB . ffht1uab1p [ 2 ] ; if (
ssIsSampleHit ( rtS , 1 , 0 ) ) { p1wjvujgew [ 0 ] = 0.0 ; p1wjvujgew [ 1 ] =
rtB . ljudbp5sfm ; p1wjvujgew [ 2 ] = rtB . mhbhj1bpzc ; p1wjvujgew [ 3 ] =
rtB . av1jt30k31 [ 0 ] ; p1wjvujgew [ 6 ] = rtB . ewh2czgzt2 [ 0 ] ;
p1wjvujgew [ 9 ] = rtB . ldelskn1jo [ 0 ] ; p1wjvujgew [ 12 ] = rtB .
fwckhvycxa [ 0 ] ; p1wjvujgew [ 15 ] = rtB . lc5ruufnmk [ 0 ] ; p1wjvujgew [
4 ] = rtB . av1jt30k31 [ 1 ] ; p1wjvujgew [ 7 ] = rtB . ewh2czgzt2 [ 1 ] ;
p1wjvujgew [ 10 ] = rtB . ldelskn1jo [ 1 ] ; p1wjvujgew [ 13 ] = rtB .
fwckhvycxa [ 1 ] ; p1wjvujgew [ 16 ] = rtB . lc5ruufnmk [ 1 ] ; p1wjvujgew [
5 ] = rtB . av1jt30k31 [ 2 ] ; p1wjvujgew [ 8 ] = rtB . ewh2czgzt2 [ 2 ] ;
p1wjvujgew [ 11 ] = rtB . ldelskn1jo [ 2 ] ; p1wjvujgew [ 14 ] = rtB .
fwckhvycxa [ 2 ] ; p1wjvujgew [ 17 ] = rtB . lc5ruufnmk [ 2 ] ; if (
ssGetLogOutput ( rtS ) ) { { const char * errMsg = ( NULL ) ; void * fp = (
void * ) rtDW . atwrl0cbxb . FilePtr ; if ( fp != ( NULL ) ) { { real_T t ;
void * u ; t = ssGetTaskTime ( rtS , 1 ) ; u = ( void * ) & p1wjvujgew [ 0 ]
; errMsg = rtwH5LoggingCollectionWrite ( 1 , fp , 0 , t , u ) ; if ( errMsg
!= ( NULL ) ) { ssSetErrorStatus ( rtS , errMsg ) ; return ; } } } } } rtB .
ckb3sq150e = rtP . DiscretePIDController4_I * rtB . eisyorlq2r ; rtB .
hrq2k5iwyr = rtP . DiscretePIDController_I * rtB . m1c2gjrdhf ; rtB .
knqqe5buxf = rtP . DiscretePIDController1_I * rtB . c2nosomft5 ; { if ( rtDW
. f0qoodbnbc . AQHandles && ssGetLogOutput ( rtS ) ) { sdiWriteSignal ( rtDW
. f0qoodbnbc . AQHandles , ssGetTaskTime ( rtS , 1 ) , ( char * ) & rtB .
amv5xbxcgx + 0 ) ; } } rtB . pxzonjrd4i = rtP . DiscretePIDController2_I *
rtB . ctr2i5cu0j ; rtB . deddzxm4gc = rtP . DiscretePIDController3_I * rtB .
agbvtgnrv4 ; } UNUSED_PARAMETER ( tid ) ; } void MdlOutputsTID2 ( int_T tid )
{ real_T tmp [ 18 ] ; real_T j3r1wb322f ; int32_T i ; tmp [ 0 ] = rtP . mass
; tmp [ 6 ] = rtP . Constant4_Value ; tmp [ 12 ] = rtP . Constant4_Value ;
tmp [ 1 ] = rtP . Constant4_Value ; tmp [ 7 ] = rtP . mass ; tmp [ 13 ] = rtP
. Constant4_Value ; tmp [ 2 ] = rtP . Constant4_Value ; tmp [ 8 ] = rtP .
Constant4_Value ; tmp [ 14 ] = rtP . mass ; for ( i = 0 ; i < 3 ; i ++ ) {
tmp [ 6 * i + 3 ] = rtP . Constant1_Value [ 3 * i ] ; tmp [ 6 * i + 4 ] = rtP
. Constant1_Value [ 3 * i + 1 ] ; tmp [ 6 * i + 5 ] = rtP . Constant1_Value [
3 * i + 2 ] ; } memcpy ( & rtB . o0ugrkeqpd [ 0 ] , & tmp [ 0 ] , 18U *
sizeof ( real_T ) ) ; for ( i = 0 ; i < 3 ; i ++ ) { tmp [ 6 * i ] = rtP .
Constant1_Value [ 3 * i ] ; tmp [ 6 * i + 1 ] = rtP . Constant1_Value [ 3 * i
+ 1 ] ; tmp [ 6 * i + 2 ] = rtP . Constant1_Value [ 3 * i + 2 ] ; } tmp [ 3 ]
= rtP . Ixx ; tmp [ 9 ] = rtP . Constant4_Value ; tmp [ 15 ] = rtP .
Constant4_Value ; tmp [ 4 ] = rtP . Constant4_Value ; tmp [ 10 ] = rtP . Iyy
; tmp [ 16 ] = rtP . Constant4_Value ; tmp [ 5 ] = rtP . Constant4_Value ;
tmp [ 11 ] = rtP . Constant4_Value ; tmp [ 17 ] = rtP . Izz ; memcpy ( & rtB
. o0ugrkeqpd [ 18 ] , & tmp [ 0 ] , 18U * sizeof ( real_T ) ) ; rtB .
ijvi5t5r0z = rtP . Constant4_Value_lvvzxuwh5z ; j3r1wb322f = rtP .
Deg2Rad4_Gain * 0.0 ; rtB . i5zbjzuhhx = rtP . CYDr * j3r1wb322f * rtP .
Gain2_Gain_b4uvpqpdbd ; rtB . kwxg3amuly = rtP . ClDr * j3r1wb322f * rtP .
Gain1_Gain_nbhhfd3fwa ; rtB . b1n2m12ywt = rtP . SliderGain_gain * rtP . Clp
; rtB . bx1plzk1jh = rtP . SliderGain1_gain * rtP . Clr ; rtB . eej5dfdnuw =
rtP . CnDr * j3r1wb322f * rtP . Gain1_Gain_dd3z2ich2e ; rtB . leydlmjwwh =
rtP . SliderGain_gain_hyc34xasfz * rtP . Cnp ; rtB . exx2dadn0g = rtP .
SliderGain1_gain_mv1hpouzrh * rtP . Cnr ; rtB . ebpprftokq = rtP . CLa_dot *
0.0 * rtP . Gain3_Gain_jo4inzsfgw ; rtB . b152zcpgbp = rtP . Cma_dot * 0.0 *
rtP . Gain3_Gain_fosanw5ymw ; rtB . l0yxgnvu5h = rtP .
SliderGain_gain_bsd0ykrtc0 * rtP . Cmq ; UNUSED_PARAMETER ( tid ) ; } void
MdlUpdate ( int_T tid ) { if ( ssIsSampleHit ( rtS , 1 , 0 ) ) { rtDW .
blkvfyc1ut += rtP . Integrator_gainval * rtB . ckb3sq150e ; rtDW . dbof0j1l1z
= rtB . m0diztvarb ; rtDW . epsgdxius2 += rtP . Integrator_gainval_gsc5ke3qa1
* rtB . hrq2k5iwyr ; rtDW . i5vdoafna1 = rtB . gyndz2ty42 ; rtDW . f21v3dtx13
+= rtP . Integrator_gainval_pgxpxjbdlc * rtB . knqqe5buxf ; rtDW . odzrzx3nyk
= rtB . c4zgqksn3s ; rtDW . ko2emyti4i += rtP . Integrator_gainval_fn0merchw3
* rtB . pxzonjrd4i ; rtDW . hx53qo0tyb += rtP . Filter_gainval * rtB .
pvv2cmskei ; rtDW . hoflvlpyvq += rtP . Integrator_gainval_kdbzsgvpvb * rtB .
deddzxm4gc ; rtDW . bsuso3aou5 += rtP . Filter_gainval_elrzqrryfc * rtB .
hjhp5kuoxj ; } UNUSED_PARAMETER ( tid ) ; } void MdlUpdateTID2 ( int_T tid )
{ UNUSED_PARAMETER ( tid ) ; } void MdlDerivatives ( void ) { XDot * _rtXdot
; _rtXdot = ( ( XDot * ) ssGetdX ( rtS ) ) ; _rtXdot -> f50afzevjg [ 0 ] =
rtB . k1afspykmn [ 0 ] ; _rtXdot -> kc2egwi14h [ 0 ] = rtB . aoodyqcbut [ 0 ]
; _rtXdot -> o2igygaiml [ 0 ] = rtB . ddcf0ek4jw [ 0 ] ; _rtXdot ->
ajbdf0rme2 [ 0 ] = rtB . ddcf0ek4jw [ 3 ] ; _rtXdot -> f50afzevjg [ 1 ] = rtB
. k1afspykmn [ 1 ] ; _rtXdot -> kc2egwi14h [ 1 ] = rtB . aoodyqcbut [ 1 ] ;
_rtXdot -> o2igygaiml [ 1 ] = rtB . ddcf0ek4jw [ 1 ] ; _rtXdot -> ajbdf0rme2
[ 1 ] = rtB . ddcf0ek4jw [ 4 ] ; _rtXdot -> f50afzevjg [ 2 ] = rtB .
k1afspykmn [ 2 ] ; _rtXdot -> kc2egwi14h [ 2 ] = rtB . aoodyqcbut [ 2 ] ;
_rtXdot -> o2igygaiml [ 2 ] = rtB . ddcf0ek4jw [ 2 ] ; _rtXdot -> ajbdf0rme2
[ 2 ] = rtB . ddcf0ek4jw [ 5 ] ; } void MdlProjection ( void ) { } void
MdlZeroCrossings ( void ) { ZCV * _rtZCSV ; _rtZCSV = ( ( ZCV * )
ssGetSolverZcSignalVector ( rtS ) ) ; _rtZCSV -> gxbd5k5ga1 = rtB .
jd2mqrgdxl [ 0 ] - rtP . Switch_Threshold ; _rtZCSV -> fyia3f0ajs = rtB .
lda1u2jc0p - rtP . Switch_Threshold_hwgs5rnbxi ; _rtZCSV -> f1gbjogenh = rtB
. ewh2czgzt2 [ 2 ] - rtP . ISA_hmax ; _rtZCSV -> pugigtm5ja = rtB .
ewh2czgzt2 [ 2 ] - rtP . Limitaltitude_LowerSat ; _rtZCSV -> lfvmfu5zzq [ 1 ]
= rtB . f4k3dw2w0v - rtP . Saturation_UpperSat ; _rtZCSV -> leel0qnkh1 [ 1 ]
= rtB . f4k3dw2w0v - rtP . Saturation_LowerSat ; _rtZCSV -> d1cz5eqy4p = rtB
. m5psfntta4 - rtP . Saturation1_UpperSat ; _rtZCSV -> p25sjuw5vw = rtB .
m5psfntta4 - rtP . Saturation1_LowerSat ; } void MdlTerminate ( void ) { {
const char * errMsg = ( NULL ) ; void * fp = ( void * ) rtDW . atwrl0cbxb .
FilePtr ; if ( fp != ( NULL ) ) { errMsg =
rtwH5LoggingCollectionDestroyInstance ( 1 , fp ) ; if ( errMsg != ( NULL ) )
{ ssSetErrorStatus ( rtS , errMsg ) ; return ; } } } { if ( rtDW . f0qoodbnbc
. AQHandles ) { sdiTerminateStreaming ( & rtDW . f0qoodbnbc . AQHandles ) ; }
} } static void mr_sixdof_cacheDataAsMxArray ( mxArray * destArray , mwIndex
i , int j , const void * srcData , size_t numBytes ) ; static void
mr_sixdof_cacheDataAsMxArray ( mxArray * destArray , mwIndex i , int j ,
const void * srcData , size_t numBytes ) { mxArray * newArray =
mxCreateUninitNumericMatrix ( ( size_t ) 1 , numBytes , mxUINT8_CLASS ,
mxREAL ) ; memcpy ( ( uint8_T * ) mxGetData ( newArray ) , ( const uint8_T *
) srcData , numBytes ) ; mxSetFieldByNumber ( destArray , i , j , newArray )
; } static void mr_sixdof_restoreDataFromMxArray ( void * destData , const
mxArray * srcArray , mwIndex i , int j , size_t numBytes ) ; static void
mr_sixdof_restoreDataFromMxArray ( void * destData , const mxArray * srcArray
, mwIndex i , int j , size_t numBytes ) { memcpy ( ( uint8_T * ) destData , (
const uint8_T * ) mxGetData ( mxGetFieldByNumber ( srcArray , i , j ) ) ,
numBytes ) ; } static void mr_sixdof_cacheBitFieldToMxArray ( mxArray *
destArray , mwIndex i , int j , uint_T bitVal ) ; static void
mr_sixdof_cacheBitFieldToMxArray ( mxArray * destArray , mwIndex i , int j ,
uint_T bitVal ) { mxSetFieldByNumber ( destArray , i , j ,
mxCreateDoubleScalar ( ( real_T ) bitVal ) ) ; } static uint_T
mr_sixdof_extractBitFieldFromMxArray ( const mxArray * srcArray , mwIndex i ,
int j , uint_T numBits ) ; static uint_T mr_sixdof_extractBitFieldFromMxArray
( const mxArray * srcArray , mwIndex i , int j , uint_T numBits ) { const
uint_T varVal = ( uint_T ) mxGetScalar ( mxGetFieldByNumber ( srcArray , i ,
j ) ) ; return varVal & ( ( 1u << numBits ) - 1u ) ; } static void
mr_sixdof_cacheDataToMxArrayWithOffset ( mxArray * destArray , mwIndex i ,
int j , mwIndex offset , const void * srcData , size_t numBytes ) ; static
void mr_sixdof_cacheDataToMxArrayWithOffset ( mxArray * destArray , mwIndex i
, int j , mwIndex offset , const void * srcData , size_t numBytes ) { uint8_T
* varData = ( uint8_T * ) mxGetData ( mxGetFieldByNumber ( destArray , i , j
) ) ; memcpy ( ( uint8_T * ) & varData [ offset * numBytes ] , ( const
uint8_T * ) srcData , numBytes ) ; } static void
mr_sixdof_restoreDataFromMxArrayWithOffset ( void * destData , const mxArray
* srcArray , mwIndex i , int j , mwIndex offset , size_t numBytes ) ; static
void mr_sixdof_restoreDataFromMxArrayWithOffset ( void * destData , const
mxArray * srcArray , mwIndex i , int j , mwIndex offset , size_t numBytes ) {
const uint8_T * varData = ( const uint8_T * ) mxGetData ( mxGetFieldByNumber
( srcArray , i , j ) ) ; memcpy ( ( uint8_T * ) destData , ( const uint8_T *
) & varData [ offset * numBytes ] , numBytes ) ; } static void
mr_sixdof_cacheBitFieldToCellArrayWithOffset ( mxArray * destArray , mwIndex
i , int j , mwIndex offset , uint_T fieldVal ) ; static void
mr_sixdof_cacheBitFieldToCellArrayWithOffset ( mxArray * destArray , mwIndex
i , int j , mwIndex offset , uint_T fieldVal ) { mxSetCell (
mxGetFieldByNumber ( destArray , i , j ) , offset , mxCreateDoubleScalar ( (
real_T ) fieldVal ) ) ; } static uint_T
mr_sixdof_extractBitFieldFromCellArrayWithOffset ( const mxArray * srcArray ,
mwIndex i , int j , mwIndex offset , uint_T numBits ) ; static uint_T
mr_sixdof_extractBitFieldFromCellArrayWithOffset ( const mxArray * srcArray ,
mwIndex i , int j , mwIndex offset , uint_T numBits ) { const uint_T fieldVal
= ( uint_T ) mxGetScalar ( mxGetCell ( mxGetFieldByNumber ( srcArray , i , j
) , offset ) ) ; return fieldVal & ( ( 1u << numBits ) - 1u ) ; } mxArray *
mr_sixdof_GetDWork ( ) { static const char_T * ssDWFieldNames [ 3 ] = { "rtB"
, "rtDW" , "NULL_PrevZCX" , } ; mxArray * ssDW = mxCreateStructMatrix ( 1 , 1
, 3 , ssDWFieldNames ) ; mr_sixdof_cacheDataAsMxArray ( ssDW , 0 , 0 , (
const void * ) & ( rtB ) , sizeof ( rtB ) ) ; { static const char_T *
rtdwDataFieldNames [ 28 ] = { "rtDW.kjy5vllogw" , "rtDW.blkvfyc1ut" ,
"rtDW.dbof0j1l1z" , "rtDW.epsgdxius2" , "rtDW.i5vdoafna1" , "rtDW.f21v3dtx13"
, "rtDW.odzrzx3nyk" , "rtDW.ko2emyti4i" , "rtDW.hx53qo0tyb" ,
"rtDW.hoflvlpyvq" , "rtDW.bsuso3aou5" , "rtDW.kqs40q3ion" , "rtDW.j2zbeu35vc"
, "rtDW.ih0gu0a4vg" , "rtDW.no2vyppbyo" , "rtDW.n33rcmsjab" ,
"rtDW.jye5a0flet" , "rtDW.ejk4nu5buq" , "rtDW.mhy0u4hbsx" , "rtDW.ljddttc2rd"
, "rtDW.lvfkgpske1" , "rtDW.ecfpev5hmr" , "rtDW.mqsusrzct3" ,
"rtDW.gzmh1uauzr" , "rtDW.a0cdktfgmq" , "rtDW.jhvamlflm5" , "rtDW.pz1vk2xm02"
, "rtDW.ovkmgmp3yk" , } ; mxArray * rtdwData = mxCreateStructMatrix ( 1 , 1 ,
28 , rtdwDataFieldNames ) ; mr_sixdof_cacheDataAsMxArray ( rtdwData , 0 , 0 ,
( const void * ) & ( rtDW . kjy5vllogw ) , sizeof ( rtDW . kjy5vllogw ) ) ;
mr_sixdof_cacheDataAsMxArray ( rtdwData , 0 , 1 , ( const void * ) & ( rtDW .
blkvfyc1ut ) , sizeof ( rtDW . blkvfyc1ut ) ) ; mr_sixdof_cacheDataAsMxArray
( rtdwData , 0 , 2 , ( const void * ) & ( rtDW . dbof0j1l1z ) , sizeof ( rtDW
. dbof0j1l1z ) ) ; mr_sixdof_cacheDataAsMxArray ( rtdwData , 0 , 3 , ( const
void * ) & ( rtDW . epsgdxius2 ) , sizeof ( rtDW . epsgdxius2 ) ) ;
mr_sixdof_cacheDataAsMxArray ( rtdwData , 0 , 4 , ( const void * ) & ( rtDW .
i5vdoafna1 ) , sizeof ( rtDW . i5vdoafna1 ) ) ; mr_sixdof_cacheDataAsMxArray
( rtdwData , 0 , 5 , ( const void * ) & ( rtDW . f21v3dtx13 ) , sizeof ( rtDW
. f21v3dtx13 ) ) ; mr_sixdof_cacheDataAsMxArray ( rtdwData , 0 , 6 , ( const
void * ) & ( rtDW . odzrzx3nyk ) , sizeof ( rtDW . odzrzx3nyk ) ) ;
mr_sixdof_cacheDataAsMxArray ( rtdwData , 0 , 7 , ( const void * ) & ( rtDW .
ko2emyti4i ) , sizeof ( rtDW . ko2emyti4i ) ) ; mr_sixdof_cacheDataAsMxArray
( rtdwData , 0 , 8 , ( const void * ) & ( rtDW . hx53qo0tyb ) , sizeof ( rtDW
. hx53qo0tyb ) ) ; mr_sixdof_cacheDataAsMxArray ( rtdwData , 0 , 9 , ( const
void * ) & ( rtDW . hoflvlpyvq ) , sizeof ( rtDW . hoflvlpyvq ) ) ;
mr_sixdof_cacheDataAsMxArray ( rtdwData , 0 , 10 , ( const void * ) & ( rtDW
. bsuso3aou5 ) , sizeof ( rtDW . bsuso3aou5 ) ) ;
mr_sixdof_cacheDataAsMxArray ( rtdwData , 0 , 11 , ( const void * ) & ( rtDW
. kqs40q3ion ) , sizeof ( rtDW . kqs40q3ion ) ) ;
mr_sixdof_cacheDataAsMxArray ( rtdwData , 0 , 12 , ( const void * ) & ( rtDW
. j2zbeu35vc ) , sizeof ( rtDW . j2zbeu35vc ) ) ;
mr_sixdof_cacheDataAsMxArray ( rtdwData , 0 , 13 , ( const void * ) & ( rtDW
. ih0gu0a4vg ) , sizeof ( rtDW . ih0gu0a4vg ) ) ;
mr_sixdof_cacheDataAsMxArray ( rtdwData , 0 , 14 , ( const void * ) & ( rtDW
. no2vyppbyo ) , sizeof ( rtDW . no2vyppbyo ) ) ;
mr_sixdof_cacheDataAsMxArray ( rtdwData , 0 , 15 , ( const void * ) & ( rtDW
. n33rcmsjab ) , sizeof ( rtDW . n33rcmsjab ) ) ;
mr_sixdof_cacheDataAsMxArray ( rtdwData , 0 , 16 , ( const void * ) & ( rtDW
. jye5a0flet ) , sizeof ( rtDW . jye5a0flet ) ) ;
mr_sixdof_cacheDataAsMxArray ( rtdwData , 0 , 17 , ( const void * ) & ( rtDW
. ejk4nu5buq ) , sizeof ( rtDW . ejk4nu5buq ) ) ;
mr_sixdof_cacheDataAsMxArray ( rtdwData , 0 , 18 , ( const void * ) & ( rtDW
. mhy0u4hbsx ) , sizeof ( rtDW . mhy0u4hbsx ) ) ;
mr_sixdof_cacheDataAsMxArray ( rtdwData , 0 , 19 , ( const void * ) & ( rtDW
. ljddttc2rd ) , sizeof ( rtDW . ljddttc2rd ) ) ;
mr_sixdof_cacheDataAsMxArray ( rtdwData , 0 , 20 , ( const void * ) & ( rtDW
. lvfkgpske1 ) , sizeof ( rtDW . lvfkgpske1 ) ) ;
mr_sixdof_cacheDataAsMxArray ( rtdwData , 0 , 21 , ( const void * ) & ( rtDW
. ecfpev5hmr ) , sizeof ( rtDW . ecfpev5hmr ) ) ;
mr_sixdof_cacheDataAsMxArray ( rtdwData , 0 , 22 , ( const void * ) & ( rtDW
. mqsusrzct3 ) , sizeof ( rtDW . mqsusrzct3 ) ) ;
mr_sixdof_cacheDataAsMxArray ( rtdwData , 0 , 23 , ( const void * ) & ( rtDW
. gzmh1uauzr ) , sizeof ( rtDW . gzmh1uauzr ) ) ;
mr_sixdof_cacheDataAsMxArray ( rtdwData , 0 , 24 , ( const void * ) & ( rtDW
. a0cdktfgmq ) , sizeof ( rtDW . a0cdktfgmq ) ) ;
mr_sixdof_cacheDataAsMxArray ( rtdwData , 0 , 25 , ( const void * ) & ( rtDW
. jhvamlflm5 ) , sizeof ( rtDW . jhvamlflm5 ) ) ;
mr_sixdof_cacheDataAsMxArray ( rtdwData , 0 , 26 , ( const void * ) & ( rtDW
. pz1vk2xm02 ) , sizeof ( rtDW . pz1vk2xm02 ) ) ;
mr_sixdof_cacheDataAsMxArray ( rtdwData , 0 , 27 , ( const void * ) & ( rtDW
. ovkmgmp3yk ) , sizeof ( rtDW . ovkmgmp3yk ) ) ; mxSetFieldByNumber ( ssDW ,
0 , 1 , rtdwData ) ; } return ssDW ; } void mr_sixdof_SetDWork ( const
mxArray * ssDW ) { ( void ) ssDW ; mr_sixdof_restoreDataFromMxArray ( ( void
* ) & ( rtB ) , ssDW , 0 , 0 , sizeof ( rtB ) ) ; { const mxArray * rtdwData
= mxGetFieldByNumber ( ssDW , 0 , 1 ) ; mr_sixdof_restoreDataFromMxArray ( (
void * ) & ( rtDW . kjy5vllogw ) , rtdwData , 0 , 0 , sizeof ( rtDW .
kjy5vllogw ) ) ; mr_sixdof_restoreDataFromMxArray ( ( void * ) & ( rtDW .
blkvfyc1ut ) , rtdwData , 0 , 1 , sizeof ( rtDW . blkvfyc1ut ) ) ;
mr_sixdof_restoreDataFromMxArray ( ( void * ) & ( rtDW . dbof0j1l1z ) ,
rtdwData , 0 , 2 , sizeof ( rtDW . dbof0j1l1z ) ) ;
mr_sixdof_restoreDataFromMxArray ( ( void * ) & ( rtDW . epsgdxius2 ) ,
rtdwData , 0 , 3 , sizeof ( rtDW . epsgdxius2 ) ) ;
mr_sixdof_restoreDataFromMxArray ( ( void * ) & ( rtDW . i5vdoafna1 ) ,
rtdwData , 0 , 4 , sizeof ( rtDW . i5vdoafna1 ) ) ;
mr_sixdof_restoreDataFromMxArray ( ( void * ) & ( rtDW . f21v3dtx13 ) ,
rtdwData , 0 , 5 , sizeof ( rtDW . f21v3dtx13 ) ) ;
mr_sixdof_restoreDataFromMxArray ( ( void * ) & ( rtDW . odzrzx3nyk ) ,
rtdwData , 0 , 6 , sizeof ( rtDW . odzrzx3nyk ) ) ;
mr_sixdof_restoreDataFromMxArray ( ( void * ) & ( rtDW . ko2emyti4i ) ,
rtdwData , 0 , 7 , sizeof ( rtDW . ko2emyti4i ) ) ;
mr_sixdof_restoreDataFromMxArray ( ( void * ) & ( rtDW . hx53qo0tyb ) ,
rtdwData , 0 , 8 , sizeof ( rtDW . hx53qo0tyb ) ) ;
mr_sixdof_restoreDataFromMxArray ( ( void * ) & ( rtDW . hoflvlpyvq ) ,
rtdwData , 0 , 9 , sizeof ( rtDW . hoflvlpyvq ) ) ;
mr_sixdof_restoreDataFromMxArray ( ( void * ) & ( rtDW . bsuso3aou5 ) ,
rtdwData , 0 , 10 , sizeof ( rtDW . bsuso3aou5 ) ) ;
mr_sixdof_restoreDataFromMxArray ( ( void * ) & ( rtDW . kqs40q3ion ) ,
rtdwData , 0 , 11 , sizeof ( rtDW . kqs40q3ion ) ) ;
mr_sixdof_restoreDataFromMxArray ( ( void * ) & ( rtDW . j2zbeu35vc ) ,
rtdwData , 0 , 12 , sizeof ( rtDW . j2zbeu35vc ) ) ;
mr_sixdof_restoreDataFromMxArray ( ( void * ) & ( rtDW . ih0gu0a4vg ) ,
rtdwData , 0 , 13 , sizeof ( rtDW . ih0gu0a4vg ) ) ;
mr_sixdof_restoreDataFromMxArray ( ( void * ) & ( rtDW . no2vyppbyo ) ,
rtdwData , 0 , 14 , sizeof ( rtDW . no2vyppbyo ) ) ;
mr_sixdof_restoreDataFromMxArray ( ( void * ) & ( rtDW . n33rcmsjab ) ,
rtdwData , 0 , 15 , sizeof ( rtDW . n33rcmsjab ) ) ;
mr_sixdof_restoreDataFromMxArray ( ( void * ) & ( rtDW . jye5a0flet ) ,
rtdwData , 0 , 16 , sizeof ( rtDW . jye5a0flet ) ) ;
mr_sixdof_restoreDataFromMxArray ( ( void * ) & ( rtDW . ejk4nu5buq ) ,
rtdwData , 0 , 17 , sizeof ( rtDW . ejk4nu5buq ) ) ;
mr_sixdof_restoreDataFromMxArray ( ( void * ) & ( rtDW . mhy0u4hbsx ) ,
rtdwData , 0 , 18 , sizeof ( rtDW . mhy0u4hbsx ) ) ;
mr_sixdof_restoreDataFromMxArray ( ( void * ) & ( rtDW . ljddttc2rd ) ,
rtdwData , 0 , 19 , sizeof ( rtDW . ljddttc2rd ) ) ;
mr_sixdof_restoreDataFromMxArray ( ( void * ) & ( rtDW . lvfkgpske1 ) ,
rtdwData , 0 , 20 , sizeof ( rtDW . lvfkgpske1 ) ) ;
mr_sixdof_restoreDataFromMxArray ( ( void * ) & ( rtDW . ecfpev5hmr ) ,
rtdwData , 0 , 21 , sizeof ( rtDW . ecfpev5hmr ) ) ;
mr_sixdof_restoreDataFromMxArray ( ( void * ) & ( rtDW . mqsusrzct3 ) ,
rtdwData , 0 , 22 , sizeof ( rtDW . mqsusrzct3 ) ) ;
mr_sixdof_restoreDataFromMxArray ( ( void * ) & ( rtDW . gzmh1uauzr ) ,
rtdwData , 0 , 23 , sizeof ( rtDW . gzmh1uauzr ) ) ;
mr_sixdof_restoreDataFromMxArray ( ( void * ) & ( rtDW . a0cdktfgmq ) ,
rtdwData , 0 , 24 , sizeof ( rtDW . a0cdktfgmq ) ) ;
mr_sixdof_restoreDataFromMxArray ( ( void * ) & ( rtDW . jhvamlflm5 ) ,
rtdwData , 0 , 25 , sizeof ( rtDW . jhvamlflm5 ) ) ;
mr_sixdof_restoreDataFromMxArray ( ( void * ) & ( rtDW . pz1vk2xm02 ) ,
rtdwData , 0 , 26 , sizeof ( rtDW . pz1vk2xm02 ) ) ;
mr_sixdof_restoreDataFromMxArray ( ( void * ) & ( rtDW . ovkmgmp3yk ) ,
rtdwData , 0 , 27 , sizeof ( rtDW . ovkmgmp3yk ) ) ; } } mxArray *
mr_sixdof_GetSimStateDisallowedBlocks ( ) { mxArray * data =
mxCreateCellMatrix ( 10 , 3 ) ; mwIndex subs [ 2 ] , offset ; { static const
char_T * blockType [ 10 ] = { "Scope" , "Scope" , "Scope" , "Scope" , "Scope"
, "Scope" , "Scope" , "Scope" , "Scope" , "Scope" , } ; static const char_T *
blockPath [ 10 ] = { "sixdof/Scope1" , "sixdof/Scope11" , "sixdof/Scope2" ,
"sixdof/Scope3" , "sixdof/Scope4" , "sixdof/Scope5" , "sixdof/Scope7" ,
"sixdof/Scope9" , "sixdof/A//C/Euler Angles (y-psi, p-theta, g-psi)" ,
"sixdof/A//C/F" , } ; static const int reason [ 10 ] = { 0 , 0 , 0 , 0 , 0 ,
0 , 0 , 0 , 0 , 0 , } ; for ( subs [ 0 ] = 0 ; subs [ 0 ] < 10 ; ++ ( subs [
0 ] ) ) { subs [ 1 ] = 0 ; offset = mxCalcSingleSubscript ( data , 2 , subs )
; mxSetCell ( data , offset , mxCreateString ( blockType [ subs [ 0 ] ] ) ) ;
subs [ 1 ] = 1 ; offset = mxCalcSingleSubscript ( data , 2 , subs ) ;
mxSetCell ( data , offset , mxCreateString ( blockPath [ subs [ 0 ] ] ) ) ;
subs [ 1 ] = 2 ; offset = mxCalcSingleSubscript ( data , 2 , subs ) ;
mxSetCell ( data , offset , mxCreateDoubleScalar ( ( real_T ) reason [ subs [
0 ] ] ) ) ; } } return data ; } void MdlInitializeSizes ( void ) {
ssSetNumContStates ( rtS , 12 ) ; ssSetNumPeriodicContStates ( rtS , 0 ) ;
ssSetNumY ( rtS , 0 ) ; ssSetNumU ( rtS , 0 ) ; ssSetDirectFeedThrough ( rtS
, 0 ) ; ssSetNumSampleTimes ( rtS , 2 ) ; ssSetNumBlocks ( rtS , 375 ) ;
ssSetNumBlockIO ( rtS , 64 ) ; ssSetNumBlockParams ( rtS , 18269 ) ; } void
MdlInitializeSampleTimes ( void ) { ssSetSampleTime ( rtS , 0 , 0.0 ) ;
ssSetSampleTime ( rtS , 1 , 0.01 ) ; ssSetOffsetTime ( rtS , 0 , 0.0 ) ;
ssSetOffsetTime ( rtS , 1 , 0.0 ) ; } void raccel_set_checksum ( ) {
ssSetChecksumVal ( rtS , 0 , 1405113090U ) ; ssSetChecksumVal ( rtS , 1 ,
4097125932U ) ; ssSetChecksumVal ( rtS , 2 , 3769232021U ) ; ssSetChecksumVal
( rtS , 3 , 2404196798U ) ; }
#if defined(_MSC_VER)
#pragma optimize( "", off )
#endif
SimStruct * raccel_register_model ( ssExecutionInfo * executionInfo ) {
static struct _ssMdlInfo mdlInfo ; static struct _ssBlkInfo2 blkInfo2 ;
static struct _ssBlkInfoSLSize blkInfoSLSize ; ( void ) memset ( ( char_T * )
rtS , 0 , sizeof ( SimStruct ) ) ; ( void ) memset ( ( char_T * ) & mdlInfo ,
0 , sizeof ( struct _ssMdlInfo ) ) ; ( void ) memset ( ( char_T * ) &
blkInfo2 , 0 , sizeof ( struct _ssBlkInfo2 ) ) ; ( void ) memset ( ( char_T *
) & blkInfoSLSize , 0 , sizeof ( struct _ssBlkInfoSLSize ) ) ;
ssSetBlkInfo2Ptr ( rtS , & blkInfo2 ) ; ssSetBlkInfoSLSizePtr ( rtS , &
blkInfoSLSize ) ; ssSetMdlInfoPtr ( rtS , & mdlInfo ) ; ssSetExecutionInfo (
rtS , executionInfo ) ; slsaAllocOPModelData ( rtS ) ; { static time_T
mdlPeriod [ NSAMPLE_TIMES ] ; static time_T mdlOffset [ NSAMPLE_TIMES ] ;
static time_T mdlTaskTimes [ NSAMPLE_TIMES ] ; static int_T mdlTsMap [
NSAMPLE_TIMES ] ; static int_T mdlSampleHits [ NSAMPLE_TIMES ] ; static
boolean_T mdlTNextWasAdjustedPtr [ NSAMPLE_TIMES ] ; static int_T
mdlPerTaskSampleHits [ NSAMPLE_TIMES * NSAMPLE_TIMES ] ; static time_T
mdlTimeOfNextSampleHit [ NSAMPLE_TIMES ] ; { int_T i ; for ( i = 0 ; i <
NSAMPLE_TIMES ; i ++ ) { mdlPeriod [ i ] = 0.0 ; mdlOffset [ i ] = 0.0 ;
mdlTaskTimes [ i ] = 0.0 ; mdlTsMap [ i ] = i ; mdlSampleHits [ i ] = 1 ; } }
ssSetSampleTimePtr ( rtS , & mdlPeriod [ 0 ] ) ; ssSetOffsetTimePtr ( rtS , &
mdlOffset [ 0 ] ) ; ssSetSampleTimeTaskIDPtr ( rtS , & mdlTsMap [ 0 ] ) ;
ssSetTPtr ( rtS , & mdlTaskTimes [ 0 ] ) ; ssSetSampleHitPtr ( rtS , &
mdlSampleHits [ 0 ] ) ; ssSetTNextWasAdjustedPtr ( rtS , &
mdlTNextWasAdjustedPtr [ 0 ] ) ; ssSetPerTaskSampleHitsPtr ( rtS , &
mdlPerTaskSampleHits [ 0 ] ) ; ssSetTimeOfNextSampleHitPtr ( rtS , &
mdlTimeOfNextSampleHit [ 0 ] ) ; } ssSetSolverMode ( rtS ,
SOLVER_MODE_SINGLETASKING ) ; { ssSetBlockIO ( rtS , ( ( void * ) & rtB ) ) ;
( void ) memset ( ( ( void * ) & rtB ) , 0 , sizeof ( B ) ) ; } { real_T * x
= ( real_T * ) & rtX ; ssSetContStates ( rtS , x ) ; ( void ) memset ( ( void
* ) x , 0 , sizeof ( X ) ) ; } { void * dwork = ( void * ) & rtDW ;
ssSetRootDWork ( rtS , dwork ) ; ( void ) memset ( dwork , 0 , sizeof ( DW )
) ; } { static DataTypeTransInfo dtInfo ; ( void ) memset ( ( char_T * ) &
dtInfo , 0 , sizeof ( dtInfo ) ) ; ssSetModelMappingInfo ( rtS , & dtInfo ) ;
dtInfo . numDataTypes = 25 ; dtInfo . dataTypeSizes = & rtDataTypeSizes [ 0 ]
; dtInfo . dataTypeNames = & rtDataTypeNames [ 0 ] ; dtInfo . BTransTable = &
rtBTransTable ; dtInfo . PTransTable = & rtPTransTable ; dtInfo .
dataTypeInfoTable = rtDataTypeInfoTable ; } sixdof_InitializeDataMapInfo ( )
; ssSetIsRapidAcceleratorActive ( rtS , true ) ; ssSetRootSS ( rtS , rtS ) ;
ssSetVersion ( rtS , SIMSTRUCT_VERSION_LEVEL2 ) ; ssSetModelName ( rtS ,
"sixdof" ) ; ssSetPath ( rtS , "sixdof" ) ; ssSetTStart ( rtS , 0.0 ) ;
ssSetTFinal ( rtS , 800.0 ) ; ssSetStepSize ( rtS , 0.01 ) ;
ssSetFixedStepSize ( rtS , 0.01 ) ; { static RTWLogInfo rt_DataLoggingInfo ;
rt_DataLoggingInfo . loggingInterval = ( NULL ) ; ssSetRTWLogInfo ( rtS , &
rt_DataLoggingInfo ) ; } { { static int_T rt_LoggedStateWidths [ ] = { 3 , 3
, 3 , 3 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 } ; static int_T
rt_LoggedStateNumDimensions [ ] = { 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1
, 1 , 1 , 1 } ; static int_T rt_LoggedStateDimensions [ ] = { 3 , 3 , 3 , 3 ,
1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 } ; static boolean_T
rt_LoggedStateIsVarDims [ ] = { 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0
, 0 , 0 } ; static BuiltInDTypeId rt_LoggedStateDataTypeIds [ ] = { SS_DOUBLE
, SS_DOUBLE , SS_DOUBLE , SS_DOUBLE , SS_DOUBLE , SS_DOUBLE , SS_DOUBLE ,
SS_DOUBLE , SS_DOUBLE , SS_DOUBLE , SS_DOUBLE , SS_DOUBLE , SS_DOUBLE ,
SS_DOUBLE } ; static int_T rt_LoggedStateComplexSignals [ ] = { 0 , 0 , 0 , 0
, 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 } ; static RTWPreprocessingFcnPtr
rt_LoggingStatePreprocessingFcnPtrs [ ] = { ( NULL ) , ( NULL ) , ( NULL ) ,
( NULL ) , ( NULL ) , ( NULL ) , ( NULL ) , ( NULL ) , ( NULL ) , ( NULL ) ,
( NULL ) , ( NULL ) , ( NULL ) , ( NULL ) } ; static const char_T *
rt_LoggedStateLabels [ ] = { "CSTATE" , "CSTATE" , "CSTATE" , "CSTATE" ,
"DSTATE" , "DSTATE" , "DSTATE" , "DSTATE" , "DSTATE" , "DSTATE" , "DSTATE" ,
"DSTATE" , "DSTATE" , "DSTATE" } ; static const char_T *
rt_LoggedStateBlockNames [ ] = { "sixdof/A//C/6DoF EoM/xe\nye\nze" ,
"sixdof/A//C/6DoF EoM/phi\ntheta\npsi" , "sixdof/A//C/6DoF EoM/ub\nvb\nwb" ,
"sixdof/A//C/6DoF EoM/pqr" ,
 "sixdof/Airspeed Controller/Discrete PID Controller4/Integrator/Discrete/Integrator"
,
"sixdof/Airspeed Controller/Discrete PID Controller4/Filter/Differentiator/UD"
,
 "sixdof/Altitude Controller/Discrete PID Controller/Integrator/Discrete/Integrator"
,
"sixdof/Altitude Controller/Discrete PID Controller/Filter/Differentiator/UD"
,
 "sixdof/Altitude Controller/Discrete PID Controller1/Integrator/Discrete/Integrator"
,
"sixdof/Altitude Controller/Discrete PID Controller1/Filter/Differentiator/UD"
,
"sixdof/Yaw Controller/Discrete PID Controller2/Integrator/Discrete/Integrator"
,
 "sixdof/Yaw Controller/Discrete PID Controller2/Filter/Disc. Forward Euler Filter/Filter"
,
"sixdof/Yaw Controller/Discrete PID Controller3/Integrator/Discrete/Integrator"
,
 "sixdof/Yaw Controller/Discrete PID Controller3/Filter/Disc. Forward Euler Filter/Filter"
} ; static const char_T * rt_LoggedStateNames [ ] = { "" , "" , "" , "" , ""
, "" , "" , "" , "" , "" , "" , "" , "" , "" } ; static boolean_T
rt_LoggedStateCrossMdlRef [ ] = { 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 ,
0 , 0 , 0 } ; static RTWLogDataTypeConvert rt_RTWLogDataTypeConvert [ ] = { {
0 , SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE ,
SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0
, 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 ,
0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 ,
SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE ,
SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0
, 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 ,
0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 ,
SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE ,
SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0
, 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 ,
0.0 } } ; static int_T rt_LoggedStateIdxList [ ] = { 0 , 1 , 2 , 3 , 1 , 2 ,
3 , 4 , 5 , 6 , 7 , 8 , 9 , 10 } ; static RTWLogSignalInfo
rt_LoggedStateSignalInfo = { 14 , rt_LoggedStateWidths ,
rt_LoggedStateNumDimensions , rt_LoggedStateDimensions ,
rt_LoggedStateIsVarDims , ( NULL ) , ( NULL ) , rt_LoggedStateDataTypeIds ,
rt_LoggedStateComplexSignals , ( NULL ) , rt_LoggingStatePreprocessingFcnPtrs
, { rt_LoggedStateLabels } , ( NULL ) , ( NULL ) , ( NULL ) , {
rt_LoggedStateBlockNames } , { rt_LoggedStateNames } ,
rt_LoggedStateCrossMdlRef , rt_RTWLogDataTypeConvert , rt_LoggedStateIdxList
} ; static void * rt_LoggedStateSignalPtrs [ 14 ] ; rtliSetLogXSignalPtrs (
ssGetRTWLogInfo ( rtS ) , ( LogSignalPtrsType ) rt_LoggedStateSignalPtrs ) ;
rtliSetLogXSignalInfo ( ssGetRTWLogInfo ( rtS ) , & rt_LoggedStateSignalInfo
) ; rt_LoggedStateSignalPtrs [ 0 ] = ( void * ) & rtX . f50afzevjg [ 0 ] ;
rt_LoggedStateSignalPtrs [ 1 ] = ( void * ) & rtX . kc2egwi14h [ 0 ] ;
rt_LoggedStateSignalPtrs [ 2 ] = ( void * ) & rtX . o2igygaiml [ 0 ] ;
rt_LoggedStateSignalPtrs [ 3 ] = ( void * ) & rtX . ajbdf0rme2 [ 0 ] ;
rt_LoggedStateSignalPtrs [ 4 ] = ( void * ) & rtDW . blkvfyc1ut ;
rt_LoggedStateSignalPtrs [ 5 ] = ( void * ) & rtDW . dbof0j1l1z ;
rt_LoggedStateSignalPtrs [ 6 ] = ( void * ) & rtDW . epsgdxius2 ;
rt_LoggedStateSignalPtrs [ 7 ] = ( void * ) & rtDW . i5vdoafna1 ;
rt_LoggedStateSignalPtrs [ 8 ] = ( void * ) & rtDW . f21v3dtx13 ;
rt_LoggedStateSignalPtrs [ 9 ] = ( void * ) & rtDW . odzrzx3nyk ;
rt_LoggedStateSignalPtrs [ 10 ] = ( void * ) & rtDW . ko2emyti4i ;
rt_LoggedStateSignalPtrs [ 11 ] = ( void * ) & rtDW . hx53qo0tyb ;
rt_LoggedStateSignalPtrs [ 12 ] = ( void * ) & rtDW . hoflvlpyvq ;
rt_LoggedStateSignalPtrs [ 13 ] = ( void * ) & rtDW . bsuso3aou5 ; }
rtliSetLogT ( ssGetRTWLogInfo ( rtS ) , "tout" ) ; rtliSetLogX (
ssGetRTWLogInfo ( rtS ) , "tmp_raccel_xout" ) ; rtliSetLogXFinal (
ssGetRTWLogInfo ( rtS ) , "xFinal" ) ; rtliSetLogVarNameModifier (
ssGetRTWLogInfo ( rtS ) , "none" ) ; rtliSetLogFormat ( ssGetRTWLogInfo ( rtS
) , 2 ) ; rtliSetLogMaxRows ( ssGetRTWLogInfo ( rtS ) , 1000 ) ;
rtliSetLogDecimation ( ssGetRTWLogInfo ( rtS ) , 1 ) ; rtliSetLogY (
ssGetRTWLogInfo ( rtS ) , "" ) ; rtliSetLogYSignalInfo ( ssGetRTWLogInfo (
rtS ) , ( NULL ) ) ; rtliSetLogYSignalPtrs ( ssGetRTWLogInfo ( rtS ) , ( NULL
) ) ; } { static struct _ssStatesInfo2 statesInfo2 ; ssSetStatesInfo2 ( rtS ,
& statesInfo2 ) ; } { static ssPeriodicStatesInfo periodicStatesInfo ;
ssSetPeriodicStatesInfo ( rtS , & periodicStatesInfo ) ; } { static
ssJacobianPerturbationBounds jacobianPerturbationBounds ;
ssSetJacobianPerturbationBounds ( rtS , & jacobianPerturbationBounds ) ; } {
static ssSolverInfo slvrInfo ; static boolean_T contStatesDisabled [ 12 ] ;
static uint8_T zcAttributes [ 10 ] = { ( SL_ZCS_EVENT_ALL ) , (
SL_ZCS_EVENT_ALL ) , ( SL_ZCS_EVENT_ALL ) , ( SL_ZCS_EVENT_ALL ) , ( 0x40 |
SL_ZCS_EVENT_ALL ) , ( SL_ZCS_EVENT_ALL ) , ( 0x40 | SL_ZCS_EVENT_ALL ) , (
SL_ZCS_EVENT_ALL ) , ( SL_ZCS_EVENT_ALL ) , ( SL_ZCS_EVENT_ALL ) } ; static
ssNonContDerivSigInfo nonContDerivSigInfo [ 5 ] = { { 1 * sizeof ( real_T ) ,
( char * ) ( & rtB . h1saod1n1q ) , ( NULL ) } , { 1 * sizeof ( real_T ) , (
char * ) ( & rtB . aq2in4etwi ) , ( NULL ) } , { 1 * sizeof ( real_T ) , (
char * ) ( & rtB . crwpdhv3lp ) , ( NULL ) } , { 1 * sizeof ( real_T ) , (
char * ) ( & rtB . hxc25hdudb ) , ( NULL ) } , { 1 * sizeof ( real_T ) , (
char * ) ( & rtB . ezi3wqgg1t ) , ( NULL ) } } ; ssSetZCCacheNeedsReset ( rtS
, 1 ) ; ssSetDerivCacheNeedsReset ( rtS , 0 ) ; ssSetNumNonContDerivSigInfos
( rtS , 5 ) ; ssSetNonContDerivSigInfos ( rtS , nonContDerivSigInfo ) ;
ssSetSolverInfo ( rtS , & slvrInfo ) ; ssSetSolverName ( rtS , "ode3" ) ;
ssSetVariableStepSolver ( rtS , 0 ) ; ssSetSolverConsistencyChecking ( rtS ,
0 ) ; ssSetSolverAdaptiveZcDetection ( rtS , 0 ) ;
ssSetSolverRobustResetMethod ( rtS , 0 ) ; ssSetSolverStateProjection ( rtS ,
0 ) ; ssSetSolverMassMatrixType ( rtS , ( ssMatrixType ) 0 ) ;
ssSetSolverMassMatrixNzMax ( rtS , 0 ) ; ssSetModelOutputs ( rtS , MdlOutputs
) ; ssSetModelUpdate ( rtS , MdlUpdate ) ; ssSetModelDerivatives ( rtS ,
MdlDerivatives ) ; ssSetSolverZcSignalAttrib ( rtS , zcAttributes ) ;
ssSetSolverNumZcSignals ( rtS , 10 ) ; ssSetModelZeroCrossings ( rtS ,
MdlZeroCrossings ) ; ssSetTNextTid ( rtS , INT_MIN ) ; ssSetTNext ( rtS ,
rtMinusInf ) ; ssSetSolverNeedsReset ( rtS ) ; ssSetNumNonsampledZCs ( rtS ,
8 ) ; ssSetContStateDisabled ( rtS , contStatesDisabled ) ; }
ssSetChecksumVal ( rtS , 0 , 1405113090U ) ; ssSetChecksumVal ( rtS , 1 ,
4097125932U ) ; ssSetChecksumVal ( rtS , 2 , 3769232021U ) ; ssSetChecksumVal
( rtS , 3 , 2404196798U ) ; { static const sysRanDType rtAlwaysEnabled =
SUBSYS_RAN_BC_ENABLE ; static RTWExtModeInfo rt_ExtModeInfo ; static const
sysRanDType * systemRan [ 7 ] ; gblRTWExtModeInfo = & rt_ExtModeInfo ;
ssSetRTWExtModeInfo ( rtS , & rt_ExtModeInfo ) ;
rteiSetSubSystemActiveVectorAddresses ( & rt_ExtModeInfo , systemRan ) ;
systemRan [ 0 ] = & rtAlwaysEnabled ; systemRan [ 1 ] = & rtAlwaysEnabled ;
systemRan [ 2 ] = & rtAlwaysEnabled ; systemRan [ 3 ] = & rtAlwaysEnabled ;
systemRan [ 4 ] = & rtAlwaysEnabled ; systemRan [ 5 ] = & rtAlwaysEnabled ;
systemRan [ 6 ] = & rtAlwaysEnabled ; rteiSetModelMappingInfoPtr (
ssGetRTWExtModeInfo ( rtS ) , & ssGetModelMappingInfo ( rtS ) ) ;
rteiSetChecksumsPtr ( ssGetRTWExtModeInfo ( rtS ) , ssGetChecksums ( rtS ) )
; rteiSetTPtr ( ssGetRTWExtModeInfo ( rtS ) , ssGetTPtr ( rtS ) ) ; }
slsaDisallowedBlocksForSimTargetOP ( rtS ,
mr_sixdof_GetSimStateDisallowedBlocks ) ; slsaGetWorkFcnForSimTargetOP ( rtS
, mr_sixdof_GetDWork ) ; slsaSetWorkFcnForSimTargetOP ( rtS ,
mr_sixdof_SetDWork ) ; rtP . Saturation_UpperSat = rtInf ; rtP .
Saturation1_UpperSat = rtInf ; rt_RapidReadMatFileAndUpdateParams ( rtS ) ;
if ( ssGetErrorStatus ( rtS ) ) { return rtS ; } return rtS ; }
#if defined(_MSC_VER)
#pragma optimize( "", on )
#endif
const int_T gblParameterTuningTid = 2 ; void MdlOutputsParameterSampleTime (
int_T tid ) { MdlOutputsTID2 ( tid ) ; }
