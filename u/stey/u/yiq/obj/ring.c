#include <armor.h>

#include <ansi.h>
inherit FINGER;

void create()
{
  set_name(HIG"结婚钻指"NOR, ({ "zuan jie", "zuanjie", "ring" }));
  set("long","慈航道人和无缘结婚纪念"+"。\n");
  set("weight", 0);
                set("armor_prop/armor", 5);
  if (clonep())
    set_default_object(__FILE__);
  else {
    set("unit", "枚");
    set("value", 12000);
    set("material", "diamond");
    set("armor_prop/armor", 1);
    set("armor_prop/personality", 10);
  }
  setup();
}       
int query_autoload() { return 1; }
