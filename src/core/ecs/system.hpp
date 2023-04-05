#pragma once

class System
{
public:
    virtual void OnInitialized() = 0;
    virtual void OnUpdate() = 0;
    virtual void OnDestroy() = 0;

    // Set the larger order to get system sooner executed
    inline void SetOrder(int order) { m_order = order; }
    inline int GetOrder() { return 0; }
    inline void Enable() { m_enable = true; }
    inline void Disable() { m_enable = false; }

    bool operator<(const System& other)
    {
        return m_order < other.m_order;
    }

private:
    int m_order = 0;
    bool m_enable = true;
};
