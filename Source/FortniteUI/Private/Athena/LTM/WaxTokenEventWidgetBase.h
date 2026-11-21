// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Athena/LTM/LTMWidgetBase.h"
#include "WaxTokenEventWidgetBase.generated.h"

class AFortAthenaMutator_Wax;
class AFortPlayerStateAthena;

UCLASS(BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UWaxTokenEventWidgetBase : public ULTMWidgetBase
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent, Category="Token Events")
	void OnFlyingTokensApplied(AFortPlayerStateAthena* Player, int32 Amount);

	UFUNCTION(BlueprintImplementableEvent, Category="Token Events")
	void OnTokensAwarded(AFortPlayerStateAthena* Player, int32 Amount);

	UFUNCTION(BlueprintImplementableEvent, Category="Token Events")
	void OnTokensCollected(AFortPlayerStateAthena* Player, int32 Amount);

	UPROPERTY(BlueprintReadOnly, Category="WaxTokenEventWidgetBase")
	TObjectPtr<AFortAthenaMutator_Wax> WaxMutator;

};

