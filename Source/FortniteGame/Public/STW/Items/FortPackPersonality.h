// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "FortPackPersonality.generated.h"

class USoundCue;

UCLASS(BlueprintType)
class UFortPackPersonality : public UDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Store")
	TObjectPtr<USoundCue> TickleVOSound;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Store")
	TObjectPtr<USoundCue> TickleSFXSound;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Store")
	TObjectPtr<USoundCue> XRayVOSound;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Store")
	TObjectPtr<USoundCue> HoverVOSound;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Store")
	TObjectPtr<USoundCue> BuySFXSound;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Generic")
	TObjectPtr<USoundCue> OpenGenericVO_Sound;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Generic")
	TObjectPtr<USoundCue> OpenGenericSFX_Sound;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Silver")
	TObjectPtr<USoundCue> UpgradeSilverVO_Sound;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Silver")
	TObjectPtr<USoundCue> UpgradeSilverSFX_Sound;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Silver")
	TObjectPtr<USoundCue> OpenSilverVO_Sound;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Silver")
	TObjectPtr<USoundCue> OpenSilverSFX_Sound;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Gold")
	TObjectPtr<USoundCue> UpgradeGoldVO_Sound;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Gold")
	TObjectPtr<USoundCue> UpgradeGoldSFX_Sound;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Gold")
	TObjectPtr<USoundCue> OpenGoldVO_Sound;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Gold")
	TObjectPtr<USoundCue> OpenGoldSFX_Sound;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Greets")
	TObjectPtr<USoundCue> GreetGenericVO_Sound;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Greets")
	TObjectPtr<USoundCue> GreetAxeVO_Sound;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Greets")
	TObjectPtr<USoundCue> GreetBaseballBatVO_Sound;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Greets")
	TObjectPtr<USoundCue> GreetGardenHoeVO_Sound;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Greets")
	TObjectPtr<USoundCue> GreetGardenRakeVO_Sound;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Greets")
	TObjectPtr<USoundCue> GreetHockeyStickVO_Sound;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Greets")
	TObjectPtr<USoundCue> GreetPickAxeVO_Sound;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Greets")
	TObjectPtr<USoundCue> GreetPitchforkVO_Sound;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Greets")
	TObjectPtr<USoundCue> GreetScytheVO_Sound;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Greets")
	TObjectPtr<USoundCue> GreetSledgehammerVO_Sound;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Greets")
	TObjectPtr<USoundCue> GreetSwordVO_Sound;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Sound")
	TObjectPtr<USoundCue> PreHitVO_Sound;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Music")
	TObjectPtr<USoundCue> DropMusic_Sound;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Music")
	TObjectPtr<USoundCue> OpenMusic_Sound;

};

