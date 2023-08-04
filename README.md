# Using

## 1.在当前工作空间下

```commandlind
source ./devel/setup.bash
roscd ur_description/urdf/
# xacro转urdf
rosrun xacro xacro ur5_robot.urdf.xacro > ur5.urdf --inorder
rosrun xacro xacro my_ur5_joint_limited_robot.urdf.xacro > my_ur5.urdf --inorder
# check urdf
check_urdf ur5.urdf
check_urdf my_ur5.urdf
# 写入pdf
urdf_to_graphiz ur5.urdf
urdf_to_graphiz my_ur5.urdf
# rviz可视化
roslaunch ur_description ur5_urdf_rviz.launch
roslaunch ur_description my_ur5_urdf_rviz.launch
```
