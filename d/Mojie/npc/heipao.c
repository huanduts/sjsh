#include <ansi.h>
inherit NPC;
inherit F_MASTER;
void create()
{
        set_name("黑袍", ({"heipao"}));
        set("gender", "男性" );
        set("age", 33);
        set("title", "无天座下右护法");
        set("combat_exp", 1500000);
	set("daoxing", 1500000);
              set("long","此魔是无天座下右护法，为人凶狠残暴，嗜血如命。他本
是一山妖，后被无天收服，得己重用，是无天必不可少的
刽子手。\n");
        set("attitude", "peaceful");
	set("int", 25);
	set("class", "mo");
        create_family("魔界", 2, "弟子");
	
        set("eff_dx", 30000);
        set("nkgain", 200);

        set_skill("unarmed", 280);
        set_skill("dodge", 280);
        set_skill("parry", 280);
        set_skill("spells", 280);  
        set_skill("molianspells", 280);
        set_skill("literate", 280);
        set_skill("sword", 280);  
        set_skill("xueling-jian", 280);
        set_skill("shifo-zhi", 280);  
        set_skill("moshenbu", 280);
        set_skill("dodge", 280);  
        set_skill("force", 280);   
        set_skill("heilianforce", 280);

        map_skill("spells", "molianspells");
        map_skill("unarmed", "shifo-zhi");
        map_skill("force", "heilianforce");
        map_skill("sword", "xueling-jian");
        map_skill("parry", "xueling-jian");
        map_skill("dodge", "moshenbu");


        set("per", 30);
        set("max_kee", 2500);
        set("max_sen", 2500);
        set("force", 2500);
        set("max_force", 2500);
        set("force_factor", 50);
        set("mana", 2500);
        set("max_mana", 2500);
        set("mana_factor", 50);

        setup();
        carry_object("/d/mojie/obj/tongjia")->wear();
        carry_object("/d/mojie/obj/sword")->wield();
}
void attempt_apprentice(object ob, object me)
{
        if( (int)ob->query_skill("molianforce", 1) < 120 ) {
        command("say 这位" + RANK_D->query_respect(ob) + "对我魔道内功领会还不够深，现在收你也是勉为其难，不如作罢！\n");              
        return;
        }
        command("say 很好，" + RANK_D->query_respect(ob) +
"加入魔界以后多加努力，他日为杀如来做出你的贡献。\n");
        command("recruit " + ob->query("id") );
            ob->set("title", HIC"魔界右护法座下弟子"NOR);
	return;
}		

int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                ob->set("class", "mo");
}

�
