//yitianjian.c
#include <ansi.h>
#include <weapon.h>

inherit SWORD;

void create()
{
    set_name( HIC "������" NOR, ({ "feiwu jian", "feiwu","jian" }) );
    set_weight(20000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
        	set("unit", "��");
                set("value", 100000);
//        	set("no_drop", "1");
        	set("material", "iron");
                set("long", "���Ƿ���ɱ��ĵ�һ�������С�����ɱ���ǹֲ��֮˵��\n");
        	set("wield_msg","ֱ�������ˮ���������һ�㣬$n����$N���У����Ϊ֮��ɫ��\n");
        	set("unwield_msg", "$N��$n������䣬�����������ؼ�ֻ��������\n");
				set("no_sell",1);
				set("no_drop","ȥ�����Ѷ��ɣ����ӻ���Ⱦ����!\n");
               	}
        init_sword(150);
	setup();
}