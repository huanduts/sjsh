// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
inherit ROOM;

void create ()
{
  set ("short", "走廊");
  set ("long", @LONG
 
这是一条长长的走廊，青石为砖，白玉为栏。沿着长廊一路都是
汉青玉的柱子，紫金镶嵌，雕龙画凤。长廊外繁花似锦，一对对
蝴蝶翩舞其间。好一派神仙福地、佛门洞天！

LONG);

  set("outdoors", 1);

  set("exits", ([
  "west" : "/d/xuyi/dadian",
  "east" : "/d/xuyi/shuifang2",
]));

  setup();
  replace_program(ROOM);
}

