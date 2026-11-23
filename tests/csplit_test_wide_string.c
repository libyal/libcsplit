/*
 * Library wide string functions test program
 *
 * Copyright (C) 2008-2026, Joachim Metz <joachim.metz@gmail.com>
 *
 * Refer to AUTHORS for acknowledgements.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

#include <common.h>
#include <file_stream.h>
#include <types.h>
#include <wide_string.h>

#if defined( HAVE_STDLIB_H ) || defined( WINAPI )
#include <stdlib.h>
#endif

#include "csplit_test_libcerror.h"
#include "csplit_test_libcsplit.h"
#include "csplit_test_macros.h"
#include "csplit_test_memory.h"
#include "csplit_test_unused.h"

#if defined( LIBCSPLIT_HAVE_WIDE_CHARACTER_TYPE )

/* Verifies the segments of a split string
 * Returns 1 if successful or 0 if not
 */
int csplit_test_wide_split_string_verify_segments(
     libcsplit_wide_split_string_t *split_string,
     const wchar_t * const expected_segments[],
     const size_t expected_segment_sizes[],
     int number_of_segments )
{
	libcerror_error_t *error    = NULL;
	wchar_t *string_segment     = NULL;
	size_t string_segment_size  = 0;
	size_t segment_index        = 0;
	int result                  = 0;
	int test_number_of_segments = 0;

	/* Retrieve the number of segments
	 */
	result = libcsplit_wide_split_string_get_number_of_segments(
	          split_string,
	          &test_number_of_segments,
	          &error );

	CSPLIT_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CSPLIT_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	CSPLIT_TEST_ASSERT_EQUAL_INT(
	 "test_number_of_segments",
	 test_number_of_segments,
	 number_of_segments );

	/* Verify the segments
	 */
	for( segment_index = 0;
	     segment_index < (size_t) number_of_segments;
	     segment_index++ )
	{
		result = libcsplit_wide_split_string_get_segment_by_index(
		          split_string,
		          (int) segment_index,
		          &string_segment,
		          &string_segment_size,
		          &error );

		CSPLIT_TEST_ASSERT_EQUAL_INT(
		 "result",
		 result,
		 1 );

		CSPLIT_TEST_ASSERT_IS_NOT_NULL(
		 "string_segment",
		 string_segment );

		CSPLIT_TEST_ASSERT_EQUAL_SIZE(
		 "string_segment_size",
		 string_segment_size,
		 expected_segment_sizes[ segment_index ] );

		if( expected_segment_sizes[ segment_index ] > 1 )
		{
			if( wide_string_compare(
			     string_segment,
			     expected_segments[ segment_index ],
			     expected_segment_sizes[ segment_index ] - 1 ) != 0 )
			{
				fprintf(
				 stdout,
				 "%s:%d segment: %d does not match expected segment\n",
				 __FILE__,
				 __LINE__,
				 (int) segment_index );

				goto on_error;
			}
		}
	}
	return( 1 );

on_error:
	if( error != NULL )
	{
		libcerror_error_free(
		 &error );
	}
	return( 0 );
}

/* Tests the libcsplit_wide_string_split function
 * Returns 1 if successful or 0 if not
 */
int csplit_test_wide_string_split(
      void )
{
	libcerror_error_t *error                    = NULL;
	libcsplit_wide_split_string_t *split_string = NULL;
	const wchar_t *expected_segments_1[ 6 ]     = { L"1", L"2", L"3", L"4", L"", L"5" };
	const size_t expected_segment_sizes_1[ 6 ]  = { 2, 2, 2, 2, 1, 2 };
	const wchar_t *expected_segments_2[ 1 ]     = { L"1 2 3 4  5" };
	const size_t expected_segment_sizes_2[ 1 ]  = { 11 };
	const wchar_t *expected_segments_3[ 5 ]     = { L"", L"a", L"1", L"2", L"3" };
	const size_t expected_segment_sizes_3[ 5 ]  = { 1, 2, 2, 2, 2 };
	const wchar_t *expected_segments_4[ 4 ]     = { L"1", L"2", L"3", L"" };
	const size_t expected_segment_sizes_4[ 4 ]  = { 2, 2, 2, 1 };
	const wchar_t *expected_segments_5[ 1 ]     = { L"1" };
	const size_t expected_segment_sizes_5[ 1 ]  = { 2 };
	int result                                  = 0;

	/* Test regular cases
	 */
	result = libcsplit_wide_string_split(
	          L"1 2 3 4  5",
	          11,
	          (wchar_t) ' ',
	          &split_string,
	          &error );

	CSPLIT_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CSPLIT_TEST_ASSERT_IS_NOT_NULL(
	 "split_string",
	 split_string );

	CSPLIT_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Verify the segments of the split string
	 */
	result = csplit_test_wide_split_string_verify_segments(
	          split_string,
	          expected_segments_1,
	          expected_segment_sizes_1,
	          6 );

	CSPLIT_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	result = libcsplit_wide_split_string_free(
	          &split_string,
	          &error );

	CSPLIT_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CSPLIT_TEST_ASSERT_IS_NULL(
	 "split_string",
	 split_string );

	CSPLIT_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test string that does not need splitting
	 */
	result = libcsplit_wide_string_split(
	          L"1 2 3 4  5",
	          11,
	          (wchar_t) '\n',
	          &split_string,
	          &error );

	CSPLIT_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CSPLIT_TEST_ASSERT_IS_NOT_NULL(
	 "split_string",
	 split_string );

	CSPLIT_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Verify the segments of the split string
	 */
	result = csplit_test_wide_split_string_verify_segments(
	          split_string,
	          expected_segments_2,
	          expected_segment_sizes_2,
	          1 );

	CSPLIT_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	result = libcsplit_wide_split_string_free(
	          &split_string,
	          &error );

	CSPLIT_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CSPLIT_TEST_ASSERT_IS_NULL(
	 "split_string",
	 split_string );

	CSPLIT_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test string with a leading delimiter
	 */
	result = libcsplit_wide_string_split(
	          L" a 1 2 3",
	          9,
	          (wchar_t) ' ',
	          &split_string,
	          &error );

	CSPLIT_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CSPLIT_TEST_ASSERT_IS_NOT_NULL(
	 "split_string",
	 split_string );

	CSPLIT_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Verify the segments of the split string
	 */
	result = csplit_test_wide_split_string_verify_segments(
	          split_string,
	          expected_segments_3,
	          expected_segment_sizes_3,
	          5 );

	CSPLIT_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	result = libcsplit_wide_split_string_free(
	          &split_string,
	          &error );

	CSPLIT_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CSPLIT_TEST_ASSERT_IS_NULL(
	 "split_string",
	 split_string );

	CSPLIT_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test string with a trailing delimiter
	 */
	result = libcsplit_wide_string_split(
	          L"1 2 3 ",
	          7,
	          (wchar_t) ' ',
	          &split_string,
	          &error );

	CSPLIT_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CSPLIT_TEST_ASSERT_IS_NOT_NULL(
	 "split_string",
	 split_string );

	CSPLIT_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Verify the segments of the split string
	 */
	result = csplit_test_wide_split_string_verify_segments(
	          split_string,
	          expected_segments_4,
	          expected_segment_sizes_4,
	          4 );

	CSPLIT_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	result = libcsplit_wide_split_string_free(
	          &split_string,
	          &error );

	CSPLIT_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CSPLIT_TEST_ASSERT_IS_NULL(
	 "split_string",
	 split_string );

	CSPLIT_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test string without delimiters
	 */
	result = libcsplit_wide_string_split(
	          L"1",
	          2,
	          (wchar_t) ' ',
	          &split_string,
	          &error );

	CSPLIT_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CSPLIT_TEST_ASSERT_IS_NOT_NULL(
	 "split_string",
	 split_string );

	CSPLIT_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Verify the segments of the split string
	 */
	result = csplit_test_wide_split_string_verify_segments(
	          split_string,
	          expected_segments_5,
	          expected_segment_sizes_5,
	          1 );

	CSPLIT_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	result = libcsplit_wide_split_string_free(
	          &split_string,
	          &error );

	CSPLIT_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CSPLIT_TEST_ASSERT_IS_NULL(
	 "split_string",
	 split_string );

	CSPLIT_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test empty string
	 */
	result = libcsplit_wide_string_split(
	          L"",
	          1,
	          (wchar_t) ' ',
	          &split_string,
	          &error );

	CSPLIT_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CSPLIT_TEST_ASSERT_IS_NULL(
	 "split_string",
	 split_string );

	CSPLIT_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = libcsplit_wide_string_split(
	          L"1 2 3 4  5",
	          0,
	          (wchar_t) ' ',
	          &split_string,
	          &error );

	CSPLIT_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CSPLIT_TEST_ASSERT_IS_NULL(
	 "split_string",
	 split_string );

	CSPLIT_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test error cases
	 */
	result = libcsplit_wide_string_split(
	          NULL,
	          11,
	          (wchar_t) ' ',
	          &split_string,
	          &error );

	CSPLIT_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	CSPLIT_TEST_ASSERT_IS_NULL(
	 "split_string",
	 split_string );

	CSPLIT_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	split_string = (libcsplit_wide_split_string_t *) 0x12345678UL;

	result = libcsplit_wide_string_split(
	          L"1 2 3 4  5",
	          11,
	          (wchar_t) ' ',
	          &split_string,
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

	split_string = NULL;

	result = libcsplit_wide_string_split(
	          L"1 2 3 4  5",
	          (size_t) SSIZE_MAX + 1,
	          (wchar_t) ' ',
	          &split_string,
	          &error );

	CSPLIT_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	CSPLIT_TEST_ASSERT_IS_NULL(
	 "split_string",
	 split_string );

	CSPLIT_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	result = libcsplit_wide_string_split(
	          L"1 2 3 4  5",
	          11,
	          (wchar_t) ' ',
	          NULL,
	          &error );

	CSPLIT_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	CSPLIT_TEST_ASSERT_IS_NULL(
	 "split_string",
	 split_string );

	CSPLIT_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

#if defined( HAVE_CSPLIT_TEST_MEMORY )

	/* Test csplit_test_wide_string_split with malloc failing in libcsplit_wide_split_string_initialize
	 */
	csplit_test_malloc_attempts_before_fail = 0;

	result = libcsplit_wide_string_split(
	          L"1 2 3 4  5",
	          11,
	          (wchar_t) ' ',
	          &split_string,
	          &error );

	if( csplit_test_malloc_attempts_before_fail != -1 )
	{
		csplit_test_malloc_attempts_before_fail = -1;

		if( split_string != NULL )
		{
			libcsplit_wide_split_string_free(
			 &split_string,
			 NULL );
		}
	}
	else
	{
		CSPLIT_TEST_ASSERT_EQUAL_INT(
		 "result",
		 result,
		 -1 );

		CSPLIT_TEST_ASSERT_IS_NULL(
		 "split_string",
		 split_string );

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
	if( split_string != NULL )
	{
		libcsplit_wide_split_string_free(
		 &split_string,
		 NULL );
	}
	return( 0 );
}

#endif /* defined( LIBCSPLIT_HAVE_WIDE_CHARACTER_TYPE ) */

/* The main program
 */
#if defined( HAVE_WIDE_SYSTEM_CHARACTER )
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

	CSPLIT_TEST_RUN(
	 "libcsplit_wide_string_split",
	 csplit_test_wide_string_split );

#endif /* defined( LIBCSPLIT_HAVE_WIDE_CHARACTER_TYPE ) */

	return( EXIT_SUCCESS );

#if defined( LIBCSPLIT_HAVE_WIDE_CHARACTER_TYPE )

on_error:
	return( EXIT_FAILURE );

#endif /* defined( LIBCSPLIT_HAVE_WIDE_CHARACTER_TYPE ) */
}
