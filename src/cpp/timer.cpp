#include <cassert>
#include <functional>
#include "SDL.h"

typedef Uint32 milliseconds_t;

class timer
{
    typedef std::function<Uint32(Uint32)> callback_t;

public:
    timer(milliseconds_t time, const callback_t& callback)
        : callback_(callback)
    {
        id_ = SDL_AddTimer(time, &timer::do_callback, &callback_);
    }

    ~timer() {
        assert(SDL_RemoveTimer(id_));
    }

private:
    static Uint32 do_callback(Uint32 interval, void* data) {
        return (*static_cast<callback_t*>(data))(interval);
    }

    callback_t callback_;
    SDL_TimerID id_;
};

int main() {
    timer t(100, [](Uint32 interval){ return interval; });
    return 0;
}

