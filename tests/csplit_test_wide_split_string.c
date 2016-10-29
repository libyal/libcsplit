/*
 * Library wide_split_string type testing program
 *
 * Copyright (C) 2011-2016, Joachim Metz <joachim.metz@gmail.com>
 *
 * Refer to AUTHORS for acknowledgements.
 *
 * This software is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This software is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this software.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <common.h>
#include <file_stream.h>

#if defined( HAVE_STDLIB_H ) || defined( WINAPI )
#include <stdlib.h>
#endif

#include "csplit_test_libcerror.h"
#include "csplit_test_libcsplit.h"
#include "csplit_test_libcstring.h"
#include "csplit_test_macros.h"
#include "csplit_test_memory.h"
#include "csplit_test_unused.h"

#if defined( LIBCSPLIT_HAVE_WIDE_CHARACTER_TYPE )

#if defined( __GNUC__ )

extern \
int libcsplit_wide_split_string_initialize(
     libcsplit_wide_split_string_t **split_string,
     const char *string,
     size_t string_size,
     int number_of_segments,
     libcerror_error_t **error );

/* Tests the libcsplit_wide_split_string_initialize function
 * Returns 1 if successful or 0 if not
 */
int csplit_test_wide_split_string_initialize(
     void )
{
	libcsplit_wide_split_string_t *wide_split_string = NULL;
	libcerror_error_t *error                         = NULL;
	int result                                       = 0;

	/* Test libcsplit_wide_split_string_initialize
	 */
	result = libcsplit_wide_split_string_initialize(
	          &wide_split_string,
	          "Test",
	          4,
	          1,
	          &error );

	CSPLIT_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

        CSPLIT_TEST_ASSERT_IS_NOT_NULL(
         "wide_split_string",
         wide_split_string );

        CSPLIT_TEST_ASSERT_IS_NULL(
         "error",
         error );

	result = libcsplit_wide_split_string_free(
	          &wide_split_string,
	          &error );

	CSPLIT_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

        CSPLIT_TEST_ASSERT_IS_NULL(
         "wide_split_string",
         wide_split_string );

        CSPLIT_TEST_ASSERT_IS_NULL(
         "error",
         error );

	/* Test error cases
	 */
	result = libcsplit_wide_split_string_initialize(
	          NULL,
	          "Test",
	          4,
	          1,
	          &error );

	CSPLIT_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

        CSPLIT_TEST_ASSERT_IS_NOT_NULL(
         "error",
         error );

	libcerror_error_free(
	 &error );

	wide_split_string = (libcsplit_wide_split_string_t *) 0x12345678UL;

	result = libcsplit_wide_split_string_initialize(
	          &wide_split_string,
	          "Test",
	          4,
	          1,
	          &error );

	CSPLIT_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

        CSPLIT_TEST_ASSERT_IS_NOT_NULL(
         "error",
         error );

	libcerror_error_free(
	 &error );

	wide_split_string = NULL;

#if defined( HAVE_CSPLIT_TEST_MEMORY )

	/* Test libcsplit_wide_split_string_initialize with malloc failing
	 */
	csplit_test_malloc_attempts_before_fail = 0;

	result = libcsplit_wide_split_string_initialize(
	          &wide_split_string,
	          "Test",
	          4,
	          1,
	          &error );

	if( csplit_test_malloc_attempts_before_fail != -1 )
	{
		csplit_test_malloc_attempts_before_fail = -1;
	}
	else
	{
		CSPLIT_TEST_ASSERT_EQUAL_INT(
		 "result",
		 result,
		 -1 );

		CSPLIT_TEST_ASSERT_IS_NULL(
		 "wide_split_string",
		 wide_split_string );

		CSPLIT_TEST_ASSERT_IS_NOT_NULL(
		 "error",
		 error );

		libcerror_error_free(
		 &error );
	}
	/* Test libcsplit_wide_split_string_initialize with memset failing
	 */
	csplit_test_memset_attempts_before_fail = 0;

	result = libcsplit_wide_split_string_initialize(
	          &wide_split_string,
	          "Test",
	          4,
	          1,
	          &error );

	if( csplit_test_memset_attempts_before_fail != -1 )
	{
		csplit_test_memset_attempts_before_fail = -1;
	}
	else
	{
		CSPLIT_TEST_ASSERT_EQUAL_INT(
		 "result",
		 result,
		 -1 );

		CSPLIT_TEST_ASSERT_IS_NULL(
		 "wide_split_string",
		 wide_split_string );

		CSPLIT_TEST_ASSERT_IS_NOT_NULL(
		 "error",
		 error );

		libcerror_error_free(
		 &error );
	}
#endif /* defined( HAVE_CSPLIT_TEST_MEMORY ) */

	return( 1 );

on_error:
	if( error != NULL )
	{
		libcerror_error_free(
		 &error );
	}
	if( wide_split_string != NULL )
	{
		libcsplit_wide_split_string_free(
		 &wide_split_string,
		 NULL );
	}
	return( 0 );
}

#endif /* defined( __GNUC__ ) */

/* Tests the libcsplit_wide_split_string_free function
 * Returns 1 if successful or 0 if not
 */
int csplit_test_wide_split_string_free(
     void )
{
	libcerror_error_t *error = NULL;
	int result               = 0;

	/* Test error cases
	 */
	result = libcsplit_wide_split_string_free(
	          NULL,
	          &error );

	CSPLIT_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

        CSPLIT_TEST_ASSERT_IS_NOT_NULL(
         "error",
         error );

	libcerror_error_free(
	 &error );

	return( 1 );

on_error:
	if( error != NULL )
	{
		libcerror_error_free(
		 &error );
	}
	return( 0 );
}

/* Tests the libcsplit_wide_split_string_get_string function
 * Returns 1 if successful or 0 if not
 */
int csplit_test_wide_split_string_get_string(
     void )
{
	libcerror_error_t *error = NULL;
	wchar_t *string          = NULL;
	size_t string_size       = 0;
	int result               = 0;

	/* Test error cases
	 */
	result = libcsplit_wide_split_string_get_string(
	          NULL,
	          &string,
	          &string_size,
	          &error );

	CSPLIT_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

        CSPLIT_TEST_ASSERT_IS_NOT_NULL(
         "error",
         error );

	libcerror_error_free(
	 &error );

	return( 1 );

on_error:
	if( error != NULL )
	{
		libcerror_error_free(
		 &error );
	}
	return( 0 );
}

/* Tests the libcsplit_wide_split_string_get_number_of_segments function
 * Returns 1 if successful or 0 if not
 */
int csplit_test_wide_split_string_get_number_of_segments(
     void )
{
	libcerror_error_t *error = NULL;
	int number_of_segments   = 0;
	int result               = 0;

	/* Test error cases
	 */
	result = libcsplit_wide_split_string_get_number_of_segments(
	          NULL,
	          &number_of_segments,
	          &error );

	CSPLIT_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

        CSPLIT_TEST_ASSERT_IS_NOT_NULL(
         "error",
         error );

	libcerror_error_free(
	 &error );

	return( 1 );

on_error:
	if( error != NULL )
	{
		libcerror_error_free(
		 &error );
	}
	return( 0 );
}

/* Tests the libcsplit_wide_split_string_get_segment_by_index function
 * Returns 1 if successful or 0 if not
 */
int csplit_test_wide_split_string_get_segment_by_index(
     void )
{
	libcerror_error_t *error   = NULL;
	wchar_t *string_segment    = NULL;
	size_t string_segment_size = 0;
	int result                 = 0;

	/* Test error cases
	 */
	result = libcsplit_wide_split_string_get_segment_by_index(
	          NULL,
	          0,
	          &string_segment,
	          &string_segment_size,
	          &error );

	CSPLIT_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

        CSPLIT_TEST_ASSERT_IS_NOT_NULL(
         "error",
         error );

	libcerror_error_free(
	 &error );

	return( 1 );

on_error:
	if( error != NULL )
	{
		libcerror_error_free(
		 &error );
	}
	return( 0 );
}

#endif /* defined( LIBCSPLIT_HAVE_WIDE_CHARACTER_TYPE ) */

/* The main program
 */
#if defined( LIBCSTRING_HAVE_WIDE_SYSTEM_CHARACTER )
int wmain(
     int argc CSPLIT_TEST_ATTRIBUTE_UNUSED,
     wchar_t * const argv[] CSPLIT_TEST_ATTRIBUTE_UNUSED )
#else
int main(
     int argc CSPLIT_TEST_ATTRIBUTE_UNUSED,
     char * const argv[] CSPLIT_TEST_ATTRIBUTE_UNUSED )
#endif
{
	CSPLIT_TEST_UNREFERENCED_PARAMETER( argc )
	CSPLIT_TEST_UNREFERENCED_PARAMETER( argv )

#if defined( LIBCSPLIT_HAVE_WIDE_CHARACTER_TYPE )

#if defined( __GNUC__ )

	CSPLIT_TEST_RUN(
	 "libcsplit_wide_split_string_initialize",
	 csplit_test_wide_split_string_initialize );

#endif /* defined( __GNUC__ ) */

	CSPLIT_TEST_RUN(
	 "libcsplit_wide_split_string_free",
	 csplit_test_wide_split_string_free );

	CSPLIT_TEST_RUN(
	 "libcsplit_wide_split_string_get_string",
	 csplit_test_wide_split_string_get_string );

	CSPLIT_TEST_RUN(
	 "libcsplit_wide_split_string_get_number_of_segments",
	 csplit_test_wide_split_string_get_number_of_segments );

	CSPLIT_TEST_RUN(
	 "libcsplit_wide_split_string_get_segment_by_index",
	 csplit_test_wide_split_string_get_segment_by_index );

	/* TODO: add test for libcsplit_wide_split_string_set_segment_by_index */

#endif /* defined( LIBCSPLIT_HAVE_WIDE_CHARACTER_TYPE ) */

	return( EXIT_SUCCESS );

on_error:
	return( EXIT_FAILURE );
}

