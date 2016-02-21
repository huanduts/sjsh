#include <room.h>
inherit ROOM;

void create ()
{
  set ("short", "试炼窟第一层");
  set ("long", @LONG
走进试炼窟，你不禁被这里的气氛吓了一跳。
LONG);
  set("exits", ([ 
  "south" : __DIR__"gate",
  "north" : __DIR__"0102",
  "east" : __DIR__"0103",
  "west" : __DIR__"0104",
]));
  setup();
}

void init()
{
        object me=this_player();
        if( !present("yao1") || interactive(me)) {
                remove_call_out("greeting");
                call_out("greeting",5, me);
        }
}
void greeting(object me)
{       object yao;
        if( !me || environment(me) != this_object() ) return;
        if( present("du zhizhu") ) return;
        seteuid(getuid());
        if(yao=new(__DIR__"/npc/yao1"))
                yao->move(this_object());
                message("vision", "\n一阵惺风吹来，一只毒蜘蛛钻了出来。\n\n", this_object() );
        yao->kill_ob(me);
         me->kill_ob(yao);
}
