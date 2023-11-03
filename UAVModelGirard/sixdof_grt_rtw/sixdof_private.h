/*
 * sixdof_private.h
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

#ifndef RTW_HEADER_sixdof_private_h_
#define RTW_HEADER_sixdof_private_h_
#include "rtwtypes.h"
#include "builtin_typeid_types.h"
#include "multiword_types.h"
#include "zero_crossing_types.h"
#include "sixdof_types.h"
#include "sixdof.h"

extern real_T rt_powd_snf(real_T u0, real_T u1);
extern void rt_mldivide_U1d6x6_U2d_njaLHVwJ(const real_T u0[36], real_T u1[6]);
int_T rt_WriteMat4FileHeader(FILE *fp,
  int32_T m,
  int32_T n,
  const char_T *name);

/* private model entry point functions */
extern void sixdof_derivatives(void);
extern void sixdof_zeroCrossings(void);

#endif                                 /* RTW_HEADER_sixdof_private_h_ */
