inherit NPC;
int ask_aoyun();
void create()
{
set_name("申奥成功使者", ({"shi","shizhe"}));
set ("long", @LONG
他是在这里负责给大家发奥运奖励(aoyun)的，
大家赶快向他要（ask）吧。
LONG);
set("inquiry", ([
"aoyun": (: ask_aoyun :),
        ]));
setup();
}
int ask_aoyun()
{
object me=this_player();
int sss;
if (this_player()->query("sss")){
message_vision("$N对着$n哼了一声。\n",this_object(),this_player());
      command("say 奥运申办成功了，大补也给你了，你怎么还要啊！小心整蛊你！\n");
 return 1;
}
me->add("potential",150000);
me->set("sss",1);
command("say 奥运申办成功了，大家也有一份功劳,给你些潜能吧!\n");
return 1;
}
