
inherit NPC;
#include <ansi.h>

void create()
{
        set_name("�׺�ͯ��", ({"tong zi", "zi"}));
        set("gender", "����" );
	create_family("������", 5, "����");
        set("title",HIG"����ɽ���鶴"NOR);
        set("age", 30);
        set("long", "һ��С��ʿ��������ϰ���ա�\n");
        set("combat_exp", 3000);
        set("attitude", "peaceful");
        setup();
}

