// THIS IS AN AUTOMATICALLY GENERATED FILE.  DO NOT MODIFY
// BY HAND!!
//
// Generated by zcm-gen

#include <string.h>
#include "array_var_size1.h"

static int __array_var_size1_hash_computed;
static uint64_t __array_var_size1_hash;

uint64_t __array_var_size1_hash_recursive(const __zcm_hash_ptr *p)
{
    const __zcm_hash_ptr *fp;
    for (fp = p; fp != NULL; fp = fp->parent)
        if (fp->v == __array_var_size1_get_hash)
            return 0;

    __zcm_hash_ptr cp;
    cp.parent =  p;
    cp.v = (void*)__array_var_size1_get_hash;
    (void) cp;

    uint64_t hash = (uint64_t)0xd3b4ee3fab9e2e02LL
         + __int8_t_hash_recursive(&cp)
         + __int16_t_hash_recursive(&cp)
         + __int32_t_hash_recursive(&cp)
         + __int64_t_hash_recursive(&cp)
         + __int8_t_hash_recursive(&cp)
         + __int8_t_hash_recursive(&cp)
         + __int8_t_hash_recursive(&cp)
         + __int8_t_hash_recursive(&cp)
         + __int16_t_hash_recursive(&cp)
         + __int16_t_hash_recursive(&cp)
         + __int16_t_hash_recursive(&cp)
         + __int16_t_hash_recursive(&cp)
         + __int32_t_hash_recursive(&cp)
         + __int32_t_hash_recursive(&cp)
         + __int32_t_hash_recursive(&cp)
         + __int32_t_hash_recursive(&cp)
         + __int64_t_hash_recursive(&cp)
         + __int64_t_hash_recursive(&cp)
         + __int64_t_hash_recursive(&cp)
         + __int64_t_hash_recursive(&cp)
         + __float_hash_recursive(&cp)
         + __float_hash_recursive(&cp)
         + __float_hash_recursive(&cp)
         + __float_hash_recursive(&cp)
         + __double_hash_recursive(&cp)
         + __double_hash_recursive(&cp)
         + __double_hash_recursive(&cp)
         + __double_hash_recursive(&cp)
         + __string_hash_recursive(&cp)
         + __string_hash_recursive(&cp)
         + __string_hash_recursive(&cp)
         + __string_hash_recursive(&cp)
         + __boolean_hash_recursive(&cp)
         + __boolean_hash_recursive(&cp)
         + __boolean_hash_recursive(&cp)
         + __boolean_hash_recursive(&cp)
         + __byte_hash_recursive(&cp)
         + __byte_hash_recursive(&cp)
         + __byte_hash_recursive(&cp)
         + __byte_hash_recursive(&cp)
        ;

    return (hash<<1) + ((hash>>63)&1);
}

int64_t __array_var_size1_get_hash(void)
{
    if (!__array_var_size1_hash_computed) {
        __array_var_size1_hash = (int64_t)__array_var_size1_hash_recursive(NULL);
        __array_var_size1_hash_computed = 1;
    }

    return __array_var_size1_hash;
}

int __array_var_size1_encode_array(void *buf, int offset, int maxlen, const array_var_size1 *p, int elements)
{
    int pos = 0, element;
    int thislen;

    for (element = 0; element < elements; element++) {

        thislen = __int8_t_encode_array(buf, offset + pos, maxlen - pos, &(p[element].k1), 1);
        if (thislen < 0) return thislen; else pos += thislen;

        thislen = __int16_t_encode_array(buf, offset + pos, maxlen - pos, &(p[element].k2), 1);
        if (thislen < 0) return thislen; else pos += thislen;

        thislen = __int32_t_encode_array(buf, offset + pos, maxlen - pos, &(p[element].k3), 1);
        if (thislen < 0) return thislen; else pos += thislen;

        thislen = __int64_t_encode_array(buf, offset + pos, maxlen - pos, &(p[element].k4), 1);
        if (thislen < 0) return thislen; else pos += thislen;

        thislen = __int8_t_encode_array(buf, offset + pos, maxlen - pos, p[element].i8_1, p[element].k1);
        if (thislen < 0) return thislen; else pos += thislen;

        thislen = __int8_t_encode_array(buf, offset + pos, maxlen - pos, p[element].i8_2, p[element].k2);
        if (thislen < 0) return thislen; else pos += thislen;

        thislen = __int8_t_encode_array(buf, offset + pos, maxlen - pos, p[element].i8_3, p[element].k3);
        if (thislen < 0) return thislen; else pos += thislen;

        thislen = __int8_t_encode_array(buf, offset + pos, maxlen - pos, p[element].i8_4, p[element].k4);
        if (thislen < 0) return thislen; else pos += thislen;

        thislen = __int16_t_encode_array(buf, offset + pos, maxlen - pos, p[element].i16_1, p[element].k1);
        if (thislen < 0) return thislen; else pos += thislen;

        thislen = __int16_t_encode_array(buf, offset + pos, maxlen - pos, p[element].i16_2, p[element].k2);
        if (thislen < 0) return thislen; else pos += thislen;

        thislen = __int16_t_encode_array(buf, offset + pos, maxlen - pos, p[element].i16_3, p[element].k3);
        if (thislen < 0) return thislen; else pos += thislen;

        thislen = __int16_t_encode_array(buf, offset + pos, maxlen - pos, p[element].i16_4, p[element].k4);
        if (thislen < 0) return thislen; else pos += thislen;

        thislen = __int32_t_encode_array(buf, offset + pos, maxlen - pos, p[element].i32_1, p[element].k1);
        if (thislen < 0) return thislen; else pos += thislen;

        thislen = __int32_t_encode_array(buf, offset + pos, maxlen - pos, p[element].i32_2, p[element].k2);
        if (thislen < 0) return thislen; else pos += thislen;

        thislen = __int32_t_encode_array(buf, offset + pos, maxlen - pos, p[element].i32_3, p[element].k3);
        if (thislen < 0) return thislen; else pos += thislen;

        thislen = __int32_t_encode_array(buf, offset + pos, maxlen - pos, p[element].i32_4, p[element].k4);
        if (thislen < 0) return thislen; else pos += thislen;

        thislen = __int64_t_encode_array(buf, offset + pos, maxlen - pos, p[element].i64_1, p[element].k1);
        if (thislen < 0) return thislen; else pos += thislen;

        thislen = __int64_t_encode_array(buf, offset + pos, maxlen - pos, p[element].i64_2, p[element].k2);
        if (thislen < 0) return thislen; else pos += thislen;

        thislen = __int64_t_encode_array(buf, offset + pos, maxlen - pos, p[element].i64_3, p[element].k3);
        if (thislen < 0) return thislen; else pos += thislen;

        thislen = __int64_t_encode_array(buf, offset + pos, maxlen - pos, p[element].i64_4, p[element].k4);
        if (thislen < 0) return thislen; else pos += thislen;

        thislen = __float_encode_array(buf, offset + pos, maxlen - pos, p[element].f_1, p[element].k1);
        if (thislen < 0) return thislen; else pos += thislen;

        thislen = __float_encode_array(buf, offset + pos, maxlen - pos, p[element].f_2, p[element].k2);
        if (thislen < 0) return thislen; else pos += thislen;

        thislen = __float_encode_array(buf, offset + pos, maxlen - pos, p[element].f_3, p[element].k3);
        if (thislen < 0) return thislen; else pos += thislen;

        thislen = __float_encode_array(buf, offset + pos, maxlen - pos, p[element].f_4, p[element].k4);
        if (thislen < 0) return thislen; else pos += thislen;

        thislen = __double_encode_array(buf, offset + pos, maxlen - pos, p[element].d_1, p[element].k1);
        if (thislen < 0) return thislen; else pos += thislen;

        thislen = __double_encode_array(buf, offset + pos, maxlen - pos, p[element].d_2, p[element].k2);
        if (thislen < 0) return thislen; else pos += thislen;

        thislen = __double_encode_array(buf, offset + pos, maxlen - pos, p[element].d_3, p[element].k3);
        if (thislen < 0) return thislen; else pos += thislen;

        thislen = __double_encode_array(buf, offset + pos, maxlen - pos, p[element].d_4, p[element].k4);
        if (thislen < 0) return thislen; else pos += thislen;

        thislen = __string_encode_array(buf, offset + pos, maxlen - pos, p[element].s_1, p[element].k1);
        if (thislen < 0) return thislen; else pos += thislen;

        thislen = __string_encode_array(buf, offset + pos, maxlen - pos, p[element].s_2, p[element].k2);
        if (thislen < 0) return thislen; else pos += thislen;

        thislen = __string_encode_array(buf, offset + pos, maxlen - pos, p[element].s_3, p[element].k3);
        if (thislen < 0) return thislen; else pos += thislen;

        thislen = __string_encode_array(buf, offset + pos, maxlen - pos, p[element].s_4, p[element].k4);
        if (thislen < 0) return thislen; else pos += thislen;

        thislen = __boolean_encode_array(buf, offset + pos, maxlen - pos, p[element].bl_1, p[element].k1);
        if (thislen < 0) return thislen; else pos += thislen;

        thislen = __boolean_encode_array(buf, offset + pos, maxlen - pos, p[element].bl_2, p[element].k2);
        if (thislen < 0) return thislen; else pos += thislen;

        thislen = __boolean_encode_array(buf, offset + pos, maxlen - pos, p[element].bl_3, p[element].k3);
        if (thislen < 0) return thislen; else pos += thislen;

        thislen = __boolean_encode_array(buf, offset + pos, maxlen - pos, p[element].bl_4, p[element].k4);
        if (thislen < 0) return thislen; else pos += thislen;

        thislen = __byte_encode_array(buf, offset + pos, maxlen - pos, p[element].b_1, p[element].k1);
        if (thislen < 0) return thislen; else pos += thislen;

        thislen = __byte_encode_array(buf, offset + pos, maxlen - pos, p[element].b_2, p[element].k2);
        if (thislen < 0) return thislen; else pos += thislen;

        thislen = __byte_encode_array(buf, offset + pos, maxlen - pos, p[element].b_3, p[element].k3);
        if (thislen < 0) return thislen; else pos += thislen;

        thislen = __byte_encode_array(buf, offset + pos, maxlen - pos, p[element].b_4, p[element].k4);
        if (thislen < 0) return thislen; else pos += thislen;

    }
    return pos;
}

int array_var_size1_encode(void *buf, int offset, int maxlen, const array_var_size1 *p)
{
    int pos = 0, thislen;
    int64_t hash = __array_var_size1_get_hash();

    thislen = __int64_t_encode_array(buf, offset + pos, maxlen - pos, &hash, 1);
    if (thislen < 0) return thislen; else pos += thislen;

    thislen = __array_var_size1_encode_array(buf, offset + pos, maxlen - pos, p, 1);
    if (thislen < 0) return thislen; else pos += thislen;

    return pos;
}

int __array_var_size1_encoded_array_size(const array_var_size1 *p, int elements)
{
    int size = 0, element;
    for (element = 0; element < elements; element++) {

        size += __int8_t_encoded_array_size(&(p[element].k1), 1);

        size += __int16_t_encoded_array_size(&(p[element].k2), 1);

        size += __int32_t_encoded_array_size(&(p[element].k3), 1);

        size += __int64_t_encoded_array_size(&(p[element].k4), 1);

        size += __int8_t_encoded_array_size(p[element].i8_1, p[element].k1);

        size += __int8_t_encoded_array_size(p[element].i8_2, p[element].k2);

        size += __int8_t_encoded_array_size(p[element].i8_3, p[element].k3);

        size += __int8_t_encoded_array_size(p[element].i8_4, p[element].k4);

        size += __int16_t_encoded_array_size(p[element].i16_1, p[element].k1);

        size += __int16_t_encoded_array_size(p[element].i16_2, p[element].k2);

        size += __int16_t_encoded_array_size(p[element].i16_3, p[element].k3);

        size += __int16_t_encoded_array_size(p[element].i16_4, p[element].k4);

        size += __int32_t_encoded_array_size(p[element].i32_1, p[element].k1);

        size += __int32_t_encoded_array_size(p[element].i32_2, p[element].k2);

        size += __int32_t_encoded_array_size(p[element].i32_3, p[element].k3);

        size += __int32_t_encoded_array_size(p[element].i32_4, p[element].k4);

        size += __int64_t_encoded_array_size(p[element].i64_1, p[element].k1);

        size += __int64_t_encoded_array_size(p[element].i64_2, p[element].k2);

        size += __int64_t_encoded_array_size(p[element].i64_3, p[element].k3);

        size += __int64_t_encoded_array_size(p[element].i64_4, p[element].k4);

        size += __float_encoded_array_size(p[element].f_1, p[element].k1);

        size += __float_encoded_array_size(p[element].f_2, p[element].k2);

        size += __float_encoded_array_size(p[element].f_3, p[element].k3);

        size += __float_encoded_array_size(p[element].f_4, p[element].k4);

        size += __double_encoded_array_size(p[element].d_1, p[element].k1);

        size += __double_encoded_array_size(p[element].d_2, p[element].k2);

        size += __double_encoded_array_size(p[element].d_3, p[element].k3);

        size += __double_encoded_array_size(p[element].d_4, p[element].k4);

        size += __string_encoded_array_size(p[element].s_1, p[element].k1);

        size += __string_encoded_array_size(p[element].s_2, p[element].k2);

        size += __string_encoded_array_size(p[element].s_3, p[element].k3);

        size += __string_encoded_array_size(p[element].s_4, p[element].k4);

        size += __boolean_encoded_array_size(p[element].bl_1, p[element].k1);

        size += __boolean_encoded_array_size(p[element].bl_2, p[element].k2);

        size += __boolean_encoded_array_size(p[element].bl_3, p[element].k3);

        size += __boolean_encoded_array_size(p[element].bl_4, p[element].k4);

        size += __byte_encoded_array_size(p[element].b_1, p[element].k1);

        size += __byte_encoded_array_size(p[element].b_2, p[element].k2);

        size += __byte_encoded_array_size(p[element].b_3, p[element].k3);

        size += __byte_encoded_array_size(p[element].b_4, p[element].k4);

    }
    return size;
}

int array_var_size1_encoded_size(const array_var_size1 *p)
{
    return 8 + __array_var_size1_encoded_array_size(p, 1);
}

int __array_var_size1_decode_array(const void *buf, int offset, int maxlen, array_var_size1 *p, int elements)
{
    int pos = 0, thislen, element;

    for (element = 0; element < elements; element++) {

        thislen = __int8_t_decode_array(buf, offset + pos, maxlen - pos, &(p[element].k1), 1);
        if (thislen < 0) return thislen; else pos += thislen;

        thislen = __int16_t_decode_array(buf, offset + pos, maxlen - pos, &(p[element].k2), 1);
        if (thislen < 0) return thislen; else pos += thislen;

        thislen = __int32_t_decode_array(buf, offset + pos, maxlen - pos, &(p[element].k3), 1);
        if (thislen < 0) return thislen; else pos += thislen;

        thislen = __int64_t_decode_array(buf, offset + pos, maxlen - pos, &(p[element].k4), 1);
        if (thislen < 0) return thislen; else pos += thislen;

        p[element].i8_1 = (int8_t*) zcm_malloc(sizeof(int8_t) * p[element].k1);
        thislen = __int8_t_decode_array(buf, offset + pos, maxlen - pos, p[element].i8_1, p[element].k1);
        if (thislen < 0) return thislen; else pos += thislen;

        p[element].i8_2 = (int8_t*) zcm_malloc(sizeof(int8_t) * p[element].k2);
        thislen = __int8_t_decode_array(buf, offset + pos, maxlen - pos, p[element].i8_2, p[element].k2);
        if (thislen < 0) return thislen; else pos += thislen;

        p[element].i8_3 = (int8_t*) zcm_malloc(sizeof(int8_t) * p[element].k3);
        thislen = __int8_t_decode_array(buf, offset + pos, maxlen - pos, p[element].i8_3, p[element].k3);
        if (thislen < 0) return thislen; else pos += thislen;

        p[element].i8_4 = (int8_t*) zcm_malloc(sizeof(int8_t) * p[element].k4);
        thislen = __int8_t_decode_array(buf, offset + pos, maxlen - pos, p[element].i8_4, p[element].k4);
        if (thislen < 0) return thislen; else pos += thislen;

        p[element].i16_1 = (int16_t*) zcm_malloc(sizeof(int16_t) * p[element].k1);
        thislen = __int16_t_decode_array(buf, offset + pos, maxlen - pos, p[element].i16_1, p[element].k1);
        if (thislen < 0) return thislen; else pos += thislen;

        p[element].i16_2 = (int16_t*) zcm_malloc(sizeof(int16_t) * p[element].k2);
        thislen = __int16_t_decode_array(buf, offset + pos, maxlen - pos, p[element].i16_2, p[element].k2);
        if (thislen < 0) return thislen; else pos += thislen;

        p[element].i16_3 = (int16_t*) zcm_malloc(sizeof(int16_t) * p[element].k3);
        thislen = __int16_t_decode_array(buf, offset + pos, maxlen - pos, p[element].i16_3, p[element].k3);
        if (thislen < 0) return thislen; else pos += thislen;

        p[element].i16_4 = (int16_t*) zcm_malloc(sizeof(int16_t) * p[element].k4);
        thislen = __int16_t_decode_array(buf, offset + pos, maxlen - pos, p[element].i16_4, p[element].k4);
        if (thislen < 0) return thislen; else pos += thislen;

        p[element].i32_1 = (int32_t*) zcm_malloc(sizeof(int32_t) * p[element].k1);
        thislen = __int32_t_decode_array(buf, offset + pos, maxlen - pos, p[element].i32_1, p[element].k1);
        if (thislen < 0) return thislen; else pos += thislen;

        p[element].i32_2 = (int32_t*) zcm_malloc(sizeof(int32_t) * p[element].k2);
        thislen = __int32_t_decode_array(buf, offset + pos, maxlen - pos, p[element].i32_2, p[element].k2);
        if (thislen < 0) return thislen; else pos += thislen;

        p[element].i32_3 = (int32_t*) zcm_malloc(sizeof(int32_t) * p[element].k3);
        thislen = __int32_t_decode_array(buf, offset + pos, maxlen - pos, p[element].i32_3, p[element].k3);
        if (thislen < 0) return thislen; else pos += thislen;

        p[element].i32_4 = (int32_t*) zcm_malloc(sizeof(int32_t) * p[element].k4);
        thislen = __int32_t_decode_array(buf, offset + pos, maxlen - pos, p[element].i32_4, p[element].k4);
        if (thislen < 0) return thislen; else pos += thislen;

        p[element].i64_1 = (int64_t*) zcm_malloc(sizeof(int64_t) * p[element].k1);
        thislen = __int64_t_decode_array(buf, offset + pos, maxlen - pos, p[element].i64_1, p[element].k1);
        if (thislen < 0) return thislen; else pos += thislen;

        p[element].i64_2 = (int64_t*) zcm_malloc(sizeof(int64_t) * p[element].k2);
        thislen = __int64_t_decode_array(buf, offset + pos, maxlen - pos, p[element].i64_2, p[element].k2);
        if (thislen < 0) return thislen; else pos += thislen;

        p[element].i64_3 = (int64_t*) zcm_malloc(sizeof(int64_t) * p[element].k3);
        thislen = __int64_t_decode_array(buf, offset + pos, maxlen - pos, p[element].i64_3, p[element].k3);
        if (thislen < 0) return thislen; else pos += thislen;

        p[element].i64_4 = (int64_t*) zcm_malloc(sizeof(int64_t) * p[element].k4);
        thislen = __int64_t_decode_array(buf, offset + pos, maxlen - pos, p[element].i64_4, p[element].k4);
        if (thislen < 0) return thislen; else pos += thislen;

        p[element].f_1 = (float*) zcm_malloc(sizeof(float) * p[element].k1);
        thislen = __float_decode_array(buf, offset + pos, maxlen - pos, p[element].f_1, p[element].k1);
        if (thislen < 0) return thislen; else pos += thislen;

        p[element].f_2 = (float*) zcm_malloc(sizeof(float) * p[element].k2);
        thislen = __float_decode_array(buf, offset + pos, maxlen - pos, p[element].f_2, p[element].k2);
        if (thislen < 0) return thislen; else pos += thislen;

        p[element].f_3 = (float*) zcm_malloc(sizeof(float) * p[element].k3);
        thislen = __float_decode_array(buf, offset + pos, maxlen - pos, p[element].f_3, p[element].k3);
        if (thislen < 0) return thislen; else pos += thislen;

        p[element].f_4 = (float*) zcm_malloc(sizeof(float) * p[element].k4);
        thislen = __float_decode_array(buf, offset + pos, maxlen - pos, p[element].f_4, p[element].k4);
        if (thislen < 0) return thislen; else pos += thislen;

        p[element].d_1 = (double*) zcm_malloc(sizeof(double) * p[element].k1);
        thislen = __double_decode_array(buf, offset + pos, maxlen - pos, p[element].d_1, p[element].k1);
        if (thislen < 0) return thislen; else pos += thislen;

        p[element].d_2 = (double*) zcm_malloc(sizeof(double) * p[element].k2);
        thislen = __double_decode_array(buf, offset + pos, maxlen - pos, p[element].d_2, p[element].k2);
        if (thislen < 0) return thislen; else pos += thislen;

        p[element].d_3 = (double*) zcm_malloc(sizeof(double) * p[element].k3);
        thislen = __double_decode_array(buf, offset + pos, maxlen - pos, p[element].d_3, p[element].k3);
        if (thislen < 0) return thislen; else pos += thislen;

        p[element].d_4 = (double*) zcm_malloc(sizeof(double) * p[element].k4);
        thislen = __double_decode_array(buf, offset + pos, maxlen - pos, p[element].d_4, p[element].k4);
        if (thislen < 0) return thislen; else pos += thislen;

        p[element].s_1 = (char**) zcm_malloc(sizeof(char*) * p[element].k1);
        thislen = __string_decode_array(buf, offset + pos, maxlen - pos, p[element].s_1, p[element].k1);
        if (thislen < 0) return thislen; else pos += thislen;

        p[element].s_2 = (char**) zcm_malloc(sizeof(char*) * p[element].k2);
        thislen = __string_decode_array(buf, offset + pos, maxlen - pos, p[element].s_2, p[element].k2);
        if (thislen < 0) return thislen; else pos += thislen;

        p[element].s_3 = (char**) zcm_malloc(sizeof(char*) * p[element].k3);
        thislen = __string_decode_array(buf, offset + pos, maxlen - pos, p[element].s_3, p[element].k3);
        if (thislen < 0) return thislen; else pos += thislen;

        p[element].s_4 = (char**) zcm_malloc(sizeof(char*) * p[element].k4);
        thislen = __string_decode_array(buf, offset + pos, maxlen - pos, p[element].s_4, p[element].k4);
        if (thislen < 0) return thislen; else pos += thislen;

        p[element].bl_1 = (int8_t*) zcm_malloc(sizeof(int8_t) * p[element].k1);
        thislen = __boolean_decode_array(buf, offset + pos, maxlen - pos, p[element].bl_1, p[element].k1);
        if (thislen < 0) return thislen; else pos += thislen;

        p[element].bl_2 = (int8_t*) zcm_malloc(sizeof(int8_t) * p[element].k2);
        thislen = __boolean_decode_array(buf, offset + pos, maxlen - pos, p[element].bl_2, p[element].k2);
        if (thislen < 0) return thislen; else pos += thislen;

        p[element].bl_3 = (int8_t*) zcm_malloc(sizeof(int8_t) * p[element].k3);
        thislen = __boolean_decode_array(buf, offset + pos, maxlen - pos, p[element].bl_3, p[element].k3);
        if (thislen < 0) return thislen; else pos += thislen;

        p[element].bl_4 = (int8_t*) zcm_malloc(sizeof(int8_t) * p[element].k4);
        thislen = __boolean_decode_array(buf, offset + pos, maxlen - pos, p[element].bl_4, p[element].k4);
        if (thislen < 0) return thislen; else pos += thislen;

        p[element].b_1 = (uint8_t*) zcm_malloc(sizeof(uint8_t) * p[element].k1);
        thislen = __byte_decode_array(buf, offset + pos, maxlen - pos, p[element].b_1, p[element].k1);
        if (thislen < 0) return thislen; else pos += thislen;

        p[element].b_2 = (uint8_t*) zcm_malloc(sizeof(uint8_t) * p[element].k2);
        thislen = __byte_decode_array(buf, offset + pos, maxlen - pos, p[element].b_2, p[element].k2);
        if (thislen < 0) return thislen; else pos += thislen;

        p[element].b_3 = (uint8_t*) zcm_malloc(sizeof(uint8_t) * p[element].k3);
        thislen = __byte_decode_array(buf, offset + pos, maxlen - pos, p[element].b_3, p[element].k3);
        if (thislen < 0) return thislen; else pos += thislen;

        p[element].b_4 = (uint8_t*) zcm_malloc(sizeof(uint8_t) * p[element].k4);
        thislen = __byte_decode_array(buf, offset + pos, maxlen - pos, p[element].b_4, p[element].k4);
        if (thislen < 0) return thislen; else pos += thislen;

    }
    return pos;
}

int __array_var_size1_decode_array_cleanup(array_var_size1 *p, int elements)
{
    int element;
    for (element = 0; element < elements; element++) {

        __int8_t_decode_array_cleanup(&(p[element].k1), 1);

        __int16_t_decode_array_cleanup(&(p[element].k2), 1);

        __int32_t_decode_array_cleanup(&(p[element].k3), 1);

        __int64_t_decode_array_cleanup(&(p[element].k4), 1);

        __int8_t_decode_array_cleanup(p[element].i8_1, p[element].k1);
        if (p[element].i8_1) free(p[element].i8_1);

        __int8_t_decode_array_cleanup(p[element].i8_2, p[element].k2);
        if (p[element].i8_2) free(p[element].i8_2);

        __int8_t_decode_array_cleanup(p[element].i8_3, p[element].k3);
        if (p[element].i8_3) free(p[element].i8_3);

        __int8_t_decode_array_cleanup(p[element].i8_4, p[element].k4);
        if (p[element].i8_4) free(p[element].i8_4);

        __int16_t_decode_array_cleanup(p[element].i16_1, p[element].k1);
        if (p[element].i16_1) free(p[element].i16_1);

        __int16_t_decode_array_cleanup(p[element].i16_2, p[element].k2);
        if (p[element].i16_2) free(p[element].i16_2);

        __int16_t_decode_array_cleanup(p[element].i16_3, p[element].k3);
        if (p[element].i16_3) free(p[element].i16_3);

        __int16_t_decode_array_cleanup(p[element].i16_4, p[element].k4);
        if (p[element].i16_4) free(p[element].i16_4);

        __int32_t_decode_array_cleanup(p[element].i32_1, p[element].k1);
        if (p[element].i32_1) free(p[element].i32_1);

        __int32_t_decode_array_cleanup(p[element].i32_2, p[element].k2);
        if (p[element].i32_2) free(p[element].i32_2);

        __int32_t_decode_array_cleanup(p[element].i32_3, p[element].k3);
        if (p[element].i32_3) free(p[element].i32_3);

        __int32_t_decode_array_cleanup(p[element].i32_4, p[element].k4);
        if (p[element].i32_4) free(p[element].i32_4);

        __int64_t_decode_array_cleanup(p[element].i64_1, p[element].k1);
        if (p[element].i64_1) free(p[element].i64_1);

        __int64_t_decode_array_cleanup(p[element].i64_2, p[element].k2);
        if (p[element].i64_2) free(p[element].i64_2);

        __int64_t_decode_array_cleanup(p[element].i64_3, p[element].k3);
        if (p[element].i64_3) free(p[element].i64_3);

        __int64_t_decode_array_cleanup(p[element].i64_4, p[element].k4);
        if (p[element].i64_4) free(p[element].i64_4);

        __float_decode_array_cleanup(p[element].f_1, p[element].k1);
        if (p[element].f_1) free(p[element].f_1);

        __float_decode_array_cleanup(p[element].f_2, p[element].k2);
        if (p[element].f_2) free(p[element].f_2);

        __float_decode_array_cleanup(p[element].f_3, p[element].k3);
        if (p[element].f_3) free(p[element].f_3);

        __float_decode_array_cleanup(p[element].f_4, p[element].k4);
        if (p[element].f_4) free(p[element].f_4);

        __double_decode_array_cleanup(p[element].d_1, p[element].k1);
        if (p[element].d_1) free(p[element].d_1);

        __double_decode_array_cleanup(p[element].d_2, p[element].k2);
        if (p[element].d_2) free(p[element].d_2);

        __double_decode_array_cleanup(p[element].d_3, p[element].k3);
        if (p[element].d_3) free(p[element].d_3);

        __double_decode_array_cleanup(p[element].d_4, p[element].k4);
        if (p[element].d_4) free(p[element].d_4);

        __string_decode_array_cleanup(p[element].s_1, p[element].k1);
        if (p[element].s_1) free(p[element].s_1);

        __string_decode_array_cleanup(p[element].s_2, p[element].k2);
        if (p[element].s_2) free(p[element].s_2);

        __string_decode_array_cleanup(p[element].s_3, p[element].k3);
        if (p[element].s_3) free(p[element].s_3);

        __string_decode_array_cleanup(p[element].s_4, p[element].k4);
        if (p[element].s_4) free(p[element].s_4);

        __boolean_decode_array_cleanup(p[element].bl_1, p[element].k1);
        if (p[element].bl_1) free(p[element].bl_1);

        __boolean_decode_array_cleanup(p[element].bl_2, p[element].k2);
        if (p[element].bl_2) free(p[element].bl_2);

        __boolean_decode_array_cleanup(p[element].bl_3, p[element].k3);
        if (p[element].bl_3) free(p[element].bl_3);

        __boolean_decode_array_cleanup(p[element].bl_4, p[element].k4);
        if (p[element].bl_4) free(p[element].bl_4);

        __byte_decode_array_cleanup(p[element].b_1, p[element].k1);
        if (p[element].b_1) free(p[element].b_1);

        __byte_decode_array_cleanup(p[element].b_2, p[element].k2);
        if (p[element].b_2) free(p[element].b_2);

        __byte_decode_array_cleanup(p[element].b_3, p[element].k3);
        if (p[element].b_3) free(p[element].b_3);

        __byte_decode_array_cleanup(p[element].b_4, p[element].k4);
        if (p[element].b_4) free(p[element].b_4);

    }
    return 0;
}

int array_var_size1_decode(const void *buf, int offset, int maxlen, array_var_size1 *p)
{
    int pos = 0, thislen;
    int64_t hash = __array_var_size1_get_hash();

    int64_t this_hash;
    thislen = __int64_t_decode_array(buf, offset + pos, maxlen - pos, &this_hash, 1);
    if (thislen < 0) return thislen; else pos += thislen;
    if (this_hash != hash) return -1;

    thislen = __array_var_size1_decode_array(buf, offset + pos, maxlen - pos, p, 1);
    if (thislen < 0) return thislen; else pos += thislen;

    return pos;
}

int array_var_size1_decode_cleanup(array_var_size1 *p)
{
    return __array_var_size1_decode_array_cleanup(p, 1);
}

int __array_var_size1_clone_array(const array_var_size1 *p, array_var_size1 *q, int elements)
{
    int element;
    for (element = 0; element < elements; element++) {

        __int8_t_clone_array(&(p[element].k1), &(q[element].k1), 1);

        __int16_t_clone_array(&(p[element].k2), &(q[element].k2), 1);

        __int32_t_clone_array(&(p[element].k3), &(q[element].k3), 1);

        __int64_t_clone_array(&(p[element].k4), &(q[element].k4), 1);

        q[element].i8_1 = (int8_t*) zcm_malloc(sizeof(int8_t) * q[element].k1);
        __int8_t_clone_array(p[element].i8_1, q[element].i8_1, p[element].k1);

        q[element].i8_2 = (int8_t*) zcm_malloc(sizeof(int8_t) * q[element].k2);
        __int8_t_clone_array(p[element].i8_2, q[element].i8_2, p[element].k2);

        q[element].i8_3 = (int8_t*) zcm_malloc(sizeof(int8_t) * q[element].k3);
        __int8_t_clone_array(p[element].i8_3, q[element].i8_3, p[element].k3);

        q[element].i8_4 = (int8_t*) zcm_malloc(sizeof(int8_t) * q[element].k4);
        __int8_t_clone_array(p[element].i8_4, q[element].i8_4, p[element].k4);

        q[element].i16_1 = (int16_t*) zcm_malloc(sizeof(int16_t) * q[element].k1);
        __int16_t_clone_array(p[element].i16_1, q[element].i16_1, p[element].k1);

        q[element].i16_2 = (int16_t*) zcm_malloc(sizeof(int16_t) * q[element].k2);
        __int16_t_clone_array(p[element].i16_2, q[element].i16_2, p[element].k2);

        q[element].i16_3 = (int16_t*) zcm_malloc(sizeof(int16_t) * q[element].k3);
        __int16_t_clone_array(p[element].i16_3, q[element].i16_3, p[element].k3);

        q[element].i16_4 = (int16_t*) zcm_malloc(sizeof(int16_t) * q[element].k4);
        __int16_t_clone_array(p[element].i16_4, q[element].i16_4, p[element].k4);

        q[element].i32_1 = (int32_t*) zcm_malloc(sizeof(int32_t) * q[element].k1);
        __int32_t_clone_array(p[element].i32_1, q[element].i32_1, p[element].k1);

        q[element].i32_2 = (int32_t*) zcm_malloc(sizeof(int32_t) * q[element].k2);
        __int32_t_clone_array(p[element].i32_2, q[element].i32_2, p[element].k2);

        q[element].i32_3 = (int32_t*) zcm_malloc(sizeof(int32_t) * q[element].k3);
        __int32_t_clone_array(p[element].i32_3, q[element].i32_3, p[element].k3);

        q[element].i32_4 = (int32_t*) zcm_malloc(sizeof(int32_t) * q[element].k4);
        __int32_t_clone_array(p[element].i32_4, q[element].i32_4, p[element].k4);

        q[element].i64_1 = (int64_t*) zcm_malloc(sizeof(int64_t) * q[element].k1);
        __int64_t_clone_array(p[element].i64_1, q[element].i64_1, p[element].k1);

        q[element].i64_2 = (int64_t*) zcm_malloc(sizeof(int64_t) * q[element].k2);
        __int64_t_clone_array(p[element].i64_2, q[element].i64_2, p[element].k2);

        q[element].i64_3 = (int64_t*) zcm_malloc(sizeof(int64_t) * q[element].k3);
        __int64_t_clone_array(p[element].i64_3, q[element].i64_3, p[element].k3);

        q[element].i64_4 = (int64_t*) zcm_malloc(sizeof(int64_t) * q[element].k4);
        __int64_t_clone_array(p[element].i64_4, q[element].i64_4, p[element].k4);

        q[element].f_1 = (float*) zcm_malloc(sizeof(float) * q[element].k1);
        __float_clone_array(p[element].f_1, q[element].f_1, p[element].k1);

        q[element].f_2 = (float*) zcm_malloc(sizeof(float) * q[element].k2);
        __float_clone_array(p[element].f_2, q[element].f_2, p[element].k2);

        q[element].f_3 = (float*) zcm_malloc(sizeof(float) * q[element].k3);
        __float_clone_array(p[element].f_3, q[element].f_3, p[element].k3);

        q[element].f_4 = (float*) zcm_malloc(sizeof(float) * q[element].k4);
        __float_clone_array(p[element].f_4, q[element].f_4, p[element].k4);

        q[element].d_1 = (double*) zcm_malloc(sizeof(double) * q[element].k1);
        __double_clone_array(p[element].d_1, q[element].d_1, p[element].k1);

        q[element].d_2 = (double*) zcm_malloc(sizeof(double) * q[element].k2);
        __double_clone_array(p[element].d_2, q[element].d_2, p[element].k2);

        q[element].d_3 = (double*) zcm_malloc(sizeof(double) * q[element].k3);
        __double_clone_array(p[element].d_3, q[element].d_3, p[element].k3);

        q[element].d_4 = (double*) zcm_malloc(sizeof(double) * q[element].k4);
        __double_clone_array(p[element].d_4, q[element].d_4, p[element].k4);

        q[element].s_1 = (char**) zcm_malloc(sizeof(char*) * q[element].k1);
        __string_clone_array(p[element].s_1, q[element].s_1, p[element].k1);

        q[element].s_2 = (char**) zcm_malloc(sizeof(char*) * q[element].k2);
        __string_clone_array(p[element].s_2, q[element].s_2, p[element].k2);

        q[element].s_3 = (char**) zcm_malloc(sizeof(char*) * q[element].k3);
        __string_clone_array(p[element].s_3, q[element].s_3, p[element].k3);

        q[element].s_4 = (char**) zcm_malloc(sizeof(char*) * q[element].k4);
        __string_clone_array(p[element].s_4, q[element].s_4, p[element].k4);

        q[element].bl_1 = (int8_t*) zcm_malloc(sizeof(int8_t) * q[element].k1);
        __boolean_clone_array(p[element].bl_1, q[element].bl_1, p[element].k1);

        q[element].bl_2 = (int8_t*) zcm_malloc(sizeof(int8_t) * q[element].k2);
        __boolean_clone_array(p[element].bl_2, q[element].bl_2, p[element].k2);

        q[element].bl_3 = (int8_t*) zcm_malloc(sizeof(int8_t) * q[element].k3);
        __boolean_clone_array(p[element].bl_3, q[element].bl_3, p[element].k3);

        q[element].bl_4 = (int8_t*) zcm_malloc(sizeof(int8_t) * q[element].k4);
        __boolean_clone_array(p[element].bl_4, q[element].bl_4, p[element].k4);

        q[element].b_1 = (uint8_t*) zcm_malloc(sizeof(uint8_t) * q[element].k1);
        __byte_clone_array(p[element].b_1, q[element].b_1, p[element].k1);

        q[element].b_2 = (uint8_t*) zcm_malloc(sizeof(uint8_t) * q[element].k2);
        __byte_clone_array(p[element].b_2, q[element].b_2, p[element].k2);

        q[element].b_3 = (uint8_t*) zcm_malloc(sizeof(uint8_t) * q[element].k3);
        __byte_clone_array(p[element].b_3, q[element].b_3, p[element].k3);

        q[element].b_4 = (uint8_t*) zcm_malloc(sizeof(uint8_t) * q[element].k4);
        __byte_clone_array(p[element].b_4, q[element].b_4, p[element].k4);

    }
    return 0;
}

array_var_size1 *array_var_size1_copy(const array_var_size1 *p)
{
    array_var_size1 *q = (array_var_size1*) malloc(sizeof(array_var_size1));
    __array_var_size1_clone_array(p, q, 1);
    return q;
}

void array_var_size1_destroy(array_var_size1 *p)
{
    __array_var_size1_decode_array_cleanup(p, 1);
    free(p);
}

int array_var_size1_publish(zcm_t *lc, const char *channel, const array_var_size1 *p)
{
      int max_data_size = array_var_size1_encoded_size (p);
      uint8_t *buf = (uint8_t*) malloc (max_data_size);
      if (!buf) return -1;
      int data_size = array_var_size1_encode (buf, 0, max_data_size, p);
      if (data_size < 0) {
          free (buf);
          return data_size;
      }
      int status = zcm_publish (lc, channel, (char *)buf, (size_t)data_size);
      free (buf);
      return status;
}

struct _array_var_size1_subscription_t {
    array_var_size1_handler_t user_handler;
    void *userdata;
    zcm_sub_t *z_sub;
};
static
void array_var_size1_handler_stub (const zcm_recv_buf_t *rbuf,
                            const char *channel, void *userdata)
{
    int status;
    array_var_size1 p;
    memset(&p, 0, sizeof(array_var_size1));
    status = array_var_size1_decode (rbuf->data, 0, rbuf->data_size, &p);
    if (status < 0) {
        fprintf (stderr, "error %d decoding array_var_size1!!!\n", status);
        return;
    }

    array_var_size1_subscription_t *h = (array_var_size1_subscription_t*) userdata;
    h->user_handler (rbuf, channel, &p, h->userdata);

    array_var_size1_decode_cleanup (&p);
}

array_var_size1_subscription_t* array_var_size1_subscribe (zcm_t *zcm,
                    const char *channel,
                    array_var_size1_handler_t f, void *userdata)
{
    array_var_size1_subscription_t *n = (array_var_size1_subscription_t*)
                       malloc(sizeof(array_var_size1_subscription_t));
    n->user_handler = f;
    n->userdata = userdata;
    n->z_sub = zcm_subscribe (zcm, channel,
                              array_var_size1_handler_stub, n);
    if (n->z_sub == NULL) {
        fprintf (stderr,"couldn't reg array_var_size1 ZCM handler!\n");
        free (n);
        return NULL;
    }
    return n;
}

int array_var_size1_unsubscribe(zcm_t *zcm, array_var_size1_subscription_t* hid)
{
    int status = zcm_unsubscribe (zcm, hid->z_sub);
    if (0 != status) {
        fprintf(stderr,
           "couldn't unsubscribe array_var_size1_handler %p!\n", hid);
        return -1;
    }
    free (hid);
    return 0;
}

