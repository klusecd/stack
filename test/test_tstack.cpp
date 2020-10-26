#include "utstack.h"

#include <gtest.h>

TEST(TStack, can_create_stack)
{
	ASSERT_NO_THROW(TStack<int> s);
}

TEST(TStack, cant_create_too_large_stack)
{
	ASSERT_ANY_THROW(TStack<int> s(MAX_STACK_SIZE + 1));
}

TEST(TStack, cant_create_stack_with_negative_length)
{
	ASSERT_ANY_THROW(TStack<int> s(-15));
}

TEST(TStack, can_push)
{
	TStack<int> s;
	ASSERT_NO_THROW(s.push(2));
}

TEST(TStack, can_pop)
{
	TStack<int> s;
	s.push(2);
	ASSERT_NO_THROW(s.pop());
}
 
TEST(TStack, can_detect_emptiness) {
	TStack<int> s(5);
	ASSERT_TRUE(s.empty());
}

TEST(TStack, can_assign_stacks_of_different_size)
{
	TStack<int> s1(4), s2(10);
	s2 = s1;
	EXPECT_EQ(s1, s2);
}

TEST(TStack, throws_when_push_into_full_stack)
{
	TStack<int> s(3);
	s.push(1);
	s.push(2);
	s.push(3);
	ASSERT_ANY_THROW(s.push(4));
}
