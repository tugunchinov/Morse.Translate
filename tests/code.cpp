#include <code.h>
#include <gtest/gtest.h>

TEST(Encode, Register)
{
    ASSERT_EQ(encode("HeLlO"), encode("hELLo"));
    ASSERT_EQ(encode("goodbye"), encode("GOODBYE"));
}

TEST(Encode, Encode)
{
    ASSERT_EQ(encode("Hello, world!"),
              QString(".... . .-.. .-.. --- .-.-.-  " // Hello,
                      ".-- --- .-. .-.. -.. --..--")); // world!
}

TEST(Decode, Decode)
{
    ASSERT_EQ(QString("HELLO, WORLD!"),
              decode(".... . .-.. .-.. --- .-.-.-  " // Hello,
                     ".-- --- .-. .-.. -.. --..--")); // world!
}