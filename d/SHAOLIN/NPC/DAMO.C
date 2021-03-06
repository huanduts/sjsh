#include <ansi.h>
inherit NPC;
inherit F_MASTER;
void create()
{
       set_name(HIC"达摩祖师"NOR, ({"master damo","damo", "master"}));
       set("long", "他是一位卷发络腮须的天竺老僧，身穿一袭邋遢金丝绣红袈裟。
他就是少林派开山鼻祖、当今武林的隐世高僧达摩祖师。 \n");
       set("title",HIW"少林开山祖师"NOR);
       set("gender", "男性");
       set("age", 80);
   set("class", "taoist");
       set("attitude", "friendly");
       set("shen_type", 1);
       set("rank_info/respect", "老师祖");
       set("per", 26);
   set("looking", "满面红光，目蕴慈笑，眼现智珠，一派得道高僧气势。");
   set("int", 30);
       set("max_kee", 6000);
       set("max_sen", 6000);
       set("sen", 6000);
       set("kee", 6000);
       set("max_mana", 5000);
       set("max_force", 5000);
       set("force", 5000);
       set("mana", 5000);
       set("daoxing", 8500000);
       set("combat_exp", 6500000);
       set("max_gin", 1000);
       set("force_factor", 220);
       set("mana_factor", 100);
       set_skill("unarmed", 400);
       set_skill("dodge", 400);
       set_skill("parry", 400);
     set_skill("sword",400);
      set_skill("stick", 400);
   set_skill("spells", 400);
   set_skill("chanzong", 400);
   set_skill("banruo-zhang", 400);
   set_skill("jingang-leg", 400);
   set_skill("yijinjing", 400);
   set_skill("force", 400);
   set_skill("zui-gun", 400);
   set_skill("shaolin-sword", 400);
   set_skill("shaolin-shenfa", 400);
   map_skill("spells", "chanzong");
   map_skill("unarmed", "banruo-zhang");
   map_skill("force", "yijinjing");
   map_skill("stick", "zui-gun");
   map_skill("parry", "jingang-leg");
   map_skill("dodge", "shaolin-shenfa");
   map_skill("sword", "shaolin-sword");
   create_family("少林寺", 1, "祖师");
setup();

        carry_object("/d/lingtai/obj/pao")->wear();
        carry_object("/d/lingtai/obj/shoe")->wear();
        carry_object("/d/shaolin/obj/damobang")->wield();
}

void attempt_apprentice(object ob)
{   ob=this_player();
   if( (string)ob->query("family/family_name")=="少林寺") {
   if ((int)ob->query("daoxing") < 1500000 ) {
     command("say 我们修行之人最注重道行，" + RANK_D->query_respect(ob) + "还需多加努力才能修成正果。\n");
   return;
   }
   if ((int)ob->query_int() < 25) {
   command("say 万事都讲一个缘字。");
   command("say " + RANK_D->query_respect(ob) + "与佛无缘，还是请回吧。");
   command("sigh");
   return;
   }
   if( (int)ob->query_skill("yijinjing", 1) < 280 ) {
   command("say 这位" + RANK_D->query_respect(ob) + "对我佛门易筋经的领会还不够深，你现在就来找我也太早了点吧 !\n");
   command("sigh");
   return;
   }
        command("smile");
        command("say 很好，" + RANK_D->query_respect(ob) + "恭喜你荣升为少林寺渡字辈弟子 !老衲又得一可塑之才，真是大畅老怀 !");
        command("recruit " + ob->query("id") );
        message("system", HIY"少林寺又多了一位弟子  "+this_player()->name()+HIW"
                少林寺的势力加强了。\n"NOR,users());
        
   return;
   }
        command("shake");
        command("say 不知此话从何谈起？" + RANK_D->query_respect(ob) + "与本寺素无来往，还是请回吧。\n");
        return;
}
int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                ob->set("class", "bonze");
                ob->set("title", HIG"达摩祖师亲授弟子"NOR); 
}

int accept_fight(object me, object ob)
{   ob=this_player();
   command("say " + RANK_D->query_rude(ob) + "杀心太重，恐祸不久已！\n");
   return 0;
}
void die()
{

        if( environment() ) {
        message("sound", "\n\n达摩祖师双目微闭，说道：放下屠刀,立地成佛！望你早悟正道。\n\n",
 environment());
        command("sigh");
        message("sound", "\n达摩祖师起身而去，周围一片金光。。。\n\n", environment());
        }

        destruct(this_object());
}

