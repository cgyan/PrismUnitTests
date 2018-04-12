#include <gmock/gmock.h>
using namespace ::testing;
#include <prism/global>
#include <prism/FileInfo>

PRISM_BEGIN_NAMESPACE
PRISM_BEGIN_TEST_NAMESPACE

class FileInfoSuffixParamTests : public TestWithParam<std::string>
{
public:
        FileInfo cut;
};

INSTANTIATE_TEST_CASE_P(
        ,
        FileInfoSuffixParamTests,
        Values(
                "file.txt"
                ".txt",
                "file.old.txt",
                "./file.txt",
                "../file.txt",
                "data/./files/../file.txt",
                "/files/file.txt",
                "c:/file.txt"
        )
);

TEST_P(FileInfoSuffixParamTests, ShouldReturnSuffixWhenFilenameIsNotEmpty)
{
        const std::string filePath = GetParam();
        cut.setFile(filePath);
        EXPECT_THAT(cut.suffix(), Eq("txt"));
}

TEST(FileInfoSuffixTests, ShouldReturnEmptyStringWhenFilenameHasNoSuffix)
{
        const std::string filenameWithNoSuffix = "files/file_with_no_suffix";
        FileInfo cut(filenameWithNoSuffix);
        EXPECT_THAT(cut.suffix(), Eq(""));
}

TEST(FileInfoSuffixTests, ShouldReturnEmptyStringWhenFilenameIsEmpty)
{
        FileInfo cut;
        EXPECT_THAT(cut.suffix(), Eq(""));
}

PRISM_END_TEST_NAMESPACE
PRISM_END_NAMESPACE