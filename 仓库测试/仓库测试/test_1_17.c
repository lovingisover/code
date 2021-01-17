/**
* Note: The returned array must be malloced, assume caller calls free().
*/
double* twoSum(int n, int* returnSize){

	int dp[15][70] = { 0 };

	for (int i = 1; i <= 6; i++) {
		dp[1][i] = 1;
	}
	for (int i = 2; i <= n; i++) {
		for (int j = i; j <= 6 * i; j++) {
			for (int cur = 1; cur <= 6; cur++) {
				if (j - cur <= 0) {
					break;
				}
				dp[i][j] += dp[i - 1][j - cur];//��n�����ӵĵ���Ϊcur������ǰn-1��ɸ�ӵĵ�����Ϊĳ��ȷ������ʱ�����ж��������ӵ��������
			}
		}
	}
	int all = pow(6, n);
	int count = 0;
	double *res = (double *)malloc(sizeof(double)* (6 * n + 1));
	for (int i = n; i <= 6 * n; i++) {//��С����Ϊn������ȫΪ1�����ȫΪ6
		res[i - n] = dp[n][i] * 1.0 / all;
		count++;
	}
	*returnSize = count;
	return res;

}