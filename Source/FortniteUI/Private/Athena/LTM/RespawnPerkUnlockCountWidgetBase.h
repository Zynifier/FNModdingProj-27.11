// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Athena/LTM/LTMWidgetBase.h"
#include "RespawnPerkUnlockCountWidgetBase.generated.h"

class AFortAthenaMutator_SpyRumble;
class UCommonTextBlock;

UCLASS()
class URespawnPerkUnlockCountWidgetBase : public ULTMWidgetBase
{
	GENERATED_BODY()

protected:
	UFUNCTION()
	void HandleRequiredKillsForPerkUnlockChanged(int32 KillCount);

	UFUNCTION(BlueprintImplementableEvent)
	void OnNewTechAvailable(int32 NewCount);

	UFUNCTION()
	void UpdateScore();

	UPROPERTY()
	TObjectPtr<AFortAthenaMutator_SpyRumble> CachedMutator;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> TextBlock_RequiredKills;

};

