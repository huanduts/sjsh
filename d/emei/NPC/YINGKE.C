// worker.c

inherit NPC;
#include <ansi.h>

void create()
{
        set_name("女童", ({"nu tong", "tong"}));
        set("gender", "女性" );
        set("class", "xian" );
        create_family("峨嵋派", 6, "弟子");
        set("age", 17);
        set("title", HIM"峨嵋派山门迎客"NOR);
        set("long", "一位峨嵋派弟子，每天负责在花严顶迎接远道而来的客人．\n");
        set("combat_exp", 200000);
        set("attitude", "friendly");
        set_skill("dodge", 180);
        set_skill("unarmed", 180);
        set("per", 30);
        set("max_kee", 150);
        set("max_gin", 150);
        set("max_sen", 150);
        setup();
        carry_object("/d/shaolin/obj/cloth.c")->wear();

}
void init()
{
        object ob;

        ::init();
        if( interactive(ob = this_player()) && !is_fighting()
	&& !this_player()->query("env/invisibility") ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}

void greeting(object ob)
{
        if( !ob || !present(ob, environment(this_object())) ) return;
        say( "女童说道：这位" + RANK_D->query_respect(ob) +
"，欢迎到我们峨嵋山来！\n");
}

