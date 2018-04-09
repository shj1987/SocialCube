#ifndef __SIMULATOR_WORKER__
#define __SIMULATOR_WORKER__

#include <thread>
#include <mutex>
#include <condition_variable>
#include <memory>
#include <queue>

#include "Simulator/Community.hpp"
#include "EventManager/EventManager.hpp"
#include "SimulatorWorkerManager/SimulatorWorkerManager.hpp"
#include "common/Workload.hpp"

class SimulatorWorkerManager;

class SimulatorWorker {
    private:
        // member variables 
        SimulatorWorkerManager& manager;

        std::thread* m_thread;

        const unsigned m_workerID;

        std::shared_ptr<std::condition_variable> m_cv;

        // member functions
        Workload fetchWorkload(unsigned wid) const;

        void notifyWorkerManager() const;

        // class functions
        static bool workloadAvailable(unsigned wid);

        static void SimulatorWorkerImpl(SimulatorWorker const * ptr);

        static void simulate(Workload& t_workload);
        
    public:
        SimulatorWorker(unsigned t_workerID, std::shared_ptr<std::condition_variable> t_cv);

        ~SimulatorWorker();

        unsigned getWorkerID() const;
};

#endif