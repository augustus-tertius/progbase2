#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

#include <check.h>
#include <lectureCourse.h> 
#include <convert.h>

START_TEST (structToStr_nullStruct_emptyStr)
{
  LectureCourse* test = NULL;
  char str [1000];
  
  structToStr(test, str);
  ck_assert_str_eq(str, "");

  LectureCourse_free(&test);
}
END_TEST

START_TEST (structToStr_basicValue_returnsValidString)
{
  LectureCourse * test = LectureCourse_create("Електротехніка", "Бужко", "Олена", "Миколаївна", 51, 48, 4.8);
	char str [1000];
  
  structToStr(test, str);
  ck_assert_str_eq(str, "Електротехніка Бужко Олена Миколаївна 51 48 4.8");

  LectureCourse_free(&test);
}
END_TEST

START_TEST (refillParam_newStringIsNull_noChanges)
{
  char* str = NULL;
  LectureCourse * test = LectureCourse_create("Електротехніка", "Бужко", "Олена", "Миколаївна", 51, 48, 4.8);

  refillParam(test, 1, str);
  ck_assert_str_eq(LectureCourse_getCourseName(test), LectureCourse_getCourseName(test));
  LectureCourse_free(&test);
}
END_TEST

START_TEST (refillParam_newLength_validChanges)
{
  char * str = "17";
  LectureCourse * test = LectureCourse_create("Електротехніка", "Бужко", "Олена", "Миколаївна", 51, 48, 4.8);

  refillParam(test, 6, str);
  ck_assert_int_eq(LectureCourse_getLength(test), LectureCourse_getLength(test));
  LectureCourse_free(&test);
}
END_TEST

START_TEST(copyStruct_oldStructIsNULL_noChanges)
{
  LectureCourse * oldStr = NULL;
  LectureCourse * newStr = LectureCourse_create("Електротехніка", "Бужко", "Олена", "Миколаївна", 51, 48, 4.8);

  copyStruct(newStr, oldStr);
  ck_assert_int_eq(LectureCourse_getLength(newStr), LectureCourse_getLength(newStr));
  ck_assert_str_eq(LectureCourse_getCourseName(newStr), LectureCourse_getCourseName(newStr));

  LectureCourse_free(&oldStr);
  LectureCourse_free(&newStr);
}
END_TEST

START_TEST(copyStruct_newStructIsNULL_noChanges)
{
  LectureCourse * newStr = NULL;
  LectureCourse * oldStr = LectureCourse_create("Електротехніка", "Бужко", "Олена", "Миколаївна", 51, 48, 4.8);

  copyStruct(newStr, oldStr);
  ck_assert_int_eq(LectureCourse_getLength(oldStr), LectureCourse_getLength(oldStr));
  ck_assert_str_eq(LectureCourse_getCourseName(oldStr), LectureCourse_getCourseName(oldStr));

  LectureCourse_free(&oldStr);
  LectureCourse_free(&newStr);
}
END_TEST

START_TEST(copyStruct_validStruct_normalChanges)
{
  LectureCourse * newStr = LectureCourse_new();
  LectureCourse * oldStr = LectureCourse_create("Електротехніка", "Бужко", "Олена", "Миколаївна", 51, 48, 4.8);

  copyStruct(newStr, oldStr);
  ck_assert_int_eq(LectureCourse_getLength(newStr), LectureCourse_getLength(oldStr));
  ck_assert_str_eq(LectureCourse_getCourseName(newStr), LectureCourse_getCourseName(oldStr));

  LectureCourse_free(&oldStr);
  LectureCourse_free(&newStr);
}
END_TEST





Suite *test_suite() {
  Suite *s = suite_create("Convert Module");
  TCase *tc_sample = tcase_create("tc_struct");

  tc_sample = tcase_create("TestCase");
  tcase_add_test(tc_sample, structToStr_nullStruct_emptyStr);
  tcase_add_test(tc_sample, structToStr_basicValue_returnsValidString);

  tcase_add_test(tc_sample, refillParam_newStringIsNull_noChanges);
  tcase_add_test(tc_sample, refillParam_newLength_validChanges);

  tcase_add_test(tc_sample, copyStruct_oldStructIsNULL_noChanges);
  tcase_add_test(tc_sample, copyStruct_newStructIsNULL_noChanges);
  tcase_add_test(tc_sample, copyStruct_validStruct_normalChanges);

  suite_add_tcase(s, tc_sample);

  return s;
}

int main() {
  Suite *s = test_suite();
  SRunner *sr = srunner_create(s);

  //srunner_set_fork_status(sr, CK_NOFORK);

  srunner_run_all(sr, CK_VERBOSE);

  int num_tests_failed = srunner_ntests_failed(sr);
  srunner_free(sr);
  return num_tests_failed;
}