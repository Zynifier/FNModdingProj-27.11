// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "FortMovementMode_ExtLogicTraversalBase.h"
#include "HurdleType.h"
#include "Movement/FortCharacterMovementTypes.h"
#include "FortMovementMode_ExtLogicHurdle.generated.h"

class UAnimMontage;
enum class EHurdleType : uint8;

USTRUCT()
struct FFortMovementMode_HurdleCreationData : public FFortMovementMode_TraversalBaseCreationData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="FortMovementMode_HurdleCreationData")
	EHurdleType Type;

	UPROPERTY()
	bool bIsNarrowOpening;

};

USTRUCT()
struct FFortMovementMode_HurdleRuntimeData : public FFortMovementMode_TraversalBaseRuntimeData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="FortMovementMode_HurdleRuntimeData")
	EHurdleType Type;

};

UCLASS(BlueprintType, Blueprintable)
class VAULTINGCODERUNTIME_API UFortMovementMode_ExtLogicHurdle : public UFortMovementMode_ExtLogicTraversalBase
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintImplementableEvent, meta=(DisplayName="GetAnimationMontageInformation"))
	void BP_GetAnimationMontageInformation(FSynchedActionInfo SynchedActionInfo, EHurdleType Type, bool bIsNarrowOpening, bool bIsCrouched, UAnimMontage*& AnimMontage, FName& StartSectionName, FName& MontageMiddleSectionName);

protected:
	UFUNCTION(BlueprintPure)
	bool IsContextualActionPrototypeActive() const;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortMovementMode_ExtLogicHurdle")
	FGameplayTagContainer HurdleTag;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortMovementMode_ExtLogicHurdle")
	FGameplayTag HurdleStartedTag;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortMovementMode_ExtLogicHurdle")
	FGameplayTagContainer HurdleFinishedTag;

};

