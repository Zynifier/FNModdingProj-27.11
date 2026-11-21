// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FabricFloatProvider.h"
#include "FabricFloatProviderValueSetter.generated.h"

UENUM(BlueprintType)
enum EFabricValueSetterTransitionTiming
{
	Immediate = 0,
	NextBeat = 1,
	NextBar = 2,
	NextPhrase = 3,
};

USTRUCT(BlueprintType)
struct FABRICRUNTIME_API FFabricValueSetterGenerator
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly, Category="FabricValueSetterGenerator")
	int32 PhraseLengthInBars;

};

UCLASS(BlueprintType, Blueprintable)
class FABRICRUNTIME_API UFabricFloatProviderValueSetter : public UFabricFloatProviderBase
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void BroadcastCurrentValue();

protected:
	UFUNCTION(BlueprintPure)
	float GetUpdateBeat() const;

	UPROPERTY(EditAnywhere, Category="FabricFloatProviderValueSetter")
	FString ValueParam;

	UPROPERTY(EditAnywhere, Category="FabricFloatProviderValueSetter")
	FString TransitionTimingParam;

};

