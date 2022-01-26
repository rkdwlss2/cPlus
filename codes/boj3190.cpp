////
////  boj3190.cpp
////  codes
////
////  Created by 강명진 on 2022/01/25.
////
//
//#include <iostream>
//#include <queue>
//using namespace std;
//
//int board[101][101]; // 보드 배열
//int n; // n*n 행열 크기
//int tx,ty; // 꼬리좌표
//int hx,hy; // 머리좌표
//int dir=0; // 뱀의 방향
//int dx[4]={0,1,0,-1}; // 이동할 방향 벡터 x
//int dy[4]={1,0,-1,0}; // 이동할 방향 벡터 y
//
//int direction[10001]; // 이동방향 배열
//queue<pair<int,int>> q; // 뱀의 이동했던 위치를 저장하는 queue자료 구조 : 꼬리가 중요하기 때문에 queue를 썼고, pair을 이용해서 x,y로 나타냄 ex) pair의 first 는 x, pair의 second는 y
////  x y
////
//// {3 2}                  {3 2} 사과가 없다면 꼬리를 지움                 {3 2}
//// {2 2}                  {2 2}                                     {2 2}
//// {1 2} (방향 전환됨) ->.   {1 2}                            ->       {1 2}
//// {0 2}                  {0 2}                                     {0 2}
//// {0 1}                  {0 1}                                     {0 1}
//// {0 0}.                 {0 0} q.pop()을 하면 마지막이 삭제됨
//
//int main(){
//    ios::sync_with_stdio(0); //c++에서 cin,cout은 속도가 느리기 때문에 설정
//    cin.tie(0); //c++에서 cin,cout은 속도가 느리기 때문에 설정
//    cin>>n; // 보드 크기 입력으로 받음
//    int K; // 사과의 갯수
//    cin>>K; // 사과의 갯수 받음
//    tx=0;ty=0;hx=0;hy=0; // 꼬리와 머리 좌표 셋팅
//    board[0][0]=2; // 처음에 0,0에는 무조건 뱀이 위치해 있어서 기본 셋팅
//    q.push({0,0}); // q에도 뱀이 있는 위치를 저장해야 하기 때문에 첫 위치 저장
//    while(K--){ //사과 위치 입력 받고 사과는 보드에 1로 저장함
//        int a,b;
//        cin>>a>>b;
//        board[a-1][b-1]=1;
//    }
//    int L; // 변경 방향 갯수
//    cin>>L;
//    while(L--){ // 변경 방향을 direction배열에 저장함 L일경우 1로 D일경우 2로 저장
//        int a;
//        char b;
//        cin>>a>>b;
//        if (b=='L'){
//            direction[a]=1;
//        }else{
//            direction[a]=2;
//        }
//    }
//    int t=0; //시작 시간 0초
//    while(true){
//        int nx=hx+dx[dir]; //뱀이 이동할 x좌표 -> 기존 x좌표에 이동방향 dir으로 이동
//        int ny=hy+dy[dir]; //뱀이 이동할 y좌표 -> 기존 y좌표에 이동방향 dir으로 이동
//        if (nx<0||nx>=n||ny<0||ny>=n)break; //보드 밖으로 이동했으면 종료
//        if (board[nx][ny]==2)break; //자기 자신을 만날 경우 종료
//        if (board[nx][ny]==0){ // 사과가 없을때
//            auto now = q.front(); //꼬리는 queue의 front임
//            q.pop(); //꼬리를 없애도 되서 queue -> pop
//            int tmpX=now.first; //꼬리의 x좌표
//            int tmpY=now.second; //꼬리의 y좌표
//            board[tmpX][tmpY]=0; //꼬리를 빈칸으로
//        }
//        q.push({nx,ny}); //nx,ny 는 뱀이 이동할 좌표라서 queue에 저장
//        board[nx][ny]=2; //nx,ny 는 뱀이 있는 좌표
//        hx=nx; //head위치 설정
//        hy=ny;
//        t++; //시간 증가
//        if (direction[t]!=0){ //만약에 시간이 지났을때 방향을 바꿔야 한다면 (0이 아니면 방향을 바꿔 줘야 한다)
//            if (direction[t]==2){ // 만약에 D일경우 direction[t]을 2로 저장함
//                dir=(dir+1)%4; //애초에 dx에서 증가할수록 방향에서 +1하면 되서 더한다.. 여기서 방향은 항상 0,1,2,3이라 4의 나머지
//            }else{
//                dir=(4+dir-1)%4;//방향이 반대면 방향에서 -1해주면 된다.. 예를 들어 0일 경우 0+4-1의 나머지는 3이 된다
//            }
//        }
//    }
//    cout<<t+1<<'\n';// 예를 들어 8일 경우에 나중에 t=t+1해주기 때문에 마지막에 나와서 더해주면 된다..
//}
