// created 17-06-2001 ����Ʈ(piao)

#include <weapon.h>


inherit SWORD;

void create()
{
	set_name("Сľ��", ({"sword"}) );
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ������������÷����������Сľ��\n");
		set("value", 400);
		set("material", "steel");
		set("wield_msg", "$N��ৡ���һ�����һ��$n�������С�\n");
		set("unwield_msg", "$N�����е�$n��������Ľ��ʡ�\n");
	}
	init_sword(45);
	setup();
}