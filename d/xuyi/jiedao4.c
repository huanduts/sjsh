// �����硤���μ�֮�����ͣ�
 
// create by jing 2000.7.13

inherit ROOM;

void create ()
{
  set ("short", "�ֵ�");
  set ("long", @LONG

һ���������ʯ·�棬·����Ȼ���Ǻܿ�����������������Ҳ��һƬ����
�ľ����������ϙ���æ�Ľ�ͨҪ��ʮ��·�ڣ����ﴫ��������������
��������һ��Ǯׯ��
LONG);

  set("exits", ([
        "east"   : __DIR__"jiedao11",
        "west"   : __DIR__"lukou",
        "south"   : __DIR__"bank",
      ]));
  set("objects", ([
//        __DIR__"npc/people"   : 1,
      ]));
  set("outdoors", __DIR__);

  setup();
}
