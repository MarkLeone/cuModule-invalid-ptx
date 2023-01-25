
#include <OptiXToolkit/DemandLoading/Texture2D.h>
#include <cstdio>

__global__ void testKernel( demandLoading::DeviceContext* context, cudaTextureObject_t tex, float x, float y, float2 ddx, float2 ddy, bool* isResident)
{
    float C = tex2DGrad<float>( *context, tex, x, y, ddx, ddy, isResident );
    printf( "C = %f\n", C );
}
