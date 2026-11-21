// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonButtonLegacy.h"
#include "FortTabListWidgetBase.h"
#include "FortTopBarTabButton.generated.h"

class UFortPersistentTabObject;

UCLASS(Abstract, MinimalAPI, meta=(DisableNativeTick))
class UFortTopBarTabButton : public UCommonButtonLegacy, public IFortTabButtonInterface
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure)
	bool IsAlternateLabelStyleUsed() const;

	UFUNCTION()
	void SetTabLabelInfo_Implementation(const FFortTabButtonLabelInfo& TabLabelInfo);

protected:
	UPROPERTY(EditAnywhere, Category="FortTopBarTabButton")
	bool bUseAlternateLabelStyle;

	UPROPERTY(EditAnywhere, Category="FortTopBarTabButton")
	bool bAlwaysShowTextLabel;

	UPROPERTY(Transient)
	TArray<TObjectPtr<UFortPersistentTabObject>> TabObjectInstances;

};

