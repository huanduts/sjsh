#include <ansi.h>
inherit ITEM;
int do_eat(string);
void init();
void init()
{
  if (!wizardp(this_player())) {
    set("no_give","这么珍贵的药，哪能随便给人？\n");
    set("no_drop","这么宝贵的丹药，扔了多可惜呀！\n");
    set("no_sell","凡人哪里知道"+this_object()->query("name")+"的价值？还是自己留着吧。\n");
  }
  add_action("do_eat", "eat");
}
void create()
{
  set_name(RED "无敌果" NOR, ({"wudi guo","guo"}));
  set_weight(200);
  if (clonep())
    set_default_object(__FILE__);
  else {
    set("unit", "枚");
    set("long", "一枚采自海中仙山，色红如火的香枣。\n");
    set("value", 0);
    set("drug_type", "补品");
  }
  set("is_monitored",1);
  setup();
}
int do_eat(string arg)
{
  object me = this_player();
  int mana_add, howold;
  howold= (int)me->query("mud_age") + (int)me->query("age_modufy");
  if (!id(arg))
    return notify_fail("你要吃什么？\n");  
  me->set("food", (int)me->max_food_capacity());
  me->set("water", (int)me->max_water_capacity());
  if( howold > 864000 ) {
    me->add("maximum_force", 1000);
    me->add("max_force", 1000);
    me->add("force", 1000);
    me->add("maximum_mana", 1000);
    me->add("max_mana", 1000);
    me->add("max_mana", 1000);
    me->add("mana", 1000);
  message_vision(HIC "$N吃下一颗"NOR+HIR"无敌果"NOR+HIC"，只觉体内血气翻腾，丹田火烫！\n"NOR,me);
  destruct(this_object());
  }
  return 1;
}
