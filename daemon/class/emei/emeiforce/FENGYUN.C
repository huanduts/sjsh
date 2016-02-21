
// fengyun.c

#include <ansi.h>

int exert(object me)
{
	int skill;
        skill = (int)me->query_skill("emeiforce",1);

	if (me->query_condition("linji_fengyun"))
		return notify_fail("���Ѿ����˷���ׯ�ˣ�\n");


	if( me->is_fighting() )
		return notify_fail("ս�����޷��˷���ׯ��\n");

        if( (int)me->query("force") < 400)
		return notify_fail("�������������\n");

        if( (int)me->query_skill("emeiforce",1) < 120)
                return notify_fail("��Ķ����ķ����𲻹���\n");

        if( (int)me->query("sen") < (int)me->query("max_sen") / 2 )
                return notify_fail( "���Ѿ����˹��أ��޷��˹���\n");

	message_vision(
HIC "$N���������������ׯ�������������˵�����ӿȪѨ��....\n"
"����������һ��ů�������ӿ��ӿ���ϣ���ʱ�����������࣬ԾԾ���ɡ�\n" NOR, me );
	me->apply_condition("linji_fengyun", (int)skill/20);
        me->add("force", -400);
        me->add("sen", -20);
	me->add("dex", (int)skill/20);
	me->set("linji/dex", (int)skill/30);
	return 1;
}
