//gunseng.c
#include <ansi.h>

int ask_name(); 

inherit NPC;
inherit F_MASTER;
void create()
{

set_name("玄痛大师", ({
		"xuantong dashi",
		"xuantong",
		"dashi",
	}));
        set("gender", "男性" );
        create_family("少林寺", 3, "弟子");
        set("title",HIC"少林寺戒律院主持"NOR );
        set("age", 78);
set("long",
		"他是一位白须白眉的老僧，身穿一袭银丝棕黄袈裟。他身材高大，\n"
		"两手过膝。双目半睁半闭，却不时射出一缕精光。\n"
	);
	set("class", "bonze");
	set("attitude", "heroism");

        set("force", 1700);
        set("max_force", 1700);
        set("force_factor", 70);
        set("mana", 1700);
        set("max_mana", 1700);
        set("mana_factor", 20);
        set("combat_exp", 1200000);
        set("daoxing", 1500000);

        set_skill("banruo-zhang", 180);
        set_skill("jingang-leg", 180);
        set_skill("yijinjing", 200);
        set_skill("chanzong", 200);
        set_skill("spells", 180);
        set_skill("force", 180);
        set_skill("unarmed", 180);
        set_skill("literate", 180);
        set_skill("dodge", 180);
        set_skill("parry", 180);
        map_skill("unarmed", "banruo-zhang");
        map_skill("parry", "jingang-leg");
        map_skill("force", "yijinjing");
        map_skill("spells", "chanzong");

	set("max_kee", 1300);
	set("max_sen", 1300);
	setup();
        carry_object("/d/shaolin/obj/changjian")->wield();
        carry_object("/d/shaolin/obj/dao-cloth")->wear();


}
void attempt_apprentice(object ob)
{
	if( (string)ob->query("gender") != "男性" )
	{
		command ("say 阿弥陀佛！女施主呀，贫僧可不敢开这等玩笑啊。");
		return;
	}

	if( (string)ob->query("class")!="bonze" )
	{
		command ("say 阿弥陀佛！贫僧就收下你做『俗家弟子』了。");
	}
	command("say 阿弥陀佛，善哉！善哉！");
        command("recruit " + ob->query("id"));
        ob->set("title", HIG"嵩山少林寺弟子"NOR);
}
