#include "Effect.h"

static TexAnim _effect_bomb[] = {
    //{パターン、速度}
            { 0,10 },
            { 1,5 },
            { 2,5 },
            { 3,5 },
};
TexAnimData Effect::_anim_data[] = {
        ANIMDATA(_effect_bomb),
};

Effect::Effect(const CVector2D& pos) :Base(eType_Effect)
{
    m_img.Load("Image/Effect.png", _anim_data, 50, 50);
    m_pos = pos;
    m_img.SetSize(128, 128);
    m_img.SetCenter(64, 64);
    m_img.ChangeAnimation(0, false);

}
void Effect::Update()
{
    m_img.UpdateAnimation();
    if (m_img.CheckAnimationEnd())
        SetKill();

}

void Effect::Draw()
{
    m_img.SetPos(m_pos);
    m_img.Draw();
}