// last modified by alone
#include <ansi.h>
#include <mudlib.h>

inherit F_CLEAN_UP;
int top_list(object ob1,object ob2);
int get_score(object ob);
int main(object me, string arg)
{
        
        object *list,*ob;
        int i;
        string msg;

      ob = filter_array(objects(), (: userp($1) && !wizardp($1) :));
        list = sort_array(ob, (: top_list :));
      msg =  "\n              ┏ "+BLINK HIW+"仙侣情缘"+HIC+"*"+HIR+"三界神话"+HIW+"在线高手排行榜 "NOR" ┓\n";
      msg += "┏━━━━━┯┻━━━━━━━━━━━┯━━━━━┻┯━━━━┓\n";
 msg += "┃"+BCYN HIW+"  名 次  "NOR+" │"+BCYN HIW+"      高        手      "NOR+"│"+BCYN HIW+"  门    派  "NOR+"│"+BCYN HIW+" 评  价 "NOR+"┃\n";
       msg += "┠━──━─┴────────────┴──────┴────┨\n";
        for (i = 0 ;i < 15 ; i++) {
        if( i >= sizeof(list)) msg += "┃暂时空缺。 \n";
                else {
                if(list[i] == me) msg += BBLU HIY;
             msg += sprintf("┃"+HIR+"  %-7s"NOR+" ┃"+HIC+" %-12s"NOR+HIC+" %-10s"NOR+"┃"+HIG+"%-12s"NOR+"┃"+HIY+" %5d"NOR+"  ┃\n",chinese_number(i+1),list[i]->query("name"),"["+
      list[i]->query("id")+"]", list[i]->query("family")?  list[i]->query("family/family_name"):"普通百姓",
        get_score(list[i]));
                }
                         }
        msg += "┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n";
       msg += "              " +BCYN HIW+ NATURE_D->game_time() + "记\n"NOR;
        write(msg);
        return 1;

}
int top_list(object ob1, object ob2)
{
      int score1,score2;

        score1 = get_score(ob1);
        score2 = get_score(ob2);
     return score2 - score1;
}

int get_score(object ob)
{
        int tlvl,i,score;
        string *ski;
        mapping skills;

      reset_eval_cost();
        skills = ob->query_skills();
        if (!sizeof(skills)) return 1; 
        ski  = keys(skills);
          for(i = 0; i<sizeof(ski); i++) {
       if( (string)ob->query("id")=="loveyou" ) return 1;       
                        tlvl += skills[ski[i]];
                        }  // count total skill levels
        score = tlvl/10;
        score += ob->query("max_force")/10;
        score += ob->query("max_mana")/10;
//        score += ob->query_str() + ob->query_int() + ob->query_dex() + ob->query_con();
       score += (int)ob->query("combat_exp")/5000;
       score += (int)ob->query("daoxing")/5000;

        return score;
}
int help(object me)
{
write(@HELP
指令格式 : top
 
这个指令可以让你知道在线十大高手是哪些，别去惹他们。 
 
HELP
    );
    return 1;
}

