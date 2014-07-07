#include "lib/file_system.h"

int usage()
{
    std::cerr << "Usage: ./ls <root> <path>" << std::endl;
    return 1;
}

int main(int argc, char *argv[])
{
    if (argc != 3)
        return usage();

    FileSystem fs(argv[1]);
    return fs.doLs(argv[2]);
}

