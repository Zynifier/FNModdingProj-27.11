// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "CurieInterface.h"
#include "FortCurieInterface.generated.h"

UENUM(BlueprintType)
enum class EFortNativeCurieFXCueResponse : uint8
{
	/** If the Curie state also has specified a gameplay cue, it should be ignored */
	IgnoreCue = 0,
	/** If the Curie state also has specified a gameplay cue, it should be allowed */
	AllowCue = 1,
	/** Any Curie state cue should be ignored and instead a specified cue should be played */
	OverrideCue = 2,
};

USTRUCT(BlueprintType)
struct FFortNativeCurieFXResponse
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortNativeCurieFXResponse", meta=(Categories="GameplayCue.Curie", EditCondition="GameplayCueResponse == EFortNativeCurieFXCueResponse::OverrideCue"))
	FGameplayTag OverrideGameplayCue;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortNativeCurieFXResponse")
	EFortNativeCurieFXCueResponse GameplayCueResponse;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortNativeCurieFXResponse")
	uint8 bShouldPlayGeneralVFX : 1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortNativeCurieFXResponse")
	uint8 bShouldPlayAmbientAudio : 1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortNativeCurieFXResponse")
	uint8 bShouldPlayGlow : 1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortNativeCurieFXResponse")
	uint8 bShouldPlayFXAsAOE : 1;

};

UINTERFACE(MinimalAPI)
class UFortCurieInterface : public UCurieInterface
{
	GENERATED_BODY()
};

class FORTNITEGAME_API IFortCurieInterface : public ICurieInterface
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintNativeEvent, Category="Curie|FX")
	void ShouldPlayNativeCurieFX(FGameplayTag FXTag, FFortNativeCurieFXResponse& OutResponse) const;

};

