#include <ansi.h>
inherit ROOM;
void create ()
{
  set ("short", "官道");
  set ("long", @LONG

  这是一条并不算宽阔的官道，看起来走的人不多，因为路上
很少有人或动物留下的痕迹。
LONG);
  set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"road2",
]));
  set("outdoors", 1);
  setup();
}
void init()
{
add_action("do_guibai","guibai");
}
int do_guibai(string arg)
{
object ob = this_player();
if( ! arg || arg != "tian" )
return notify_fail("你要拜什么？\n");
message_vision(HIW"$N对着天上跪下拜了几拜，天边亮光一闪，出现了一个门口。\n"NOR,ob);
set("exits/enter", __DIR__"room");
remove_call_out("close");
call_out("close", 3, this_object());
return 1;
}
void close(object room)
{
message("vision",HIW"亮光一闪，门又不见了。\n"NOR, room);
room->delete("exits/enter");
}
