#include "sdl_msm.hpp"

struct button_clicked
{
    static const int id = SDL_MOUSEBUTTONUP;

    explicit button_clicked(const SDL_Event& event)
        : x(event.button.x), y(event.button.y)
    { }

    int x = 0;
    int y = 0;
};

struct time_click
{
    static const int id = __LINE__;
};

class controller : public state_machine_def<controller>
{
    struct idle    : state<>, euml_state<idle> { };
    struct clicked : state<>, euml_state<clicked> { };

public:
    typedef vector<idle, timeout> initial_state;

    BOOST_MSM_EUML_DECLARE_TRANSITION_TABLE((
        clicked()  == idle()    + button_clicked()
        idle()     == clicked() + time_click()
    ), transition_table);
};

typedef sdl::msm<controller> controller_t;

int main() {
    controller_t controller_;

    sdl::timer timer(
        1000 // time in milliseconds
      , [&](sdl::milliseconds_t interval) {
            controller_.process_event(time_tick());
            return 0; // non periodic
        }
    );

    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        controller_.process_event(event);
    }

    return 0;
}

