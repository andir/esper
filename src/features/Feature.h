#ifndef FEATURE_H
#define FEATURE_H

#include "../devices/HassDevice.h"
#include "../util/Log.h"
#include "AbstractFeature.h"

template<const char *TYPE_NAME>
class Feature : public AbstractFeature, public Log<TYPE_NAME> {
protected:
    String name;
    HassDevice &device;
public:

    Feature(HassDevice &device, const char *name) : name(name), device(device) {
    }

    virtual void publish(const String &partial_topic, const String &message) const {
        device.publish(this->getName() + '/' + partial_topic, message);
    }

    virtual void registerSubscription(const String partial_topic, MqttStringSubscriptionCallback cb) {
        device.registerSubscription(this->getName() + "/" + partial_topic, cb);
    }

    virtual void onMqttConnected() {
        publishCurrentState();
        registerSubscriptions();
    }

    virtual void registerSubscriptions() = 0;

    virtual void publishCurrentState() = 0;

    String getName() const {
        return name;
    }

    inline HassDevice &getDevice() const {
        return device;
    }
};

#endif
