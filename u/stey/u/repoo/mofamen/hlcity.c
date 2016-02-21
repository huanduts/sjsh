//By Repoo
#include <room.h>
#include <ansi.h>
inherit ROOM;
inherit F_SAVE;
string SAVE_NAME;
void create ()
{
set ("short", HIB"黑龙城"NOR);
set ("long", @LONG
 
这是一座古老的城堡。城堡周围被炙热的岩浆包围。这里
热的让你喘不过气来。城中心有一座非常小的死火山，火
口是非常规正的圆形。

LONG);
  set("exits", ([ /* sizeof() == 1 */
  "west" : "/u/repoo/mofamen/hl_door",
]));
  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/heilong" : 1,
  ]));
  create_door("west", "黑龙城城门", "east", DOOR_CLOSED);
  set("no_clean_up", 1);
  setup();
}
void init()
{
        add_action("do_insert", "insert");
        set("no_clean_up", 1);
}

int do_insert(string arg)
{
         object hlcity, ob, me;
        me=this_player();

   if(!me->query_temp("heilong_killed"))
              return notify_fail("你最好先杀了守城护卫？\n");
        if( !arg)
                return notify_fail("你要放什么东西？\n");

if( !arg || arg!="yuan yu" || !(ob=present(arg, me)))
                return notify_fail("似乎孔中放不下这个东西。\n");

          if( !(hlcity = find_object(__DIR__"gl_door")) )
                hlcity = load_object(__DIR__"gl_door");

       if( hlcity = find_object(__DIR__"gl_door") ) 
        {
                set("exits/enter", __DIR__"gl_door");
message_vision("$N将$n塞入圆孔，一道白光闪过，出现一条通道。\n", me, ob);
               message("vision", "通道从外面打开了。。\n", hlcity );
                  hlcity->set("exits/out", __DIR__"hlcity");
                destruct(ob);
        call_out("close_down", 600);
        }
        return 1;
}
void close_down()
{
        object hlcity;

        message("vision", "通道消失在白光中。\n", this_object() );
        if( hlcity= find_object(__DIR__"gl_door")) {
         message("vision", "通道消失在白光中。\n", hlcity);
        hlcity->delete("exits/out");
        }
        delete("exits/enter");
}
