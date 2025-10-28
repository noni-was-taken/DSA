/*
  test.h - stress tests for open hashing dictionary

  Provides: int run_open_hashing_tests(Dictionary d);

  This header is included by openHashing.c after the Dictionary typedef and
  function prototypes. It relies on the following signatures:
	- void initDict(Dictionary);
	- void insertStudent(Dictionary, int, char*, char*);
	- int  hash(char*, char*);
	- void displayStudents(Dictionary);

  The tests will:
	1) Insert a fixed set of students (some sharing initial letters to force collisions)
	2) Insert a larger batch programmatically
	3) Validate bucket counts and total node count
	4) Spot-check that specific hashes map to expected indices based on the provided hash
*/

#ifndef OPEN_HASHING_TEST_H
#define OPEN_HASHING_TEST_H

#include <stdio.h>
#include <string.h>

/* Small assertion helper that prints failures but never exits */
static int th_assert(int condition, const char *msg){
	if(!condition){
		printf("\n[TEST][FAIL] %s", msg);
		return 1;
	}
	return 0;
}

/* Count total nodes in the dictionary */
static int th_count_total(Dictionary d){
	int total = 0;
	for(int i=0;i<MAX;i++){
		for(NodePtr t = d[i]; t != NULL; t = t->next){
			total++;
		}
	}
	return total;
}

/* Count nodes in one bucket */
static int th_bucket_size(Dictionary d, int idx){
	int c = 0; 
	for(NodePtr t = d[idx]; t != NULL; t = t->next) c++;
	return c;
}

/* Get head node id at a bucket or -1 if empty */
static int th_bucket_head_id(Dictionary d, int idx){
	return d[idx] ? d[idx]->data.id : -1;
}

/* Construct simple names within maxString bounds: fNNN and lNNN */
static void th_make_names(int n, char *lname, char *fname){
	/* ensure we do not overflow maxString=20 */
	snprintf(lname, maxString, "l%d", n);
	snprintf(fname, maxString, "f%d", n);
}

static int test_small_fixed(Dictionary d){
	int fails = 0;
	/* Force collisions: same initials control hash heavily */
	insertStudent(d, 101, "Smith", "Sam");   // 'S','S'
	insertStudent(d, 102, "Stone", "Seth");  // 'S','S' -> same bucket as above
	insertStudent(d, 103, "Adams", "Alice"); // 'A','A'
	insertStudent(d, 104, "Adler", "Aaron"); // 'A','A' -> collision with above
	insertStudent(d, 105, "Brown", "Bob");   // 'B','B'

	int total = th_count_total(d);
	fails += th_assert(total == 5, "Total items after small fixed insert should be 5");

	/* Buckets for 'S','S' and 'A','A' should each contain >= 2 nodes
	   Note: They might map to the same index; handle both cases */
	int bSS = hash("Smith","Sam");
	int bAA = hash("Adams","Alice");
	fails += th_assert(th_bucket_size(d, bSS) >= 2, "Bucket for 'S','S' should have >=2 items");
	fails += th_assert(th_bucket_size(d, bAA) >= 2, "Bucket for 'A','A' should have >=2 items");

	/* Verify relative order within each initial group regardless of bucket interleaving */
	for(int pass=0; pass<2; ++pass){
		int idx = (pass==0? bSS : bAA);
		char L0 = (pass==0? 'S' : 'A');
		char F0 = (pass==0? 'S' : 'A');
		int expected_head = (pass==0? 102 : 104);
		int expected_next = (pass==0? 101 : 103);

		int found_first = -1, found_second = -1;
		for(NodePtr t = d[idx]; t != NULL; t = t->next){
			if((unsigned char)t->data.lName[0] == (unsigned char)L0 &&
			   (unsigned char)t->data.fName[0] == (unsigned char)F0){
				if(found_first < 0){
					found_first = t->data.id;
				}else if(found_second < 0){
					found_second = t->data.id;
					break;
				}
			}
		}
		fails += th_assert(found_first == expected_head, pass==0 ?
			"Within 'S','S' group, last inserted should appear before earlier one" :
			"Within 'A','A' group, last inserted should appear before earlier one");
		fails += th_assert(found_second == expected_next, pass==0 ?
			"Within 'S','S' group, second should be previous insert" :
			"Within 'A','A' group, second should be previous insert");
	}

	return fails;
}

static int test_bulk_randomish(Dictionary d){
	int fails = 0;
	/* Insert many entries to stress chaining; vary initial letters to spread */
	const int N = 200; /* > MAX to ensure collisions */
	char ln[maxString];
	char fn[maxString];
	for(int i=0;i<N;i++){
		/* cycle through a few initials to blend buckets */
		char l0, f0;
		switch(i % 5){
			case 0: l0='A'; f0='A'; break;
			case 1: l0='S'; f0='S'; break;
			case 2: l0='B'; f0='B'; break;
			case 3: l0='C'; f0='D'; break;
			default:l0='Z'; f0='Y'; break;
		}
		/* make short unique tails; but hash only uses first letter, so collisions occur */
		th_make_names(i, ln, fn);
		ln[0] = l0; fn[0] = f0; /* enforce first letter */
		insertStudent(d, 1000 + i, ln, fn);
	}

	int total = th_count_total(d);
	fails += th_assert(total >= 205, "Total items after bulk insert should be >= 205 (includes earlier 5)");

	/* Ensure several buckets are non-empty and reasonably loaded */
	int bAA = hash("Apple","Adam");
	int bSS = hash("Stone","Seth");
	int bBB = hash("Brown","Bob");
	int bCD = hash("Cxx","Dyy");
	int bZY = hash("Zzz","Yyy");

	fails += th_assert(th_bucket_size(d, bAA) > 0, "Bucket A/A should be non-empty");
	fails += th_assert(th_bucket_size(d, bSS) > 0, "Bucket S/S should be non-empty");
	fails += th_assert(th_bucket_size(d, bBB) > 0, "Bucket B/B should be non-empty");
	fails += th_assert(th_bucket_size(d, bCD) > 0, "Bucket C/D should be non-empty");
	fails += th_assert(th_bucket_size(d, bZY) > 0, "Bucket Z/Y should be non-empty");

	/* Spot-check head insertion on one of the buckets we kept inserting into */
	/* For sequence i where i%5==1 we used S/S; the last such i < N is: */
	int lastSSi = N - 1 - ((N - 1) % 5 != 1 ? ((N - 1) % 5) - 1 : 0);
	/* Build the expected id and names for the last S/S insert */
	int expected_id = 1000 + lastSSi;
	th_make_names(lastSSi, ln, fn); ln[0]='S'; fn[0]='S';
	int b_lastSS = hash(ln, fn);
	fails += th_assert(b_lastSS == bSS, "Computed last S/S bucket should match bSS");
	fails += th_assert(th_bucket_head_id(d, bSS) == expected_id, "Head of S/S bucket should match id of last S/S insertion");

	return fails;
}

static int test_hash_index_math(void){
	int fails = 0;
	/* Given current hash: idx = (l0*89 + f0*71) % MAX */
	int idx = hash("Smith","Sam");
	int expected = (((int)(unsigned char)'S')*89 + ((int)(unsigned char)'S')*71) % MAX;
	fails += th_assert(idx == expected, "hash('Smith','Sam') should match formula");
	return fails;
}

static void test_print_bucket_stats(Dictionary d){
	/* Optional summary to help visualize distribution */
	int nonEmpty = 0, maxLen = 0;
	for(int i=0;i<MAX;i++){
		int k = th_bucket_size(d, i);
		if(k>0){ nonEmpty++; if(k>maxLen) maxLen = k; }
	}
	printf("\n[TEST] Non-empty buckets: %d / %d, max chain length: %d\n", nonEmpty, MAX, maxLen);
}

static int run_open_hashing_tests(Dictionary d){
	int failures = 0;
	printf("\n[TEST] Running open hashing tests...\n");
	failures += test_small_fixed(d);
	failures += test_hash_index_math();
	failures += test_bulk_randomish(d);
	test_print_bucket_stats(d);
	if(failures==0){
		printf("[TEST][PASS] All tests passed.\n");
	}
	return failures;
}

#endif /* OPEN_HASHING_TEST_H */
