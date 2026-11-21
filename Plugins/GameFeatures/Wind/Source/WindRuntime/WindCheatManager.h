// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Player/FortCheatManager.h"
#include "WindCheatManager.generated.h"

class UGameplayEffect;

UCLASS(BlueprintType, Blueprintable)
class UWindCheatManager : public UChildCheatManager
{
	GENERATED_BODY()

public:
	UFUNCTION(Exec, BlueprintAuthorityOnly)
	void InflateBalloonOnSelf(int32 NumBalloons = 1) const;

	UFUNCTION(Exec, BlueprintAuthorityOnly)
	void ReleaseBalloonOnSelf(int32 NumBalloons = 1) const;

protected:
	UPROPERTY(EditDefaultsOnly, Category="WindCheatManager")
	TSubclassOf<UGameplayEffect> InflateEffectClass;

	UPROPERTY(EditDefaultsOnly, Category="WindCheatManager")
	TSubclassOf<UGameplayEffect> DeflateEffectClass;

	UPROPERTY(EditDefaultsOnly, Category="WindCheatManager")
	int32 MinBalloonsOnPlayer;

	UPROPERTY(EditDefaultsOnly, Category="WindCheatManager")
	int32 MaxBalloonsOnPlayer;

};

