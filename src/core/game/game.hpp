#pragma once

class Game
{
public:
    void OnInitialized();
    void OnUpdate();
    void OnDestroy();

    bool IsEnd();
};
