#include <Arduino.h> 
#include <ESP32-TWAI-CAN.hpp>
#define P_MAX 12.5f
#define P_MIN -12.5f
#define V_MIN -5.0f //théoriquement, c'est -50 =>-40 juste pour être sur 
#define V_MAX 5.0f //théoriquement, c'est 50 =>40 juste pour être sur 
#define KP_MIN 0.0f
#define KP_MAX 500.0f
#define KD_MIN 0.0f
#define KD_MAX 5.0f
#define T_MIN 0.0f //théoriquement, c'est -48 =>-35 juste pour être sur 
#define T_MAX 5.0f //théoriquement, c'est 48 =>35 juste pour être sur 
// SET VALUES


//measured values



class Motor{
    private:
    uint32_t m_MotorId;

    public:
        Motor(uint32_t p_MotorId);
        void enterMode(CanFrame* msg);
        void exitMode(CanFrame* msg);
        void zeroSet(CanFrame* msg);
        void zero(CanFrame* msg);//go to origin position i guess
        void pack_cmd(CanFrame* msg, float p_des, float v_des, float kp, float kd, float t_ff);
        void unpack_reply(CanFrame* msg);
        unsigned int float_to_uint(float x, float x_min, float x_max, int bits);
        float uint_to_float(unsigned int x_int, float x_min, float x_max, int bits);
        float p_in = 0.0f;
        float v_in = 3.0f;
        float kp_in = 0.0f;
        float kd_in = 3.0f;
        float t_in = 0.0f;
        float p_out = 0.0f;
        float v_out = 0.0f;
        float t_out = 0.0f;
};


