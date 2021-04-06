#include <stdio.h>

int main(){
	int a, b, Sa, Sb, ml;
	scanf("%d %d",&a,&b);
	scanf("%d %d %d",&Sa,&Sb,&ml);
	double aa,bb,aa_c,bb_c,aa_w,bb_w,cnt,sSb;
	sSb = Sb;
	aa = a;
	bb = b;
	double saveaa;
	aa_c = (aa/100) * Sa;
	bb_c = bb/100 * Sb;
	aa_w = Sa - aa_c;
	bb_w = Sb - bb_c;

	while (aa>=saveaa){
		Sb -= ml;
		saveaa = aa;
		aa_c = (aa/100 * (Sa - ml)) + (bb/100 * ml);
		aa = aa_c / Sa * 100;
		bb_c = bb/100 * Sb;
		bb = bb_c/sSb * 100;
		printf("%f %f\n",aa,saveaa);
		cnt++;
		if(cnt >= 50){
			printf("gg\n");
			break;
		}
	}
	printf("%f\n",cnt );

}