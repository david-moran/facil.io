#ifndef FIOBJ_ARRAY_H
/*
Copyright: Boaz segev, 2017
License: MIT

Feel free to copy, use and enjoy according to the license provided.
*/

/**
A dynamic Array type for the fiobj_s dynamic type system.
*/
#define FIOBJ_ARRAY_H

#include "fiobject.h"

#ifdef __cplusplus
extern "C" {
#endif

/** The Array type indentifier. */
extern const uintptr_t FIOBJ_T_ARRAY;

/* *****************************************************************************
Array direct entry access API
***************************************************************************** */

/** Creates a mutable empty Array object. Use `fiobj_free` when done. */
fiobj_s *fiobj_ary_new(void);

/** Creates a mutable empty Array object with the requested capacity. */
fiobj_s *fiobj_ary_new2(size_t capa);

/** Returns the number of elements in the Array. */
size_t fiobj_ary_count(fiobj_s *ary);

/** Returns the current, temporary, array capacity (it's dynamic). */
size_t fiobj_ary_capa(fiobj_s *ary);

/* *****************************************************************************
Array direct entry access API
***************************************************************************** */

/**
 * Returns a temporary object owned by the Array.
 *
 * Wrap this function call within `fiobj_dup` to get a persistent handle. i.e.:
 *
 *     fiobj_dup(fiobj_ary_index(array, 0));
 *
 * Negative values are retrived from the end of the array. i.e., `-1`
 * is the last item.
 */
fiobj_s *fiobj_ary_index(fiobj_s *ary, int64_t pos);
/** alias for `fiobj_ary_index` */
#define fiobj_ary_entry(a, p) fiobj_ary_index((a), (p))

/**
 * Sets an object at the requested position.
 */
void fiobj_ary_set(fiobj_s *ary, fiobj_s *obj, int64_t pos);

/* *****************************************************************************
Array push / shift API
***************************************************************************** */

/**
 * Pushes an object to the end of the Array.
 */
void fiobj_ary_push(fiobj_s *ary, fiobj_s *obj);

/** Pops an object from the end of the Array. */
fiobj_s *fiobj_ary_pop(fiobj_s *ary);

/**
 * Unshifts an object to the begining of the Array. This could be
 * expensive.
 */
void fiobj_ary_unshift(fiobj_s *ary, fiobj_s *obj);

/** Shifts an object from the beginning of the Array. */
fiobj_s *fiobj_ary_shift(fiobj_s *ary);

/* *****************************************************************************
Array compacting (untested)
***************************************************************************** */

/**
 * Removes any NULL *pointers* from an Array, keeping all Objects (including
 * explicit NULL objects) in the array.
 *
 * This action is O(n) where n in the length of the array.
 * It could get expensive.
 */
void fiobj_ary_compact(fiobj_s *ary);

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif
