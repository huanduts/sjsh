// shoes.c

#include <armor.h>
#include <ansi.h>

inherit BOOTS;


void create()
{
        set_name(HIW "��������" NOR, ({ "shoes" }) );
	set_weight(900);
	if( clonep() )
		set_default_object(__FILE__);
	else {
                set("long", "һ˫����ɽ���Ӵ���Ь��  \n");
		set("material", "cloth");
		set("unit", "˫");
                set("value", 30000);
                set("armor_prop/armor", 50 );
                set("female_only", 10);
                set("armor_prop/dodge", 20 );
        }
	setup();
}
//int query_autoload() { return 1; }

