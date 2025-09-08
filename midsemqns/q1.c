#include <stdio.h>
#include <string.h>
struct Book{
    char title[50];
    char author[50];
    int price;
};

void priceSortInsertion(struct Book *books, int n){
    if(n<=1) return;

    priceSortInsertion(books, n-1);  //first sort n-1 books

    //insert nth book in the sorted part
    struct Book last = *(books + n-1);   //books is a pointer to the 1st book of the books array so we move pointer to the last 'book of the array and using * helps dereference the ptr som were actually adressing the book in the array
    int j = n-2;

    //shift books whose price is greater ythan last
    while (j>=0&& (books+j)->price > last.price)
    {
        *(books + j + 1) = *(books +j);
        j--;
    }
    *(books+j+1) = last;
    
}

int findMinIndex(struct Book *books, int start, int n){
    int minIndex = start;
    for (int i = start+1; i < n; i++)
    {
        if ((books + minIndex)->price > (books+i)->price)
        {
            minIndex = i;
        }
    }
    return minIndex;
}

void priceSortSelection(struct Book *books,int start, int n){
    if (start>=n-1) return; //base case
    //find book with least price
    int minIndex = findMinIndex(books, start, n);
    //sqap current with the min
    if (minIndex!=start){
        struct Book temp = *(books + start);
        *(books + start) = *(books + minIndex);
        *(books + minIndex) = temp;
    }
    //now 1st element is the min and hence sorted so we do not consider it in the next iteration
    priceSortSelection(books, start+1, n);
    
}

void priceBubbleSort(struct Book *books, int n){
    if (n<=1) return;

    for (int i = 0; i < n-1; i++)
    {
        if ((books + i)->price > (books + i + 1)->price)
        {
            struct Book temp = *(books + i);
            *(books + i) = *(books + i + 1);
            *(books + i + 1) = temp;
        }
        
    }
    //atfer each pass the largest element in the array is sorted in bubble sort so dont consider last element
    priceBubbleSort(books, n-1);
    
}

void display(struct Book *books, int n){
    printf("displaying books details....");
    for (int i = 0; i < n; i++)
    {
        printf("=====deails of Book %d=====\n", i+1);
        printf("title of the book: %s\n", books[i].title);
        printf("name of author: %s\n", books[i].author);
        printf("price of the book: %d\n", books[i].price);
        printf("\n");
    }
    
}

int main(){
    int n;
    printf("enter the number of books in the store\n");
    scanf("%d", &n);
    struct Book books[n];
    for (int i = 0; i < n; i++)
    {
        printf("enter the deails of Book %d\n", i+1);
        printf("enter the title of the book\n");
        scanf("%s", &books[i].title);
        printf("enter the name of author\n");
        scanf("%s", &books[i].author);
        printf("enter the price of the book\n");
        scanf("%d", &books[i].price);
        printf("\n");
    }
    display(books, n);
    priceSortInsertion(books, n);
    display(books, n);
}

