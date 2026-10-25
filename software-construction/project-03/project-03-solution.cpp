// How to compile code: g++ filename
// How to run code: ./a.out


# include <iostream>
# include <stdlib.h>
# include <assert.h>
# include <ctime>
using namespace std;

const int TOTAL_RUNS = 10000;
const double AARON_ACCURACY = 1 / 3.0;
const double BOB_ACCURACY = 0.5;
const double CHARLIE_ACCURACY = 1.0;

bool at_least_two_alive(bool A_alive, bool B_alive, bool C_alive);
void test_at_least_two_alive(void);
void test_Aaron_shoots1(void);
void test_Bob_shoots(void);
void test_Charlie_shoots(void);
void test_Aaron_shoots2(void);
void Aaron_shoots1(bool& B_alive, bool& C_alive);
void Bob_shoots(bool& A_alive, bool& C_alive);
void Charlie_shoots(bool& A_alive, bool& B_alive);
void Aaron_shoots2(bool& B_alive, bool& C_alive);
void strategy_1(bool& a, bool& b, bool& c);
void strategy_2(bool& a, bool& b, bool& c);




int main(){

    cout << "*** Welcome to Christian's Truel of the Fates Simulator ***" << endl;

    test_at_least_two_alive();
    cout << "Press Enter to continue...";
    cin.get();

    test_Aaron_shoots1();
    cout << "\tPress Enter to continue...";
    cin.get();
    cout << endl;

    test_Bob_shoots();
    cout << "\tPress Enter to continue...";
    cin.get();
    cout << endl;

    test_Charlie_shoots();
    cout << "\tPress Enter to continue...";
    cin.get();
    cout << endl;

    test_Aaron_shoots2();
    cout << "\tPress Enter to continue...";
    cin.get();
    cout << endl;


    cout << "Ready to test strategy 1 (run 10000 times):" << endl;
    cout << "Press Enter to continue...";
    cin.get();
    cout << endl;
    
    srand(time(0));
    bool a = true;
    bool b = true;
    bool c = true;

    double a_accuracy = 0;
    double b_accuracy = 0;
    double c_accuracy = 0;

    double first_Strategy_ac_Aaron = 0;

    int a_win_count = 0;
    int b_win_count = 0;
    int c_win_count = 0;

    for(int i = 0; i < TOTAL_RUNS; i++){
       
        a = true;
        b = true;
        c = true;

        strategy_1(a, b, c);

        if(a) a_win_count++;
        else if(b) b_win_count++;
        else if(c) c_win_count++;
    }

    a_accuracy = 100.0 * a_win_count / TOTAL_RUNS;
    first_Strategy_ac_Aaron = a_accuracy;
    cout << "Aaron won " << a_win_count << "/" << TOTAL_RUNS << " truels or " << a_accuracy << "%.\n";

    b_accuracy = 100.0 * b_win_count / TOTAL_RUNS;
    cout << "Bob won " << b_win_count << "/" << TOTAL_RUNS << " truels or " << b_accuracy << "%.\n";

    c_accuracy = 100.0 * c_win_count / TOTAL_RUNS;
    cout << "Charlie won " << c_win_count << "/" << TOTAL_RUNS << " truels or " << c_accuracy << "%.\n";

    
    // -------- Strategy 2 -----------
    cout << endl;
    cout << "Ready to test strategy 2 (run 10000 times):" << endl;
    cout << "Press Enter to continue...";
    cin.get();
    cout << endl;

    a_accuracy = 0;
    b_accuracy = 0;
    c_accuracy = 0;

    a_win_count = 0;
    b_win_count = 0;
    c_win_count = 0;

    for(int i = 0; i < TOTAL_RUNS; i++){
       
        a = true;
        b = true;
        c = true;

        strategy_2(a, b, c);

        if(a) a_win_count++;
        else if(b) b_win_count++;
        else if(c) c_win_count++;
    }

    a_accuracy = 100.0 * a_win_count / TOTAL_RUNS;
    cout << "Aaron won " << a_win_count << "/" << TOTAL_RUNS << " truels or " << a_accuracy << "%.\n";

    b_accuracy = 100.0 * b_win_count / TOTAL_RUNS;
    cout << "Bob won " << b_win_count << "/" << TOTAL_RUNS << " truels or " << b_accuracy << "%.\n";

    c_accuracy = 100.0 * c_win_count / TOTAL_RUNS;
    cout << "Charlie won " << c_win_count << "/" << TOTAL_RUNS << " truels or " << c_accuracy << "%.\n";

    if(a_accuracy >= first_Strategy_ac_Aaron){
        cout << endl;
        cout << "Strategy 2 is better than strategy 1.\n"; 
    } else {
        cout << endl;
        cout << "Strategy 1 is better than strategy 2.\n"; 
    }

    return 0;
}

void strategy_1(bool& a, bool& b, bool& c){

    while(at_least_two_alive(a, b, c)){
        //cout << "Aaron turn: \n";
        if(a) Aaron_shoots1(b, c);
        if(!at_least_two_alive(a, b, c)) break;

        //cout << "Bob turn: \n";
        if(b) Bob_shoots(a, c);
        if(!at_least_two_alive(a, b, c)) break;

        //cout << "Charlie turn: \n";
        if(c) Charlie_shoots(a, b);
    }
}

void strategy_2(bool& a, bool& b, bool& c){

    while(at_least_two_alive(a, b, c)){
        //cout << "Aaron turn: \n";
        if(a) Aaron_shoots2(b, c);
        if(!at_least_two_alive(a, b, c)) break;

        //cout << "Bob turn: \n";
        if(b) Bob_shoots(a, c);
        if(!at_least_two_alive(a, b, c)) break;

        //cout << "Charlie turn: \n";
        if(c) Charlie_shoots(a, b);
    }
}

bool at_least_two_alive(bool A_alive, bool B_alive, bool C_alive){
    if(A_alive && B_alive || A_alive && C_alive || B_alive && C_alive){
        return true;
    } else {
        return false;
    }
}


void Aaron_shoots1(bool& B_alive, bool& C_alive){
    
    //try shooting
    int shoot_target_result = rand() % 100;

    if (shoot_target_result < AARON_ACCURACY * 100){
        if(C_alive){
            C_alive = 0;
            //cout << "A Hit the target C\n";
        } else if (B_alive){
            B_alive = 0;
            //cout << " A Hit the target B\n";
        } 
    } else {
        //cout << "A Shot on target missed\n";
    }
}

void Bob_shoots(bool& A_alive, bool& C_alive){
    
    //try shooting
    int shoot_target_result = rand() % 100;
    //cout << shoot_target_result << endl;

    if (shoot_target_result < BOB_ACCURACY * 100){
        if(C_alive){
            C_alive = 0;
            //cout << "B Hit the target C\n";
        } else if (A_alive){
            A_alive = 0;
            //cout << "B Hit the target A\n";
        } 
    } else {
        //cout << "B Shot on target missed\n";
    }
}

void Charlie_shoots(bool& A_alive, bool& B_alive){
    
    //try shooting
    int shoot_target_result = rand() % 100;

    if (shoot_target_result < CHARLIE_ACCURACY * 100){
        if(B_alive){
            B_alive = 0;
            //cout << "C Hit the target B\n";
        } else if (A_alive){
            A_alive = 0;
            //cout << "C Hit the target A\n";
        } 
    } else {
        //cout << "C Shot on target missed\n";
    }
}

void Aaron_shoots2(bool& B_alive, bool& C_alive){
    
    if(B_alive && C_alive){
        return;
    }

    Aaron_shoots1(B_alive, C_alive);
}


// --------------- test drivers --------------------

void test_at_least_two_alive(){
    cout << "Unit Testing 1: Function - at_least_two_alive()\n";

    cout << "\tCase 1: Aaron alive, Bob alive, Charlie alive\n";
    assert(true == at_least_two_alive(true, true, true));
    cout << "\t\tCase passed ...\n";

    cout << "\tCase 2: Aaron dead, Bob alive, Charlie alive\n";
    assert(true == at_least_two_alive(false, true, true));
    cout << "\t\tCase passed ...\n";

    cout << "\tCase 3: Aaron alive, Bob dead, Charlie alive\n";
    assert(true == at_least_two_alive(true, false, true));
    cout << "\t\tCase passed ...\n";

    cout << "\tCase 4: Aaron alive, Bob alive, Charlie dead\n";
    assert(true == at_least_two_alive(true, true, false));
    cout << "\t\tCase passed ...\n";

    cout << "\tCase 5: Aaron dead, Bob dead, Charlie alive\n";
    assert(false == at_least_two_alive(false, false, true));
    cout << "\t\tCase passed ...\n";

    cout << "\tCase 6: Aaron dead, Bob alive, Charlie dead\n";
    assert(false == at_least_two_alive(false, true, false));
    cout << "\t\tCase passed ...\n";

    cout << "\tCase 7: Aaron alive, Bob dead, Charlie dead\n";
    assert(false == at_least_two_alive(true, false, false));
    cout << "\t\tCase passed ...\n";

    cout << "\tCase 8: Aaron dead, Bob dead, Charlie dead\n";
    assert(false == at_least_two_alive(false, false, false));
    cout << "\t\tCase passed ...\n";
}


void test_Aaron_shoots1(){
    cout << "Unit Testing 2: Function Aaron_shoots1(Bob_alive, Charlie_alive)\n";
    bool B_alive, C_alive;

    cout << "\tCase 1: Bob alive, Charlie alive\n";
    B_alive = true; C_alive = true;
    cout << "\t\tAaron is shooting at Charlie\n";
    Aaron_shoots1(B_alive, C_alive);
    assert(B_alive == true);                 // Bob is never the target here

    cout << "\tCase 2: Bob dead, Charlie alive\n";
    B_alive = false; C_alive = true;
    cout << "\t\tAaron is shooting at Charlie\n";
    Aaron_shoots1(B_alive, C_alive);
    assert(B_alive == false);                // Bob stays dead

    cout << "\tCase 3: Bob alive, Charlie dead\n";
    B_alive = true; C_alive = false;
    cout << "\t\tAaron is shooting at Bob\n";
    Aaron_shoots1(B_alive, C_alive);
    assert(C_alive == false);                // Charlie stays dead
}

void test_Bob_shoots(void) {
    cout << "Unit Testing 3: Function Bob_shoots(Aaron_alive, Charlie_alive)\n";
    bool A_alive, C_alive;

    cout << "\tCase 1: Aaron alive, Charlie alive\n";
    A_alive = true; C_alive = true;
    cout << "\t\tBob is shooting at Charlie\n";
    Bob_shoots(A_alive, C_alive);
    assert(A_alive == true);                 // Aaron is never the target here

    cout << "\tCase 2: Aaron dead, Charlie alive\n";
    A_alive = false; C_alive = true;
    cout << "\t\tBob is shooting at Charlie\n";
    Bob_shoots(A_alive, C_alive);
    assert(A_alive == false);

    cout << "\tCase 3: Aaron alive, Charlie dead\n";
    A_alive = true; C_alive = false;
    cout << "\t\tBob is shooting at Aaron\n";
    Bob_shoots(A_alive, C_alive);
    assert(C_alive == false);
}

void test_Charlie_shoots(void) {
    cout << "Unit Testing 4: Function Charlie_shoots(Aaron_alive, Bob_alive)\n";
    bool A_alive, B_alive;

    // Charlie never misses, so every result is fully predictable
    cout << "\tCase 1: Aaron alive, Bob alive\n";
    A_alive = true; B_alive = true;
    cout << "\t\tCharlie is shooting at Bob\n";
    Charlie_shoots(A_alive, B_alive);
    assert(A_alive == true && B_alive == false);

    cout << "\tCase 2: Aaron dead, Bob alive\n";
    A_alive = false; B_alive = true;
    cout << "\t\tCharlie is shooting at Bob\n";
    Charlie_shoots(A_alive, B_alive);
    assert(A_alive == false && B_alive == false);

    cout << "\tCase 3: Aaron alive, Bob dead\n";
    A_alive = true; B_alive = false;
    cout << "\t\tCharlie is shooting at Aaron\n";
    Charlie_shoots(A_alive, B_alive);
    assert(A_alive == false && B_alive == false);
}

void test_Aaron_shoots2(void) {
    cout << "Unit Testing 5: Function Aaron_shoots2(Bob_alive, Charlie_alive)\n";
    bool B_alive, C_alive;

    cout << "\tCase 1: Bob alive, Charlie alive\n";
    B_alive = true; C_alive = true;
    cout << "\t\tAaron intentionally misses his first shot\n";
    Aaron_shoots2(B_alive, C_alive);
    assert(B_alive == true && C_alive == true);   // nobody can die
    cout << "\t\tBoth Bob and Charlie are alive.\n";

    cout << "\tCase 2: Bob dead, Charlie alive\n";
    B_alive = false; C_alive = true;
    cout << "\t\tAaron is shooting at Charlie\n";
    Aaron_shoots2(B_alive, C_alive);
    assert(B_alive == false);

    cout << "\tCase 3: Bob alive, Charlie dead\n";
    B_alive = true; C_alive = false;
    cout << "\t\tAaron is shooting at Bob\n";
    Aaron_shoots2(B_alive, C_alive);
    assert(C_alive == false);
}