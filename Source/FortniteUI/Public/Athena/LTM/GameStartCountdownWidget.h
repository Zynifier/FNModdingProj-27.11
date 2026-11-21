// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Athena/LTM/LTMWidgetBase.h"
#include "GameStartCountdownWidget.generated.h"

class AFortAthenaMutator_GameStartCountdown;
class USoundBase;

UCLASS(MinimalAPI, BlueprintType, Blueprintable)
class UGameStartCountdownWidget : public ULTMWidgetBase
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure)
	USoundBase* GetCountdownMusicStinger() const;

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void HandleGameStartCountdownBegin(float Duration, int32 StartingCountdownInteger);

	UFUNCTION(BlueprintImplementableEvent)
	void HandleGameStartCountdownEnd();

	UPROPERTY(Transient)
	TObjectPtr<USoundBase> CountdownMusicStinger;

	UPROPERTY()
	TObjectPtr<AFortAthenaMutator_GameStartCountdown> GameStartCountdownMutator;

};

