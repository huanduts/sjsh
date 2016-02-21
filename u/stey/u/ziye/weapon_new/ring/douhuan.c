// hammer.c
#include <ansi.h>
#include <weapon.h>

inherit UNARMED;

void create()
{
        set_name(HIY "斗神指环" NOR, ({"doushen zhihuan", "ring"}));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "只");
                set("long",
"战神留下来的指环，据说威力很大哦。\n");
                set("value", 0);
                set("material", "diamond");
                set("wield_msg",
"$N戴上一只$n。\n");
                set("unwield_msg", "$N放下手中的$n。\n");
        set("weapon_prop/dodge", 40);
        set("weapon_prop/unarmed", 40);
        }

        init_unarmed(10);
        setup();
}
mixed hit_ob(object me, object victim)
{
    int dam = 0;

    if( (string)me->query("class") == "fighter"
)
    dam = me->query_skill("unarmed");
    dam = (dam+random(dam))/2;

    victim->receive_damage("kee",dam);
    victim->receive_wound("kee",dam/2);
}

