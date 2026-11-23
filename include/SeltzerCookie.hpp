#ifndef SELTZERCOOKIE_HPP
#define SELTZERCOOKIE_HPP

#include "BackGingerbreadMan.hpp"

class SeltzerCookie final : public BackGingerbreadMan {
public:
    SeltzerCookie();

    bool attacked(int incomingDamage) override;
};

#endif
