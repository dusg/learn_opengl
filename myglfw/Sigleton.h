//
// Created by Du Carl on 2018/6/24.
//

#ifndef OPENGL_SIGLETON_H
#define OPENGL_SIGLETON_H
template <typename T>
class Sigleton {
public:
    static T& Get() {
        static T* s_instance = nullptr;
        if (!s_instance) {
            s_instance = new T();
        }
        return *s_instance;
    }

};

#endif //OPENGL_SIGLETON_H
