#ifndef SET_H
#define SET_H

#include <stdio.h>
#include <stdbool.h>

#define MAX 20

typedef struct {
    int arr[MAX];
    int count;
} Set;

Set createSet() {
    Set initSet;

    initSet.count = 0;
    
    for (int i = 0; i < MAX; i++)
    {
        initSet.arr[i] = -1;
    }
    
    return initSet;
}

void swap(int* a, int* b) {
    int hold = *a;
    *a = *b;
    *b = hold;
}

bool isMember(Set st, int member) {
    for (int i = 0; i < st.count; i++)
    {
        if (st.arr[i] == member) return true;
    }
    
    return false;
}

int searchMember(Set st, int member) {
    for (int i = 0; i < st.count; i++)
    {
        if (st.arr[i] == member)
        {
            return i;
        }
        
    }
    
    return -1;
}

int cardinality(Set st) {
    return st.count;
}

void insertMember(Set* st, int member) {
    if (!isMember(*st, member) && st->count < MAX)
    {
        st->arr[st->count++] = member;

        bool swapped;

        for (int i = 0; i < st->count - 1; i++)
        {
            swapped = false;

            for (int j = 0; j < st->count - i - 1; j++)
            {
                if (st->arr[j] > st->arr[j + 1])
                {
                    swap(&st->arr[j], &st->arr[j + 1]);
                    swapped = true;
                }
                
            }
            
            if (swapped == false) break;
            
        }
        
    }

}

void deleteMember(Set* st, int member) {
    int index = searchMember(*st, member);
    if (index == -1) return;

    for (int i = index; i < st->count; i++)
    {
        st->arr[i] = st->arr[i + 1];
    }
    
    st->count--;
}

Set UNION(Set a, Set b) {
    Set U = createSet();
    
    for (int i = 0; i < a.count; i++)
    {
        insertMember(&U, a.arr[i]);
    }
    
    for (int j = 0; j < b.count; j++)
    {
        insertMember(&U, b.arr[j]);
    }
    
    return U;
}

Set DIFFERENCE(Set a, Set b) {
    Set D = createSet();

    for (int i = 0; i < a.count; i++)
    {
        if (!isMember(b, a.arr[i]))
        {
            insertMember(&D, a.arr[i]);
        }
        
    }
    
    return D;
}

Set SYMMETRIC_DIFFERENCE(Set a, Set b) {
    Set SD = createSet();

    for (int i = 0; i < a.count; i++)
    {
        if (!isMember(b, a.arr[i]))
        {
            insertMember(&SD, a.arr[i]);
        }
        
    }

    for (int j = 0; j < b.count; j++)
    {
        if (!isMember(a, b.arr[j]))
        {
            insertMember(&SD, b.arr[j]);
        }
        
    }

    return SD;
}

Set INTERSECTION(Set a, Set b) {
    Set I = createSet();

    for (int i = 0; i < a.count; i++)
    {
        if (isMember(b, a.arr[i]))
        {
            insertMember(&I, a.arr[i]);
        }
        
    }
    

    return I;
}

Set COMPLEMENT(Set u, Set a) {
    Set C = createSet();

    for (int i = 0; i < u.count; i++)
    {
        if (!isMember(a, u.arr[i]))
        {
            insertMember(&C, u.arr[i]);
        }
        
    }
    

    return C;
}

void displaySet(Set st, char* label) {
    printf("%8s = { ", label);
    for (int i = 0; i < st.count; i++)
    {
        printf("%d", st.arr[i]);

        if (i + 1 < st.count)
        {
            printf(", ");
        }
        
    }
    printf(" }\n");
}

#endif