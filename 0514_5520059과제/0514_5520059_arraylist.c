#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#define max_list_size 100

typedef int element;

typedef struct {
	element array[max_list_size];
	int size;
}arraylisttype;


//�ʱ�ȭ 
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
		printf("���� �Ϸ�, ������ �̵� Ƚ��: ");
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
	else error("��ġ����");
}

int get_length(arraylisttype* l) {
	return(l->size);
}


element delete(arraylisttype* l, int pos) {

	if (pos < 0 || pos >= l->size) {
		error("��ġ ����");
	}
	else {
		element item = l->array[pos];
		for (int i = pos; i < (l->size - 1); i++) {
			l->array[i] = l->array[i + 1];
		}
		l->size = l->size - 1;
		printf("���� �Ϸ�, ������ �̵� Ƚ��: ");
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
	printf("%d\n", count - 1); // ó�� ����Ʈ�� ������ ��� count �Ǵ°� ����. �����̴� ��Ҹ� �����ϱ� ���� 
}


int main() {

	arraylisttype list;
	init(&list);
	int choice, n, po_in, po_out;


	while (1) {
		printf("\n�޴�\n");
		printf("1. ����Ʈ�� �߰�\n");
		printf("2. ����Ʈ���� ����\n");
		printf("3. ����Ʈ ���\n");
		printf("0. ���α׷� ����\n");
		printf("����: ");
		scanf("%d", &choice);

		switch (choice) {
		case 1:
			if (is_full(&list)) {
				printf("����Ʈ�� �� á���ϴ�.\n");
			}
			else {
				printf("���ڸ� �Է��ϼ���: ");
				scanf("%d", &n);
				printf("�߰��� ��ġ�� �Է��ϼ���: ");
				scanf("%d", &po_in);
				insert(&list, po_in, n);

			}
			break;
		case 2:
			if (is_empty(&list)) {
				printf("����Ʈ�� ����ֽ��ϴ�.\n");
			}
			else {
				printf("������ ��ġ�� �Է��ϼ���: ");
				scanf("%d", &po_out);
				delete(&list, po_out);

			}
			break;
		case 3:
			print_list(&list);
			break;
		case 0:
			printf("���α׷� ����\n");
			return 0;
		default:
			printf("�߸��� �����Դϴ�. �ٽ� �õ��ϼ���.\n");
		}
	}
}

