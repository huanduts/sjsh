inherit ROOM;;
#include <ansi.h>
void create ()
{
set ("short",HIG"ҹˮ��--�㷻");
set ("long", @LONG

    �ĵ������������ŷ�������ľ�Ƶ�С��ǰ����һ��ľ
��--��ҹˮ�ġ���
    ��ȥ����֪������һ����ˮ�ӹ�������ҹˮ�ġ���Ů��
�˴�����ˮ�����֡�ҹ����ˮ��΢��������Ƣ������������
���ڿ����У�����������̲�ס��ڵĺ����������㡣
    Ů��������һϮ��ȹ�����еĴ����ڻ��뻨֮�䣬ƿ��
ƿ֮�У���������ĵ���������������ʱ�������������ͣ
�����ļ��ϣ��ȶ��Ų�ɫ�ĳ���ƺ����ᳪ��ʲô��
    �㷻��ǰ��һ����Ӱ��С�ڶ���Ů�����������ܹܣ���
Ҫ�������ڵ����񡣾�Ө����ˮ�����ˣ������ԡ�ҹˮ��
����ˮ��ʲô���˽�Ŀ�������������˵���������ѯ����
���ڡ�ҹˮ�ġ��Լ����䷽������������������;��������
���ȵȣ��������һ��������Ĵ𸴵ġ�

LONG);;;
set("exits",([
"east" : __DIR__"loveroom",
"south" : __DIR__"workroom"
]));
set("objects",([
"/u/rainy/npc/xfayu":1,
"/u/rainy/npc/xheier":1]));
setup();
}