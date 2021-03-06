// feitian-jian.c  飞天剑
// Modified by Cody March.2001
// Write by Cody

#include <ansi.h>

inherit SSERVER;


int perform(object me, object target)
{
        object weapon, ob;
        string msg;

        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail("你要对谁施展这一招「九头龙闪」?\n");

        if( !me->is_fighting() )
            return notify_fail("「九头龙闪」只能在战斗中使用。\n");

        if (!objectp(weapon = me->query_temp("weapon"))
                || (string)weapon->query("skill_type") != "sword")
                        return notify_fail("你使用的武器不对。\n");

        if( environment(me)->query("no_fight") )
                return notify_fail("在这里不能攻击他人。\n");

        if( (int)me->query_skill("feitian-jian",1) < 100 )
                return notify_fail("你的飞天剑等级不够，你怎么能使出「九头龙闪」。\n");

//      if( (int)me->query("combat_exp",1) < 250000 )
//              return notify_fail("你的经验不足，不能使出「九头龙闪」。\n");

        if (me->query("force") < 300)
                return notify_fail("你内力不继，难以使出「九头龙闪」。\n");



        msg = HIG "$N使出飞天御剑流的剑决「九头龙闪」，以神速向九个方向发出攻击！\n\n" NOR;
        message_vision(msg, me);

        me->clean_up_enemy();
        ob = me->select_opponent();

        message_vision(HIW"只见一道剑光直刺向$n。"NOR, me, ob);
        COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 0);

        message_vision(HIW"只见一道剑光直刺向$n。"NOR, me, ob);
        COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 0);

        message_vision(HIW"只见一道剑光直刺向$n。"NOR, me, ob);
        COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 0);

        message_vision(HIW"只见一道剑光直刺向$n。"NOR, me, ob);
        COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 0);

        message_vision(HIW"只见一道剑光直刺向$n。"NOR, me, ob);
        COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 0);

        message_vision(HIW"只见一道剑光直刺向$n。"NOR, me, ob);
        COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 0);

        message_vision(HIW"只见一道剑光直刺向$n。"NOR, me, ob);
        COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 0);

        message_vision(HIW"只见一道剑光直刺向$n。"NOR, me, ob);
        COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 0);

        message_vision(HIW"只见一道剑光直刺向$n。"NOR, me, ob);
        COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 0);

        
        me->add("force", -150);
        me->start_busy(1);



        return 1;  

}
