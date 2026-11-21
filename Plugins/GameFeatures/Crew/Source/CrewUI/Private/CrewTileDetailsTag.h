// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"
#include "CrewTileDetailsTag.generated.h"

class UCommonRichTextBlock;
enum class ECrewDetailsTag : uint8;

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UCrewTileDetailsTag : public UCommonUserWidget
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void OnTagSetup(ECrewDetailsTag RewardTag, bool bIsOwnedTag);

private:
	UPROPERTY(BlueprintReadOnly, Export, Category="CrewTileDetailsTag", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UCommonRichTextBlock> Text_Label;

};

