#include <iostream>
#include <opencv2/opencv.hpp>

#include <math.h>
#include <gtest/gtest.h>

using namespace std;
using namespace cv;


double squareRoot(const double a) {
    double b = sqrt(a);
    if(b != b) { // nan check
        return -1.0;
    }else{
        return sqrt(a);
    }
}

class Foo
{
public:
    Foo()
            : i(0)
    {
        std::cout << "CONSTRUCTED" << std::endl;
    }
    ~Foo()
    {
        std::cout << "DESTRUCTED" << std::endl;
    }
    int i;
};

class TestFoo : public ::testing::Test
{
protected:
    void SetUp()
    {
        foo = new Foo;
        foo->i = 5;
    }
    void TearDown()
    {
        delete foo;
    }
    void change()
    {
        foo->i = 10;
    }
    Foo *foo;
};

TEST_F(TestFoo, test1)
{
ASSERT_EQ(foo->i, 5);
foo->i = 10;
}

TEST_F(TestFoo, test2)
{
ASSERT_EQ(foo->i, 5);
}

TEST(SquareRootTest, PositiveNos) {
ASSERT_EQ(6, squareRoot(36.0)) << "!!!!!!!!!!!!!!!!!!!!";
ASSERT_EQ(18.0, squareRoot(324.0));
ASSERT_EQ(25.4, squareRoot(645.16));
ASSERT_EQ(0, squareRoot(0.0));
}

TEST(SquareRootTest, NegativeNos) {
ASSERT_EQ(-1.0, squareRoot(-15.0));
ASSERT_EQ(-1.0, squareRoot(-0.2));
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}