class AnimalShelf {
    queue<pair<int,int>> queCat; //猫队列
    queue<pair<int,int>> queDog; //狗队列
    int cout = 0; //设置自增数
public:
    AnimalShelf() {
    }

    void enqueue(vector<int> animal) {
        if(animal[1]) queDog.push({cout,animal[0]});  //种类为狗
        else queCat.push({cout,animal[0]});   //种类为猫
        cout ++; //编号自增
    }
    
    vector<int> dequeueAny() {
        if(queDog.empty() && queCat.empty()) return {-1, -1};  //猫狗都为空
        else if(queCat.empty() && queDog.size()) return dequeueDog(); //有狗无猫
        else if(queDog.empty() && queCat.size()) return dequeueCat(); //有猫无狗
        else if(queDog.front() < queCat.front()) return dequeueDog(); //有猫有狗，狗编号小
        else return dequeueCat(); //有猫有狗，猫编号小
    }
    
    vector<int> dequeueDog() {
        if(queDog.empty()) return {-1, -1}; //无狗
        int temp = queDog.front().first; //有狗，先进先出
        queDog.pop();
        return {temp, 1};
    }
    
    vector<int> dequeueCat() {
        if(queCat.empty()) return {-1, -1}; //无猫
        int temp = queCat.front().first; //有猫先进先出
        queCat.pop();
        return {temp, 0};
    }
};


/**
 * Your AnimalShelf object will be instantiated and called as such:
 * AnimalShelf* obj = new AnimalShelf();
 * obj->enqueue(animal);
 * vector<int> param_2 = obj->dequeueAny();
 * vector<int> param_3 = obj->dequeueDog();
 * vector<int> param_4 = obj->dequeueCat();
 */