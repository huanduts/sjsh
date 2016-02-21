
//Room: dgtsheshenya.c 睹光台舍身崖
//Date: Oct. 2 1997 by That

inherit ROOM;
#include <ansi.h>

void create()
{
	  set("short","睹光台舍身崖");
	  set("long",@LONG
从卧云庵出来，这里是看日出、云海、佛光、神灯之地。台下深崖万丈，
陡彻无底，云遮雾掩。极目四望，数百里外的大小雪山皆历历在目。因为这里
至高至洁，至险至奇，又至美至幻，常有人在这里投身云海，舍此肉身尘世。
　　金顶云海，迷迷茫茫，笼罩四野，远接天际。云海轻荡时，你在金顶，脚
踏白云，大有飘飘欲仙之感；当云涛迅猛涌来时，整个金顶都似在向前浮动，
令人有乘舟欲风之意。（ｊｕｍｐ）
LONG);
	  set("outdoors", "emei");
	  set("exits",([ /* sizeof() == 1 */
	  "enter"	: __DIR__"woyunan",
	  "east"	 : __DIR__"duguangtai", 
	  ]));
	  set("no_clean_up", 0);
	  setup();
}
void init()
{
   add_action("do_jump","jump");
}

int do_jump(object me,object cl)
{
	         me = this_player();
                     if( (string)me->query("title")=="普通百姓" ){                  
            cl = new("/d/emei/obj/mejian.c");
	message_vision(HIR"$N决定就是死也要找到属于自己的那把剑。\n"NOR, me);
	message_vision(HIR"$N毅然跳出舍身崖，长声尖叫，凄厉的声音响彻山谷，随着$N的的下落也急剧向下拉长。\n"NOR, me);
        if (random(2)==1)//这里是找到剑的机率
	{
       message_vision(HIW"\n$N下落的时候突然间看见崖壁上有东西闪闪发光，伸手一拿原来是一把剑。\n"NOR, me);
       message_vision(HIW"$N找到了自己的剑。\n"NOR, me);
            me->set_temp("marks/收到",1);
                     cl->move(me);
            me->move(__DIR__"jieyindian");
       message_vision(HIC"\n阳光对$N说道:$N找到自己的剑了，$N有资格拜我为师了。\n"NOR, me);

	}
	else
	{
message("channel:rumor",HIM"【"HIW"空穴来凤"HIM"】某人：听说" + me->query("name") + "，为了拜入峨嵋门下毅然跳下了舍身崖！\n"NOR,users());
             me->move(__DIR__"st0");
	me->unconcious();

	}
}
	else{
       message_vision(HIC"你高兴地跳了起来。\n"NOR, me);

	}

	return 1;
}

