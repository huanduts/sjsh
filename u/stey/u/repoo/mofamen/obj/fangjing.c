//copy from fangjing by repoo

#include <ansi.h>
inherit ITEM;

void create()
{
  set_name(HIW"方晶"NOR, ({"fang jing","jing","shuijing"}));
  set_weight(1000);
  if (clonep())
    set_default_object(__FILE__);
  else {
    set("long", "一快正方形的水晶石。\n");
    set("unit", "快");
    set("material", "stone");
     }
  setup();
}
