      #ifdef __APPLE__                                                                                                                          
      #import <OpenGLES/ES2/gl.h>                                                                                                               
      #import <OpenGLES/ES2/glext.h>                                                                                                            
      #endif                                                                                                                                    
                                          
      frameBufferPlane_GaussianVertical_SHADER = glCreateProgram();                                                                                                         
                                                                   
      const GLchar *vertexSource_frameBufferPlane_GaussianVertical =                                                                                                        
      //===============================================================================================================================  
      "    #define highp                                                                                                                 \n"                           

      "    attribute highp vec4 position;                                                                                                      \n"
      "    attribute highp vec2 texture;                                                                                                       \n"
      "    uniform   highp float blurRadius;                                                                                                   \n"
      "    uniform   highp float screenRatio;                                                                                                  \n"
    
                                    
      "    varying highp vec2 v_texCoord;                                                                                                      \n"
      "    varying highp vec2 v_blurTexCoords[7];                                                                                              \n"
 
      "    void main()                                                                                                                   \n" 
      "    {                                                                                                                             \n" 
      
      "           highp vec2 Pos;                                                                                                              \n"
      "           Pos = sign(position.xy);                                                                                               \n"  
 
      "           gl_Position = highp vec4(Pos, 0.0, 1.0);                                                                                     \n"
                  //Image-space
      "           v_texCoord = Pos * 0.4 + 0.5;                                                                                          \n"  
   
      "           v_texCoord = texture;                                                                                                  \n" 
                  //------------------
      "           v_blurTexCoords[ 0] = v_texCoord + highp vec2(0.0, -3.0 * (blurRadius)* screenRatio) ;                                                       \n"
      "           v_blurTexCoords[ 1] = v_texCoord + highp vec2(0.0, -2.0 * (blurRadius)* screenRatio) ;                                                       \n"
      "           v_blurTexCoords[ 2] = v_texCoord + highp vec2(0.0, -1.0 * (blurRadius)* screenRatio) ;                                                       \n"
      "           v_blurTexCoords[ 3] = v_texCoord + highp vec2(0.0,  0.0 * (blurRadius)* screenRatio) ;                                                       \n"
      "           v_blurTexCoords[ 4] = v_texCoord + highp vec2(0.0,  1.0 * (blurRadius)* screenRatio) ;                                                       \n"
      "           v_blurTexCoords[ 5] = v_texCoord + highp vec2(0.0,  2.0 * (blurRadius)* screenRatio) ;                                                       \n"
      "           v_blurTexCoords[ 6] = v_texCoord + highp vec2(0.0,  3.0 * (blurRadius)* screenRatio) ;                                                       \n"
      
      "    }\n";                                                                                                                             
      //===============================================================================================================================                                                                    
      frameBufferPlane_GaussianVertical_SHADER_VERTEX = glCreateShader(GL_VERTEX_SHADER);                                                                                   
      glShaderSource(frameBufferPlane_GaussianVertical_SHADER_VERTEX, 1, &vertexSource_frameBufferPlane_GaussianVertical, NULL);                                                                        
      glCompileShader(frameBufferPlane_GaussianVertical_SHADER_VERTEX);                                                                                                     
      //@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
      const GLchar *fragmentSource_frameBufferPlane_GaussianVertical =                                                                                                            
      //=============================================================================================================================== 
      " #ifdef GL_ES                                                                                                          \n"                       
      " #else                                                                                                                 \n"                       
      " #define highp                                                                                                         \n"                       
      " #endif                                                                                                                \n"                       

      "       uniform sampler2D s_texture;                                                                                     \n" 
 
      "       varying highp vec2 v_texCoord;                                                                                     \n"
      "       varying highp vec2 v_blurTexCoords[7];                                                                                     \n" 
 
      "       void main()                                                                                                           \n" 
      "       {                                                                                                                     \n" 
  
      "           highp float tempShadow = 0.0;                              \n"   
  
      "           tempShadow += texture2D(s_texture, v_blurTexCoords[ 0]).w * 0.09;                              \n" 
      "           tempShadow += texture2D(s_texture, v_blurTexCoords[ 1]).w * 0.12;                              \n" 
      "           tempShadow += texture2D(s_texture, v_blurTexCoords[ 2]).w * 0.15;                              \n" 
      "           tempShadow += texture2D(s_texture, v_blurTexCoords[ 3]).w * 0.16;                              \n" 
      "           tempShadow += texture2D(s_texture, v_blurTexCoords[ 4]).w * 0.15;                              \n" 
      "           tempShadow += texture2D(s_texture, v_blurTexCoords[ 5]).w * 0.12;                              \n" 
      "           tempShadow += texture2D(s_texture, v_blurTexCoords[ 6]).w * 0.09;                              \n" 
  
      "           gl_FragColor = texture2D(s_texture, v_texCoord);                                                                                     \n" 
      "           gl_FragColor.w = tempShadow;                                                                                     \n" 
 
//------------------------------------------------------------------------------------------------------------------------------------  
      "    }\n";                                                                                                                                   

//====================================================================================================================================      

      //---------------------------------------------------------------------                                                                         
      frameBufferPlane_GaussianVertical_SHADER_FRAGMENT = glCreateShader(GL_FRAGMENT_SHADER);                                                                                     
      glShaderSource(frameBufferPlane_GaussianVertical_SHADER_FRAGMENT, 1, &fragmentSource_frameBufferPlane_GaussianVertical, NULL);                                                                          
      glCompileShader(frameBufferPlane_GaussianVertical_SHADER_FRAGMENT);                                                                                                         
      //------------------------------------------------                                                                                              
      glAttachShader(frameBufferPlane_GaussianVertical_SHADER, frameBufferPlane_GaussianVertical_SHADER_VERTEX);                                                                                              
      glAttachShader(frameBufferPlane_GaussianVertical_SHADER, frameBufferPlane_GaussianVertical_SHADER_FRAGMENT);                                                                                            
      //------------------------------------------------                                                                                              
      glBindAttribLocation(frameBufferPlane_GaussianVertical_SHADER, 0, "position");                                                                                            
      glBindAttribLocation(frameBufferPlane_GaussianVertical_SHADER, 1, "texture");                                                                                             
      //------------------------------------------------                                                                                              
      glLinkProgram(frameBufferPlane_GaussianVertical_SHADER);                                                                                                                    
      //------------------------------------------------                                                                                              
      #ifdef __APPLE__                                                                                                                                
      glDetachShader(frameBufferPlane_GaussianVertical_SHADER, frameBufferPlane_GaussianVertical_SHADER_VERTEX);                                                                                              
      glDetachShader(frameBufferPlane_GaussianVertical_SHADER, frameBufferPlane_GaussianVertical_SHADER_FRAGMENT);                                                                                            
      #endif                                                                                                                                          
      //------------------------------------------------                                                                                              
      glDeleteShader(frameBufferPlane_GaussianVertical_SHADER_VERTEX);                                                                                                            
      glDeleteShader(frameBufferPlane_GaussianVertical_SHADER_FRAGMENT);                                                                                                          
      //-----------------------------------------------------------------------------------------------------------              
      
      UNIFORM_TEXTURE_frameBufferPlane_GaussianVertical            = glGetUniformLocation(frameBufferPlane_GaussianVertical_SHADER,   "s_texture");                                               
      UNIFORM_blurRadius_frameBufferPlane_GaussianVertical         = glGetUniformLocation(frameBufferPlane_GaussianVertical_SHADER,   "blurRadius");       
      UNIFORM_screenRatio_frameBufferPlane_GaussianVertical        = glGetUniformLocation(frameBufferPlane_GaussianVertical_SHADER,   "screenRatio");      
      
      
      //-----------------------------------------------------------------------------------------------------------              
                                                                                                                          
      //-----------------------------------------------------------------------------------------------------------            
