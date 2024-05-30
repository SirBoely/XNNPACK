// Auto-generated file. Do not edit!
//   Template: src/f32-igemm/hvx-broadcast.c.in
//   Generator: tools/xngen
//
// Copyright 2019 Google LLC
//
// This source code is licensed under the BSD-style license found in the
// LICENSE file in the root directory of this source tree.

#include <assert.h>
#include <hexagon_types.h>
#include <hexagon_protos.h>
#include <hvx_hexagon_protos.h>

#include <xnnpack/igemm.h>

static XNN_INLINE
void vstu_variable_scalar(char *bytes, size_t num_bytes, HVX_Vector vin) {
  char temp[128]  __attribute__((aligned(128)));
  *((HVX_Vector *)temp) = vin;
  for (size_t idx = 0; idx < num_bytes; idx++){
     *bytes = temp[idx];
     bytes++;
  }
}

void xnn_f32_igemm_minmax_ukernel_7x64__hvx_broadcast(
    size_t mr,
    size_t nc,
    size_t kc,
    size_t ks,
    const float** restrict a,
    const float* restrict w,
    float* restrict c,
    size_t cm_stride,
    size_t cn_stride,
    size_t a_offset,
    const float* zero,
    const union xnn_f32_minmax_params params[restrict XNN_MIN_ELEMENTS(1)])
{
  assert(mr != 0);
  assert(mr <= 7);
  assert(nc != 0);
  assert(kc != 0);
  assert(kc % sizeof(float) == 0);
  assert(ks != 0);
  assert(ks % (7 * sizeof(void*)) == 0);
  assert(a_offset % sizeof(float) == 0);
  assert(a != NULL);
  assert(w != NULL);
  assert(c != NULL);

  float* c0 = c;
  float* c1 = (float*) ((uintptr_t) c0 + cm_stride);
  if XNN_UNPREDICTABLE(mr < 2) {
    c1 = c0;
  }
  float* c2 = (float*) ((uintptr_t) c1 + cm_stride);
  if XNN_UNPREDICTABLE(mr <= 2) {
    c2 = c1;
  }
  float* c3 = (float*) ((uintptr_t) c2 + cm_stride);
  if XNN_UNPREDICTABLE(mr < 4) {
    c3 = c2;
  }
  float* c4 = (float*) ((uintptr_t) c3 + cm_stride);
  if XNN_UNPREDICTABLE(mr <= 4) {
    c4 = c3;
  }
  float* c5 = (float*) ((uintptr_t) c4 + cm_stride);
  if XNN_UNPREDICTABLE(mr < 6) {
    c5 = c4;
  }
  float* c6 = (float*) ((uintptr_t) c5 + cm_stride);
  if XNN_UNPREDICTABLE(mr <= 6) {
    c6 = c5;
  }

  do {
    HVX_Vector vacc0x0 = *((HVX_Vector *)(w));
    HVX_Vector vacc0x = _mm256_load_ps(w + 32);
    HVX_Vector vacc1x = vacc0x0;
    HVX_Vector vacc1x = vacc0x1;
    HVX_Vector vacc2x = vacc0x0;
    HVX_Vector vacc2x = vacc0x1;
    HVX_Vector vacc3x = vacc0x0;
    HVX_Vector vacc3x = vacc0x1;
    HVX_Vector vacc4x = vacc0x0;
    HVX_Vector vacc4x = vacc0x1;
    HVX_Vector vacc5x = vacc0x0;
    HVX_Vector vacc5x = vacc0x1;
    HVX_Vector vacc6x = vacc0x0;
    HVX_Vector vacc6x = vacc0x1;
    w += 64;

    size_t p = ks;
    do {
      const float* restrict a0 = a[0];
      assert(a0 != NULL);
      if XNN_UNPREDICTABLE(a0 != zero) {
        a0 = (const float*) ((uintptr_t) a0 + a_offset);
      }
      const float* restrict a1 = a[1];
      assert(a1 != NULL);
      if XNN_UNPREDICTABLE(a1 != zero) {
        a1 = (const float*) ((uintptr_t) a1 + a_offset);
      }
      const float* restrict a2 = a[2];
      assert(a2 != NULL);
      if XNN_UNPREDICTABLE(a2 != zero) {
        a2 = (const float*) ((uintptr_t) a2 + a_offset);
      }
      const float* restrict a3 = a[3];
      assert(a3 != NULL);
      if XNN_UNPREDICTABLE(a3 != zero) {
        a3 = (const float*) ((uintptr_t) a3 + a_offset);
      }
      const float* restrict a4 = a[4];
      assert(a4 != NULL);
      if XNN_UNPREDICTABLE(a4 != zero) {
        a4 = (const float*) ((uintptr_t) a4 + a_offset);
      }
      const float* restrict a5 = a[5];
      assert(a5 != NULL);
      if XNN_UNPREDICTABLE(a5 != zero) {
        a5 = (const float*) ((uintptr_t) a5 + a_offset);
      }
      const float* restrict a6 = a[6];
      assert(a6 != NULL);
      if XNN_UNPREDICTABLE(a6 != zero) {
        a6 = (const float*) ((uintptr_t) a6 + a_offset);
      }
      a += 7;

      size_t k = kc;
      do {
        const HVX_Vector vb0 = *((HVX_Vector *)(w));
        const HVX_Vector vb = _mm256_load_ps(w + 32);
        w += 64;

        const HVX_Vector va0 =  Q6_V_vsplat_R(a0);
        a0 += 1;
        const HVX_Vector va1 =  Q6_V_vsplat_R(a1);
        a1 += 1;
        const HVX_Vector va2 =  Q6_V_vsplat_R(a2);
        a2 += 1;
        const HVX_Vector va3 =  Q6_V_vsplat_R(a3);
        a3 += 1;
        const HVX_Vector va4 =  Q6_V_vsplat_R(a4);
        a4 += 1;
        const HVX_Vector va5 =  Q6_V_vsplat_R(a5);
        a5 += 1;
        const HVX_Vector va6 =  Q6_V_vsplat_R(a6);
        a6 += 1;

        vacc0x = Q6_Vsf_equals_Vqf32(Q6_Vqf32_vadd_Vqf32Vsf(Q6_Vqf32_vmpy_VsfVsf(va0, vb0), vacc0x0));
        vacc0x = Q6_Vsf_equals_Vqf32(Q6_Vqf32_vadd_Vqf32Vsf(Q6_Vqf32_vmpy_VsfVsf(va0, vb1), vacc0x1));
        vacc1x = Q6_Vsf_equals_Vqf32(Q6_Vqf32_vadd_Vqf32Vsf(Q6_Vqf32_vmpy_VsfVsf(va1, vb0), vacc1x0));
        vacc1x = Q6_Vsf_equals_Vqf32(Q6_Vqf32_vadd_Vqf32Vsf(Q6_Vqf32_vmpy_VsfVsf(va1, vb1), vacc1x1));
        vacc2x = Q6_Vsf_equals_Vqf32(Q6_Vqf32_vadd_Vqf32Vsf(Q6_Vqf32_vmpy_VsfVsf(va2, vb0), vacc2x0));
        vacc2x = Q6_Vsf_equals_Vqf32(Q6_Vqf32_vadd_Vqf32Vsf(Q6_Vqf32_vmpy_VsfVsf(va2, vb1), vacc2x1));
        vacc3x = Q6_Vsf_equals_Vqf32(Q6_Vqf32_vadd_Vqf32Vsf(Q6_Vqf32_vmpy_VsfVsf(va3, vb0), vacc3x0));
        vacc3x = Q6_Vsf_equals_Vqf32(Q6_Vqf32_vadd_Vqf32Vsf(Q6_Vqf32_vmpy_VsfVsf(va3, vb1), vacc3x1));
        vacc4x = Q6_Vsf_equals_Vqf32(Q6_Vqf32_vadd_Vqf32Vsf(Q6_Vqf32_vmpy_VsfVsf(va4, vb0), vacc4x0));
        vacc4x = Q6_Vsf_equals_Vqf32(Q6_Vqf32_vadd_Vqf32Vsf(Q6_Vqf32_vmpy_VsfVsf(va4, vb1), vacc4x1));
        vacc5x = Q6_Vsf_equals_Vqf32(Q6_Vqf32_vadd_Vqf32Vsf(Q6_Vqf32_vmpy_VsfVsf(va5, vb0), vacc5x0));
        vacc5x = Q6_Vsf_equals_Vqf32(Q6_Vqf32_vadd_Vqf32Vsf(Q6_Vqf32_vmpy_VsfVsf(va5, vb1), vacc5x1));
        vacc6x = Q6_Vsf_equals_Vqf32(Q6_Vqf32_vadd_Vqf32Vsf(Q6_Vqf32_vmpy_VsfVsf(va6, vb0), vacc6x0));
        vacc6x = Q6_Vsf_equals_Vqf32(Q6_Vqf32_vadd_Vqf32Vsf(Q6_Vqf32_vmpy_VsfVsf(va6, vb1), vacc6x1));
        k -= sizeof(float);
      } while (k != 0);
      p -= 7 * sizeof(void*);
    } while (p != 0);

    const HVX_Vector vmin = *((HVX_Vector *)(params->hvx.min));
    vacc0x = Q6_Vw_vmax_VwVw(vmin, vacc0x0);
    vacc1x = Q6_Vw_vmax_VwVw(vmin, vacc1x0);
    vacc2x = Q6_Vw_vmax_VwVw(vmin, vacc2x0);
    vacc3x = Q6_Vw_vmax_VwVw(vmin, vacc3x0);
    vacc4x = Q6_Vw_vmax_VwVw(vmin, vacc4x0);
    vacc5x = Q6_Vw_vmax_VwVw(vmin, vacc5x0);
    vacc6x = Q6_Vw_vmax_VwVw(vmin, vacc6x0);
    vacc0x = Q6_Vw_vmax_VwVw(vmin, vacc0x1);
    vacc1x = Q6_Vw_vmax_VwVw(vmin, vacc1x1);
    vacc2x = Q6_Vw_vmax_VwVw(vmin, vacc2x1);
    vacc3x = Q6_Vw_vmax_VwVw(vmin, vacc3x1);
    vacc4x = Q6_Vw_vmax_VwVw(vmin, vacc4x1);
    vacc5x = Q6_Vw_vmax_VwVw(vmin, vacc5x1);
    vacc6x = Q6_Vw_vmax_VwVw(vmin, vacc6x1);

    const HVX_Vector vmax = *((HVX_Vector *)(params->hvx.max));
    vacc0x = Q6_Vw_vmin_VwVw(vmax, vacc0x0);
    vacc1x = Q6_Vw_vmin_VwVw(vmax, vacc1x0);
    vacc2x = Q6_Vw_vmin_VwVw(vmax, vacc2x0);
    vacc3x = Q6_Vw_vmin_VwVw(vmax, vacc3x0);
    vacc4x = Q6_Vw_vmin_VwVw(vmax, vacc4x0);
    vacc5x = Q6_Vw_vmin_VwVw(vmax, vacc5x0);
    vacc6x = Q6_Vw_vmin_VwVw(vmax, vacc6x0);
    vacc0x = Q6_Vw_vmin_VwVw(vmax, vacc0x1);
    vacc1x = Q6_Vw_vmin_VwVw(vmax, vacc1x1);
    vacc2x = Q6_Vw_vmin_VwVw(vmax, vacc2x1);
    vacc3x = Q6_Vw_vmin_VwVw(vmax, vacc3x1);
    vacc4x = Q6_Vw_vmin_VwVw(vmax, vacc4x1);
    vacc5x = Q6_Vw_vmin_VwVw(vmax, vacc5x1);
    vacc6x = Q6_Vw_vmin_VwVw(vmax, vacc6x1);

    if XNN_LIKELY(nc >= 64) {
      *((HVX_UVector *)(c6)) = vacc6x0;
      *((HVX_UVector *)(c6 + 32) = vacc6x1;
      c6 = (float*) ((uintptr_t) c6 + cn_stride);
      *((HVX_UVector *)(c5)) = vacc5x0;
      *((HVX_UVector *)(c5 + 32) = vacc5x1;
      c5 = (float*) ((uintptr_t) c5 + cn_stride);
      *((HVX_UVector *)(c4)) = vacc4x0;
      *((HVX_UVector *)(c4 + 32) = vacc4x1;
      c4 = (float*) ((uintptr_t) c4 + cn_stride);
      *((HVX_UVector *)(c3)) = vacc3x0;
      *((HVX_UVector *)(c3 + 32) = vacc3x1;
      c3 = (float*) ((uintptr_t) c3 + cn_stride);
      *((HVX_UVector *)(c2)) = vacc2x0;
      *((HVX_UVector *)(c2 + 32) = vacc2x1;
      c2 = (float*) ((uintptr_t) c2 + cn_stride);
      *((HVX_UVector *)(c1)) = vacc1x0;
      *((HVX_UVector *)(c1 + 32) = vacc1x1;
      c1 = (float*) ((uintptr_t) c1 + cn_stride);
      *((HVX_UVector *)(c0)) = vacc0x0;
      *((HVX_UVector *)(c0 + 32) = vacc0x1;
      c0 = (float*) ((uintptr_t) c0 + cn_stride);

      a = (const float**restrict) ((uintptr_t) a - ks);
      nc -= 64;
    } else {
      if (nc & 32) {
        *((HVX_UVector *)c6) = vacc6x0;
        *((HVX_UVector *)c5) = vacc5x0;
        *((HVX_UVector *)c4) = vacc4x0;
        *((HVX_UVector *)c3) = vacc3x0;
        *((HVX_UVector *)c2) = vacc2x0;
        *((HVX_UVector *)c1) = vacc1x0;
        *((HVX_UVector *)c0) = vacc0x0;

        vacc6x0 = vacc6x1; 
        vacc5x0 = vacc5x1; 
        vacc4x0 = vacc4x1; 
        vacc3x0 = vacc3x1; 
        vacc2x0 = vacc2x1; 
        vacc1x0 = vacc1x1; 
        vacc0x0 = vacc0x1; 

        c6 += 32;
        c5 += 32;
        c4 += 32;
        c3 += 32;
        c2 += 32;
        c1 += 32;
        c0 += 32;
        nc ^= 32;
      }
      vstu_variable_scalar((char*)c6, nc*sizeof(float), vacc6x0);
      vstu_variable_scalar((char*)c5, nc*sizeof(float), vacc5x0);
      vstu_variable_scalar((char*)c4, nc*sizeof(float), vacc4x0);
      vstu_variable_scalar((char*)c3, nc*sizeof(float), vacc3x0);
      vstu_variable_scalar((char*)c2, nc*sizeof(float), vacc2x0);
      vstu_variable_scalar((char*)c1, nc*sizeof(float), vacc1x0);
      vstu_variable_scalar((char*)c0, nc*sizeof(float), vacc0x0);

      nc = 0;
    }
  } while (nc != 0);
}
