// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "EditorSubsystem.h"
#include "ValkyrieProjectManager.generated.h"

class UValkyrieProject;

UCLASS(BlueprintType)
class VALKYRIEEDITOR_API UValkyrieProjectManager : public UEditorSubsystem
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="Valkyrie")
	void CloseCurrentProject();

	UFUNCTION(BlueprintCallable, Category="Valkyrie")
	void CloseProject(UValkyrieProject* Project);

	UFUNCTION(BlueprintCallable, Category="Valkyrie")
	void CreateProject(const FString& ProjectName, const FString& ProjectLocation);

	UFUNCTION(BlueprintCallable, Category="Valkyrie")
	void DeleteProject(const FString& ProjectFileName);

	UFUNCTION(BlueprintCallable, Category="Valkyrie")
	void DuplicateProject(const FString& DestinationName, const FString& DestinationDir, const FString& TemplateProjectFileName);

	UFUNCTION(BlueprintCallable, Category="Valkyrie")
	static UValkyrieProject* GetCurrentProject();

	UFUNCTION(BlueprintCallable, Category="Valkyrie")
	UValkyrieProject* OpenProject(const FString& ProjectFileName);

	UFUNCTION(BlueprintCallable, Category="Valkyrie")
	void RenameProject(const FString& ProjectFileName, const FString& NewProjectName);

private:
	UPROPERTY()
	TMap<FString, TObjectPtr<UValkyrieProject>> Projects;

	UPROPERTY()
	TArray<TObjectPtr<UValkyrieProject>> OpenedProjects;

	UPROPERTY()
	TObjectPtr<UValkyrieProject> CurrentProject;

};

