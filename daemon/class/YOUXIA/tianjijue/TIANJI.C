// jushu.c
#include <ansi.h>

inherit SSERVER;

int cast(object me, object target)
{
	int success_adj, damage_adj;

	success_adj = 150;
	damage_adj = 140;

	if( !target ) target = offensive_target(me);

	if( !target
	||      !target->is_character()
	||      target->is_corpse()
	||      target==me)
                return notify_fail("��Ҫ��˭ʩչ��"HIY"�����"NOR"����\n");

	if((int)me->query("mana") < 25+2*(int)me->query("mana_factor") )
                return notify_fail(HIR "��ķ���������ʩչ����䣡\n");

        if((int)me->query("sen") < 200 )
                return notify_fail(HIR "���޷����о������޷�ʩչ����䣡\n");

	me->add("mana", -25-2*(int)me->query("mana_factor"));
        me->receive_damage("sen", 100);

	if( random(me->query("max_mana")) < 50 ) {
                write(HIC "����������ˣ�û��ʩչ������䣡\n");
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
                HIY "$N�����૵��������ģ�����һ���Ϲ⽥�������鶯�ޱȣ�
ֻ��$N���һ��������䣡������������������$n��\n" NOR,
			//initial message
                HIY "\n$n����Ŀ�����Ѫ�������ڵأ�\n" NOR, 
			//success message
                HIY "����$n��������һ����ʲôҲû�������Ƶġ�\n" NOR, 
			//fail message
                HIR "���ı�$n�Է���һ������������$N�Ķ����\n" NOR, 
			//backfire initial message
                HIR "\n$n����Ŀ�����Ѫ�������ڵأ�\n" NOR, 
			//backfire hit message. note here $N and $n!!!
	);

	me->start_busy(1+random(0));
	return 1+random(2);
}
