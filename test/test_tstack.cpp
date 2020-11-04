#include "utstack.h"

#include <gtest.h>

TEST(TStack, can_create_stack)
{
	ASSERT_NO_THROW(TStack<int> s);
}

TEST(TStack, cant_create_too_large_stack)
{
	ASSERT_ANY_THROW(TStack<int> s(MAX_SIZE + 1));
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

TEST(TStack, can_get_top) {
	TStack<int> s(3);
	s.push(1);
	ASSERT_NO_THROW(s.top());
}

TEST(TStack, can_clear_stack)
{
	TStack<int> s;
	s.push(1);
	s.clear();
	EXPECT_EQ(1, s.empty());
}

//---------------------------------------------------

TEST(TQueue, can_create_queue_with_positive_length)
{
	ASSERT_NO_THROW(TQueue<int> q(5));
}

TEST(TQueue, cant_create_too_large_queue)
{
	ASSERT_ANY_THROW(TQueue<int> q(MAX_SIZE + 1));
}

TEST(TQueue, throws_when_create_queue_with_negative_length)
{
	ASSERT_ANY_THROW(TQueue<int> q(-1));
}

TEST(Queue, cant_do_pop_when_queue_is_empty) {
	TQueue<int> q;
	ASSERT_ANY_THROW(q.pop());
}

TEST(TQueue, can_pop)
{
	TQueue<int> q(5);
	q.push(1);
	ASSERT_NO_THROW(q.pop());
}

TEST(TQueue, no_throw_when_many_pushes_and_pops)
{
	TQueue<int> q(5);
	q.push(1);
	q.push(2);
	q.push(3);
	q.push(4);
	q.push(5);
	q.pop();
	q.push(6);
	ASSERT_NO_THROW(q.pop());
}

TEST(TQueue, cannot_push_full_queue) {
	TQueue<int> q(2);
	q.push(2);
	q.push(4);
	ASSERT_ANY_THROW(q.push(3));
}

TEST(TQueue, can_create_queue)
{
	ASSERT_NO_THROW(TQueue<int> s);
}

TEST(TQueue, can_push)
{
	TQueue<int> q;
	ASSERT_NO_THROW(q.push(1));
}


TEST(TQueue, throws_when_pop_from_empty_stack)
{
	TQueue<int> q;
	ASSERT_ANY_THROW(q.pop());
}


TEST(TQueue, works_correctly)
{
	TQueue<int> q(5);
	q.push(1);
	q.push(2);
	q.push(3);
	q.push(4);
	q.push(5);
	q.pop();
	q.push(6);
	EXPECT_EQ(6, q[4]);
}


TEST(TQueue, can_return_element)
{
	TQueue<int> q(5);
	q.push(1);
	ASSERT_NO_THROW(q[0]);
}

TEST(TQueue, return_true_when_queue_is_full) {
	TQueue<int> q;
	EXPECT_EQ(false, q.full());
}

TEST(TQueue, return_false_when_queue_isnt_full) {
	TQueue<int> q(6);
	q.push(1);
	EXPECT_EQ(false, q.full());
}

TEST(TQueue, return_true_when_queue_is_empty) {
	TQueue<int> q;
	EXPECT_EQ(true, q.empty());
}

TEST(TQueue, throw_when_push_into_full_queue)
{
	TQueue<int> q(3);
	q.push(1);
	q.push(2);
	q.push(3);
	ASSERT_ANY_THROW(q.push(4));
}

TEST(TQueue, can_clear_queue)
{
	TQueue<int> q;
	q.push(1);
	q.clear();
	EXPECT_EQ(1, q.empty());
}