#include <gmock/gmock.h>
using namespace ::testing;
#include <prism/global>
#include <prism/FileInfo>
#include <prism/FileSystemFactory>
#include <prism/FakeFileSystem>
#include <map>

PRISM_BEGIN_NAMESPACE
PRISM_BEGIN_TEST_NAMESPACE
//======================================================================================================================
// FileInfoFilenameParamTests
//======================================================================================================================
class FileInfoFilenameParamTests : public TestWithParam<std::string>
{
public:
        FileInfo testSubject;
        const std::string expectedFilename() { return m_expectedFilename; }
private:
        std::string m_expectedFilename{"file.txt"};
};

INSTANTIATE_TEST_CASE_P(
        ,
        FileInfoFilenameParamTests,
        Values(
                "file.txt",
                "./file.txt",
                "../file.txt",
                "/files/file.txt",
                "c:\\file.txt",
                "/usr/file.txt",
                "..\\file.txt"
        )
);

TEST_P(FileInfoFilenameParamTests, ShouldExtractFilenameFromFilePath)
{
        std::string filePath = GetParam();
        testSubject.setFile(filePath);
        EXPECT_EQ(expectedFilename(), testSubject.filename());
}
//======================================================================================================================
// FileInfoFilenameTests
//======================================================================================================================
class FileInfoFilenameTests : public Test {
public:
        FileInfo testSubject;
};

TEST_F(FileInfoFilenameTests, WhenFilenameHasNotBeenSetExpectEmptyStringReturned)
{
        EXPECT_EQ("", testSubject.filename());
}

TEST_F(FileInfoFilenameTests, WhenFilenameContainsMultipleSuffixesExpectBasenameAndSuffixesReturned)
{
        const std::string filenameContainingMultipleSuffixes = "files/compressed/file.tar.gz";
        testSubject.setFile(filenameContainingMultipleSuffixes);
        const std::string expected = "file.tar.gz";
        EXPECT_EQ(expected, testSubject.filename());
}

TEST_F(FileInfoFilenameTests, WhenFilenameHasNoBasenameExpectSuffixReturned)
{
        const std::string filenameWithoutBasename = ".txt";
        testSubject.setFile(filenameWithoutBasename);
        EXPECT_EQ(filenameWithoutBasename, testSubject.filename());
}

TEST_F(FileInfoFilenameTests, WhenFilenameHasNoSuffixExpectSuffixReturned)
{
        const std::string filenameWithoutSuffix = "file";
        testSubject.setFile(filenameWithoutSuffix);
        EXPECT_EQ(filenameWithoutSuffix, testSubject.filename());
}

PRISM_END_TEST_NAMESPACE
PRISM_END_NAMESPACE