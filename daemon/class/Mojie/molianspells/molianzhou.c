#include <ansi.h>

inherit SSERVER;

int cast(object me, object target)
{
	int success_adj, damage_adj;

        success_adj = 180;
        damage_adj = 170;

	if( !target ) target = offensive_target(me);

	if( !target
	||      !target->is_character()
	||      target->is_corpse()
	||      target==me)
		return notify_fail("你要对谁施展魔莲咒？\n");

	if((int)me->query("mana") < 25+2*(int)me->query("mana_factor") )
		return notify_fail("你的法力不够！\n");

	if((int)me->query("sen") < 50 )
		return notify_fail("你无法集中精力瞄准！\n");

	me->add("mana", -25-2*(int)me->query("mana_factor"));
		me->receive_damage("sen", 10);

	if( random(me->query("max_mana")) < 50 ) {
		write("你的咒语好像是念错了！\n");
		return 1;
	}

	SPELL_D->attacking_cast(
		me, 
			//attacker 
		target, 
			//target
		success_adj, 	
			//success adjustment
		damage_adj, 	
			//damage adjustment
		"both", 		
			//damage type: could be "qi"/"kee", "shen"/"sen", ...default "both"
		HIC "$N口中念了几句咒文，随着一声“魔莲咒！”半空中现出一座巨大的魔莲。\n只见魔莲飞速之下，“轰”的一声，向$n当头盖下！\n" NOR,
			//initial message
		HIC "结果砸个正着，差点没把$n盖扁！\n" NOR, 
			//success message
		HIC "但是$n在千钧一发之际跳了开来。\n" NOR, 
			//fail message
        HIC "但是黑莲被$n以法力一引，反而盖到了$N的顶门！\n" NOR,
			//backfire initial message
		HIC "结果砸个正着，差点没把$n压扁！\n" NOR
			//backfire hit message. note here $N and $n!!!
	);

	me->start_busy(1+random(2));
	return 3+random(5);
}

