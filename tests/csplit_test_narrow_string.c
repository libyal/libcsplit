/*
 * Library narrow string functions test program
 *
 * Copyright (C) 2008-2017, Joachim Metz <joachim.metz@gmail.com>
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
#include <types.h>

#if defined( HAVE_STDLIB_H ) || defined( WINAPI )
#include <stdlib.h>
#endif

#include "csplit_test_libcerror.h"
#include "csplit_test_libcsplit.h"
#include "csplit_test_macros.h"
#include "csplit_test_unused.h"

/* Tests the libcsplit_narrow_string_split function
 * Returns 1 if successful or 0 if not
 */
int csplit_test_narrow_string_split(
     void )
{
	libcerror_error_t *error                      = NULL;
	libcsplit_narrow_split_string_t *split_string = NULL;
	int result                                    = 0;

	/* Test error cases
	 */
	result = libcsplit_narrow_string_split(
	          NULL,
	          10,
	          ' ',
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

	result = libcsplit_narrow_string_split(
	          "1 2 3 4 5",
	          (size_t) SSIZE_MAX + 1,
	          ' ',
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

	result = libcsplit_narrow_string_split(
	          "1 2 3 4 5",
	          10,
	          ' ',
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

	CSPLIT_TEST_RUN(
	 "libcsplit_narrow_string_split",
	 csplit_test_narrow_string_split );

	return( EXIT_SUCCESS );

on_error:
	return( EXIT_FAILURE );
}

