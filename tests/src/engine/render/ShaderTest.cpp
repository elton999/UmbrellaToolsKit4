#include <catch2/catch_test_macros.hpp>
#include <string>

#include "../../../../src/engine/render/Shader.h"
#include "../../../../src/engine/core/platform/FileSystem.h"
#include "../../../../src/engine/core/RenderWindow.h"
#include "../../../../src/engine/core/platform/graphics_wrappers/integrations/GlwfBackendIntegration.h"

TEST_CASE("Check if the Shader is loaded", "[Load]")
{

    Umbrella::RenderWindow renderWindow = {};
    renderWindow.BackendIntegration = new Umbrella::GLWF_BackendIntegration;
    renderWindow.StartUp();

    const char* vertexCode =
        "#version 330 core\n"
        "layout(location = 0) in vec3 position;\n"
        "layout(location = 1) in vec3 vertexColor;\n"
        "layout(location = 2) in vec2 texCoords;\n"
        "out vec2 TexCoords;\n"
        "uniform mat4 model;\n"
        "uniform mat4 projection;\n"
        "void main() {\n"
        "    TexCoords = texCoords;\n"
        "    gl_Position = projection * model * vec4(position, 1.0);\n"
        "}\n";

    const char* fragmentCode =
        "#version 330 core\n"
        "in vec2 TexCoords;\n"
        "out vec4 color;\n"
        "uniform sampler2D image;\n"
        "uniform vec3 spriteColor;\n"
        "// texOffset: (offsetX, offsetY) in normalized coords\n"
        "// texScale:  (scaleX, scaleY) in normalized coords\n"
        "uniform vec2 texOffset;\n"
        "uniform vec2 texScale;\n"
        "void main()\n"
        "{\n"
        "    vec2 uv = texOffset + texScale * TexCoords;\n"
        "    color = vec4(spriteColor, 1.0) * texture(image, uv);\n"
        "}\n";

    std::string path = "Testing/Temporary/shaderTest";

    Umbrella::FileSystem::Write(path + ".vert", vertexCode);
    Umbrella::FileSystem::Write(path + ".frag", fragmentCode);

    Umbrella::Shader shader1 = {};
    shader1.Load(path);

    REQUIRE(shader1.IsShaderReady());
    shader1.Unload();
    REQUIRE_FALSE(shader1.IsShaderReady());

    Umbrella::FileSystem::Write(path + "1.vert", vertexCode);
    Umbrella::FileSystem::Write(path + "2.frag", fragmentCode);

    Umbrella::Shader shader2 = {};
    shader2.Load(path + "1");

    REQUIRE_FALSE(shader2.IsShaderReady());

    Umbrella::Shader shader3 = {};
    shader3.Load(path + "2");

    REQUIRE_FALSE(shader3.IsShaderReady());

}
