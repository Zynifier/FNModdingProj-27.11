// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Bacchus/HUDLayoutToolV2/FortMobileHUDElementProxy.h"
#include "HUDLayoutToolV2_KillfeedProxy.generated.h"

class UFortDynamicEntryBox;

UCLASS()
class UHUDLayoutToolV2_KillfeedProxy : public UFortMobileHUDElementProxy
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, Category="Custom Properties", meta=(Categories="HUDLayout.Property"))
	FGameplayTag NumberOfKillfeedLinesTag;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortDynamicEntryBox> EntryBox_KillFeedText;

};

