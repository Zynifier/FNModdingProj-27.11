// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Math/MathFwd.h"
#include "FortHolsterWeaponSourceInterface.h"
#include "Movement/FortCharacterMovementTypes.h"
#include "Movement/FortMovementMode_BaseExtLogic.h"
#include "Pawns/FortPawnTypes.h"
#include "FortMovementMode_ExtLogicTraversalBase.generated.h"

class AActor;
class UAnimMontage;
class UFortCameraMode;
class UPrimitiveComponent;

USTRUCT()
struct FFortMovementMode_TraversalBaseCreationData : public FFortMovementMode_BaseExtCreationData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="FortMovementMode_TraversalBaseCreationData")
	FSynchedActionInfo SynchedActionInfo;

	UPROPERTY()
	FSynchedActionWarpPointInfo_Replicated SynchedActionWarpPointInfo;

	UPROPERTY()
	FVector TargetLocation;

	UPROPERTY()
	FRotator TargetRotation;

	UPROPERTY()
	TWeakObjectPtr<AActor> RefActor;

	UPROPERTY(Export)
	TWeakObjectPtr<UPrimitiveComponent> RefActorComponent;

	UPROPERTY()
	FName RefActorBoneName;

	UPROPERTY()
	EFortSynchedActionEndMovementMode EndMovementMode;

};

USTRUCT(BlueprintType)
struct CONTEXTUALTRAVERSALRUNTIME_API FFortMovementMode_TraversalBaseRuntimeData : public FFortMovementMode_BaseExtRuntimeData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="FortMovementMode_TraversalBaseRuntimeData")
	TObjectPtr<UAnimMontage> AnimMontage;

	UPROPERTY(EditAnywhere, Category="FortMovementMode_TraversalBaseRuntimeData")
	FName MontageStartSectionName;

	UPROPERTY(EditAnywhere, Category="FortMovementMode_TraversalBaseRuntimeData")
	FName MontageMiddleSectionName;

	UPROPERTY()
	FSynchedActionWarpPointInfo_Replicated SynchedActionWarpPointInfo;

};

UCLASS(BlueprintType, Blueprintable)
class CONTEXTUALTRAVERSALRUNTIME_API UFortMovementMode_ExtLogicTraversalBase : public UFortMovementMode_BaseExtLogic, public IFortHolsterWeaponSourceInterface
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortMovementMode_ExtLogicTraversalBase")
	TSubclassOf<UFortCameraMode> CameraMode;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortMovementMode_ExtLogicTraversalBase")
	FGameplayTag CameraModeTag;

	UPROPERTY(EditAnywhere, Category="FortMovementMode_ExtLogicTraversalBase")
	FName MontageStartSectionName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortMovementMode_ExtLogicTraversalBase")
	bool bUseNextSectionAnimName;

	UPROPERTY(EditDefaultsOnly, Category="FortMovementMode_ExtLogicTraversalBase")
	float OverrideServerAllowablePositionError;

	UPROPERTY(EditDefaultsOnly, Category="FortMovementMode_ExtLogicTraversalBase")
	float OverrideAnimBlendOutTimeWhenLanding;

};

