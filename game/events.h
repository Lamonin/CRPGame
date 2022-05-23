
#ifndef CRPGAME_EVENTS_H
#define CRPGAME_EVENTS_H

#include <map>
#include <functional>

template<typename ...Args>
class event
{
private:
    using functor = std::function<void(Args...)>;
    std::map<std::string, functor> functors;

public:
    event() = default;
    virtual ~event() = default;

    void bind(const std::string &event_id, const functor &f)
    {
        functors.insert(std::make_pair(event_id, f));
    }

    void unbind(const std::string &event_id)
    {
        functors.erase(event_id);
    }

    void invoke(Args ...params)
    {
        for(const auto& func:functors)
            std::invoke(func.second, params...);
    }
};

#endif //CRPGAME_EVENTS_H
