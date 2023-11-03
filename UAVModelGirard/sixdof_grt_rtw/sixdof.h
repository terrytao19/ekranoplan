/*
 * sixdof.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "sixdof".
 *
 * Model version              : 23.7
 * Simulink Coder version : 9.9 (R2023a) 19-Nov-2022
 * C source code generated on : Thu Nov  2 17:31:06 2023
 *
 * Target selection: grt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: 32-bit Generic
 * Emulation hardware selection:
 *    Differs from embedded hardware (MATLAB Host)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_sixdof_h_
#define RTW_HEADER_sixdof_h_
#ifndef sixdof_COMMON_INCLUDES_
#define sixdof_COMMON_INCLUDES_
#include <stdio.h>
#include <string.h>
#include "rtwtypes.h"
#include "simstruc.h"
#include "fixedpoint.h"
#include "rt_logging.h"
#endif                                 /* sixdof_COMMON_INCLUDES_ */

#include "sixdof_types.h"
#include <stddef.h>
#include "rt_nonfinite.h"
#include "rtGetInf.h"
#include "rtGetNaN.h"
#include <math.h>
#include "rt_defines.h"
#include "zero_crossing_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetBlockIO
#define rtmGetBlockIO(rtm)             ((rtm)->blockIO)
#endif

#ifndef rtmSetBlockIO
#define rtmSetBlockIO(rtm, val)        ((rtm)->blockIO = (val))
#endif

#ifndef rtmGetChecksums
#define rtmGetChecksums(rtm)           ((rtm)->Sizes.checksums)
#endif

#ifndef rtmSetChecksums
#define rtmSetChecksums(rtm, val)      ((rtm)->Sizes.checksums = (val))
#endif

#ifndef rtmGetConstBlockIO
#define rtmGetConstBlockIO(rtm)        ((rtm)->constBlockIO)
#endif

#ifndef rtmSetConstBlockIO
#define rtmSetConstBlockIO(rtm, val)   ((rtm)->constBlockIO = (val))
#endif

#ifndef rtmGetContStateDisabled
#define rtmGetContStateDisabled(rtm)   ((rtm)->contStateDisabled)
#endif

#ifndef rtmSetContStateDisabled
#define rtmSetContStateDisabled(rtm, val) ((rtm)->contStateDisabled = (val))
#endif

#ifndef rtmGetContStates
#define rtmGetContStates(rtm)          ((rtm)->contStates)
#endif

#ifndef rtmSetContStates
#define rtmSetContStates(rtm, val)     ((rtm)->contStates = (val))
#endif

#ifndef rtmGetContTimeOutputInconsistentWithStateAtMajorStepFlag
#define rtmGetContTimeOutputInconsistentWithStateAtMajorStepFlag(rtm) ((rtm)->CTOutputIncnstWithState)
#endif

#ifndef rtmSetContTimeOutputInconsistentWithStateAtMajorStepFlag
#define rtmSetContTimeOutputInconsistentWithStateAtMajorStepFlag(rtm, val) ((rtm)->CTOutputIncnstWithState = (val))
#endif

#ifndef rtmGetCtrlRateMdlRefTiming
#define rtmGetCtrlRateMdlRefTiming(rtm) ()
#endif

#ifndef rtmSetCtrlRateMdlRefTiming
#define rtmSetCtrlRateMdlRefTiming(rtm, val) ()
#endif

#ifndef rtmGetCtrlRateMdlRefTimingPtr
#define rtmGetCtrlRateMdlRefTimingPtr(rtm) ()
#endif

#ifndef rtmSetCtrlRateMdlRefTimingPtr
#define rtmSetCtrlRateMdlRefTimingPtr(rtm, val) ()
#endif

#ifndef rtmGetCtrlRateNumTicksToNextHit
#define rtmGetCtrlRateNumTicksToNextHit(rtm) ()
#endif

#ifndef rtmSetCtrlRateNumTicksToNextHit
#define rtmSetCtrlRateNumTicksToNextHit(rtm, val) ()
#endif

#ifndef rtmGetDataMapInfo
#define rtmGetDataMapInfo(rtm)         ()
#endif

#ifndef rtmSetDataMapInfo
#define rtmSetDataMapInfo(rtm, val)    ()
#endif

#ifndef rtmGetDefaultParam
#define rtmGetDefaultParam(rtm)        ((rtm)->defaultParam)
#endif

#ifndef rtmSetDefaultParam
#define rtmSetDefaultParam(rtm, val)   ((rtm)->defaultParam = (val))
#endif

#ifndef rtmGetDerivCacheNeedsReset
#define rtmGetDerivCacheNeedsReset(rtm) ((rtm)->derivCacheNeedsReset)
#endif

#ifndef rtmSetDerivCacheNeedsReset
#define rtmSetDerivCacheNeedsReset(rtm, val) ((rtm)->derivCacheNeedsReset = (val))
#endif

#ifndef rtmGetDirectFeedThrough
#define rtmGetDirectFeedThrough(rtm)   ((rtm)->Sizes.sysDirFeedThru)
#endif

#ifndef rtmSetDirectFeedThrough
#define rtmSetDirectFeedThrough(rtm, val) ((rtm)->Sizes.sysDirFeedThru = (val))
#endif

#ifndef rtmGetErrorStatusFlag
#define rtmGetErrorStatusFlag(rtm)     ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatusFlag
#define rtmSetErrorStatusFlag(rtm, val) ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetFinalTime
#define rtmGetFinalTime(rtm)           ((rtm)->Timing.tFinal)
#endif

#ifndef rtmSetFinalTime
#define rtmSetFinalTime(rtm, val)      ((rtm)->Timing.tFinal = (val))
#endif

#ifndef rtmGetFirstInitCondFlag
#define rtmGetFirstInitCondFlag(rtm)   ()
#endif

#ifndef rtmSetFirstInitCondFlag
#define rtmSetFirstInitCondFlag(rtm, val) ()
#endif

#ifndef rtmGetIntgData
#define rtmGetIntgData(rtm)            ((rtm)->intgData)
#endif

#ifndef rtmSetIntgData
#define rtmSetIntgData(rtm, val)       ((rtm)->intgData = (val))
#endif

#ifndef rtmGetMdlRefGlobalRuntimeEventIndices
#define rtmGetMdlRefGlobalRuntimeEventIndices(rtm) ()
#endif

#ifndef rtmSetMdlRefGlobalRuntimeEventIndices
#define rtmSetMdlRefGlobalRuntimeEventIndices(rtm, val) ()
#endif

#ifndef rtmGetMdlRefGlobalTID
#define rtmGetMdlRefGlobalTID(rtm)     ()
#endif

#ifndef rtmSetMdlRefGlobalTID
#define rtmSetMdlRefGlobalTID(rtm, val) ()
#endif

#ifndef rtmGetMdlRefGlobalTimerIndices
#define rtmGetMdlRefGlobalTimerIndices(rtm) ()
#endif

#ifndef rtmSetMdlRefGlobalTimerIndices
#define rtmSetMdlRefGlobalTimerIndices(rtm, val) ()
#endif

#ifndef rtmGetMdlRefTriggerTID
#define rtmGetMdlRefTriggerTID(rtm)    ()
#endif

#ifndef rtmSetMdlRefTriggerTID
#define rtmSetMdlRefTriggerTID(rtm, val) ()
#endif

#ifndef rtmGetModelMappingInfo
#define rtmGetModelMappingInfo(rtm)    ((rtm)->SpecialInfo.mappingInfo)
#endif

#ifndef rtmSetModelMappingInfo
#define rtmSetModelMappingInfo(rtm, val) ((rtm)->SpecialInfo.mappingInfo = (val))
#endif

#ifndef rtmGetModelName
#define rtmGetModelName(rtm)           ((rtm)->modelName)
#endif

#ifndef rtmSetModelName
#define rtmSetModelName(rtm, val)      ((rtm)->modelName = (val))
#endif

#ifndef rtmGetNonInlinedSFcns
#define rtmGetNonInlinedSFcns(rtm)     ()
#endif

#ifndef rtmSetNonInlinedSFcns
#define rtmSetNonInlinedSFcns(rtm, val) ()
#endif

#ifndef rtmGetNumBlockIO
#define rtmGetNumBlockIO(rtm)          ((rtm)->Sizes.numBlockIO)
#endif

#ifndef rtmSetNumBlockIO
#define rtmSetNumBlockIO(rtm, val)     ((rtm)->Sizes.numBlockIO = (val))
#endif

#ifndef rtmGetNumBlockParams
#define rtmGetNumBlockParams(rtm)      ((rtm)->Sizes.numBlockPrms)
#endif

#ifndef rtmSetNumBlockParams
#define rtmSetNumBlockParams(rtm, val) ((rtm)->Sizes.numBlockPrms = (val))
#endif

#ifndef rtmGetNumBlocks
#define rtmGetNumBlocks(rtm)           ((rtm)->Sizes.numBlocks)
#endif

#ifndef rtmSetNumBlocks
#define rtmSetNumBlocks(rtm, val)      ((rtm)->Sizes.numBlocks = (val))
#endif

#ifndef rtmGetNumContStates
#define rtmGetNumContStates(rtm)       ((rtm)->Sizes.numContStates)
#endif

#ifndef rtmSetNumContStates
#define rtmSetNumContStates(rtm, val)  ((rtm)->Sizes.numContStates = (val))
#endif

#ifndef rtmGetNumDWork
#define rtmGetNumDWork(rtm)            ((rtm)->Sizes.numDwork)
#endif

#ifndef rtmSetNumDWork
#define rtmSetNumDWork(rtm, val)       ((rtm)->Sizes.numDwork = (val))
#endif

#ifndef rtmGetNumInputPorts
#define rtmGetNumInputPorts(rtm)       ((rtm)->Sizes.numIports)
#endif

#ifndef rtmSetNumInputPorts
#define rtmSetNumInputPorts(rtm, val)  ((rtm)->Sizes.numIports = (val))
#endif

#ifndef rtmGetNumNonSampledZCs
#define rtmGetNumNonSampledZCs(rtm)    ((rtm)->Sizes.numNonSampZCs)
#endif

#ifndef rtmSetNumNonSampledZCs
#define rtmSetNumNonSampledZCs(rtm, val) ((rtm)->Sizes.numNonSampZCs = (val))
#endif

#ifndef rtmGetNumOutputPorts
#define rtmGetNumOutputPorts(rtm)      ((rtm)->Sizes.numOports)
#endif

#ifndef rtmSetNumOutputPorts
#define rtmSetNumOutputPorts(rtm, val) ((rtm)->Sizes.numOports = (val))
#endif

#ifndef rtmGetNumPeriodicContStates
#define rtmGetNumPeriodicContStates(rtm) ((rtm)->Sizes.numPeriodicContStates)
#endif

#ifndef rtmSetNumPeriodicContStates
#define rtmSetNumPeriodicContStates(rtm, val) ((rtm)->Sizes.numPeriodicContStates = (val))
#endif

#ifndef rtmGetNumSFcnParams
#define rtmGetNumSFcnParams(rtm)       ((rtm)->Sizes.numSFcnPrms)
#endif

#ifndef rtmSetNumSFcnParams
#define rtmSetNumSFcnParams(rtm, val)  ((rtm)->Sizes.numSFcnPrms = (val))
#endif

#ifndef rtmGetNumSFunctions
#define rtmGetNumSFunctions(rtm)       ((rtm)->Sizes.numSFcns)
#endif

#ifndef rtmSetNumSFunctions
#define rtmSetNumSFunctions(rtm, val)  ((rtm)->Sizes.numSFcns = (val))
#endif

#ifndef rtmGetNumSampleTimes
#define rtmGetNumSampleTimes(rtm)      ((rtm)->Sizes.numSampTimes)
#endif

#ifndef rtmSetNumSampleTimes
#define rtmSetNumSampleTimes(rtm, val) ((rtm)->Sizes.numSampTimes = (val))
#endif

#ifndef rtmGetNumU
#define rtmGetNumU(rtm)                ((rtm)->Sizes.numU)
#endif

#ifndef rtmSetNumU
#define rtmSetNumU(rtm, val)           ((rtm)->Sizes.numU = (val))
#endif

#ifndef rtmGetNumY
#define rtmGetNumY(rtm)                ((rtm)->Sizes.numY)
#endif

#ifndef rtmSetNumY
#define rtmSetNumY(rtm, val)           ((rtm)->Sizes.numY = (val))
#endif

#ifndef rtmGetOdeF
#define rtmGetOdeF(rtm)                ((rtm)->odeF)
#endif

#ifndef rtmSetOdeF
#define rtmSetOdeF(rtm, val)           ((rtm)->odeF = (val))
#endif

#ifndef rtmGetOdeY
#define rtmGetOdeY(rtm)                ((rtm)->odeY)
#endif

#ifndef rtmSetOdeY
#define rtmSetOdeY(rtm, val)           ((rtm)->odeY = (val))
#endif

#ifndef rtmGetOffsetTimeArray
#define rtmGetOffsetTimeArray(rtm)     ((rtm)->Timing.offsetTimesArray)
#endif

#ifndef rtmSetOffsetTimeArray
#define rtmSetOffsetTimeArray(rtm, val) ((rtm)->Timing.offsetTimesArray = (val))
#endif

#ifndef rtmGetOffsetTimePtr
#define rtmGetOffsetTimePtr(rtm)       ((rtm)->Timing.offsetTimes)
#endif

#ifndef rtmSetOffsetTimePtr
#define rtmSetOffsetTimePtr(rtm, val)  ((rtm)->Timing.offsetTimes = (val))
#endif

#ifndef rtmGetOptions
#define rtmGetOptions(rtm)             ((rtm)->Sizes.options)
#endif

#ifndef rtmSetOptions
#define rtmSetOptions(rtm, val)        ((rtm)->Sizes.options = (val))
#endif

#ifndef rtmGetParamIsMalloced
#define rtmGetParamIsMalloced(rtm)     ()
#endif

#ifndef rtmSetParamIsMalloced
#define rtmSetParamIsMalloced(rtm, val) ()
#endif

#ifndef rtmGetPath
#define rtmGetPath(rtm)                ((rtm)->path)
#endif

#ifndef rtmSetPath
#define rtmSetPath(rtm, val)           ((rtm)->path = (val))
#endif

#ifndef rtmGetPerTaskSampleHits
#define rtmGetPerTaskSampleHits(rtm)   ()
#endif

#ifndef rtmSetPerTaskSampleHits
#define rtmSetPerTaskSampleHits(rtm, val) ()
#endif

#ifndef rtmGetPerTaskSampleHitsArray
#define rtmGetPerTaskSampleHitsArray(rtm) ((rtm)->Timing.perTaskSampleHitsArray)
#endif

#ifndef rtmSetPerTaskSampleHitsArray
#define rtmSetPerTaskSampleHitsArray(rtm, val) ((rtm)->Timing.perTaskSampleHitsArray = (val))
#endif

#ifndef rtmGetPerTaskSampleHitsPtr
#define rtmGetPerTaskSampleHitsPtr(rtm) ((rtm)->Timing.perTaskSampleHits)
#endif

#ifndef rtmSetPerTaskSampleHitsPtr
#define rtmSetPerTaskSampleHitsPtr(rtm, val) ((rtm)->Timing.perTaskSampleHits = (val))
#endif

#ifndef rtmGetPeriodicContStateIndices
#define rtmGetPeriodicContStateIndices(rtm) ((rtm)->periodicContStateIndices)
#endif

#ifndef rtmSetPeriodicContStateIndices
#define rtmSetPeriodicContStateIndices(rtm, val) ((rtm)->periodicContStateIndices = (val))
#endif

#ifndef rtmGetPeriodicContStateRanges
#define rtmGetPeriodicContStateRanges(rtm) ((rtm)->periodicContStateRanges)
#endif

#ifndef rtmSetPeriodicContStateRanges
#define rtmSetPeriodicContStateRanges(rtm, val) ((rtm)->periodicContStateRanges = (val))
#endif

#ifndef rtmGetPrevZCSigState
#define rtmGetPrevZCSigState(rtm)      ((rtm)->prevZCSigState)
#endif

#ifndef rtmSetPrevZCSigState
#define rtmSetPrevZCSigState(rtm, val) ((rtm)->prevZCSigState = (val))
#endif

#ifndef rtmGetRTWExtModeInfo
#define rtmGetRTWExtModeInfo(rtm)      ((rtm)->extModeInfo)
#endif

#ifndef rtmSetRTWExtModeInfo
#define rtmSetRTWExtModeInfo(rtm, val) ((rtm)->extModeInfo = (val))
#endif

#ifndef rtmGetRTWGeneratedSFcn
#define rtmGetRTWGeneratedSFcn(rtm)    ((rtm)->Sizes.rtwGenSfcn)
#endif

#ifndef rtmSetRTWGeneratedSFcn
#define rtmSetRTWGeneratedSFcn(rtm, val) ((rtm)->Sizes.rtwGenSfcn = (val))
#endif

#ifndef rtmGetRTWLogInfo
#define rtmGetRTWLogInfo(rtm)          ((rtm)->rtwLogInfo)
#endif

#ifndef rtmSetRTWLogInfo
#define rtmSetRTWLogInfo(rtm, val)     ((rtm)->rtwLogInfo = (val))
#endif

#ifndef rtmGetRTWRTModelMethodsInfo
#define rtmGetRTWRTModelMethodsInfo(rtm) ()
#endif

#ifndef rtmSetRTWRTModelMethodsInfo
#define rtmSetRTWRTModelMethodsInfo(rtm, val) ()
#endif

#ifndef rtmGetRTWSfcnInfo
#define rtmGetRTWSfcnInfo(rtm)         ((rtm)->sfcnInfo)
#endif

#ifndef rtmSetRTWSfcnInfo
#define rtmSetRTWSfcnInfo(rtm, val)    ((rtm)->sfcnInfo = (val))
#endif

#ifndef rtmGetRTWSolverInfo
#define rtmGetRTWSolverInfo(rtm)       ((rtm)->solverInfo)
#endif

#ifndef rtmSetRTWSolverInfo
#define rtmSetRTWSolverInfo(rtm, val)  ((rtm)->solverInfo = (val))
#endif

#ifndef rtmGetRTWSolverInfoPtr
#define rtmGetRTWSolverInfoPtr(rtm)    ((rtm)->solverInfoPtr)
#endif

#ifndef rtmSetRTWSolverInfoPtr
#define rtmSetRTWSolverInfoPtr(rtm, val) ((rtm)->solverInfoPtr = (val))
#endif

#ifndef rtmGetReservedForXPC
#define rtmGetReservedForXPC(rtm)      ((rtm)->SpecialInfo.xpcData)
#endif

#ifndef rtmSetReservedForXPC
#define rtmSetReservedForXPC(rtm, val) ((rtm)->SpecialInfo.xpcData = (val))
#endif

#ifndef rtmGetRootDWork
#define rtmGetRootDWork(rtm)           ((rtm)->dwork)
#endif

#ifndef rtmSetRootDWork
#define rtmSetRootDWork(rtm, val)      ((rtm)->dwork = (val))
#endif

#ifndef rtmGetSFunctions
#define rtmGetSFunctions(rtm)          ((rtm)->childSfunctions)
#endif

#ifndef rtmSetSFunctions
#define rtmSetSFunctions(rtm, val)     ((rtm)->childSfunctions = (val))
#endif

#ifndef rtmGetSampleHitArray
#define rtmGetSampleHitArray(rtm)      ((rtm)->Timing.sampleHitArray)
#endif

#ifndef rtmSetSampleHitArray
#define rtmSetSampleHitArray(rtm, val) ((rtm)->Timing.sampleHitArray = (val))
#endif

#ifndef rtmGetSampleHitPtr
#define rtmGetSampleHitPtr(rtm)        ((rtm)->Timing.sampleHits)
#endif

#ifndef rtmSetSampleHitPtr
#define rtmSetSampleHitPtr(rtm, val)   ((rtm)->Timing.sampleHits = (val))
#endif

#ifndef rtmGetSampleTimeArray
#define rtmGetSampleTimeArray(rtm)     ((rtm)->Timing.sampleTimesArray)
#endif

#ifndef rtmSetSampleTimeArray
#define rtmSetSampleTimeArray(rtm, val) ((rtm)->Timing.sampleTimesArray = (val))
#endif

#ifndef rtmGetSampleTimePtr
#define rtmGetSampleTimePtr(rtm)       ((rtm)->Timing.sampleTimes)
#endif

#ifndef rtmSetSampleTimePtr
#define rtmSetSampleTimePtr(rtm, val)  ((rtm)->Timing.sampleTimes = (val))
#endif

#ifndef rtmGetSampleTimeTaskIDArray
#define rtmGetSampleTimeTaskIDArray(rtm) ((rtm)->Timing.sampleTimeTaskIDArray)
#endif

#ifndef rtmSetSampleTimeTaskIDArray
#define rtmSetSampleTimeTaskIDArray(rtm, val) ((rtm)->Timing.sampleTimeTaskIDArray = (val))
#endif

#ifndef rtmGetSampleTimeTaskIDPtr
#define rtmGetSampleTimeTaskIDPtr(rtm) ((rtm)->Timing.sampleTimeTaskIDPtr)
#endif

#ifndef rtmSetSampleTimeTaskIDPtr
#define rtmSetSampleTimeTaskIDPtr(rtm, val) ((rtm)->Timing.sampleTimeTaskIDPtr = (val))
#endif

#ifndef rtmGetSelf
#define rtmGetSelf(rtm)                ()
#endif

#ifndef rtmSetSelf
#define rtmSetSelf(rtm, val)           ()
#endif

#ifndef rtmGetSimMode
#define rtmGetSimMode(rtm)             ((rtm)->simMode)
#endif

#ifndef rtmSetSimMode
#define rtmSetSimMode(rtm, val)        ((rtm)->simMode = (val))
#endif

#ifndef rtmGetSimTimeStep
#define rtmGetSimTimeStep(rtm)         ((rtm)->Timing.simTimeStep)
#endif

#ifndef rtmSetSimTimeStep
#define rtmSetSimTimeStep(rtm, val)    ((rtm)->Timing.simTimeStep = (val))
#endif

#ifndef rtmGetSolverZcSignalVector
#define rtmGetSolverZcSignalVector(rtm) ((rtm)->zcSignalVector)
#endif

#ifndef rtmSetSolverZcSignalVector
#define rtmSetSolverZcSignalVector(rtm, val) ((rtm)->zcSignalVector = (val))
#endif

#ifndef rtmGetStartTime
#define rtmGetStartTime(rtm)           ((rtm)->Timing.tStart)
#endif

#ifndef rtmSetStartTime
#define rtmSetStartTime(rtm, val)      ((rtm)->Timing.tStart = (val))
#endif

#ifndef rtmGetStepSize
#define rtmGetStepSize(rtm)            ((rtm)->Timing.stepSize)
#endif

#ifndef rtmSetStepSize
#define rtmSetStepSize(rtm, val)       ((rtm)->Timing.stepSize = (val))
#endif

#ifndef rtmGetStopRequestedFlag
#define rtmGetStopRequestedFlag(rtm)   ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequestedFlag
#define rtmSetStopRequestedFlag(rtm, val) ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetTaskCounters
#define rtmGetTaskCounters(rtm)        ()
#endif

#ifndef rtmSetTaskCounters
#define rtmSetTaskCounters(rtm, val)   ()
#endif

#ifndef rtmGetTaskTimeArray
#define rtmGetTaskTimeArray(rtm)       ((rtm)->Timing.tArray)
#endif

#ifndef rtmSetTaskTimeArray
#define rtmSetTaskTimeArray(rtm, val)  ((rtm)->Timing.tArray = (val))
#endif

#ifndef rtmGetTimePtr
#define rtmGetTimePtr(rtm)             ((rtm)->Timing.t)
#endif

#ifndef rtmSetTimePtr
#define rtmSetTimePtr(rtm, val)        ((rtm)->Timing.t = (val))
#endif

#ifndef rtmGetTimingData
#define rtmGetTimingData(rtm)          ((rtm)->Timing.timingData)
#endif

#ifndef rtmSetTimingData
#define rtmSetTimingData(rtm, val)     ((rtm)->Timing.timingData = (val))
#endif

#ifndef rtmGetU
#define rtmGetU(rtm)                   ((rtm)->inputs)
#endif

#ifndef rtmSetU
#define rtmSetU(rtm, val)              ((rtm)->inputs = (val))
#endif

#ifndef rtmGetVarNextHitTimesListPtr
#define rtmGetVarNextHitTimesListPtr(rtm) ((rtm)->Timing.varNextHitTimesList)
#endif

#ifndef rtmSetVarNextHitTimesListPtr
#define rtmSetVarNextHitTimesListPtr(rtm, val) ((rtm)->Timing.varNextHitTimesList = (val))
#endif

#ifndef rtmGetY
#define rtmGetY(rtm)                   ((rtm)->outputs)
#endif

#ifndef rtmSetY
#define rtmSetY(rtm, val)              ((rtm)->outputs = (val))
#endif

#ifndef rtmGetZCCacheNeedsReset
#define rtmGetZCCacheNeedsReset(rtm)   ((rtm)->zCCacheNeedsReset)
#endif

#ifndef rtmSetZCCacheNeedsReset
#define rtmSetZCCacheNeedsReset(rtm, val) ((rtm)->zCCacheNeedsReset = (val))
#endif

#ifndef rtmGetZCSignalValues
#define rtmGetZCSignalValues(rtm)      ((rtm)->zcSignalValues)
#endif

#ifndef rtmSetZCSignalValues
#define rtmSetZCSignalValues(rtm, val) ((rtm)->zcSignalValues = (val))
#endif

#ifndef rtmGetZCVL
#define rtmGetZCVL(rtm)                ((rtm)->zcVL)
#endif

#ifndef rtmSetZCVL
#define rtmSetZCVL(rtm, val)           ((rtm)->zcVL = (val))
#endif

#ifndef rtmGetZCVR
#define rtmGetZCVR(rtm)                ((rtm)->zcVR)
#endif

#ifndef rtmSetZCVR
#define rtmSetZCVR(rtm, val)           ((rtm)->zcVR = (val))
#endif

#ifndef rtmGetZCVZ
#define rtmGetZCVZ(rtm)                ((rtm)->zcVZ)
#endif

#ifndef rtmSetZCVZ
#define rtmSetZCVZ(rtm, val)           ((rtm)->zcVZ = (val))
#endif

#ifndef rtmGetZCt0
#define rtmGetZCt0(rtm)                ((rtm)->zct0)
#endif

#ifndef rtmSetZCt0
#define rtmSetZCt0(rtm, val)           ((rtm)->zct0 = (val))
#endif

#ifndef rtmGetZCtR
#define rtmGetZCtR(rtm)                ((rtm)->zctR)
#endif

#ifndef rtmSetZCtR
#define rtmSetZCtR(rtm, val)           ((rtm)->zctR = (val))
#endif

#ifndef rtmGetZCx0
#define rtmGetZCx0(rtm)                ((rtm)->zcx0)
#endif

#ifndef rtmSetZCx0
#define rtmSetZCx0(rtm, val)           ((rtm)->zcx0 = (val))
#endif

#ifndef rtmGetZCxR
#define rtmGetZCxR(rtm)                ((rtm)->zcxR)
#endif

#ifndef rtmSetZCxR
#define rtmSetZCxR(rtm, val)           ((rtm)->zcxR = (val))
#endif

#ifndef rtmGetZcDetectorData
#define rtmGetZcDetectorData(rtm)      ((rtm)->zcDetectorData)
#endif

#ifndef rtmSetZcDetectorData
#define rtmSetZcDetectorData(rtm, val) ((rtm)->zcDetectorData = (val))
#endif

#ifndef rtmGetZcSignalAttibutes
#define rtmGetZcSignalAttibutes(rtm)   ((rtm)->zcSignalAttributes)
#endif

#ifndef rtmSetZcSignalAttibutes
#define rtmSetZcSignalAttibutes(rtm, val) ((rtm)->zcSignalAttributes = (val))
#endif

#ifndef rtmGet_TimeOfLastOutput
#define rtmGet_TimeOfLastOutput(rtm)   ((rtm)->Timing.timeOfLastOutput)
#endif

#ifndef rtmSet_TimeOfLastOutput
#define rtmSet_TimeOfLastOutput(rtm, val) ((rtm)->Timing.timeOfLastOutput = (val))
#endif

#ifndef rtmGetdX
#define rtmGetdX(rtm)                  ((rtm)->derivs)
#endif

#ifndef rtmSetdX
#define rtmSetdX(rtm, val)             ((rtm)->derivs = (val))
#endif

#ifndef rtmGettimingBridge
#define rtmGettimingBridge(rtm)        ()
#endif

#ifndef rtmSettimingBridge
#define rtmSettimingBridge(rtm, val)   ()
#endif

#ifndef rtmGetChecksumVal
#define rtmGetChecksumVal(rtm, idx)    ((rtm)->Sizes.checksums[idx])
#endif

#ifndef rtmSetChecksumVal
#define rtmSetChecksumVal(rtm, idx, val) ((rtm)->Sizes.checksums[idx] = (val))
#endif

#ifndef rtmGetDWork
#define rtmGetDWork(rtm, idx)          ((rtm)->dwork[idx])
#endif

#ifndef rtmSetDWork
#define rtmSetDWork(rtm, idx, val)     ((rtm)->dwork[idx] = (val))
#endif

#ifndef rtmGetOffsetTime
#define rtmGetOffsetTime(rtm, idx)     ((rtm)->Timing.offsetTimes[idx])
#endif

#ifndef rtmSetOffsetTime
#define rtmSetOffsetTime(rtm, idx, val) ((rtm)->Timing.offsetTimes[idx] = (val))
#endif

#ifndef rtmGetSFunction
#define rtmGetSFunction(rtm, idx)      ((rtm)->childSfunctions[idx])
#endif

#ifndef rtmSetSFunction
#define rtmSetSFunction(rtm, idx, val) ((rtm)->childSfunctions[idx] = (val))
#endif

#ifndef rtmGetSampleTime
#define rtmGetSampleTime(rtm, idx)     ((rtm)->Timing.sampleTimes[idx])
#endif

#ifndef rtmSetSampleTime
#define rtmSetSampleTime(rtm, idx, val) ((rtm)->Timing.sampleTimes[idx] = (val))
#endif

#ifndef rtmGetSampleTimeTaskID
#define rtmGetSampleTimeTaskID(rtm, idx) ((rtm)->Timing.sampleTimeTaskIDPtr[idx])
#endif

#ifndef rtmSetSampleTimeTaskID
#define rtmSetSampleTimeTaskID(rtm, idx, val) ((rtm)->Timing.sampleTimeTaskIDPtr[idx] = (val))
#endif

#ifndef rtmGetVarNextHitTimeList
#define rtmGetVarNextHitTimeList(rtm, idx) ((rtm)->Timing.varNextHitTimesList[idx])
#endif

#ifndef rtmSetVarNextHitTimeList
#define rtmSetVarNextHitTimeList(rtm, idx, val) ((rtm)->Timing.varNextHitTimesList[idx] = (val))
#endif

#ifndef rtmIsContinuousTask
#define rtmIsContinuousTask(rtm, tid)  ((tid) == 0)
#endif

#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

#ifndef rtmIsMajorTimeStep
#define rtmIsMajorTimeStep(rtm)        (((rtm)->Timing.simTimeStep) == MAJOR_TIME_STEP)
#endif

#ifndef rtmIsMinorTimeStep
#define rtmIsMinorTimeStep(rtm)        (((rtm)->Timing.simTimeStep) == MINOR_TIME_STEP)
#endif

#ifndef rtmIsSampleHit
#define rtmIsSampleHit(rtm, sti, tid)  ((rtmIsMajorTimeStep((rtm)) && (rtm)->Timing.sampleHits[(rtm)->Timing.sampleTimeTaskIDPtr[sti]]))
#endif

#ifndef rtmGetStopRequested
#define rtmGetStopRequested(rtm)       ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
#define rtmSetStopRequested(rtm, val)  ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
#define rtmGetStopRequestedPtr(rtm)    (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
#define rtmGetT(rtm)                   (rtmGetTPtr((rtm))[0])
#endif

#ifndef rtmSetT
#define rtmSetT(rtm, val)                                        /* Do Nothing */
#endif

#ifndef rtmGetTFinal
#define rtmGetTFinal(rtm)              ((rtm)->Timing.tFinal)
#endif

#ifndef rtmSetTFinal
#define rtmSetTFinal(rtm, val)         ((rtm)->Timing.tFinal = (val))
#endif

#ifndef rtmGetTPtr
#define rtmGetTPtr(rtm)                ((rtm)->Timing.t)
#endif

#ifndef rtmSetTPtr
#define rtmSetTPtr(rtm, val)           ((rtm)->Timing.t = (val))
#endif

#ifndef rtmGetTStart
#define rtmGetTStart(rtm)              ((rtm)->Timing.tStart)
#endif

#ifndef rtmSetTStart
#define rtmSetTStart(rtm, val)         ((rtm)->Timing.tStart = (val))
#endif

#ifndef rtmGetTaskTime
#define rtmGetTaskTime(rtm, sti)       (rtmGetTPtr((rtm))[(rtm)->Timing.sampleTimeTaskIDPtr[sti]])
#endif

#ifndef rtmSetTaskTime
#define rtmSetTaskTime(rtm, sti, val)  (rtmGetTPtr((rtm))[sti] = (val))
#endif

#ifndef rtmGetTimeOfLastOutput
#define rtmGetTimeOfLastOutput(rtm)    ((rtm)->Timing.timeOfLastOutput)
#endif

#ifdef rtmGetRTWSolverInfo
#undef rtmGetRTWSolverInfo
#endif

#define rtmGetRTWSolverInfo(rtm)       &((rtm)->solverInfo)

/* Definition for use in the target main file */
#define sixdof_rtModel                 RT_MODEL_sixdof_T

/* Block signals (default storage) */
typedef struct {
  real_T pqr[3];                       /* '<S7>/pqr' */
  real_T xeyeze[3];                    /* '<S7>/xe ye ze' */
  real_T ubvbwb[3];                    /* '<S7>/ub vb wb' */
  real_T Product[3];                   /* '<S7>/Product' */
  real_T Zpositiveisdown[3];           /* '<S7>/Z-positive is down' */
  real_T airspeed_error;               /* '<Root>/Subtract4' */
  real_T Tsamp;                        /* '<S279>/Tsamp' */
  real_T Subtract;                     /* '<Root>/Subtract' */
  real_T FilterCoefficient;            /* '<S91>/Filter Coefficient' */
  real_T Sum;                          /* '<S97>/Sum' */
  real_T pitch_error;                  /* '<Root>/Subtract1' */
  real_T Tsamp_o;                      /* '<S133>/Tsamp' */
  real_T R2D3[3];                      /* '<S1>/R2D3' */
  real_T aoa;                          /* '<S19>/R2D2' */
  real_T beta;                         /* '<S19>/R2D1' */
  real_T Gain3;                        /* '<S45>/Gain3' */
  real_T Gain1;                        /* '<S45>/Gain1' */
  real_T MathFunction;                 /* '<S19>/Math Function' */
  real_T Sum_h;                        /* '<S45>/Sum' */
  real_T Subtract_c;                   /* '<S45>/Subtract' */
  real_T Gain2;                        /* '<S31>/Gain2' */
  real_T Gain3_j;                      /* '<S32>/Gain3' */
  real_T Gain1_h;                      /* '<S32>/Gain1' */
  real_T SliderGain;                   /* '<S35>/Slider Gain' */
  real_T SliderGain_e;                 /* '<S36>/Slider Gain' */
  real_T Gain3_g;                      /* '<S46>/Gain3' */
  real_T Gain1_p;                      /* '<S46>/Gain1' */
  real_T SliderGain_h;                 /* '<S50>/Slider Gain' */
  real_T Gain3_p;                      /* '<S33>/Gain3' */
  real_T Gain1_g;                      /* '<S33>/Gain1' */
  real_T SliderGain_m;                 /* '<S40>/Slider Gain' */
  real_T SliderGain_c;                 /* '<S41>/Slider Gain' */
  real_T Reshape[6];                   /* '<S9>/Reshape' */
  real_T StaticThrustlbs;              /* '<S8>/Static Thrust (lbs)' */
  real_T mps2fps;                      /* '<S8>/mps2fps' */
  real_T kg2N;                         /* '<S8>/kg2N' */
  real_T Saturation1;                  /* '<S8>/Saturation1' */
  real_T Fcn1;                         /* '<S1>/Fcn1' */
  real_T Fcn2;                         /* '<S1>/Fcn2' */
  real_T R2D2[3];                      /* '<S1>/R2D2' */
  real_T MatrixConcatenation2[36];     /* '<S17>/Matrix Concatenation2' */
  real_T Vdot[6];                      /* '<S15>/V*dot ' */
  real_T R2D1;                         /* '<S1>/R2D1' */
  real_T TmpSignalConversionAtphithetaps[3];/* '<S7>/phidot thetadot psidot' */
  real_T R2D[3];                       /* '<S12>/R2D' */
  real_T IntegralGain;                 /* '<S85>/Integral Gain' */
  real_T IntegralGain_g;               /* '<S135>/Integral Gain' */
  real_T IntegralGain_e;               /* '<S281>/Integral Gain' */
  real_T Add1;                         /* '<S45>/Add1' */
} B_sixdof_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  uav_sluav_internal_system_Way_T obj; /* '<Root>/Waypoint Follower' */
  real_T Integrator_DSTATE;            /* '<S284>/Integrator' */
  real_T UD_DSTATE;                    /* '<S277>/UD' */
  real_T Integrator_DSTATE_e;          /* '<S88>/Integrator' */
  real_T Filter_DSTATE;                /* '<S83>/Filter' */
  real_T Integrator_DSTATE_e5;         /* '<S138>/Integrator' */
  real_T UD_DSTATE_l;                  /* '<S131>/UD' */
  struct {
    void *FilePtr;
  } ToFile_PWORK;                      /* '<S12>/To File' */

  struct {
    int_T Count;
    int_T Decimation;
  } ToFile_IWORK;                      /* '<S12>/To File' */

  int_T Limitaltitude_MODE;            /* '<S54>/Limit  altitude' */
  int_T Saturation_MODE[2];            /* '<S8>/Saturation' */
  int_T Saturation1_MODE;              /* '<S8>/Saturation1' */
  int8_T MathFunction_DWORK1;          /* '<S19>/Math Function' */
  int8_T MathFunction_DWORK1_o;        /* '<S45>/Math Function' */
  boolean_T Switch_Mode;               /* '<S45>/Switch' */
  boolean_T objisempty;                /* '<Root>/Waypoint Follower' */
} DW_sixdof_T;

/* Continuous states (default storage) */
typedef struct {
  real_T pqr_CSTATE[3];                /* '<S7>/pqr' */
  real_T xeyeze_CSTATE[3];             /* '<S7>/xe ye ze' */
  real_T phithetapsi_CSTATE[3];        /* '<S7>/phi theta psi' */
  real_T ubvbwb_CSTATE[3];             /* '<S7>/ub vb wb' */
} X_sixdof_T;

/* State derivatives (default storage) */
typedef struct {
  real_T pqr_CSTATE[3];                /* '<S7>/pqr' */
  real_T xeyeze_CSTATE[3];             /* '<S7>/xe ye ze' */
  real_T phithetapsi_CSTATE[3];        /* '<S7>/phi theta psi' */
  real_T ubvbwb_CSTATE[3];             /* '<S7>/ub vb wb' */
} XDot_sixdof_T;

/* State disabled  */
typedef struct {
  boolean_T pqr_CSTATE[3];             /* '<S7>/pqr' */
  boolean_T xeyeze_CSTATE[3];          /* '<S7>/xe ye ze' */
  boolean_T phithetapsi_CSTATE[3];     /* '<S7>/phi theta psi' */
  boolean_T ubvbwb_CSTATE[3];          /* '<S7>/ub vb wb' */
} XDis_sixdof_T;

/* Zero-crossing (trigger) state */
typedef struct {
  real_T Switch_SwitchCond_ZC;         /* '<S45>/Switch' */
  real_T Limitaltitude_UprLim_ZC;      /* '<S54>/Limit  altitude' */
  real_T Limitaltitude_LwrLim_ZC;      /* '<S54>/Limit  altitude' */
  real_T Saturation_UprLim_ZC[2];      /* '<S8>/Saturation' */
  real_T Saturation_LwrLim_ZC[2];      /* '<S8>/Saturation' */
  real_T Saturation1_UprLim_ZC;        /* '<S8>/Saturation1' */
  real_T Saturation1_LwrLim_ZC;        /* '<S8>/Saturation1' */
} ZCV_sixdof_T;

#ifndef ODE3_INTG
#define ODE3_INTG

/* ODE3 Integration Data */
typedef struct {
  real_T *y;                           /* output */
  real_T *f[3];                        /* derivatives */
} ODE3_IntgData;

#endif

typedef struct {
  real_T *vL;
  real_T *vR;
  real_T *vZ;
  real_T t0;
  real_T tR;
  real_T *x0;
  real_T *xR;
} ZcDetectorData;

/* Backward compatible GRT Identifiers */
#define rtB                            sixdof_B
#define BlockIO                        B_sixdof_T
#define rtX                            sixdof_X
#define ContinuousStates               X_sixdof_T
#define rtXdot                         sixdof_XDot
#define StateDerivatives               XDot_sixdof_T
#define tXdis                          sixdof_XDis
#define StateDisabled                  XDis_sixdof_T
#define rtP                            sixdof_P
#define Parameters                     P_sixdof_T
#define rtDWork                        sixdof_DW
#define D_Work                         DW_sixdof_T
#define rtZCSignalValue                ((ZCV_sixdof_T *) sixdof_M->zcSignalVector)
#define ZCSignalValues                 ZCV_sixdof_T

/* Parameters (default storage) */
struct P_sixdof_T_ {
  real_T Apolar;                       /* Variable: Apolar
                                        * Referenced by: '<S44>/Apolar'
                                        */
  real_T CD0;                          /* Variable: CD0
                                        * Referenced by: '<S44>/CD0'
                                        */
  real_T CL0;                          /* Variable: CL0
                                        * Referenced by: '<S45>/CL0'
                                        */
  real_T CLDe;                         /* Variable: CLDe
                                        * Referenced by: '<S45>/CLDe'
                                        */
  real_T CLa;                          /* Variable: CLa
                                        * Referenced by: '<S45>/CLa'
                                        */
  real_T CLa_dot;                      /* Variable: CLa_dot
                                        * Referenced by: '<S45>/CLa_dot'
                                        */
  real_T CLq;                          /* Variable: CLq
                                        * Referenced by: '<S47>/Constant'
                                        */
  real_T CYDr;                         /* Variable: CYDr
                                        * Referenced by: '<S31>/CYDr'
                                        */
  real_T CYb;                          /* Variable: CYb
                                        * Referenced by: '<S31>/CYb'
                                        */
  real_T ClDa;                         /* Variable: ClDa
                                        * Referenced by: '<S32>/ClDa'
                                        */
  real_T ClDr;                         /* Variable: ClDr
                                        * Referenced by: '<S32>/ClDr'
                                        */
  real_T Clb;                          /* Variable: Clb
                                        * Referenced by: '<S32>/Clb'
                                        */
  real_T Clp;                          /* Variable: Clp
                                        * Referenced by: '<S34>/Constant'
                                        */
  real_T Clr;                          /* Variable: Clr
                                        * Referenced by: '<S34>/Constant1'
                                        */
  real_T Cm0;                          /* Variable: Cm0
                                        * Referenced by: '<S46>/Cm0'
                                        */
  real_T CmDe;                         /* Variable: CmDe
                                        * Referenced by: '<S46>/CmDe'
                                        */
  real_T Cma;                          /* Variable: Cma
                                        * Referenced by: '<S46>/Cma'
                                        */
  real_T Cma_dot;                      /* Variable: Cma_dot
                                        * Referenced by: '<S46>/Cma_dot'
                                        */
  real_T Cmq;                          /* Variable: Cmq
                                        * Referenced by: '<S49>/Constant'
                                        */
  real_T CnDa;                         /* Variable: CnDa
                                        * Referenced by: '<S33>/CnDa'
                                        */
  real_T CnDr;                         /* Variable: CnDr
                                        * Referenced by: '<S33>/CnDr'
                                        */
  real_T Cnb;                          /* Variable: Cnb
                                        * Referenced by: '<S33>/Cnb'
                                        */
  real_T Cnp;                          /* Variable: Cnp
                                        * Referenced by: '<S39>/Constant'
                                        */
  real_T Cnr;                          /* Variable: Cnr
                                        * Referenced by: '<S39>/Constant1'
                                        */
  real_T Euler_0[3];                   /* Variable: Euler_0
                                        * Referenced by: '<S7>/phi theta psi'
                                        */
  real_T ISA_T0;                       /* Variable: ISA_T0
                                        * Referenced by:
                                        *   '<S54>/Sea Level  Temperature'
                                        *   '<S54>/1//T0'
                                        */
  real_T ISA_g;                        /* Variable: ISA_g
                                        * Referenced by: '<S8>/kg2N'
                                        */
  real_T ISA_hmax;                     /* Variable: ISA_hmax
                                        * Referenced by: '<S54>/Limit  altitude'
                                        */
  real_T ISA_lapse;                    /* Variable: ISA_lapse
                                        * Referenced by: '<S54>/Lapse Rate'
                                        */
  real_T ISA_rho0;                     /* Variable: ISA_rho0
                                        * Referenced by: '<S54>/rho0'
                                        */
  real_T Ixx;                          /* Variable: Ixx
                                        * Referenced by: '<S17>/Ixx'
                                        */
  real_T Iyy;                          /* Variable: Iyy
                                        * Referenced by: '<S17>/Iyy'
                                        */
  real_T Izz;                          /* Variable: Izz
                                        * Referenced by: '<S17>/Izz'
                                        */
  real_T Pos_0[3];                     /* Variable: Pos_0
                                        * Referenced by: '<S7>/xe ye ze'
                                        */
  real_T chord;                        /* Variable: chord
                                        * Referenced by:
                                        *   '<S19>/span1'
                                        *   '<S24>/chord'
                                        *   '<S48>/Cmq2'
                                        *   '<S51>/Cmq2'
                                        */
  real_T mass;                         /* Variable: mass
                                        * Referenced by: '<S17>/mass'
                                        */
  real_T span;                         /* Variable: span
                                        * Referenced by:
                                        *   '<S19>/span'
                                        *   '<S24>/span'
                                        *   '<S45>/span1'
                                        *   '<S37>/Cmq2'
                                        *   '<S38>/Cmq2'
                                        *   '<S42>/Cmq2'
                                        *   '<S43>/Cmq2'
                                        */
  real_T DiscretePIDController4_D;   /* Mask Parameter: DiscretePIDController4_D
                                      * Referenced by: '<S276>/Derivative Gain'
                                      */
  real_T DiscretePIDController_D;     /* Mask Parameter: DiscretePIDController_D
                                       * Referenced by: '<S82>/Derivative Gain'
                                       */
  real_T DiscretePIDController1_D;   /* Mask Parameter: DiscretePIDController1_D
                                      * Referenced by: '<S130>/Derivative Gain'
                                      */
  real_T DiscretePIDController4_Differen;
                              /* Mask Parameter: DiscretePIDController4_Differen
                               * Referenced by: '<S277>/UD'
                               */
  real_T DiscretePIDController1_Differen;
                              /* Mask Parameter: DiscretePIDController1_Differen
                               * Referenced by: '<S131>/UD'
                               */
  real_T DiscretePIDController_I;     /* Mask Parameter: DiscretePIDController_I
                                       * Referenced by: '<S85>/Integral Gain'
                                       */
  real_T DiscretePIDController1_I;   /* Mask Parameter: DiscretePIDController1_I
                                      * Referenced by: '<S135>/Integral Gain'
                                      */
  real_T DiscretePIDController4_I;   /* Mask Parameter: DiscretePIDController4_I
                                      * Referenced by: '<S281>/Integral Gain'
                                      */
  real_T DiscretePIDController_InitialCo;
                              /* Mask Parameter: DiscretePIDController_InitialCo
                               * Referenced by: '<S83>/Filter'
                               */
  real_T DiscretePIDController4_InitialC;
                              /* Mask Parameter: DiscretePIDController4_InitialC
                               * Referenced by: '<S284>/Integrator'
                               */
  real_T DiscretePIDController_Initial_f;
                              /* Mask Parameter: DiscretePIDController_Initial_f
                               * Referenced by: '<S88>/Integrator'
                               */
  real_T DiscretePIDController1_InitialC;
                              /* Mask Parameter: DiscretePIDController1_InitialC
                               * Referenced by: '<S138>/Integrator'
                               */
  real_T DiscretePIDController_N;     /* Mask Parameter: DiscretePIDController_N
                                       * Referenced by: '<S91>/Filter Coefficient'
                                       */
  real_T DiscretePIDController4_P;   /* Mask Parameter: DiscretePIDController4_P
                                      * Referenced by: '<S289>/Proportional Gain'
                                      */
  real_T DiscretePIDController_P;     /* Mask Parameter: DiscretePIDController_P
                                       * Referenced by: '<S93>/Proportional Gain'
                                       */
  real_T DiscretePIDController1_P;   /* Mask Parameter: DiscretePIDController1_P
                                      * Referenced by: '<S143>/Proportional Gain'
                                      */
  real_T SliderGain_gain;              /* Mask Parameter: SliderGain_gain
                                        * Referenced by: '<S35>/Slider Gain'
                                        */
  real_T SliderGain1_gain;             /* Mask Parameter: SliderGain1_gain
                                        * Referenced by: '<S36>/Slider Gain'
                                        */
  real_T SliderGain_gain_b;            /* Mask Parameter: SliderGain_gain_b
                                        * Referenced by: '<S50>/Slider Gain'
                                        */
  real_T SliderGain_gain_h;            /* Mask Parameter: SliderGain_gain_h
                                        * Referenced by: '<S40>/Slider Gain'
                                        */
  real_T SliderGain1_gain_m;           /* Mask Parameter: SliderGain1_gain_m
                                        * Referenced by: '<S41>/Slider Gain'
                                        */
  real_T WindZ_XData[3002];            /* Expression: YPGwind(:,1)
                                        * Referenced by: '<S56>/WindZ'
                                        */
  real_T WindZ_YData[3002];            /* Expression: YPGwind(:,4)
                                        * Referenced by: '<S56>/WindZ'
                                        */
  real_T u_Gain;                       /* Expression: 1
                                        * Referenced by: '<S56>/   2'
                                        */
  real_T WindY_XData[3002];            /* Expression: YPGwind(:,1)
                                        * Referenced by: '<S56>/WindY'
                                        */
  real_T WindY_YData[3002];            /* Expression: YPGwind(:,2)
                                        * Referenced by: '<S56>/WindY'
                                        */
  real_T u_Gain_l;                     /* Expression: 1
                                        * Referenced by: '<S56>/   1'
                                        */
  real_T WindX_XData[3002];            /* Expression: YPGwind(:,1)
                                        * Referenced by: '<S56>/WindX'
                                        */
  real_T WindX_YData[3002];            /* Expression: YPGwind(:,3)
                                        * Referenced by: '<S56>/WindX'
                                        */
  real_T _Gain;                        /* Expression: 1
                                        * Referenced by: '<S56>/   '
                                        */
  real_T MatrixGain6_Gain[9];          /* Expression: [1 0 0 ;0 1 0 ;0  0 -1]
                                        * Referenced by: '<S55>/Matrix Gain6'
                                        */
  real_T pqr_IC[3];                    /* Expression: PQR_0'
                                        * Referenced by: '<S7>/pqr'
                                        */
  real_T airpseed_desired_Value;       /* Expression: 20
                                        * Referenced by: '<Root>/airpseed_desired'
                                        */
  real_T ubvbwb_IC[3];                 /* Expression: Vb_0'
                                        * Referenced by: '<S7>/ub vb wb'
                                        */
  real_T Zpositiveisdown_Gain[9];      /* Expression: [1 0 0;0 1 0;0 0 -1]
                                        * Referenced by: '<S7>/Z-positive is down'
                                        */
  real_T Integrator_gainval;           /* Computed Parameter: Integrator_gainval
                                        * Referenced by: '<S284>/Integrator'
                                        */
  real_T Tsamp_WtEt;                   /* Computed Parameter: Tsamp_WtEt
                                        * Referenced by: '<S279>/Tsamp'
                                        */
  real_T h_desired_Value;              /* Expression: 20
                                        * Referenced by: '<Root>/h_desired'
                                        */
  real_T Integrator_gainval_i;       /* Computed Parameter: Integrator_gainval_i
                                      * Referenced by: '<S88>/Integrator'
                                      */
  real_T Filter_gainval;               /* Computed Parameter: Filter_gainval
                                        * Referenced by: '<S83>/Filter'
                                        */
  real_T Integrator_gainval_o;       /* Computed Parameter: Integrator_gainval_o
                                      * Referenced by: '<S138>/Integrator'
                                      */
  real_T Tsamp_WtEt_k;                 /* Computed Parameter: Tsamp_WtEt_k
                                        * Referenced by: '<S133>/Tsamp'
                                        */
  real_T R2D3_Gain;                    /* Expression: 180/pi
                                        * Referenced by: '<S1>/R2D3'
                                        */
  real_T nowind_Value[3];              /* Expression: [0;0;0]
                                        * Referenced by: '<S1>/ no wind'
                                        */
  real_T R2D2_Gain;                    /* Expression: 180/pi
                                        * Referenced by: '<S19>/R2D2'
                                        */
  real_T R2D1_Gain;                    /* Expression: 180/pi
                                        * Referenced by: '<S19>/R2D1'
                                        */
  real_T D2R_Gain;                     /* Expression: pi/180
                                        * Referenced by: '<S23>/D2R'
                                        */
  real_T Deg2Rad_Gain;                 /* Expression: pi/180
                                        * Referenced by: '<S24>/Deg2Rad'
                                        */
  real_T Gain4_Gain;                   /* Expression: 1
                                        * Referenced by: '<S45>/Gain4'
                                        */
  real_T Gain3_Gain;                   /* Expression: 1
                                        * Referenced by: '<S45>/Gain3'
                                        */
  real_T Deg2Rad2_Gain;                /* Expression: pi/180
                                        * Referenced by: '<S24>/Deg2Rad2'
                                        */
  real_T Gain1_Gain;                   /* Expression: 1
                                        * Referenced by: '<S45>/Gain1'
                                        */
  real_T Constant_Value;               /* Expression: -0.248
                                        * Referenced by: '<S45>/Constant'
                                        */
  real_T Constant1_Value;              /* Expression: -0.148
                                        * Referenced by: '<S45>/Constant1'
                                        */
  real_T Switch_Threshold;             /* Expression: 0
                                        * Referenced by: '<S45>/Switch'
                                        */
  real_T Gain_Gain;                    /* Expression: -1
                                        * Referenced by: '<S30>/Gain'
                                        */
  real_T Limitaltitude_LowerSat;       /* Expression: 0
                                        * Referenced by: '<S54>/Limit  altitude'
                                        */
  real_T Constant_Value_i;             /* Expression: 0.5
                                        * Referenced by: '<S19>/Constant'
                                        */
  real_T Gain_Gain_m;                  /* Expression: 1
                                        * Referenced by: '<S24>/Gain'
                                        */
  real_T Deg2Rad1_Gain;                /* Expression: pi/180
                                        * Referenced by: '<S24>/Deg2Rad1'
                                        */
  real_T Gain1_Gain_n;                 /* Expression: 1
                                        * Referenced by: '<S31>/Gain1'
                                        */
  real_T Deg2Rad4_Gain;                /* Expression: pi/180
                                        * Referenced by: '<S24>/Deg2Rad4'
                                        */
  real_T Gain2_Gain;                   /* Expression: 1
                                        * Referenced by: '<S31>/Gain2'
                                        */
  real_T Gain1_Gain_f;                 /* Expression: 1
                                        * Referenced by: '<S24>/Gain1'
                                        */
  real_T Gain1_Gain_e;                 /* Expression: -1
                                        * Referenced by: '<S30>/Gain1'
                                        */
  real_T Gain2_Gain_h;                 /* Expression: 1
                                        * Referenced by: '<S24>/Gain2'
                                        */
  real_T Weightmatrix_Value[3];        /* Expression: [0 0 mass*ISA_g]
                                        * Referenced by: '<S9>/Weight matrix'
                                        */
  real_T Gain4_Gain_l;                 /* Expression: 1
                                        * Referenced by: '<S32>/Gain4'
                                        */
  real_T Deg2Rad3_Gain;                /* Expression: pi/180
                                        * Referenced by: '<S24>/Deg2Rad3'
                                        */
  real_T Gain3_Gain_g;                 /* Expression: 1
                                        * Referenced by: '<S32>/Gain3'
                                        */
  real_T Gain1_Gain_nb;                /* Expression: 1
                                        * Referenced by: '<S32>/Gain1'
                                        */
  real_T Cmq1_Value;                   /* Expression: .5
                                        * Referenced by: '<S37>/Cmq1'
                                        */
  real_T Cmq1_Value_d;                 /* Expression: .5
                                        * Referenced by: '<S38>/Cmq1'
                                        */
  real_T Gain3_Gain_j;                 /* Expression: 1
                                        * Referenced by: '<S24>/Gain3'
                                        */
  real_T Gain4_Gain_f;                 /* Expression: 1
                                        * Referenced by: '<S46>/Gain4'
                                        */
  real_T Gain3_Gain_f;                 /* Expression: 1
                                        * Referenced by: '<S46>/Gain3'
                                        */
  real_T Gain1_Gain_d;                 /* Expression: 1
                                        * Referenced by: '<S46>/Gain1'
                                        */
  real_T Gain4_Gain_o;                 /* Expression: 1
                                        * Referenced by: '<S24>/Gain4'
                                        */
  real_T Gain4_Gain_n;                 /* Expression: 1
                                        * Referenced by: '<S33>/Gain4'
                                        */
  real_T Gain3_Gain_gj;                /* Expression: 1
                                        * Referenced by: '<S33>/Gain3'
                                        */
  real_T Gain1_Gain_dd;                /* Expression: 1
                                        * Referenced by: '<S33>/Gain1'
                                        */
  real_T Cmq1_Value_h;                 /* Expression: .5
                                        * Referenced by: '<S42>/Cmq1'
                                        */
  real_T Cmq1_Value_a;                 /* Expression: .5
                                        * Referenced by: '<S43>/Cmq1'
                                        */
  real_T Gain5_Gain;                   /* Expression: 1
                                        * Referenced by: '<S24>/Gain5'
                                        */
  real_T Throttle2RPM_Gain;            /* Expression: 9000
                                        * Referenced by: '<S8>/Throttle2RPM'
                                        */
  real_T mps2fps_Gain;                 /* Expression: 3.280839895
                                        * Referenced by: '<S8>/mps2fps'
                                        */
  real_T Saturation_UpperSat;          /* Expression: inf
                                        * Referenced by: '<S8>/Saturation'
                                        */
  real_T Saturation_LowerSat;          /* Expression: .1
                                        * Referenced by: '<S8>/Saturation'
                                        */
  real_T lbs2kg_Gain;                  /* Expression: 0.45359237
                                        * Referenced by: '<S8>/lbs2kg'
                                        */
  real_T Saturation1_UpperSat;         /* Expression: inf
                                        * Referenced by: '<S8>/Saturation1'
                                        */
  real_T Saturation1_LowerSat;         /* Expression: 1
                                        * Referenced by: '<S8>/Saturation1'
                                        */
  real_T Constant4_Value;              /* Expression: 0
                                        * Referenced by: '<S8>/Constant4'
                                        */
  real_T R2D2_Gain_j;                  /* Expression: 180/pi
                                        * Referenced by: '<S1>/R2D2'
                                        */
  real_T Constant4_Value_c;            /* Expression: 0
                                        * Referenced by: '<S17>/Constant4'
                                        */
  real_T Constant1_Value_c[9];         /* Expression: zeros(3,3)
                                        * Referenced by: '<S17>/Constant1'
                                        */
  real_T Gain_Gain_a[9];               /* Expression: [0 0 0;0 0 -1; 0 1 0]
                                        * Referenced by: '<S18>/Gain'
                                        */
  real_T Gain1_Gain_m[9];              /* Expression: [0 0 1;0 0 0; -1 0 0]
                                        * Referenced by: '<S18>/Gain1'
                                        */
  real_T Gain2_Gain_k[9];              /* Expression: [0 -1 0;1 0 0;  0 0 0]
                                        * Referenced by: '<S18>/Gain2'
                                        */
  real_T Gain3_Gain_k;                 /* Expression: 0
                                        * Referenced by: '<S18>/Gain3'
                                        */
  real_T R2D1_Gain_g;                  /* Expression: 180/pi
                                        * Referenced by: '<S1>/R2D1'
                                        */
  real_T R2D_Gain;                     /* Expression: 180/pi
                                        * Referenced by: '<S12>/R2D'
                                        */
  real_T Constant1_Value_e[15];
             /* Expression: [0,0,20; 500, 0, 20; 500, 500, 20; 0 500 20; 0 0 20]
              * Referenced by: '<Root>/Constant1'
              */
  real_T LookaheadDistance_Value;      /* Expression: 50
                                        * Referenced by: '<Root>/Lookahead Distance'
                                        */
  uint8_T ManualSwitch1_CurrentSetting;
                             /* Computed Parameter: ManualSwitch1_CurrentSetting
                              * Referenced by: '<S1>/Manual Switch1'
                              */
};

/* Real-time Model Data Structure */
struct tag_RTM_sixdof_T {
  const char_T *path;
  const char_T *modelName;
  struct SimStruct_tag * *childSfunctions;
  const char_T *errorStatus;
  SS_SimMode simMode;
  RTWLogInfo *rtwLogInfo;
  RTWExtModeInfo *extModeInfo;
  RTWSolverInfo solverInfo;
  RTWSolverInfo *solverInfoPtr;
  void *sfcnInfo;
  void *blockIO;
  const void *constBlockIO;
  void *defaultParam;
  ZCSigState *prevZCSigState;
  real_T *contStates;
  int_T *periodicContStateIndices;
  real_T *periodicContStateRanges;
  real_T *derivs;
  void *zcSignalValues;
  void *inputs;
  void *outputs;
  boolean_T *contStateDisabled;
  boolean_T zCCacheNeedsReset;
  boolean_T derivCacheNeedsReset;
  boolean_T CTOutputIncnstWithState;
  real_T odeY[12];
  real_T odeF[3][12];
  ODE3_IntgData intgData;
  real_T *zcSignalVector;
  uint8_T zcSignalAttributes[9];
  ZcDetectorData zcDetectorData;
  real_T zcVL[9];
  real_T zcVR[9];
  real_T zcVZ[9];
  real_T zct0;
  real_T zctR;
  real_T zcx0[12];
  real_T zcxR[12];
  void *dwork;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    uint32_T checksums[4];
    uint32_T options;
    int_T numContStates;
    int_T numPeriodicContStates;
    int_T numU;
    int_T numY;
    int_T numSampTimes;
    int_T numBlocks;
    int_T numBlockIO;
    int_T numBlockPrms;
    int_T numDwork;
    int_T numSFcnPrms;
    int_T numSFcns;
    int_T numIports;
    int_T numOports;
    int_T numNonSampZCs;
    int_T sysDirFeedThru;
    int_T rtwGenSfcn;
  } Sizes;

  /*
   * SpecialInfo:
   * The following substructure contains special information
   * related to other components that are dependent on RTW.
   */
  struct {
    const void *mappingInfo;
    void *xpcData;
  } SpecialInfo;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    time_T stepSize;
    uint32_T clockTick0;
    uint32_T clockTickH0;
    time_T stepSize0;
    uint32_T clockTick1;
    uint32_T clockTickH1;
    time_T stepSize1;
    time_T tStart;
    time_T tFinal;
    time_T timeOfLastOutput;
    void *timingData;
    real_T *varNextHitTimesList;
    SimTimeStep simTimeStep;
    boolean_T stopRequestedFlag;
    time_T *sampleTimes;
    time_T *offsetTimes;
    int_T *sampleTimeTaskIDPtr;
    int_T *sampleHits;
    int_T *perTaskSampleHits;
    time_T *t;
    time_T sampleTimesArray[2];
    time_T offsetTimesArray[2];
    int_T sampleTimeTaskIDArray[2];
    int_T sampleHitArray[2];
    int_T perTaskSampleHitsArray[4];
    time_T tArray[2];
  } Timing;
};

/* Block parameters (default storage) */
extern P_sixdof_T sixdof_P;

/* Block signals (default storage) */
extern B_sixdof_T sixdof_B;

/* Continuous states (default storage) */
extern X_sixdof_T sixdof_X;

/* Disabled states (default storage) */
extern XDis_sixdof_T sixdof_XDis;

/* Block states (default storage) */
extern DW_sixdof_T sixdof_DW;

/* Model entry point functions */
extern void sixdof_initialize(void);
extern void sixdof_output(void);
extern void sixdof_update(void);
extern void sixdof_terminate(void);

/*====================*
 * External functions *
 *====================*/
extern sixdof_rtModel *sixdof(void);
extern void MdlInitializeSizes(void);
extern void MdlInitializeSampleTimes(void);
extern void MdlInitialize(void);
extern void MdlStart(void);
extern void MdlOutputs(int_T tid);
extern void MdlUpdate(int_T tid);
extern void MdlTerminate(void);

/* Real-time Model object */
extern RT_MODEL_sixdof_T *const sixdof_M;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'sixdof'
 * '<S1>'   : 'sixdof/A//C'
 * '<S2>'   : 'sixdof/Discrete PID Controller'
 * '<S3>'   : 'sixdof/Discrete PID Controller1'
 * '<S4>'   : 'sixdof/Discrete PID Controller2'
 * '<S5>'   : 'sixdof/Discrete PID Controller3'
 * '<S6>'   : 'sixdof/Discrete PID Controller4'
 * '<S7>'   : 'sixdof/A//C/6DoF EoM'
 * '<S8>'   : 'sixdof/A//C/Engine model'
 * '<S9>'   : 'sixdof/A//C/Forces & Moments'
 * '<S10>'  : 'sixdof/A//C/Global PQR'
 * '<S11>'  : 'sixdof/A//C/ISA Atmosphere & Winds'
 * '<S12>'  : 'sixdof/A//C/Output'
 * '<S13>'  : 'sixdof/A//C/sigma_ge'
 * '<S14>'  : 'sixdof/A//C/6DoF EoM/Direction Cosine Matrix from Euler Angles'
 * '<S15>'  : 'sixdof/A//C/6DoF EoM/[V1,2,3,W1,2,3]'
 * '<S16>'  : 'sixdof/A//C/6DoF EoM/phidot thetadot psidot'
 * '<S17>'  : 'sixdof/A//C/6DoF EoM/[V1,2,3,W1,2,3]/A Matrix'
 * '<S18>'  : 'sixdof/A//C/6DoF EoM/[V1,2,3,W1,2,3]/Sigma'
 * '<S19>'  : 'sixdof/A//C/Forces & Moments/AoA//Beta'
 * '<S20>'  : 'sixdof/A//C/Forces & Moments/Body Frame F & M'
 * '<S21>'  : 'sixdof/A//C/Forces & Moments/U2B1'
 * '<S22>'  : 'sixdof/A//C/Forces & Moments/U2B2'
 * '<S23>'  : 'sixdof/A//C/Forces & Moments/Body Frame F & M/Transfer to body frame'
 * '<S24>'  : 'sixdof/A//C/Forces & Moments/Body Frame F & M/Wind frame F& M'
 * '<S25>'  : 'sixdof/A//C/Forces & Moments/Body Frame F & M/Transfer to body frame/Ra2b1'
 * '<S26>'  : 'sixdof/A//C/Forces & Moments/Body Frame F & M/Transfer to body frame/Ra2b22'
 * '<S27>'  : 'sixdof/A//C/Forces & Moments/Body Frame F & M/Transfer to body frame/Ra2b1/Rb2a'
 * '<S28>'  : 'sixdof/A//C/Forces & Moments/Body Frame F & M/Transfer to body frame/Ra2b22/Rb2a'
 * '<S29>'  : 'sixdof/A//C/Forces & Moments/Body Frame F & M/Wind frame F& M/Lateral Channel'
 * '<S30>'  : 'sixdof/A//C/Forces & Moments/Body Frame F & M/Wind frame F& M/Longitudinal Channel'
 * '<S31>'  : 'sixdof/A//C/Forces & Moments/Body Frame F & M/Wind frame F& M/Lateral Channel/CY'
 * '<S32>'  : 'sixdof/A//C/Forces & Moments/Body Frame F & M/Wind frame F& M/Lateral Channel/Cl'
 * '<S33>'  : 'sixdof/A//C/Forces & Moments/Body Frame F & M/Wind frame F& M/Lateral Channel/Cn'
 * '<S34>'  : 'sixdof/A//C/Forces & Moments/Body Frame F & M/Wind frame F& M/Lateral Channel/Cl/roll factors'
 * '<S35>'  : 'sixdof/A//C/Forces & Moments/Body Frame F & M/Wind frame F& M/Lateral Channel/Cl/roll factors/Slider Gain'
 * '<S36>'  : 'sixdof/A//C/Forces & Moments/Body Frame F & M/Wind frame F& M/Lateral Channel/Cl/roll factors/Slider Gain1'
 * '<S37>'  : 'sixdof/A//C/Forces & Moments/Body Frame F & M/Wind frame F& M/Lateral Channel/Cl/roll factors/roll rate fact'
 * '<S38>'  : 'sixdof/A//C/Forces & Moments/Body Frame F & M/Wind frame F& M/Lateral Channel/Cl/roll factors/yaw rate fact'
 * '<S39>'  : 'sixdof/A//C/Forces & Moments/Body Frame F & M/Wind frame F& M/Lateral Channel/Cn/yaw factors'
 * '<S40>'  : 'sixdof/A//C/Forces & Moments/Body Frame F & M/Wind frame F& M/Lateral Channel/Cn/yaw factors/Slider Gain'
 * '<S41>'  : 'sixdof/A//C/Forces & Moments/Body Frame F & M/Wind frame F& M/Lateral Channel/Cn/yaw factors/Slider Gain1'
 * '<S42>'  : 'sixdof/A//C/Forces & Moments/Body Frame F & M/Wind frame F& M/Lateral Channel/Cn/yaw factors/roll rate fact'
 * '<S43>'  : 'sixdof/A//C/Forces & Moments/Body Frame F & M/Wind frame F& M/Lateral Channel/Cn/yaw factors/yaw rate fact'
 * '<S44>'  : 'sixdof/A//C/Forces & Moments/Body Frame F & M/Wind frame F& M/Longitudinal Channel/CD'
 * '<S45>'  : 'sixdof/A//C/Forces & Moments/Body Frame F & M/Wind frame F& M/Longitudinal Channel/CL'
 * '<S46>'  : 'sixdof/A//C/Forces & Moments/Body Frame F & M/Wind frame F& M/Longitudinal Channel/Cm'
 * '<S47>'  : 'sixdof/A//C/Forces & Moments/Body Frame F & M/Wind frame F& M/Longitudinal Channel/CL/Lif due to pitch rate'
 * '<S48>'  : 'sixdof/A//C/Forces & Moments/Body Frame F & M/Wind frame F& M/Longitudinal Channel/CL/Lif due to pitch rate/pitch rate factor'
 * '<S49>'  : 'sixdof/A//C/Forces & Moments/Body Frame F & M/Wind frame F& M/Longitudinal Channel/Cm/Lif due to pitch rate'
 * '<S50>'  : 'sixdof/A//C/Forces & Moments/Body Frame F & M/Wind frame F& M/Longitudinal Channel/Cm/Lif due to pitch rate/Slider Gain'
 * '<S51>'  : 'sixdof/A//C/Forces & Moments/Body Frame F & M/Wind frame F& M/Longitudinal Channel/Cm/Lif due to pitch rate/pitch rate factor'
 * '<S52>'  : 'sixdof/A//C/Forces & Moments/U2B1/Rb2u'
 * '<S53>'  : 'sixdof/A//C/Forces & Moments/U2B2/Rb2u'
 * '<S54>'  : 'sixdof/A//C/ISA Atmosphere & Winds/ISA'
 * '<S55>'  : 'sixdof/A//C/ISA Atmosphere & Winds/Wind model'
 * '<S56>'  : 'sixdof/A//C/ISA Atmosphere & Winds/Wind model/GetWind'
 * '<S57>'  : 'sixdof/Discrete PID Controller/Anti-windup'
 * '<S58>'  : 'sixdof/Discrete PID Controller/D Gain'
 * '<S59>'  : 'sixdof/Discrete PID Controller/Filter'
 * '<S60>'  : 'sixdof/Discrete PID Controller/Filter ICs'
 * '<S61>'  : 'sixdof/Discrete PID Controller/I Gain'
 * '<S62>'  : 'sixdof/Discrete PID Controller/Ideal P Gain'
 * '<S63>'  : 'sixdof/Discrete PID Controller/Ideal P Gain Fdbk'
 * '<S64>'  : 'sixdof/Discrete PID Controller/Integrator'
 * '<S65>'  : 'sixdof/Discrete PID Controller/Integrator ICs'
 * '<S66>'  : 'sixdof/Discrete PID Controller/N Copy'
 * '<S67>'  : 'sixdof/Discrete PID Controller/N Gain'
 * '<S68>'  : 'sixdof/Discrete PID Controller/P Copy'
 * '<S69>'  : 'sixdof/Discrete PID Controller/Parallel P Gain'
 * '<S70>'  : 'sixdof/Discrete PID Controller/Reset Signal'
 * '<S71>'  : 'sixdof/Discrete PID Controller/Saturation'
 * '<S72>'  : 'sixdof/Discrete PID Controller/Saturation Fdbk'
 * '<S73>'  : 'sixdof/Discrete PID Controller/Sum'
 * '<S74>'  : 'sixdof/Discrete PID Controller/Sum Fdbk'
 * '<S75>'  : 'sixdof/Discrete PID Controller/Tracking Mode'
 * '<S76>'  : 'sixdof/Discrete PID Controller/Tracking Mode Sum'
 * '<S77>'  : 'sixdof/Discrete PID Controller/Tsamp - Integral'
 * '<S78>'  : 'sixdof/Discrete PID Controller/Tsamp - Ngain'
 * '<S79>'  : 'sixdof/Discrete PID Controller/postSat Signal'
 * '<S80>'  : 'sixdof/Discrete PID Controller/preSat Signal'
 * '<S81>'  : 'sixdof/Discrete PID Controller/Anti-windup/Passthrough'
 * '<S82>'  : 'sixdof/Discrete PID Controller/D Gain/Internal Parameters'
 * '<S83>'  : 'sixdof/Discrete PID Controller/Filter/Disc. Forward Euler Filter'
 * '<S84>'  : 'sixdof/Discrete PID Controller/Filter ICs/Internal IC - Filter'
 * '<S85>'  : 'sixdof/Discrete PID Controller/I Gain/Internal Parameters'
 * '<S86>'  : 'sixdof/Discrete PID Controller/Ideal P Gain/Passthrough'
 * '<S87>'  : 'sixdof/Discrete PID Controller/Ideal P Gain Fdbk/Disabled'
 * '<S88>'  : 'sixdof/Discrete PID Controller/Integrator/Discrete'
 * '<S89>'  : 'sixdof/Discrete PID Controller/Integrator ICs/Internal IC'
 * '<S90>'  : 'sixdof/Discrete PID Controller/N Copy/Disabled'
 * '<S91>'  : 'sixdof/Discrete PID Controller/N Gain/Internal Parameters'
 * '<S92>'  : 'sixdof/Discrete PID Controller/P Copy/Disabled'
 * '<S93>'  : 'sixdof/Discrete PID Controller/Parallel P Gain/Internal Parameters'
 * '<S94>'  : 'sixdof/Discrete PID Controller/Reset Signal/Disabled'
 * '<S95>'  : 'sixdof/Discrete PID Controller/Saturation/Passthrough'
 * '<S96>'  : 'sixdof/Discrete PID Controller/Saturation Fdbk/Disabled'
 * '<S97>'  : 'sixdof/Discrete PID Controller/Sum/Sum_PID'
 * '<S98>'  : 'sixdof/Discrete PID Controller/Sum Fdbk/Disabled'
 * '<S99>'  : 'sixdof/Discrete PID Controller/Tracking Mode/Disabled'
 * '<S100>' : 'sixdof/Discrete PID Controller/Tracking Mode Sum/Passthrough'
 * '<S101>' : 'sixdof/Discrete PID Controller/Tsamp - Integral/TsSignalSpecification'
 * '<S102>' : 'sixdof/Discrete PID Controller/Tsamp - Ngain/Passthrough'
 * '<S103>' : 'sixdof/Discrete PID Controller/postSat Signal/Forward_Path'
 * '<S104>' : 'sixdof/Discrete PID Controller/preSat Signal/Forward_Path'
 * '<S105>' : 'sixdof/Discrete PID Controller1/Anti-windup'
 * '<S106>' : 'sixdof/Discrete PID Controller1/D Gain'
 * '<S107>' : 'sixdof/Discrete PID Controller1/Filter'
 * '<S108>' : 'sixdof/Discrete PID Controller1/Filter ICs'
 * '<S109>' : 'sixdof/Discrete PID Controller1/I Gain'
 * '<S110>' : 'sixdof/Discrete PID Controller1/Ideal P Gain'
 * '<S111>' : 'sixdof/Discrete PID Controller1/Ideal P Gain Fdbk'
 * '<S112>' : 'sixdof/Discrete PID Controller1/Integrator'
 * '<S113>' : 'sixdof/Discrete PID Controller1/Integrator ICs'
 * '<S114>' : 'sixdof/Discrete PID Controller1/N Copy'
 * '<S115>' : 'sixdof/Discrete PID Controller1/N Gain'
 * '<S116>' : 'sixdof/Discrete PID Controller1/P Copy'
 * '<S117>' : 'sixdof/Discrete PID Controller1/Parallel P Gain'
 * '<S118>' : 'sixdof/Discrete PID Controller1/Reset Signal'
 * '<S119>' : 'sixdof/Discrete PID Controller1/Saturation'
 * '<S120>' : 'sixdof/Discrete PID Controller1/Saturation Fdbk'
 * '<S121>' : 'sixdof/Discrete PID Controller1/Sum'
 * '<S122>' : 'sixdof/Discrete PID Controller1/Sum Fdbk'
 * '<S123>' : 'sixdof/Discrete PID Controller1/Tracking Mode'
 * '<S124>' : 'sixdof/Discrete PID Controller1/Tracking Mode Sum'
 * '<S125>' : 'sixdof/Discrete PID Controller1/Tsamp - Integral'
 * '<S126>' : 'sixdof/Discrete PID Controller1/Tsamp - Ngain'
 * '<S127>' : 'sixdof/Discrete PID Controller1/postSat Signal'
 * '<S128>' : 'sixdof/Discrete PID Controller1/preSat Signal'
 * '<S129>' : 'sixdof/Discrete PID Controller1/Anti-windup/Passthrough'
 * '<S130>' : 'sixdof/Discrete PID Controller1/D Gain/Internal Parameters'
 * '<S131>' : 'sixdof/Discrete PID Controller1/Filter/Differentiator'
 * '<S132>' : 'sixdof/Discrete PID Controller1/Filter/Differentiator/Tsamp'
 * '<S133>' : 'sixdof/Discrete PID Controller1/Filter/Differentiator/Tsamp/Internal Ts'
 * '<S134>' : 'sixdof/Discrete PID Controller1/Filter ICs/Internal IC - Differentiator'
 * '<S135>' : 'sixdof/Discrete PID Controller1/I Gain/Internal Parameters'
 * '<S136>' : 'sixdof/Discrete PID Controller1/Ideal P Gain/Passthrough'
 * '<S137>' : 'sixdof/Discrete PID Controller1/Ideal P Gain Fdbk/Disabled'
 * '<S138>' : 'sixdof/Discrete PID Controller1/Integrator/Discrete'
 * '<S139>' : 'sixdof/Discrete PID Controller1/Integrator ICs/Internal IC'
 * '<S140>' : 'sixdof/Discrete PID Controller1/N Copy/Disabled wSignal Specification'
 * '<S141>' : 'sixdof/Discrete PID Controller1/N Gain/Passthrough'
 * '<S142>' : 'sixdof/Discrete PID Controller1/P Copy/Disabled'
 * '<S143>' : 'sixdof/Discrete PID Controller1/Parallel P Gain/Internal Parameters'
 * '<S144>' : 'sixdof/Discrete PID Controller1/Reset Signal/Disabled'
 * '<S145>' : 'sixdof/Discrete PID Controller1/Saturation/Passthrough'
 * '<S146>' : 'sixdof/Discrete PID Controller1/Saturation Fdbk/Disabled'
 * '<S147>' : 'sixdof/Discrete PID Controller1/Sum/Sum_PID'
 * '<S148>' : 'sixdof/Discrete PID Controller1/Sum Fdbk/Disabled'
 * '<S149>' : 'sixdof/Discrete PID Controller1/Tracking Mode/Disabled'
 * '<S150>' : 'sixdof/Discrete PID Controller1/Tracking Mode Sum/Passthrough'
 * '<S151>' : 'sixdof/Discrete PID Controller1/Tsamp - Integral/TsSignalSpecification'
 * '<S152>' : 'sixdof/Discrete PID Controller1/Tsamp - Ngain/Passthrough'
 * '<S153>' : 'sixdof/Discrete PID Controller1/postSat Signal/Forward_Path'
 * '<S154>' : 'sixdof/Discrete PID Controller1/preSat Signal/Forward_Path'
 * '<S155>' : 'sixdof/Discrete PID Controller2/Anti-windup'
 * '<S156>' : 'sixdof/Discrete PID Controller2/D Gain'
 * '<S157>' : 'sixdof/Discrete PID Controller2/Filter'
 * '<S158>' : 'sixdof/Discrete PID Controller2/Filter ICs'
 * '<S159>' : 'sixdof/Discrete PID Controller2/I Gain'
 * '<S160>' : 'sixdof/Discrete PID Controller2/Ideal P Gain'
 * '<S161>' : 'sixdof/Discrete PID Controller2/Ideal P Gain Fdbk'
 * '<S162>' : 'sixdof/Discrete PID Controller2/Integrator'
 * '<S163>' : 'sixdof/Discrete PID Controller2/Integrator ICs'
 * '<S164>' : 'sixdof/Discrete PID Controller2/N Copy'
 * '<S165>' : 'sixdof/Discrete PID Controller2/N Gain'
 * '<S166>' : 'sixdof/Discrete PID Controller2/P Copy'
 * '<S167>' : 'sixdof/Discrete PID Controller2/Parallel P Gain'
 * '<S168>' : 'sixdof/Discrete PID Controller2/Reset Signal'
 * '<S169>' : 'sixdof/Discrete PID Controller2/Saturation'
 * '<S170>' : 'sixdof/Discrete PID Controller2/Saturation Fdbk'
 * '<S171>' : 'sixdof/Discrete PID Controller2/Sum'
 * '<S172>' : 'sixdof/Discrete PID Controller2/Sum Fdbk'
 * '<S173>' : 'sixdof/Discrete PID Controller2/Tracking Mode'
 * '<S174>' : 'sixdof/Discrete PID Controller2/Tracking Mode Sum'
 * '<S175>' : 'sixdof/Discrete PID Controller2/Tsamp - Integral'
 * '<S176>' : 'sixdof/Discrete PID Controller2/Tsamp - Ngain'
 * '<S177>' : 'sixdof/Discrete PID Controller2/postSat Signal'
 * '<S178>' : 'sixdof/Discrete PID Controller2/preSat Signal'
 * '<S179>' : 'sixdof/Discrete PID Controller2/Anti-windup/Passthrough'
 * '<S180>' : 'sixdof/Discrete PID Controller2/D Gain/Internal Parameters'
 * '<S181>' : 'sixdof/Discrete PID Controller2/Filter/Disc. Forward Euler Filter'
 * '<S182>' : 'sixdof/Discrete PID Controller2/Filter ICs/Internal IC - Filter'
 * '<S183>' : 'sixdof/Discrete PID Controller2/I Gain/Internal Parameters'
 * '<S184>' : 'sixdof/Discrete PID Controller2/Ideal P Gain/Passthrough'
 * '<S185>' : 'sixdof/Discrete PID Controller2/Ideal P Gain Fdbk/Disabled'
 * '<S186>' : 'sixdof/Discrete PID Controller2/Integrator/Discrete'
 * '<S187>' : 'sixdof/Discrete PID Controller2/Integrator ICs/Internal IC'
 * '<S188>' : 'sixdof/Discrete PID Controller2/N Copy/Disabled'
 * '<S189>' : 'sixdof/Discrete PID Controller2/N Gain/Internal Parameters'
 * '<S190>' : 'sixdof/Discrete PID Controller2/P Copy/Disabled'
 * '<S191>' : 'sixdof/Discrete PID Controller2/Parallel P Gain/Internal Parameters'
 * '<S192>' : 'sixdof/Discrete PID Controller2/Reset Signal/Disabled'
 * '<S193>' : 'sixdof/Discrete PID Controller2/Saturation/Passthrough'
 * '<S194>' : 'sixdof/Discrete PID Controller2/Saturation Fdbk/Disabled'
 * '<S195>' : 'sixdof/Discrete PID Controller2/Sum/Sum_PID'
 * '<S196>' : 'sixdof/Discrete PID Controller2/Sum Fdbk/Disabled'
 * '<S197>' : 'sixdof/Discrete PID Controller2/Tracking Mode/Disabled'
 * '<S198>' : 'sixdof/Discrete PID Controller2/Tracking Mode Sum/Passthrough'
 * '<S199>' : 'sixdof/Discrete PID Controller2/Tsamp - Integral/TsSignalSpecification'
 * '<S200>' : 'sixdof/Discrete PID Controller2/Tsamp - Ngain/Passthrough'
 * '<S201>' : 'sixdof/Discrete PID Controller2/postSat Signal/Forward_Path'
 * '<S202>' : 'sixdof/Discrete PID Controller2/preSat Signal/Forward_Path'
 * '<S203>' : 'sixdof/Discrete PID Controller3/Anti-windup'
 * '<S204>' : 'sixdof/Discrete PID Controller3/D Gain'
 * '<S205>' : 'sixdof/Discrete PID Controller3/Filter'
 * '<S206>' : 'sixdof/Discrete PID Controller3/Filter ICs'
 * '<S207>' : 'sixdof/Discrete PID Controller3/I Gain'
 * '<S208>' : 'sixdof/Discrete PID Controller3/Ideal P Gain'
 * '<S209>' : 'sixdof/Discrete PID Controller3/Ideal P Gain Fdbk'
 * '<S210>' : 'sixdof/Discrete PID Controller3/Integrator'
 * '<S211>' : 'sixdof/Discrete PID Controller3/Integrator ICs'
 * '<S212>' : 'sixdof/Discrete PID Controller3/N Copy'
 * '<S213>' : 'sixdof/Discrete PID Controller3/N Gain'
 * '<S214>' : 'sixdof/Discrete PID Controller3/P Copy'
 * '<S215>' : 'sixdof/Discrete PID Controller3/Parallel P Gain'
 * '<S216>' : 'sixdof/Discrete PID Controller3/Reset Signal'
 * '<S217>' : 'sixdof/Discrete PID Controller3/Saturation'
 * '<S218>' : 'sixdof/Discrete PID Controller3/Saturation Fdbk'
 * '<S219>' : 'sixdof/Discrete PID Controller3/Sum'
 * '<S220>' : 'sixdof/Discrete PID Controller3/Sum Fdbk'
 * '<S221>' : 'sixdof/Discrete PID Controller3/Tracking Mode'
 * '<S222>' : 'sixdof/Discrete PID Controller3/Tracking Mode Sum'
 * '<S223>' : 'sixdof/Discrete PID Controller3/Tsamp - Integral'
 * '<S224>' : 'sixdof/Discrete PID Controller3/Tsamp - Ngain'
 * '<S225>' : 'sixdof/Discrete PID Controller3/postSat Signal'
 * '<S226>' : 'sixdof/Discrete PID Controller3/preSat Signal'
 * '<S227>' : 'sixdof/Discrete PID Controller3/Anti-windup/Passthrough'
 * '<S228>' : 'sixdof/Discrete PID Controller3/D Gain/Internal Parameters'
 * '<S229>' : 'sixdof/Discrete PID Controller3/Filter/Disc. Forward Euler Filter'
 * '<S230>' : 'sixdof/Discrete PID Controller3/Filter ICs/Internal IC - Filter'
 * '<S231>' : 'sixdof/Discrete PID Controller3/I Gain/Internal Parameters'
 * '<S232>' : 'sixdof/Discrete PID Controller3/Ideal P Gain/Passthrough'
 * '<S233>' : 'sixdof/Discrete PID Controller3/Ideal P Gain Fdbk/Disabled'
 * '<S234>' : 'sixdof/Discrete PID Controller3/Integrator/Discrete'
 * '<S235>' : 'sixdof/Discrete PID Controller3/Integrator ICs/Internal IC'
 * '<S236>' : 'sixdof/Discrete PID Controller3/N Copy/Disabled'
 * '<S237>' : 'sixdof/Discrete PID Controller3/N Gain/Internal Parameters'
 * '<S238>' : 'sixdof/Discrete PID Controller3/P Copy/Disabled'
 * '<S239>' : 'sixdof/Discrete PID Controller3/Parallel P Gain/Internal Parameters'
 * '<S240>' : 'sixdof/Discrete PID Controller3/Reset Signal/Disabled'
 * '<S241>' : 'sixdof/Discrete PID Controller3/Saturation/Passthrough'
 * '<S242>' : 'sixdof/Discrete PID Controller3/Saturation Fdbk/Disabled'
 * '<S243>' : 'sixdof/Discrete PID Controller3/Sum/Sum_PID'
 * '<S244>' : 'sixdof/Discrete PID Controller3/Sum Fdbk/Disabled'
 * '<S245>' : 'sixdof/Discrete PID Controller3/Tracking Mode/Disabled'
 * '<S246>' : 'sixdof/Discrete PID Controller3/Tracking Mode Sum/Passthrough'
 * '<S247>' : 'sixdof/Discrete PID Controller3/Tsamp - Integral/TsSignalSpecification'
 * '<S248>' : 'sixdof/Discrete PID Controller3/Tsamp - Ngain/Passthrough'
 * '<S249>' : 'sixdof/Discrete PID Controller3/postSat Signal/Forward_Path'
 * '<S250>' : 'sixdof/Discrete PID Controller3/preSat Signal/Forward_Path'
 * '<S251>' : 'sixdof/Discrete PID Controller4/Anti-windup'
 * '<S252>' : 'sixdof/Discrete PID Controller4/D Gain'
 * '<S253>' : 'sixdof/Discrete PID Controller4/Filter'
 * '<S254>' : 'sixdof/Discrete PID Controller4/Filter ICs'
 * '<S255>' : 'sixdof/Discrete PID Controller4/I Gain'
 * '<S256>' : 'sixdof/Discrete PID Controller4/Ideal P Gain'
 * '<S257>' : 'sixdof/Discrete PID Controller4/Ideal P Gain Fdbk'
 * '<S258>' : 'sixdof/Discrete PID Controller4/Integrator'
 * '<S259>' : 'sixdof/Discrete PID Controller4/Integrator ICs'
 * '<S260>' : 'sixdof/Discrete PID Controller4/N Copy'
 * '<S261>' : 'sixdof/Discrete PID Controller4/N Gain'
 * '<S262>' : 'sixdof/Discrete PID Controller4/P Copy'
 * '<S263>' : 'sixdof/Discrete PID Controller4/Parallel P Gain'
 * '<S264>' : 'sixdof/Discrete PID Controller4/Reset Signal'
 * '<S265>' : 'sixdof/Discrete PID Controller4/Saturation'
 * '<S266>' : 'sixdof/Discrete PID Controller4/Saturation Fdbk'
 * '<S267>' : 'sixdof/Discrete PID Controller4/Sum'
 * '<S268>' : 'sixdof/Discrete PID Controller4/Sum Fdbk'
 * '<S269>' : 'sixdof/Discrete PID Controller4/Tracking Mode'
 * '<S270>' : 'sixdof/Discrete PID Controller4/Tracking Mode Sum'
 * '<S271>' : 'sixdof/Discrete PID Controller4/Tsamp - Integral'
 * '<S272>' : 'sixdof/Discrete PID Controller4/Tsamp - Ngain'
 * '<S273>' : 'sixdof/Discrete PID Controller4/postSat Signal'
 * '<S274>' : 'sixdof/Discrete PID Controller4/preSat Signal'
 * '<S275>' : 'sixdof/Discrete PID Controller4/Anti-windup/Passthrough'
 * '<S276>' : 'sixdof/Discrete PID Controller4/D Gain/Internal Parameters'
 * '<S277>' : 'sixdof/Discrete PID Controller4/Filter/Differentiator'
 * '<S278>' : 'sixdof/Discrete PID Controller4/Filter/Differentiator/Tsamp'
 * '<S279>' : 'sixdof/Discrete PID Controller4/Filter/Differentiator/Tsamp/Internal Ts'
 * '<S280>' : 'sixdof/Discrete PID Controller4/Filter ICs/Internal IC - Differentiator'
 * '<S281>' : 'sixdof/Discrete PID Controller4/I Gain/Internal Parameters'
 * '<S282>' : 'sixdof/Discrete PID Controller4/Ideal P Gain/Passthrough'
 * '<S283>' : 'sixdof/Discrete PID Controller4/Ideal P Gain Fdbk/Disabled'
 * '<S284>' : 'sixdof/Discrete PID Controller4/Integrator/Discrete'
 * '<S285>' : 'sixdof/Discrete PID Controller4/Integrator ICs/Internal IC'
 * '<S286>' : 'sixdof/Discrete PID Controller4/N Copy/Disabled wSignal Specification'
 * '<S287>' : 'sixdof/Discrete PID Controller4/N Gain/Passthrough'
 * '<S288>' : 'sixdof/Discrete PID Controller4/P Copy/Disabled'
 * '<S289>' : 'sixdof/Discrete PID Controller4/Parallel P Gain/Internal Parameters'
 * '<S290>' : 'sixdof/Discrete PID Controller4/Reset Signal/Disabled'
 * '<S291>' : 'sixdof/Discrete PID Controller4/Saturation/Passthrough'
 * '<S292>' : 'sixdof/Discrete PID Controller4/Saturation Fdbk/Disabled'
 * '<S293>' : 'sixdof/Discrete PID Controller4/Sum/Sum_PID'
 * '<S294>' : 'sixdof/Discrete PID Controller4/Sum Fdbk/Disabled'
 * '<S295>' : 'sixdof/Discrete PID Controller4/Tracking Mode/Disabled'
 * '<S296>' : 'sixdof/Discrete PID Controller4/Tracking Mode Sum/Passthrough'
 * '<S297>' : 'sixdof/Discrete PID Controller4/Tsamp - Integral/TsSignalSpecification'
 * '<S298>' : 'sixdof/Discrete PID Controller4/Tsamp - Ngain/Passthrough'
 * '<S299>' : 'sixdof/Discrete PID Controller4/postSat Signal/Forward_Path'
 * '<S300>' : 'sixdof/Discrete PID Controller4/preSat Signal/Forward_Path'
 */
#endif                                 /* RTW_HEADER_sixdof_h_ */
