#ifdef _win32
    char dir[20] = "C:\\"
#elif __linux__
    char dir[20] = "/"
#elif __APPLE__
    char dir[20] = "/"
#endif
