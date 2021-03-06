/*
* ========== Copyright Header Begin ==========================================
* 
* OpenSPARC T1 Processor File: l2_emul_test.c
* Copyright (c) 2006 Sun Microsystems, Inc.  All Rights Reserved.
* DO NOT ALTER OR REMOVE COPYRIGHT NOTICES.
* 
* The above named program is free software; you can redistribute it and/or
* modify it under the terms of the GNU General Public
* License version 2 as published by the Free Software Foundation.
* 
* The above named program is distributed in the hope that it will be 
* useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
* General Public License for more details.
* 
* You should have received a copy of the GNU General Public
* License along with this work; if not, write to the Free Software
* Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301, USA.
* 
* ========== Copyright Header End ============================================
*/
#include <sys/types.h>
#include <stdio.h>


/*
 * This program runs on T1 FPGA system and shuffles the test_memory_data[].
 * The final shuffled contents of the test_memory_data[] must match with the
 * contents of the expected_memory_data[]. The contents of the expected_memory_data[]
 * are generated by running the shuffling function on a SPARC system on
 * the same input test_memory_data[].
 */


#include "shuffle_memory.h"
#include "data.h"


int
main(int argc, char *argv[])
{
    Elem *test_memory     = test_memory_data;
    Elem *expected_memory = expected_memory_data;


    if (shuffle_memory(test_memory) == 0) {
	printf("ERROR: shuffle_memory failed. not verifying results \n");
	return 1;
    }

    if (verify_results(test_memory, expected_memory) == 0) {
	printf("ERROR: verify_results failed. \n");
	return 1;
    }

    return 0;
}
