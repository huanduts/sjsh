// Room: /d/shaolin/wuchang.c
// Date: YZC 96/01/19

inherit ROOM;

void create()
{
	set("short", "练武场");
	set("long", @LONG
这里是少林寺的练武场。由无数块巨大的花岗岩石板铺就。
上千年的踩踏已使得这些石板如同镜子般平整光滑。西边角上还
有两个大沙坑，十来个僧人正在练习武艺。东西两面各有一练武
场。
LONG );
	set("exits", ([
		"south" : __DIR__"houdian",
                "east" : __DIR__"luohan5",
                "west" : __DIR__"banruo5.c",
		"north" : __DIR__"fzlou",
	]));
set("objects", ([
                __DIR__"npc/xiao": 3, 
               __DIR__"npc/zhangmen": 1,
		__DIR__"obj/rack": 1,
]));
	set("no_clean_up", 0);
	set("outdoors", 1);
        setup();
}



