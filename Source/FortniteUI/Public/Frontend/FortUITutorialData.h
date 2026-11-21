// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "FortUITutorialData.generated.h"

class UTexture2D;

USTRUCT(BlueprintType)
struct FFortUITutorialData : public FTableRowBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Tutorial")
	FName TutorialWidgetName;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Tutorial")
	FText Title;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Tutorial")
	FString DevComment;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Tutorial")
	TArray<FText> Descriptions;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Tutorial")
	TArray<TSoftObjectPtr<UTexture2D>> PreviewImages;

};

