#include <iostream>

#include <Eigen/Core>
#include <Eigen/Geometry>

using namespace std;

#define PI (3.1415926535897932346f)

int main(int argc, char **argv)
{
    /**** 1. 旋转向量 ****/
    cout << endl << "********** AngleAxis **********" << endl;
    Eigen::AngleAxisd rotation_vector1 (M_PI/4, Eigen::Vector3d(0, 0, 1));      //1.0 初始化旋转向量,沿Z轴旋转45度的旋转向量

    //1.1 旋转向量转换为旋转矩阵
    Eigen::Matrix3d rotation_matrix1 = Eigen::Matrix3d::Identity();             //旋转向量用matrix()转换成旋转矩阵
    rotation_matrix1 = rotation_vector1.matrix();
    cout << "rotation matrix1 =\n" << rotation_matrix1 << endl;

    rotation_matrix1 = rotation_vector1.toRotationMatrix();                     //或者由罗德里格公式进行转换
    cout << "rotation matrix1 =\n" << rotation_matrix1 << endl;

    /*1.2 旋转向量转换为欧拉角*/
    Eigen::Vector3d eulerAngle1 = rotation_vector1.matrix().eulerAngles(2,1,0); //将旋转向量转换为旋转矩阵,再由旋转矩阵转换为欧拉角,详见旋转矩阵转换为欧拉角
    cout << "eulerAngle1, z y x: " << eulerAngle1 << endl;

    /*1.3 旋转向量转四元数*/
    Eigen::Quaterniond quaternion1(rotation_vector1);
    cout << "quaternion1 x: " << quaternion1.x() << endl;
    cout << "quaternion1 y: " << quaternion1.y() << endl;
    cout << "quaternion1 z: " << quaternion1.z() << endl;
    cout << "quaternion1 w: " << quaternion1.w() << endl;

    Eigen::Quaterniond quaternion1_1;                                           //或者
    quaternion1_1 = rotation_vector1;
    cout << "quaternion1_1 x: " << quaternion1_1.x() << endl;
    cout << "quaternion1_1 y: " << quaternion1_1.y() << endl;
    cout << "quaternion1_1 z: " << quaternion1_1.z() << endl;
    cout << "quaternion1_1 w: " << quaternion1_1.w() << endl;


    /**** 2. 旋转矩阵 *****/
    cout << endl << "********** RotationMatrix **********" << endl;
    Eigen::Matrix3d rotation_matrix21;                                                  //2.0 旋转矩阵初始化
    Eigen::Matrix3d rotation_matrix22;
    Eigen::Matrix3d rotation_matrix2;
    rotation_matrix21 << 1, 0, 0, 0, -0.707107, -0.707107, 0, 0.707107, -0.707107;
    rotation_matrix22 << 0.707107, -0.707107, 0, 0.707107, 0.707107, 0, 0, 0, 1;
    rotation_matrix2 = rotation_matrix21*rotation_matrix22;

    Eigen::Matrix3d rotation_matrix23;                                                  //2.1 旋转矩阵初始化
    Eigen::Matrix3d rotation_matrix24;
    Eigen::Matrix3d rotation_matrix25;
    rotation_matrix23 << -0.707107, 0, -0.707107, 0, 1, 0, 0.707107, 0, -0.707107;
    rotation_matrix24 << -0.707107, -0.707107, 0, 0.707107, -0.707107, 0, 0, 0, 1;
    rotation_matrix25 = rotation_matrix23*rotation_matrix24;

    Eigen::Matrix3d rotation_matrix2_1 = Eigen::Matrix3d::Identity();                   //或直接单位矩阵初始化

    //2.1 旋转矩阵转换为欧拉角
    Eigen::Vector3d euler_angles = rotation_matrix2.eulerAngles(2, 1, 0);               //ZYX顺序，即先绕x轴roll,再绕y轴pitch,最后绕z轴yaw,0表示X轴,1表示Y轴,2表示Z轴
	cout << "-------注意:输出的结果为rpy的相反顺序" << endl;
    cout << "yaw(z) pitch(y) roll(x) = " << euler_angles.transpose() << endl;

	Eigen::Vector3d euler_angles1 = rotation_matrix25.eulerAngles(2, 1, 0);
    cout << "yaw(z) pitch(y) roll(x) = " << euler_angles1.transpose() << endl;

    //2.2 旋转矩阵转换为旋转向量
    Eigen::AngleAxisd rotation_vector2;
    rotation_vector2.fromRotationMatrix(rotation_matrix2);
    cout << "rotation_vector2 " << "angle is: " << rotation_vector2.angle() * (180 / M_PI)
                                << " axis is: " << rotation_vector2.axis().transpose() << endl;

    Eigen::AngleAxisd rotation_vector2_1(rotation_matrix2);     //或者
    cout << "rotation_vector2_1 " << "angle is: " << rotation_vector2_1.angle() * (180 / M_PI)
                                  << " axis is: " << rotation_vector2_1.axis().transpose() << endl;

    //2.3 旋转矩阵转换为四元数
    Eigen::Quaterniond quaternion2(rotation_matrix2);
    cout << "quaternion2 x: " << quaternion2.x() << endl;
    cout << "quaternion2 y: " << quaternion2.y() << endl;
    cout << "quaternion2 z: " << quaternion2.z() << endl;
    cout << "quaternion2 w: " << quaternion2.w() << endl;

    Eigen::Quaterniond quaternion2_1;                           //或者
    quaternion2_1 = rotation_matrix2;
    cout << "quaternion2_1 x: " << quaternion2_1.x() << endl;
    cout << "quaternion2_1 y: " << quaternion2_1.y() << endl;
    cout << "quaternion2_1 z: " << quaternion2_1.z() << endl;
    cout << "quaternion2_1 w: " << quaternion2_1.w() << endl;


    /**** 3. 欧拉角 ****/
    cout << endl << "********** EulerAngle **********" << endl;
    Eigen::Vector3d ea(-2.024, 0.803, 1.839);                               //3.0 初始化欧拉角(Z-Y-X，即RPY, 先绕x轴roll,再绕y轴pitch,最后绕z轴yaw)

    //3.1 欧拉角转换为旋转矩阵
    Eigen::Matrix3d rotation_matrix3;
    rotation_matrix3 = Eigen::AngleAxisd(ea[0], Eigen::Vector3d::UnitZ()) *
                       Eigen::AngleAxisd(ea[1], Eigen::Vector3d::UnitY()) *
                       Eigen::AngleAxisd(ea[2], Eigen::Vector3d::UnitX());
    cout << "rotation matrix3 =\n" << rotation_matrix3 << endl;

    //3.2 欧拉角转换为四元数,
    Eigen::Quaterniond quaternion3;
    quaternion3 = Eigen::AngleAxisd(ea[0], Eigen::Vector3d::UnitZ()) *
                  Eigen::AngleAxisd(ea[1], Eigen::Vector3d::UnitY()) *
                  Eigen::AngleAxisd(ea[2], Eigen::Vector3d::UnitX());
    cout << "quaternion3 x: " << quaternion3.x() << endl;
    cout << "quaternion3 y: " << quaternion3.y() << endl;
    cout << "quaternion3 z: " << quaternion3.z() << endl;
    cout << "quaternion3 w: " << quaternion3.w() << endl;

    //3.3 欧拉角转换为旋转向量
    Eigen::AngleAxisd rotation_vector3;
    rotation_vector3 = Eigen::AngleAxisd(ea[0], Eigen::Vector3d::UnitZ()) *
                       Eigen::AngleAxisd(ea[1], Eigen::Vector3d::UnitY()) *
                       Eigen::AngleAxisd(ea[2], Eigen::Vector3d::UnitX());
    cout << "rotation_vector3 " << "angle is: " << rotation_vector3.angle() * (180 / M_PI)
                                << " axis is: " << rotation_vector3.axis().transpose() << endl;


    /**** 4.四元数 ****/
    cout << endl << "********** Quaternion **********" << endl;
    Eigen::Quaterniond quaternion4(0.92388, 0, 0, 0.382683);                //4.0 初始化四元素,注意eigen Quaterniond类四元数初始化参数顺序为w,x,y,z

    //4.1 四元数转换为旋转向量
    Eigen::AngleAxisd rotation_vector4(quaternion4);
    cout << "rotation_vector4 " << "angle is: " << rotation_vector4.angle() * (180 / M_PI)
                                << " axis is: " << rotation_vector4.axis().transpose() << endl;

    Eigen::AngleAxisd rotation_vector4_1;                                   //或者
    rotation_vector4_1 = quaternion4;
    cout << "rotation_vector4_1 " << "angle is: " << rotation_vector4_1.angle() * (180 / M_PI)
                                  << " axis is: " << rotation_vector4_1.axis().transpose() << endl;

    //4.2 四元数转换为旋转矩阵
    Eigen::Matrix3d rotation_matrix4;
    rotation_matrix4 = quaternion4.matrix();
    Eigen::Matrix3d rotation_matrix4_1;
    rotation_matrix4_1 = quaternion4.toRotationMatrix();
    cout << "rotation matrix4 =\n" << rotation_matrix4 << endl;
    cout << "rotation matrix4_1 =\n" << rotation_matrix4_1 << endl;

    //4.4 四元数转欧拉角(Z-Y-X，即RPY)
    Eigen::Vector3d eulerAngle4 = quaternion4.matrix().eulerAngles(2,1,0);
    cout << "yaw(z) pitch(y) roll(x) = " << eulerAngle4.transpose() << endl;

    return 0;
}
