// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonButtonLegacy.h"
#include "FortBannerSlotButton.generated.h"

class UFortPlayerBanner;

UCLASS()
class UFortBannerSlotButton : public UCommonButtonLegacy
{
	GENERATED_BODY()

protected:
	UFUNCTION()
	void HandleInventoryUpdated(const TSet<FString>& ItemChangeFlags, int64 ProfileRevision);

private:
	UPROPERTY(BlueprintReadOnly, Export, Category="FortBannerSlotButton", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UFortPlayerBanner> PlayerBanner;

};

