// 神话世界·西游记之（世纪）
 
// create by jing 2000.7.13
 
inherit ROOM;

void create ()
{
  set ("short", "花铺");
  set ("long", @LONG

花铺里一阵清香扑鼻，隐约可以望见花铺后面是个巨大的花圃，里面栽种
着各种各样的鲜花，你想买真正的鲜花，这里绝对是最好的选择。在花铺
门口，俏生生地站着一个小姑娘。
LONG);

  set("exits", ([
        "south"   : __DIR__"jiedao1",
      ]));
  set("objects", ([
         __DIR__"npc/maihuanu"   : 1,
      ]));

  setup();
}
 

