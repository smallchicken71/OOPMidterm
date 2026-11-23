#include "GingerbreadGroup.hpp"

#include <algorithm>
#include <stdexcept>

GingerbreadGroup::GingerbreadGroup(int maxSize)
    : maxSize(maxSize) {
    if (maxSize < 3 || maxSize > 9) {
        throw std::invalid_argument("Team capacity must be between 3 and 9");
    }
}

std::vector<int> GingerbreadGroup::attack(std::vector<Element>& types) {
    std::vector<int> damages(types.size(), 0);

    if (queue.empty()) {
        return damages;
    }

    GingerbreadMan& attacker = queue[currIndex];
    std::vector<Position> positions = attacker.getInteractPositions();
    std::size_t unit = types.size() / 3;

    for (std::size_t i = 0; i < types.size(); ++i) {
        Position targetPosition = Position::Back;

        if (i < unit) {
            targetPosition = Position::Front;
        } else if (i < 2 * unit) {
            targetPosition = Position::Middle;
        }

        if (types.size() < 3 ||
            std::find(positions.begin(), positions.end(), targetPosition) != positions.end()) {
            damages[i] = attacker.attack(types[i]);
        }
    }

    currIndex = (currIndex + 1) % queue.size();
    return damages;
}

void GingerbreadGroup::attacked(std::vector<float>& damages) {
    if (damages.size() != queue.size()) {
        throw std::invalid_argument("Damage count must match team size");
    }

    for (std::size_t i = 0; i < queue.size(); ++i) {
        int incomingDamage = int(damages[i]);
        queue[i].attacked(incomingDamage);
    }

    removeDeadGingerbreadMan();
}

void GingerbreadGroup::addGingerbreadMan(const GingerbreadMan& gingerbreadMan) {
    Position position = gingerbreadMan.getPosition();
    int capacity = maxSize / 3;

    if (position == Position::Back) {
        capacity = maxSize - 2 * capacity;
    }

    int count = 0;

    for (const GingerbreadMan& member : queue) {
        if (member.getName() == gingerbreadMan.getName()) {
            throw std::invalid_argument("Duplicate member name");
        }

        if (member.getPosition() == position) {
            ++count;
        }
    }

    if (count >= capacity) {
        throw std::invalid_argument("Position is full");
    }

    queue.push_back(gingerbreadMan);
}

void GingerbreadGroup::replaceGingerbreadMan(
    int index, const GingerbreadMan& gingerbreadMan) {
    checkIndex(index);

    if (queue[index].getPosition() != gingerbreadMan.getPosition()) {
        throw std::invalid_argument("Replacement must have the same position");
    }

    for (int i = 0; i < int(queue.size()); ++i) {
        if (i != index && queue[i].getName() == gingerbreadMan.getName()) {
            throw std::invalid_argument("Duplicate member name");
        }
    }

    queue[index] = gingerbreadMan;
}

void GingerbreadGroup::sortByHealth() {
    std::stable_sort(queue.begin(), queue.end(),
        [](const GingerbreadMan& left, const GingerbreadMan& right) {
            return left.getHealth() > right.getHealth();
        });
}

void GingerbreadGroup::sortByDamage() {
    std::stable_sort(queue.begin(), queue.end(),
        [](const GingerbreadMan& left, const GingerbreadMan& right) {
            return left.getDamage() > right.getDamage();
        });
}

void GingerbreadGroup::sortByDefense() {
    std::stable_sort(queue.begin(), queue.end(),
        [](const GingerbreadMan& left, const GingerbreadMan& right) {
            return left.getDefense() > right.getDefense();
        });
}

int GingerbreadGroup::countCombatPower() {
    int total = 0;

    for (const GingerbreadMan& member : queue) {
        total += member.getHealth() + member.getDefense() + member.getDamage();
    }

    return total;
}

void GingerbreadGroup::removeDeadGingerbreadMan() {
    queue.erase(std::remove_if(queue.begin(), queue.end(),
        [](const GingerbreadMan& member) {
            return member.getCurrHealth() <= 0;
        }), queue.end());

    resetIndexIfNeeded();
}

void GingerbreadGroup::removeGingerbreadMan(std::string name) {
    auto member = std::find_if(queue.begin(), queue.end(),
        [&name](const GingerbreadMan& candidate) {
            return candidate.getName() == name;
        });

    if (member != queue.end()) {
        queue.erase(member);
        resetIndexIfNeeded();
    }
}

void GingerbreadGroup::removeGingerbreadMan(Element element) {
    queue.erase(std::remove_if(queue.begin(), queue.end(),
        [element](const GingerbreadMan& member) {
            return member.getElementType() == element;
        }), queue.end());

    resetIndexIfNeeded();
}

GingerbreadMan GingerbreadGroup::getGingerbreadMan(int index) {
    checkIndex(index);
    return queue[index];
}

void GingerbreadGroup::checkIndex(int index) const {
    if (index < 0 || index >= int(queue.size())) {
        throw std::out_of_range("Member index is out of range");
    }
}

void GingerbreadGroup::resetIndexIfNeeded() {
    if (currIndex >= queue.size()) {
        currIndex = 0;
    }
}