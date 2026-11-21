// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Math/MathFwd.h"
#include "FortMovementMode_ExtLogicTraversalBase.h"
#include "Movement/FortCharacterMovementTypes.h"
#include "Pawns/FortPawnTypes.h"
#include "FortMovementMode_ExtClambering.generated.h"

class UAnimMontage;
class UCameraShakeBase;
class UFortCameraMode;

USTRUCT()
struct FFortMovementMode_ClamberingCreationData : public FFortMovementMode_TraversalBaseCreationData
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FSynchedActionWarpPointInfo_Replicated LedgeLaunchWarpPointInfo;

	UPROPERTY()
	bool bCanStandOnLedge;

	UPROPERTY()
	bool bHasFixedLedgeLaunchWarpPoint;

};

USTRUCT(BlueprintType)
struct FFortMovementMode_ClamberingRuntimeData : public FFortMovementMode_TraversalBaseRuntimeData
{
	GENERATED_BODY()

};

UCLASS()
class CLAMBERINGCODERUNTIME_API UFortMovementMode_ExtClambering : public UFortMovementMode_ExtLogicTraversalBase
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintImplementableEvent, meta=(DisplayName="GetAnimationMontageInformation"))
	void BP_GetAnimationMontageInformation(const FSynchedActionInfo& BaseSynchedActionInfo, bool bIsLedgeLaunch, bool bHasFutureLedge, const FVector& FutureLedgeWarpPoint, UAnimMontage*& AnimMontage, FName& StartSectionName, FName& MontageMiddleSectionName);

	UFUNCTION(BlueprintPure, meta=(DisplayName="GetClamberLocation"))
	FVector BP_GetClamberLocation() const;

	UFUNCTION(BlueprintPure)
	bool IsContextualActionPrototypeActive() const;

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortMovementMode_ExtClambering")
	TSubclassOf<UFortCameraMode> LedgeLaunchCameraMode;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortMovementMode_ExtClambering")
	FGameplayTagContainer ClamberingTag;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortMovementMode_ExtClambering")
	FGameplayTag ClamberingStartedTag;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortMovementMode_ExtClambering")
	FGameplayTagContainer ClamberingFinishedTag;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortMovementMode_ExtClambering")
	TObjectPtr<UCameraShakeBase> CameraShake;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortMovementMode_ExtClambering")
	FName LedgeLaunchSyncPointName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortMovementMode_ExtClambering")
	float LedgeLaunchSyncPointInterpSpeed;

};

