# Ship Battle

这是一款双人回合制对战小游戏。

## 游戏玩法

### 基本玩法

游戏中的单位有`船`(ship)，`炮弹`(cannon)，`技能`(skill)。

每个玩家拥有一些船，两个玩家轮流攻击。
每一回合当前玩家按序号顺序操控自己的每一艘船指定目标进行一次攻击或发动一个技能(也可以不攻击)。
当船的生命值降为0时，该单位死亡。
消灭敌方所有船即为胜利。

通用`炮弹`有以下种类: 
- `炮弹1`(Cannon1): 对指定敌方目标造成1点伤害。冷却: 1回合
- `炮弹2`(Cannon2): 对指定敌方目标造成2点伤害，50%概率使目标`眩晕`1回合，当船的生命低于3时永久失效。冷却: 2回合
- `炮弹3`(Cannon3): 对指定敌方目标造成3点伤害，回复1点生命，当船的生命低于5时永久失效。冷却: 3回合
- `炮弹4`(Cannon4): 对指定敌方目标造成4点伤害，回复2点生命，当船的生命低于10时永久失效。冷却: 4回合
- `炮弹5`(Cannon5): 对指定敌方目标造成5点伤害，回复3点生命，当船的生命低于15时永久失效。冷却: 5回合

`船`有以下种类: 
- `高级船`(Big Ship): 20点生命，配备`炮弹1`、`炮弹2`、`炮弹3`、`炮弹4`、`炮弹5`
- `中级船`(Middle Ship): 10点生命，配备`炮弹1`、`炮弹2`、`炮弹3`
- `低级船`(Small Ship): 5点生命，配备`炮弹1`、`炮弹2`
- `防御船`(Defense Ship): 15点生命，配备`炮弹1`、`炮弹2`、`炮弹3`
  - 特性: 当生命值大于等于12时，本体受到的伤害减2；当生命值小于12时，本体受到的伤害减1
  - 技能1: `护盾`(Shield)，对指定己方目标生成一个有5点生命的`护盾`。冷却: 3回合
  - 技能2: `超级护盾`(Super Shield)，对所有己方目标生成一个有2点生命的`护盾`。冷却: 4回合
- `法师船`(Wizard Ship): 15点生命，配备`分裂弹`、`分裂弹`、`眩晕弹`、`爆炸弹`，初始拥有5点`护盾`
  - 特性: 不受`眩晕`影响，且拥有`护盾`时，`护盾`有100%`反伤`效果
  - `分裂弹`(Split Cannon): 对指定3个敌方目标分别造成1点伤害。冷却: 2回合
  - `眩晕弹`(Stunning Cannon): 使指定2个敌方目标`眩晕`1回合，当船的生命低于4时永久失效。冷却: 3回合
  - `爆炸弹`(Explosive Cannon): 对指定敌方目标造成4点伤害，并对相邻序号目标造成2点溅射伤害，当船的生命低于8时永久失效。冷却: 4回合
    - `爆炸弹`是否被`闪避`仅取决于该指定目标。若`爆炸弹`被该目标`闪避`，则无溅射伤害；若`爆炸弹`未被该目标`闪避`，则溅射伤害无法被闪避
  - 技能: `免疫`(Immune)，对指定2个己方目标施加2回合`免疫`效果。冷却: 3回合
- `治疗船`(Heal Ship): 30点生命，配备`炮弹1`、`治疗弹`
  - 特性: 每回合自身回复2点生命(`眩晕`时无法回复)
  - `治疗弹`(Heal Cannon): 使指定己方目标回复5点生命。冷却: 3回合
  - 技能1: `吸血`(Suck)，对指定己方目标施加2回合`吸血`效果。冷却: 2回合
  - 技能2: `治疗`(Heal)，对指定己方目标施加3回合`治疗`效果。冷却: 3回合
  - 技能3: `超级治疗`(Super Heal)，使所有己方目标回复4点生命。冷却: 4回合
- `暴击船`(Crit Ship): 15点生命，配备`暴击弹`、`暴击弹`、`超级暴击弹`
  - `暴击弹`(Crit Cannon): 对指定敌方目标造成2点伤害，30%概率造成2倍暴击。冷却: 2回合
  - `超级暴击弹`(Super Crit Cannon): 对指定敌方目标造成3点伤害，40%概率造成2倍暴击，20%概率造成3倍暴击，当船的生命低于6时永久失效。冷却: 4回合
  - 技能: `狂暴`(Fury)，对指定己方目标施加1层`狂暴`效果。冷却: 3回合
- `敏捷船`(Swift Ship): 15点生命，配备`炮弹1`、`炮弹2`、`炮弹3`
  - 特性: 受到攻击时有25%概率闪避
  - 技能: `闪避`(Dodge)，对指定己方目标施加2回合`闪避`效果。冷却: 3回合
- `霰弹船`(Grapeshot Ship): 18点生命，配备`炮弹1`、`炮弹2`、`炮弹3`
  - 技能1: `霰弹`(Grapeshot)，攻击性技能，对所有敌方目标造成2点伤害。冷却: 2回合
  - 技能2: `超级霰弹`(Super Grapeshot)，攻击性技能，对所有敌方目标造成4点伤害。冷却: 5回合
- `小型自爆船`(Small Explosive Ship): 5点生命
  - 特性: 不受`眩晕`影响
  - 技能: `小型自爆`(Small Explode)，攻击性技能，对指定敌方目标造成5点伤害，同时自己死亡。若有`护盾`，则`护盾`造成等同于`护盾`血量的攻击。此技能不受`狂暴`效果加成，且无法被`闪避`。初始冷却: 1回合
- `中型自爆船`(Medium Explosive Ship): 10点生命
  - 特性: 不受`眩晕`影响
  - 技能: `中型自爆`(Medium Explode)，攻击性技能，对指定敌方目标造成8点伤害，并对相邻序号目标造成4点溅射伤害，同时自己死亡。若有`护盾`，则`护盾`对中心目标造成等同于`护盾`血量的攻击，对相邻序号目标造成等同于`护盾`血量50%的攻击。此技能不受`狂暴`效果加成，且无法被`闪避`。初始冷却: 2回合
- `大型自爆船`(Big Explosive Ship): 15点生命
  - 特性: 不受`眩晕`影响
  - 技能: `大型自爆`(Big Explode)，攻击性技能，对指定敌方目标造成12点伤害，并对相邻序号目标造成6点溅射伤害，同时自己死亡。若有`护盾`，则`护盾`对中心目标造成等同于`护盾`血量的攻击，对相邻序号目标造成等同于`护盾`血量50%的攻击。此技能不受`狂暴`效果加成，且无法被`闪避`。初始冷却: 3回合
- `鱼雷船`(Torpedo Ship): 15点生命，配备`炮弹1`、`鱼雷`、`鱼雷`
  - `鱼雷`(Torpedo): 30%概率对指定敌方目标造成8点伤害，并对该目标施加3层`燃烧`效果。冷却: 2回合
- `点火船`(Igniting Ship): 20点生命，配备`燃烧弹`、`燃烧弹`
  - `燃烧弹`(Burning Cannon): 对指定敌方目标造成2点伤害，并对该目标施加2层`燃烧`效果，当船的生命低于6时永久失效。冷却: 3回合
  - 技能1: `点火`(Ignite)，对指定2个敌方目标分别施加1回合`燃烧`效果。冷却: 3回合
  - 技能2: `煽风点火`(Blow)，限定技，攻击性技能，对指定敌方目标造成等同于`燃烧`层数的伤害，并使`燃烧`层数翻倍。
- `随机船`(Random Ship): 随机11-20点生命，初始随机拥有1-5点`护盾`，配备`偏心弹`、`随机炮弹`、`随机治疗弹`
  - `偏心弹`(Biased Cannon): 指定一个敌方目标，50%概率对该敌方造成3点伤害，分别25%概率对相邻序号目标造成3点伤害。冷却: 2回合
    - 若相邻序号目标不存在或已死亡，则无法造成对应效果
  - `随机炮弹`(Random Cannon): 随机对敌方1-3个目标造成1-5点伤害。冷却: 3回合
  - `随机治疗弹`(Random Heal Cannon): 使指定己方目标随机回复1-5点生命。冷却: 2回合
  - 技能: `随机技能`(Random Buff)，指定一个己方目标，对其施加2层以下特殊效果中随机一种: `护盾`、`免疫`、`吸血`、`治疗`、`狂暴`、`闪避`、`隐身`、`眩晕`、`燃烧`。冷却: 2回合
- `幽灵船`(Specter Ship): 15点生命，配备`幽灵弹`、`幽灵弹`
  - 特性: 可以给自身叠加`幽灵`(specter)效果，至多叠加5层。每一层`幽灵`可以为其增加10%减伤效果与10%闪避效果。
  - `幽灵弹`(Specter Cannon): 对指定敌方目标造成1点伤害，自身叠加1层`幽灵`。冷却: 1回合
  - 技能1: `幽灵附身`(Specter)，自身叠加2层`幽灵`。冷却: 3回合
  - 技能2: `隐身`(Hide)，消耗1层`幽灵`，给自身施加1回合`隐身`效果。无冷却
  - 技能3: `幽灵引爆`(Specter Explode)，攻击性技能，对指定敌方目标造成(`幽灵`层数+2)的伤害，并消耗所有`幽灵`层数。冷却: 3回合
  - 技能4: `超级幽灵引爆`(Super Specter Explode)，限定技，攻击性技能，对指定敌方目标造成(`幽灵`层数×3+5)的伤害，对相邻序号目标造成(`幽灵`层数×10%)比例的溅射伤害，同时消耗所有`幽灵`层数。
- `刺客船`(Assassin Ship): 12点生命，配备`炮弹1`、`炮弹2`
  - 特性1: 当生命大于等于9时，拥有技能1；当生命小于9大于等于5时，拥有技能2；当生命小于5时，拥有技能3
  - 特性2: 不受`眩晕`影响
  - 特性3: 当生命大于等于5时，本体受到的伤害减20%；当生命小于5时，本体受到的伤害减1
  - 技能1: `献祭`(Sacrifice)，攻击性技能，对指定敌方目标造成2点伤害，自身失去2点生命。无冷却
  - 技能2: `桎梏`(Lock)，对指定敌方目标施加1回合`锁定`效果。冷却: 2回合
  - 技能3: `突刺`(Stab)，攻击性技能，对指定敌方目标随机造成5-15点伤害，仅当该目标在该回合前存活且在该回合后死亡时，80%概率自身存活，否则自身死亡。无冷却
- `发育船`(Development Ship): 12点生命，配备`炮弹1`、`炮弹2`、`炮弹3`
  - 特性: 每次攻击或受到伤害时随机将`2倍暴击率`、`闪避率`、`减伤率`中的一个提高10%，初始值为0，最大提高到50%，优先提高未达到上限的项
  - `狂暴`效果比`2倍暴击率`优先结算
  - `闪避`效果与`闪避率`结算时直接相加
- `炸弹船`(Bomb Ship): 16点生命
  - 特性1: 由于携带炸弹过多，每一回合有15%概率炸掉自身8点生命(被`眩晕`时不会触发)
  - 特性2: 每一回合可以使用2个`技能`
  - 技能1: `定时炸弹`(Time Bomb), 对指定敌方目标施加`定时炸弹`。冷却: 2回合
  - 技能2: `不定时炸弹`(Untime Bomb), 对指定敌方目标施加`不定时炸弹`。冷却: 2回合
  - 技能3: `小炸弹`(Small Bomb), 对指定敌方目标施加`小炸弹`。冷却: 2回合
  - 技能4: `大炸弹`(Big Bomb), 对指定敌方目标施加`大炸弹`。冷却: 2回合

特殊效果: (同一类型同时只能存在一个)
- `眩晕`(stunned): 负面效果，船在`眩晕`状态时无法行动，且冷却不会恢复
  - `眩晕`效果**可以**叠加持续时间
- `护盾`(shield): `护盾`可以抵挡攻击，且有`护盾`时船不受`眩晕`影响，不会被施加`炸弹`(已经存在的`炸弹`仍然可以产生效果)
  - 护盾的生命值**可以**叠加
  - 攻击`护盾`时溢出伤害**不会**攻击到本体
- `反伤`: 受到攻击时，攻击方会受到正比于攻击力的伤害
  - 攻击`护盾`时溢出伤害也会参与`反伤`
  - `反伤`的攻击没有攻击方
- `免疫`(immune): 移除所有`负面效果`，且在此期间不受`负面效果`影响，不会被施加`炸弹`(已经存在的`炸弹`仍然可以产生效果)
  - `免疫`效果**可以**叠加持续时间
- `吸血`(suck): 攻击时，可以回复攻击力100%的生命值
  - `吸血`效果**可以**叠加持续时间
- `治疗`(heal): 每一回合自身回复2点生命
  - `治疗`效果**可以**叠加持续时间
- `狂暴`(fury): 下一次攻击必定造成2倍暴击
  - `狂暴`效果**可以**叠加层数，每次攻击后会减少1层
- `闪避`(dodge): 受到攻击时有25%概率闪避
  - 若船本身有闪避特性，则**闪避概率**叠加
  - `闪避`效果**可以**叠加持续时间
- `燃烧`(burn): 负面效果，每一回合扣除等同于`燃烧`层数的生命
  - `燃烧`效果**可以**叠加层数，每一回合减少1层
  - `燃烧`的伤害没有攻击方
- `隐身`(hide): 受到攻击时100%概率闪避
  - `隐身`效果**可以**叠加持续时间
- `锁定`(lock): 负面效果，受到攻击时无视护盾，且无法闪避
  - `锁定`效果**可以**叠加持续时间

附属物: (同一类型可以同时存在多个)
- `定时炸弹`(time bomb): 炸弹，在3回合后爆炸，使携带者死亡
  - `休息`时有75%概率可以拆除
- `不定时炸弹`(untime bomb): 炸弹，每一回合有30%概率爆炸，使携带者死亡
  - `休息`时有75%概率可以拆除
- `小炸弹`(small bomb): 炸弹，每一回合扣除3点生命
  - `休息`时有75%概率可以拆除
- `大炸弹`(big bomb): 炸弹，每一回合扣除25%生命值上限的生命
  - `休息`时有75%概率可以拆除

特殊机制: 
- 可以攻击已经死亡的船，并且仍然可以获得对应效果
- 攻击伤害可以溢出
- 只有船在回合结束后所在阶段拥有的`技能`会更新冷却，其余`未激活技能`(hidden skill)不会更新冷却
- **攻击时判定顺序**：`眩晕`->`伤害`->`回血`
- **结算顺序**: 拆除炸弹->攻击->攻击性技能->更新冷却/触发炸弹/炸弹船自爆->辅助性技能
- 若200回合时仍未分出胜负，则为平局

### 格斗模式 (battle)

初始玩家1有3艘`中级船`和1艘`低级船`，玩家2有4艘`中级船`，进行对战。

### 高级模式 (advanced)

每一艘船有一定的费用，如下:
- `高级船`: 4
- `中级船`: 2
- `初级船`: 1
- `防御船`: 5
- `法师船`: 5
- `治疗船`: 5
- `暴击船`: 3
- `敏捷船`: 3
- `霰弹船`: 4
- `小型自爆船`: 1
- `中型自爆船`: 2
- `大型自爆船`: 3
- `鱼雷船`: 3
- `点火船`: 4
- `随机船`: 3
- `幽灵船`: 4
- `刺客船`: 3
- `发育船`: 3
- `炸弹船`: 4

可以设定初始双方的金钱数量，其中先手方为后手方的85%，同时可以指定禁用一些船只。
双方利用这些金钱购买船只，之后进行对战。

### 沙盒模式 (sandbox)

可以自由设置两方的初始配置，同时可以设定其中一些玩家为电脑，进行对战。

### 随机模式 (random)

可以设定初始双方的金钱数量，设定其中一些玩家为电脑，其中先手方与后手方金钱的比例取决于双方是人还是电脑，同时可以指定禁用一些船只。
系统按照金钱和禁用列表随机生成两方的船只，保证剩余钱数无法再买任何一艘船，之后双方进行对战。

### boss战 (boss)

可以选择一个`boss`作为玩家2，由电脑操控。玩家1的金钱数量为`boss`费用的65%，可以指定禁用一些船只。
系统按照金钱和禁用列表随机生成玩家1的船只，保证剩余钱数无法再买任何一艘船，之后进行对战。

`boss`有以下种类:
- `缝合怪`(Concatenation Boss): 60点生命，配备`炮弹1`、`炮弹2`、`炮弹3`、`炮弹4`、`炮弹5`、`分裂弹`、`眩晕弹`、`爆炸弹`、`治疗弹`、`暴击弹`、`超级暴击弹`、`鱼雷`，初始拥有20点护盾
  - 费用: 40
  - 技能: `护盾`、`治疗`、`狂暴`、`闪避`、`霰弹`
  - 特性1: 每回合可以使用4个`炮弹`或`技能`
  - 特性2: 不受`眩晕`影响
  - 特性3: 拥有`护盾`时，`护盾`有100%`反伤`效果
  - 特性4: 每回合自身回复2点生命
  - 特性5: 受到攻击时有25%概率闪避
  - 特性6: 当生命值大于30时，本体受到的伤害减1；当生命值小于等于30时，本体受到的伤害减20%

### 测试模式 (test)

可以通过修改代码进行一些测试