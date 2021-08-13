#include <iostream>

using namespace std;

int N;
char map[6500][6500];

void print(){
    for(int i=1; i<=N; i++){
        for(int j=1; j<=2*N; j++)
            cout<<((map[i][j]=='*')?'*':' ');
        cout<<"\n";
    }
}
/*
                       *                        
                      * *                       
                     *****                      
                    *     *                     
                   * *   * *                    
                  ***** *****                   
                 *           *                  
                * *         * *                 
               *****       *****                
              *     *     *     *               
             * *   * *   * *   * *              
            ***** ***** ***** *****             
           *                       *            
          * *                     * *           
         *****                   *****          
        *     *                 *     *         
       * *   * *               * *   * *        
      ***** *****             ***** *****       
     *           *           *           *      
    * *         * *         * *         * *     
   *****       *****       *****       *****    
  *     *     *     *     *     *     *     *   
 * *   * *   * *   * *   * *   * *   * *   * *  
***** ***** ***** ***** ***** ***** ***** *****
출처
*/
void draw(int y , int x, int n){
    
    if(n == 3){
        map[y][x] = '*';
        map[y+1][x-1] = '*';
        map[y+1][x+1] = '*';
        for(int i=-2; i<=2; i++)
            map[y+2][x+i] = '*';
        return;
    }
    
    draw(y, x, n/2);
    draw(y+n/2, x-n/2, n/2);
    draw(y+n/2, x+n/2, n/2);

}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);

    // init
    cin>>N;

    // start!
    draw(1, N, N);

    // end
    print();

    return 0;
}