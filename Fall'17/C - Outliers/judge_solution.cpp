#include <stdio.h>


#define max(a,b) (a > b ? a : b)
#define min(a,b) (a < b ? a : b)

int input_data[1000500];
int cumulative_sum[1000500];

//int test[] = {3, 13, 7, 5, 21, 23, 39, 23, 40, 23, 14, 12, 56, 23, 29};
//int test[] = {3, 5, 7, 12, 13, 14, 21, 23, 23, 23, 23, 29, 40, 56};
//int test[] = {1, 2, 3,4,5,6,7};
//int test[] = {1, 2, 3,4,5,6,7,8};


double get_median(int left, int right, int maxi){
		int size = right - left + 1;
		double median = -1;
		double median1 = -1;
		double median2 = -1;
		if(size % 2 != 0){
				int mid_point = (size+1)/2 + left - 1;
				for(int i = 0 ; i <= maxi ; i ++){
						if(mid_point <= cumulative_sum[i]){
								median = i;
								return median;
							}
				}

			}
		else{

				int mid_point = (size)/2 + left - 1;
				for(int i = 0 ; i <= maxi ; i ++){
						if(mid_point <= cumulative_sum[i]){
								median1 = i;
								if(mid_point+1 <= cumulative_sum[i]){
										median2 = i;
										median = (median1+median2)/2.0;
										return median;
									}
								else{
										for(int j = i + 1 ; j <= maxi ; j ++){
											if(mid_point+1 <= cumulative_sum[j]){
												median2 = j;
												median = (median1+median2)/2.0;
												return median;
											}
										}
									}

							}
				}
			}


		return median;

	}

int main(){

	 int N,T,v;

	 //freopen ("input01.txt","r",stdin);
    //freopen ("output01.txt","w",stdout);

		scanf("%d",&T);

		for(int t = 1  ; t <= T ; t ++){
				int total = 0; int mini = 1 << 30;
				int maxi = -1;double median  = -1;double q1 = -1;double q3 = -1;

				scanf("%d",&N);

				for(int j = 1 ; j <= N ;j ++){
						scanf("%d",&v);
						input_data[v]++;
						maxi = max(maxi,v);
						mini = min(mini,v);
						++total;
					}
				for(int i = mini ; i <= maxi ; i ++){
					cumulative_sum[i] += input_data[i] + cumulative_sum[i-1];
				}
				if(total % 2 != 0){
					median = get_median(1,total,maxi);
					q1 = get_median(1,total/2,maxi);
					q3 = get_median(total/2+2,total,maxi);
				}else{
					median = get_median(1,total,maxi);
					q1 = get_median(1,total/2,maxi);
					q3 = get_median(total/2+1,total,maxi);
				}

				double IQR = 1.5 * (q3 - q1);
				double F1 = q1 - IQR;
				double F2 = q3 + IQR;
				int outlier = 0;
				for(int i = maxi ; i >= 0 ; i --){
					if(i > F2 && input_data[i] > 0 ){
						outlier ++;
					}
					if(i < F1 && input_data[i] > 0 ){
							outlier ++;
					}
				}

				printf("Experiment %d: %.2lf %.2lf %.2lf %d\n",t,median,q1,q3,outlier);

				for(int i = 0 ; i<= maxi ;i++){
						input_data[i] = 0;
						cumulative_sum[i] = 0;
					}
		}

		return 0;
	}

