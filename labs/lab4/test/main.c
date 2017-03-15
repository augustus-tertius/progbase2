#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

#include <check.h>
#include <convert.h>

START_TEST (min_emptyList_errnoErrorListEmpty)
{

}
END_TEST

START_TEST (min_oneValue_returnsThatOneValue)
{
	
}
END_TEST

START_TEST (min_someValues_returnsMinimum)
{
	
}
END_TEST


Suite *test_suite() {
  Suite *s = suite_create("Module");
  TCase *tc_sample;

  tc_sample = tcase_create("TestCase");
  tcase_add_test(tc_sample, min_emptyList_errnoErrorListEmpty);
  tcase_add_test(tc_sample, min_oneValue_returnsThatOneValue);
  tcase_add_test(tc_sample, min_someValues_returnsMinimum);

  suite_add_tcase(s, tc_sample);

  return s;
}

int main() {
  Suite *s = test_suite();
  SRunner *sr = srunner_create(s);
  srunner_set_fork_status(sr, CK_NOFORK);

  srunner_run_all(sr, CK_VERBOSE);

  int num_tests_failed = srunner_ntests_failed(sr);
  srunner_free(sr);
  
  return num_tests_failed;
}