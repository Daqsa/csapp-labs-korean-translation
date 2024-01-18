 /***************************************************************************
 * 닥터 이블의 교활한 폭탄, 버전 1.1
 * 저작권 2011, 닥터 이블 주식회사. 모든 권리 보유.
 *
 * 라이센스:
 *
 * 닥터 이블 인코퍼레이티드(이하 가해자)는 이에 따라 귀하(이하
 * 피해자)에게 이 폭탄을 사용할 수 있는 명시적인 권한을 부여합니다. 이것은
 * 한시적 라이선스이며, 피해자의 사망으로 만료됩니다.
 * 가해자는 손상, 좌절에 대해 어떠한 책임도 지지 않습니다,
 * 정신 이상, 벌레 눈, 손목 터널 증후군, 수면 부족, 또는 기타
 * 피해자에 대한 피해에 대해 책임을 지지 않습니다. 가해자가 크레딧을 받고자 하는 경우를 제외하고 말입니다.
 * 피해자는 이 폭탄 소스 코드를 다음과 같은 사람에게 배포할 수 없습니다.
 * 피해자는 리버스 엔지니어링, "문자열" 실행, 디컴파일, 암호 해독 또는
 * 기타 기술을 사용하여 폭탄에 대한 지식을 얻거나 폭탄을 해체할 수 없습니다. 
 * 이 프로그램을 다룰 때는 방폭 복장을 착용할 수 없습니다.   
 * 가해자는 가해자의 빈약한 유머 감각에 대해 사과하지 않습니다.
 * 이 라이선스는 법에 의해 폭탄이 금지된 곳에서는 무효입니다.
 ***************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "support.h"
#include "phases.h"

/* 
 * 스스로에게 남기는 메세지: 피해자들이 무슨 일이 일어나는지 알 수 없게 하기 위해, 
 * 모두 스펙타클하고 광기 어린 폭발 속에 휩싸이도록 하기 위해
 * 이 파일을 지우는걸 기억하도록. -- 닥터 이블
 */

FILE *infile;

int main(int argc, char *argv[])
{
    char *input;

    /* 스스로에게 남기는 메세지: 이 폭탄을 윈도우로 포팅하고 
     * 환상적인 GUI를 추가하는 것을 잊지 말자. */

    /* 인자 없이 실행하면 폭탄은 표준 입력으로부터 줄을 읽는다. */
    if (argc == 1) {  
	infile = stdin;
    } 

    /* 폭탄을 인자 하나 <파일>로 실행하면 <파일>에서 EOF까지 읽은 다음 
     * 표준 입력으로 전환한다. 따라서 각 단계를 해체할 때 문자열을
     * <파일>에 추가하면 다시 입력할 필요가 없다. */
    else if (argc == 2) {
	if (!(infile = fopen(argv[1], "r"))) {
	    printf("%s: Error: Couldn't open %s\n", argv[0], argv[1]);
	    exit(8);
	}
    }

    /* 명령줄 인자를 2개 이상 사용하여 폭탄을 호출할 수 없다. */
    else {
	printf("Usage: %s [<input_file>]\n", argv[0]);
	exit(8);
    }

    /* 폭탄을 해체하기 어렵게 만들도록 모든 종류의 비밀 작업을 수행한다. */
    initialize_bomb();

    printf("Welcome to my fiendish little bomb. You have 6 phases with\n");
    printf("which to blow yourself up. Have a nice day!\n");

    /* 흠... 페이즈가 여섯개 있으면 한개 있는것보다 더 안전하겠지! */

    input = read_line();             /* 입력값 받기                  */
    phase_1(input);                  /* 페이즈 실행하기               */
    phase_defused();                 /* 젠장! 알아내버렸잖아!
				      * 어떻게 해체했는지 알고싶군. */
    printf("Phase 1 defused. How about the next one?\n");

    /* 두 번째 페이즈는 더 어렵지. 아무도 이 폭탄을 해체하는 방법을 알아내지 못할거야... */
    input = read_line();
    phase_2(input);
    phase_defused();
    printf("That's number 2.  Keep going!\n");

    /* 지금까지는 너무 쉬운 것 같군. 코드를 좀 더 복잡하게 하면 사람들을 혼란스럽게 하겠지. */
    input = read_line();
    phase_3(input);
    phase_defused();
    printf("Halfway there!\n");

    /* 그래? 흥, 너 수학 잘하냐? 이 매콤한 문제를 풀어보라고! */
    input = read_line();
    phase_4(input);
    phase_defused();
    printf("So you got that one.  Try this one.\n");
    
    /* 메모리 속에서 우린 돌고 도네, 멈추는 순간 폭탄도 터지지! */
    input = read_line();
    phase_5(input);
    phase_defused();
    printf("Good work!  On to the next...\n");

    /* 이 페이즈는 아무도 이전 페이즈를 통과하지 못할거니까 사용하지 않을 거야.
     * 하지만 만일을 대비해 이 페이즈를 더 어렵게 만들겠어. */
    input = read_line();
    phase_6(input);
    phase_defused();

    /* 와, 해냈군! 하지만 뭔가... 빠진 게 있지 않나? 
     * 아마도 네가 간과한 게 있을지도?  무아하하하하! */
    
    return 0;
}
