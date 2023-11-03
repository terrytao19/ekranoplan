/*
 * sixdof.c
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

#include "sixdof.h"
#include "rtwtypes.h"
#include <string.h>
#include <math.h>
#include "rt_look.h"
#include "rt_look1d.h"
#include "sixdof_private.h"
#include "rt_nonfinite.h"

/* Block signals (default storage) */
B_sixdof_T sixdof_B;

/* Continuous states */
X_sixdof_T sixdof_X;

/* Disabled State Vector */
XDis_sixdof_T sixdof_XDis;

/* Block states (default storage) */
DW_sixdof_T sixdof_DW;

/* Real-time model */
static RT_MODEL_sixdof_T sixdof_M_;
RT_MODEL_sixdof_T *const sixdof_M = &sixdof_M_;

/* Forward declaration for local functions */
static real_T sixdof_norm(const real_T x[3]);

/*
 * Writes out MAT-file header.  Returns success or failure.
 * Returns:
 * 0 - success
 * 1 - failure
 */
int_T rt_WriteMat4FileHeader(FILE *fp, int32_T m, int32_T n, const char *name)
{
  typedef enum { ELITTLE_ENDIAN, EBIG_ENDIAN } ByteOrder;

  int16_T one = 1;
  ByteOrder byteOrder = (*((int8_T *)&one)==1) ? ELITTLE_ENDIAN : EBIG_ENDIAN;
  int32_T type = (byteOrder == ELITTLE_ENDIAN) ? 0: 1000;
  int32_T imagf = 0;
  int32_T name_len = (int32_T)strlen(name) + 1;
  if ((fwrite(&type, sizeof(int32_T), 1, fp) == 0) ||
      (fwrite(&m, sizeof(int32_T), 1, fp) == 0) ||
      (fwrite(&n, sizeof(int32_T), 1, fp) == 0) ||
      (fwrite(&imagf, sizeof(int32_T), 1, fp) == 0) ||
      (fwrite(&name_len, sizeof(int32_T), 1, fp) == 0) ||
      (fwrite(name, sizeof(char), name_len, fp) == 0)) {
    return(1);
  } else {
    return(0);
  }
}                                      /* end rt_WriteMat4FileHeader */

/* Detector for Fixed step detector, for use with RTW. */
boolean_T rt_checkForEvent( RTWSolverInfo *si, real_T* vL, real_T* vR, int_T izc
  )
{
  int_T nZc = 9;
  uint8_T *zcSignalAttributes = rtsiGetSolverZcSignalAttrib(si);
  static const slZcEventType eventMatrix[4][4] = {
    /*          ZER              POS              NEG              UNK */
    { SL_ZCS_EVENT_NUL, SL_ZCS_EVENT_Z2P, SL_ZCS_EVENT_Z2N, SL_ZCS_EVENT_NUL },/* ZER */

    { SL_ZCS_EVENT_P2Z, SL_ZCS_EVENT_NUL, SL_ZCS_EVENT_P2N, SL_ZCS_EVENT_NUL },/* POS */

    { SL_ZCS_EVENT_N2Z, SL_ZCS_EVENT_N2P, SL_ZCS_EVENT_NUL, SL_ZCS_EVENT_NUL },/* NEG */

    { SL_ZCS_EVENT_NUL, SL_ZCS_EVENT_NUL, SL_ZCS_EVENT_NUL, SL_ZCS_EVENT_NUL }/* UNK */
  };

  slZcSignalSignType vLSign = (slZcSignalSignType)((vL[izc]) > 0.0 ?
    SL_ZCS_SIGN_POS :
    ((vL[izc]) < 0.0 ? SL_ZCS_SIGN_NEG : SL_ZCS_SIGN_ZERO));
  slZcSignalSignType vRSign = (slZcSignalSignType)((vR[izc]) > 0.0 ?
    SL_ZCS_SIGN_POS :
    ((vR[izc]) < 0.0 ? SL_ZCS_SIGN_NEG : SL_ZCS_SIGN_ZERO));
  slZcEventType currEv = eventMatrix[vLSign][vRSign];
  if (((currEv) & (zcSignalAttributes[izc])) != 0x00) {
    return true;
  }

  /*No Event Found, return false*/
  return false;
}

/* Simplified version Fixed cost detector, for use with RTW. */
void rt_ZcLocate( RTWSolverInfo *si )
{
  real_T tL;
  real_T tzMin;
  real_T tzMax;
  real_T tZi;
  real_T tZ;
  real_T theta;
  int_T it;
  int_T maxZcBracketingIterations = 10;
  time_T h = rtsiGetStepSize(si);
  ODE3_IntgData *id = (ODE3_IntgData *)rtsiGetSolverData(si);
  ZcDetectorData *zcData = (ZcDetectorData*) &sixdof_M->zcDetectorData;
  real_T *vL = zcData->vL;
  real_T *vR = zcData->vR;
  real_T *vZ = zcData->vZ;
  real_T t0 = zcData->t0;
  real_T *tR = &(zcData->tR);
  real_T *x0 = zcData->x0;
  real_T *xR = zcData->xR;
  int_T nZc = 9;
  real_T tLPrev = rtGetNaN();
  real_T tRPrev = rtGetNaN();
  real_T vLPrev[9];
  real_T vRPrev[9];
  real_T tTOL;
  real_T EPS = 2.220446049250313E-16;
  real_T absTol = 6.310887241768094E-30;
  real_T relTol;
  real_T vTOL = 128*EPS;
  real_T *f0 = id->f[0];
  real_T *f1 = id->f[1];
  boolean_T f1Evaluated = false;
  real_T *x = rtsiGetContStates(si);
  int_T nXc = 12;
  real_T x1[12];
  boolean_T moveRightPost = false;
  int_T ix;
  int_T izc;
  int_T bracketMovement = 0;
  time_T tnew = rtsiGetSolverStopTime(si);
  for (izc = 0; izc < nZc; ++izc) {
    vLPrev[izc] = rtGetNaN();
    vRPrev[izc] = rtGetNaN();
  }

  /* Cache the integrated solver state in x1.  Note that this state value should not
     be wrapped or projected as it is needed by the interpolant */
  (void) memcpy(x1, x,
                (uint_T)nXc*sizeof(real_T));

  /*Copy x into xR */
  (void) memcpy(xR, x,
                (uint_T)nXc*sizeof(real_T));

  /* Initiate tL at t0 and tR at t1 */
  tL = t0;
  *tR = tnew;
  it = 0;
  while ((*tR - tL > 128*EPS*tL) && (it < maxZcBracketingIterations) ) {
    /*Compute TZ */
    relTol = 128.0* EPS *(tL);
    tTOL = absTol > relTol? absTol:relTol;
    tzMin = tL + 0.5*tTOL;
    tzMax = *tR - 0.5*tTOL;
    tZ = *tR;
    for (izc = 0; izc < nZc; ++izc) {
      if (!rt_checkForEvent(si, vL, vR, izc)) {
        continue;
      }

      tZi = rtGetNaN();
      if (fabs(vR[izc] - vL[izc]) <= vTOL) {
        tZi = 0.5*(tL + *tR);
      } else if (vL[izc] == 0) {
        if (!rtIsNaN(tRPrev)) {
          if (( (vR[izc] < 0.0 && vRPrev[izc] < vR[izc]) ||
               (vR[izc] > 0.0 && vRPrev[izc] > vR[izc]) ) &&
              (fabs(vRPrev[izc] - vR[izc]) > vTOL) ) {
            tZi = (tRPrev*vR[izc] - *tR*vRPrev[izc])/(vR[izc] - vRPrev[izc]);
          }
        }

        if (rtIsNaN(tZi)) {
          tZi = 0.5*(tL + *tR);
        }
      } else if (vR[izc] == 0) {
        if (!rtIsNaN(tLPrev)) {
          if (( (vL[izc] < 0.0 && vLPrev[izc] < vL[izc]) ||
               (vL[izc] > 0.0 && vLPrev[izc] > vL[izc]) ) &&
              (fabs(vLPrev[izc] - vL[izc]) > vTOL) ) {
            tZi = (tLPrev*vL[izc] - tL*vLPrev[izc])/(vL[izc] - vLPrev[izc]);
          }
        }

        if (rtIsNaN(tZi)) {
          tZi = 0.5*(tL + *tR);
        }
      } else {
        tZi = (tL * vR[izc] - *tR * vL[izc]) / (vR[izc] - vL[izc]);
      }

      /* Enforce: tL+0.5*tol <= tZ <= tR-0.5*tol*/
      if (tZi < tzMin)
        tZi = tzMin;
      if (tZi > tzMax)
        tZi = tzMax;

      /* track the earliest event*/
      if (tZi < tZ) {
        tZ = tZi;
      }
    }

    /*End Compute TZ*/

    /*Interpolation Formula*/
    /* Two-point Hermite Interpolant */
    theta = (tZ - t0)/h;
    if (!f1Evaluated) {
      rtsiSetT(si, tnew);
      rtsiSetdX(si, f1);
      sixdof_output();
      sixdof_derivatives();
      f1Evaluated = true;
    }

    for (ix = 0; ix < nXc; ++ix) {
      x[ix] = (1.0 - theta) * x0[ix] + theta * x1[ix] + theta * (theta - 1.0)
        *((1.0 - 2.0 * theta) * (x1[ix] - x0[ix]) + (theta - 1.0) * h * f0[ix] +
          theta * h * f1[ix]);
    }

    rtsiSetT(si, tZ);

    /* compute zc signal with interpolated state
       Need to call both projections and wrapped states before hand*/
    sixdof_output();
    rtsiSetSolverZcSignalVector(si, vZ);
    sixdof_zeroCrossings();

    /*Determine bracket movement*/
    for (izc = 0; izc < nZc; ++izc) {
      moveRightPost = rt_checkForEvent(si, vL, vZ, izc);
      if (moveRightPost) {
        break;
      }
    }

    /* Movement of the bracket */
    if (moveRightPost) {
      /*move the right post leftward*/
      if (bracketMovement < 0) {
        if (bracketMovement < -1) {
          for (izc = 0; izc < nZc; ++izc) {
            if (fabs(vL[izc]) > EPS)
              vL[izc] *= 0.5;
          }
        }

        --bracketMovement;
      } else {
        bracketMovement = -1;
      }

      tRPrev = *tR ;
      tLPrev = rtGetNaN();
      (void) memcpy(vRPrev, vR,
                    (uint_T)nZc*sizeof(real_T));
      *tR = tZ;
      (void) memcpy(vR, vZ,
                    (uint_T)nZc*sizeof(real_T));
      (void) memcpy(xR, x,
                    (uint_T)nXc*sizeof(real_T));
    } else {
      /* move the left post rightward*/
      if (bracketMovement > 0) {
        if (bracketMovement > 1) {
          for (izc = 0; izc < nZc; ++izc) {
            if (fabs(vR[izc]) > EPS)
              vR[izc] *= 0.5;
          }
        }

        ++bracketMovement;
      } else {
        bracketMovement = 1;
      }

      tLPrev = tL ;
      tRPrev = rtGetNaN();
      (void) memcpy(vLPrev, vL,
                    (uint_T)nZc*sizeof(real_T));
      tL = tZ;
      (void) memcpy(vL, vZ,
                    (uint_T)nZc*sizeof(real_T));
    }

    /* End Bracket Movement*/
    it++;
  }

  (void) memcpy(x, x1,
                (uint_T)nXc*sizeof(real_T));
}                                      /* end rt_ZcLocate */

/*
 * This function updates continuous states using the ODE3 fixed-step
 * solver algorithm
 */
static void rt_ertODEIntegrate(RTWSolverInfo *si )
{
  /* Solver Matrices */
  static const real_T rt_ODE3_A[3] = {
    1.0/2.0, 3.0/4.0, 1.0
  };

  static const real_T rt_ODE3_B[3][3] = {
    { 1.0/2.0, 0.0, 0.0 },

    { 0.0, 3.0/4.0, 0.0 },

    { 2.0/9.0, 1.0/3.0, 4.0/9.0 }
  };

  time_T t = rtsiGetT(si);
  time_T tnew = rtsiGetSolverStopTime(si);
  time_T h = rtsiGetStepSize(si);
  real_T *x = rtsiGetContStates(si);
  ODE3_IntgData *id = (ODE3_IntgData *)rtsiGetSolverData(si);
  real_T *y = id->y;
  real_T *f0 = id->f[0];
  real_T *f1 = id->f[1];
  real_T *f2 = id->f[2];
  real_T hB[3];
  int_T i;
  int_T nXc = 12;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);

  /* Save the state values at time t in y, we'll use x as ynew. */
  (void) memcpy(y, x,
                (uint_T)nXc*sizeof(real_T));

  /* Assumes that rtsiSetT and ModelOutputs are up-to-date */
  /* f0 = f(t,y) */
  rtsiSetdX(si, f0);
  sixdof_derivatives();

  /* f(:,2) = feval(odefile, t + hA(1), y + f*hB(:,1), args(:)(*)); */
  hB[0] = h * rt_ODE3_B[0][0];
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[0]);
  rtsiSetdX(si, f1);
  sixdof_output();
  sixdof_derivatives();

  /* f(:,3) = feval(odefile, t + hA(2), y + f*hB(:,2), args(:)(*)); */
  for (i = 0; i <= 1; i++) {
    hB[i] = h * rt_ODE3_B[1][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[1]);
  rtsiSetdX(si, f2);
  sixdof_output();
  sixdof_derivatives();

  /* tnew = t + hA(3);
     ynew = y + f*hB(:,3); */
  for (i = 0; i <= 2; i++) {
    hB[i] = h * rt_ODE3_B[2][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1] + f2[i]*hB[2]);
  }

  rtsiSetT(si, tnew);
}

/*
 * This function updates continuous states using the ODE3 fixed-step
 * solver algorithm
 */
static void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si )
{
  time_T tnew = rtsiGetSolverStopTime(si);
  time_T h = rtsiGetStepSize(si);
  real_T *x = rtsiGetContStates(si);
  int_T nXc = 12;
  ZcDetectorData *zcData = (ZcDetectorData*) &sixdof_M->zcDetectorData;
  real_T *vL = zcData->vL;
  real_T *vR = zcData->vR;
  real_T *vZ = zcData->vZ;
  real_T *x0 = zcData->x0;
  real_T *xR = zcData->xR;
  int_T nZc = 9;
  int_T numZcEventsFound;
  int_T maxNumZcEventsPerStep = 2;
  int_T izc;
  boolean_T hadEvent = false;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);

  /*Maintain a copy of the time and state at prior to integration*/
  zcData->t0 = rtsiGetT(si);
  (void) memcpy(x0, x,
                (uint_T)nXc*sizeof(real_T));

  /*Evaluate ZC at beginning of integration interval*/
  sixdof_output();
  rtsiSetSolverZcSignalVector(si, vL);
  sixdof_zeroCrossings();

  /*First trial integration */
  rt_ertODEIntegrate(&sixdof_M->solverInfo);

  /* Evaluate ZC at end of integration interval*/
  sixdof_output();
  rtsiSetSolverZcSignalVector(si, vR);
  sixdof_zeroCrossings();

  /*If zero crossing occurred, react to zero crossing and integrate */
  numZcEventsFound = 0;
  hadEvent = false;
  for (izc = 0; izc < nZc; ++izc) {
    hadEvent = rt_checkForEvent(si, vL, vR, izc);
    if (hadEvent) {
      break;
    }
  }

  while ((numZcEventsFound < maxNumZcEventsPerStep) && hadEvent) {
    numZcEventsFound++;

    /* Locate the zero Crossing */
    rt_ZcLocate(&sixdof_M->solverInfo);
    if (!(zcData->tR < tnew)) {
      /*If tR == tNew, then we don't need to do anything*/
      break;
    } else {
      /* Reset the current time to tR, xR */
      rtsiSetT(si, zcData->tR);
      (void) memcpy(x, xR,
                    (uint_T)nXc*sizeof(real_T));

      /* Block react to zc Event*/
      rtsiSetIsMinorTimeStepWithModeChange(si, true);
      sixdof_output();
      sixdof_update();
      rtsiSetIsMinorTimeStepWithModeChange(si, false);

      /*Maintain a copy of the state at prior to integration*/
      (void) memcpy(x0, x,
                    (uint_T)nXc*sizeof(real_T));

      /*Evaluate ZC at beginning of integration interval*/
      sixdof_output();
      rtsiSetSolverZcSignalVector(si, vL);
      sixdof_zeroCrossings();

      /* Integrate from tR to t1 */
      zcData->t0 = rtsiGetT(si);
      rtsiSetStepSize(si, tnew - zcData->tR);
      rt_ertODEIntegrate(&sixdof_M->solverInfo);

      /* Evaluate ZC at end of integration interval*/
      sixdof_output();
      rtsiSetSolverZcSignalVector(si, vR);
      sixdof_zeroCrossings();
      hadEvent = false;
      for (izc = 0; izc < nZc; ++izc) {
        hadEvent = rt_checkForEvent(si, vL, vR, izc);
        if (hadEvent) {
          break;
        }
      }
    }
  }

  /* Restore the step size */
  rtsiSetStepSize(si, h);

  /* Advance time */
  rtsiSetT(si, tnew);
  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

real_T rt_powd_snf(real_T u0, real_T u1)
{
  real_T tmp;
  real_T tmp_0;
  real_T y;
  if (rtIsNaN(u0) || rtIsNaN(u1)) {
    y = (rtNaN);
  } else {
    tmp = fabs(u0);
    tmp_0 = fabs(u1);
    if (rtIsInf(u1)) {
      if (tmp == 1.0) {
        y = 1.0;
      } else if (tmp > 1.0) {
        if (u1 > 0.0) {
          y = (rtInf);
        } else {
          y = 0.0;
        }
      } else if (u1 > 0.0) {
        y = 0.0;
      } else {
        y = (rtInf);
      }
    } else if (tmp_0 == 0.0) {
      y = 1.0;
    } else if (tmp_0 == 1.0) {
      if (u1 > 0.0) {
        y = u0;
      } else {
        y = 1.0 / u0;
      }
    } else if (u1 == 2.0) {
      y = u0 * u0;
    } else if ((u1 == 0.5) && (u0 >= 0.0)) {
      y = sqrt(u0);
    } else if ((u0 < 0.0) && (u1 > floor(u1))) {
      y = (rtNaN);
    } else {
      y = pow(u0, u1);
    }
  }

  return y;
}

void rt_mldivide_U1d6x6_U2d_njaLHVwJ(const real_T u0[36], real_T u1[6])
{
  real_T x[36];
  real_T s;
  real_T smax;
  int32_T c;
  int32_T c_0;
  int32_T ijA;
  int32_T ix;
  int32_T iy;
  int32_T jA;
  int32_T jj;
  int32_T jp1j;
  int32_T kAcol;
  int8_T ipiv[6];
  int8_T ipiv_0;
  memcpy(&x[0], &u0[0], 36U * sizeof(real_T));
  for (ix = 0; ix < 6; ix++) {
    ipiv[ix] = (int8_T)(ix + 1);
  }

  for (kAcol = 0; kAcol < 5; kAcol++) {
    c = kAcol * 7 + 2;
    jj = kAcol * 7;
    c_0 = 6 - kAcol;
    iy = 1;
    smax = fabs(x[jj]);
    for (jA = 2; jA <= c_0; jA++) {
      s = fabs(x[(c + jA) - 3]);
      if (s > smax) {
        iy = jA;
        smax = s;
      }
    }

    if (x[(c + iy) - 3] != 0.0) {
      if (iy - 1 != 0) {
        ix = kAcol + iy;
        ipiv[kAcol] = (int8_T)ix;
        for (jA = 0; jA < 6; jA++) {
          iy = jA * 6 + kAcol;
          smax = x[iy];
          jp1j = (jA * 6 + ix) - 1;
          x[iy] = x[jp1j];
          x[jp1j] = smax;
        }
      }

      iy = c - kAcol;
      for (ix = c; ix <= iy + 4; ix++) {
        x[ix - 1] /= x[jj];
      }
    }

    c_0 = 4 - kAcol;
    jA = jj;
    jj += 6;
    for (jp1j = 0; jp1j <= c_0; jp1j++) {
      smax = x[jp1j * 6 + jj];
      if (smax != 0.0) {
        iy = jA + 8;
        ix = (jA - kAcol) + 12;
        for (ijA = iy; ijA <= ix; ijA++) {
          x[ijA - 1] += x[((c + ijA) - jA) - 9] * -smax;
        }
      }

      jA += 6;
    }

    ipiv_0 = ipiv[kAcol];
    if (kAcol + 1 != ipiv_0) {
      smax = u1[kAcol];
      u1[kAcol] = u1[ipiv_0 - 1];
      u1[ipiv_0 - 1] = smax;
    }
  }

  for (jA = 0; jA < 6; jA++) {
    kAcol = 6 * jA - 1;
    if (u1[jA] != 0.0) {
      for (ix = jA + 2; ix < 7; ix++) {
        u1[ix - 1] -= x[ix + kAcol] * u1[jA];
      }
    }
  }

  for (jA = 5; jA >= 0; jA--) {
    kAcol = 6 * jA;
    smax = u1[jA];
    if (smax != 0.0) {
      u1[jA] = smax / x[jA + kAcol];
      iy = jA - 1;
      for (ix = 0; ix <= iy; ix++) {
        u1[ix] -= x[ix + kAcol] * u1[jA];
      }
    }
  }
}

static real_T sixdof_norm(const real_T x[3])
{
  real_T absxk;
  real_T scale;
  real_T t;
  real_T y;
  scale = 3.3121686421112381E-170;
  absxk = fabs(x[0]);
  if (absxk > 3.3121686421112381E-170) {
    y = 1.0;
    scale = absxk;
  } else {
    t = absxk / 3.3121686421112381E-170;
    y = t * t;
  }

  absxk = fabs(x[1]);
  if (absxk > scale) {
    t = scale / absxk;
    y = y * t * t + 1.0;
    scale = absxk;
  } else {
    t = absxk / scale;
    y += t * t;
  }

  absxk = fabs(x[2]);
  if (absxk > scale) {
    t = scale / absxk;
    y = y * t * t + 1.0;
    scale = absxk;
  } else {
    t = absxk / scale;
    y += t * t;
  }

  return scale * sqrt(y);
}

/* Model output function */
void sixdof_output(void)
{
  real_T rtb_MatrixConcatenation_0[36];
  real_T rtb_MatrixConcatenation_1[36];
  real_T rtb_MatrixConcatenation[18];
  real_T rtb_MatrixConcatenation1[18];
  real_T b_waypointsIn_data[15];
  real_T waypoints_data[15];
  real_T rtb_Deg2Rad_0[9];
  real_T rtb_MathFunction_o[9];
  real_T rtb_MathFunction1_0[6];
  real_T tmp[6];
  real_T rtb_Gain2[3];
  real_T rtb_VectorConcatenate_0[3];
  real_T rtb_phithetapsi[3];
  real_T Weightmatrix_Value;
  real_T Weightmatrix_Value_0;
  real_T Weightmatrix_Value_1;
  real_T rtb_CD;
  real_T rtb_Deg2Rad;
  real_T rtb_Deg2Rad2;
  real_T rtb_Deg2Rad3;
  real_T rtb_Deg2Rad4;
  real_T rtb_MathFunction_f;
  real_T rtb_MathFunction_f_0;
  real_T rtb_Product_h;
  real_T rtb_Saturation_idx_1;
  real_T rtb_Sum2;
  real_T rtb_Sum_h;
  real_T rtb_u2_h;
  real_T rtb_u2_o;
  int32_T b_exponent;
  int32_T b_exponent_0;
  int32_T i;
  int32_T i2;
  int32_T ix;
  int32_T iy;
  int32_T waypoints_data_tmp;
  int8_T tmp_data[5];
  boolean_T x[12];
  boolean_T distinctWptsIdx[5];
  boolean_T y[4];
  boolean_T exitg1;
  boolean_T guard1;
  boolean_T guard2;
  boolean_T p;
  boolean_T p_0;
  if (rtmIsMajorTimeStep(sixdof_M)) {
    /* set solver stop time */
    if (!(sixdof_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&sixdof_M->solverInfo,
                            ((sixdof_M->Timing.clockTickH0 + 1) *
        sixdof_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&sixdof_M->solverInfo, ((sixdof_M->Timing.clockTick0
        + 1) * sixdof_M->Timing.stepSize0 + sixdof_M->Timing.clockTickH0 *
        sixdof_M->Timing.stepSize0 * 4294967296.0));
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(sixdof_M)) {
    sixdof_M->Timing.t[0] = rtsiGetT(&sixdof_M->solverInfo);
  }

  /* Integrator: '<S7>/pqr' */
  sixdof_B.pqr[0] = sixdof_X.pqr_CSTATE[0];
  sixdof_B.pqr[1] = sixdof_X.pqr_CSTATE[1];
  sixdof_B.pqr[2] = sixdof_X.pqr_CSTATE[2];
  if (rtmIsMajorTimeStep(sixdof_M)) {
  }

  /* Integrator: '<S7>/xe ye ze' */
  sixdof_B.xeyeze[0] = sixdof_X.xeyeze_CSTATE[0];
  sixdof_B.xeyeze[1] = sixdof_X.xeyeze_CSTATE[1];
  sixdof_B.xeyeze[2] = sixdof_X.xeyeze_CSTATE[2];
  if (rtmIsMajorTimeStep(sixdof_M)) {
  }

  /* Integrator: '<S7>/phi theta psi' */
  rtb_phithetapsi[0] = sixdof_X.phithetapsi_CSTATE[0];

  /* Integrator: '<S7>/ub vb wb' */
  sixdof_B.ubvbwb[0] = sixdof_X.ubvbwb_CSTATE[0];

  /* Integrator: '<S7>/phi theta psi' */
  rtb_phithetapsi[1] = sixdof_X.phithetapsi_CSTATE[1];

  /* Integrator: '<S7>/ub vb wb' */
  sixdof_B.ubvbwb[1] = sixdof_X.ubvbwb_CSTATE[1];

  /* Integrator: '<S7>/phi theta psi' */
  rtb_phithetapsi[2] = sixdof_X.phithetapsi_CSTATE[2];

  /* Integrator: '<S7>/ub vb wb' */
  sixdof_B.ubvbwb[2] = sixdof_X.ubvbwb_CSTATE[2];

  /* Fcn: '<S14>/11' incorporates:
   *  Fcn: '<S14>/21'
   *  Fcn: '<S14>/22'
   *  Fcn: '<S14>/32'
   *  Integrator: '<S7>/phi theta psi'
   */
  rtb_Deg2Rad = cos(sixdof_X.phithetapsi_CSTATE[2]);

  /* Fcn: '<S14>/21' incorporates:
   *  Fcn: '<S14>/12'
   *  Fcn: '<S14>/22'
   *  Fcn: '<S14>/23'
   *  Fcn: '<S14>/31'
   *  Fcn: '<S14>/32'
   *  Fcn: '<S14>/33'
   *  Integrator: '<S7>/phi theta psi'
   */
  rtb_Product_h = cos(sixdof_X.phithetapsi_CSTATE[0]);
  rtb_CD = sin(sixdof_X.phithetapsi_CSTATE[2]);
  rtb_u2_h = sin(sixdof_X.phithetapsi_CSTATE[0]);

  /* Fcn: '<S14>/11' incorporates:
   *  Fcn: '<S14>/12'
   *  Fcn: '<S14>/23'
   *  Fcn: '<S14>/33'
   *  Integrator: '<S7>/phi theta psi'
   */
  rtb_Sum2 = cos(sixdof_X.phithetapsi_CSTATE[1]);

  /* Fcn: '<S14>/21' incorporates:
   *  Fcn: '<S14>/13'
   *  Fcn: '<S14>/22'
   *  Integrator: '<S7>/phi theta psi'
   */
  rtb_u2_o = sin(sixdof_X.phithetapsi_CSTATE[1]);

  /* Product: '<S7>/Product' incorporates:
   *  Fcn: '<S14>/11'
   *  Fcn: '<S14>/12'
   *  Fcn: '<S14>/13'
   *  Fcn: '<S14>/21'
   *  Fcn: '<S14>/22'
   *  Fcn: '<S14>/23'
   *  Fcn: '<S14>/31'
   *  Fcn: '<S14>/32'
   *  Fcn: '<S14>/33'
   *  Integrator: '<S7>/phi theta psi'
   */
  rtb_Deg2Rad_0[0] = rtb_Deg2Rad * rtb_Sum2;
  rtb_Deg2Rad_0[3] = rtb_Deg2Rad * rtb_u2_o * rtb_u2_h - rtb_CD * rtb_Product_h;
  rtb_Deg2Rad_0[6] = cos(sixdof_X.phithetapsi_CSTATE[2]) * sin
    (sixdof_X.phithetapsi_CSTATE[1]) * rtb_Product_h + rtb_CD * rtb_u2_h;
  rtb_Deg2Rad_0[1] = rtb_CD * rtb_Sum2;
  rtb_Deg2Rad_0[4] = rtb_CD * rtb_u2_o * rtb_u2_h + rtb_Deg2Rad * rtb_Product_h;
  rtb_Deg2Rad_0[7] = sin(sixdof_X.phithetapsi_CSTATE[2]) * sin
    (sixdof_X.phithetapsi_CSTATE[1]) * rtb_Product_h - rtb_Deg2Rad * rtb_u2_h;
  rtb_Deg2Rad_0[2] = -rtb_u2_o;
  rtb_Deg2Rad_0[5] = rtb_Sum2 * rtb_u2_h;
  rtb_Deg2Rad_0[8] = rtb_Sum2 * rtb_Product_h;
  rtb_u2_o = sixdof_B.ubvbwb[1];
  rtb_Deg2Rad = sixdof_B.ubvbwb[0];
  rtb_Sum2 = sixdof_B.ubvbwb[2];
  for (i = 0; i < 3; i++) {
    /* Product: '<S7>/Product' */
    sixdof_B.Product[i] = (rtb_Deg2Rad_0[i + 3] * rtb_u2_o + rtb_Deg2Rad_0[i] *
      rtb_Deg2Rad) + rtb_Deg2Rad_0[i + 6] * rtb_Sum2;
  }

  /* Gain: '<S7>/Z-positive is down' */
  rtb_u2_o = sixdof_B.Product[1];
  rtb_Deg2Rad = sixdof_B.Product[0];
  rtb_Sum2 = sixdof_B.Product[2];
  for (i = 0; i < 3; i++) {
    /* Gain: '<S7>/Z-positive is down' */
    sixdof_B.Zpositiveisdown[i] = (sixdof_P.Zpositiveisdown_Gain[i + 3] *
      rtb_u2_o + sixdof_P.Zpositiveisdown_Gain[i] * rtb_Deg2Rad) +
      sixdof_P.Zpositiveisdown_Gain[i + 6] * rtb_Sum2;
  }

  /* Sum: '<Root>/Subtract4' incorporates:
   *  Constant: '<Root>/airpseed_desired'
   */
  sixdof_B.airspeed_error = sixdof_P.airpseed_desired_Value -
    sixdof_B.Zpositiveisdown[0];
  if (rtmIsMajorTimeStep(sixdof_M)) {
    /* Gain: '<S276>/Derivative Gain' */
    rtb_Sum_h = sixdof_P.DiscretePIDController4_D * sixdof_B.airspeed_error;

    /* SampleTimeMath: '<S279>/Tsamp'
     *
     * About '<S279>/Tsamp':
     *  y = u * K where K = 1 / ( w * Ts )
     */
    sixdof_B.Tsamp = rtb_Sum_h * sixdof_P.Tsamp_WtEt;

    /* Sum: '<S293>/Sum' incorporates:
     *  Delay: '<S277>/UD'
     *  DiscreteIntegrator: '<S284>/Integrator'
     *  Gain: '<S289>/Proportional Gain'
     *  Sum: '<S277>/Diff'
     */
    rtb_Sum_h = (sixdof_P.DiscretePIDController4_P * sixdof_B.airspeed_error +
                 sixdof_DW.Integrator_DSTATE) + (sixdof_B.Tsamp -
      sixdof_DW.UD_DSTATE);
  }

  /* Sum: '<Root>/Subtract' incorporates:
   *  Constant: '<Root>/h_desired'
   */
  sixdof_B.Subtract = sixdof_P.h_desired_Value - sixdof_B.xeyeze[2];
  if (rtmIsMajorTimeStep(sixdof_M)) {
    /* Gain: '<S91>/Filter Coefficient' incorporates:
     *  DiscreteIntegrator: '<S83>/Filter'
     *  Gain: '<S82>/Derivative Gain'
     *  Sum: '<S83>/SumD'
     */
    sixdof_B.FilterCoefficient = (sixdof_P.DiscretePIDController_D *
      sixdof_B.Subtract - sixdof_DW.Filter_DSTATE) *
      sixdof_P.DiscretePIDController_N;

    /* Sum: '<S97>/Sum' incorporates:
     *  DiscreteIntegrator: '<S88>/Integrator'
     *  Gain: '<S93>/Proportional Gain'
     */
    sixdof_B.Sum = (sixdof_P.DiscretePIDController_P * sixdof_B.Subtract +
                    sixdof_DW.Integrator_DSTATE_e) + sixdof_B.FilterCoefficient;
  }

  /* Sum: '<Root>/Subtract1' */
  sixdof_B.pitch_error = sixdof_B.Sum - sixdof_B.pqr[1];
  if (rtmIsMajorTimeStep(sixdof_M)) {
    /* Gain: '<S130>/Derivative Gain' */
    rtb_Deg2Rad2 = sixdof_P.DiscretePIDController1_D * sixdof_B.pitch_error;

    /* SampleTimeMath: '<S133>/Tsamp'
     *
     * About '<S133>/Tsamp':
     *  y = u * K where K = 1 / ( w * Ts )
     */
    sixdof_B.Tsamp_o = rtb_Deg2Rad2 * sixdof_P.Tsamp_WtEt_k;

    /* Sum: '<S147>/Sum' incorporates:
     *  Delay: '<S131>/UD'
     *  DiscreteIntegrator: '<S138>/Integrator'
     *  Gain: '<S143>/Proportional Gain'
     *  Sum: '<S131>/Diff'
     */
    rtb_Deg2Rad2 = (sixdof_P.DiscretePIDController1_P * sixdof_B.pitch_error +
                    sixdof_DW.Integrator_DSTATE_e5) + (sixdof_B.Tsamp_o -
      sixdof_DW.UD_DSTATE_l);
  }

  /* Gain: '<S1>/R2D3' incorporates:
   *  Integrator: '<S7>/phi theta psi'
   */
  sixdof_B.R2D3[0] = sixdof_P.R2D3_Gain * sixdof_X.phithetapsi_CSTATE[0];
  sixdof_B.R2D3[1] = sixdof_P.R2D3_Gain * sixdof_X.phithetapsi_CSTATE[1];
  sixdof_B.R2D3[2] = sixdof_P.R2D3_Gain * sixdof_X.phithetapsi_CSTATE[2];
  if (rtmIsMajorTimeStep(sixdof_M)) {
  }

  /* ManualSwitch: '<S1>/Manual Switch1' incorporates:
   *  Constant: '<S1>/ no wind'
   *  Gain: '<S18>/Gain2'
   */
  if (sixdof_P.ManualSwitch1_CurrentSetting == 1) {
    rtb_Gain2[0] = sixdof_P.nowind_Value[0];
    rtb_Gain2[1] = sixdof_P.nowind_Value[1];
    rtb_Gain2[2] = sixdof_P.nowind_Value[2];
  } else {
    /* SignalConversion generated from: '<S55>/Matrix Gain6' incorporates:
     *  Gain: '<S56>/   '
     *  Gain: '<S56>/   1'
     *  Gain: '<S56>/   2'
     *  Lookup: '<S56>/WindX'
     *  Lookup: '<S56>/WindY'
     *  Lookup: '<S56>/WindZ'
     */
    rtb_Sum2 = sixdof_P._Gain * rt_Lookup(&sixdof_P.WindX_XData[0], 3002,
      sixdof_B.xeyeze[2], &sixdof_P.WindX_YData[0]);
    rtb_CD = sixdof_P.u_Gain_l * rt_Lookup(&sixdof_P.WindY_XData[0], 3002,
      sixdof_B.xeyeze[2], &sixdof_P.WindY_YData[0]);
    rtb_Saturation_idx_1 = sixdof_P.u_Gain * rt_Lookup(&sixdof_P.WindZ_XData[0],
      3002, sixdof_B.xeyeze[2], &sixdof_P.WindZ_YData[0]);
    for (i = 0; i < 3; i++) {
      /* Gain: '<S18>/Gain2' incorporates:
       *  Gain: '<S55>/Matrix Gain6'
       */
      rtb_Gain2[i] = (sixdof_P.MatrixGain6_Gain[i + 3] * rtb_CD +
                      sixdof_P.MatrixGain6_Gain[i] * rtb_Sum2) +
        sixdof_P.MatrixGain6_Gain[i + 6] * rtb_Saturation_idx_1;
    }
  }

  /* End of ManualSwitch: '<S1>/Manual Switch1' */

  /* Math: '<S22>/Math Function' incorporates:
   *  Fcn: '<S53>/11'
   *  Fcn: '<S53>/12'
   *  Fcn: '<S53>/13'
   *  Fcn: '<S53>/21'
   *  Fcn: '<S53>/22'
   *  Fcn: '<S53>/23'
   *  Fcn: '<S53>/31'
   *  Fcn: '<S53>/32'
   *  Fcn: '<S53>/33'
   *  Integrator: '<S7>/phi theta psi'
   */
  rtb_Deg2Rad_0[0] = cos(sixdof_X.phithetapsi_CSTATE[2]) * cos
    (sixdof_X.phithetapsi_CSTATE[1]);
  rtb_Deg2Rad_0[1] = cos(sixdof_X.phithetapsi_CSTATE[2]) * sin
    (sixdof_X.phithetapsi_CSTATE[1]) * sin(sixdof_X.phithetapsi_CSTATE[0]) - sin
    (sixdof_X.phithetapsi_CSTATE[2]) * cos(sixdof_X.phithetapsi_CSTATE[0]);
  rtb_Deg2Rad_0[2] = cos(sixdof_X.phithetapsi_CSTATE[2]) * sin
    (sixdof_X.phithetapsi_CSTATE[1]) * cos(sixdof_X.phithetapsi_CSTATE[0]) + sin
    (sixdof_X.phithetapsi_CSTATE[2]) * sin(sixdof_X.phithetapsi_CSTATE[0]);
  rtb_Deg2Rad_0[3] = sin(sixdof_X.phithetapsi_CSTATE[2]) * cos
    (sixdof_X.phithetapsi_CSTATE[1]);
  rtb_Deg2Rad_0[4] = sin(sixdof_X.phithetapsi_CSTATE[2]) * sin
    (sixdof_X.phithetapsi_CSTATE[1]) * sin(sixdof_X.phithetapsi_CSTATE[0]) + cos
    (sixdof_X.phithetapsi_CSTATE[2]) * cos(sixdof_X.phithetapsi_CSTATE[0]);
  rtb_Deg2Rad_0[5] = sin(sixdof_X.phithetapsi_CSTATE[2]) * sin
    (sixdof_X.phithetapsi_CSTATE[1]) * cos(sixdof_X.phithetapsi_CSTATE[0]) - cos
    (sixdof_X.phithetapsi_CSTATE[2]) * sin(sixdof_X.phithetapsi_CSTATE[0]);
  rtb_Deg2Rad_0[6] = -sin(sixdof_X.phithetapsi_CSTATE[1]);
  rtb_Deg2Rad_0[7] = cos(sixdof_X.phithetapsi_CSTATE[1]) * sin
    (sixdof_X.phithetapsi_CSTATE[0]);
  rtb_Deg2Rad_0[8] = cos(sixdof_X.phithetapsi_CSTATE[1]) * cos
    (sixdof_X.phithetapsi_CSTATE[0]);

  /* Sum: '<S9>/Vair' incorporates:
   *  Gain: '<S18>/Gain2'
   */
  rtb_Sum2 = sixdof_B.Product[0] - rtb_Gain2[0];
  rtb_CD = sixdof_B.Product[1] - rtb_Gain2[1];
  rtb_Saturation_idx_1 = sixdof_B.Product[2] - rtb_Gain2[2];

  /* Product: '<S22>/Product1' */
  for (i = 0; i < 3; i++) {
    /* Math: '<S9>/Math Function1' */
    rtb_Gain2[i] = (rtb_Deg2Rad_0[i + 3] * rtb_CD + rtb_Deg2Rad_0[i] * rtb_Sum2)
      + rtb_Deg2Rad_0[i + 6] * rtb_Saturation_idx_1;
  }

  /* End of Product: '<S22>/Product1' */

  /* Gain: '<S19>/R2D2' incorporates:
   *  Fcn: '<S19>/tan(aoa)'
   *  Math: '<S9>/Math Function1'
   *  Trigonometry: '<S19>/aoa'
   */
  sixdof_B.aoa = atan(rtb_Gain2[2] / rtb_Gain2[0]) * sixdof_P.R2D2_Gain;

  /* Fcn: '<S19>/tan(beta)' incorporates:
   *  Fcn: '<S19>/V^2'
   *  Math: '<S9>/Math Function1'
   */
  rtb_u2_o = rt_powd_snf(rtb_Gain2[0], 2.0);
  rtb_CD = rt_powd_snf(rtb_Gain2[2], 2.0);

  /* Gain: '<S19>/R2D1' incorporates:
   *  Fcn: '<S19>/tan(beta)'
   *  Math: '<S9>/Math Function1'
   *  Trigonometry: '<S19>/beta'
   */
  sixdof_B.beta = atan(rtb_Gain2[1] / sqrt(rtb_u2_o + rtb_CD)) *
    sixdof_P.R2D1_Gain;

  /* Gain: '<S23>/D2R' */
  rtb_Sum2 = sixdof_P.D2R_Gain * sixdof_B.aoa;
  rtb_Saturation_idx_1 = sixdof_P.D2R_Gain * sixdof_B.beta;

  /* Gain: '<S24>/Deg2Rad' */
  rtb_Deg2Rad = sixdof_P.Deg2Rad_Gain * sixdof_B.aoa;
  if (rtmIsMajorTimeStep(sixdof_M)) {
    /* Gain: '<S45>/Gain3' incorporates:
     *  Constant: '<S45>/CLa_dot'
     *  Product: '<S45>/Product5'
     */
    sixdof_B.Gain3 = sixdof_P.CLa_dot * 0.0 * sixdof_P.Gain3_Gain;

    /* Gain: '<S24>/Deg2Rad2' */
    rtb_Deg2Rad2 *= sixdof_P.Deg2Rad2_Gain;

    /* Gain: '<S45>/Gain1' incorporates:
     *  Constant: '<S45>/CLDe'
     *  Product: '<S45>/Product1'
     */
    sixdof_B.Gain1 = sixdof_P.CLDe * rtb_Deg2Rad2 * sixdof_P.Gain1_Gain;
  }

  /* Fcn: '<S19>/V^2' incorporates:
   *  Math: '<S9>/Math Function1'
   */
  rtb_Product_h = (rtb_u2_o + rt_powd_snf(rtb_Gain2[1], 2.0)) + rtb_CD;

  /* Math: '<S19>/Math Function'
   *
   * About '<S19>/Math Function':
   *  Operator: sqrt
   */
  sixdof_B.MathFunction = sqrt(rtb_Product_h);

  /* Sum: '<S45>/Sum' incorporates:
   *  Constant: '<S45>/CL0'
   *  Constant: '<S45>/CLa'
   *  Constant: '<S47>/Constant'
   *  Constant: '<S48>/Cmq2'
   *  Gain: '<S45>/Gain4'
   *  Product: '<S45>/Product4'
   *  Product: '<S47>/Product'
   *  Product: '<S48>/Product'
   */
  sixdof_B.Sum_h = (((sixdof_P.CLa * rtb_Deg2Rad * sixdof_P.Gain4_Gain +
                      sixdof_P.CL0) + sixdof_B.Gain3) + sixdof_B.Gain1) +
    sixdof_B.pqr[1] * sixdof_P.chord / sixdof_B.MathFunction * sixdof_P.CLq;

  /* Sum: '<S45>/Subtract' incorporates:
   *  Constant: '<S45>/span1'
   */
  sixdof_B.Subtract_c = sixdof_B.xeyeze[2] - sixdof_P.span;

  /* Switch: '<S45>/Switch' */
  if (rtsiIsModeUpdateTimeStep(&sixdof_M->solverInfo)) {
    sixdof_DW.Switch_Mode = (sixdof_B.Subtract_c > sixdof_P.Switch_Threshold);
  }

  if (sixdof_DW.Switch_Mode) {
    rtb_u2_o = sixdof_B.Sum_h;
  } else {
    /* Math: '<S45>/Math Function' */
    rtb_CD = sixdof_B.xeyeze[2];
    if (rtmIsMajorTimeStep(sixdof_M)) {
      if (sixdof_DW.MathFunction_DWORK1_o != 0) {
        rtsiSetBlockStateForSolverChangedAtMajorStep(&sixdof_M->solverInfo, true);
        rtsiSetContTimeOutputInconsistentWithStateAtMajorStep
          (&sixdof_M->solverInfo, true);
        sixdof_DW.MathFunction_DWORK1_o = 0;
      }
    } else if (sixdof_B.xeyeze[2] < 0.0) {
      rtb_CD = 0.0;
      sixdof_DW.MathFunction_DWORK1_o = 1;
    }

    /* Sum: '<S45>/Add1' incorporates:
     *  Constant: '<S45>/Constant'
     *  Constant: '<S45>/Constant1'
     *  Math: '<S45>/Math Function'
     *  Product: '<S45>/Product'
     *  Sum: '<S45>/Add'
     */
    sixdof_B.Add1 = (log(rtb_CD) * sixdof_P.Constant1_Value +
                     sixdof_P.Constant_Value) + sixdof_B.Sum_h;
    rtb_u2_o = sixdof_B.Add1;
  }

  /* End of Switch: '<S45>/Switch' */

  /* Saturate: '<S54>/Limit  altitude' */
  if (rtsiIsModeUpdateTimeStep(&sixdof_M->solverInfo)) {
    sixdof_DW.Limitaltitude_MODE = sixdof_B.xeyeze[2] >= sixdof_P.ISA_hmax ? 1 :
      sixdof_B.xeyeze[2] > sixdof_P.Limitaltitude_LowerSat ? 0 : -1;
  }

  /* Gain: '<S54>/1//T0' incorporates:
   *  Constant: '<S54>/Sea Level  Temperature'
   *  Gain: '<S54>/Lapse Rate'
   *  Saturate: '<S54>/Limit  altitude'
   *  Sum: '<S54>/Sum1'
   */
  rtb_u2_h = (sixdof_P.ISA_T0 - (sixdof_DW.Limitaltitude_MODE == 1 ?
    sixdof_P.ISA_hmax : sixdof_DW.Limitaltitude_MODE == -1 ?
    sixdof_P.Limitaltitude_LowerSat : sixdof_B.xeyeze[2]) * sixdof_P.ISA_lapse) *
    (1.0 / sixdof_P.ISA_T0);

  /* Fcn: '<S54>/(T//T0)^(g//LR)' */
  if (rtb_u2_h < 0.0) {
    rtb_Deg2Rad3 = -rt_powd_snf(-rtb_u2_h, 5.2613240418118465);
  } else {
    rtb_Deg2Rad3 = rt_powd_snf(rtb_u2_h, 5.2613240418118465);
  }

  /* Product: '<S19>/Product' incorporates:
   *  Constant: '<S19>/Constant'
   *  Constant: '<S19>/span'
   *  Constant: '<S19>/span1'
   *  Fcn: '<S54>/(T//T0)^(g//LR)'
   *  Gain: '<S54>/rho0'
   *  Product: '<S54>/Product'
   */
  rtb_Product_h = rtb_Deg2Rad3 / rtb_u2_h * sixdof_P.ISA_rho0 * rtb_Product_h *
    sixdof_P.Constant_Value_i * sixdof_P.span * sixdof_P.chord;

  /* Gain: '<S24>/Deg2Rad1' */
  rtb_u2_h = sixdof_P.Deg2Rad1_Gain * sixdof_B.beta;
  if (rtmIsMajorTimeStep(sixdof_M)) {
    /* Gain: '<S24>/Deg2Rad4' */
    rtb_Deg2Rad4 = sixdof_P.Deg2Rad4_Gain * 0.0;

    /* Gain: '<S31>/Gain2' incorporates:
     *  Constant: '<S31>/CYDr'
     *  Product: '<S31>/Product1'
     */
    sixdof_B.Gain2 = sixdof_P.CYDr * rtb_Deg2Rad4 * sixdof_P.Gain2_Gain;

    /* Gain: '<S24>/Deg2Rad3' */
    rtb_Deg2Rad3 = sixdof_P.Deg2Rad3_Gain * 0.0;

    /* Gain: '<S32>/Gain3' incorporates:
     *  Constant: '<S32>/ClDa'
     *  Product: '<S32>/Product5'
     */
    sixdof_B.Gain3_j = sixdof_P.ClDa * rtb_Deg2Rad3 * sixdof_P.Gain3_Gain_g;

    /* Gain: '<S32>/Gain1' incorporates:
     *  Constant: '<S32>/ClDr'
     *  Product: '<S32>/Product1'
     */
    sixdof_B.Gain1_h = sixdof_P.ClDr * rtb_Deg2Rad4 * sixdof_P.Gain1_Gain_nb;

    /* Gain: '<S35>/Slider Gain' incorporates:
     *  Constant: '<S34>/Constant'
     */
    sixdof_B.SliderGain = sixdof_P.SliderGain_gain * sixdof_P.Clp;

    /* Gain: '<S36>/Slider Gain' incorporates:
     *  Constant: '<S34>/Constant1'
     */
    sixdof_B.SliderGain_e = sixdof_P.SliderGain1_gain * sixdof_P.Clr;

    /* Gain: '<S46>/Gain3' incorporates:
     *  Constant: '<S46>/Cma_dot'
     *  Product: '<S46>/Product5'
     */
    sixdof_B.Gain3_g = sixdof_P.Cma_dot * 0.0 * sixdof_P.Gain3_Gain_f;

    /* Gain: '<S46>/Gain1' incorporates:
     *  Constant: '<S46>/CmDe'
     *  Product: '<S46>/Product1'
     */
    sixdof_B.Gain1_p = sixdof_P.CmDe * rtb_Deg2Rad2 * sixdof_P.Gain1_Gain_d;

    /* Gain: '<S50>/Slider Gain' incorporates:
     *  Constant: '<S49>/Constant'
     */
    sixdof_B.SliderGain_h = sixdof_P.SliderGain_gain_b * sixdof_P.Cmq;

    /* Gain: '<S33>/Gain3' incorporates:
     *  Constant: '<S33>/CnDa'
     *  Product: '<S33>/Product5'
     */
    sixdof_B.Gain3_p = sixdof_P.CnDa * rtb_Deg2Rad3 * sixdof_P.Gain3_Gain_gj;

    /* Gain: '<S33>/Gain1' incorporates:
     *  Constant: '<S33>/CnDr'
     *  Product: '<S33>/Product1'
     */
    sixdof_B.Gain1_g = sixdof_P.CnDr * rtb_Deg2Rad4 * sixdof_P.Gain1_Gain_dd;

    /* Gain: '<S40>/Slider Gain' incorporates:
     *  Constant: '<S39>/Constant'
     */
    sixdof_B.SliderGain_m = sixdof_P.SliderGain_gain_h * sixdof_P.Cnp;

    /* Gain: '<S41>/Slider Gain' incorporates:
     *  Constant: '<S39>/Constant1'
     */
    sixdof_B.SliderGain_c = sixdof_P.SliderGain1_gain_m * sixdof_P.Cnr;
  }

  /* Fcn: '<S27>/11' incorporates:
   *  Fcn: '<S27>/13'
   *  Fcn: '<S27>/21'
   *  Fcn: '<S27>/22'
   *  Fcn: '<S27>/33'
   */
  rtb_Deg2Rad2 = cos(rtb_Saturation_idx_1);
  rtb_Deg2Rad4 = cos(rtb_Sum2);

  /* Fcn: '<S27>/12' incorporates:
   *  Fcn: '<S27>/21'
   *  Fcn: '<S27>/23'
   */
  rtb_Deg2Rad3 = sin(rtb_Saturation_idx_1);

  /* Fcn: '<S27>/13' incorporates:
   *  Fcn: '<S27>/31'
   */
  rtb_Sum2 = sin(rtb_Sum2);

  /* Math: '<S25>/Ra2b' incorporates:
   *  Fcn: '<S27>/11'
   *  Fcn: '<S27>/12'
   *  Fcn: '<S27>/13'
   *  Fcn: '<S27>/21'
   *  Fcn: '<S27>/22'
   *  Fcn: '<S27>/23'
   *  Fcn: '<S27>/31'
   *  Fcn: '<S27>/32'
   *  Fcn: '<S27>/33'
   *  Math: '<S26>/Ra2b'
   */
  rtb_MathFunction_o[0] = rtb_Deg2Rad4 * rtb_Deg2Rad2;
  rtb_MathFunction_o[1] = rtb_Deg2Rad3;
  rtb_MathFunction_o[2] = rtb_Sum2 * rtb_Deg2Rad2;
  rtb_MathFunction_o[3] = -rtb_Deg2Rad4 * rtb_Deg2Rad3;
  rtb_MathFunction_o[4] = rtb_Deg2Rad2;
  rtb_MathFunction_o[5] = -rtb_Sum2 * rtb_Deg2Rad3;
  rtb_MathFunction_o[6] = -rtb_Sum2;
  rtb_MathFunction_o[7] = 0.0;
  rtb_MathFunction_o[8] = rtb_Deg2Rad4;

  /* Product: '<S25>/Product2' incorporates:
   *  Constant: '<S31>/CYb'
   *  Constant: '<S44>/Apolar'
   *  Constant: '<S44>/CD0'
   *  Gain: '<S24>/Gain'
   *  Gain: '<S24>/Gain1'
   *  Gain: '<S24>/Gain2'
   *  Gain: '<S30>/Gain'
   *  Gain: '<S30>/Gain1'
   *  Gain: '<S31>/Gain1'
   *  Product: '<S24>/Fx_a(Drag)'
   *  Product: '<S24>/Fy_a(Side)'
   *  Product: '<S24>/Fz_a(Lift)'
   *  Product: '<S31>/Product'
   *  Product: '<S44>/Product'
   *  Product: '<S44>/Product1'
   *  Sum: '<S31>/Sum2'
   *  Sum: '<S44>/Sum1'
   */
  rtb_Sum2 = (rtb_u2_o * rtb_u2_o * sixdof_P.Apolar + sixdof_P.CD0) *
    sixdof_P.Gain_Gain * rtb_Product_h * sixdof_P.Gain_Gain_m;
  rtb_CD = (sixdof_P.CYb * rtb_u2_h * sixdof_P.Gain1_Gain_n + sixdof_B.Gain2) *
    rtb_Product_h * sixdof_P.Gain1_Gain_f;
  rtb_Saturation_idx_1 = sixdof_P.Gain1_Gain_e * rtb_u2_o * rtb_Product_h *
    sixdof_P.Gain2_Gain_h;

  /* Fcn: '<S52>/11' incorporates:
   *  Fcn: '<S16>/psidot'
   *  Fcn: '<S52>/12'
   *  Fcn: '<S52>/21'
   *  Fcn: '<S52>/22'
   *  Fcn: '<S52>/23'
   *  Fcn: '<S52>/32'
   *  Fcn: '<S52>/33'
   */
  rtb_Deg2Rad3 = cos(rtb_phithetapsi[2]);
  rtb_u2_o = cos(rtb_phithetapsi[1]);

  /* Math: '<S21>/Math Function' incorporates:
   *  Fcn: '<S52>/11'
   */
  rtb_Deg2Rad_0[0] = rtb_Deg2Rad3 * rtb_u2_o;

  /* Fcn: '<S52>/21' incorporates:
   *  Fcn: '<S16>/phidot'
   *  Fcn: '<S16>/psidot'
   *  Fcn: '<S52>/12'
   *  Fcn: '<S52>/13'
   *  Fcn: '<S52>/22'
   *  Fcn: '<S52>/23'
   *  Fcn: '<S52>/31'
   *  Fcn: '<S52>/32'
   *  Fcn: '<S52>/33'
   */
  Weightmatrix_Value = sin(rtb_phithetapsi[1]);
  Weightmatrix_Value_0 = rtb_Deg2Rad3 * Weightmatrix_Value;
  rtb_Deg2Rad2 = cos(rtb_phithetapsi[0]);
  Weightmatrix_Value_1 = sin(rtb_phithetapsi[2]);
  rtb_Deg2Rad4 = sin(rtb_phithetapsi[0]);

  /* Math: '<S21>/Math Function' incorporates:
   *  Fcn: '<S52>/12'
   *  Fcn: '<S52>/21'
   *  Fcn: '<S52>/31'
   */
  rtb_Deg2Rad_0[1] = Weightmatrix_Value_0 * rtb_Deg2Rad4 - Weightmatrix_Value_1 *
    rtb_Deg2Rad2;
  rtb_Deg2Rad_0[2] = Weightmatrix_Value_0 * rtb_Deg2Rad2 + Weightmatrix_Value_1 *
    rtb_Deg2Rad4;
  rtb_Deg2Rad_0[3] = Weightmatrix_Value_1 * rtb_u2_o;

  /* Fcn: '<S52>/22' incorporates:
   *  Fcn: '<S52>/32'
   */
  Weightmatrix_Value_0 = Weightmatrix_Value_1 * Weightmatrix_Value;

  /* Math: '<S21>/Math Function' incorporates:
   *  Fcn: '<S52>/13'
   *  Fcn: '<S52>/22'
   *  Fcn: '<S52>/23'
   *  Fcn: '<S52>/32'
   *  Fcn: '<S52>/33'
   */
  rtb_Deg2Rad_0[4] = Weightmatrix_Value_0 * rtb_Deg2Rad4 + rtb_Deg2Rad3 *
    rtb_Deg2Rad2;
  rtb_Deg2Rad_0[5] = Weightmatrix_Value_0 * rtb_Deg2Rad2 - rtb_Deg2Rad3 *
    rtb_Deg2Rad4;
  rtb_Deg2Rad_0[6] = -Weightmatrix_Value;
  rtb_Deg2Rad_0[7] = rtb_u2_o * rtb_Deg2Rad4;
  rtb_Deg2Rad_0[8] = rtb_u2_o * rtb_Deg2Rad2;

  /* Product: '<S26>/Product2' incorporates:
   *  Constant: '<S24>/chord'
   *  Constant: '<S24>/span'
   *  Constant: '<S32>/Clb'
   *  Constant: '<S33>/Cnb'
   *  Constant: '<S37>/Cmq1'
   *  Constant: '<S37>/Cmq2'
   *  Constant: '<S38>/Cmq1'
   *  Constant: '<S38>/Cmq2'
   *  Constant: '<S42>/Cmq1'
   *  Constant: '<S42>/Cmq2'
   *  Constant: '<S43>/Cmq1'
   *  Constant: '<S43>/Cmq2'
   *  Constant: '<S46>/Cm0'
   *  Constant: '<S46>/Cma'
   *  Constant: '<S51>/Cmq2'
   *  Gain: '<S24>/Gain3'
   *  Gain: '<S24>/Gain4'
   *  Gain: '<S24>/Gain5'
   *  Gain: '<S32>/Gain4'
   *  Gain: '<S33>/Gain4'
   *  Gain: '<S46>/Gain4'
   *  Product: '<S24>/Mx_a'
   *  Product: '<S24>/My_a'
   *  Product: '<S24>/Mz_a'
   *  Product: '<S32>/Product4'
   *  Product: '<S33>/Product4'
   *  Product: '<S34>/Product'
   *  Product: '<S34>/Product1'
   *  Product: '<S37>/Product'
   *  Product: '<S38>/Product'
   *  Product: '<S39>/Product'
   *  Product: '<S39>/Product1'
   *  Product: '<S42>/Product'
   *  Product: '<S43>/Product'
   *  Product: '<S46>/Product4'
   *  Product: '<S49>/Product'
   *  Product: '<S51>/Product'
   *  Sum: '<S32>/Sum'
   *  Sum: '<S33>/Sum'
   *  Sum: '<S46>/Sum'
   */
  rtb_Deg2Rad3 = ((((sixdof_P.Clb * rtb_u2_h * sixdof_P.Gain4_Gain_l +
                     sixdof_B.Gain3_j) + sixdof_B.Gain1_h) + sixdof_B.pqr[0] *
                   sixdof_P.Cmq1_Value * sixdof_P.span / sixdof_B.MathFunction *
                   sixdof_B.SliderGain) + sixdof_B.pqr[2] *
                  sixdof_P.Cmq1_Value_d * sixdof_P.span / sixdof_B.MathFunction *
                  sixdof_B.SliderGain_e) * rtb_Product_h * sixdof_P.span *
    sixdof_P.Gain3_Gain_j;
  rtb_Deg2Rad = ((((sixdof_P.Cma * rtb_Deg2Rad * sixdof_P.Gain4_Gain_f +
                    sixdof_P.Cm0) + sixdof_B.Gain3_g) + sixdof_B.Gain1_p) +
                 sixdof_B.pqr[1] * sixdof_P.chord / sixdof_B.MathFunction *
                 sixdof_B.SliderGain_h) * rtb_Product_h * sixdof_P.chord *
    sixdof_P.Gain4_Gain_o;
  rtb_u2_h = ((((sixdof_P.Cnb * rtb_u2_h * sixdof_P.Gain4_Gain_n +
                 sixdof_B.Gain3_p) + sixdof_B.Gain1_g) + sixdof_B.pqr[0] *
               sixdof_P.Cmq1_Value_h * sixdof_P.span / sixdof_B.MathFunction *
               sixdof_B.SliderGain_m) + sixdof_B.pqr[2] * sixdof_P.Cmq1_Value_a *
              sixdof_P.span / sixdof_B.MathFunction * sixdof_B.SliderGain_c) *
    rtb_Product_h * sixdof_P.span * sixdof_P.Gain5_Gain;

  /* Product: '<S21>/Product1' incorporates:
   *  Constant: '<S9>/Weight matrix'
   */
  Weightmatrix_Value = sixdof_P.Weightmatrix_Value[1];
  Weightmatrix_Value_0 = sixdof_P.Weightmatrix_Value[0];
  Weightmatrix_Value_1 = sixdof_P.Weightmatrix_Value[2];
  for (i = 0; i < 3; i++) {
    /* Product: '<S25>/Product2' incorporates:
     *  Math: '<S25>/Ra2b'
     */
    rtb_Product_h = rtb_MathFunction_o[i];
    rtb_MathFunction_f = rtb_Product_h * rtb_Sum2;

    /* Product: '<S26>/Product2' incorporates:
     *  Math: '<S26>/Ra2b'
     */
    rtb_MathFunction_f_0 = rtb_Product_h * rtb_Deg2Rad3;

    /* Product: '<S25>/Product2' incorporates:
     *  Math: '<S25>/Ra2b'
     */
    rtb_Product_h = rtb_MathFunction_o[i + 3];
    rtb_MathFunction_f += rtb_Product_h * rtb_CD;

    /* Product: '<S26>/Product2' incorporates:
     *  Math: '<S26>/Ra2b'
     */
    rtb_MathFunction_f_0 += rtb_Product_h * rtb_Deg2Rad;

    /* Product: '<S25>/Product2' incorporates:
     *  Math: '<S25>/Ra2b'
     */
    rtb_Product_h = rtb_MathFunction_o[i + 6];

    /* Reshape: '<S9>/Reshape' incorporates:
     *  Constant: '<S9>/Weight matrix'
     *  Math: '<S25>/Ra2b'
     *  Math: '<S26>/Ra2b'
     *  Product: '<S21>/Product1'
     *  Product: '<S25>/Product2'
     *  Product: '<S26>/Product2'
     *  Sum: '<S9>/Sum2'
     */
    sixdof_B.Reshape[i] = ((rtb_Deg2Rad_0[i + 3] * Weightmatrix_Value +
      rtb_Deg2Rad_0[i] * Weightmatrix_Value_0) + rtb_Deg2Rad_0[i + 6] *
      Weightmatrix_Value_1) + (rtb_Product_h * rtb_Saturation_idx_1 +
      rtb_MathFunction_f);
    sixdof_B.Reshape[i + 3] = rtb_Product_h * rtb_u2_h + rtb_MathFunction_f_0;
  }

  if (rtmIsMajorTimeStep(sixdof_M)) {
    /* Fcn: '<S8>/Static Thrust (lbs)' incorporates:
     *  Gain: '<S8>/Throttle2RPM'
     */
    sixdof_B.StaticThrustlbs = sixdof_P.Throttle2RPM_Gain * rtb_Sum_h * 0.00146
      - 4.088;
  }

  /* Gain: '<S8>/mps2fps' */
  sixdof_B.mps2fps = sixdof_P.mps2fps_Gain * sixdof_B.MathFunction;

  /* Saturate: '<S8>/Saturation' */
  if (rtsiIsModeUpdateTimeStep(&sixdof_M->solverInfo)) {
    sixdof_DW.Saturation_MODE[0] = sixdof_B.StaticThrustlbs >=
      sixdof_P.Saturation_UpperSat ? 1 : sixdof_B.StaticThrustlbs >
      sixdof_P.Saturation_LowerSat ? 0 : -1;
    sixdof_DW.Saturation_MODE[1] = sixdof_B.mps2fps >=
      sixdof_P.Saturation_UpperSat ? 1 : sixdof_B.mps2fps >
      sixdof_P.Saturation_LowerSat ? 0 : -1;
  }

  rtb_Sum2 = sixdof_DW.Saturation_MODE[0] == 1 ? sixdof_P.Saturation_UpperSat :
    sixdof_DW.Saturation_MODE[0] == -1 ? sixdof_P.Saturation_LowerSat :
    sixdof_B.StaticThrustlbs;

  /* Fcn: '<S8>/Thrust (lbs)' */
  if (rtb_Sum2 < 0.0) {
    rtb_Deg2Rad3 = -sqrt(-rtb_Sum2);
  } else {
    rtb_Deg2Rad3 = sqrt(rtb_Sum2);
  }

  /* Gain: '<S8>/kg2N' incorporates:
   *  Fcn: '<S8>/Thrust (lbs)'
   *  Gain: '<S8>/lbs2kg'
   *  Saturate: '<S8>/Saturation'
   */
  sixdof_B.kg2N = (rtb_Sum2 - (sixdof_DW.Saturation_MODE[1] == 1 ?
    sixdof_P.Saturation_UpperSat : sixdof_DW.Saturation_MODE[1] == -1 ?
    sixdof_P.Saturation_LowerSat : sixdof_B.mps2fps) * 0.0238 * rtb_Deg2Rad3) *
    sixdof_P.lbs2kg_Gain * sixdof_P.ISA_g;

  /* Saturate: '<S8>/Saturation1' */
  if (rtsiIsModeUpdateTimeStep(&sixdof_M->solverInfo)) {
    sixdof_DW.Saturation1_MODE = sixdof_B.kg2N >= sixdof_P.Saturation1_UpperSat ?
      1 : sixdof_B.kg2N > sixdof_P.Saturation1_LowerSat ? 0 : -1;
  }

  /* Saturate: '<S8>/Saturation1' */
  sixdof_B.Saturation1 = sixdof_DW.Saturation1_MODE == 1 ?
    sixdof_P.Saturation1_UpperSat : sixdof_DW.Saturation1_MODE == -1 ?
    sixdof_P.Saturation1_LowerSat : sixdof_B.kg2N;
  if (rtmIsMajorTimeStep(sixdof_M)) {
  }

  /* Fcn: '<S1>/Fcn1' */
  sixdof_B.Fcn1 = sqrt(rt_powd_snf(sixdof_B.Product[0], 2.0) + rt_powd_snf
                       (sixdof_B.Product[1], 2.0));
  if (rtmIsMajorTimeStep(sixdof_M)) {
  }

  /* Fcn: '<S1>/Fcn2' */
  sixdof_B.Fcn2 = sixdof_B.Product[2];
  if (rtmIsMajorTimeStep(sixdof_M)) {
  }

  /* Gain: '<S1>/R2D2' */
  sixdof_B.R2D2[0] = sixdof_P.R2D2_Gain_j * sixdof_B.pqr[0];
  sixdof_B.R2D2[1] = sixdof_P.R2D2_Gain_j * sixdof_B.pqr[1];
  sixdof_B.R2D2[2] = sixdof_P.R2D2_Gain_j * sixdof_B.pqr[2];
  if (rtmIsMajorTimeStep(sixdof_M)) {
    /* Concatenate: '<S17>/Matrix Concatenation' incorporates:
     *  Concatenate: '<S17>/Matrix Concatenation2'
     *  Constant: '<S17>/Constant1'
     *  Constant: '<S17>/Constant4'
     *  Constant: '<S17>/mass'
     *  Reshape: '<S17>/Reshape'
     */
    rtb_MatrixConcatenation[0] = sixdof_P.mass;
    rtb_MatrixConcatenation[6] = sixdof_P.Constant4_Value_c;
    rtb_MatrixConcatenation[12] = sixdof_P.Constant4_Value_c;
    rtb_MatrixConcatenation[1] = sixdof_P.Constant4_Value_c;
    rtb_MatrixConcatenation[7] = sixdof_P.mass;
    rtb_MatrixConcatenation[13] = sixdof_P.Constant4_Value_c;
    rtb_MatrixConcatenation[2] = sixdof_P.Constant4_Value_c;
    rtb_MatrixConcatenation[8] = sixdof_P.Constant4_Value_c;
    rtb_MatrixConcatenation[14] = sixdof_P.mass;
    for (i = 0; i < 3; i++) {
      rtb_MatrixConcatenation[6 * i + 3] = sixdof_P.Constant1_Value_c[3 * i];
      rtb_MatrixConcatenation[6 * i + 4] = sixdof_P.Constant1_Value_c[3 * i + 1];
      rtb_MatrixConcatenation[6 * i + 5] = sixdof_P.Constant1_Value_c[3 * i + 2];
    }

    memcpy(&sixdof_B.MatrixConcatenation2[0], &rtb_MatrixConcatenation[0], 18U *
           sizeof(real_T));

    /* End of Concatenate: '<S17>/Matrix Concatenation' */

    /* Concatenate: '<S17>/Matrix Concatenation1' incorporates:
     *  Concatenate: '<S17>/Matrix Concatenation2'
     *  Constant: '<S17>/Constant1'
     *  Constant: '<S17>/Constant4'
     *  Constant: '<S17>/Ixx'
     *  Constant: '<S17>/Iyy'
     *  Constant: '<S17>/Izz'
     *  Reshape: '<S17>/Reshape1'
     */
    for (i = 0; i < 3; i++) {
      rtb_MatrixConcatenation[6 * i] = sixdof_P.Constant1_Value_c[3 * i];
      rtb_MatrixConcatenation[6 * i + 1] = sixdof_P.Constant1_Value_c[3 * i + 1];
      rtb_MatrixConcatenation[6 * i + 2] = sixdof_P.Constant1_Value_c[3 * i + 2];
    }

    rtb_MatrixConcatenation[3] = sixdof_P.Ixx;
    rtb_MatrixConcatenation[9] = sixdof_P.Constant4_Value_c;
    rtb_MatrixConcatenation[15] = sixdof_P.Constant4_Value_c;
    rtb_MatrixConcatenation[4] = sixdof_P.Constant4_Value_c;
    rtb_MatrixConcatenation[10] = sixdof_P.Iyy;
    rtb_MatrixConcatenation[16] = sixdof_P.Constant4_Value_c;
    rtb_MatrixConcatenation[5] = sixdof_P.Constant4_Value_c;
    rtb_MatrixConcatenation[11] = sixdof_P.Constant4_Value_c;
    rtb_MatrixConcatenation[17] = sixdof_P.Izz;
    memcpy(&sixdof_B.MatrixConcatenation2[18], &rtb_MatrixConcatenation[0], 18U *
           sizeof(real_T));

    /* End of Concatenate: '<S17>/Matrix Concatenation1' */
  }

  /* Gain: '<S18>/Gain' */
  rtb_Sum_h = sixdof_B.pqr[1];
  rtb_Deg2Rad = sixdof_B.pqr[0];
  rtb_Sum2 = sixdof_B.pqr[2];
  for (i = 0; i < 3; i++) {
    /* Math: '<S18>/Math Function' incorporates:
     *  Gain: '<S18>/Gain'
     *  Gain: '<S18>/Gain1'
     *  Gain: '<S18>/Gain2'
     */
    rtb_MathFunction_o[3 * i] = (sixdof_P.Gain_Gain_a[i + 3] * rtb_Sum_h +
      sixdof_P.Gain_Gain_a[i] * rtb_Deg2Rad) + sixdof_P.Gain_Gain_a[i + 6] *
      rtb_Sum2;
    rtb_MathFunction_o[3 * i + 1] = (sixdof_P.Gain1_Gain_m[i + 3] * rtb_Sum_h +
      sixdof_P.Gain1_Gain_m[i] * rtb_Deg2Rad) + sixdof_P.Gain1_Gain_m[i + 6] *
      rtb_Sum2;
    rtb_MathFunction_o[3 * i + 2] = (sixdof_P.Gain2_Gain_k[i + 3] * rtb_Sum_h +
      sixdof_P.Gain2_Gain_k[i] * rtb_Deg2Rad) + sixdof_P.Gain2_Gain_k[i + 6] *
      rtb_Sum2;
  }

  /* End of Gain: '<S18>/Gain' */
  for (i = 0; i < 9; i++) {
    /* SignalConversion generated from: '<S18>/Matrix Concatenation' incorporates:
     *  Math: '<S18>/Math Function'
     */
    rtb_Product_h = rtb_MathFunction_o[i];
    rtb_MatrixConcatenation[i] = rtb_Product_h;

    /* Gain: '<S18>/Gain3' incorporates:
     *  Math: '<S18>/Math Function'
     */
    rtb_Sum_h = sixdof_P.Gain3_Gain_k * rtb_Product_h;

    /* SignalConversion generated from: '<S18>/Matrix Concatenation' incorporates:
     *  Gain: '<S18>/Gain3'
     */
    rtb_MatrixConcatenation[i + 9] = rtb_Sum_h;

    /* SignalConversion generated from: '<S18>/Matrix Concatenation1' incorporates:
     *  Gain: '<S18>/Gain3'
     */
    rtb_MatrixConcatenation1[i] = rtb_Sum_h;

    /* SignalConversion generated from: '<S18>/Matrix Concatenation1' incorporates:
     *  Math: '<S18>/Math Function'
     */
    rtb_MatrixConcatenation1[i + 9] = rtb_Product_h;
  }

  /* Sum: '<S1>/Sum' incorporates:
   *  Constant: '<S8>/Constant4'
   */
  tmp[0] = sixdof_B.Saturation1;
  tmp[1] = sixdof_P.Constant4_Value;
  tmp[2] = sixdof_P.Constant4_Value;
  tmp[3] = sixdof_P.Constant4_Value;
  tmp[4] = sixdof_P.Constant4_Value;
  tmp[5] = sixdof_P.Constant4_Value;

  /* Concatenate: '<S18>/Matrix Concatenation2' incorporates:
   *  Concatenate: '<S18>/Matrix Concatenation'
   *  Concatenate: '<S18>/Matrix Concatenation1'
   */
  for (i = 0; i < 6; i++) {
    rtb_MatrixConcatenation_0[6 * i] = rtb_MatrixConcatenation[3 * i];
    rtb_MatrixConcatenation_0[6 * i + 3] = rtb_MatrixConcatenation1[3 * i];
    i2 = 3 * i + 1;
    rtb_MatrixConcatenation_0[6 * i + 1] = rtb_MatrixConcatenation[i2];
    rtb_MatrixConcatenation_0[6 * i + 4] = rtb_MatrixConcatenation1[i2];
    i2 = 3 * i + 2;
    rtb_MatrixConcatenation_0[6 * i + 2] = rtb_MatrixConcatenation[i2];
    rtb_MatrixConcatenation_0[6 * i + 5] = rtb_MatrixConcatenation1[i2];
  }

  /* End of Concatenate: '<S18>/Matrix Concatenation2' */

  /* Product: '<S15>/Sigma*A' incorporates:
   *  Concatenate: '<S17>/Matrix Concatenation2'
   */
  for (i = 0; i < 6; i++) {
    for (i2 = 0; i2 < 6; i2++) {
      rtb_Sum_h = 0.0;
      for (iy = 0; iy < 6; iy++) {
        rtb_Sum_h += rtb_MatrixConcatenation_0[6 * iy + i2] *
          sixdof_B.MatrixConcatenation2[6 * i + iy];
      }

      rtb_MatrixConcatenation_1[i2 + 6 * i] = rtb_Sum_h;
    }
  }

  /* End of Product: '<S15>/Sigma*A' */

  /* SignalConversion generated from: '<S15>/Sigma*A*V+' */
  rtb_MathFunction1_0[0] = rtb_Gain2[0];
  rtb_MathFunction1_0[3] = sixdof_B.pqr[0];
  rtb_MathFunction1_0[1] = rtb_Gain2[1];
  rtb_MathFunction1_0[4] = sixdof_B.pqr[1];
  rtb_MathFunction1_0[2] = rtb_Gain2[2];
  rtb_MathFunction1_0[5] = sixdof_B.pqr[2];

  /* Product: '<S15>/Sigma*A*V+' incorporates:
   *  Product: '<S15>/V*dot '
   *  Reshape: '<S9>/Reshape'
   *  Sum: '<S15>/Sum1'
   *  Sum: '<S1>/Sum'
   */
  for (i = 0; i < 6; i++) {
    rtb_Sum_h = 0.0;
    for (i2 = 0; i2 < 6; i2++) {
      rtb_Sum_h += rtb_MatrixConcatenation_1[6 * i2 + i] *
        rtb_MathFunction1_0[i2];
    }

    sixdof_B.Vdot[i] = (sixdof_B.Reshape[i] + tmp[i]) - rtb_Sum_h;
  }

  /* End of Product: '<S15>/Sigma*A*V+' */

  /* Product: '<S15>/V*dot ' incorporates:
   *  Concatenate: '<S17>/Matrix Concatenation2'
   */
  rt_mldivide_U1d6x6_U2d_njaLHVwJ(sixdof_B.MatrixConcatenation2, sixdof_B.Vdot);
  if (rtmIsMajorTimeStep(sixdof_M)) {
  }

  /* Gain: '<S1>/R2D1' */
  sixdof_B.R2D1 = sixdof_P.R2D1_Gain_g * sixdof_B.Vdot[5];
  if (rtmIsMajorTimeStep(sixdof_M)) {
  }

  /* Fcn: '<S16>/phidot' incorporates:
   *  Fcn: '<S16>/psidot'
   */
  rtb_Sum_h = tan(rtb_phithetapsi[1]);
  rtb_Deg2Rad3 = sixdof_B.pqr[1] * rtb_Deg2Rad4;
  rtb_CD = sixdof_B.pqr[2] * rtb_Deg2Rad2;

  /* SignalConversion generated from: '<S7>/phi theta psi' incorporates:
   *  Fcn: '<S16>/phidot'
   *  Fcn: '<S16>/psidot'
   *  Fcn: '<S16>/thetadot'
   */
  sixdof_B.TmpSignalConversionAtphithetaps[0] = (rtb_Deg2Rad3 * rtb_Sum_h +
    sixdof_B.pqr[0]) + rtb_CD * rtb_Sum_h;
  sixdof_B.TmpSignalConversionAtphithetaps[1] = sixdof_B.pqr[1] * rtb_Deg2Rad2 -
    sixdof_B.pqr[2] * rtb_Deg2Rad4;
  sixdof_B.TmpSignalConversionAtphithetaps[2] = rtb_Deg2Rad3 / rtb_u2_o + rtb_CD
    / rtb_u2_o;
  if (rtmIsMajorTimeStep(sixdof_M)) {
  }

  /* Gain: '<S12>/R2D' */
  sixdof_B.R2D[0] = sixdof_P.R2D_Gain * rtb_phithetapsi[0];
  sixdof_B.R2D[1] = sixdof_P.R2D_Gain * rtb_phithetapsi[1];
  sixdof_B.R2D[2] = sixdof_P.R2D_Gain * rtb_phithetapsi[2];
  if (rtmIsMajorTimeStep(sixdof_M)) {
    /* SignalConversion generated from: '<S12>/To File' */
    rtb_MatrixConcatenation[0] = 0.0;
    rtb_MatrixConcatenation[1] = sixdof_B.aoa;
    rtb_MatrixConcatenation[2] = sixdof_B.beta;
    rtb_MatrixConcatenation[3] = sixdof_B.ubvbwb[0];
    rtb_MatrixConcatenation[6] = sixdof_B.xeyeze[0];
    rtb_MatrixConcatenation[9] = sixdof_B.Product[0];
    rtb_MatrixConcatenation[12] = sixdof_B.R2D2[0];
    rtb_MatrixConcatenation[15] = sixdof_B.R2D[0];
    rtb_MatrixConcatenation[4] = sixdof_B.ubvbwb[1];
    rtb_MatrixConcatenation[7] = sixdof_B.xeyeze[1];
    rtb_MatrixConcatenation[10] = sixdof_B.Product[1];
    rtb_MatrixConcatenation[13] = sixdof_B.R2D2[1];
    rtb_MatrixConcatenation[16] = sixdof_B.R2D[1];
    rtb_MatrixConcatenation[5] = sixdof_B.ubvbwb[2];
    rtb_MatrixConcatenation[8] = sixdof_B.xeyeze[2];
    rtb_MatrixConcatenation[11] = sixdof_B.Product[2];
    rtb_MatrixConcatenation[14] = sixdof_B.R2D2[2];
    rtb_MatrixConcatenation[17] = sixdof_B.R2D[2];

    /* ToFile: '<S12>/To File' */
    {
      if (!(++sixdof_DW.ToFile_IWORK.Decimation % 1) &&
          (sixdof_DW.ToFile_IWORK.Count * (18 + 1)) + 1 < 100000000 ) {
        FILE *fp = (FILE *) sixdof_DW.ToFile_PWORK.FilePtr;
        if (fp != (NULL)) {
          real_T u[18 + 1];
          sixdof_DW.ToFile_IWORK.Decimation = 0;
          u[0] = sixdof_M->Timing.t[1];
          u[1] = rtb_MatrixConcatenation[0];
          u[2] = rtb_MatrixConcatenation[1];
          u[3] = rtb_MatrixConcatenation[2];
          u[4] = rtb_MatrixConcatenation[3];
          u[5] = rtb_MatrixConcatenation[4];
          u[6] = rtb_MatrixConcatenation[5];
          u[7] = rtb_MatrixConcatenation[6];
          u[8] = rtb_MatrixConcatenation[7];
          u[9] = rtb_MatrixConcatenation[8];
          u[10] = rtb_MatrixConcatenation[9];
          u[11] = rtb_MatrixConcatenation[10];
          u[12] = rtb_MatrixConcatenation[11];
          u[13] = rtb_MatrixConcatenation[12];
          u[14] = rtb_MatrixConcatenation[13];
          u[15] = rtb_MatrixConcatenation[14];
          u[16] = rtb_MatrixConcatenation[15];
          u[17] = rtb_MatrixConcatenation[16];
          u[18] = rtb_MatrixConcatenation[17];
          if (fwrite(u, sizeof(real_T), 18 + 1, fp) != 18 + 1) {
            rtmSetErrorStatus(sixdof_M, "Error writing to MAT-file simout.mat");
            return;
          }

          if (((++sixdof_DW.ToFile_IWORK.Count) * (18 + 1))+1 >= 100000000) {
            (void)fprintf(stdout,
                          "*** The ToFile block will stop logging data before\n"
                          "    the simulation has ended, because it has reached\n"
                          "    the maximum number of elements (100000000)\n"
                          "    allowed in MAT-file simout.mat.\n");
          }
        }
      }
    }

    /* Gain: '<S85>/Integral Gain' */
    sixdof_B.IntegralGain = sixdof_P.DiscretePIDController_I * sixdof_B.Subtract;

    /* Gain: '<S135>/Integral Gain' */
    sixdof_B.IntegralGain_g = sixdof_P.DiscretePIDController1_I *
      sixdof_B.pitch_error;

    /* Gain: '<S281>/Integral Gain' */
    sixdof_B.IntegralGain_e = sixdof_P.DiscretePIDController4_I *
      sixdof_B.airspeed_error;
  }

  /* MATLABSystem: '<Root>/Waypoint Follower' incorporates:
   *  Constant: '<Root>/Constant1'
   *  Constant: '<Root>/Lookahead Distance'
   */
  rtb_Sum_h = sixdof_P.LookaheadDistance_Value;
  sixdof_DW.obj.LookaheadDistFlag = 0U;
  if (sixdof_P.LookaheadDistance_Value < 0.1) {
    rtb_Sum_h = 0.1;
    sixdof_DW.obj.LookaheadDistFlag = 1U;
  }

  sixdof_DW.obj.InitialPose[0] = 0.0;
  sixdof_DW.obj.InitialPose[1] = 0.0;
  sixdof_DW.obj.InitialPose[2] = 0.0;
  sixdof_DW.obj.InitialPose[3] = 0.0;
  sixdof_DW.obj.NumWaypoints = 5.0;
  guard1 = false;
  if (sixdof_DW.obj.NumWaypoints != 5.0) {
    guard1 = true;
  } else {
    if (sixdof_DW.obj.NumWaypoints < 1.0) {
      iy = 0;
    } else {
      iy = (int32_T)sixdof_DW.obj.NumWaypoints;
    }

    if (sixdof_DW.obj.NumWaypoints < 1.0) {
      i = 0;
    } else {
      i = (int32_T)sixdof_DW.obj.NumWaypoints;
    }

    p = false;
    p_0 = false;
    if (iy == i) {
      p_0 = true;
    }

    if (p_0 && (iy != 0) && (i != 0)) {
      i2 = 0;
      exitg1 = false;
      while ((!exitg1) && (i2 <= i * 3 - 1)) {
        if (!(sixdof_DW.obj.WaypointsInternal[i2 / iy * 5 + i2 % iy] ==
              sixdof_P.Constant1_Value_e[i2 / i * 5 + i2 % i])) {
          p_0 = false;
          exitg1 = true;
        } else {
          i2++;
        }
      }
    }

    if (p_0) {
      p = true;
    }

    if (!p) {
      guard1 = true;
    }
  }

  if (guard1) {
    memcpy(&sixdof_DW.obj.WaypointsInternal[0], &sixdof_P.Constant1_Value_e[0],
           15U * sizeof(real_T));
    sixdof_DW.obj.WaypointIndex = 1.0;
  }

  for (i = 0; i < 5; i++) {
    distinctWptsIdx[i] = true;
  }

  for (i = 0; i < 3; i++) {
    rtb_Deg2Rad4 = sixdof_P.Constant1_Value_e[5 * i + 1];
    i2 = i << 2;
    x[i2] = (sixdof_P.Constant1_Value_e[5 * i] != rtb_Deg2Rad4);
    rtb_Deg2Rad2 = sixdof_P.Constant1_Value_e[5 * i + 2];
    x[i2 + 1] = (rtb_Deg2Rad4 != rtb_Deg2Rad2);
    rtb_Deg2Rad4 = sixdof_P.Constant1_Value_e[5 * i + 3];
    x[i2 + 2] = (rtb_Deg2Rad2 != rtb_Deg2Rad4);
    x[i2 + 3] = (sixdof_P.Constant1_Value_e[5 * i + 4] != rtb_Deg2Rad4);
  }

  y[0] = false;
  y[1] = false;
  y[2] = false;
  y[3] = false;
  i = 0;
  i2 = 8;
  for (iy = 0; iy < 4; iy++) {
    i++;
    i2++;
    ix = i;
    exitg1 = false;
    while ((!exitg1) && (ix <= i2)) {
      if (x[ix - 1]) {
        y[iy] = true;
        exitg1 = true;
      } else {
        ix += 4;
      }
    }
  }

  distinctWptsIdx[0] = y[0];
  distinctWptsIdx[1] = y[1];
  distinctWptsIdx[2] = y[2];
  distinctWptsIdx[3] = y[3];
  i2 = 0;
  for (i = 0; i < 5; i++) {
    /* MATLABSystem: '<Root>/Waypoint Follower' */
    if (distinctWptsIdx[i]) {
      i2++;
    }
  }

  iy = i2;
  i2 = 0;
  for (i = 0; i < 5; i++) {
    /* MATLABSystem: '<Root>/Waypoint Follower' */
    if (distinctWptsIdx[i]) {
      tmp_data[i2] = (int8_T)i;
      i2++;
    }
  }

  /* MATLABSystem: '<Root>/Waypoint Follower' incorporates:
   *  Constant: '<Root>/Constant1'
   *  SignalConversion generated from: '<Root>/Vector Concatenate'
   * */
  for (i = 0; i < 3; i++) {
    for (i2 = 0; i2 < iy; i2++) {
      b_waypointsIn_data[i2 + iy * i] = sixdof_P.Constant1_Value_e[5 * i +
        tmp_data[i2]];
    }
  }

  sixdof_DW.obj.LookaheadDistance = rtb_Sum_h;
  if (iy == 0) {
  } else {
    guard1 = false;
    if (iy == 1) {
      if (sixdof_DW.obj.StartFlag) {
        sixdof_DW.obj.InitialPose[0] = sixdof_B.xeyeze[0];
        sixdof_DW.obj.InitialPose[1] = sixdof_B.xeyeze[1];
        sixdof_DW.obj.InitialPose[2] = sixdof_B.xeyeze[2];
        sixdof_DW.obj.InitialPose[3] = sixdof_B.pqr[2];
      }

      rtb_phithetapsi[0] = b_waypointsIn_data[0] - sixdof_B.xeyeze[0];
      rtb_phithetapsi[1] = b_waypointsIn_data[1] - sixdof_B.xeyeze[1];
      rtb_phithetapsi[2] = b_waypointsIn_data[2] - sixdof_B.xeyeze[2];
      if (sixdof_norm(rtb_phithetapsi) < 1.4901161193847656E-8) {
        sixdof_DW.obj.StartFlag = false;
      } else {
        sixdof_DW.obj.StartFlag = false;
        sixdof_DW.obj.NumWaypoints = 2.0;
        ix = iy + 1;
        for (i = 0; i < 3; i++) {
          waypoints_data_tmp = (iy + 1) * i;
          waypoints_data[waypoints_data_tmp] = sixdof_DW.obj.InitialPose[i];
          for (i2 = 0; i2 < iy; i2++) {
            waypoints_data[(i2 + waypoints_data_tmp) + 1] =
              b_waypointsIn_data[iy * i + i2];
          }
        }

        guard1 = true;
      }
    } else {
      ix = iy;
      iy *= 3;
      if (iy - 1 >= 0) {
        memcpy(&waypoints_data[0], &b_waypointsIn_data[0], (uint32_T)iy * sizeof
               (real_T));
      }

      guard1 = true;
    }

    if (guard1) {
      p = false;
      if (sixdof_DW.obj.WaypointIndex == sixdof_DW.obj.NumWaypoints) {
        p = true;
      }

      if (p) {
        sixdof_DW.obj.LastWaypointFlag = true;
        sixdof_DW.obj.WaypointIndex--;
      }

      rtb_VectorConcatenate_0[0] = sixdof_B.xeyeze[0] - waypoints_data[(int32_T)
        (sixdof_DW.obj.WaypointIndex + 1.0) - 1];
      rtb_VectorConcatenate_0[1] = sixdof_B.xeyeze[1] - waypoints_data[((int32_T)
        (sixdof_DW.obj.WaypointIndex + 1.0) + ix) - 1];
      rtb_VectorConcatenate_0[2] = sixdof_B.xeyeze[2] - waypoints_data[((int32_T)
        (sixdof_DW.obj.WaypointIndex + 1.0) + (ix << 1)) - 1];
      guard2 = false;
      if (sixdof_norm(rtb_VectorConcatenate_0) <= 10.0) {
        guard2 = true;
      } else {
        rtb_Sum_h = waypoints_data[(int32_T)(sixdof_DW.obj.WaypointIndex + 1.0)
          - 1];
        rtb_phithetapsi[0] = sixdof_B.xeyeze[0] - rtb_Sum_h;
        rtb_Gain2[0] = rtb_Sum_h - waypoints_data[(int32_T)
          sixdof_DW.obj.WaypointIndex - 1];
        rtb_Sum_h = waypoints_data[((int32_T)(sixdof_DW.obj.WaypointIndex + 1.0)
          + ix) - 1];
        rtb_phithetapsi[1] = sixdof_B.xeyeze[1] - rtb_Sum_h;
        rtb_Gain2[1] = rtb_Sum_h - waypoints_data[((int32_T)
          sixdof_DW.obj.WaypointIndex + ix) - 1];
        rtb_Deg2Rad = waypoints_data[((int32_T)(sixdof_DW.obj.WaypointIndex +
          1.0) + (ix << 1)) - 1];
        rtb_phithetapsi[2] = sixdof_B.xeyeze[2] - rtb_Deg2Rad;
        rtb_Sum2 = waypoints_data[((ix << 1) + (int32_T)
          sixdof_DW.obj.WaypointIndex) - 1];
        rtb_Gain2[2] = rtb_Deg2Rad - rtb_Sum2;
        rtb_Deg2Rad3 = sixdof_norm(rtb_Gain2);
        Weightmatrix_Value = sixdof_norm(rtb_phithetapsi);
        rtb_Sum_h = waypoints_data[(int32_T)sixdof_DW.obj.WaypointIndex - 1];
        rtb_Deg2Rad4 = waypoints_data[(int32_T)(sixdof_DW.obj.WaypointIndex +
          1.0) - 1];
        rtb_Deg2Rad2 = waypoints_data[((int32_T)sixdof_DW.obj.WaypointIndex + ix)
          - 1];
        rtb_u2_o = waypoints_data[((int32_T)(sixdof_DW.obj.WaypointIndex + 1.0)
          + ix) - 1];
        rtb_CD = ((rtb_Deg2Rad4 - rtb_Sum_h) / rtb_Deg2Rad3 * (rtb_phithetapsi[0]
                   / Weightmatrix_Value) + (rtb_u2_o - rtb_Deg2Rad2) /
                  rtb_Deg2Rad3 * (rtb_phithetapsi[1] / Weightmatrix_Value)) +
          (rtb_Deg2Rad - rtb_Sum2) / rtb_Deg2Rad3 * (rtb_phithetapsi[2] /
          Weightmatrix_Value);
        if (rtIsNaN(rtb_CD)) {
          rtb_Deg2Rad3 = (rtNaN);
        } else if (rtb_CD < 0.0) {
          rtb_Deg2Rad3 = -1.0;
        } else {
          rtb_Deg2Rad3 = (rtb_CD > 0.0);
        }

        if (rtb_Deg2Rad3 >= 0.0) {
          guard2 = true;
        } else {
          rtb_phithetapsi[0] = rtb_Sum_h;
          rtb_Gain2[0] = rtb_Deg2Rad4;
          rtb_phithetapsi[1] = rtb_Deg2Rad2;
          rtb_Gain2[1] = rtb_u2_o;
          rtb_phithetapsi[2] = rtb_Sum2;
          rtb_Gain2[2] = rtb_Deg2Rad;
        }
      }

      if (guard2) {
        sixdof_DW.obj.WaypointIndex++;
        p = false;
        if (sixdof_DW.obj.WaypointIndex == sixdof_DW.obj.NumWaypoints) {
          p = true;
        }

        if (p) {
          sixdof_DW.obj.LastWaypointFlag = true;
          sixdof_DW.obj.WaypointIndex--;
        }

        rtb_phithetapsi[0] = waypoints_data[(int32_T)sixdof_DW.obj.WaypointIndex
          - 1];
        rtb_Gain2[0] = waypoints_data[(int32_T)(sixdof_DW.obj.WaypointIndex +
          1.0) - 1];
        rtb_phithetapsi[1] = waypoints_data[((int32_T)
          sixdof_DW.obj.WaypointIndex + ix) - 1];
        rtb_Gain2[1] = waypoints_data[((int32_T)(sixdof_DW.obj.WaypointIndex +
          1.0) + ix) - 1];
        rtb_phithetapsi[2] = waypoints_data[((ix << 1) + (int32_T)
          sixdof_DW.obj.WaypointIndex) - 1];
        rtb_Gain2[2] = waypoints_data[((int32_T)(sixdof_DW.obj.WaypointIndex +
          1.0) + (ix << 1)) - 1];
      }

      rtb_Deg2Rad4 = rtb_Gain2[0] - rtb_phithetapsi[0];
      rtb_Deg2Rad2 = sixdof_B.xeyeze[0] - rtb_phithetapsi[0];
      rtb_u2_o = rtb_Gain2[1] - rtb_phithetapsi[1];
      rtb_Deg2Rad = sixdof_B.xeyeze[1] - rtb_phithetapsi[1];
      rtb_Sum2 = rtb_Gain2[2] - rtb_phithetapsi[2];
      rtb_Deg2Rad3 = sixdof_B.xeyeze[2] - rtb_phithetapsi[2];
      rtb_CD = ((rtb_Deg2Rad * rtb_u2_o + rtb_Deg2Rad2 * rtb_Deg2Rad4) +
                rtb_Deg2Rad3 * rtb_Sum2) / ((rtb_u2_o * rtb_u2_o + rtb_Deg2Rad4 *
        rtb_Deg2Rad4) + rtb_Sum2 * rtb_Sum2);
      rtb_Sum_h = rtb_CD;
      if (rtb_Sum_h < 0.0) {
        rtb_VectorConcatenate_0[0] = rtb_Deg2Rad2;
        rtb_VectorConcatenate_0[1] = rtb_Deg2Rad;
        rtb_VectorConcatenate_0[2] = rtb_Deg2Rad3;
        rtb_Sum_h = sixdof_norm(rtb_VectorConcatenate_0);
      } else if (rtb_Sum_h > 1.0) {
        rtb_VectorConcatenate_0[0] = sixdof_B.xeyeze[0] - rtb_Gain2[0];
        rtb_VectorConcatenate_0[1] = sixdof_B.xeyeze[1] - rtb_Gain2[1];
        rtb_VectorConcatenate_0[2] = sixdof_B.xeyeze[2] - rtb_Gain2[2];
        rtb_Sum_h = sixdof_norm(rtb_VectorConcatenate_0);
      } else {
        rtb_VectorConcatenate_0[0] = sixdof_B.xeyeze[0] - (rtb_Sum_h *
          rtb_Deg2Rad4 + rtb_phithetapsi[0]);
        rtb_VectorConcatenate_0[1] = sixdof_B.xeyeze[1] - (rtb_Sum_h * rtb_u2_o
          + rtb_phithetapsi[1]);
        rtb_VectorConcatenate_0[2] = sixdof_B.xeyeze[2] - (rtb_Sum_h * rtb_Sum2
          + rtb_phithetapsi[2]);
        rtb_Sum_h = sixdof_norm(rtb_VectorConcatenate_0);
      }

      if (sixdof_DW.obj.LastWaypointFlag) {
        rtb_Sum_h = rtb_CD;
        rtb_VectorConcatenate_0[0] = sixdof_B.xeyeze[0] - (rtb_Sum_h *
          rtb_Deg2Rad4 + rtb_phithetapsi[0]);
        rtb_VectorConcatenate_0[1] = sixdof_B.xeyeze[1] - (rtb_Sum_h * rtb_u2_o
          + rtb_phithetapsi[1]);
        rtb_VectorConcatenate_0[2] = sixdof_B.xeyeze[2] - (rtb_Sum_h * rtb_Sum2
          + rtb_phithetapsi[2]);
        rtb_Sum_h = sixdof_norm(rtb_VectorConcatenate_0);
      }

      rtb_Deg2Rad4 = fabs(rtb_Sum_h);
      if (rtIsInf(rtb_Deg2Rad4) || rtIsNaN(rtb_Deg2Rad4)) {
        rtb_Deg2Rad2 = (rtNaN);
        rtb_Deg2Rad4 = (rtNaN);
      } else if (rtb_Deg2Rad4 < 4.4501477170144028E-308) {
        rtb_Deg2Rad2 = 4.94065645841247E-324;
        rtb_Deg2Rad4 = 4.94065645841247E-324;
      } else {
        frexp(rtb_Deg2Rad4, &b_exponent);
        rtb_Deg2Rad2 = ldexp(1.0, b_exponent - 53);
        frexp(rtb_Deg2Rad4, &b_exponent_0);
        rtb_Deg2Rad4 = ldexp(1.0, b_exponent_0 - 53);
      }

      rtb_Deg2Rad2 = sqrt(rtb_Deg2Rad2);
      rtb_Deg2Rad4 *= 5.0;
      if ((rtb_Deg2Rad2 >= rtb_Deg2Rad4) || rtIsNaN(rtb_Deg2Rad4)) {
        rtb_Deg2Rad4 = rtb_Deg2Rad2;
      }

      if (sixdof_DW.obj.LookaheadDistance <= rtb_Sum_h + rtb_Deg2Rad4) {
        sixdof_DW.obj.LookaheadDistance = sixdof_DW.obj.LookaheadFactor *
          rtb_Sum_h;
      }

      sixdof_DW.obj.LastWaypointFlag = false;
    }
  }

  if (rtmIsMajorTimeStep(sixdof_M)) {
  }
}

/* Model update function */
void sixdof_update(void)
{
  if (rtmIsMajorTimeStep(sixdof_M)) {
    /* Update for DiscreteIntegrator: '<S284>/Integrator' */
    sixdof_DW.Integrator_DSTATE += sixdof_P.Integrator_gainval *
      sixdof_B.IntegralGain_e;

    /* Update for Delay: '<S277>/UD' */
    sixdof_DW.UD_DSTATE = sixdof_B.Tsamp;

    /* Update for DiscreteIntegrator: '<S88>/Integrator' */
    sixdof_DW.Integrator_DSTATE_e += sixdof_P.Integrator_gainval_i *
      sixdof_B.IntegralGain;

    /* Update for DiscreteIntegrator: '<S83>/Filter' */
    sixdof_DW.Filter_DSTATE += sixdof_P.Filter_gainval *
      sixdof_B.FilterCoefficient;

    /* Update for DiscreteIntegrator: '<S138>/Integrator' */
    sixdof_DW.Integrator_DSTATE_e5 += sixdof_P.Integrator_gainval_o *
      sixdof_B.IntegralGain_g;

    /* Update for Delay: '<S131>/UD' */
    sixdof_DW.UD_DSTATE_l = sixdof_B.Tsamp_o;
  }

  /* ContTimeOutputInconsistentWithStateAtMajorOutputFlag is set, need to run a minor output */
  if (rtmIsMajorTimeStep(sixdof_M)) {
    if (rtsiGetContTimeOutputInconsistentWithStateAtMajorStep
        (&sixdof_M->solverInfo)) {
      rtsiSetSimTimeStep(&sixdof_M->solverInfo,MINOR_TIME_STEP);
      rtsiSetContTimeOutputInconsistentWithStateAtMajorStep
        (&sixdof_M->solverInfo, false);
      sixdof_output();
      rtsiSetSimTimeStep(&sixdof_M->solverInfo, MAJOR_TIME_STEP);
    }
  }

  if (rtmIsMajorTimeStep(sixdof_M)) {
    rt_ertODEUpdateContinuousStates(&sixdof_M->solverInfo);

    /* Update absolute time for base rate */
    /* The "clockTick0" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick0"
     * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick0 and the high bits
     * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++sixdof_M->Timing.clockTick0)) {
      ++sixdof_M->Timing.clockTickH0;
    }

    sixdof_M->Timing.t[0] = rtsiGetSolverStopTime(&sixdof_M->solverInfo);

    {
      /* Update absolute timer for sample time: [0.01s, 0.0s] */
      /* The "clockTick1" counts the number of times the code of this task has
       * been executed. The absolute time is the multiplication of "clockTick1"
       * and "Timing.stepSize1". Size of "clockTick1" ensures timer will not
       * overflow during the application lifespan selected.
       * Timer of this task consists of two 32 bit unsigned integers.
       * The two integers represent the low bits Timing.clockTick1 and the high bits
       * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
       */
      if (!(++sixdof_M->Timing.clockTick1)) {
        ++sixdof_M->Timing.clockTickH1;
      }

      sixdof_M->Timing.t[1] = sixdof_M->Timing.clockTick1 *
        sixdof_M->Timing.stepSize1 + sixdof_M->Timing.clockTickH1 *
        sixdof_M->Timing.stepSize1 * 4294967296.0;
    }
  }                                    /* end MajorTimeStep */
}

/* Derivatives for root system: '<Root>' */
void sixdof_derivatives(void)
{
  XDot_sixdof_T *_rtXdot;
  _rtXdot = ((XDot_sixdof_T *) sixdof_M->derivs);

  /* Derivatives for Integrator: '<S7>/pqr' */
  _rtXdot->pqr_CSTATE[0] = sixdof_B.Vdot[3];

  /* Derivatives for Integrator: '<S7>/xe ye ze' */
  _rtXdot->xeyeze_CSTATE[0] = sixdof_B.Zpositiveisdown[0];

  /* Derivatives for Integrator: '<S7>/phi theta psi' */
  _rtXdot->phithetapsi_CSTATE[0] = sixdof_B.TmpSignalConversionAtphithetaps[0];

  /* Derivatives for Integrator: '<S7>/ub vb wb' */
  _rtXdot->ubvbwb_CSTATE[0] = sixdof_B.Vdot[0];

  /* Derivatives for Integrator: '<S7>/pqr' */
  _rtXdot->pqr_CSTATE[1] = sixdof_B.Vdot[4];

  /* Derivatives for Integrator: '<S7>/xe ye ze' */
  _rtXdot->xeyeze_CSTATE[1] = sixdof_B.Zpositiveisdown[1];

  /* Derivatives for Integrator: '<S7>/phi theta psi' */
  _rtXdot->phithetapsi_CSTATE[1] = sixdof_B.TmpSignalConversionAtphithetaps[1];

  /* Derivatives for Integrator: '<S7>/ub vb wb' */
  _rtXdot->ubvbwb_CSTATE[1] = sixdof_B.Vdot[1];

  /* Derivatives for Integrator: '<S7>/pqr' */
  _rtXdot->pqr_CSTATE[2] = sixdof_B.Vdot[5];

  /* Derivatives for Integrator: '<S7>/xe ye ze' */
  _rtXdot->xeyeze_CSTATE[2] = sixdof_B.Zpositiveisdown[2];

  /* Derivatives for Integrator: '<S7>/phi theta psi' */
  _rtXdot->phithetapsi_CSTATE[2] = sixdof_B.TmpSignalConversionAtphithetaps[2];

  /* Derivatives for Integrator: '<S7>/ub vb wb' */
  _rtXdot->ubvbwb_CSTATE[2] = sixdof_B.Vdot[2];
}

/* ZeroCrossings for root system: '<Root>' */
void sixdof_zeroCrossings(void)
{
  ZCV_sixdof_T *_rtZCSV;
  _rtZCSV = ((ZCV_sixdof_T *) sixdof_M->zcSignalVector);

  /* ZeroCrossings for Switch: '<S45>/Switch' */
  _rtZCSV->Switch_SwitchCond_ZC = sixdof_B.Subtract_c -
    sixdof_P.Switch_Threshold;

  /* ZeroCrossings for Saturate: '<S54>/Limit  altitude' */
  _rtZCSV->Limitaltitude_UprLim_ZC = sixdof_B.xeyeze[2] - sixdof_P.ISA_hmax;
  _rtZCSV->Limitaltitude_LwrLim_ZC = sixdof_B.xeyeze[2] -
    sixdof_P.Limitaltitude_LowerSat;

  /* ZeroCrossings for Saturate: '<S8>/Saturation' */
  _rtZCSV->Saturation_UprLim_ZC[1] = sixdof_B.mps2fps -
    sixdof_P.Saturation_UpperSat;
  _rtZCSV->Saturation_LwrLim_ZC[1] = sixdof_B.mps2fps -
    sixdof_P.Saturation_LowerSat;

  /* ZeroCrossings for Saturate: '<S8>/Saturation1' */
  _rtZCSV->Saturation1_UprLim_ZC = sixdof_B.kg2N - sixdof_P.Saturation1_UpperSat;
  _rtZCSV->Saturation1_LwrLim_ZC = sixdof_B.kg2N - sixdof_P.Saturation1_LowerSat;
}

/* Model initialize function */
void sixdof_initialize(void)
{
  /* Start for Math: '<S45>/Math Function' */
  sixdof_DW.MathFunction_DWORK1_o = 0;

  /* Start for ToFile: '<S12>/To File' */
  {
    FILE *fp = (NULL);
    char fileName[509] = "simout.mat";
    if ((fp = fopen(fileName, "wb")) == (NULL)) {
      rtmSetErrorStatus(sixdof_M, "Error creating .mat file simout.mat");
      return;
    }

    if (rt_WriteMat4FileHeader(fp, 18 + 1, 0, "simout")) {
      rtmSetErrorStatus(sixdof_M,
                        "Error writing mat file header to file simout.mat");
      return;
    }

    sixdof_DW.ToFile_IWORK.Count = 0;
    sixdof_DW.ToFile_IWORK.Decimation = -1;
    sixdof_DW.ToFile_PWORK.FilePtr = fp;
  }

  /* Start for MATLABSystem: '<Root>/Waypoint Follower' */
  sixdof_DW.obj.LastWaypointFlag = false;
  sixdof_DW.obj.StartFlag = true;
  sixdof_DW.obj.LookaheadFactor = 1.01;
  sixdof_DW.objisempty = true;
  sixdof_DW.obj.isInitialized = 1;
  memset(&sixdof_DW.obj.WaypointsInternal[0], 0, 15U * sizeof(real_T));
  sixdof_DW.obj.NumWaypoints = 0.0;

  {
    int32_T i;

    /* InitializeConditions for Integrator: '<S7>/pqr' */
    sixdof_X.pqr_CSTATE[0] = sixdof_P.pqr_IC[0];

    /* InitializeConditions for Integrator: '<S7>/xe ye ze' */
    sixdof_X.xeyeze_CSTATE[0] = sixdof_P.Pos_0[0];

    /* InitializeConditions for Integrator: '<S7>/phi theta psi' */
    sixdof_X.phithetapsi_CSTATE[0] = sixdof_P.Euler_0[0];

    /* InitializeConditions for Integrator: '<S7>/ub vb wb' */
    sixdof_X.ubvbwb_CSTATE[0] = sixdof_P.ubvbwb_IC[0];

    /* InitializeConditions for Integrator: '<S7>/pqr' */
    sixdof_X.pqr_CSTATE[1] = sixdof_P.pqr_IC[1];

    /* InitializeConditions for Integrator: '<S7>/xe ye ze' */
    sixdof_X.xeyeze_CSTATE[1] = sixdof_P.Pos_0[1];

    /* InitializeConditions for Integrator: '<S7>/phi theta psi' */
    sixdof_X.phithetapsi_CSTATE[1] = sixdof_P.Euler_0[1];

    /* InitializeConditions for Integrator: '<S7>/ub vb wb' */
    sixdof_X.ubvbwb_CSTATE[1] = sixdof_P.ubvbwb_IC[1];

    /* InitializeConditions for Integrator: '<S7>/pqr' */
    sixdof_X.pqr_CSTATE[2] = sixdof_P.pqr_IC[2];

    /* InitializeConditions for Integrator: '<S7>/xe ye ze' */
    sixdof_X.xeyeze_CSTATE[2] = sixdof_P.Pos_0[2];

    /* InitializeConditions for Integrator: '<S7>/phi theta psi' */
    sixdof_X.phithetapsi_CSTATE[2] = sixdof_P.Euler_0[2];

    /* InitializeConditions for Integrator: '<S7>/ub vb wb' */
    sixdof_X.ubvbwb_CSTATE[2] = sixdof_P.ubvbwb_IC[2];

    /* InitializeConditions for DiscreteIntegrator: '<S284>/Integrator' */
    sixdof_DW.Integrator_DSTATE = sixdof_P.DiscretePIDController4_InitialC;

    /* InitializeConditions for Delay: '<S277>/UD' */
    sixdof_DW.UD_DSTATE = sixdof_P.DiscretePIDController4_Differen;

    /* InitializeConditions for DiscreteIntegrator: '<S88>/Integrator' */
    sixdof_DW.Integrator_DSTATE_e = sixdof_P.DiscretePIDController_Initial_f;

    /* InitializeConditions for DiscreteIntegrator: '<S83>/Filter' */
    sixdof_DW.Filter_DSTATE = sixdof_P.DiscretePIDController_InitialCo;

    /* InitializeConditions for DiscreteIntegrator: '<S138>/Integrator' */
    sixdof_DW.Integrator_DSTATE_e5 = sixdof_P.DiscretePIDController1_InitialC;

    /* InitializeConditions for Delay: '<S131>/UD' */
    sixdof_DW.UD_DSTATE_l = sixdof_P.DiscretePIDController1_Differen;

    /* InitializeConditions for MATLABSystem: '<Root>/Waypoint Follower' */
    sixdof_DW.obj.WaypointIndex = 1.0;
    for (i = 0; i < 15; i++) {
      sixdof_DW.obj.WaypointsInternal[i] *= 0.0;
    }

    /* End of InitializeConditions for MATLABSystem: '<Root>/Waypoint Follower' */
  }
}

/* Model terminate function */
void sixdof_terminate(void)
{
  /* Terminate for ToFile: '<S12>/To File' */
  {
    FILE *fp = (FILE *) sixdof_DW.ToFile_PWORK.FilePtr;
    if (fp != (NULL)) {
      char fileName[509] = "simout.mat";
      if (fclose(fp) == EOF) {
        rtmSetErrorStatus(sixdof_M, "Error closing MAT-file simout.mat");
        return;
      }

      if ((fp = fopen(fileName, "r+b")) == (NULL)) {
        rtmSetErrorStatus(sixdof_M, "Error reopening MAT-file simout.mat");
        return;
      }

      if (rt_WriteMat4FileHeader(fp, 18 + 1, sixdof_DW.ToFile_IWORK.Count,
           "simout")) {
        rtmSetErrorStatus(sixdof_M,
                          "Error writing header for simout to MAT-file simout.mat");
      }

      if (fclose(fp) == EOF) {
        rtmSetErrorStatus(sixdof_M, "Error closing MAT-file simout.mat");
        return;
      }

      sixdof_DW.ToFile_PWORK.FilePtr = (NULL);
    }
  }
}

/*========================================================================*
 * Start of Classic call interface                                        *
 *========================================================================*/

/* Solver interface called by GRT_Main */
#ifndef USE_GENERATED_SOLVER

void rt_ODECreateIntegrationData(RTWSolverInfo *si)
{
  UNUSED_PARAMETER(si);
  return;
}                                      /* do nothing */

void rt_ODEDestroyIntegrationData(RTWSolverInfo *si)
{
  UNUSED_PARAMETER(si);
  return;
}                                      /* do nothing */

void rt_ODEUpdateContinuousStates(RTWSolverInfo *si)
{
  UNUSED_PARAMETER(si);
  return;
}                                      /* do nothing */

#endif

void MdlOutputs(int_T tid)
{
  sixdof_output();
  UNUSED_PARAMETER(tid);
}

void MdlUpdate(int_T tid)
{
  sixdof_update();
  UNUSED_PARAMETER(tid);
}

void MdlInitializeSizes(void)
{
}

void MdlInitializeSampleTimes(void)
{
}

void MdlInitialize(void)
{
}

void MdlStart(void)
{
  sixdof_initialize();
}

void MdlTerminate(void)
{
  sixdof_terminate();
}

/* Registration function */
RT_MODEL_sixdof_T *sixdof(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* non-finite (run-time) assignments */
  sixdof_P.Saturation_UpperSat = rtInf;
  sixdof_P.Saturation1_UpperSat = rtInf;

  /* initialize real-time model */
  (void) memset((void *)sixdof_M, 0,
                sizeof(RT_MODEL_sixdof_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&sixdof_M->solverInfo, &sixdof_M->Timing.simTimeStep);
    rtsiSetTPtr(&sixdof_M->solverInfo, &rtmGetTPtr(sixdof_M));
    rtsiSetStepSizePtr(&sixdof_M->solverInfo, &sixdof_M->Timing.stepSize0);
    rtsiSetdXPtr(&sixdof_M->solverInfo, &sixdof_M->derivs);
    rtsiSetContStatesPtr(&sixdof_M->solverInfo, (real_T **)
                         &sixdof_M->contStates);
    rtsiSetNumContStatesPtr(&sixdof_M->solverInfo,
      &sixdof_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&sixdof_M->solverInfo,
      &sixdof_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&sixdof_M->solverInfo,
      &sixdof_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&sixdof_M->solverInfo,
      &sixdof_M->periodicContStateRanges);
    rtsiSetSolverZcSignalPtr(&sixdof_M->solverInfo, &sixdof_M->zcSignalVector);
    rtsiSetErrorStatusPtr(&sixdof_M->solverInfo, (&rtmGetErrorStatus(sixdof_M)));
    rtsiSetRTModelPtr(&sixdof_M->solverInfo, sixdof_M);
  }

  rtsiSetSimTimeStep(&sixdof_M->solverInfo, MAJOR_TIME_STEP);
  sixdof_M->intgData.y = sixdof_M->odeY;
  sixdof_M->intgData.f[0] = sixdof_M->odeF[0];
  sixdof_M->intgData.f[1] = sixdof_M->odeF[1];
  sixdof_M->intgData.f[2] = sixdof_M->odeF[2];
  sixdof_M->contStates = ((real_T *) &sixdof_X);
  sixdof_M->contStateDisabled = ((boolean_T *) &sixdof_XDis);
  rtsiSetSolverData(&sixdof_M->solverInfo, (void *)&sixdof_M->intgData);
  rtsiSetIsMinorTimeStepWithModeChange(&sixdof_M->solverInfo, false);

  {
    /* Zero-crossing Data */
    static uint8_T zcAttributes[9] = { (SL_ZCS_EVENT_ALL), (SL_ZCS_EVENT_ALL),
      (SL_ZCS_EVENT_ALL), (0x40|SL_ZCS_EVENT_ALL), (SL_ZCS_EVENT_ALL), (0x40|
      SL_ZCS_EVENT_ALL), (SL_ZCS_EVENT_ALL), (SL_ZCS_EVENT_ALL),
      (SL_ZCS_EVENT_ALL) };

    rtsiSetSolverZcSignalAttrib(&sixdof_M->solverInfo,
      zcAttributes);
    sixdof_M->zcDetectorData.vL = sixdof_M->zcVL;
    sixdof_M->zcDetectorData.vR = sixdof_M->zcVR;
    sixdof_M->zcDetectorData.vZ = sixdof_M->zcVZ;
    sixdof_M->zcDetectorData.t0 = sixdof_M->zct0;
    sixdof_M->zcDetectorData.tR = sixdof_M->zctR;
    sixdof_M->zcDetectorData.x0 = sixdof_M->zcx0;
    sixdof_M->zcDetectorData.xR = sixdof_M->zcxR;
  }

  rtsiSetSolverName(&sixdof_M->solverInfo,"ode3");

  /* Initialize timing info */
  {
    int_T *mdlTsMap = sixdof_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;

    /* polyspace +2 MISRA2012:D4.1 [Justified:Low] "sixdof_M points to
       static memory which is guaranteed to be non-NULL" */
    sixdof_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    sixdof_M->Timing.sampleTimes = (&sixdof_M->Timing.sampleTimesArray[0]);
    sixdof_M->Timing.offsetTimes = (&sixdof_M->Timing.offsetTimesArray[0]);

    /* task periods */
    sixdof_M->Timing.sampleTimes[0] = (0.0);
    sixdof_M->Timing.sampleTimes[1] = (0.01);

    /* task offsets */
    sixdof_M->Timing.offsetTimes[0] = (0.0);
    sixdof_M->Timing.offsetTimes[1] = (0.0);
  }

  rtmSetTPtr(sixdof_M, &sixdof_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = sixdof_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    mdlSampleHits[1] = 1;
    sixdof_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(sixdof_M, 1000.0);
  sixdof_M->Timing.stepSize0 = 0.01;
  sixdof_M->Timing.stepSize1 = 0.01;

  /* Setup for data logging */
  {
    static RTWLogInfo rt_DataLoggingInfo;
    rt_DataLoggingInfo.loggingInterval = (NULL);
    sixdof_M->rtwLogInfo = &rt_DataLoggingInfo;
  }

  /* Setup for data logging */
  {
    rtliSetLogXSignalInfo(sixdof_M->rtwLogInfo, (NULL));
    rtliSetLogXSignalPtrs(sixdof_M->rtwLogInfo, (NULL));
    rtliSetLogT(sixdof_M->rtwLogInfo, "tout");
    rtliSetLogX(sixdof_M->rtwLogInfo, "");
    rtliSetLogXFinal(sixdof_M->rtwLogInfo, "");
    rtliSetLogVarNameModifier(sixdof_M->rtwLogInfo, "rt_");
    rtliSetLogFormat(sixdof_M->rtwLogInfo, 0);
    rtliSetLogMaxRows(sixdof_M->rtwLogInfo, 1000);
    rtliSetLogDecimation(sixdof_M->rtwLogInfo, 1);
    rtliSetLogY(sixdof_M->rtwLogInfo, "");
    rtliSetLogYSignalInfo(sixdof_M->rtwLogInfo, (NULL));
    rtliSetLogYSignalPtrs(sixdof_M->rtwLogInfo, (NULL));
  }

  sixdof_M->solverInfoPtr = (&sixdof_M->solverInfo);
  sixdof_M->Timing.stepSize = (0.01);
  rtsiSetFixedStepSize(&sixdof_M->solverInfo, 0.01);
  rtsiSetSolverMode(&sixdof_M->solverInfo, SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  sixdof_M->blockIO = ((void *) &sixdof_B);
  (void) memset(((void *) &sixdof_B), 0,
                sizeof(B_sixdof_T));

  /* parameters */
  sixdof_M->defaultParam = ((real_T *)&sixdof_P);

  /* states (continuous) */
  {
    real_T *x = (real_T *) &sixdof_X;
    sixdof_M->contStates = (x);
    (void) memset((void *)&sixdof_X, 0,
                  sizeof(X_sixdof_T));
  }

  /* disabled states */
  {
    boolean_T *xdis = (boolean_T *) &sixdof_XDis;
    sixdof_M->contStateDisabled = (xdis);
    (void) memset((void *)&sixdof_XDis, 0,
                  sizeof(XDis_sixdof_T));
  }

  /* states (dwork) */
  sixdof_M->dwork = ((void *) &sixdof_DW);
  (void) memset((void *)&sixdof_DW, 0,
                sizeof(DW_sixdof_T));

  /* Initialize Sizes */
  sixdof_M->Sizes.numContStates = (12);/* Number of continuous states */
  sixdof_M->Sizes.numPeriodicContStates = (0);
                                      /* Number of periodic continuous states */
  sixdof_M->Sizes.numY = (0);          /* Number of model outputs */
  sixdof_M->Sizes.numU = (0);          /* Number of model inputs */
  sixdof_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  sixdof_M->Sizes.numSampTimes = (2);  /* Number of sample times */
  sixdof_M->Sizes.numBlocks = (329);   /* Number of blocks */
  sixdof_M->Sizes.numBlockIO = (49);   /* Number of block outputs */
  sixdof_M->Sizes.numBlockPrms = (18221);/* Sum of parameter "widths" */
  return sixdof_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
