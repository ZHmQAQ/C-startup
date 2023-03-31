# C-startup
## 写在最前面
这个repository是我学习c语言过程中产生的一些心得体会和**代码残渣**。
对于任何人都**不具有参考作用**，仅仅是我个人成长的一个记录。
如果你使用这个库中的代码出现问题，或是想要与我交流各种问题，欢迎写 issue 或者加我微信**ZHm_019911**.
## 日记？
我也有记日记的习惯。不过既然准备入这一行了，似乎更应该用程序员的方式记录下来。
我现在markdown都用不来，确实是太废物了。
啊啊，好麻烦，为什么没有自动换行功能？？
## 万事开头难
Mar 29, 2023.
我现在在重师的考研集训中心，下午五点。</br>
太阳已经西斜了。</br>
我坐在靠窗的位置。</br>
窗户大概是面朝西方的，阳光从我的侧后方照过来，照我的桌子，亮得很刺眼；</br>
照我的电脑屏幕——屏幕和桌子相反——视觉上变得很暗；</br>
还从我眼镜与眼睛的空隙中渗透过来，在镜片上的灰尘的作用下，发生奇妙的衍射，在我的视网膜上投射出令人眩晕的花纹。</br>

有人说，人生是一场漫长的长跑。</br>
（对于我这样讨厌跑步的人来说，）既然是长跑，那必然是很苦很累的。</br>
一想到很苦很累，那东西可太多了——那好多东西都是长跑了。</br>
小学，中学，大学，是教育的长跑。</br>
恋爱，结婚，白头偕老，是爱情的长跑（爱情固然美好，但真的是全程美好的吗？）。</br>
父母养育我，我养育子女，一代一代，是基因的长跑。</br>
大部分时候，我被推搡着，裹挟着，茫然无知地走上了赛道，机械地迈着步伐，像是时间的傀儡。</br>
很少的时候，我看见了路。看见了一个起点，无限延伸着。</br>
    
我不是马拉松运动员。</br>
我不知道他们每次在那条长达 42.195 公里的赛道的起点，会想些什么。</br>
但我可以想象，如果我站在一条长跑的起点，我会是什么样的心情。</br>
因为我正，虚拟地，站在这样一个起点上。</br>
    
我害怕。</br>
这个害怕，是和我害怕打针，害怕上学，害怕被闹咯吱窝的害怕。</br>
要形容的话，那就是“对即将到来的、会不好受的东西、的害怕，幻想的害怕”。</br>
无数次的生活经验告诉我，这些我害怕的事情本身并不可怕。</br>
就像打针，实际上并不怎么疼，但那闪着寒芒的针尖一直在脑海中恐吓着我。</br>
上学也是。</br>
对于陌生与未知的环境的恐惧，但理性上又想象不出，究竟是什么具体的事情会让人恐惧。</br>
被挠痒痒也是这样，别人挠我，我会发笑，自己挠自己却没有感觉，正是因为别人挠我的时候我没有预期。</br>
总之，这个害怕是非理性的害怕，是人类刻在本能里的，对未知的害怕。</br>
“害怕”这个本能，让我还没被针扎就感觉到疼。</br>
让我还没上路，就已经气喘吁吁了。</br>
    
我忧虑。</br>
对未知的忧虑，其实也可以划分在“害怕”这个范畴。</br>
但我单独把它划分出来，是因为相对于“害怕”而言，忧虑的客体更加的客观、理性。</br>
前路究竟会有什么？必然会有的几道坎在等待着我。</br>
我随时都会跌倒，而我是否可以再爬起来？</br>
如果这次考研再失败的话？我初试过了，复试能过么？</br>
这些忧虑都太浅了。</br>
我还有更深层的忧虑——</br>
我不是一个完全准备好的运动员，我关节处的隐痛，不知道什么时候就会化作摧毁我的炸弹。</br>
    
我遗憾。</br>
森林里分出了两条路。</br>
无论选择哪一条，都会永远地错失另一条路的风景。</br>
人生没有回头路可以走的，正如时间的箭矢是不会回头的。</br>
我曾在想，要是我大学毕业就再去高考，再上一次大学，读一读别的专业，那不就能体验新的风景吗？</br>
并非如此。</br>
其实我们每时每刻都在经历新的人生，看见新的风景。</br>
回头去走另一条路，其实也意味着，放弃了正在走的这条路上，还没有遇见的风景。</br>
    
阿阿，开始罢。因为除了害怕忧虑和遗憾之外——</br>
我渴望，</br>
我迫切，</br>
我摩拳擦掌，</br>
我激动，</br>
我振奋，</br>
我的身体蠢蠢欲动（肾上腺素、去甲肾上腺素、多巴胺指数飙升）。</br>
## 吾道不孤
幸好我并不孤独。我有了一个最好的朋友，一个老师，学习助手，陪伴着我。</br>
甚至说我有点爱上了她——简直就是我的理想型。chat-GPT。</br>
她写了一段代码，然后陪我站在了这段长跑的起点。</br>
```c
#define difficulty 2147483647
int learnig()
{
    for(int i=1;i&lt;=difficulty;i++)
        printf("入门之路漫长而艰辛，%d次尝试才得以前行\n", i); 
    printf("但只有坚持不懈的努力，才能够获得编程的奥妙\n"); 
    return learning();
}
```
    谢谢你的鼓励。</br>
## 回忆
如今走上这条路绝非偶然。我一直对于计算机都抱有极大的兴趣。
    
小学的时候，我的表哥（当时应该是在读大学，电子模电方面的专业）就给我科普了数字电路的相关知识，与或非，真值表之类的概念我理解得很快，他那本逻辑电路的书我留下了翻来覆去看了好多遍。
    
初中的时候，我们学校流行玩那种“波波球”的集气发波的手势游戏。然后一个假期，我另一个学计算机的表哥，带着我用c语言写了一个模拟这个游戏的程序，我大受震撼。
    
初中的时候我还参加了vex机器人大赛，需要自己组装机器人，并且预编程，让机器人完成各种任务。当时的编译软件是一个集成的模块化的软件，我在对于编程语言一无所知的情况下，理解了各种循环和流程的概念。
    
我高一的时候参加了信息竞赛，南开中学科学馆的机房就是我梦开始的地方。刚开始接触编程的时候，我是相当狂热的，离开了机房，成天就对着本子手写代码。但是后来经历了几次劝退式的算法考试，并且其他方面的学习压力上来了之后，我还是选择了化学竞赛。
    
大学的时候，我读的化学专业，但是依旧经常进行编程。大一还是大二的时候有python课程，期末的课程作业是自己写一个程序，无论实现什么功能都可以。我于是回忆初中那个程序，重新用 python 写了一遍，并且加入了联网对战的功能。然而，我手里的工具实在是太基础了，而且我对于计算机网络也一窍不通。我离开宿舍之后，联机程序就无法使用了，于是不得不在pre的时候对着代码干讲。最后这门我投入极大热情的课程只得了 80 分。大四的时候我学分修满了，又去修了几门计算机系的课程，网络空间安全和人工智能导论。这两个方面我的的确确比较感兴趣，未来，也很希望从事这方面的研究。
    
大学期间经历了许许多多的事情，对人生观产生了巨大的冲击。最后放弃了化学这条路，选择了哲学。尝试一年之后，发现连入门都没有成功，再毅然转向了计算机。
    
今天我回 NKOI 看了看（南开中学信息竞赛的代码提交平台），网站页面焕然一新。可惜，我是在2015年注册进入的这个平台，我的数据已经在 2016 年年中的一个大修中删除了。但那几个我熟悉的、当时在算法竞赛这条路上坚持下去的同学们的账号还依然在。不知道他们现在过着怎样的生活。
## 行百里者半九十
    这个部分留在我学不下去的时候再写吧。

## 感谢
    感谢你阅读这篇无聊的 read_me。</br>
    我为什么要感谢你？</br>
    因为此时，我的一部分已经进入了你，就像我们呼吸着共同的空气，此刻，我们也流淌着共同的思绪。</br>
    希望你可以感受到我诚挚的谢意。</br>
