//Cracked by Roath
#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
        string msg;
        int extra,i,lmt;
        object weapon;
        extra = me->query_skill("zui-gun",1);
        if ( extra < 100) return notify_fail("你的少林醉棍还不够娴熟，无法施展「"HIB"醉罗汉"NOR"」！\n");
        extra = me->query_skill("yijinjing",1);
        if ( extra < 80) return notify_fail("你的易筋经神功还不够娴熟，无法发挥少林醉棍的威力！\n");
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("「"HIB"醉罗汉"NOR"」只能对战斗中的对手使用。\n");

        if(me->query("family/family_name")!="少林寺")
  return notify_fail("「"HIB"醉罗汉"NOR"」是少林寺的不传之秘，外人哪里能够领悟。\n");;

        weapon = me->query_temp("weapon");
        msg = YEL "$N酒劲大发，手中的"+ weapon->name()+  ""YEL"狂风暴雨般地向$n"YEL"袭来！"NOR"" NOR;
        message_vision(msg,me,target);
        me->add_temp("apply/attack",extra/10);
        me->add_temp("apply/damage",extra/10);
        lmt = random(5)+3;
        for(i=1;i<=lmt;i++)
        {
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        }
        me->add_temp("apply/attack",-extra/10);
        me->add_temp("apply/damage",-extra/10);
        me->start_busy(2+random(1));
        return 1;
}
