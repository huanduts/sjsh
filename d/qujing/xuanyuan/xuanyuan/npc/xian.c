inherit NPC;
string expell_me(object me);
void create()
{
  set_name("����", ({"xiang xiang", "xiang", "fox"}));
  set("gender", "Ů��");
  set("age", 18);
  set("long",
"�����������ޱȣ�ȴ�Ķ����ס������Ҳ�������Ǻ��������ˡ�\n"
"��Ϊ�����Ĵ���һ��������ʹ���б���ͬ�࣬����һֱ�ܹ¶���\n"
"�������������ôһ��ʡ�µĲ��¡���\n");
set("title", "��Ĺٻ��");
set("per", 40);
set("int", 40);
set("cor",40);
set("combat_exp",400000);
  set_skill("force",120);
  set_skill("parry",120);
  set_skill("dodge",120);
  set_skill("literate",120);
  set_skill("needle",120);
  set_skill("spells",120);
  set_skill("xuanhu-xinfa",120);
  set_skill("tianyi-zhen",120);
  set_skill("huxing-step",120);
  set_skill("xuanhu-shentong",120);
  map_skill("force","xuanhu-xinfa");
  map_skill("needle","tianyi-zhen");
  map_skill("dodge","huxing-step");
  map_skill("spells","xuanhu-shentong");
  set("attitude", "heroic");
create_family("��ԯ��Ĺ", 2, "����");

  set("inquiry", ([
                  "����": (: expell_me :),
                   "leave": (: expell_me :),
                ]) );
  setup();
        carry_object("/d/moon/obj/luoyi")->wear();
        carry_object("/clone/weapon/needle1")->wield();
}
string expell_me(object me)
{
  me=this_player();
 if((string)me->query("family/family_name")=="��ԯ��Ĺ")

  {
      me->set_temp("xuanyuan/betray", 1);
     return ("Ҫ�ߣ��ȡ����������ˡ����������ܲ��˵ġ�����(zou)\n");
}
  return ("�㲻�����ǵ��˰ɣ���Ҫ�߾��ߺ��ˡ���\n");
}
void init()
{
    add_action("do_accept", "zou");
}
void do_accept()
{
    object me=this_player();
if(!me-query_temp("xuanyuan/betray"))
message_vision("$N��������ʲô�ߣ�\n",this_object());
    message_vision("$N��������������������������Ӷ�Ѭ���ˣ�\n", me);
    me->add("betray/count", 1);
    me->add("betray/xuanyuan", 1);
    me->set("combat_exp", me->query("combat_exp")*95/100);
    me->delete("family");
    me->set("faith",0);
    me->delete("class");
    me->set("title", "��ͨ����");
    me->save();
}