/*
 * console.cpp
 *
 *  Created on: Nov 14, 2017
 *      Author: efarhan
 */

#include <console.h>

void Console::Draw()
{
	ImGui::BeginChild("ScrollingRegion", ImVec2(0,-ImGui::GetItemsLineHeightWithSpacing()), false, ImGuiWindowFlags_HorizontalScrollbar);
	ImGui::PushStyleVar(ImGuiStyleVar_ItemSpacing, ImVec2(4,1)); // Tighten spacing
	for (int i = 0; i < log_texts.size(); i++)
	{
		const char* item = log_texts[i].c_str();

		ImVec4 col = ImVec4(1.0f,1.0f,1.0f,1.0f); // A better implementation may store a type per-item. For the sample let's just parse the text.

		ImGui::PushStyleColor(ImGuiCol_Text, col);
		ImGui::TextUnformatted(item);
		ImGui::PopStyleColor();
	}
	ImGui::PopStyleVar();
    ImGui::EndChild();
}
void Console::AddLog(std::string log)
{
	log_texts.push_back(log);
}
