#ros2_tutorial
## チュートリアル1
### 実行手順
```bash
ros2 launch ros2_tutorial tutorial001.launch.py
```

### 解説
1つのノードを複数のclass（SplitMainSubscriber Class、SplitSubSubscriber Class、NumSubscriber Class）に分割。  
それぞれのclassからsubscribeしたデータを監視できる。  

* SplitMainSubscriber：メインのクラス。このクラスをweak_ptrで持つことで同じノードとして動作する。
* SplitSubSubscriber：サブのクラス
* NumSubscriber：subscribeするためのクラス

```python
/*
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
*/
```
