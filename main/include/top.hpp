#ifndef SASI_TOP_HPP
#define SASI_TOP_HPP

#include "cadmium/modeling/devs/coupled.hpp"
#include "traffic_light.hpp"
#include "led_output.hpp"
#include "RGB.hpp"

namespace cadmium::comms::example {
    struct topSystem : public Coupled {

            Port<RGB> in;
            /**
             * Constructor function for the blinkySystem model.
             * @param id ID of the blinkySystem model.
             */
            topSystem(const std::string& id) : Coupled(id) {
                in = addInPort<RGB>("in");
                auto atomic_1 = addComponent<traffic_light>("traffic_light");
                auto atomic_2 = addComponent<led_output>("led_output");

                addCoupling(in, atomic_2->in);
            }
        };
}

#endif