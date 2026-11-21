// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonActivatablePanelLegacy.h"
#include "FortAlterationModOptinScreenBase.generated.h"

class UFortItem;

UCLASS(Abstract, BlueprintType, meta=(DisableNativeTick))
class UFortAlterationModOptinScreenBase : public UCommonActivatablePanelLegacy
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="AlterationModOptIn")
	void SetupItem(UFortItem* Item);

protected:
	UFUNCTION(BlueprintCallable, Category="AlterationModOptIn")
	void ConvertItemAlterations();

	UFUNCTION(BlueprintImplementableEvent, Category="AlterationModOptIn")
	void OnItemConversionComplete();

	UFUNCTION(BlueprintImplementableEvent, Category="AlterationModOptIn")
	void OnSetupItem();

	UFUNCTION(BlueprintCallable, Category="AlterationModOptIn")
	void RequestClose(bool bCancelled = false);

	UPROPERTY(BlueprintReadOnly, Category="AlterationModOptIn")
	TObjectPtr<UFortItem> ItemToOptin;

};

