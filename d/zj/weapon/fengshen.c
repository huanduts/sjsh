// 封神法杖 by Calvin

#include <ansi.h>
#include <weapon.h>
inherit STAFF;
void create()
{
          set_name(HIY"封神法杖"NOR, ({"fengshen fazhang", "fazhang", "zhang", "staff"}) );
        set_weight(10000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "条");
                set("long", "一条精致的小法杖,上面刻有无数佛像,是得封封官封神时使用的。\n");
           set("replace_file", "/d/nanhai/obj/budd_staff");
           set("weapon_prop/strength", 10);
                set("value", 10000000);
                set("material", "brass");
                set("no_sell", "1");
                set("wield_msg", "忽然天界雷声隆隆,原来是$N拿出一根五彩毫光的$n握在了手中。\n");
                set("unwield_msg", "$N放下手中的$n。\n");
        }
        init_staff(100);
        setup();
}
