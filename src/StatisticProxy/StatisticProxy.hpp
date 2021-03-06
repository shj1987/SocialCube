#ifndef __STATISTIC_PROXY__
#define __STATISTIC_PROXY__

#include <vector>
#include <string>
#include <unordered_map>
#include <cstdlib>
#include <memory>
#include "Dependency/HourlyActionRate.hpp"
#include "Dependency/ObjectPreference.hpp"
#include "StatisticProxy/UserIDProxy/UserIDProxy.hpp"
#include "StatisticProxy/UserIDProxy/ClusteredUserIDProxy.hpp"
#include "StatisticProxy/ObjectIDProxy/ObjectIDProxy.hpp"
#include "StatisticProxy/ObjectPreferenceProxy/ObjectPreferenceProxy.hpp"
#include "StatisticProxy/HourlyActionRateProxy/HourlyActionRateProxy.hpp"
#include "StatisticProxy/TypeDistributionProxy/TypeDistributionProxy.hpp"

class StatisticProxy {
    private:
        std::string m_defaultUserIDProxyFile;
        std::string m_defaultObjectIDProxyFile;
        std::string m_defaultObjectPreferenceProxyFile;
        std::string m_defaultHourlyActionRateProxyFile;
        std::string m_defaultTypeDistributionProxyFile;

    private:
        std::unique_ptr<UserIDProxy> m_userIDProxy;
        std::unique_ptr<ObjectIDProxy> m_objectIDProxy;
        std::unique_ptr<ObjectPreferenceProxy> m_objectPreferenceProxy;
        std::unique_ptr<HourlyActionRateProxy> m_hourlyActionRateProxy;
        std::unique_ptr<TypeDistributionProxy> m_typeDistributionProxy;

        // Private member functions
        StatisticProxy();

        void initProxySourceFile();
        

    public:

        ~StatisticProxy();
        
        static StatisticProxy& getInstance();

        void retrieveStatistics();

        std::vector<std::string>& getUserIDs() const;

        std::vector<std::string>& getObjectIDs() const; 

        HourlyActionRate& getUserHourlyActionRate(const std::string &userID) const;

        ObjectPreference& getUserObjectPreference(const std::string &userID) const; 

        TypeDistribution& getUserTypeDistribution(const std::string &userID) const; 

        uint64_t getUserCommunityTag(const std::string &userID) const; 
};

#endif
