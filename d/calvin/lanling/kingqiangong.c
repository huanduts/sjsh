//shulin 兰陵

inherit ROOM;

void create ()
{
        set ("short", "乾宫");
        set ("long", @LONG

这是兰陵陵宫的第一大宫殿,这里有来自世界各地的珍奇
雄伟而有壮观的乾宫是多少文武百官商讨国家大事的地方
这里装修典雅,华丽夺目 ... ...
LONG);

        //set("item_desc", ([" *** " : " *** ", ]));

        set("exits", 
        ([ //sizeof() == 8
                "northdown" : "/d/calvin/lanling/kingdoor1",
                "south" : "/d/calvin/lanling/kingkungong",
        ]));

        set("objects", 
        ([ //sizeof() == 1
        ]));

//        set("outdoors", "changan")
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
