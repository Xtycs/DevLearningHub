//*题目：有 1、2、3、4 四个数字，能组成多少个互不相同且无重复数字的三位数？都是多少？
//*程序分析：可填在百位、十位、个位的数字都是 1、2、3、4，组成所有的排列后再去掉不满足条件的排列。
#include <stdio.h>
//个位units place 十位decade 百位hundreds place 千位kilobit 
int main(){
    for (int u = 1; u < 5; u++)
    {
        for (int d = 1; d < 5; d++)
        {
            for (int h = 1; h < 5; h++)
            {
                if(u!=d && u!=h && d!=h){
                    printf("%d%d%d\n", h, d, u);
                }
            }
        }
    }
    return 0;
}
