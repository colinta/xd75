
#define LAYOUT_my( \
    k00 , k01 , k02 , k03 , k04 , k05 , k06 , k07 , k08 , k09 , k0a , k0b , k0c , k0d , k0e , \
          k11 , k12 , k13 , k14 , k15 , k16 , k17 , k18 , k19 , k1a , k1b , k1c , k1d , k1e , \
          k21 , k22 , k23 , k24 , k25 , k26 , k27 , k28 , k29 , k2a , k2b , k2c , k2d , k2e , \
          k31 , k32 , k33 , k34 , k35 , k36 , k37 , k38 , k39 , k3a , k3b , k3c , k3d , k3e , \
          k41    ,    k43    ,    k45    ,          k48       , k4a , k4b , k4c , k4d , k4e   \
) { \
    k00,  k01 , k02 , k03 , k04 , k05 , k06 , k07 , k08 , k09 , k0a , k0b , k0c , k0d , k0e , \
    ____, k11 , k12 , k13 , k14 , k15 , k16 , k17 , k18 , k19 , k1a , k1b , k1c , k1d , k1e , \
    ____, k21 , k22 , k23 , k24 , k25 , k26 , k27 , k28 , k29 , k2a , k2b , k2c , k2d , k2e , \
    ____, k31 , k32 , k33 , k34 , k35 , k36 , k37 , k38 , k39 , k3a , k3b , k3c , k3d , k3e , \
    ____, k41 , ____, k43 , ____, k45 , ____, ____, k48 , ____, k4a , k4b , k4c , k4d , k4e   \
}
