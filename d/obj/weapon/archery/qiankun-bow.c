#include <weapon.h>

inherit BOW;

void create()
{
        set_name("乾坤弓", ({"qiankun gong", "qiankungong", "bow", "gong", "qiankun"}));
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
		set("long", "乾坤弓乃是陈唐关总兵李靖的镇关之宝。后因李靖结交\n虬髯客被疑而调入京城，也被李靖带来了。\n");
                set("unit", "张");
		set("value", 30000);
                set("wield_msg", "$N抓起一张$n，握在手中当武器。\n");
                set("material", "steel");
                set("anqi/allow", 1);
                set("anqi/max", 9);
                set("anqi/now", 0);
        }

init_bow(1);
        setup();

}
void init()
{
        add_action("do_install", "install");
        add_action("do_uninstall", "uninstall");
}

int do_install(string arg)
  {
   object me=this_object();
   object who=this_player();
   object aq;
   int remain;

   if( !arg)  return notify_fail("你想装什么？\n");

   aq=present(arg, who);
   if (! present(arg, who)) 
        return notify_fail("你身上没有这东西。\n");
   else if (aq->query("name") == me->query("name") ) return notify_fail("装什么？\n");
     else if (aq->query("name") != "震天箭") 
        return notify_fail("这玩艺装不进去。\n");
   else if (me->query("anqi/now") == me->query("anqi/max"))
        return notify_fail(me->query("name")+"已经装满震天箭了。\n");
   else if (me->query("anqi/now") >0 && 
            me->query("anqi/type") != aq->query("name") )
        return notify_fail(me->query("name")+"不能装不同的东西。\n");
   else  
     {
     message_vision( "$N打开"+me->query("name")+"的机关，将一"+aq->query("unit")+aq->query("name")+"装了进去。\n",who);
     who->start_busy(1);
     if (me->query("anqi/now") ==0) me->set("anqi/type",aq->query("name"));
     if (me->query("anqi/now") + aq->query_amount() > me->query("anqi/max")) 
         {
         remain=me->query("anqi/now") + aq->query_amount() - me->query("anqi/max");
         me->set("anqi/now",me->query("anqi/max"));
         me->set("long",me->query("orilong")+"里面已经装了" +chinese_number(me->query("anqi/now"))+aq->query("base_unit")+aq->query("name")+"，想拆掉用uninstall。\n");
         aq->set_amount(remain);
         }
     else 
         {
         me->set("anqi/now",me->query("anqi/now") + aq->query_amount());
         me->set("long",me->query("orilong")+"里面已经装了" +chinese_number(me->query("anqi/now"))+aq->query("base_unit")+aq->query("name")+"，想拆掉用uninstall。\n");
         destruct(aq);
         }
     return 1;
     }
  }

int do_uninstall(string arg)
  {
   object ob;
   object me=this_object();
   object who=this_player();

   if( !this_object()->id(arg) ) return notify_fail("你想拆什么？\n");
   else if (me->query("anqi/now") ==0) return notify_fail(me->query("name")+"里面什么也没有。\n");
   else 
     {
      if (me->query("anqi/type") =="震天箭") ob=new("/d/obj/weapon/archery/zhentian-arrow");
      ob->set_amount(me->query("anqi/now"));
      ob->move(who);
      me->set("long","乾坤弓乃是陈唐关总兵李靖的镇关之宝。后因李靖结交\n虬髯客被疑而调入京城，也被李靖带来了。\n");
      me->set("anqi/now", 0);
      message_vision("$N从"+me->query("name")+"里面拆出一"+ob->query("unit")+ob->query("name")+"。\n", who);
      who->add_busy(1);
      return 1; 
     }
  }
