
// daxiao.c

#include <ansi.h>

int exert(object me)
{
	int skill;
        skill = (int)me->query_skill("emeiforce",1);

	if (me->query_condition("linji_daxiao"))
                return notify_fail("���Ѿ����˴�С�����ˣ�\n");


	if( me->is_fighting() )
                return notify_fail("ս�����޷��˴�С������\n");

        if( (int)me->query("force") < 500)
		return notify_fail("�������������\n");

        if( (int)me->query("sen") < skill + 100)
                return notify_fail("��ľ��񲻹��˴�С������\n");

        if( (int)me->query_skill("emeiforce",1) < 150)
                return notify_fail("��Ķ����ķ����𲻹���\n");

        if( (int)me->query("kee") < (int)me->query("max_kee") / 2 )
                return notify_fail( "���Ѿ����˹��أ��޷��˹���\n");

	message_vision(
"$N�������������С�������������ɣ�����ֱ͸���ء�������ɫһ���"HIR"��"NOR"��\n"
"һ���"HIC"��"NOR"��һ���ֱ��"HIY"��"NOR"ɫ��������ڻظ�ԭ������ɫ��\n" NOR, me );
	me->apply_condition("linji_daxiao", (int)skill/20);
        me->add("force",  -500);
        me->add("sen", 0 - skill);
        me->add("kee", 2 * skill);
	me->set("linji/jing", skill);
	return 1;
}
