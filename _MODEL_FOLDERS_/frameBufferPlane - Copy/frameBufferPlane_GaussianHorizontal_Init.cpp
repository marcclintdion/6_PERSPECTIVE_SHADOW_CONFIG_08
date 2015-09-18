      #ifdef __APPLE__                                                                                                                          
      #import <OpenGLES/ES2/gl.h>                                                                                                               
      #import <OpenGLES/ES2/glext.h>                                                                                                            
      #endif                                                                                                                                    
      //===============================================================================================                                         
      frameBufferPlane_GaussianHorizontal_SHADER = glCreateProgram();                                                                                                         
      //---------------------------------------------------------------------                                                                   
      const GLchar *vertexSource_frameBufferPlane_GaussianHorizontal =                                                                                                        

      "    #define highp                                                                                                      \n"                           

      "    attribute  vec4 position;                                                                                        \n" 

      "    void main()                                                                                                              \n" 
      "    {                                                                                                                        \n" 
      

      "         gl_Position = position;                                                                                      \n"  

      "    }\n";                                                                                                                             
      //---------------------------------------------------------------------                                                                   
      frameBufferPlane_GaussianHorizontal_SHADER_VERTEX = glCreateShader(GL_VERTEX_SHADER);                                                                                   
      glShaderSource(frameBufferPlane_GaussianHorizontal_SHADER_VERTEX, 1, &vertexSource_frameBufferPlane_GaussianHorizontal, NULL);                                                                        
      glCompileShader(frameBufferPlane_GaussianHorizontal_SHADER_VERTEX);                                                                                                     
      //---------------------------------------------------------------------                                                                   
      const GLchar *fragmentSource_frameBufferPlane_GaussianHorizontal =                                                                                                            

      " #ifdef GL_ES                                                                                                          \n"                       
      " #else                                                                                                                 \n"                       
      " #define highp                                                                                                         \n"                       
      " #endif                                                                                                                \n"                       


      "       void main()                                                                                                           \n" 
      "       {                                                                                                                     \n" 
      "           gl_FragColor = vec4(1.0);                                                                                     \n" 


//--------------------------------------------------------------------------------------------------------------  


         
//--------------------------------------------------------------------------------------------------------------     
   
    
//==============================================================================================================      
//==============================================================================================================      
      "    }\n";                                                                                                                                   

      //---------------------------------------------------------------------                                                                         
      frameBufferPlane_GaussianHorizontal_SHADER_FRAGMENT = glCreateShader(GL_FRAGMENT_SHADER);                                                                                     
      glShaderSource(frameBufferPlane_GaussianHorizontal_SHADER_FRAGMENT, 1, &fragmentSource_frameBufferPlane_GaussianHorizontal, NULL);                                                                          
      glCompileShader(frameBufferPlane_GaussianHorizontal_SHADER_FRAGMENT);                                                                                                         
      //------------------------------------------------                                                                                              
      glAttachShader(frameBufferPlane_GaussianHorizontal_SHADER, frameBufferPlane_GaussianHorizontal_SHADER_VERTEX);                                                                                              
      glAttachShader(frameBufferPlane_GaussianHorizontal_SHADER, frameBufferPlane_GaussianHorizontal_SHADER_FRAGMENT);                                                                                            
      //------------------------------------------------                                                                                              
      glBindAttribLocation(frameBufferPlane_GaussianHorizontal_SHADER, 0, "position");                                                                                            
      glBindAttribLocation(frameBufferPlane_GaussianHorizontal_SHADER, 1, "texture");                                                                                             
      //glBindAttribLocation(frameBufferPlane_GaussianHorizontal _SHADER, 2, "normal");                                                                                           
      //------------------------------------------------                                                                                              
      glLinkProgram(frameBufferPlane_GaussianHorizontal_SHADER);                                                                                                                    
      //------------------------------------------------                                                                                              
      #ifdef __APPLE__                                                                                                                                
      glDetachShader(frameBufferPlane_GaussianHorizontal_SHADER, frameBufferPlane_GaussianHorizontal_SHADER_VERTEX);                                                                                              
      glDetachShader(frameBufferPlane_GaussianHorizontal_SHADER, frameBufferPlane_GaussianHorizontal_SHADER_FRAGMENT);                                                                                            
      #endif                                                                                                                                          
      //------------------------------------------------                                                                                              
      glDeleteShader(frameBufferPlane_GaussianHorizontal_SHADER_VERTEX);                                                                                                            
      glDeleteShader(frameBufferPlane_GaussianHorizontal_SHADER_FRAGMENT);                                                                                                          
      //------------------------------------------------------------------------------------------------------------//___LOAD_UNIFORMS                
      
                                         
      UNIFORM_TEXTURE_frameBufferPlane_GaussianHorizontal            = glGetUniformLocation(frameBufferPlane_GaussianHorizontal_SHADER,   "s_texture");                                               
       UNIFORM_blurRadius_frameBufferPlane_GaussianHorizontal            = glGetUniformLocation(frameBufferPlane_GaussianHorizontal_SHADER,   "blurRadius");       
      //------------------------------------------------------------------------------------------------------------//___LOAD_TEXTURES                
      //------------------------------------------------------------------------------------------                                              
                                                                                                                                 
