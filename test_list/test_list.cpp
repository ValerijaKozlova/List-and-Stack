#include "tlist.h"

#include <gtest.h>

TEST(TList, can_create_node)
{
	ASSERT_NO_THROW(node<int> nd);
}

TEST(TList, can_create_list)
{
	ASSERT_NO_THROW(TList<int> ls);
}

TEST(TList, new_list_is_empty)
{
	TList<int> ls;

	EXPECT_EQ(true, ls.IsStackEmpty());
}

TEST(TList, can_print_white_list)
{
	TList<int> ls;

	ASSERT_NO_THROW(ls.PrintStack());// "List is empty"
}

//Проверка вставки

TEST(TList, can_insert_at_begin)
{
	TList<int> ls;
	ls.InsertBegin(2);
	EXPECT_EQ(2, ls.View());

}

TEST(TList, can_insert_at_end)
{
	TList<int> ls;
	ls.InsertBegin(2);
	ls.InsertEnd(4);
	EXPECT_EQ(4, ls.View());
}

TEST(TList, can_insert_after_elem)
{
	TList<int> ls;
	ls.InsertBegin(2);
	node<int>* start = ls.Search(2);
	ls.Insert(4, start);
	EXPECT_EQ(2, ls.View());
}

TEST(TList, can_insert_in_empty_list)
{
	TList<int> ls;

	ASSERT_NO_THROW(ls.InsertBegin(3));
}

//Проверка удаления

TEST(TList, can_delete_at_begin)
{
	TList<int> ls;
	ls.InsertBegin(3);
	ls.InsertEnd(5);
	ls.DeleteBegin();

	EXPECT_EQ(3, ls.View());
}

TEST(TList, can_delete_at_end)
{
	TList<int> ls;
	ls.InsertBegin(3);
	ls.InsertEnd(5);
	ls.DeleteEnd();

	EXPECT_EQ(5, ls.View());
}

TEST(TList, can_delete_after_elem)
{
	TList<int> ls;
	ls.InsertBegin(3);
	ls.InsertEnd(5);
	node<int>* start = ls.Search(3);
	ls.Delete(start);

	ASSERT_EQ(3, ls.View());
}

//Проверка поиска

TEST(TList, search_in_white_list)
{
	TList<int> ls;

	EXPECT_EQ(0, ls.Search(3));
}

TEST(TList, search_elem)
{

	TList<int> ls;
	ls.InsertBegin(3);
	ls.InsertEnd(5);
	node<int>* start = ls.Search(5);

	EXPECT_EQ(5, start->data);
}