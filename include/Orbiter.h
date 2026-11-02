#pragma once

class Orbiter {
    public:
        /**
         * Creates an orbiter.
         * 
         * @param starting_location the initial location of the Orbiter
         * @param starting_velocity the initial velocity of the Orbiter, {dx, dy}
         * @param center the center to orbit around
         */
        Orbiter(bn::fixed_point starting_location, bn::fixed_point starting_velocity, Center &center);

        /**
         * Take a step orbiting around the center.
         */
        void update();

    private:
        bn::sprite_ptr _sprite;
        bn::fixed_point _velocity;
        Center& _center;
};