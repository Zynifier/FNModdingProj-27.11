// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonActivatableWidget.h"
#include "UIManager/FortPrimaryContentInterface.h"
#include "AthenaItemSelectorScreenBase.generated.h"

class ULockerConfirmationModal;

UCLASS(Abstract, Config=Game)
class UAthenaItemSelectorScreenBase : public UCommonActivatableWidget, public IFortPrimaryContentInterface
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintImplementableEvent)
	void OnHideItemInfoHeader(bool bShouldHide);

protected:
	UFUNCTION(BlueprintCallable)
	void RequestItemSelectorScreenRefreshFocus();

	UPROPERTY(BlueprintReadOnly, Config, Category="AthenaItemSelectorScreenBase")
	bool bVariantZoomUsesSnap;

private:
	UPROPERTY(EditDefaultsOnly, Category="AthenaItemSelectorScreenBase")
	TSoftClassPtr<ULockerConfirmationModal> LockerConfirmationModalClass;

	UPROPERTY(EditDefaultsOnly, Category="AthenaItemSelectorScreenBase")
	FName ArchiveMaterialParameterName;

	UPROPERTY(EditDefaultsOnly, Category="AthenaItemSelectorScreenBase")
	float ArchiveMaterialParameterEquippingValue;

	UPROPERTY(EditDefaultsOnly, Category="AthenaItemSelectorScreenBase")
	float ArchiveMaterialParameterArchivingValue;

};

