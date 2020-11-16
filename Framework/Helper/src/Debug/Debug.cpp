//
// Created by Nikita on 16.11.2020.
//

#include "Debug/Debug.h"
#include "FileSystem/FileSystem.h"
#include "Types/Memory.h"

void Framework::Helper::Debug::Print(std::string &msg, Framework::Helper::Debug::Type type) {
    m_mutex.lock();

    static std::string pref		= "";
    static ConsoleColor color	= ConsoleColor::Black;

    switch (type) {
        case Debug::Type::Log:		pref = "[Log] ";	color = ConsoleColor::Cyan;				break;
        case Debug::Type::Info:	    pref = "[Info] ";	color = ConsoleColor::Magenta;			break;
        case Debug::Type::Debug:	pref = "[Debug] ";	color = ConsoleColor::Blue;				break;
        case Debug::Type::Graph:	pref = "[Graph] ";	color = ConsoleColor::Green;			break;
        case Debug::Type::Shader:	pref = "[Shader] ";	color = ConsoleColor::LightCyan;		break;
        case Debug::Type::Script:	pref = "[Script] ";	color = ConsoleColor::Brown;			break;
        case Debug::Type::System:	pref = "[System] ";	color = ConsoleColor::LightBlue;		break;
        case Debug::Type::Warn:	    pref = "[Warn] ";	color = ConsoleColor::Yellow;			break;
        case Debug::Type::Error:	pref = "[Error] ";	color = ConsoleColor::LightRed;			break;
        default:					pref = "[Unk] ";	color = ConsoleColor::Black;			break;
    }

    if (Debug::m_show_use_memory) {
        std::cout << '<' << Memory::GetUsedMemoryLoad() / 1024.f << " KB> ";
        if (m_file.is_open())
            m_file << '<' << Memory::GetUsedMemoryLoad() / 1024.f << " KB> ";
    }

    SetConsoleTextAttribute(Debug::m_console, (WORD)(((int)ConsoleColor::LightGray << 4) | (int)color));
    std::cout << pref;
    if (m_file.is_open())
        m_file << pref;
    SetConsoleTextAttribute(Debug::m_console, (WORD)(((int)ConsoleColor::LightGray << 4) | (int)ConsoleColor::Black));

    std::cout << msg << std::endl;
    if (m_file.is_open())
        m_file << msg << std::endl;

    m_mutex.unlock();
}

void Framework::Helper::Debug::Init(std::string log_path, bool ShowUsedMemory) {
    setlocale(LC_ALL, "rus");
    setlocale(LC_NUMERIC, "C");

    InitColorTherme();

    m_log_path = log_path + "/log.txt";
    if (FileSystem::FileExists(m_log_path))
        FileSystem::Delete(m_log_path);
    m_file.open(m_log_path);

    m_console = GetStdHandle(STD_OUTPUT_HANDLE);

    m_isInit = true;
    m_show_use_memory = ShowUsedMemory;

    std::string msg = "Debugger has been initialized.";
    Print(msg, Type::Debug);
}
