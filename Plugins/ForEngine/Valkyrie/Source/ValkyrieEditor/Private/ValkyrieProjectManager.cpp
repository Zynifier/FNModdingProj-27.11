// Copyright Epic Games, Inc. All Rights Reserved.

#include "ValkyrieProjectManager.h"

void UValkyrieProjectManager::CloseCurrentProject()
{
}

void UValkyrieProjectManager::CloseProject(UValkyrieProject* Project)
{
}

void UValkyrieProjectManager::CreateProject(const FString& ProjectName, const FString& ProjectLocation)
{
}

void UValkyrieProjectManager::DeleteProject(const FString& ProjectFileName)
{
}

void UValkyrieProjectManager::DuplicateProject(const FString& DestinationName, const FString& DestinationDir, const FString& TemplateProjectFileName)
{
}

UValkyrieProject* UValkyrieProjectManager::GetCurrentProject()
{
	return nullptr;
}

UValkyrieProject* UValkyrieProjectManager::OpenProject(const FString& ProjectFileName)
{
	return nullptr;
}

void UValkyrieProjectManager::RenameProject(const FString& ProjectFileName, const FString& NewProjectName)
{
}
