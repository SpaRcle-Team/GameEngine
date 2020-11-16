//
// Created by Nikita on 16.11.2020.
//

#ifndef GAME_DEBUG_H
#define GAME_DEBUG_H

#include <fstream>
#include <ostream>
#include <mutex>
#include "Types/Memory.h"

namespace Framework {
    namespace Helper {
        class Debug {

        public:
            enum class Level {
                None = 0, Low = 1, Medium = 2, High = 3, Full = 4
            };

            enum class ConsoleColor {
                Black = 0,
                Blue = 1,
                Green = 2,
                Cyan = 3,
                Red = 4,
                Magenta = 5,
                Brown = 6,
                LightGray = 7,
                DarkGray = 8,
                LightBlue = 9,
                LightGreen = 10,
                LightCyan = 11,
                LightRed = 12,
                LightMagenta = 13,
                Yellow = 14,
                White = 15
            };
            enum class Type {
                Log, Info, Debug, Graph, Shader, Script, System, Warn, Error
            };
        private:
            Debug() { };
            ~Debug() { };
        private:
            inline static std::mutex	m_mutex						= std::mutex();
            inline static HANDLE		m_console					= nullptr;
            inline static bool			m_show_use_memory			= false;
            inline static bool			m_ColorThermeIsEnabled		= false;
            inline static volatile bool m_isInit					= false;
            inline static std::string	m_log_path					= "";
            inline static std::ofstream m_file						= std::ofstream();
        private:
            static inline Level			m_level						= Level::Low;
            static inline void InitColorTherme() {
                if (!m_ColorThermeIsEnabled)
                    system("color 70");
                m_ColorThermeIsEnabled = true;
            }
            static void Print(std::string& msg, Type type);
        public:
            static const Level GetLevel() { return m_level; }
            static void Init(std::string log_path, bool ShowUsedMemory);
            static int Stop() {
                std::string msg = "Debugger has been stopped.";
                Print(msg, Type::Debug);
                m_file.close();

                return 0;
            }
        public:
            static void Log(std::string msg)		{ Print(msg, Type::Log);		}
            static void Info(std::string msg)		{ Print(msg, Type::Info);		}
            static void Graph(std::string msg)		{ Print(msg, Type::Graph);		}
            static void Shader(std::string msg)		{ Print(msg, Type::Shader);		}
            static void Script(std::string msg)		{ Print(msg, Type::Script);		}
            static void System(std::string msg)		{ Print(msg, Type::System);		}
            static void Warn(std::string msg)		{ Print(msg, Type::Warn);		}
            static void Error(std::string msg)		{ Print(msg, Type::Error);		}
        };
    }
}

#endif //GAME_DEBUG_H
