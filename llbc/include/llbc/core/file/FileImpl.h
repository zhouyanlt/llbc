/**
 * @file    FileImpl.h
 * @author  Longwei Lai<lailongwei@126.com>
 * @date    2016/01/05
 *
 * @brief
 */
#ifdef __LLBC_CORE_FILE_File_H__

__LLBC_NS_BEGIN

inline int LLBC_File::Read(bool &boolVal)
{
    return ReadRawObj<bool>(boolVal);
}

inline int LLBC_File::Read(sint8 &sint8Val)
{
    return ReadRawObj<sint8>(sint8Val);
}

inline int LLBC_File::Read(uint8 &uint8Val)
{
    return ReadRawObj<uint8>(uint8Val);
}

inline int LLBC_File::Read(sint16 &sint16Val)
{
    return ReadRawObj<sint16>(sint16Val);
}

inline int LLBC_File::Read(uint16 &uint16Val)
{
    return ReadRawObj<uint16>(uint16Val);
}

inline int LLBC_File::Read(sint32 &sint32Val)
{
    return ReadRawObj<sint32>(sint32Val);
}

inline int LLBC_File::Read(uint32 &uint32Val)
{
    return ReadRawObj<uint32>(uint32Val);
}

inline int LLBC_File::Read(long &longVal)
{
    return ReadRawObj<long>(longVal);
}

inline int LLBC_File::Read(LLBC_NS ulong &ulongVal)
{
    return ReadRawObj<LLBC_NS ulong>(ulongVal);
}

inline int LLBC_File::Read(sint64 &sint64Val)
{
    return ReadRawObj<sint64>(sint64Val);
}

inline int LLBC_File::Read(uint64 &uint64Val)
{
    return ReadRawObj<uint64>(uint64Val);
}

inline int LLBC_File::Read(float &floatVal)
{
    return ReadRawObj<float>(floatVal);
}

inline int LLBC_File::Read(double &doubleVal)
{
    return ReadRawObj<double>(doubleVal);
}

inline int LLBC_File::Read(ldouble &ldoubleVal)
{
    return ReadRawObj<ldouble>(ldoubleVal);
}

inline LLBC_String LLBC_File::ReadLine()
{
    LLBC_String line;

    char ch;
    while (Read(ch) != LLBC_RTN_FAILED)
    {
        if (ch != LLBC_CR && ch != LLBC_LF)
        {
            line.append(1, ch);
            continue;
        }

        if (ch == LLBC_CR)
        {
            // Read linefeed.
            if (ReadRawObj<char>(ch) == LLBC_RTN_OK)
            {
                if (ch != LLBC_LF)
                    OffsetFilePosition(-1);
            }
        }

        break;
    }

    return line;
}

template <typename T>
inline int LLBC_File::ReadRawObj(T &obj)
{
    long actuallyRead = Read((&obj), sizeof(T));
    if (actuallyRead == -1)
    {
        return LLBC_RTN_FAILED;
    }
    else if (actuallyRead != sizeof(T))
    {
        LLBC_SetLastError(LLBC_ERROR_TRUNCATED);
        return LLBC_RTN_FAILED;
    }

    return LLBC_RTN_OK;
}

inline int LLBC_File::Write(const bool &boolVal)
{
    return WriteRawObj<bool>(boolVal);
}

inline int LLBC_File::Write(const sint8 &sint8Val)
{
    return WriteRawObj<sint8>(sint8Val);
}

inline int LLBC_File::Write(const uint8 &uint8Val)
{
    return WriteRawObj<uint8>(uint8Val);
}

inline int LLBC_File::Write(const sint16 &sint16Val)
{
    return WriteRawObj<sint16>(sint16Val);
}

inline int LLBC_File::Write(const uint16 &uint16Val)
{
    return WriteRawObj<uint16>(uint16Val);
}

inline int LLBC_File::Write(const sint32 &sint32Val)
{
    return WriteRawObj<sint32>(sint32Val);
}

inline int LLBC_File::Write(const uint32 &uint32Val)
{
    return WriteRawObj<uint32>(uint32Val);
}

inline int LLBC_File::Write(const sint64 &sint64Val)
{
    return WriteRawObj<sint64>(sint64Val);
}

inline int LLBC_File::Write(const uint64 &uint64Val)
{
    return WriteRawObj<uint64>(uint64Val);
}

inline int LLBC_File::Write(const long &longVal)
{
    return WriteRawObj<long>(longVal);
}

inline int LLBC_File::Write(const LLBC_NS ulong &ulongVal)
{
    return WriteRawObj<LLBC_NS ulong>(ulongVal);
}

inline int LLBC_File::Write(const float &floatVal)
{
    return WriteRawObj<float>(floatVal);
}

inline int LLBC_File::Write(const double &doubleVal)
{
    return WriteRawObj<double>(doubleVal);
}

inline int LLBC_File::Write(const ldouble &ldoubleVal)
{
    return WriteRawObj<ldouble>(ldoubleVal);
}

inline int LLBC_File::Write(const LLBC_String &str)
{
    const long actuallyWrote = Write(str.data(), str.size());
    if (actuallyWrote == -1)
    {
        return LLBC_RTN_FAILED;
    }
    else if (actuallyWrote != static_cast<long>(str.size()))
    {
        LLBC_SetLastError(LLBC_ERROR_TRUNCATED);
        return LLBC_RTN_FAILED;
    }

    return LLBC_RTN_OK;
}

inline int LLBC_File::Write(const LLBC_WString &wstr)
{
    const long actuallyWrote = Write(
        wstr.data(), wstr.size() * sizeof(LLBC_WString::value_type));
    if (actuallyWrote == -1)
    {
        return LLBC_RTN_FAILED;
    }
    else if (actuallyWrote != static_cast<long>(
            wstr.size() * sizeof(LLBC_WString::value_type)))
    {
        LLBC_SetLastError(LLBC_ERROR_TRUNCATED);
        return LLBC_RTN_FAILED;
    }

    return LLBC_RTN_OK;
}

inline int LLBC_File::Write(const std::string &str)
{
    const long actuallyWrote = Write(str.data(), str.size());
    if (actuallyWrote == -1)
    {
        return LLBC_RTN_FAILED;
    }
    else if (actuallyWrote != static_cast<long>(str.size()))
    {
        LLBC_SetLastError(LLBC_ERROR_TRUNCATED);
        return LLBC_RTN_FAILED;
    }

    return LLBC_RTN_OK;
}

inline int LLBC_File::Write(const std::wstring &wstr)
{
    const long actuallyWrote = Write(
        wstr.data(), wstr.size() * sizeof(std::string::value_type));
    if (actuallyWrote == -1)
    {
        return LLBC_RTN_FAILED;
    }
    else if (actuallyWrote != static_cast<long>(
            wstr.size() * sizeof(std::string::value_type)))
    {
        LLBC_SetLastError(LLBC_ERROR_TRUNCATED);
        return LLBC_RTN_FAILED;
    }

    return LLBC_RTN_OK;
}

inline long LLBC_File::WriteLine(const LLBC_String &line, int newLineFormat)
{
    const long contentRet = Write(line.data(), line.size());
    if (contentRet != static_cast<long>(line.size()))
        return contentRet;

    long lineEndingRet = -1;
    if (newLineFormat == LLBC_FileNewLineFormat::AutoMatch)
    {
#if LLBC_TARGET_PLATFORM_WIN32
        lineEndingRet = Write(LLBC_CRLF, 2);
#elif LLBC_TARGET_PLATFORM_IPHONE || LLBC_TARGET_PLATFORM_MAC
        lineEndingRet = Write(LLBC_CR);
#else // Linux, Android, and others
        lineEndingRet = Write(LLBC_LF);
#endif
    }
    else if (newLineFormat == LLBC_FileNewLineFormat::UnixStyle)
    {
        lineEndingRet = Write(LLBC_LF);
    }
    else if (newLineFormat == LLBC_FileNewLineFormat::WindowsStyle)
    {
        lineEndingRet = Write(LLBC_CRLF, 2);
    }
    else
    {
        lineEndingRet = Write(LLBC_CR);
    }

    if (lineEndingRet == -1)
        return lineEndingRet;
    else
        return contentRet + lineEndingRet;
}

template <typename T>
inline int LLBC_File::WriteRawObj(const T &obj)
{
    long actuallyWrote = Write(&obj, sizeof(T));
    if (actuallyWrote == -1)
    {
        return LLBC_RTN_FAILED;
    }
    else if (actuallyWrote != sizeof(T))
    {
        LLBC_SetLastError(LLBC_ERROR_TRUNCATED);
        return LLBC_RTN_FAILED;
    }

    return LLBC_RTN_OK;
}

__LLBC_NS_END

#endif // __LLBC_CORE_FILE_File_H__
