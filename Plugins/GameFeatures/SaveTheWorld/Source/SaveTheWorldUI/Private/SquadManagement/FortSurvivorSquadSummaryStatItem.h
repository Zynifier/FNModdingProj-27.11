// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"
#include "FortBrushSize.h"
#include "SquadManagement/FortSquadLandingPageSurvivorSummary.h"
#include "FortSurvivorSquadSummaryStatItem.generated.h"

class UCommonTextBlock;
class UImage;

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UFortSurvivorSquadSummaryStatItem : public UCommonUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="SquadSummary")
	void SetAttributeModifierAccumulation(const FFortAttributeModifierAccumulation& Accumulation);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="SquadSummary")
	TEnumAsByte<EFortBrushSize::Type> ImageSize;

	UPROPERTY(BlueprintReadOnly, Export, Category="SquadSummary", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UImage> Icon;

	UPROPERTY(BlueprintReadOnly, Export, Category="SquadSummary", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Value;

	UPROPERTY(BlueprintReadOnly, Export, Category="SquadSummary", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Name;

};

