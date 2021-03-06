// shendao.c stey 血刀「祭血神刀」

#include <ansi.h>

inherit SSERVER;
int perform(object me, object target)
{
    int damage;
    string msg;
    object weapon;

    if (!target ) target = offensive_target(me);
    if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "blade")
        return notify_fail(RED"装备刀才能使用「枯骨祭血神刀」？\n"NOR);
    if (!target || !target->is_character() || !me->is_fighting(target) )
        return notify_fail("「枯骨祭血神刀」只能对战斗中的对手使用。\n");
    if ((int)me->query_skill("kugu-blade", 1) < 100 )
        return notify_fail(WHT"你枯骨刀刀法不够娴熟，使不出「枯骨祭血神刀」。\n"NOR);
    if ((int)me->query_skill("huntian-qigong", 1) < 100 )
        return notify_fail(RED"你混天气功火候不够，使不出「枯骨祭血神刀」。\n"NOR);
    if ((int)me->query("max_force") < 600)
        return notify_fail(RED"你内力修为不足，无法运足内力。\n"NOR);
    if ((int)me->query("force") < 600)
    {
        return notify_fail(HIC"你现在内力不够，没能将「枯骨祭血神刀」使完！\n"NOR);
    }
    msg = HIC "$N右手持刀向左肩一勒，一阵血珠溅满刀面，紧接着右臂抡出，一片血光
裹住刀影向$n当头劈落，\n"NOR;
    if ( random(me->query("combat_exp")) > (int)target->query("combat_exp")/10 )
    {
        damage = random((int)(me->query("sen")/20))+(int)(me->query("sen")/50);
        me->add("force", -300);
        me->receive_wound("kee", me->query("kee")/20);
        me->start_busy(1);
        target->start_busy(random(3));
        target->receive_damage("kee", damage);
        target->receive_wound("kee", damage/2);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
msg += HIC"$n疾忙侧身避让，但血刀疾闪，只觉眼前一阵血红，刀刃劈面而下，鲜血飞
溅，惨声大嚎！\n"NOR;
    } else
    {
        me->start_busy(2);
        me->receive_wound("kee", me->query("kee")/20);
msg += HIY"可是$n侧身避让，不荒不忙，躲过了$N的血刀。\n"NOR;
        me->add("force", -200);
    }
    message_vision(msg, me, target);
    if(!target->is_fighting(me)) target->fight_ob(me);
    return 1;
}
