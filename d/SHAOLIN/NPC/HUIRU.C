//gunseng.c
#include <ansi.h>

int ask_name(); 

inherit NPC;
inherit F_MASTER;
void create()
{

set_name("慧如尊者", ({
                "huiru zunzhe",
                "huiru",
		"zunzhe",
	}));
        set("gender", "男性" );
        create_family("少林寺", 3, "弟子");
        set("title",HIC"嵩山少林寺护法尊者"NOR );
        set("age", 58);
set("long",
		"他是一位两鬓斑白的老僧，身穿一袭青布镶边袈裟。他身材略高，\n"
		"太阳穴微凸，双目炯炯有神。\n"
	);
	set("class", "bonze");
	set("attitude", "heroism");

        set("force", 2200);
        set("max_force", 2200);
        set("force_factor", 70);
        set("mana", 2200);
        set("max_mana", 2200);
        set("mana_factor", 20);
        set("combat_exp", 1800000);
        set("daoxing", 1500000);

        set_skill("yijinjing", 200);
        set_skill("chanzong", 200);
        set_skill("spells", 200);
        set_skill("force", 200);
        set_skill("dodge", 180);
        set_skill("shaolin-shenfa", 180);
        set_skill("jingang-leg", 180);
        set_skill("unarmed", 180);
        set_skill("parry", 180);
        set_skill("stick", 180);
        set_skill("zui-gun", 180);
        map_skill("unarmed", "jingang-leg");
        map_skill("stick", "zui-gun");
        map_skill("dodge", "shaolin-shenfa");
        map_skill("parry", "zui-gun");
        map_skill("force", "yijinjing");
        map_skill("spells", "chanzong");

	set("max_kee", 1300);
	set("max_sen", 1300);
	setup();
        carry_object("/d/shaolin/obj/qimeigun")->wield();
        carry_object("/d/shaolin/obj/hui-cloth")->wear();


}
void attempt_apprentice(object ob)
{
	object me; 
	mapping ob_fam, my_fam;
	string name, new_name;

	me = this_object();
	my_fam  = me->query("family");
	name = ob->query("name");

        if( (string)ob->query("gender") != "男性" )
	{
		command ("say 阿弥陀佛！女施主呀，贫僧可不敢开这等玩笑啊。");
		return;
        }

          if(((int)ob->query_skill("yijinjing",1) < 100))
        {
	command("say " + RANK_D->query_respect(ob) + "，你易筋经修为不够，不能越级拜师。");
                return;
        }

          if( (int)ob->query_skill("chanzong",1) < 100)
        {
        command("say " + RANK_D->query_respect(ob) + "，你禅法修为不够，不能越级拜师。");
                return;
        }

        if (!(ob_fam = ob->query("family")) || ob_fam["family_name"] != "少林寺")
	{
		command("say " + RANK_D->query_respect(ob) + "与本派素无来往，不知此话从何谈起？");
		return;
	}

        if ( (string)ob->query("class")!="bonze" && ob_fam["family_name"] == "少林寺") 
	{
		command("say " + RANK_D->query_respect(ob) + "是俗家弟子，不能在寺内学艺。");
		return;
	}

	command("say 阿弥陀佛，善哉！善哉！");
        command("recruit " + ob->query("id"));
        ob->set("title", HIC"嵩山少林寺护法尊者"NOR);
}
