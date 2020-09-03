#include <gtest/gtest.h>
#include <config.h>

int main(int argc, char** argv)
{
    initDictionaries();
    
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
