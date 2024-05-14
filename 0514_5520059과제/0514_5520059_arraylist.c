#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#define max_list_size 100

typedef int element;

typedef struct {
	element array[max_list_size];
	int size;
}arraylisttype;


//초기화 
init(arraylisttype* l) {
	l->size = 0;
}

void clear(arraylisttype* l) {
	init(l);
}


int is_full(arraylisttype* l) {

	//if (l->size >= max_list_size) return 1;
	//else return 0;
	return (l->size == max_list_size);
}


int is_empty(arraylisttype* l) {
	return (l->size == 0);
}

void insert(arraylisttype* l, int pos, element item) {

	if (!is_full(l) && (pos >= 0) && (pos <= l->size)) {
		for (int i = l->size - 1; i >= pos; i = i - 1) {
			l->array[i + 1] = l->array[i];
		}
		l->array[pos] = item;
		l->size = l->size + 1;
		printf("삽입 완료, 데이터 이동 횟수: ");
		count(l);
	}
}

void error(char* message) {
	fprintf(stderr, "%s\n", message);
}

void insert_last(arraylisttype* l, element item) {
	if (l->size == max_list_size) {
		error(" list overflow");
	}
	l->array[l->size++] = item;
}

void insert_first(arraylisttype* l, element item) {
	insert(l, 0, item);
}

element get_entry(arraylisttype* l, int pos) {
	if (pos > 0 && pos < l->size) return l->array[pos];
	else error("위치오류");
}

int get_length(arraylisttype* l) {
	return(l->size);
}


element delete(arraylisttype* l, int pos) {

	if (pos < 0 || pos >= l->size) {
		error("위치 오류");
	}
	else {
		element item = l->array[pos];
		for (int i = pos; i < (l->size - 1); i++) {
			l->array[i] = l->array[i + 1];
		}
		l->size = l->size - 1;
		printf("삽입 완료, 데이터 이동 횟수: ");
		count(l);
		return item;
	}

}

void print_list(arraylisttype* l) {
	int i;
	for (i = 0; i < l->size; i++) {
		printf("%d -> ", l->array[i]);
	}
	printf("NULL\n");
}


// count 
int count(arraylisttype* l) {
	int count = 0;
	for (int i = 0; i < l->size; i++) {
		if (l->array[i] != 0) {
			count++;
		}
	}
	printf("%d\n", count - 1); // 처음 리스트에 들어오는 요소 count 되는거 빼기. 움직이는 요소만 세야하기 때문 
}


int main() {

	arraylisttype list;
	init(&list);
	int choice, n, po_in, po_out;


	while (1) {
		printf("\n메뉴\n");
		printf("1. 리스트에 추가\n");
		printf("2. 리스트에서 삭제\n");
		printf("3. 리스트 출력\n");
		printf("0. 프로그램 종료\n");
		printf("선택: ");
		scanf("%d", &choice);

		switch (choice) {
		case 1:
			if (is_full(&list)) {
				printf("리스트가 꽉 찼습니다.\n");
			}
			else {
				printf("숫자를 입력하세요: ");
				scanf("%d", &n);
				printf("추가할 위치를 입력하세요: ");
				scanf("%d", &po_in);
				insert(&list, po_in, n);

			}
			break;
		case 2:
			if (is_empty(&list)) {
				printf("리스트가 비어있습니다.\n");
			}
			else {
				printf("삭제할 위치를 입력하세요: ");
				scanf("%d", &po_out);
				delete(&list, po_out);

			}
			break;
		case 3:
			print_list(&list);
			break;
		case 0:
			printf("프로그램 종료\n");
			return 0;
		default:
			printf("잘못된 선택입니다. 다시 시도하세요.\n");
		}
	}
}

