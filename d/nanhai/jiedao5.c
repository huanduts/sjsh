// 神话世界·西游记之（世纪）
 
// create by night 2000.7.24

inherit ROOM;

void create ()
{
  set ("short", "街道");
  set ("long", @LONG

一条整洁的碎石路面，路面虽然不是很宽，但是人来人往的也是一片繁荣
的景象。东面就是蠙城最繁忙的交通要道十字路口，喧哗声阵阵传来。街
北是一家成衣店。

LONG);

  set("exits", ([
        "east"   : __DIR__"lukou",
        "west"   : __DIR__"jiedao6",
        "north"   : __DIR__"garments",
      ]));
  set("objects", ([
//        __DIR__"npc/people"   : 1,
      ]));
  set("outdoors", __DIR__);

  setup();
}

