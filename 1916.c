//도시의 개수
//버스의 개수
//버스의 정보
//출발도시의 번호 , 도착도시의 번호, 버스비용
#include <stdio.h>

int main(){
	int n,m,p_start,p_end,i,j;
	int data[1000][1000] = {0};
	scanf("%d %d",&n,&m);
	for(i=0; i<m; i++){
		for(j=0; j<3; j++){
			scanf("%d", &data[i][j]);
		}
	}
	
	scanf("%d %d",&p_start,&p_end);
	int pay_save=0,pay_total; 
	for(i=0; i<m; i++){
		if(data[i][0] == p_start && data[i][2] == p_end){
			pay_total = data[i][2];
		}
		printf("%d\n",pay_total );
		for(j=i+1; j<m; j++){
			if(data[i][0] == p_start && data[i][1] == data[j][0] && data[j][1] == p_end){	
				pay_save = pay_total;				
				pay_total = data[i][2] + data[j][2];
			}
			if(pay_save > pay_total){
					pay_save = pay_total;
			}
		}
		
	}
	
}
