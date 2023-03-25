/*

    EGL loader generated by glad 0.1.36 on Sun Jan 29 02:02:36 2023.

    Language/Generator: C/C++
    Specification: egl
    APIs: egl=1.4
    Profile: -
    Extensions:
        EGL_EXT_image_dma_buf_import,
        EGL_EXT_image_dma_buf_import_modifiers,
        EGL_KHR_gl_renderbuffer_image,
        EGL_KHR_gl_texture_2D_image,
        EGL_KHR_gl_texture_3D_image,
        EGL_KHR_image,
        EGL_KHR_image_base,
        EGL_KHR_image_pixmap,
        EGL_MESA_drm_image,
        EGL_MESA_image_dma_buf_export,
        EGL_MESA_query_driver,
        EGL_WL_bind_wayland_display,
        EGL_WL_create_wayland_buffer_from_image
    Loader: True
    Local files: True
    Omit khrplatform: False
    Reproducible: False

    Commandline:
        --api="egl=1.4" --generator="c" --spec="egl" --local-files --extensions="EGL_EXT_image_dma_buf_import,EGL_EXT_image_dma_buf_import_modifiers,EGL_KHR_gl_renderbuffer_image,EGL_KHR_gl_texture_2D_image,EGL_KHR_gl_texture_3D_image,EGL_KHR_image,EGL_KHR_image_base,EGL_KHR_image_pixmap,EGL_MESA_drm_image,EGL_MESA_image_dma_buf_export,EGL_MESA_query_driver,EGL_WL_bind_wayland_display,EGL_WL_create_wayland_buffer_from_image"
    Online:
        https://glad.dav1d.de/#language=c&specification=egl&loader=on&api=egl%3D1.4&extensions=EGL_EXT_image_dma_buf_import&extensions=EGL_EXT_image_dma_buf_import_modifiers&extensions=EGL_KHR_gl_renderbuffer_image&extensions=EGL_KHR_gl_texture_2D_image&extensions=EGL_KHR_gl_texture_3D_image&extensions=EGL_KHR_image&extensions=EGL_KHR_image_base&extensions=EGL_KHR_image_pixmap&extensions=EGL_MESA_drm_image&extensions=EGL_MESA_image_dma_buf_export&extensions=EGL_MESA_query_driver&extensions=EGL_WL_bind_wayland_display&extensions=EGL_WL_create_wayland_buffer_from_image
*/


#ifndef __glad_egl_h_

#ifdef __egl_h_
#error EGL header already included, remove this include, glad already provides it
#endif

#define __glad_egl_h_
#define __egl_h_

#if defined(_WIN32) && !defined(APIENTRY) && !defined(__CYGWIN__) && !defined(__SCITECH_SNAP__)
#define APIENTRY __stdcall
#endif

#ifndef APIENTRY
#define APIENTRY
#endif
#ifndef APIENTRYP
#define APIENTRYP APIENTRY *
#endif
#ifndef GLAPI
#define GLAPI extern
#endif

#ifdef __cplusplus
extern "C" {
#endif

typedef void* (* GLADloadproc)(const char *name);

GLAPI int gladLoadEGL(void);
GLAPI int gladLoadEGLLoader(GLADloadproc);

#include <KHR/khrplatform.h>
#include <EGL/eglplatform.h>
struct AHardwareBuffer;
struct wl_buffer;
struct wl_display;
struct wl_resource;
typedef unsigned int EGLBoolean;
typedef unsigned int EGLenum;
typedef intptr_t EGLAttribKHR;
typedef intptr_t EGLAttrib;
typedef void *EGLClientBuffer;
typedef void *EGLConfig;
typedef void *EGLContext;
typedef void *EGLDeviceEXT;
typedef void *EGLDisplay;
typedef void *EGLImage;
typedef void *EGLImageKHR;
typedef void *EGLLabelKHR;
typedef void *EGLObjectKHR;
typedef void *EGLOutputLayerEXT;
typedef void *EGLOutputPortEXT;
typedef void *EGLStreamKHR;
typedef void *EGLSurface;
typedef void *EGLSync;
typedef void *EGLSyncKHR;
typedef void *EGLSyncNV;
typedef void (*__eglMustCastToProperFunctionPointerType)(void);
typedef khronos_utime_nanoseconds_t EGLTimeKHR;
typedef khronos_utime_nanoseconds_t EGLTime;
typedef khronos_utime_nanoseconds_t EGLTimeNV;
typedef khronos_utime_nanoseconds_t EGLuint64NV;
typedef khronos_uint64_t EGLuint64KHR;
typedef khronos_stime_nanoseconds_t EGLnsecsANDROID;
typedef int EGLNativeFileDescriptorKHR;
typedef khronos_ssize_t EGLsizeiANDROID;
typedef void (*EGLSetBlobFuncANDROID) (const void *key, EGLsizeiANDROID keySize, const void *value, EGLsizeiANDROID valueSize);
typedef EGLsizeiANDROID (*EGLGetBlobFuncANDROID) (const void *key, EGLsizeiANDROID keySize, void *value, EGLsizeiANDROID valueSize);
struct EGLClientPixmapHI {
    void  *pData;
    EGLint iWidth;
    EGLint iHeight;
    EGLint iStride;
};
typedef void (APIENTRY *EGLDEBUGPROCKHR)(EGLenum error,const char *command,EGLint messageType,EGLLabelKHR threadLabel,EGLLabelKHR objectLabel,const char* message);
#define PFNEGLBINDWAYLANDDISPLAYWL PFNEGLBINDWAYLANDDISPLAYWLPROC
#define PFNEGLUNBINDWAYLANDDISPLAYWL PFNEGLUNBINDWAYLANDDISPLAYWLPROC
#define PFNEGLQUERYWAYLANDBUFFERWL PFNEGLQUERYWAYLANDBUFFERWLPROC
#define PFNEGLCREATEWAYLANDBUFFERFROMIMAGEWL PFNEGLCREATEWAYLANDBUFFERFROMIMAGEWLPROC
#define EGL_ALPHA_SIZE 0x3021
#define EGL_BAD_ACCESS 0x3002
#define EGL_BAD_ALLOC 0x3003
#define EGL_BAD_ATTRIBUTE 0x3004
#define EGL_BAD_CONFIG 0x3005
#define EGL_BAD_CONTEXT 0x3006
#define EGL_BAD_CURRENT_SURFACE 0x3007
#define EGL_BAD_DISPLAY 0x3008
#define EGL_BAD_MATCH 0x3009
#define EGL_BAD_NATIVE_PIXMAP 0x300A
#define EGL_BAD_NATIVE_WINDOW 0x300B
#define EGL_BAD_PARAMETER 0x300C
#define EGL_BAD_SURFACE 0x300D
#define EGL_BLUE_SIZE 0x3022
#define EGL_BUFFER_SIZE 0x3020
#define EGL_CONFIG_CAVEAT 0x3027
#define EGL_CONFIG_ID 0x3028
#define EGL_CORE_NATIVE_ENGINE 0x305B
#define EGL_DEPTH_SIZE 0x3025
#define EGL_DONT_CARE EGL_CAST(EGLint,-1)
#define EGL_DRAW 0x3059
#define EGL_EXTENSIONS 0x3055
#define EGL_FALSE 0
#define EGL_GREEN_SIZE 0x3023
#define EGL_HEIGHT 0x3056
#define EGL_LARGEST_PBUFFER 0x3058
#define EGL_LEVEL 0x3029
#define EGL_MAX_PBUFFER_HEIGHT 0x302A
#define EGL_MAX_PBUFFER_PIXELS 0x302B
#define EGL_MAX_PBUFFER_WIDTH 0x302C
#define EGL_NATIVE_RENDERABLE 0x302D
#define EGL_NATIVE_VISUAL_ID 0x302E
#define EGL_NATIVE_VISUAL_TYPE 0x302F
#define EGL_NONE 0x3038
#define EGL_NON_CONFORMANT_CONFIG 0x3051
#define EGL_NOT_INITIALIZED 0x3001
#define EGL_NO_CONTEXT EGL_CAST(EGLContext,0)
#define EGL_NO_DISPLAY EGL_CAST(EGLDisplay,0)
#define EGL_NO_SURFACE EGL_CAST(EGLSurface,0)
#define EGL_PBUFFER_BIT 0x0001
#define EGL_PIXMAP_BIT 0x0002
#define EGL_READ 0x305A
#define EGL_RED_SIZE 0x3024
#define EGL_SAMPLES 0x3031
#define EGL_SAMPLE_BUFFERS 0x3032
#define EGL_SLOW_CONFIG 0x3050
#define EGL_STENCIL_SIZE 0x3026
#define EGL_SUCCESS 0x3000
#define EGL_SURFACE_TYPE 0x3033
#define EGL_TRANSPARENT_BLUE_VALUE 0x3035
#define EGL_TRANSPARENT_GREEN_VALUE 0x3036
#define EGL_TRANSPARENT_RED_VALUE 0x3037
#define EGL_TRANSPARENT_RGB 0x3052
#define EGL_TRANSPARENT_TYPE 0x3034
#define EGL_TRUE 1
#define EGL_VENDOR 0x3053
#define EGL_VERSION 0x3054
#define EGL_WIDTH 0x3057
#define EGL_WINDOW_BIT 0x0004
#define EGL_BACK_BUFFER 0x3084
#define EGL_BIND_TO_TEXTURE_RGB 0x3039
#define EGL_BIND_TO_TEXTURE_RGBA 0x303A
#define EGL_CONTEXT_LOST 0x300E
#define EGL_MIN_SWAP_INTERVAL 0x303B
#define EGL_MAX_SWAP_INTERVAL 0x303C
#define EGL_MIPMAP_TEXTURE 0x3082
#define EGL_MIPMAP_LEVEL 0x3083
#define EGL_NO_TEXTURE 0x305C
#define EGL_TEXTURE_2D 0x305F
#define EGL_TEXTURE_FORMAT 0x3080
#define EGL_TEXTURE_RGB 0x305D
#define EGL_TEXTURE_RGBA 0x305E
#define EGL_TEXTURE_TARGET 0x3081
#define EGL_ALPHA_FORMAT 0x3088
#define EGL_ALPHA_FORMAT_NONPRE 0x308B
#define EGL_ALPHA_FORMAT_PRE 0x308C
#define EGL_ALPHA_MASK_SIZE 0x303E
#define EGL_BUFFER_PRESERVED 0x3094
#define EGL_BUFFER_DESTROYED 0x3095
#define EGL_CLIENT_APIS 0x308D
#define EGL_COLORSPACE 0x3087
#define EGL_COLORSPACE_sRGB 0x3089
#define EGL_COLORSPACE_LINEAR 0x308A
#define EGL_COLOR_BUFFER_TYPE 0x303F
#define EGL_CONTEXT_CLIENT_TYPE 0x3097
#define EGL_DISPLAY_SCALING 10000
#define EGL_HORIZONTAL_RESOLUTION 0x3090
#define EGL_LUMINANCE_BUFFER 0x308F
#define EGL_LUMINANCE_SIZE 0x303D
#define EGL_OPENGL_ES_BIT 0x0001
#define EGL_OPENVG_BIT 0x0002
#define EGL_OPENGL_ES_API 0x30A0
#define EGL_OPENVG_API 0x30A1
#define EGL_OPENVG_IMAGE 0x3096
#define EGL_PIXEL_ASPECT_RATIO 0x3092
#define EGL_RENDERABLE_TYPE 0x3040
#define EGL_RENDER_BUFFER 0x3086
#define EGL_RGB_BUFFER 0x308E
#define EGL_SINGLE_BUFFER 0x3085
#define EGL_SWAP_BEHAVIOR 0x3093
#define EGL_UNKNOWN EGL_CAST(EGLint,-1)
#define EGL_VERTICAL_RESOLUTION 0x3091
#define EGL_CONFORMANT 0x3042
#define EGL_CONTEXT_CLIENT_VERSION 0x3098
#define EGL_MATCH_NATIVE_PIXMAP 0x3041
#define EGL_OPENGL_ES2_BIT 0x0004
#define EGL_VG_ALPHA_FORMAT 0x3088
#define EGL_VG_ALPHA_FORMAT_NONPRE 0x308B
#define EGL_VG_ALPHA_FORMAT_PRE 0x308C
#define EGL_VG_ALPHA_FORMAT_PRE_BIT 0x0040
#define EGL_VG_COLORSPACE 0x3087
#define EGL_VG_COLORSPACE_sRGB 0x3089
#define EGL_VG_COLORSPACE_LINEAR 0x308A
#define EGL_VG_COLORSPACE_LINEAR_BIT 0x0020
#define EGL_DEFAULT_DISPLAY EGL_CAST(EGLNativeDisplayType,0)
#define EGL_MULTISAMPLE_RESOLVE_BOX_BIT 0x0200
#define EGL_MULTISAMPLE_RESOLVE 0x3099
#define EGL_MULTISAMPLE_RESOLVE_DEFAULT 0x309A
#define EGL_MULTISAMPLE_RESOLVE_BOX 0x309B
#define EGL_OPENGL_API 0x30A2
#define EGL_OPENGL_BIT 0x0008
#define EGL_SWAP_BEHAVIOR_PRESERVED_BIT 0x0400
EGLBoolean eglChooseConfig(EGLDisplay dpy, const EGLint *attrib_list, EGLConfig *configs, EGLint config_size, EGLint *num_config);
EGLBoolean eglCopyBuffers(EGLDisplay dpy, EGLSurface surface, EGLNativePixmapType target);
EGLContext eglCreateContext(EGLDisplay dpy, EGLConfig config, EGLContext share_context, const EGLint *attrib_list);
EGLSurface eglCreatePbufferSurface(EGLDisplay dpy, EGLConfig config, const EGLint *attrib_list);
EGLSurface eglCreatePixmapSurface(EGLDisplay dpy, EGLConfig config, EGLNativePixmapType pixmap, const EGLint *attrib_list);
EGLSurface eglCreateWindowSurface(EGLDisplay dpy, EGLConfig config, EGLNativeWindowType win, const EGLint *attrib_list);
EGLBoolean eglDestroyContext(EGLDisplay dpy, EGLContext ctx);
EGLBoolean eglDestroySurface(EGLDisplay dpy, EGLSurface surface);
EGLBoolean eglGetConfigAttrib(EGLDisplay dpy, EGLConfig config, EGLint attribute, EGLint *value);
EGLBoolean eglGetConfigs(EGLDisplay dpy, EGLConfig *configs, EGLint config_size, EGLint *num_config);
EGLDisplay eglGetCurrentDisplay(void);
EGLSurface eglGetCurrentSurface(EGLint readdraw);
EGLDisplay eglGetDisplay(EGLNativeDisplayType display_id);
EGLint eglGetError(void);
__eglMustCastToProperFunctionPointerType eglGetProcAddress(const char *procname);
EGLBoolean eglInitialize(EGLDisplay dpy, EGLint *major, EGLint *minor);
EGLBoolean eglMakeCurrent(EGLDisplay dpy, EGLSurface draw, EGLSurface read, EGLContext ctx);
EGLBoolean eglQueryContext(EGLDisplay dpy, EGLContext ctx, EGLint attribute, EGLint *value);
const char *eglQueryString(EGLDisplay dpy, EGLint name);
EGLBoolean eglQuerySurface(EGLDisplay dpy, EGLSurface surface, EGLint attribute, EGLint *value);
EGLBoolean eglSwapBuffers(EGLDisplay dpy, EGLSurface surface);
EGLBoolean eglTerminate(EGLDisplay dpy);
EGLBoolean eglWaitGL(void);
EGLBoolean eglWaitNative(EGLint engine);
EGLBoolean eglBindTexImage(EGLDisplay dpy, EGLSurface surface, EGLint buffer);
EGLBoolean eglReleaseTexImage(EGLDisplay dpy, EGLSurface surface, EGLint buffer);
EGLBoolean eglSurfaceAttrib(EGLDisplay dpy, EGLSurface surface, EGLint attribute, EGLint value);
EGLBoolean eglSwapInterval(EGLDisplay dpy, EGLint interval);
EGLBoolean eglBindAPI(EGLenum api);
EGLenum eglQueryAPI(void);
EGLSurface eglCreatePbufferFromClientBuffer(EGLDisplay dpy, EGLenum buftype, EGLClientBuffer buffer, EGLConfig config, const EGLint *attrib_list);
EGLBoolean eglReleaseThread(void);
EGLBoolean eglWaitClient(void);
EGLContext eglGetCurrentContext(void);
#define EGL_LINUX_DMA_BUF_EXT 0x3270
#define EGL_LINUX_DRM_FOURCC_EXT 0x3271
#define EGL_DMA_BUF_PLANE0_FD_EXT 0x3272
#define EGL_DMA_BUF_PLANE0_OFFSET_EXT 0x3273
#define EGL_DMA_BUF_PLANE0_PITCH_EXT 0x3274
#define EGL_DMA_BUF_PLANE1_FD_EXT 0x3275
#define EGL_DMA_BUF_PLANE1_OFFSET_EXT 0x3276
#define EGL_DMA_BUF_PLANE1_PITCH_EXT 0x3277
#define EGL_DMA_BUF_PLANE2_FD_EXT 0x3278
#define EGL_DMA_BUF_PLANE2_OFFSET_EXT 0x3279
#define EGL_DMA_BUF_PLANE2_PITCH_EXT 0x327A
#define EGL_YUV_COLOR_SPACE_HINT_EXT 0x327B
#define EGL_SAMPLE_RANGE_HINT_EXT 0x327C
#define EGL_YUV_CHROMA_HORIZONTAL_SITING_HINT_EXT 0x327D
#define EGL_YUV_CHROMA_VERTICAL_SITING_HINT_EXT 0x327E
#define EGL_ITU_REC601_EXT 0x327F
#define EGL_ITU_REC709_EXT 0x3280
#define EGL_ITU_REC2020_EXT 0x3281
#define EGL_YUV_FULL_RANGE_EXT 0x3282
#define EGL_YUV_NARROW_RANGE_EXT 0x3283
#define EGL_YUV_CHROMA_SITING_0_EXT 0x3284
#define EGL_YUV_CHROMA_SITING_0_5_EXT 0x3285
#define EGL_DMA_BUF_PLANE3_FD_EXT 0x3440
#define EGL_DMA_BUF_PLANE3_OFFSET_EXT 0x3441
#define EGL_DMA_BUF_PLANE3_PITCH_EXT 0x3442
#define EGL_DMA_BUF_PLANE0_MODIFIER_LO_EXT 0x3443
#define EGL_DMA_BUF_PLANE0_MODIFIER_HI_EXT 0x3444
#define EGL_DMA_BUF_PLANE1_MODIFIER_LO_EXT 0x3445
#define EGL_DMA_BUF_PLANE1_MODIFIER_HI_EXT 0x3446
#define EGL_DMA_BUF_PLANE2_MODIFIER_LO_EXT 0x3447
#define EGL_DMA_BUF_PLANE2_MODIFIER_HI_EXT 0x3448
#define EGL_DMA_BUF_PLANE3_MODIFIER_LO_EXT 0x3449
#define EGL_DMA_BUF_PLANE3_MODIFIER_HI_EXT 0x344A
#define EGL_GL_RENDERBUFFER_KHR 0x30B9
#define EGL_GL_TEXTURE_2D_KHR 0x30B1
#define EGL_GL_TEXTURE_LEVEL_KHR 0x30BC
#define EGL_GL_TEXTURE_3D_KHR 0x30B2
#define EGL_GL_TEXTURE_ZOFFSET_KHR 0x30BD
#define EGL_NATIVE_PIXMAP_KHR 0x30B0
#define EGL_NO_IMAGE_KHR EGL_CAST(EGLImageKHR,0)
#define EGL_IMAGE_PRESERVED_KHR 0x30D2
#define EGL_DRM_BUFFER_FORMAT_MESA 0x31D0
#define EGL_DRM_BUFFER_USE_MESA 0x31D1
#define EGL_DRM_BUFFER_FORMAT_ARGB32_MESA 0x31D2
#define EGL_DRM_BUFFER_MESA 0x31D3
#define EGL_DRM_BUFFER_STRIDE_MESA 0x31D4
#define EGL_DRM_BUFFER_USE_SCANOUT_MESA 0x00000001
#define EGL_DRM_BUFFER_USE_SHARE_MESA 0x00000002
#define EGL_DRM_BUFFER_USE_CURSOR_MESA 0x00000004
#define EGL_WAYLAND_BUFFER_WL 0x31D5
#define EGL_WAYLAND_PLANE_WL 0x31D6
#define EGL_TEXTURE_Y_U_V_WL 0x31D7
#define EGL_TEXTURE_Y_UV_WL 0x31D8
#define EGL_TEXTURE_Y_XUXV_WL 0x31D9
#define EGL_TEXTURE_EXTERNAL_WL 0x31DA
#define EGL_WAYLAND_Y_INVERTED_WL 0x31DB
#ifndef EGL_EXT_image_dma_buf_import
#define EGL_EXT_image_dma_buf_import 1
#endif
#ifndef EGL_EXT_image_dma_buf_import_modifiers
#define EGL_EXT_image_dma_buf_import_modifiers 1
typedef EGLBoolean (APIENTRYP PFNEGLQUERYDMABUFFORMATSEXTPROC)(EGLDisplay dpy, EGLint max_formats, EGLint *formats, EGLint *num_formats);
GLAPI PFNEGLQUERYDMABUFFORMATSEXTPROC glad_eglQueryDmaBufFormatsEXT;
#define eglQueryDmaBufFormatsEXT glad_eglQueryDmaBufFormatsEXT
typedef EGLBoolean (APIENTRYP PFNEGLQUERYDMABUFMODIFIERSEXTPROC)(EGLDisplay dpy, EGLint format, EGLint max_modifiers, EGLuint64KHR *modifiers, EGLBoolean *external_only, EGLint *num_modifiers);
GLAPI PFNEGLQUERYDMABUFMODIFIERSEXTPROC glad_eglQueryDmaBufModifiersEXT;
#define eglQueryDmaBufModifiersEXT glad_eglQueryDmaBufModifiersEXT
#endif
#ifndef EGL_KHR_gl_renderbuffer_image
#define EGL_KHR_gl_renderbuffer_image 1
#endif
#ifndef EGL_KHR_gl_texture_2D_image
#define EGL_KHR_gl_texture_2D_image 1
#endif
#ifndef EGL_KHR_gl_texture_3D_image
#define EGL_KHR_gl_texture_3D_image 1
#endif
#ifndef EGL_KHR_image
#define EGL_KHR_image 1
typedef EGLImageKHR (APIENTRYP PFNEGLCREATEIMAGEKHRPROC)(EGLDisplay dpy, EGLContext ctx, EGLenum target, EGLClientBuffer buffer, const EGLint *attrib_list);
GLAPI PFNEGLCREATEIMAGEKHRPROC glad_eglCreateImageKHR;
#define eglCreateImageKHR glad_eglCreateImageKHR
typedef EGLBoolean (APIENTRYP PFNEGLDESTROYIMAGEKHRPROC)(EGLDisplay dpy, EGLImageKHR image);
GLAPI PFNEGLDESTROYIMAGEKHRPROC glad_eglDestroyImageKHR;
#define eglDestroyImageKHR glad_eglDestroyImageKHR
#endif
#ifndef EGL_KHR_image_base
#define EGL_KHR_image_base 1
#endif
#ifndef EGL_KHR_image_pixmap
#define EGL_KHR_image_pixmap 1
#endif
#ifndef EGL_MESA_drm_image
#define EGL_MESA_drm_image 1
typedef EGLImageKHR (APIENTRYP PFNEGLCREATEDRMIMAGEMESAPROC)(EGLDisplay dpy, const EGLint *attrib_list);
GLAPI PFNEGLCREATEDRMIMAGEMESAPROC glad_eglCreateDRMImageMESA;
#define eglCreateDRMImageMESA glad_eglCreateDRMImageMESA
typedef EGLBoolean (APIENTRYP PFNEGLEXPORTDRMIMAGEMESAPROC)(EGLDisplay dpy, EGLImageKHR image, EGLint *name, EGLint *handle, EGLint *stride);
GLAPI PFNEGLEXPORTDRMIMAGEMESAPROC glad_eglExportDRMImageMESA;
#define eglExportDRMImageMESA glad_eglExportDRMImageMESA
#endif
#ifndef EGL_MESA_image_dma_buf_export
#define EGL_MESA_image_dma_buf_export 1
typedef EGLBoolean (APIENTRYP PFNEGLEXPORTDMABUFIMAGEQUERYMESAPROC)(EGLDisplay dpy, EGLImageKHR image, int *fourcc, int *num_planes, EGLuint64KHR *modifiers);
GLAPI PFNEGLEXPORTDMABUFIMAGEQUERYMESAPROC glad_eglExportDMABUFImageQueryMESA;
#define eglExportDMABUFImageQueryMESA glad_eglExportDMABUFImageQueryMESA
typedef EGLBoolean (APIENTRYP PFNEGLEXPORTDMABUFIMAGEMESAPROC)(EGLDisplay dpy, EGLImageKHR image, int *fds, EGLint *strides, EGLint *offsets);
GLAPI PFNEGLEXPORTDMABUFIMAGEMESAPROC glad_eglExportDMABUFImageMESA;
#define eglExportDMABUFImageMESA glad_eglExportDMABUFImageMESA
#endif
#ifndef EGL_MESA_query_driver
#define EGL_MESA_query_driver 1
typedef char * (APIENTRYP PFNEGLGETDISPLAYDRIVERCONFIGPROC)(EGLDisplay dpy);
GLAPI PFNEGLGETDISPLAYDRIVERCONFIGPROC glad_eglGetDisplayDriverConfig;
#define eglGetDisplayDriverConfig glad_eglGetDisplayDriverConfig
typedef const char * (APIENTRYP PFNEGLGETDISPLAYDRIVERNAMEPROC)(EGLDisplay dpy);
GLAPI PFNEGLGETDISPLAYDRIVERNAMEPROC glad_eglGetDisplayDriverName;
#define eglGetDisplayDriverName glad_eglGetDisplayDriverName
#endif
#ifndef EGL_WL_bind_wayland_display
#define EGL_WL_bind_wayland_display 1
typedef EGLBoolean (APIENTRYP PFNEGLBINDWAYLANDDISPLAYWLPROC)(EGLDisplay dpy, struct wl_display *display);
GLAPI PFNEGLBINDWAYLANDDISPLAYWLPROC glad_eglBindWaylandDisplayWL;
#define eglBindWaylandDisplayWL glad_eglBindWaylandDisplayWL
typedef EGLBoolean (APIENTRYP PFNEGLUNBINDWAYLANDDISPLAYWLPROC)(EGLDisplay dpy, struct wl_display *display);
GLAPI PFNEGLUNBINDWAYLANDDISPLAYWLPROC glad_eglUnbindWaylandDisplayWL;
#define eglUnbindWaylandDisplayWL glad_eglUnbindWaylandDisplayWL
typedef EGLBoolean (APIENTRYP PFNEGLQUERYWAYLANDBUFFERWLPROC)(EGLDisplay dpy, struct wl_resource *buffer, EGLint attribute, EGLint *value);
GLAPI PFNEGLQUERYWAYLANDBUFFERWLPROC glad_eglQueryWaylandBufferWL;
#define eglQueryWaylandBufferWL glad_eglQueryWaylandBufferWL
#endif
#ifndef EGL_WL_create_wayland_buffer_from_image
#define EGL_WL_create_wayland_buffer_from_image 1
typedef struct wl_buffer * (APIENTRYP PFNEGLCREATEWAYLANDBUFFERFROMIMAGEWLPROC)(EGLDisplay dpy, EGLImageKHR image);
GLAPI PFNEGLCREATEWAYLANDBUFFERFROMIMAGEWLPROC glad_eglCreateWaylandBufferFromImageWL;
#define eglCreateWaylandBufferFromImageWL glad_eglCreateWaylandBufferFromImageWL
#endif

#ifdef __cplusplus
}
#endif

#endif
