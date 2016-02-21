//BOX.C by koker@sjsh 2002

#include <ansi.h>
inherit ITEM;
#define LAST_PAR "fg2"
#define THIS_PAR "fg1"

void create()
{
	set_name("箱子", ({ "box" }) );
	set("long",
			"这是一个黑呼呼的箱子，你可以打开它(open box)。\n" );
	set_weight(5000000);
	if( clonep() )
        set_default_object(__FILE__);
    else {
	set("unit", "个");
	set("value", 0);
        set("no_get",1);
     }
}
void init()
{
	add_action("do_get", "pick");
	add_action("do_get", "get");
	add_action("do_open", "open");
}

int do_open(string arg)
{
       object me,obj1,obj2,*inv;
       int i;
       
       me = this_player();
       if( !arg || arg!="box" ) return notify_fail("你要打开什么？\n");
       
       if( (int)me->query("level") < 6 )
    return notify_fail(""HIW"花哥看重的是各位的才学，你的等级都不够怎么能有什么才学那？."NOR"\n");
       if (me->query(THIS_PAR + "_pick")) {
       tell_object(me,CYN "你曾经打开过这个箱子啊！\n\n");
       tell_object(me,HIR "现在它里边什么也没有了！\n\n");
       tell_object(me,CYN "你失望的踢了箱子一脚。\n" NOR);
       return 1;
       }
	i=random(1000000)+3000000;
	me->add("balance", i);
	obj1 = new ("/u/koker/bingtao");
        obj1->move(me);
        obj2 = new("/u/koker/zhitiao");
        obj2->move(me);
      printf(HIM "你轻轻地打开了箱子，一阵闪光从箱子里窜了出来，你从箱子里找到了%d文钱！呵呵，花哥慷慨吧！\n\n" ,i );
      printf(HIW "你翻了翻箱子，又发现了个用冰做的桃子和一张纸条。\n" NOR);
//每次打开箱子，都将上次的参数消除，增加本次打开的参数。 
       me->delete(LAST_PAR + "_pick");
       me->set(THIS_PAR + "_pick",1);
       return 1;
}

