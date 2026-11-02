#include <bn_core.h>
#include <bn_backdrop.h>
#include <bn_color.h>
#include <bn_keypad.h>
#include <bn_fixed_point.h>
#include <bn_sprite_ptr.h>
#include <bn_vector.h>

#include "bn_sprite_items_dot.h"
#include "bn_sprite_items_square.h"

#include "movement.h"
#include "Center.h"
#include "Orbiter.h"

// Maximum number of orbiters allowed on the screen
static constexpr int MAX_ORBITERS = 30;

// Default starting posiiton and velocity for Orbiter
bn::fixed_point ORBITER_START_POSIITON = {0, 0};
bn::fixed_point ORBITER_START_VELOCITY = {0, 5};


/**
 * An object that orbits around a center. Orbits using Hooke's law, as if attached by a 2D spring.
 * The stiffness of the spring in each dimension is center.mass() / FORCE_SCALE. 
 */

int main() {
    bn::core::init();

    Center center = Center({30, 40}, .05, 2);
    bn::vector<Orbiter, MAX_ORBITERS> orbiters = {};
    
    while(true) {
        // Add an orbiter when A is pressed if there's room
        if(bn::keypad::a_pressed()) {
    if(orbiters.size() < MAX_ORBITERS) {
        bn::fixed_point left_pos = {-80, 0}; 
        bn::fixed_point left_vel = {2, 0};  
        orbiters.push_back(Orbiter(left_pos, left_vel, center));
    }
}

        // Remove an orbiter when B is pressed if there's at least one
        if (bn::keypad::b_pressed()) {
            if(orbiters.size() < MAX_ORBITERS) {
                bn::fixed_point right_pos = {80, 0}; 
                bn::fixed_point right_vel = {-2, 0};  
                orbiters.push_back(Orbiter(right_pos, right_vel, center));
            }
        }

        if (bn::keypad::start_pressed()) {
            orbiters.clear();
        }

        center.update();
        for(Orbiter& orbiter : orbiters) {
            orbiter.update();
        }

        bn::core::update();
    }
}