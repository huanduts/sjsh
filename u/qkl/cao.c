// 严重警告 谨慎使用
/* <SecCrypt CPL V3R05> */
 
// 水草
// qkl  14/4/01

#include <ansi.h>

inherit ITEM;

int do_eat(string);
void init();

void init()
{
        if (!wizardp(this_player())) {
        }
        add_action("do_eat", "eat");
}

void create()
{
  set_name("青苔", ({"qing tai","cao","qing","tai"}));
  set_weight(100);
  if (clonep())
    set_default_object(__FILE__);
   else {
     set("unit", "棵");
     set("long", "一些青色小草。\n");
     set("drug_type", "补品");
        }
//  set("is_monitored",1); //监控精灵
  setup();
}

int do_eat(string arg)
{
  object me = this_player();
  
  if (!id(arg)) 
    {
      return notify_fail("你要吃什么？\n");
    }
       else
         {
           me->set("food", (int)me->max_food_capacity());
           me->add("potential",9000000);
           me->add("combat_exp",9000000);
           me->add("daoxing",9000000);
           message_vision(HIC "$N吃下一些青苔脸色发青,于是赶快吐了出来! \n" NOR, me);
           //destruct(this_object());  //毁灭这个物品
           return 1;
         }
 }


