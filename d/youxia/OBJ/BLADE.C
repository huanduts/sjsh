// ��ս����  baizhan.c        created 17-06-2001 ����Ʈ(piao)


#include <weapon.h>
#include <ansi.h>


inherit BLADE;

void create()
{
        set_name(CYN"��ս����"NOR, ({ "baizhen blade", "blade", "baizhan" }) );
        set_weight(1500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "һ���ɸ����Ƴɵı������������С���ս�����֡�\n");
                set("unit", "��");
	    set("wield_msg", "$N���һ��$n���������У���ʱ�������ݡ�\n");
	    set("unwield_msg", "$N��������$n����Ȼ�������ݡ�\n");
                set("value", 40000);
                set("material","wood");
        }
        init_blade(160);
        setup();
}
