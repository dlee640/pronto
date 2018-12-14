#pragma once
#include "pronto_estimator_core/definitions.hpp"
#include "pronto_estimator_core/sensing_module.hpp"
namespace MavStateEst {

class IndexedMeasurementModule : public SensingModule<IndexedMeasurement> {
public:
    IndexedMeasurementModule(const RBISUpdateInterface::sensor_enum& sensor);
    RBISUpdateInterface* processMessage(const IndexedMeasurement *msg, MavStateEstimator *est) override;

    bool processMessageInit(const IndexedMeasurement *msg,
                            const std::map<std::string, bool> &sensor_initialized,
                            const RBIS &default_state,
                            const RBIM &default_cov,
                            RBIS &init_state,
                            RBIM &init_cov) override;
protected:
    RBISUpdateInterface::sensor_enum indexed_sensor;

};

} // namespace MavStateEst
