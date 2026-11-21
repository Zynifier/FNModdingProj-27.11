// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortHUDElementWidget.h"
#include "AthenaWatchers.generated.h"

class UTextBlock;

UCLASS(Abstract, BlueprintType, meta=(DisableNativeTick))
class UAthenaWatchers : public UFortHUDElementWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintImplementableEvent, meta=(DisplayName="Spectator Count Changed"))
	void SpectatorCountChanged_BP(int32 NewCount);

	UFUNCTION(BlueprintImplementableEvent)
	void SpectatorRemoved();

	UFUNCTION(BlueprintImplementableEvent)
	void SpectatorsAdded(bool bBigGroup);

	UFUNCTION(BlueprintImplementableEvent)
	void SpectatorsBegan(bool bBigGroup);

	UFUNCTION(BlueprintImplementableEvent)
	void SpectatorsEnded();

protected:
	UFUNCTION()
	void HandleSpectatorCountChanged(int32 NewSpectatorCount);

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UTextBlock> Text_Watchers;

};

