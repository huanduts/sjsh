// 神话世界·西游记之（世纪）
 
// create by jing 2000.7.13

inherit ROOM;

void create ()
{
  set ("short", "街道");
  set ("long", @LONG

一条整洁的碎石路面，路面虽然不是很宽，但是人来人往的也是一片繁荣
的景象。西面就是蠙城最繁忙的交通要道十字路口，那里传来阵阵喧哗声。
在南面是一家钱庄。
LONG);

  set("exits", ([
        "east"   : __DIR__"jiedao11",
        "west"   : __DIR__"lukou",
        "south"   : __DIR__"bank",
      ]));
  set("objects", ([
//        __DIR__"npc/people"   : 1,
      ]));
  set("outdoors", __DIR__);

  setup();
}

