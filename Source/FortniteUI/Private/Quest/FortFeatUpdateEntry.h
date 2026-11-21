// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Quest/FortQuestUpdateEntry.h"
#include "FortFeatUpdateEntry.generated.h"

class UImage;
class UTextBlock;

UCLASS(Abstract, BlueprintType, Blueprintable)
class UFortFeatUpdateEntry : public UFortQuestUpdateEntry
{
	GENERATED_BODY()

protected:
	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UImage> Image_QuestIcon;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UTextBlock> Text_QuestName;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UTextBlock> Text_QuestDescription;

};

