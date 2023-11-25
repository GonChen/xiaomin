#include <stdio.h>

// static void query_compare(int amount, int year, const char* product, int flag)
// {
//     // 将入参拼接得到预期结果
//     expstr[128];
//     CLEAR(expstr);
//     sprintf(expstr, "账户余额(元):%d,当前时间(年):%d,已购入的理财产品:%s", amount, year, product);
//     // 调用查询接口获取结果
//     ssize_t realRecvLen = SendCmd("query()", g_recvBuffer, MAX_RECV_BUFFER);
//     // 将预期与查询结果比较
//     if (flag == 0) {
//         assert_true(strcmp(expstr, g_recvBuffer) == 0);
//     }

// }

static void query_compare(const char* exp_str, int flag)
{    
    // 调用查询接口获取结果
    ssize_t realRecvLen = SendCmd("query()", g_recvBuffer, MAX_RECV_BUFFER);
    // 将预期与查询结果比较
    if (flag == 0) {
        assert_true(strcmp(expstr, g_recvBuffer) == 0);
    } else {
        assert_true(strcmp(expstr, g_recvBuffer) != 0);
    }

}
static void query_golden()
{
    // 调用查询接口获取结果
    ssize_t realRecvLen = SendCmd("query()", g_recvBuffer, MAX_RECV_BUFFER);
    printf("g_recvBuffer: %s\r", g_recvBuffer);

}

static void construct_product_str(product_name, start, end)
{
    sprintf(product_A[i], "产品编号:%s,购入时间:%d,到期时间:%d;", product_name[i], start[i], end[i]);
    sprintf(expstr, "账户余额(元):%d,当前时间(年):%d,已购入的理财产品:%s", amount, year, "");
}

static void construct_golden_p1(amount, year, p1_str)
{
    sprintf(expstr, "账户余额(元):%d,当前时间(年):%d,已购入的理财产品:%s", amount, year, p1_str);
}

static void  construct_golden_p2(amount, year, p1_str, p2_str)
{
    sprintf(expstr, "账户余额(元):%d,当前时间(年):%d,已购入的理财产品:%s,%s", amount, year, p1_str, p2_str);
}

static void  construct_golden_p3(amount, year, p1_str, p2_str, p3_str)
{
    sprintf(expstr, "账户余额(元):%d,当前时间(年):%d,已购入的理财产品:%s,%s,%s", amount, year, p1_str, p2_str, p3_str);
}

int main() {
    // printf("Hello world!\n");
    int amount = 0;
    int year = 0;
    const int charge1 = 1;
    const int charge2 = 10;
    
    charge(charge1);
    amount = amount + charge1;
    
    // 构建golden
    {
        charge(1000);
        char exp_str[] = "账户余额(元):1000,当前时间(年):0,已购入的理财产品:xxx";
        query(exp_str, 0);
    }
    {
        charge(5000);
        char exp_str[] = "账户余额(元):1000,当前时间(年):0,已购入的理财产品:xxx1";
        query(exp_str, 0);
    }
    {
        charge(5);
        char exp_str[] = "账户余额(元):1000,当前时间(年):0,已购入的理财产品:xxx2";
        query(exp_str, 0);
    }
    {
        charge(1000);
        char exp_str[] = "账户余额(元):1000,当前时间(年):0,已购入的理财产品:xxx3";
        query(exp_str, 0);
    }
    {
        charge(1000);
        char exp_str[] = "账户余额(元):1000,当前时间(年):0,已购入的理财产品:xxx5";
        query(exp_str, 0);
    }
    
    



    // 第一种：参数传入封装的query接口，在query接口中传入参数，在query中使用sprintf进行拼接，并比较

    // 第二种：不封装query接口，直接给出一整个字符串，并与query接口返回值比较

    char exp_str[200];

    // 第三种：封装一个query1接口打印返回结果，但不进行判断；
    // 封装query2接口，传入预期结果，并与query返回结果进行比较;
    // 第一遍执行调query1得到预期结果，然后将打印结果拷贝到query2的入参，


    //

    query();

}