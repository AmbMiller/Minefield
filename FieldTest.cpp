/**
 * Unit Tests for Field class
**/

#include <gtest/gtest.h>
#include <iostream>
#include <string>
#include "Field.h"
 
class FieldTest : public ::testing::Test
{
	protected:
		FieldTest(){}
		virtual ~FieldTest(){}
		virtual void SetUp(){}
		virtual void TearDown(){}
};

TEST(FieldTest, placeMineInBounds)
{
	Field minefield;
	
	minefield.placeMine(4,5);
	ASSERT_EQ( MINE_HIDDEN, minefield.get(4,5) );
}

TEST(FieldTest, fieldSizeOutOfBounds)
{
  	Field minefield;
	bool caught = false;
	try{
	   minefield.get(11,11);
	}
	catch(int err){
	  caught = true;
	}
	ASSERT_TRUE(caught);
}

TEST(FieldTest, checkAdjecent )
{
  	Field minefield;
	minefield.placeMine(4,5);
	minefield.revealAdjacent(4,4);
	ASSERT_EQ( MINE_HIDDEN, minefield.get(4,5));
}
