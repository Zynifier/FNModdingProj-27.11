// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/RootMotionSource.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Math/MathFwd.h"
#include "FortRootMotionSources.generated.h"

class ACharacter;
class UAnimMontage;
class UMotionWarpingComponent;

USTRUCT()
struct FFortRootMotionSource_Montage : public FRootMotionSource
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TObjectPtr<UAnimMontage> Montage;

	UPROPERTY(NotReplicated)
	bool bExtendMotionOnLastFrame;

	UPROPERTY(NotReplicated)
	FVector LatestRepMovementLocation;

private:
	UPROPERTY(NotReplicated, Export)
	TWeakObjectPtr<UMotionWarpingComponent> MotionWarpingComp;

};

UCLASS()
class UFortRootMotionSourcesUtilities : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="Root Motion Sources")
	static void PlayMontageWithRootMotionSource(ACharacter* Character, UAnimMontage* Montage, float PlayRate, bool bExtendMotionOnLastFrame = false, float StartTime = -1.000000f);

};

