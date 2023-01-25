
#include <cuda.h>
#include <cuda_runtime.h>
#include <sstream>
#include <exception>
#include <cstdio>

// XXX void launchTestKernel( unsigned int count );

#define CUDA_CHECK( call ) cudaCheck( call, #call, __FILE__, __LINE__ )

void cudaCheck( CUresult result, const char* expr, const char* file, unsigned int line )
{
    if( result != CUDA_SUCCESS )
    {
        const char* errorStr;
        cuGetErrorString( result, &errorStr );
        std::stringstream ss;
        ss << "CUDA call (" << expr << " ) failed with error: '" << errorStr << "' (" << file << ":" << line << ")\n";
        throw std::runtime_error( ss.str() );
    }
}

int main()
{
    cudaFree(nullptr);

    printf( "Calling cuModuleLoad( ..., \"%s\" )\n", PTX_FILENAME );

    CUmodule module;
    CUDA_CHECK( cuModuleLoad( &module, PTX_FILENAME ) );

#if 0
    launchTestKernel( 32 );    
    cudaError_t cudaerr = cudaDeviceSynchronize();
    if( cudaerr != cudaSuccess )
        printf( "kernel launch failed with error \"%s\".\n", cudaGetErrorString( cudaerr ) );
#endif

    return 0;
}
