#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_STRING_LENGTH 6

struct package {
    char* id;
    int weight;
};

typedef struct package package;

struct post_office {
    int min_weight;
    int max_weight;
    package* packages;
    int packages_count;
};

typedef struct post_office post_office;

struct town {
    char* name;
    post_office* offices;
    int offices_count;
};

typedef struct town town;

void print_all_packages(town t)
{
    printf("%s:\n", t.name);

    for (int i = 0; i < t.offices_count; i++)
    {
        printf("\t%d:\n", i);

        for (int j = 0; j < t.offices[i].packages_count; j++)
        {
            printf("\t\t%s\n", t.offices[i].packages[j].id);
        }
    }
}

void send_all_acceptable_packages(town* source, int source_office_index,
                                  town* target, int target_office_index)
{
    post_office *src = &source->offices[source_office_index];
    post_office *dest = &target->offices[target_office_index];

    package *remaining = NULL;
    int remaining_count = 0;

    for (int i = 0; i < src->packages_count; i++)
    {
        package p = src->packages[i];

        if (p.weight >= dest->min_weight && p.weight <= dest->max_weight)
        {
            dest->packages = realloc(dest->packages,
                                     (dest->packages_count + 1) * sizeof(package));

            dest->packages[dest->packages_count] = p;
            dest->packages_count++;
        }
        else
        {
            remaining = realloc(remaining,
                                (remaining_count + 1) * sizeof(package));

            remaining[remaining_count] = p;
            remaining_count++;
        }
    }

    free(src->packages);
    src->packages = remaining;
    src->packages_count = remaining_count;
}

town town_with_most_packages(town* towns, int towns_count)
{
    int max_packages = -1;
    int index = 0;

    for (int i = 0; i < towns_count; i++)
    {
        int total = 0;

        for (int j = 0; j < towns[i].offices_count; j++)
        {
            total += towns[i].offices[j].packages_count;
        }

        if (total > max_packages)
        {
            max_packages = total;
            index = i;
        }
    }

    return towns[index];
}

town* find_town(town* towns, int towns_count, char* name)
{
    for (int i = 0; i < towns_count; i++)
    {
        if (strcmp(towns[i].name, name) == 0)
        {
            return &towns[i];
        }
    }

    return NULL;
}

int main() {
    int towns_count;
    scanf("%d", &towns_count);
    town* towns = (town*)malloc(sizeof(town) * towns_count);

    for (int i = 0; i < towns_count; i++) {
        char* name = (char*)malloc(sizeof(char) * 6);
        scanf("%s", name);
        towns[i].name = name;
        
        int offices_count;
        scanf("%d", &offices_count);
        towns[i].offices_count = offices_count;
        towns[i].offices = (post_office*)malloc(sizeof(post_office) * offices_count);
        
        for (int j = 0; j < offices_count; j++) {
            int pkgs_count, min_w, max_w;
            scanf("%d %d %d", &pkgs_count, &min_w, &max_w);
            towns[i].offices[j].packages_count = pkgs_count;
            towns[i].offices[j].min_weight = min_w;
            towns[i].offices[j].max_weight = max_w;
            towns[i].offices[j].packages = (package*)malloc(sizeof(package) * pkgs_count);
            
            for (int k = 0; k < pkgs_count; k++) {
                char* p_id = (char*)malloc(sizeof(char) * 6);
                int p_weight;
                scanf("%s %d", p_id, &p_weight);
                towns[i].offices[j].packages[k].id = p_id;
                towns[i].offices[j].packages[k].weight = p_weight;
            }
        }
    }

    int queries_count;
    scanf("%d", &queries_count);
    for (int i = 0; i < queries_count; i++) {
        int type;
        scanf("%d", &type);
        if (type == 1) {
            char name[6];
            scanf("%s", name);
            print_all_packages(*find_town(towns, towns_count, name));
        } else if (type == 2) {
            char name1[6], name2[6];
            int off1, off2;
            scanf("%s %d %s %d", name1, &off1, name2, &off2);
            send_all_acceptable_packages(find_town(towns, towns_count, name1), off1, find_town(towns, towns_count, name2), off2);
        } else if (type == 3) {
            town t = town_with_most_packages(towns, towns_count);
            printf("Town with the most number of packages is %s\n", t.name);
        }
    }
    return 0;
}
