#include "Storm.h"
#include <cstring>

using namespace std;

class RanSentSpout: public storm::Spout {
public:
    void Initialize (Json::Value conf, Json::Value context){
        array_sentence[0] = "this is great";
        array_sentence[1] = "we are sending things";
        array_sentence[2] = "this is matching sending";
        present_count = 0;
    };
    void NextTuple(){
        sleep(100);
        Json::Value to_send_data;
        to_send_data.append(array_sentence[present_count%3]);
        storm::Tuple t(to_send_data);
        present_count++;
        Emit(t);
    }
private:
    string array_sentence[3];
    int present_count;
};

int main(){
    RanSentSpout random_sentence;
    random_sentence.Run();

}
