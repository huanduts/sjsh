//kunlun
inherit ROOM;

void create ()
{
        set ("short", "小路");
        set ("long", @LONG

        眼看已经到了小路的尽头了，你连忙加快了
步伐。
LONG);

        set("exits", 
  ([ //sizeof() == 4
                "northup" : __DIR__"gate",
                "east" : __DIR__"xiaolu1",
        ]));
        set("objects", ([
   ]));
        set("outdoors", "changan");
       setup();
	replace_program(ROOM);
}

