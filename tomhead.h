#ifndef TOMHEAD
#define TOMHEAD

struct thead
  {
    short xsize,ysize,zsize,lmarg,rmarg,tmarg,bmarg,tzmarg,bzmarg,\
     num_samples,num_proj,num_blocks,num_slices,bin,gain,speed,pepper,issue,num_frames,machine,spare_int[12];
    float scale,offset,voltage,current,thickness,pixel_size,distance,exposure,\
     mag_factor,gradient,spare_float[2];
    long posdistance,slices_per_block,z,theta;
    char time[26],duration[12],owner[21],user[5],specimen[32],scan[32],\
     comment[64],spare_char[192];
  };

#endif // TOMHEAD

