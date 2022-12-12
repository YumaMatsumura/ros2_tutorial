#ros2_tutorial
## チュートリアル1
### 実行手順
```bash
ros2 launch ros2_tutorial tutorial001.launch.py
```

### 解説
1つのノードを複数のclass（SplitMainSubscriber Class、SplitSubSubscriber Class、NumSubscriber Class）に分割。  
それぞれのclassからsubscribeしたデータを監視できる。  

* SplitMainSubscriber：メインのクラス。メインなのでサブに自分自身のポインタ（shared_from_this）を引数で渡す必要がある。このとき、shared_from_thisはコンストラクタでは呼べないことに注意。そのため、lifecycle_nodeとしている。また、NumSubscriberでサブスクライブしたデータをSplitSubSubscriberでも監視できるようにするため、SplitSubSubscriberにNumSubscriberのポインタを渡している。
* SplitSubSubscriber：サブのクラス。メインのクラスをweak_ptrで保持する。
* NumSubscriber：subscribeするためのクラス。メインのクラスをweak_ptrで保持する。トピックのサブスクライブをメインにするクラス。

```bash
#=== SplitSubscriber Node ======================#
|                                               |
|  #=======================#                    |
|  |                       | <----------+       |
|  |  SplitMainSubscriber  |            |       |
|  |                       | ----+   weak_ptr   |
|  #=======================#     |      |       |
|      |             ^      shared_ptr  |       |
|      |             |           |      |       |
|  shared_ptr        |           v      |       |             NormalPublisher Node
|      |             |     #=================#  |             #===================#
|      |             |     |                 |  |             |                   |
|      |             |     |  NumSubscriber  | <=== Topic === |  NormalPublisher  |
|      |             |     |                 |  |             |                   |
|      |             |     #=================#  |             #===================#
|      |          weak_ptr          ^           |
|      |             |              |           |
|      v             |         shared_ptr       |
|  #======================#         |           |
|  |                      |         |           |
|  |  SplitSubSubscriber  | --------+           |
|  |                      |                     |
|  #======================#                     |
|                                               |
#===============================================#
```
