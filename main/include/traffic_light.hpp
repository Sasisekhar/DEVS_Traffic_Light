#ifndef TRAFFIC_HPP
#define TRAFFIC_HPP

#include <iostream>
#include "cadmium/modeling/devs/atomic.hpp"
#include "RGB.hpp"

using namespace cadmium;

struct traffic_lightState {
    RGB signal;

    explicit traffic_lightState(): signal(0, 0, 0) {
    }
};

#ifndef NO_LOGGING
std::ostream& operator<<(std::ostream &out, const traffic_lightState& state) {
    out  << "Next State = " << state.signal;
    return out;
}
#endif

class traffic_light : public Atomic<traffic_lightState> {
    private:
        const RGB R;
        const RGB Y;
        const RGB G;
    public:
    Port<RGB> out;

    traffic_light(const std::string id) :   Atomic<traffic_lightState>(id, traffic_lightState()), 
                                            R(32, 0, 0),  
                                            Y(32, 16, 0),
                                            G(0, 32, 0) {
        out = addOutPort<RGB>("out");
    }

    void internalTransition(traffic_lightState& state) const override {
        if(state.signal == R) {
            state.signal = G;
        } else if(state.signal == Y) {
            state.signal = R;
        } else if(state.signal == G) {
            state.signal = Y;
        } else {
            state.signal = R; // handles illegal conditions
        }
    }

    // external transition
    void externalTransition(traffic_lightState& state, double e) const override {
        //Nothing should happen here
    }
    
    
    // output function
    void output(const traffic_lightState& state) const override {
        out->addMessage(state.signal);
    }

    // time_advance function
    [[nodiscard]] double timeAdvance(const traffic_lightState& state) const override {
        if(state.signal == R) {
            return 10;
        } else if(state.signal == Y) {
            return 2;
        } else if(state.signal == G) {
            return 10;
        }

        return 0.1; // handles illegal conditions
    }
};

#endif