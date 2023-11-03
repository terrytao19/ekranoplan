/*
 * sixdof_types.h
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

#ifndef RTW_HEADER_sixdof_types_h_
#define RTW_HEADER_sixdof_types_h_
#include "rtwtypes.h"
#ifndef struct_tag_BlgwLpgj2bjudmbmVKWwDE
#define struct_tag_BlgwLpgj2bjudmbmVKWwDE

struct tag_BlgwLpgj2bjudmbmVKWwDE
{
  uint32_T f1[8];
};

#endif                                 /* struct_tag_BlgwLpgj2bjudmbmVKWwDE */

#ifndef typedef_cell_wrap_sixdof_T
#define typedef_cell_wrap_sixdof_T

typedef struct tag_BlgwLpgj2bjudmbmVKWwDE cell_wrap_sixdof_T;

#endif                                 /* typedef_cell_wrap_sixdof_T */

#ifndef struct_tag_AMX4R0dyNZSdEICQiQHj1G
#define struct_tag_AMX4R0dyNZSdEICQiQHj1G

struct tag_AMX4R0dyNZSdEICQiQHj1G
{
  int32_T isInitialized;
  cell_wrap_sixdof_T inputVarSize[3];
  real_T LookaheadDistance;
  real_T WaypointIndex;
  real_T NumWaypoints;
  real_T WaypointsInternal[15];
  boolean_T LastWaypointFlag;
  boolean_T StartFlag;
  real_T InitialPose[4];
  real_T LookaheadFactor;
  uint8_T LookaheadDistFlag;
};

#endif                                 /* struct_tag_AMX4R0dyNZSdEICQiQHj1G */

#ifndef typedef_uav_sluav_internal_system_Way_T
#define typedef_uav_sluav_internal_system_Way_T

typedef struct tag_AMX4R0dyNZSdEICQiQHj1G uav_sluav_internal_system_Way_T;

#endif                             /* typedef_uav_sluav_internal_system_Way_T */

#ifndef SS_UINT64
#define SS_UINT64                      18
#endif

#ifndef SS_INT64
#define SS_INT64                       19
#endif

/* Parameters (default storage) */
typedef struct P_sixdof_T_ P_sixdof_T;

/* Forward declaration for rtModel */
typedef struct tag_RTM_sixdof_T RT_MODEL_sixdof_T;

#endif                                 /* RTW_HEADER_sixdof_types_h_ */
