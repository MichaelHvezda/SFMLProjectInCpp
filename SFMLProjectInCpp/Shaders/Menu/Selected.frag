uniform sampler2D texture;
uniform bool isSelected;

void main()
{
    // lookup the pixel in the texture
   // vec4 pixel = texture2D(texture, gl_TexCoord[0].xy);

    // multiply it by the color
    gl_FragColor = vec4(1,1,1,isSelected) ;
}