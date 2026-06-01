#include <gtest/gtest.h>
#include "chain.hpp"

TEST(ChainTest, CustomerSupporterHandlesCustomerIssue) {
    CEO ceo(nullptr);
    SoftwareEngineer se(&ceo);
    CustomerSupporter cs(&se);
    testing::internal::CaptureStdout();
    cs.Work(Task::CustomerIssue);
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_NE(output.find("[CustomerSupporter] Resolve customer issue."), std::string::npos);
}

TEST(ChainTest, SoftwareEngineerHandlesProgramming) {
    CEO ceo(nullptr);
    SoftwareEngineer se(&ceo);
    testing::internal::CaptureStdout();
    se.Work(Task::Programming);
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_NE(output.find("[SoftwareEngineer] Programming."), std::string::npos);
}

TEST(ChainTest, TrainedEngineerSolvesHardProgramming) {
    CEO ceo(nullptr);
    SoftwareEngineer se(&ceo);
    se.Train();
    testing::internal::CaptureStdout();
    se.Work(Task::HardProgramming);
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_NE(output.find("Successfully solve"), std::string::npos);
}

TEST(ChainTest, CEOHandlesMoneyIssue) {
    CEO ceo(nullptr);
    testing::internal::CaptureStdout();
    ceo.Work(Task::MoneyIssue);
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_NE(output.find("[CEO] Resolve money issue."), std::string::npos);
}

TEST(ChainTest, GodHandlesAnyTask) {
    God god(nullptr);
    testing::internal::CaptureStdout();
    god.Work(Task::ImpossibleTask);
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_NE(output.find("[God] God can do anything!"), std::string::npos);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
