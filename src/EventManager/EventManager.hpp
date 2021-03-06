#ifndef __EVENT_MANAGER__
#define __EVENT_MANAGER__

#include <fstream>
#include <string>
#include <vector>
#include <memory>
#include <cstdlib>


#include "SimulatorProfiler/SimulatorProfiler.hpp"
#include "common/Event.hpp"
#include "Log/Log.hpp"

class EventManager {
    private:
        // Private member variables
        
        std::vector<std::unique_ptr<Event>> m_events;

        uint64_t m_eventCount;

        uint64_t m_bufferSize;

        std::string m_eventFileName;

        std::ofstream m_eventFile; 

        bool m_eventOn;

        // Private member functions

        void emitEventOnBufferFull();

        void emitEvent();

        void _emitEvent();

        EventManager();

    public:
        static EventManager& getInstance();

        ~EventManager() = default;

        void setEventShow(bool t_eventOn); 

        void setEventFileName(const std::string& t_file);

        void setEventBufferSize(uint64_t t_bufferSize);

        void start();

        void end();

        uint64_t getEventCount();

        void storeEvent(std::vector<std::unique_ptr<Event>>& events);
};

#endif
