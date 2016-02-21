      inherit ITEM; 


void init()
{
              add_action("do_yell", "yell"); 
}

void create()
{
        set_name("魔法神剑", ({"mofa sword", "jian", "gun"})); 
        set_weight(50); 
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long", "自古而来的一股神气而形成的一把神器。\n");
                set("value", 0); 
        }
        setup();
}
int do_yell(string arg)
{
object ob,me=this_player(); 
             if( !arg ) return notify_fail("你想召唤谁??\n"); 

             if(!(ob = LOGIN_D->find_body(arg)))
                                         return notify_fail("没有这个人。\n"); 
             if(present(ob, environment(me)))
                                      return notify_fail("这个人已经在你面前了\n"); 
             message_vision("$N大声叫道："+ob->query("name")+"！！！！\n",me); 
             message_vision("$N隐约听到有人在召唤$N，身子便不由自主地被一股力量所吸引而去。\n",ob); 
             ob->move(environment(me)); 
             message_vision("$N来到了$n身边。\n",ob,me); 
           return 1; 
}


