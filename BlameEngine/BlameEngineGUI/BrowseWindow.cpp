#include "imgui.h"
#include "imgui_stdlib.h"
#include "NewProject.h"
#include <string>
ImGuiWindowFlags browse_window_flags =
    ImGuiWindowFlags_NoResize |
    ImGuiWindowFlags_NoMove |
    ImGuiWindowFlags_NoCollapse;

void BrowseWindow(bool* p_open)
{
    static NewProject newProject;
    float createProjWidth = 800;
    float createProjHeight = 600;
    ImVec2 createProjSize = ImVec2(createProjWidth, createProjHeight);
    ImGui::SetNextWindowSize(createProjSize, ImGuiCond_Appearing);
    if(!ImGui::Begin("Browse", p_open, browse_window_flags))
    {
        // Early exit if the window is closed
        ImGui::End();
        return;
    }

    static std::string projName = newProject.GetName(); // Get the name of the project
    static std::string projPath = newProject.GetPath(); // Get the path of the project

    // Set the window position to the center of the screen
    ImVec2 windowSize = ImGui::GetWindowSize();
    ImVec2 screenSize = ImGui::GetIO().DisplaySize;
    ImVec2 windowPos = ImVec2((screenSize.x - windowSize.x) * 0.5f, (screenSize.y - windowSize.y) * 0.5f);
    ImGui::SetWindowPos(windowPos);

    // Track current state
    static bool openProj = false;
    static bool createProj = false;

    // Calculate the total width of the buttons and spacing
    float buttonWidth = 120.0f; // Button width
    float buttonHeight = 30.0f; // Button height (0.0f for auto height)
    static ImVec2 buttonSize = ImVec2(buttonWidth, buttonHeight);
    float spacing = ImGui::GetStyle().ItemSpacing.x;
    float totalWidth = (buttonWidth * 2) + spacing;

    // Center the buttons
    float windowWidth = ImGui::GetWindowSize().x;
    float offsetX = (windowWidth - totalWidth) * 0.5f;
    ImGui::SetCursorPosX(offsetX);

    // Create buttons
    if (ImGui::Button("Open Project", buttonSize))
    {
        createProj = false;
        openProj = true;
    }

    ImGui::SameLine();

    if (ImGui::Button("Create Project", buttonSize))
    {
        openProj = false;
        createProj = true;
    }

    ImGuiIO io = ImGui::GetIO();
    
    if (openProj)
    {
        // Set child window background color to black
        ImGui::PushStyleColor(ImGuiCol_ChildBg, ImVec4(0.0f, 0.0f, 0.0f, 1.0f));

        // Create project logic here
        ImGui::BeginChild("OpenProjectChild", ImGui::GetContentRegionAvail());
        float listbox_height = 275;
        float totalWidth_listboxes = 195 + 400 + spacing;
        float centerX_listboxes = (createProjWidth - totalWidth_listboxes) * 0.5f;

        //ImGui::SetNextWindowPos(ImVec2(0, 150));
        ImGui::SetCursorPosY(35);
        ImGui::SetCursorPosX(centerX_listboxes);
        ImGui::BeginChild("listbox_projets", ImVec2(195, listbox_height), ImGuiChildFlags_Borders);

        // End listbox
        ImGui::EndChild();

        ImGui::SameLine();

        ImGui::BeginChild("Listbox_screenshot_display", ImVec2(400, listbox_height), ImGuiChildFlags_Borders);

        // End Screenshot display window
        ImGui::EndChild();

        // Center buttons
        ImGui::SetCursorPosX(offsetX);
        if (ImGui::Button("Open", buttonSize))
        {

        }

        ImGui::SameLine();

        if (ImGui::Button("Exit", buttonSize))
        {

        }

        // End Open Project Child
        ImGui::EndChild();

        ImGui::PopStyleColor();
    }

    if (createProj)
    {
        // Set child window background color to black
        ImGui::PushStyleColor(ImGuiCol_ChildBg, ImVec4(0.0f, 0.0f, 0.0f, 1.0f));
        
        // Create project logic here
        ImGui::BeginChild("CreateProjectChild", ImGui::GetContentRegionAvail(), ImGuiChildFlags_Borders);
        float listbox_height = 275;
        float totalWidth_listboxes = 195 + 400 + spacing;
        float centerX_listboxes = (createProjWidth - totalWidth_listboxes) * 0.5f;

        //ImGui::SetNextWindowPos(ImVec2(0, 150));
        ImGui::SetCursorPosY(35);
        ImGui::SetCursorPosX(centerX_listboxes);
        ImGui::BeginChild("listbox_projets", ImVec2(195, listbox_height), ImGuiChildFlags_Borders);

        // End listbox
        ImGui::EndChild();

        ImGui::SameLine();

        ImGui::BeginChild("Listbox_screenshot_display", ImVec2(400, listbox_height), ImGuiChildFlags_Borders);

        // End Screenshot display window
        ImGui::EndChild();

        // Create name input text box
        ImGui::SetCursorPosX(centerX_listboxes);
        ImGui::Text("Name:"); ImGui::SameLine();
        ImGui::InputText("##Name", &projName, ImGuiInputTextFlags_AutoSelectAll);
        float inputTextBoxX = ImGui::GetItemRectSize().x;
        newProject.SetName(projName); // Set the name of the project

        // Get size of browse button using font size of label
        std::string browseButtonLabel = "Browse";   // Set label name
        float browseButtonSize = (ImGui::GetFontSize() * 5) - spacing + 1;  // Get font size * 5 for each character + 1 for button spacing

        // Create Path text input box
        ImGui::SetCursorPosX(centerX_listboxes);
        ImGui::Text("Path:"); ImGui::SameLine();
        ImGui::SetNextItemWidth(inputTextBoxX - browseButtonSize);
        ImGui::InputText("##Path", &projPath); ImGui::SameLine();
        newProject.SetPath(projPath); // Set the path of the project
        ImGui::Button("Browse");

        // Create a little space between input boxes and buttons
        ImGui::Dummy(ImVec2(0, 50));

        // Center buttons
        ImGui::SetCursorPosX(offsetX);
        if (ImGui::Button("Create", buttonSize))
        {

        }

        ImGui::SameLine();

        if (ImGui::Button("Exit",buttonSize))
        {
            
        }

        // End Create Project Child
        ImGui::EndChild();

        ImGui::PopStyleColor();
    }

    //ImGui::Dummy(ImVec2(0.0f, ImGui::GetContentRegionAvail().y - 30.0f)); // Dummy space to move anything below the bottom

    // End Browse Window
    ImGui::End();
}
