// ����С· by Calvin
inherit ROOM;

void create()
{
  set ("short", "����С·");
  set ("long", @LONG

�����ɽ��Ǵ�˵�е��ɽ�,��������᫵�ɽ·��ôҲ
���˲��������ǵĵط����ж�ô��������

LONG);

  set("exits", ([ 
    "west" : __DIR__"lu8",
    "east" : __DIR__"lu5",
  ]));
  set("outdoors", __DIR__"");
  setup();
}

void init ()
{
  add_action ("do_climb","climb");
  add_action ("do_jump","jump");
}

int do_climb (string arg)
{
  object who = this_player();

  message_vision ("$N����������ȥ��\n",who);
  if (who->query("combat_exp") < 5000 ||
      who->query("kee") < 100)
  {
    message_vision ("$N��һ�����˴�ʯ����һ������������\n",who);
    who->unconcious();
    return 1;
  }
  who->add("kee",-100);
  who->move(__DIR__"lu1");
  return 1;
}

int do_jump (string arg)
{
  object who = this_player();

  message_vision ("$N��������������ȥ��\n",who);
  message_vision ("$N�������ˤ����̨�¡�\n",who);
  who->unconcious();
  return 1;
}