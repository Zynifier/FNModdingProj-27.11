// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "PropertyView/CustomPropertyViewData.h"
#include "QuestTools/QuestEditor/EditorExtension/QuestEditorExtensionData.h"
#include "QuestEditorProfileData.generated.h"

class UObject;

USTRUCT()
struct FAutoSelectProfileData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="AutoSelectProfileData")
	FString FilenameLabel;

	UPROPERTY(EditAnywhere, Category="AutoSelectProfileData")
	TSoftClassPtr<UObject> ProfileAssetClass;

};

USTRUCT(BlueprintType)
struct FQuestEditorProfileData : public FTableRowBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="QuestEditorProfileData")
	FAutoSelectProfileData AutoSelectProfileData;

	UPROPERTY(EditAnywhere, Category="QuestEditorProfileData")
	TSoftClassPtr<UObject> ProfileQuestClass;

	UPROPERTY(EditAnywhere, Category="QuestEditorProfileData")
	TArray<FPropertyToShowData> PropertiesToShow;

	UPROPERTY(EditAnywhere, Category="QuestEditorProfileData")
	TArray<FQuestEditorExtensionData> Extensions;

};

