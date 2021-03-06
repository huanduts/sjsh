// huanwangzi.c 幻忘子

#include <ansi.h>

inherit NPC;
inherit F_MASTER;

void create()
{
       set_name(HIR"幻忘子"NOR, ({"huan wangzi", "huan"}));
       set("long", "喜性荣华富贵，不甘修道清贫，投靠魔道，为虎作伥。\n");
       set("title", HIC"天一宫"NOR);
       set("per", 30);
       set("gender", "男性");
       set("age", 65);
       set("class", "sanjie");
       set("attitude", "friendly");
       set("shen_type", 1);
       set("rank_info/respect", "老道长");
       set("max_kee", 1000);
       set("max_gin", 100);
       set("max_sen", 1000);
       set("force", 1200);
       set("max_force", 1200);
       set("force_factor", 120);
       set("max_mana", 1200);
       set("mana", 1200);
       set("mana_factor", 120);
       set("combat_exp", 1200000);
       set("daoxing", 1100000);

        set_skill("dodge", 80);
        set_skill("parry", 80);
        set_skill("spells", 40);  
        set_skill("tianmogong", 40);
        set_skill("literate", 80);
        set_skill("sword", 80);  
        set_skill("huxiaojian", 80);
        set_skill("zhaoyangbu", 80);
        set_skill("force", 80);   
        set_skill("huntianforce", 80);

        map_skill("spells", "tianmogong");
        map_skill("force", "huntianforce");
        map_skill("sword", "huxiaojian");
        map_skill("parry", "huxiaojian");
        map_skill("dodge", "zhaoyangbu");

	create_family("三界山", 3, "蓝");
	
	set("inquiry", ([
	"name"     : "你可以叫我幻忘子。\n",
	"here"     : "这里不是好地方，如果想荣华富贵，可以跟我一起走。\n",
	]));	
	
	setup();
	carry_object("/d/sanjie/obj/jinjia")->wear();
	carry_object("/d/sanjie/obj/qinghong")->wield();
}

void attempt_apprentice(object ob, object me)
{
        command("say 很好，" + RANK_D->query_respect(ob) +"多加努力，他日必定有成。\n");
        command("recruit " + ob->query("id") );
	return;
}	

int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
        ob->set("class", "sanjie");
}

�
