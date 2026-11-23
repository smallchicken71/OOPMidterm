#ifndef SILVERBELLCOOKIE_HPP
#define SILVERBELLCOOKIE_HPP

#include "BackGingerbreadMan.hpp"

class SilverbellCookie final : public BackGingerbreadMan {
public:
    SilverbellCookie();

    void levelUp() override;
    bool attacked(int incomingDamage) override;

};

#endif
