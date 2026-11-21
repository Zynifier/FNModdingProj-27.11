// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/Color.h"
#include "Abilities/FortGameplayCueNotify_Loop.h"
#include "FortSoundCameraLensEffect.h"
#include "FortTeamEnum.h"
#include "FortGameplayCueNotifyLoop_SoundIndicator.generated.h"

class USoundBase;
class UTexture;

UCLASS(MinimalAPI, BlueprintType, Blueprintable, HideCategories=("Tick", "Rendering", "Input", "Actor", "Replication"), meta=(Category="GameplayCue", DisplayName="GCNL Sound Indicator", ShowWorldContextPin))
class AFortGameplayCueNotifyLoop_SoundIndicator : public AFortGameplayCueNotify_Loop
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Sound Indicator")
	EFortSoundIndicatorTypes SoundIndicatorType;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Sound Indicator")
	TObjectPtr<USoundBase> SoundBaseCue;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Sound Indicator")
	float SoundIndicatorMaxDistance;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Sound Indicator")
	TArray<TEnumAsByte<EFortTeamAffiliation::Type>> ShowAffiliations;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Sound Indicator")
	TObjectPtr<UTexture> SoundIndicatorIconOverride;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Sound Indicator")
	FLinearColor SoundIndicatorTintOverride;

};

