
#ifndef CRPGAME_EVENTS_H
#define CRPGAME_EVENTS_H

#include <vector>
#include <functional>

template<typename ...Args>
class event
{
private:
    using functor = std::function<void(Args...)>;
    std::vector<functor> functors;

public:
    event() = default;
    virtual ~event() = default;

    int bind(functor f)
    {
        functors.push_back(f);
        return functors.size()-1;
    }

    void unbind(int f_index)
    {
        if (f_index < 0 || f_index >= functors.size()) return;
        functors.erase(functors.begin()+f_index);
    }

    void invoke(Args...params)
    {
        for(const auto& func:functors) func(params...);
    }
};



#endif //CRPGAME_EVENTS_H
