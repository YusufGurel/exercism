#include "grade_school.h"


void init_roster(roster_t * roster)
{
    roster->count = 0;
}

bool add_student(roster_t *roster, const char *name, uint8_t grade)
{
    for(size_t i = 0; i < roster->count; i++)
    {
        if(strcmp(roster->students[i].name, name) == 0)
        {
            return false;
        }
    }
    roster->students[roster->count].grade = grade;
    strcpy(roster->students[roster->count].name, name);
    roster->count++;
    sortRoster(roster);
    return true;
}

void sortRoster(roster_t *roster)
{
    for(size_t i = 0; i < roster->count; i++)
    {
        for(size_t j = i + 1; j < roster->count; j++)
        {
            if(roster->students[i].grade > roster->students[j].grade)
            {
                student_t temp = roster->students[i];
                roster->students[i] = roster->students[j];
                roster->students[j] = temp;
            }
            else if(roster->students[i].grade == roster->students[j].grade)
            {
                if(strcmp(roster->students[i].name, roster->students[j].name) > 0)
                {
                    student_t temp = roster->students[i];
                    roster->students[i] = roster->students[j];
                    roster->students[j] = temp;
                }
            }
        }
    }
}

roster_t get_grade(const roster_t *roster, uint8_t grade)
{
    roster_t grade_roster;
    memset(&grade_roster, 0, sizeof(roster_t));

    for(size_t i = 0; i < roster->count; i++)
    {
        if(roster->students[i].grade == grade)
        {
            memcpy(&grade_roster.students[grade_roster.count], &roster->students[i], sizeof(student_t));
            grade_roster.count++;
        }
    }

    return grade_roster;
}
